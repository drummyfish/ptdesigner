//**********************************************************************
/** @file
 * Implementation of advanced color buffer operations.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include "proctextures.h"
#include "colorbuffer.h"
#include "matrix.h"
#include "linelist.h"
#include <stdio.h>
#include <math.h>

#define TURTLE_STACK_REALLOC_BY 256 ///< by how many realloc the stack

                                /** possible ways to draw a line */
typedef enum
  {
    LINE_NORMAL,
    LINE_ZIG_ZAG,
    LINE_WAVE,
    LINE_ARROW,
    LINE_DOUBLE,
    LINE_PARTICLES
  } t_line_type;

                                /** state for turtle graphics */
typedef struct
  {
    int angle;                  /**< angle in degrees CCW starting
                                     from pointing right */
    int step_length;            ///< step length in pixels
    unsigned char color[3];     ///< color of the line
    unsigned int line_width;    ///< line width in pixels
    t_line_type line_type;      ///< line type
    unsigned int dot_gap;       ///< gap between line segments in pixels
    int position_x;
    int position_y;
    unsigned int image_width;   ///< width of the image for the turtle
  } t_turtle_state;

                                /** represents a turtle for turtle
                                    graphics */
typedef struct
  {
    t_turtle_state state;       ///< current state
    t_turtle_state *stack;      ///< stack of states
    unsigned int stack_size;    ///< stack size
    t_grammar *grammar;         ///< grammar with drafwing instruction
    unsigned int instruction;   ///< current instruction position
    unsigned int image_width;
  } t_turtle;

t_turtle turtle;                     // global turtle
t_color_buffer turtle_noise_buffer;  // global help buffer

//----------------------------------------------------------------------

  /**
   * Private function - replaces all pixels with specified color in
   * given buffer with another color.
   *
   * @param buffer buffer in which the color will be replaced
   * @param r1 color to be replaced - red
   * @param g1 color to be replace - green
   * @param b1 color to be replace - blue
   * @param r2 color to replace with - red
   * @param g2 color to replace with - green
   * @param b2 color to replace with - blue
   */

void _pt_replace_color(t_color_buffer *buffer, unsigned char r1,
  unsigned char g1, unsigned char b1, unsigned char r2,
  unsigned char g2, unsigned char b2)

  {
    unsigned int i,j;
    unsigned char r,g,b;

    for (j = 0; j < buffer->height; j++)
      for (i = 0; i < buffer->width; i++)
        {
          color_buffer_get_pixel(buffer,i,j,&r,&g,&b);

          if (r == r1 && g == g1 && b == b1)
            color_buffer_set_pixel(buffer,i,j,r2,g2,b2);
        }
  }

//----------------------------------------------------------------------

  /**
   * Private function - draws a "bump" into given color buffer. A bump
   * is a fuzzy circullar object drawn as a function depending on
   * distance from given point.
   *
   * @param buffer buffer to braw the bump into
   * @param x x position of the bump central point, in pixels
   * @param y y position of the bump central point, in pixels
   * @param radius bump radius in pixels
   * @param alter_amplitude says if the amplitude should be altered
   *        depending on the bump size (its radius) (1) or not (0),
   *        non-altering amplitude will always be set to 255
   */

void _pt_draw_bump(t_color_buffer *buffer, unsigned int x,
  unsigned int y, unsigned int radius, int alter_amplitude)

  {
    unsigned int i,j;
    unsigned char color;
    double distance;
    unsigned char max_value;

    max_value = alter_amplitude ?
      radius / ((double) buffer->width) * 255 : 255;

    for (j = 0; j < radius; j++)    // compute only one quadrant
      for (i = 0; i < radius; i++)
        {
          distance = sqrt(i * i + j * j);

          if (distance <= radius)
            distance = sin(distance / radius * PI_DIVIDED_2);
          else
            distance = 1.0;

          color = round_to_char(max_value - distance * max_value);

          color_buffer_substract_pixel(buffer,x + i,y + j,color,
                color,color);

          if (i != 0)
            color_buffer_substract_pixel(buffer,x - i,y + j,color,color,
              color);

          if (j != 0)
            color_buffer_substract_pixel(buffer,x - i,y - j,color,color,
              color);

          if (i != 0 && j != 0)
            color_buffer_substract_pixel(buffer,x + i,y - j,color,color,
              color);
        }
  }

//----------------------------------------------------------------------

  /**
   * Private function - creates an array of points accoording to shape
   * describing string.
   *
   * @param side_string string describing a tile side, it is of format
   *        "%lf %lf %lf %lf ..." where two succeeding number are x and
   *        y coordinations of points, there must be exactly one space
   *        between numbers
   * @param points in this variable the list of points will be returned,
   *        the list will start with [0,0] and will be sorted by values
   *        of x, points with duplicite x value will be eliminated, only
   *        points with x values in range (0,1) will be considered and y
   *        values will be saturated to range <-0.5,0.5>
   * @param length in this variable length of created array will be
   *        returned
   */

void _pt_make_side_points(char *side_string, double points[128][2],
  unsigned int *length)

  {
    unsigned int i, j, position;
    int scanning_x;    // say if we're scanning x or y
    int already_in_array;
    double helper;
    double point[2];

    if (points == NULL || length == NULL)
      return;

    points[0][0] = 0; // initial point
    points[0][1] = 0;
    *length = 1;

    position = 0;      // position in the string
    scanning_x = 1;

    while (1)          // scan the string for points
      {
        if (!sscanf(side_string + position,"%lf",&helper) ||
          (side_string[position] == 0))
          break;

        // go to the next item:

        position++;

        while (side_string[position] != 0 &&
          side_string[position] != ' ')
          position++;

        point[scanning_x ? 0 : 1] = helper;
        scanning_x = !scanning_x;

        if (scanning_x) // one point scanned => add to array
          {
            point[0] = saturate_double(point[0],0.0,1.0);
            point[1] = saturate_double(point[1],-0.5,0.5);

            if (point[0] == 1.0) // make points with 1.0 not get to list
              point[0] = 0.0;

            already_in_array = 0;

            for (j = 0; j < *length; j++)       // check for duplicities
              if (points[j][0] == point[0])     // only x matters
                {
                  already_in_array = 1;
                  break;
                }

            if (!already_in_array)      // add the point to the array
              {
                points[*length][0] = point[0];
                points[*length][1] = point[1];
                *length = *length + 1;
              }

            if (*length >= 128)
              break;
          }
      }

    for (j = 1; j < *length; j++)  // sort the list with bubble sort
      for (i = 0; i < *length - j; i++)
        if (points[i][0] > points[i + 1][0])
          {
            helper = points[i][0];
            points[i][0] = points[i + 1][0];
            points[i + 1][0] = helper;

            helper = points[i][1];
            points[i][1] = points[i + 1][1];
            points[i + 1][1] = helper;
          }
  }

//----------------------------------------------------------------------

  /**
   * Private function - draws transformed tile in given buffer
   * considering transparency.
   *
   * @param tile tile image to be drawn, it should consist of only three
   *        colors - black (0,0,0), white (255,255,255) and red
   *        (255,0,0), black and white pixels will be drawn over pixels
   *        of the destination buffer, while in addition white pixels
   *        will be drawn as specified color, and red pixels will be
   *        considered as transparent
   * @param x x position of the tile in pixels
   * @param y y position of the tile in pixels
   * @param color grayscale value which the white color in tile image
   *        will be replaced with
   * @param destination in this buffer the tile will be drawn over it's
   *        current content
   * @param transformation transformation to be used for the tile, the
   *        tile image will not be affected by this function call
   * @param horizontal says if the transformation is horizontal (values
   *        greater than zero) or vertical (other values)
   */

void _pt_draw_tile(t_color_buffer *tile, unsigned int x, unsigned int y,
  unsigned char color, t_color_buffer *destination,
  t_mosaic_transformation transformation, int horizontal)

  {
    unsigned int i,j,x2,y2;
    unsigned char r,g,b;

    for (j = 0; j < tile->height; j++)
      {
        for (i = 0; i < tile->width; i++)
          {
            // transform the coordinations:

            switch (transformation)
              {
                case MOSAIC_TRANSFORM_SHIFT:

                  x2 = i;
                  y2 = j;
                  break;

                case MOSAIC_TRANSFORM_SHIFT_MIRROR:

                  if (horizontal)
                    {
                      x2 = i;
                      y2 = tile->height - j;
                    }
                  else
                    {
                      x2 = tile->width - i;
                      y2 = j;
                    }

                  break;

                case MOSAIC_TRANSFORM_ROTATE_SIDE:

                  x2 = tile->width - i;
                  y2 = tile->height - j;
                  break;

                case MOSAIC_TRANSFORM_ROTATE_VERTEX:

                  x2 = tile->height - j;
                  y2 = i;
                  break;
              }

            color_buffer_get_pixel(tile,x2,y2,&r,&g,&b);

            if (r == 255)
              {
                if (b == 255)     // white
                  {
                    r = color;
                    g = color;
                    b = color;
                  }
                else              // red
                  {
                    color_buffer_get_pixel(destination,x + i,y + j,
                      &r,&g,&b);
                  }
              }
            else                  // black
              {
                r = 0;
                g = 0;
                b = 0;
              }

            color_buffer_set_pixel(destination,x + i,y + j,r,g,b);
          }
      }
  }

//----------------------------------------------------------------------

  /**
   * Private function - depending on provided square mosaic
   * specification makes a tile polygon and returns it as a list of
   * coordinations.
   *
   * @param mosaic square mosaic specification
   * @param array in this variable a pointer to two-dimensional array of
   *        polygon points will be returned, the list is in format
   *        [point number][x/y] representing the polygon based on 1 * 1
   *        size square grid with lower left corner at [0,0], the list
   *        is sorted CW from upper left corder and the polygon is
   *        automatically modified based on side transformations
   *        specified by the mosaic
   * @param array_length in this cariable length of the created list
   *        will be returned
   */

void _pt_make_tile_polygon(t_square_mosaic *mosaic,
  double (**array)[2],unsigned int *array_length)

  {
    double points[128][2];
    double helper;
    unsigned int i,j;
    double (*polygon)[2];        // dynamic array of polygon points
   // double **polygon;
    unsigned int polygon_points; // length of the polygon array
    unsigned int length;

    polygon_points = 0;
    polygon = NULL;

    for (i = 0; i < 4; i++)   // for each side
      {
        // create the side accoording to transformations:

        switch (mosaic->transformation[i])
          {
            case MOSAIC_TRANSFORM_ROTATE_SIDE:
                _pt_make_side_points(mosaic->side_shape[i],points,
                &length);

              for (j = 0; j < length; j++) // cut the side in the middle
                if (points[j][0] >= 0.5)
                  {
                    length = j;
                    break;
                  }

              // copy the half-side upside-down (minus the first point):

              for (j = 1; j < length; j++)
                {
                  points[length * 2 - 1 - j][0] = 1.0 - points[j][0];
                  points[length * 2 - 1 - j][1] = -1 * points[j][1];
                }
              length = length * 2 - 1; // leave out the first point

              break;

            case MOSAIC_TRANSFORM_SHIFT:

              if (i == 0 || i == 1)
                {
                  _pt_make_side_points(mosaic->side_shape[i],points,
                    &length);
                }
              else // copy the opposite side for bottom or left side
                {
                  _pt_make_side_points(mosaic->side_shape[i - 2],points,
                    &length);

                  // flip the side in x and y:

                  for (j = 0; j < length / 2; j++)
                    {
                      helper = -1 * points[j + 1][1];
                      points[j + 1][1] = -1 * points[length - j - 1][1];
                      points[length - j - 1][1] = helper;

                      helper = points[j + 1][0];
                      points[j + 1][0] = 1.0 -
                        points[length - j - 1][0];
                      points[length - j - 1][0] = 1.0 - helper;
                    }
                }

              break;

            case MOSAIC_TRANSFORM_SHIFT_MIRROR:

              if (i == 0 || i == 1)
                {
                  _pt_make_side_points(mosaic->side_shape[i],points,
                    &length);
                }
              else
                {
                  _pt_make_side_points(mosaic->side_shape[i - 2],points,
                    &length);

                  // flip the side y coordinations:

                  for (j = 0; j < length; j++)
                    points[j][1] *= -1;
                }

              break;

            case MOSAIC_TRANSFORM_ROTATE_VERTEX:

              _pt_make_side_points(mosaic->side_shape[0],points,
                &length);

              if (i == 1 || i == 3)
                {
                  for (j = 0; j < length / 2; j++)
                    {
                      helper = -1 * points[j + 1][1];
                      points[j + 1][1] = -1 * points[length - j - 1][1];
                      points[length - j - 1][1] = helper;

                      helper = points[j + 1][0];
                      points[j + 1][0] = 1.0 -
                        points[length - j - 1][0];
                      points[length - j - 1][0] = 1.0 - helper;
                    }
                }

              break;
          }

        polygon = realloc(polygon,(polygon_points + length) *
          2 * sizeof(double));

        for (j = 0; j < length; j++)  // transform points
          {
            switch (i)
              {
                case 0: // top
                  points[j][1] += 1.0;
                  break;

                case 1: // right
                  helper = points[j][0];
                  points[j][0] = 1.0 + points[j][1];
                  points[j][1] = 1.0 - helper;
                  break;

                case 2: // bottom
                  points[j][0] = 1.0 - points[j][0];
                  points[j][1] *= -1;
                  break;

                case 3: // left
                  helper = points[j][0];
                  points[j][0] = -1 * points[j][1];
                  points[j][1] = helper;
                  break;
              }
          }

        for (j = 0; j < length; j++)  // copy the side to the polygon
          {
            polygon[polygon_points + j][0] = points[j][0];
            polygon[polygon_points + j][1] = points[j][1];
          }

        polygon_points += length;
      }

    *array_length = polygon_points;

    *array = polygon;
  }

//----------------------------------------------------------------------

/***
 * Private function - prepares given buffer to be processed with
 * cellular automaton. This means that the format of the buffer will be
 * made such that only red channel matters and its value is equal to the
 * current state number.
 *
 * @param buffer buffer to be converted to the cellular automata format
 * @param number_of_states number of states of the automata
 */

void _pt_cellular_automaton_prepare(t_color_buffer *buffer,
  unsigned int number_of_states)

  {
    unsigned char r,g,b;
    double interval;
    unsigned int x,y,i;

    interval = 255.0 / number_of_states;

    pt_grayscale(buffer);

    for (y = 0; y < buffer->height; y++)
      for (x = 0; x < buffer->width; x++)
        {
          color_buffer_get_pixel(buffer,x,y,&r,&g,&b);

          // threshold:

          for (i = 1; i <= number_of_states; i++)
            if (r <= interval * i)
              {
                r = i - 1;
                break;
              }

          color_buffer_set_pixel(buffer,x,y,r,0,0);
        }
  }

//----------------------------------------------------------------------

/***
 * Private function - converts the buffer's data back from cellular
 * automaton format to grayscale image format.
 *
 * @param buffer buffer to be converted
 * @param number_of_states number of states of the automaton
 */

void _pt_cellular_automaton_convert_back(t_color_buffer *buffer,
  unsigned int number_of_states)

  {
    unsigned char r,g,b;
    double interval;
    unsigned int x,y;

    if (number_of_states == 1)
      number_of_states = 2;     // to prevent division by zero

    interval = 255.0 / (number_of_states - 1);

    for (y = 0; y < buffer->height; y++)
      for (x = 0; x < buffer->width; x++)
        {
          color_buffer_get_pixel(buffer,x,y,&r,&g,&b);
          r = round_to_char(interval * r);
          color_buffer_set_pixel(buffer,x,y,r,r,r);
        }
  }

//----------------------------------------------------------------------

  /**
   * Private function - fills an area with constant color with given
   * color.
   *
   * @param buffer buffer with which the fill will be performed
   * @param x x position of the initial point of the fill
   * @param y y position of the initial point of the fill
   * @param red amount of red to be filled
   * @param green amount of green to be filled
   * @param blue amount of blue to be filled
   */

void _pt_floodfill(t_color_buffer *buffer, int x, int y,
  unsigned char red, unsigned char green, unsigned char blue)

  {
    t_line_list point_stack;          // line list used as a point stack
    unsigned char help_red1, help_green1, help_blue1, help_red2,
      help_green2, help_blue2;

    line_list_init(&point_stack);
    line_list_add(&point_stack,x,y,0,0);

    color_buffer_get_pixel(buffer,x,y,&help_red1,&help_green1,
      &help_blue1);

    while (line_list_get_length(&point_stack) > 0)
      {
        line_list_get(&point_stack,line_list_get_length(&point_stack)
          - 1,&x,&y,NULL,NULL);
        line_list_pop(&point_stack);
                                                      // color the pixel
        color_buffer_set_pixel(buffer,x,y,red,green,blue);

                                                      // check up
        color_buffer_get_pixel(buffer,x,y - 1,&help_red2,
          &help_green2,&help_blue2);

        if (help_red2 == help_red1 && help_green2 == help_green1
          && help_blue2 == help_blue1)
            line_list_add(&point_stack,x,y - 1,0,0);

                                                      // check down
        color_buffer_get_pixel(buffer,x,y + 1,&help_red2,
          &help_green2,&help_blue2);

        if (help_red2 == help_red1 && help_green2 == help_green1
          && help_blue2 == help_blue1)
            line_list_add(&point_stack,x,y + 1,0,0);

                                                      // check right
        color_buffer_get_pixel(buffer,x + 1,y,&help_red2,
          &help_green2,&help_blue2);

        if (help_red2 == help_red1 && help_green2 == help_green1
          && help_blue2 == help_blue1)
            line_list_add(&point_stack,x + 1,y,0,0);

                                                      // check left
        color_buffer_get_pixel(buffer,x - 1,y,&help_red2,
          &help_green2,&help_blue2);

        if (help_red2 == help_red1 && help_green2 == help_green1
          && help_blue2 == help_blue1)
            line_list_add(&point_stack,x - 1,y,0,0);

        // I feel bad about the copy-paste :/
      }

    line_list_destroy(&point_stack);
  }

//----------------------------------------------------------------------

  /**
   * Private function - initialises the global turtle state and sets it
   * the given grammar.
   *
   * @param grammar grammar to be set for the turtle
   * @param image_width width of the image that the turtle will draw to
   *   (this is needed to calculate some parameters like step length
   *   etc.)
   * @param image_width height of the image that the turtle will draw to
   * @param position_x initial x position of the turtle
   * @param positioy_y initial y position of the turtle
   * @param angle initial angle of the turtle in degrees
   * @param noise_intensity affects drawing of particles, says how much
   *        their velocity is affected by the noise, this should be in
   *        range <0,1> (the less, the straighter particle lines)
   */

void _pt_turtle_init(t_grammar *grammar, unsigned int image_width,
  unsigned int image_height, unsigned int position_x, unsigned int
  position_y, int angle, double noise_intensity)

  {
    turtle.image_width = image_width;
    turtle.grammar = grammar;
    turtle.stack_size = 0;
    turtle.stack = NULL;
    turtle.instruction = 0;

    // set the initial state:

    turtle.state.angle = angle;
    turtle.state.step_length = image_width * 0.2;
    turtle.state.color[0] = 0;
    turtle.state.color[1] = 0;
    turtle.state.color[2] = 0;
    turtle.state.line_type = LINE_NORMAL;
    turtle.state.dot_gap = 0;
    turtle.state.position_x = position_x;
    turtle.state.position_y = position_y;
    turtle.state.line_width = image_width / 512;

    if (turtle.state.line_width <= 0)
      turtle.state.line_width = 1;

    // init the global noise buffer (for particle line drawing):

    color_buffer_init(&turtle_noise_buffer,image_width,image_height);

    // fill the buffer with appropriate noise:

    pt_perlin_noise(4,128,noise_intensity * 12 + 3,-1, // empiric values
      INTERPOLATION_SINE,&turtle_noise_buffer,1);
    pt_add_brightness_contrast(&turtle_noise_buffer,0.0,
      -1.0 + noise_intensity);
  }

//----------------------------------------------------------------------

  /**
   * Private function - destroys the global turtle and frees it's
   * memory. The grammar pointed to by the turtle is not freed.
   */

void _pt_turtle_destroy()

   {
     if (turtle.stack != NULL)
       free(turtle.stack);

     color_buffer_destroy(&turtle_noise_buffer);
   }

//----------------------------------------------------------------------

  /**
   * Private function - gets the next draw instruction (other
   * instructions like stack and state manipulation are handled within
   * this function). It returns the coordinations of the line that
   * should be drawn.
   *
   * @param x1 in this variable the x position of the first line point
   *   will be returned
   * @param y1 in this variable the y position of the first line point
   *   will be returned
   * @param x2 in this variable the x position of the second line point
   *   will be returned
   * @param y2 in this variable the y position of the second line point
   *   will be returned
   *
   * @return 0 if there is no more instructions to be read, 1 otherwise
   */

int _pt_turtle_next_instruction(int *x1, int *y1, int *x2, int *y2)

   {
     int dx,dy,helper;
     t_grammar_char *symbol;

     while (1)
       {
         if (turtle.instruction >= (unsigned int)
           turtle.grammar->string_length)
           return 0;   // no more instructions

         symbol = &turtle.grammar->string[turtle.instruction];

         switch(symbol->character)
           {
             case '[': // stack push
               if (turtle.stack_size % TURTLE_STACK_REALLOC_BY == 0)
                 turtle.stack = (t_turtle_state *) realloc(turtle.stack,
                   ((turtle.stack_size / TURTLE_STACK_REALLOC_BY + 1) *
                   TURTLE_STACK_REALLOC_BY) * sizeof(t_turtle_state));

               turtle.stack[turtle.stack_size] = turtle.state;
               turtle.stack_size++;
               break;

             case ']': // stack pop
               if (turtle.stack_size >= 1)
                 {
                   turtle.state = turtle.stack[turtle.stack_size - 1];

                   turtle.stack_size--;

                   if (turtle.stack_size % TURTLE_STACK_REALLOC_BY == 0)
                     turtle.stack = (t_turtle_state *)
                       realloc(turtle.stack,((turtle.stack_size /
                       TURTLE_STACK_REALLOC_BY) *
                       TURTLE_STACK_REALLOC_BY) *
                       sizeof(t_turtle_state));
                 }

               break;

             case 'A': // set angle
               if (symbol->number_of_parameters >= 1)
                 {
                   turtle.state.angle = symbol->parameter_values[0];

                   while (turtle.state.angle > 360)
                     turtle.state.angle -= 360;

                   while (turtle.state.angle < 0)
                     turtle.state.angle += 360;
                 }
               break;

             case 'R': // rotate left
               if (symbol->number_of_parameters >= 1)
                 {
                   turtle.state.angle -= symbol->parameter_values[0];

                   while (turtle.state.angle > 360)
                     turtle.state.angle -= 360;

                   while (turtle.state.angle < 0)
                     turtle.state.angle += 360;
                 }
               break;

             case 'L': // rotate right
               if (symbol->number_of_parameters >= 1)
                 {
                   turtle.state.angle += symbol->parameter_values[0];

                   while (turtle.state.angle > 360)
                     turtle.state.angle -= 360;

                   while (turtle.state.angle < 0)
                     turtle.state.angle += 360;
                 }
               break;

             case 'G':
             case 'D': // draw
               *x1 = turtle.state.position_x;
               *y1 = turtle.state.position_y;

               dx = (int) (turtle.state.step_length *
                 cos(degrees_to_radians(turtle.state.angle)));
               dy = (int) (turtle.state.step_length *
                 sin(degrees_to_radians(turtle.state.angle)));

               *x2 = *x1 + dx;
               *y2 = *y1 - dy;

               turtle.state.position_x = *x2;
               turtle.state.position_y = *y2;

               if (symbol->character == 'D')
                 {
                   turtle.instruction++;  // next instruction
                   return 1;
                 }

               break;

             case 'P': // multiply step length by percentage
               if (symbol->number_of_parameters >= 1)
                 {
				   helper = symbol->parameter_values[0];
				   
				   if (helper < 0)
				     helper = 0;
					 
                   turtle.state.step_length =
                     turtle.state.step_length * helper * 0.01;
                 }
                   
               break;

             case 'B': // set step length to length unit
               if (symbol->number_of_parameters >= 1)
                 {
                   turtle.state.step_length = turtle.image_width *
                   symbol->parameter_values[0] * 0.001;
                   
                   if (turtle.state.step_length < 0)
                     turtle.state.step_length = 0;
                 }

               break;

             case 'W': // set line width to length unit
               if (symbol->number_of_parameters >= 1)
                 { 
                   helper = symbol->parameter_values[0];
                   
                   if (helper < 0)
                     helper = helper * -1;

                   turtle.state.line_width = turtle.image_width *
                     helper * 0.001;

                   if (turtle.state.line_width <= 0)
                     turtle.state.line_width = 1;
                 }

               break;

             case 'S': // set line style
             case 'T':
               if (symbol->number_of_parameters >= 2)
                 {
                   switch(symbol->parameter_values[0])
                     {
                       case 0:
                         turtle.state.line_type = LINE_NORMAL;
                         break;

                       case 1:
                         turtle.state.line_type = LINE_ZIG_ZAG;
                         break;

                       case 2:
                         turtle.state.line_type = LINE_WAVE;
                         break;

                       case 3:
                         turtle.state.line_type = LINE_ARROW;
                         break;

                       case 4:
                         turtle.state.line_type = LINE_DOUBLE;
                         break;

                       case 5:
                         turtle.state.line_type = LINE_PARTICLES;
                         break;
                     }
                 }

               turtle.state.dot_gap = symbol->parameter_values[1] *
                 turtle.image_width;

               if (symbol->character == 'S')
                 turtle.state.dot_gap *= 0.001;

               break;

             case 'I': // increase step length by pixels
               if (symbol->number_of_parameters >= 1)
                 {
                   turtle.state.step_length +=
                     symbol->parameter_values[0];
				 
				   if (turtle.state.step_length < 0)
				     turtle.state.step_length = 0;
				 }

               break;

             case 'M': // set step length in pixels
               if (symbol->number_of_parameters >= 1)
                 {
                   turtle.state.step_length =
                     symbol->parameter_values[0];
				 
				   if (turtle.state.step_length < 0)
				     turtle.state.step_length = 0;
				 }

               break;

             case 'F': // set line width in pixels
               if (symbol->number_of_parameters >= 1)
                 {
                   turtle.state.line_width =
                     symbol->parameter_values[0];
                     
                   if (turtle.state.line_width <= 0)
                     turtle.state.line_width = 1;
				 }

               break;

             case 'C': // set color
               if (symbol->number_of_parameters >= 3)
                 {
                   turtle.state.color[0] =
                     round_to_char(symbol->parameter_values[0]);
                   turtle.state.color[1] =
                     round_to_char(symbol->parameter_values[1]);
                   turtle.state.color[2] =
                     round_to_char(symbol->parameter_values[2]);
                 }

             default:
               break;
           }

         turtle.instruction++;  // go to the next instruction
       }
   }

//----------------------------------------------------------------------

  /**
   * Private function - draws a line between two given points. The line
   * can be parametrised in many ways.
   *
   * @param buffer buffer in which the line will be drawn
   * @param x1 x coordination of the first line point
   * @param y1 y coordination of the first line point
   * @param x2 x coordination of the second line point
   * @param y2 y coordination of the second line point
   * @param red amount of red of the line color
   * @param green amount of green of the line color
   * @param blue amount of blue of the line color
   * @param width line width in pixels
   * @param dot_gap gap between line segments in pixels, 0 means a
   *        continuous line
   * @param noise_intensity information about noise intensity in range
   *        <0,1>, this is only needed for drawing particle lines
   * @param particle_density for particle lines affects how many
   *        particles there will be, this should be in range <0,1>
   * @param noise_buffer buffer in which noise for drawing particle
   *        lines is stored, with other line types this can be NULL
   * @param type way in which the line will be drawn, if the type is
   *        particle, then
   */

void _pt_draw_fancy_line(t_color_buffer *buffer, int x1, int y1, int x2,
  int y2, unsigned char red, unsigned char green,
  unsigned char blue, unsigned char width, int dot_gap,
  double noise_intensity, double particle_density,
  t_color_buffer *noise_buffer, t_line_type type)

  {

    int i, j, k;
    int x,y,help_x,help_y;
    int dx,dy;
    int steps;
    int difference;   // for shifting points to sides from the line
    int half_width;
    int gap_length;
    t_color_buffer help_buffer;
    t_color_transition help_transition;
    double angle;
    double length;

    dx = x2 - x1;
    dy = y2 - y1;
    dx = dx < 0 ? -1 * dx : dx;    // make absolute values
    dy = dy < 0 ? -1 * dy : dy;

    if (dx != 0)
      angle = atan(abs(dy)/abs(dx));
    else
      angle = PI_DIVIDED_2;

    angle = two_points_to_angle(x1,y1,x2,y2);

    half_width = width / 2;      // half width of the line
    gap_length = 0;

    steps = dx > dy ? dx : dy;   // max of dx and dy
    steps++;                     // make the line end in it's endpoint

    if (type == LINE_ZIG_ZAG)
      {
        difference = (int) ((steps * 0.1) / 2);

        help_x = x1; // coordinations one iteration back
        help_y = y1;

        for (i = 1; i < 20; i++) // start from the second point
          {
            line_point(x1,y1,angle,(int) (steps * (0.05 * (i + 1))),&x,&y);

            // randomly shift the points (not the first and last one):

            if (i != 0 && i != 19)
              {
                x += noise_int_range(i * 2,-1 * difference,difference);
                y += noise_int_range((i * 2) + 1,-1 * difference,difference);
              }

            _pt_draw_fancy_line(buffer,help_x,help_y,x,y,red,green,blue,
              width,dot_gap,0.0,0.0,NULL,LINE_NORMAL);

            help_x = x;
            help_y = y;
          }
      }
    else if (type == LINE_WAVE)
      {
        help_x = x1;
        help_y = y1;

        for (i = 1; i < 20; i++)
          {
            difference = sin(0.1 * (i + 1) * PI_TIMES_2) * (steps * 0.1);

            line_point(x1,y1,angle,(int) (steps * (0.05 * (i + 1))),&x,&y);

            if (difference >= 0)
              line_point(x,y,angle - PI_DIVIDED_2,difference,&dx,&dy); // perpendicular line
            else
              line_point(x,y,angle + PI_DIVIDED_2,-1 * difference,&dx,&dy);

            _pt_draw_fancy_line(buffer,help_x,help_y,dx,dy,red,green,blue,
              width,dot_gap,0.0,0.0,NULL,LINE_NORMAL);

            help_x = dx;
            help_y = dy;
          }
      }
    else if (type == LINE_DOUBLE)      // double line
      {
        circle_point_by_angle(0,0,2 * width + 1,angle + PI_DIVIDED_2,&dx,&dy);

        _pt_draw_fancy_line(buffer,x1 + dx,y1 + dy,x2 + dx,y2 + dy,red,
          green,blue,width,dot_gap,0.0,0.0,NULL,LINE_NORMAL);

        _pt_draw_fancy_line(buffer,x1 - dx,y1 - dy,x2 - dx,y2 - dy,red,
          green,blue,width,dot_gap,0.0,0.0,NULL,LINE_NORMAL);
      }
    else if (type == LINE_PARTICLES)   // particles
      {
        // relative length:
        length = sqrt(dx * dx + dy * dy) / buffer->width;
        color_buffer_init(&help_buffer,buffer->width,buffer->height);
        color_transition_init(&help_transition);
        color_transition_add_point(255,255 - red,255 - green,255 - blue,
          &help_transition); // inversed color
        color_transition_add_point(0,0,0,0,&help_transition);

        pt_particle_movement(noise_buffer,           // empiric values:
          length * 128 + 1 +
          length * particle_density * 128,           // particles
          x1 / ((double) buffer->width - 1),
          y1 / ((double) buffer->height - 1),
          radians_to_degrees(angle),
          length * 20 + 5 + noise_intensity * 75,    // spread
          length * 13 + 0.1 +                        // initial velocity
          noise_intensity * length * 20,
          &help_buffer);

        pt_map_to_transition(&help_buffer,&help_transition);
        pt_substract_buffers(&help_buffer,buffer);

        color_transition_destroy(&help_transition);
        color_buffer_destroy(&help_buffer);
      }
    else                               // normal straight line
      for (i = 0; i < steps; i++)
        {
          gap_length++;

          if (gap_length > dot_gap)
            gap_length = 0;

          if (gap_length != 0)
            continue;

          line_point(x1,y1,angle,i,&x,&y);

          for (j = 0; j < width; j++)
            for (k = 0; k < width; k++)
              color_buffer_set_pixel(buffer,x - half_width + j,
              y - half_width + k,red,green,blue);

          if (i == steps - 1 && type == LINE_ARROW)// draw the arrow end
            {
              length = sqrt(dx * dx + dy * dy);

              circle_point_by_angle(x,y,length * 0.3,angle + 2.8,
                &help_x,&help_y);
              _pt_draw_fancy_line(buffer,x,y,help_x,help_y,red,green,
                blue,width,dot_gap,0.0,0.0,NULL,LINE_NORMAL);

              circle_point_by_angle(x,y,length * 0.3,angle - 2.8,
                &help_x,&help_y);
              _pt_draw_fancy_line(buffer,x,y,help_x,help_y,red,green,
                blue,width,dot_gap,0.0,0.0,NULL,LINE_NORMAL);
            }
        }
  }

//----------------------------------------------------------------------

void pt_color_fill(t_color_buffer *buffer, int red, int green, int blue)

  {
    unsigned int i,j;

    for (i = 0; i < buffer->width; i++)
      for (j = 0; j < buffer->height; j++)
        color_buffer_set_pixel(buffer,i,j,red,green,blue);
  }

//----------------------------------------------------------------------

void pt_add_rgb(t_color_buffer *buffer, int red, int green, int blue)

  {
    unsigned int i, j;
    int red_value, green_value, blue_value;
    unsigned char help_red, help_green, help_blue;

    for (j = 0; j < buffer->height; j++)
      for (i = 0; i < buffer->width; i++)
        {
          color_buffer_get_pixel(buffer,i,j,&help_red,&help_green,
            &help_blue);

          red_value = help_red + red;
          green_value = help_green + green;
          blue_value = help_blue + blue;

          red_value = red_value > 255 ? 255 : red_value;
          red_value = red_value < 0 ? 0 : red_value;
          green_value = green_value > 255 ? 255 : green_value;
          green_value = green_value < 0 ? 0 : green_value;
          blue_value = blue_value > 255 ? 255 : blue_value;
          blue_value = blue_value < 0 ? 0 : blue_value;

          color_buffer_set_pixel(buffer,i,j,(unsigned char) red_value,
            (unsigned char) green_value, (unsigned char) blue_value);
        }
  }

//----------------------------------------------------------------------

void pt_add_hsl(t_color_buffer *buffer, double hue, double saturation,
  double lightness)

  {
    unsigned int i, j;
    unsigned char red, green, blue;
    double h, s, l;

    for (j = 0; j < buffer->height; j++)
      for (i = 0; i < buffer->width; i++)
        {
          color_buffer_get_pixel(buffer,i,j,&red,&green,&blue);
          rgb_to_hsl(red,green,blue,&h,&s,&l);

          h = h + hue;
          s = s + saturation;
          l = l + lightness;

          if (h < 0.0)
            h = 0.0;
          else if (h > 1.0)
            h = 1.0;

          if (s < 0.0)
            s = 0.0;
          else if (s > 1.0)
            s = 1.0;

          if (l < 0.0)
            l = 0.0;
          else if (l > 1.0)
            l = 1.0;

          hsl_to_rgb(h,s,l,&red,&green,&blue);

          color_buffer_set_pixel(buffer,i,j,red,green,blue);
        }
  }

//----------------------------------------------------------------------

void pt_add_brightness_contrast(t_color_buffer *buffer,
  double brightness, double contrast)

  {
    /* This function uses GIMP style brightness/contrast adjustment */

    unsigned int i, j;
    unsigned char red, green, blue;
    double double_red, double_green, double_blue;

    if (brightness < -1.0 || brightness > 1.0 || contrast < -1.0 ||
      contrast > 1.0)
      return;

    for (j = 0; j < buffer->height; j++)
      for (i = 0; i < buffer->width; i++)
        {
          color_buffer_get_pixel(buffer,i,j,&red,&green,&blue);

          double_red = red / 255.0;
          double_green = green / 255.0;
          double_blue = blue / 255.0;

          if (brightness < 0.0)
            {
              double_red = double_red * (1.0 + brightness);
              double_green = double_green * (1.0 + brightness);
              double_blue = double_blue * (1.0 + brightness);
            }
          else
            {
              double_red =
                double_red + ((1.0 - double_red) * brightness);
              double_green =
                double_green + ((1.0 - double_green) * brightness);
              double_blue =
                double_blue + ((1.0 - double_blue) * brightness);
            }

          double_red = (double_red - 0.5) *
            (tan((contrast + 1.0) * PI_DIVIDED_4)) + 0.5;
          double_green = (double_green - 0.5) *
            (tan((contrast + 1.0) * PI_DIVIDED_4)) + 0.5;
          double_blue = (double_blue - 0.5) *
            (tan((contrast + 1.0) * PI_DIVIDED_4)) + 0.5;

          if (double_red > 1.0)
            double_red = 1.0;
          else if (double_red < 0.0)
            double_red = 0.0;

          if (double_green > 1.0)
            double_green = 1.0;
          else if (double_green < 0.0)
            double_green = 0.0;

          if (double_blue > 1.0)
            double_blue = 1.0;
          else if (double_blue < 0.0)
            double_blue = 0.0;

          color_buffer_set_pixel(buffer,i,j,
            (unsigned char) (double_red * 255),
            (unsigned char) (double_green * 255),
            (unsigned char) (double_blue * 255));
        }
  }

//----------------------------------------------------------------------

void pt_add_value(t_color_buffer *buffer, int value)

  {
    pt_add_rgb(buffer,value,value,value);
  }

//----------------------------------------------------------------------

void pt_multiply_value(t_color_buffer *buffer, double value)

  {
    unsigned char red, green, blue;
    int help_red, help_green, help_blue;
    unsigned int i, j;

    if (value < 0)
      return;

    for (j = 0; j < buffer->height; j++)
      for (i = 0; i < buffer->width; i++)
        {
          color_buffer_get_pixel(buffer,i,j,&red,&green,&blue);

          help_red = red * value;
          help_green = green * value;
          help_blue = blue * value;

          help_red = help_red > 255 ? 255 : help_red;
          help_green = help_green > 255 ? 255 : help_green;
          help_blue = help_blue > 255 ? 255 : help_blue;

          red = help_red;
          green = help_green;
          blue = help_blue;

          color_buffer_set_pixel(buffer,i,j,red,green,blue);
        }
  }

//----------------------------------------------------------------------

void pt_shift(t_color_buffer *buffer, int shift_x, int shift_y)

  {
    int i, j;
    unsigned char help_red, help_green, help_blue;
    t_color_buffer help_buffer;

    color_buffer_init(&help_buffer,buffer->width,buffer->height);

    for (j = 0; j < (int) buffer->height; j++)
      for (i = 0; i < (int) buffer->width; i++)
        {
          color_buffer_get_pixel(buffer,i,j,&help_red,&help_green,
            &help_blue);

          color_buffer_set_pixel(&help_buffer,i + shift_x, j + shift_y,
            help_red,help_green,help_blue);
        }

    color_buffer_destroy(buffer);
    color_buffer_copy(&help_buffer,buffer);
    color_buffer_destroy(&help_buffer);
  }

//----------------------------------------------------------------------

void pt_rotate(t_color_buffer *buffer, double angle)

  {
    int left_upper_x, left_upper_y, help_x, help_y, help_x2, help_y2;
    unsigned int i, j;
    unsigned char red, green, blue;
    double radius, help_angle;
    t_color_buffer help_buffer;

    radius = sqrt( buffer->width * buffer->width +
              buffer->height * buffer->height ) / 2;

    circle_point_by_angle(buffer->width / 2,buffer->height / 2,
      radius,angle + (((double) 3)/4) * PI,&left_upper_x,&left_upper_y);

    help_angle = angle + PI_TIMES_3_2;

    color_buffer_init(&help_buffer,buffer->width,buffer->height);

    for (j = 0; j < buffer->height; j++)
      {
        line_point(left_upper_x,left_upper_y,help_angle,j,&help_x,
          &help_y);

        for (i = 0; i < buffer->width; i++)
          {
            line_point(help_x,help_y,angle,i,&help_x2,
              &help_y2);

            color_buffer_get_pixel(buffer,help_x2,help_y2,&red,&green,
              &blue);

            color_buffer_set_pixel(&help_buffer,i,j,red,green,blue);
          }
      }

    color_buffer_destroy(buffer);

    color_buffer_copy(&help_buffer,buffer);

    color_buffer_destroy(&help_buffer);
  }

//----------------------------------------------------------------------

void pt_flip(t_color_buffer *buffer, t_direction direction)

  {
    unsigned int i, j;
    unsigned char red, green, blue, red2, green2, blue2;

    if (direction != DIRECTION_HORIZONTAL &&
      direction != DIRECTION_VERTICAL)
      return;

    switch (direction)
      {
        case DIRECTION_HORIZONTAL:

          for (j = 0; j < buffer->height; j++)
            for (i = 0; i < buffer->width / 2; i++)
              {
                color_buffer_get_pixel(buffer,i,j,&red,&green,&blue);
                color_buffer_get_pixel(buffer,buffer->width - i,j,&red2,
                  &green2,&blue2);

                color_buffer_set_pixel(buffer,i,j,red2,green2,blue2);
                color_buffer_set_pixel(buffer,buffer->width - i,j,red,
                  green,blue);
              }

          break;

        case DIRECTION_VERTICAL:

          for (j = 0; j < buffer->height / 2; j++)
            for (i = 0; i < buffer->width; i++)
              {
                color_buffer_get_pixel(buffer,i,j,&red,&green,&blue);
                color_buffer_get_pixel(buffer,i,buffer->height - j,
                  &red2,&green2,&blue2);

                color_buffer_set_pixel(buffer,i,j,red2,green2,blue2);
                color_buffer_set_pixel(buffer,i,buffer->height - j,red,
                  green,blue);
              }

          break;

        case DIRECTION_DIAGONAL_LD_RU:
          break;

        case DIRECTION_DIAGONAL_LU_RD:
          break;
      }
  }

//----------------------------------------------------------------------

void pt_tile(t_color_buffer *buffer, unsigned int times,
  t_color_buffer *destination)

  {
    pt_supersampling(buffer,times,destination);
    pt_change_resolution(destination,buffer->width,buffer->height);
  }

//----------------------------------------------------------------------

void pt_change_resolution(t_color_buffer *buffer,
  unsigned int new_width, unsigned int new_height)

  {
    t_color_buffer help_buffer;
    unsigned int i, j;
    unsigned char red, green, blue;

    color_buffer_init(&help_buffer,new_width,new_height);

    for (j = 0; j < new_height; j++)
      for (i = 0; i < new_width; i++)
        {
          color_buffer_get_pixel(buffer,i,j,&red,&green,&blue);
          color_buffer_set_pixel(&help_buffer,i,j,red,green,blue);
        }

    color_buffer_destroy(buffer);
    color_buffer_init(buffer,new_width,new_height);
    color_buffer_copy(&help_buffer,buffer);
    color_buffer_destroy(&help_buffer);
  }

//----------------------------------------------------------------------

void pt_resize(t_color_buffer *buffer, t_color_buffer *destination,
  t_interpolation_method interpolation)

  {
    unsigned int x,y,x2,y2;
    double position_x,position_y,decimal_part_x,decimal_part_y,
      integer_part;
    unsigned char r,g,b;
    unsigned char tl[3];
    unsigned char tr[3];
    unsigned char bl[3];
    unsigned char br[3];

    if (buffer == NULL || destination == NULL)
      return;

    for (y = 0; y < destination->height; y++)
      for (x = 0; x < destination->width; x++)
        {
          position_x = x / ((double) (destination->width)) *
            buffer->width;
          position_y = y / ((double) (destination->height)) *
            buffer->height;

          x2 = (unsigned int) position_x;
          y2 = (unsigned int) position_y;

          decimal_part_x = modf(position_x,&integer_part);
          decimal_part_y = modf(position_y,&integer_part);

          color_buffer_get_pixel(buffer,x2,y2,&r,&g,&b);
          tl[0] = r;
          tl[1] = g;
          tl[2] = b;

          color_buffer_get_pixel(buffer,x2 + 1,y2,&r,&g,&b);
          tr[0] = r;
          tr[1] = g;
          tr[2] = b;

          color_buffer_get_pixel(buffer,x2,y2 + 1,&r,&g,&b);
          bl[0] = r;
          bl[1] = g;
          bl[2] = b;

          color_buffer_get_pixel(buffer,x2 + 1,y2 + 1,&r,&g,&b);
          br[0] = r;
          br[1] = g;
          br[2] = b;

          interpolate_color_2d(decimal_part_x,decimal_part_y,tl,tr,bl,br,
            &r,&g,&b,interpolation);

          color_buffer_set_pixel(destination,x,y,r,g,b);
        }
  }

//----------------------------------------------------------------------

void pt_supersampling(t_color_buffer *buffer, unsigned int level,
  t_color_buffer *destination)

  {
    unsigned int i, j, k, l, sum_red, sum_green, sum_blue;
    unsigned char red, green, blue;

    color_buffer_init(destination,buffer->width / level,
      buffer->height / level);

    for (j = 0; j < destination->height; j++)
      for (i = 0; i < destination->width; i++)
        {
          sum_red = 0;
          sum_green = 0;
          sum_blue = 0;

          for (k = 0; k < level; k++)          // get 4 x 4 area pixels sums
            for (l = 0; l < level; l++)
              {
                color_buffer_get_pixel(buffer,(level * i) + k,
                  (level * j) + l,&red,&green,&blue);

                sum_red += red;
                sum_green += green;
                sum_blue += blue;
              }

          red = sum_red / (level * level);     // average
          green = sum_green / (level * level);
          blue = sum_blue / (level * level);

          color_buffer_set_pixel(destination,i,j,red,green,blue);
        }
  }

//----------------------------------------------------------------------

void pt_add_buffers(t_color_buffer *buffer1, t_color_buffer *buffer2)

  {
    unsigned int i,j;
    unsigned char red, green, blue;

    for (j = 0; j < buffer1->height; j++)
      for (i = 0; i < buffer1->width; i++)
        {
          color_buffer_get_pixel(buffer1,i,j,&red,&green,&blue);
          color_buffer_add_pixel(buffer2,i,j,red,green,blue);
        }
  }

//----------------------------------------------------------------------

void pt_substract_buffers(t_color_buffer *buffer1,
  t_color_buffer *buffer2)

  {
    unsigned int i,j;
    unsigned char red, green, blue;

    for (j = 0; j < buffer1->height; j++)
      for (i = 0; i < buffer1->width; i++)
        {
          color_buffer_get_pixel(buffer1,i,j,&red,&green,&blue);
          color_buffer_substract_pixel(buffer2,i,j,red,green,blue);
        }
  }

//----------------------------------------------------------------------

void pt_mix_buffers(t_color_buffer *buffer1, t_color_buffer *buffer2,
  t_color_buffer *destination, int percentage, t_mix_type type,
  t_color_buffer *alpha)

  {
    unsigned int i,j;
    unsigned char red1, green1, blue1, red2, green2, blue2;
    int red3, green3, blue3;
    double percentage_double, percentage_double2, divide_by;

    if (buffer1->width != buffer2->width ||
        buffer1->height != buffer2->height)
      return;

    if (percentage < 0)
      percentage = 0;

    if (percentage > 100)
      percentage = 100;

    if (percentage <= 50)
      percentage_double = 1.0;
    else
      percentage_double = (1.0 - (percentage / 100.0)) * 2.0;

    if (percentage >= 50)
      percentage_double2 = 1.0;
    else
      percentage_double2 = (percentage / 100.0) * 2.0;

    color_buffer_init(destination,buffer1->width,buffer1->height);

    for (j = 0; j < buffer1->height; j++)
      for (i = 0; i < buffer1->width; i++)
        {
          if (type == MIX_MULTIPLY)
            { // don't use percentages with multiply:
              percentage_double = 1.0;
              percentage_double2 = 1.0;
            }
          else if (alpha != NULL)
            {
              color_buffer_get_pixel(alpha,i,j,&red1,&green1,&blue1);
              percentage = (red1 / 255.0) * 100;

              if (percentage <= 50)         // recompute the coeficients
                percentage_double = 1.0;
              else
                percentage_double = (1.0 - (percentage / 100.0)) * 2.0;

              if (percentage >= 50)
                percentage_double2 = 1.0;
              else
                percentage_double2 = (percentage / 100.0) * 2.0;
            }

          color_buffer_get_pixel(buffer1,i,j,&red1,&green1,&blue1);

          red1 *= percentage_double;
          green1 *= percentage_double;
          blue1 *= percentage_double;

          color_buffer_get_pixel(buffer2,i,j,&red2,&green2,&blue2);

          red2 *= percentage_double2;
          green2 *= percentage_double2;
          blue2 *= percentage_double2;

          switch (type)
            {
              case MIX_ADD:
                red3 = red1 + red2;
                green3 = green1 + green2;
                blue3 = blue1 + blue2;
                break;

              case MIX_SUBSTRACT:
                red3 = red1 - red2;
                green3 = green1 - green2;
                blue3 = blue1 - blue2;
                break;

              case MIX_AVERAGE:
                divide_by = percentage_double + percentage_double2;

                red3 = (red1 + red2) / divide_by;
                green3 = (green1 + green2) / divide_by;
                blue3 = (blue1 + blue2) / divide_by;
                break;

              case MIX_MULTIPLY:
                red3 = ((red1 / 255.0) * (red2 / 255.0)) * 255;
                green3 = ((green1 / 255.0) * (green2 / 255.0)) * 255;
                blue3 = ((blue1 / 255.0) * (blue2 / 255.0)) * 255 ;
                break;
            }

          color_buffer_set_pixel(destination,i,j,
            round_to_char(red3),
            round_to_char(green3),
            round_to_char(blue3));
        }

    return;
  }

//----------------------------------------------------------------------

void pt_mix_channels(t_color_buffer *buffer_red,
  t_color_buffer *buffer_green, t_color_buffer *buffer_blue,
  t_color_buffer *destination)

  {
    unsigned int i, j;
    unsigned char red, green, blue;

    color_buffer_init(destination,buffer_red->width,buffer_red->height);

    for (j = 0; j < buffer_red->height; j++)
      for (i = 0; i < buffer_red->width; i++)
        {
          color_buffer_get_pixel(buffer_red,i,j,&red,NULL,NULL);
          color_buffer_get_pixel(buffer_green,i,j,NULL,&green,NULL);
          color_buffer_get_pixel(buffer_blue,i,j,NULL,NULL,&blue);

          color_buffer_set_pixel(destination,i,j,red,green,blue);
        }
  }

//----------------------------------------------------------------------

void pt_convolution(t_color_buffer *buffer, t_matrix *matrix)

  {
    unsigned int i, j, k, l, half_width, half_height;
    double sum_red, sum_green, sum_blue;
    unsigned char red, green, blue;
    t_color_buffer help_buffer;

    color_buffer_copy(buffer,&help_buffer);

    half_width = matrix->width / 2;
    half_height = matrix->height / 2;

    for (i = 0; i < buffer->width; i++)
      for (j = 0; j < buffer->height; j++)
        {
          sum_red = 0;
          sum_green = 0;
          sum_blue = 0;

          for (k = 0; k < matrix->width; k++)
            for (l = 0; l < matrix->height; l++)
              {
                color_buffer_get_pixel(&help_buffer,
                  i - half_width + k,j - half_height + l,
                  &red,&green,&blue);

                sum_red +=
                  matrix_get_value(matrix,k,l) * red;

                sum_green +=
                  matrix_get_value(matrix,k,l) * green;

                sum_blue +=
                  matrix_get_value(matrix,k,l) * blue;
              }

          if (sum_red > 255)
            sum_red = 255;
          if (sum_green > 255)
            sum_green = 255;
          if (sum_blue > 255)
            sum_blue = 255;
          if (sum_red < 0)
            sum_red = 0;
          if (sum_green < 0)
            sum_green = 0;
          if (sum_blue < 0)
            sum_blue = 0;

          color_buffer_set_pixel(buffer,i,j,(unsigned char) sum_red,
            (unsigned char) sum_green,(unsigned char) sum_blue);
        }

    color_buffer_destroy(&help_buffer);
  }

//----------------------------------------------------------------------

void pt_convolution_3x3(t_color_buffer *buffer, double a1, double a2,
  double a3, double b1, double b2, double b3, double c1, double c2,
  double c3)

  {
    t_matrix matrix;

    matrix_init(&matrix,3,3);

    matrix_set_value(&matrix,0,0,a1);
    matrix_set_value(&matrix,0,1,a2);
    matrix_set_value(&matrix,0,2,a3);
    matrix_set_value(&matrix,1,0,b1);
    matrix_set_value(&matrix,1,1,b2);
    matrix_set_value(&matrix,1,2,b3);
    matrix_set_value(&matrix,2,0,c1);
    matrix_set_value(&matrix,2,1,c2);
    matrix_set_value(&matrix,2,2,c3);

    pt_convolution(buffer,&matrix);

    matrix_destroy(&matrix);
  }

//----------------------------------------------------------------------

void pt_voronoi_diagram(t_voronoi_type type, t_metric metric,
  t_point_place_type point_place,  unsigned int parameter1,
  unsigned int parameter2, unsigned int parameter3[][2],
  t_color_buffer *destination)

  {
    unsigned int i, j, k, center_x, center_y, quadrant, side_length,
      duplicate_exists,           // says if there are duplicate points
      use_tree, mean_dimension, number_of_points;
    double shortest_distance, shortest_distance2, distance_ratio,
      help_distance, angle;
    unsigned char color;
    int (*point_array)[2];
    int help_x, help_y;
    int help_color;
    t_kd_tree search_tree;        /* for faster nearest neighbour search
                                     if needed */

                       // determine number of points we'll be generating

    if (point_place == PLACE_RANDOM || point_place == PLACE_CIRCLE)
      number_of_points = parameter2;
    else if (point_place == PLACE_CUSTOM)
      number_of_points = parameter1;
    else if (point_place == PLACE_CROSS_HORIZONTAL || point_place ==
      PLACE_CROSS_DIAGONAL)
      number_of_points = (parameter2 - 1) * 4 + 1;
    else if (point_place == PLACE_SQUARE)
      number_of_points = (parameter2 - 1) * 4;

    point_array = malloc(number_of_points * 2 * sizeof(int));

    if (point_array == NULL)
      return;

    center_x = destination->width / 2;   // center pixel coordinaitons
    center_y = destination->height / 2;
                                         // also serves as circle radius
    side_length = parameter1 > 100 ? 100 : parameter1;
    side_length = (int) (parameter1 * 0.01 * destination->width);

    switch(point_place)           // generate points
      {
        case PLACE_RANDOM:

          for (i = 0; i < parameter2; i++)
            {
              do
                {
                  point_array[i][0] = abs((int) (noise(i + parameter1
                    * 2) * destination->width));

                  point_array[i][1] = abs((int) (noise(i * 10 +
                    parameter1) * destination->height));

                  duplicate_exists = 0;
                              // checks if there are no duplicate points
                  for (j = 0; j < i; j++)
                    if (point_array[j][0] == point_array[i][0] &&
                      point_array[j][1] == point_array[i][1])
                      {
                        duplicate_exists = 1;
                        parameter1++; // make sure to generate different
                        break;        // points ones next time
                      }

                } while (duplicate_exists);
            }
          break;

        case PLACE_SQUARE:
                                      // distance between two points
          help_distance = ((double) side_length) / (parameter2 - 1);
                                      // set starting points
          point_array[0][0] = center_x - side_length / 2;
          point_array[0][1] = center_y - side_length / 2;
          point_array[1][0] = center_x + side_length / 2;
          point_array[1][1] = center_y - side_length / 2;
          point_array[2][0] = center_x + side_length / 2;
          point_array[2][1] = center_y + side_length / 2;
          point_array[3][0] = center_x - side_length / 2;
          point_array[3][1] = center_y + side_length / 2;

          for (i = 0; i < parameter2 - 1; i++)

            {                // make all other points for all four sides
              point_array[(i + 1) * 4][0] = point_array[0][0] +
                (i + 1) * help_distance;
              point_array[(i + 1) * 4][1] = point_array[0][1];
              point_array[(i + 1) * 4 + 1][0] = point_array[1][0];
              point_array[(i + 1) * 4 + 1][1] = point_array[1][1] +
                (i + 1) * help_distance;
              point_array[(i + 1) * 4 + 2][0] = point_array[2][0] -
                (i + 1) * help_distance;
              point_array[(i + 1) * 4 + 2][1] = point_array[2][1];
              point_array[(i + 1) * 4 + 3][0] = point_array[3][0];
              point_array[(i + 1) * 4 + 3][1] = point_array[3][1] -
                (i + 1) * help_distance;
            }

          break;

        case PLACE_CROSS_HORIZONTAL:
        case PLACE_CROSS_DIAGONAL:
                        // horizontal / vertical distance between points

          if (point_place == PLACE_CROSS_DIAGONAL)
            help_distance = sqrt((side_length / (parameter2 - 1)) *
              (side_length / (parameter2 - 1)) / 2);
          else
            help_distance = side_length / (parameter2 - 1);

          point_array[0][0] = center_x;          // center point
          point_array[0][1] = center_y;

          for (i = 0; i < parameter2 - 1; i++)   // sides
            {
              j = help_distance * (i + 1);       // precompute the step

              if (point_place == PLACE_CROSS_DIAGONAL)  // diagonal
                {
                  point_array[i * 4 + 1][0] = center_x - j;
                  point_array[i * 4 + 1][1] = center_y - j;
                  point_array[i * 4 + 2][0] = center_x + j;
                  point_array[i * 4 + 2][1] = center_y + j;
                  point_array[i * 4 + 3][0] = center_x - j;
                  point_array[i * 4 + 3][1] = center_y + j;
                  point_array[i * 4 + 4][0] = center_x + j;
                  point_array[i * 4 + 4][1] = center_y - j;
                }
              else                                      // horizontal
                {
                  point_array[i * 4 + 1][0] = center_x - j;
                  point_array[i * 4 + 1][1] = center_y;
                  point_array[i * 4 + 2][0] = center_x + j;
                  point_array[i * 4 + 2][1] = center_y;
                  point_array[i * 4 + 3][0] = center_x;
                  point_array[i * 4 + 3][1] = center_y + j;
                  point_array[i * 4 + 4][0] = center_x;
                  point_array[i * 4 + 4][1] = center_y - j;
                }
            }

          break;

        case PLACE_CIRCLE:
                                                 // angle between points
          help_distance = 2 * PI / number_of_points;
          angle = 0.0;
          quadrant = 0;

          for (i = 0; i < number_of_points; i++)
            {
              help_y = sin(angle) * side_length;
              help_x = sqrt(side_length * side_length - help_y *
                help_y);

              switch (quadrant) // place the point in the right quadrant
                {
                  case 0:
                    point_array[i][0] = center_x + help_x;
                    point_array[i][1] = center_y - help_y;
                    break;

                  case 1:
                    point_array[i][0] = center_x - help_y;
                    point_array[i][1] = center_y - help_x;
                    break;

                  case 2:
                    point_array[i][0] = center_x - help_x;
                    point_array[i][1] = center_y + help_y;
                    break;

                  case 3:
                    point_array[i][0] = center_x + help_y;
                    point_array[i][1] = center_y + help_x;
                    break;
                }

              angle += help_distance;           // move to next point

              if (angle > PI / 2)               // quadrant crossed
                {
                  quadrant++;
                  angle -= PI / 2;
                }
            }


          break;

        case PLACE_CUSTOM:
                                       // copy the input buffer point
          for (i = 0; i < number_of_points; i++)
            {
              point_array[i][0] = parameter3[i][0];
              point_array[i][1] = parameter3[i][1];
            }
          break;
      }

    pt_color_fill(destination,255,255,255);

    mean_dimension = (destination->width + destination->height) / 2;

    // if there is a lot of points to test then use k-d tree
    if ((number_of_points >= 300 || mean_dimension >= 1000000) &&
      metric == METRIC_EUCLIDEAN && type == VORONOI_DISTANCE)
      {
        use_tree = 1;
        kd_tree_init(&search_tree,point_array,number_of_points);
      }
    else
      use_tree = 0;
                                     // set the color of each pixel
    for (i = 0; i < destination->width; i++)
      for (j = 0; j < destination->height; j++)
        {
          if (use_tree)
            {
              kd_tree_find_nearest_neighbour(&search_tree,i,j,&help_x,
                &help_y,destination->width,destination->height);
              shortest_distance = get_distance(METRIC_EUCLIDEAN,help_x,
                help_y,i,j,destination->width,destination->height);
              shortest_distance2 = 0;  /* this variable will not be used
                                          when using k-d tree */
            }
          else
            {                      // not using tree (using brute force)
              shortest_distance = 100000000;    // set some high numbers
              shortest_distance2 = 100000000;
              help_x = 0;
              help_y = 0;

              for (k = 0; k < number_of_points; k++) // find two nearest
                {                                    // points distances
                  help_distance = get_distance(metric,i,j,
                      point_array[k][0], point_array[k][1],
                      destination->width,destination->height);

                  if (help_distance < shortest_distance)
                    {
                      shortest_distance2 = shortest_distance;
                      shortest_distance = help_distance;
                      help_x = point_array[k][0];
                      help_y = point_array[k][1];
                    }
                  else if (help_distance < shortest_distance2)
                    shortest_distance2 = help_distance;
              }
            }

          switch (type)
            {
              case VORONOI_DISTANCE:
                help_distance = shortest_distance * 5;
                help_color = (help_distance / mean_dimension) * 255;

                if (help_color > 255)
                  color = 255;
                else
                  color = help_color;
                break;

              case VORONOI_2_NEAREST_RATIO:
                if (shortest_distance < shortest_distance2)
                  distance_ratio =
                    shortest_distance /shortest_distance2;
                else
                  distance_ratio =
                    shortest_distance2 / shortest_distance;

                color = (unsigned char) (distance_ratio * 255);
                break;

              case VORONOI_NEAREST_HASH:
                help_color = noise(help_x + help_y) * 255;
                help_color = help_color < 0 ? -1 * help_color :
                  help_color;
                color = round_to_char(help_color);
                break;
            }

          color_buffer_set_pixel(destination,i,j,color,color,color);
        }

    if (use_tree)
      kd_tree_destroy(&search_tree);

    free(point_array);
  }

//----------------------------------------------------------------------

void pt_voronoi_diagram_random(t_voronoi_type type, t_metric metric,
   int random, int points, t_color_buffer *destination)

  {
    pt_voronoi_diagram(type,metric,PLACE_RANDOM,random,points,NULL,
      destination);
  }

//----------------------------------------------------------------------

void pt_voronoi_diagram_simple(int random, int points,
  t_color_buffer *destination)

  {
    pt_voronoi_diagram(VORONOI_2_NEAREST_RATIO,METRIC_EUCLIDEAN,
      PLACE_RANDOM,random,points,NULL,destination);
  }

//----------------------------------------------------------------------

void pt_simple_noise(int random, unsigned char amplitude, int grayscale,
  t_color_buffer *destination)

  {
    unsigned int i, j;
    unsigned char red, green ,blue;

    if (amplitude > 127)
      amplitude = 127;

    random = random * 64;    /* shift the number so the noise looks more
                                random for numbers that only differs by
                                low amount */

    for (j = 0; j < destination->height; j++)
      for (i = 0; i < destination->width; i++)
        {
          red = 128 + amplitude * noise(random);
          random++;

          if (grayscale)
            {
              green = red;
              blue = red;
            }
          else
            {
              green = 128 + amplitude * noise(random);
              random++;
              blue = 128 + amplitude * noise(random);
              random++;
            }

          color_buffer_set_pixel(destination,i,j,red,green,blue);
        }
  }

//----------------------------------------------------------------------

void pt_perlin_noise(int random, unsigned char base_amplitude,
  unsigned int base_frequency, int max_iterations,
  t_interpolation_method interpolation, t_color_buffer *destination,
  int smooth)

  {
    unsigned int x,y;
    unsigned char r,g,b,r2,g2,b2;
    int iteration;
    t_color_buffer noise_buffer,help_buffer;
    double height_ratio;                 // height to width ratio

    if (destination == NULL)
      return;

    height_ratio = destination->height / ((double) destination->width);

    pt_color_fill(destination,128,128,128);   // base level color

    color_buffer_init(&help_buffer,destination->width,
      destination->height);

    iteration = 0;

    while (1)
      {
        if ((max_iterations >= 0 && iteration >= max_iterations) ||
          base_amplitude == 0 ||
          (base_frequency > destination->width &&
          base_frequency > destination->height))
          break;

        color_buffer_init(&noise_buffer,base_frequency,
          base_frequency * height_ratio);

        pt_simple_noise(random,base_amplitude,1,&noise_buffer);
        random += 80124;     // some random value

        pt_resize(&noise_buffer,&help_buffer,interpolation);

        if (smooth && base_frequency < 10)
          pt_blur(&help_buffer,10 - base_frequency);

        // add the values:

        for (y = 0; y < destination->height; y++)
          for (x = 0; x < destination->width; x++)
            {
              color_buffer_get_pixel(destination,x,y,&r,&g,&b);
              color_buffer_get_pixel(&help_buffer,x,y,&r2,&g2,&b2);

              color_buffer_set_pixel(destination,x,y,
                round_to_char(r + r2 - 128),
                round_to_char(g + g2 - 128),
                round_to_char(b + b2 - 128));
            }

        color_buffer_destroy(&noise_buffer);

        base_frequency *= 2;
        base_amplitude /= 2;
        iteration++;
      }

    color_buffer_destroy(&help_buffer);
  }

//----------------------------------------------------------------------

void pt_fault_formation_noise(int random, t_color_buffer *destination)

  {
    int number1, number2, number3, number4, direction, limit1, limit2,
      d1, d2, i, j, k, half_resolution, border1, border2, shift_x,
      shift_y;
    unsigned char level1, level2;
    double step1, step2;
    t_color_buffer help_buffer;

    direction = 0;      // 0 => x direction, 1 => y direction

    pt_color_fill(destination,0,0,0);

    color_buffer_init(&help_buffer,destination->width,
      destination->height);

    level1 = 0;
    level2 = 3;                  // empiric value 1

    for (j = 0; j < 200; j++)    // empiric value 2
      {
        if (direction)
          {
            limit1 = destination->width;
            limit2 = destination->height;
            half_resolution = destination->height / 2;
          }
        else
          {
            limit1 = destination->height;
            limit2 = destination->width;
            half_resolution = destination->width / 2;
          }
                                 // initial points of triangles
        number1 = noise_int_range(random,0,limit1);
        random++;
        number2 = noise_int_range(random,number1,limit1);
        random++;                // top points of triangles
        number3 = noise_int_range(random,0,limit1);
        random++;
        number4 = noise_int_range(random,number3,limit1);
        random++;

        d1 = number3 - number1;  // point differences
        d2 = number4 - number2;

        step1 = ((double) d1) / half_resolution;
        step2 = ((double) d2) / half_resolution;

        for (i = 0; i <= limit2 / 2; i++)
          {
            border1 = number1 + step1 * i;
            border2 = number2 + step2 * i;

            if (direction)
              {                    // this copied cody is kind of sad :/
                for (k = 0; k < border1; k++)
                  {
                    color_buffer_set_pixel(&help_buffer,i,k,level1,
                      level1,level1);
                    color_buffer_set_pixel(&help_buffer,limit2 - i,k,
                      level1,level1,level1);
                  }
                for (k = border1; k < border2; k++)
                  {
                    color_buffer_set_pixel(&help_buffer,i,k,level2,
                      level2,level2);
                    color_buffer_set_pixel(&help_buffer,limit2 - i,k,
                      level2,level2,level2);
                  }
                for (k = border2; k <= limit1; k++)
                  {
                    color_buffer_set_pixel(&help_buffer,i,k,level1,
                      level1,level1);
                    color_buffer_set_pixel(&help_buffer,limit2 - i,k,
                      level1,level1,level1);
                  }
              }
            else
              {
                for (k = 0; k < border1; k++)
                  {
                    color_buffer_set_pixel(&help_buffer,k,i,level1,
                      level1,level1);
                    color_buffer_set_pixel(&help_buffer,k,limit2 - i,
                      level1,level1,level1);
                  }
                for (k = border1; k < border2; k++)
                  {
                    color_buffer_set_pixel(&help_buffer,k,i,level2,
                      level2,level2);
                    color_buffer_set_pixel(&help_buffer,k,limit2 - i,
                      level2,level2,level2);
                  }
                for (k = border2; k <= limit1; k++)
                  {
                    color_buffer_set_pixel(&help_buffer,k,i,level1,
                      level1,level1);
                    color_buffer_set_pixel(&help_buffer,k,limit2 - i,
                      level1,level1,level1);
                  }
              }
          }

        shift_x = noise_int_range(random,0,destination->width);
        random++;
        shift_y = noise_int_range(random,0,destination->height);
        random++;

        pt_shift(&help_buffer,shift_x,shift_y);
        pt_add_buffers(&help_buffer,destination);

        if (level2 == 0)
          break;

        direction = direction ? 0 : 1;   // switch direction
      }

    color_buffer_destroy(&help_buffer);
  }

//----------------------------------------------------------------------

void pt_substrate(int random, int iterate, unsigned int number,
  t_fill_type fill_type, int fill_grayscale,
  t_color_buffer *destination)

  {
    unsigned int iteration, i, step, total_step, new_lines_space,
      number_of_lines, number_of_iterations;
    int x, y, x2, y2, continue_drawing, length, random_shift,
      stop_iterating, help_length;
    double angle, new_angle;
    unsigned char red, green, blue;
    t_line_list list;   // list of lines

    random *= 32;       // make closer number generate more random lines

    line_list_init(&list);

    if (iterate)
      {
        number_of_lines = 4;      // empiric value
        number_of_iterations = number;
      }
    else
      {
        number_of_lines = number;
        number_of_iterations = 1;
      }
                                  // generate lines
    for (i = 0; i < number_of_lines; i++)
      {
        x = noise_int_range(random,0,destination->width);
        random++;
        y = noise_int_range(random,0,destination->height);
        random++;
        angle = PI + noise(random) * PI;
        random++;
        line_list_add(&list,x,y,angle,0);
      }

    pt_color_fill(destination,255,255,255);
    continue_drawing = 1;
    step = 0;
    iteration = 0;
    new_lines_space = destination->width / 4;
    random_shift = (int) noise(random);    // random shift by 1 pixel
    stop_iterating = 0;
    random++;
    total_step = 0;

    while (continue_drawing)
      {
        continue_drawing = 0;

        help_length = line_list_get_length(&list);

        for (i = 0; (int) i < help_length; i++)
          {
            line_list_get(&list,i,&x,&y,&angle,&length);

            if (length >= 0)
              {
                line_point(x,y,angle,length,&x2,&y2);

                                                      // make a new line
                if (iterate && !stop_iterating && length != 0 &&
                  (length % (new_lines_space + random_shift) == 0))
                  {
                    new_angle = noise(random) > 0 ?
                      angle + PI_DIVIDED_2 : angle - PI_DIVIDED_2;

                    random++;

                    random_shift = (int) noise(random);

                    random++;

                    line_list_add(&list,x2,y2,new_angle,1);
                  }

                color_buffer_get_pixel(destination,x2,y2,&red,&green,
                  &blue);

                if (red != 0) // we can draw here
                  {
                    color_buffer_set_pixel(destination,x2,y2,0,0,0);
                    continue_drawing = 1;      /* at least one point has
                                                  been drawn */
                    line_list_set(&list,i,x,y,angle,length + 1);
                  }
                else          // colission with another line => stop
                  {
                    line_list_set(&list,i,x,y,angle,-1);
                  }
              }
                              /* after 4 new lines for each line start a
                                 new iteration */
          }

        if (!stop_iterating && step >= new_lines_space * 2)
          {
            iteration++;
            new_lines_space = new_lines_space * 0.6;
            step = 0;
          }

        if (new_lines_space == 0)
          stop_iterating = 1;

        if (iteration >= number_of_iterations)
          stop_iterating = 1;

        step++;
        total_step++;
      }

    if (fill_type != FILL_NONE)             // fill the areas with color
      {
        for (y = 0; ((unsigned int) y) < destination->height; y++)
          for (x = 0; ((unsigned int) x) < destination->width; x++)
            {
              color_buffer_get_pixel(destination,x,y,&red,&green,&blue);

                                            // only fill white areas
              if (red == 255 && green == 255 && blue == 255)
                {
                  /* we only use 255 level so we don't get black which
                     might mess it all up with the borders later    */

                  red = noise_int_range(random,0,254);
                  random++;

                  if (fill_grayscale)
                    {
                      green = red;
                      blue = red;
                    }
                  else
                    {
                      green = noise_int_range(random,0,254);
                      random++;
                      blue = noise_int_range(random,0,254);
                      random++;
                    }

                  _pt_floodfill(destination,x,y,red,green,blue);
                }
            }
      }

    if (fill_type == FILL_NO_BORDERS)
      {
        for (y = 0; ((unsigned int) y) < destination->height; y++)
          for (x = 0; ((unsigned int) x) < destination->width; x++)
            {
              color_buffer_get_pixel(destination,x,y,&red,&green,&blue);

              // get rid of black borders by copying the left neighbour
              if (red == 0 && green == 0 && blue == 0)
                {
                  color_buffer_get_pixel(destination,x - 1,y,&red,
                    &green,&blue);
                  color_buffer_set_pixel(destination,x,y,red,green,
                    blue);
                }
            }
      }

    line_list_destroy(&list);
  }

//----------------------------------------------------------------------

void pt_substrate_simple(int random, int iterations, int fill,
  t_color_buffer *destination)

  {
    if (fill)
      pt_substrate(random,1,iterations,FILL_KEEP_BORDERS,0,destination);
    else
     pt_substrate(random,1,iterations,FILL_NONE,0,destination);
  }

//----------------------------------------------------------------------

void pt_marble(int random, unsigned int periods, unsigned int intensity,
  t_direction direction, unsigned int amplitude,
  t_color_buffer *destination, t_color_buffer *noise_source)

  {
    unsigned int i, j;
    unsigned char red, green, blue;
    int external_noise_source;
    double parameter, noise_affect, sin_value, intensity_double,
      coordination;
    t_color_buffer noise_buffer;

    external_noise_source = 0;

    if (noise_source != NULL)
      {
        external_noise_source = 1;
      }
    else
      {
        color_buffer_init(&noise_buffer,destination->width,
          destination->height);

        noise_source = &noise_buffer;

        pt_perlin_noise(random,128,5,-1,INTERPOLATION_LINEAR,
          noise_source,1);
      }

    if (intensity > 10)
      intensity = 10;

    if (amplitude > 127)
      amplitude = 127;


    intensity =
      (unsigned int) ((destination->width / 500.0) * intensity);

    intensity_double = intensity / 10.0;

    for (j = 0; j < noise_source->height; j++)
      for (i = 0; i < noise_source->width; i++)
        {
          color_buffer_get_pixel(noise_source,i,j,&red,&green,&blue);

          noise_affect = (((double) red) / 255) * intensity_double;

          switch (direction)
            {
              case DIRECTION_HORIZONTAL:
                coordination = (double) i;
                break;

              case DIRECTION_VERTICAL:
                coordination = (double) j;
                break;

              case DIRECTION_DIAGONAL_LD_RU:
                coordination = (double) ((destination->width - i) + j);
                break;

              case DIRECTION_DIAGONAL_LU_RD:
                coordination = (double) (i + j);
                break;
            }

          parameter = (coordination / noise_source->width
            + noise_affect) * (periods * PI_TIMES_2);

          sin_value = sin(parameter);

          red = round_to_char(127 + sin_value * amplitude);

          color_buffer_set_pixel(destination,i,j,red,red,red);
        }

    if (!external_noise_source)
      {
        color_buffer_destroy(&noise_buffer);
      }
  }

//----------------------------------------------------------------------

void pt_wood(int random, unsigned int circles, unsigned int hardness,
  unsigned int intensity, t_direction direction, unsigned int amplitude,
  t_color_buffer *destination, t_color_buffer *noise_source)

  {
    unsigned int radius;           // basic circle radius
    int i,j;
    int offset;
    int dx,dy,dx_squared,dy_squared;
    unsigned char r,g,b;
    double distance;
    int external_noise_source;
    unsigned int middle_x,middle_y;
    unsigned char value;
    t_color_buffer noise_buffer;   // in case there's no extrernal noise


    intensity = (unsigned int)
      ((((double) destination->width) / 100) * intensity);

    if (noise_source != NULL)
      {
        external_noise_source = 1;
      }
    else
      {
        color_buffer_init(&noise_buffer,destination->width,
          destination->height);

        noise_source = &noise_buffer;

        pt_perlin_noise(random,128,5,-1,INTERPOLATION_LINEAR,
          noise_source,1);
      }

    radius = destination->width >= destination->height ?
      destination->width / 2 : destination->height / 2;

    middle_x = destination->width / 2;
    middle_y = destination->height / 2;

    pt_color_fill(destination,255,255,255);

    if (hardness == 0)    // 0 not allowed
      hardness = 2;
    else
      hardness *= 2;      // can't be odd

    for (j = -1 * intensity; j < (int) (destination->height + intensity); j++)
      {
        for (i = -1 * intensity; i < (int) (destination->width + intensity); i++)
          {
            color_buffer_get_pixel(noise_source,i,j,&r,&g,&b);


            color_buffer_get_pixel(noise_source,i,j,&r,&g,&b);
            offset = intensity * (((double) r) / 255);

            if (direction == DIRECTION_HORIZONTAL ||
            direction == DIRECTION_DIAGONAL_LU_RD)
              {
                dx = middle_x - i + offset;
              }
            else if (direction == DIRECTION_DIAGONAL_LD_RU)
              {
                dx = middle_x - i - offset;
              }
            else
              {
                dx = middle_x - i;
              }

            dx_squared = dx * dx;

            if (direction == DIRECTION_VERTICAL ||
            direction == DIRECTION_DIAGONAL_LU_RD ||
            direction == DIRECTION_DIAGONAL_LD_RU)
              {
                dy = middle_y - j + offset;
              }
            else
              {
                dy = middle_y - j;
              }

            dy_squared = dy * dy;

            distance = sqrt(dx_squared + dy_squared);

            if (distance > radius)
              {
                value = 255;
              }
            else
              {
                value = 255 - round_to_char(pow(sin(distance / radius *
                  circles * PI),hardness) * amplitude);
              }

            color_buffer_get_pixel(destination,i,j,&r,&g,&b);

            value = r > value ? value : r;  // assign darker value

            color_buffer_set_pixel(destination,i,j,value,value,
              value);
          }
      }

    if (!external_noise_source)
      {
        color_buffer_destroy(&noise_buffer);
      }
  }

//----------------------------------------------------------------------

void pt_wood_simple(int random, unsigned int intensity,
  unsigned int amplitude, t_color_buffer *destination)

  {
    pt_wood(random,5,3,intensity,DIRECTION_HORIZONTAL,amplitude,
      destination,NULL);
  }

//----------------------------------------------------------------------

void pt_marble_simple(int random, unsigned int intensity,
  unsigned int amplitude, t_color_buffer *destination)

  {
    pt_marble(random,4,intensity,DIRECTION_HORIZONTAL,amplitude,
      destination,NULL);
  }

//----------------------------------------------------------------------

void pt_particle_movement(t_color_buffer *noise_buffer,
  unsigned int particles, double position_x, double position_y,
  unsigned int angle, unsigned int spread, double velocity,
  t_color_buffer *destination)

  {
    unsigned int i, j;
    int (*particle_coordinations)[2];     // array of coordinations
    double *particle_angles;              // array of angles
    double *particle_velocities;          // array of velocities
    double initial_angle, angle_difference;
    int continue_computing, x, y;
    unsigned char red, green, blue;

    if (noise_buffer == NULL)
      return;

    particle_angles = (double *) malloc(particles * sizeof(double));
    particle_velocities = (double *) malloc(particles * sizeof(double));
    particle_coordinations = (int (*)[2])
      malloc(particles * 2 * sizeof(int));

    if (particle_angles == NULL || particle_velocities == NULL ||
      particle_coordinations == NULL)
      {
        if (particle_angles != NULL)
          free(particle_angles);

        if (particle_velocities != NULL)
          free(particle_velocities);

        if (particle_coordinations != NULL)
          free(particle_coordinations);

        return;
      }

    position_x = saturate_double(position_x,0.0,1.0);
    position_y = saturate_double(position_y,0.0,1.0);
    angle = saturate_int(angle,0,360);
    spread = saturate_int(spread,0,360);

    initial_angle = degrees_to_radians(angle);
    angle_difference = degrees_to_radians(spread);

    color_buffer_init(destination,noise_buffer->width,
      noise_buffer->height);

    pt_color_fill(destination,0,0,0);

    if (particles == 0)
      {
        free(particle_angles);
        free(particle_velocities);
        free(particle_coordinations);

        return;
      }

    velocity = velocity * 0.01 * noise_buffer->width;

    x = position_x * (destination->width - 1);
    y = position_y * (destination->height - 1);

    for (i = 0; i < particles; i++) // initialise particles
      {
        particle_coordinations[i][0] = x;
        particle_coordinations[i][1] = y;

        particle_angles[i] =
          initial_angle +
          (i / (double) (particles - 1)) * angle_difference * 2 -
          angle_difference;

        particle_velocities[i] = velocity;
      }

    continue_computing = 1;

    while (continue_computing) // iterations
      {
        continue_computing = 0;

        for (i = 0; i < particles; i++) // one step for each particle
          {
            for (j = 0; j < (unsigned int) particle_velocities[i]; j++)
              {
                line_point(particle_coordinations[i][0],
                particle_coordinations[i][1],particle_angles[i],j,
                &x,&y);

                red = particle_velocities[i] / velocity * 100;

                color_buffer_add_pixel(destination,x,y,red,red,red);
              }

            line_point(particle_coordinations[i][0],
              particle_coordinations[i][1],particle_angles[i],j,
              &x,&y);

            particle_coordinations[i][0] = x;
            particle_coordinations[i][1] = y;

            particle_velocities[i] *= 0.95;

            color_buffer_get_pixel(noise_buffer,
            particle_coordinations[i][0],
            particle_coordinations[i][1],
            &red,&green,&blue);

            // adjust the angle depending on the noise in the buffer:
            particle_angles[i] += (127 - red) / 127.0 *
              PI_DIVIDED_2;

            color_buffer_get_pixel(noise_buffer,
              particle_coordinations[i][1],
              particle_coordinations[i][0],
              &red,&green,&blue);

            if (particle_velocities[i] > 0.5)
              continue_computing = 1;
          }
      }

    free(particle_angles);
    free(particle_velocities);
    free(particle_coordinations);
  }

//----------------------------------------------------------------------

void pt_particle_movement_color(t_color_buffer *noise_buffer,
  unsigned int particles, double position_x, double position_y,
  unsigned int angle, unsigned int spread, double velocity,
  t_color_buffer *destination, unsigned char red, unsigned char green,
  unsigned char blue)

  {
    t_color_transition transition;
    color_transition_init(&transition);

    color_transition_add_point(0,255,255,255,&transition);
    color_transition_add_point(255,red,green,blue,&transition);
    pt_particle_movement(noise_buffer,particles,position_x,position_y,
      angle,spread,velocity,destination);
    pt_map_to_transition(destination,&transition);
    color_transition_destroy(&transition);
  }

//----------------------------------------------------------------------

void pt_particles_simple(unsigned int particles, unsigned int sources,
  double velocity, unsigned char red, unsigned char green,
  unsigned char blue, t_color_buffer *destination, int random)

  {
    unsigned int i;
    double x,y;
    t_color_buffer help_buffer,noise_buffer;
    t_color_transition transition;

    if (destination == NULL)
      return;

    color_buffer_init(&noise_buffer,destination->width,
      destination->height);
    pt_perlin_noise(random,100,5,-1,INTERPOLATION_SINE,&noise_buffer,1);
    random++;
    color_transition_init(&transition);
    color_transition_add_point(0,255,255,255,&transition);
    color_transition_add_point(255,red,green,blue,&transition);

    pt_color_fill(destination,0,0,0);

    for (i = 0; i < sources; i++)
      {
        x = noise(random);

        if (x < 0.0)
          x = -1 * x;

        random++;

        y = noise(random);

        if (y < 0.0)
          y = -1 * y;

        random++;

        pt_particle_movement(&noise_buffer,particles,x,y,0,360,velocity,
          &help_buffer);

        pt_add_buffers(&help_buffer,destination);
        color_buffer_destroy(&help_buffer);
        random++;
      }

    pt_map_to_transition(destination,&transition);
    color_transition_destroy(&transition);
    color_buffer_destroy(&noise_buffer);
  }

//----------------------------------------------------------------------

void pt_transformation_circle(t_color_buffer *buffer, int radius,
  unsigned int repeat, t_color_buffer *destination)

  {
    unsigned int i, j, k;
    int current_x, current_y;
    unsigned char red, green, blue, average;
    double angle;

    color_buffer_init(destination,buffer->width,buffer->height);

    radius = radius > 100 ? 100 : radius;
    radius = radius < 0 ? 0 : radius;
    radius = radius * 0.01 * buffer->width;

    for (j = 0; j < buffer->height; j++)
      for (i = 0; i < buffer->width; i++)
        {
          current_x = i;
          current_y = j;

          for (k = 0; k < repeat; k++)
            {
              color_buffer_get_pixel(buffer,current_x,current_y,&red,
                &green,&blue);

              average = (red + green + blue) / 3;

              angle = 2 * PI * (((double) average) / 255);

              circle_point_by_angle(current_x,current_y,radius,angle,
                &current_x,&current_y);
              color_buffer_get_pixel(buffer,current_x,current_y,&red,
                &green,&blue);
              color_buffer_set_pixel(destination,i,j,red,green,blue);
            }
        }
  }

//----------------------------------------------------------------------

void pt_transformation_radius(t_color_buffer *buffer,
  unsigned int radius_min, unsigned int radius_max, int rotate_left,
  int go_horizontal, t_color_buffer *destination)

  {
    unsigned int i, j, radius_difference;
    unsigned char red, green, blue;
    int x, y, average;
    double angle, radius;

    if (radius_min > radius_max)
      return;

    color_buffer_init(destination,buffer->width,buffer->height);

    radius_difference = radius_max - radius_min;

    for (j = 0; j < buffer->height; j++)
      for (i = 0; i < buffer->width; i++)
        {
          color_buffer_get_pixel(buffer,i,j,&red,&green,&blue);
          average = (red + green + blue) / 3;
          radius = radius_min + (average / 255.0) * radius_difference;

          if (go_horizontal)
            angle = ((double) i) / buffer->width;
          else
            angle = ((double) j) / buffer->height;

          angle = angle + ((double) j) / buffer->height;

          if (angle > 1.0)
            angle = angle - 1;

          angle = angle * PI_TIMES_2;

          if (!rotate_left)
            angle = PI_TIMES_2 - angle;

          circle_point_by_angle(i,j,radius,angle,&x,&y);

          color_buffer_get_pixel(buffer,x,y,&red,&green,&blue);
          color_buffer_set_pixel(destination,i,j,red,green,blue);
        }
  }

//----------------------------------------------------------------------

void pt_transformation_sine(t_color_buffer *buffer, double phase,
  int periods, unsigned char amplitude, t_color_buffer *destination)

{
  unsigned int i, j;
  unsigned char red, green, blue, average;
  double angle;

  color_buffer_init(destination,buffer->width,buffer->height);

  if (periods <= 0)
    periods = 1;

  if (amplitude > 128)
    amplitude = 128;

  for (j = 0; j < buffer->height; j++)
    for (i = 0; i < buffer->width; i++)
      {
        color_buffer_get_pixel(buffer,i,j,&red,&green,&blue);

        average = (red + green + blue) / 3;
        angle = periods * 2 * PI * (((double) average) / 255) + phase;

        red = amplitude * 2 * (sin(angle) / 2 + 0.5) + 128 - amplitude;
        green = red;
        blue = red;

        color_buffer_set_pixel(destination,i,j,red,green,blue);
      }
}

//----------------------------------------------------------------------

void pt_blur(t_color_buffer *buffer, unsigned int intensity)

  {
    unsigned int i, j, k, l, core_width, half_core_width;
    int sum_red, sum_green,
    sum_blue, core_number_of_fields, help_position_x, help_position_y;
    unsigned char red, green, blue;
    t_color_buffer help_buffer;

    if (intensity == 0)
      return;

    color_buffer_copy(buffer,&help_buffer);

    core_width = intensity * 2 + 1;   // kind of convolution core matrix
    half_core_width = core_width / 2;
    core_number_of_fields = core_width * core_width;

    for (i = 0; i < buffer->width; i++)
      for (j = 0; j < buffer->height; j++)
        {
          sum_red = 0;
          sum_green = 0;
          sum_blue = 0;

          for (k = 0; k < core_width; k++)
            for (l = 0; l < core_width; l++)
              {
                                      // a little optimalization
                help_position_x = i - half_core_width;
                help_position_y = j - half_core_width;

                color_buffer_get_pixel(&help_buffer,
                  help_position_x + k,help_position_y + l,
                  &red,&green,&blue);

                sum_red += red;
                sum_green += green;
                sum_blue += blue;
              }

          red = sum_red / core_number_of_fields;
          green = sum_green / core_number_of_fields;
          blue = sum_blue / core_number_of_fields;

          color_buffer_set_pixel(buffer,i,j, red, green, blue);
        }

    color_buffer_destroy(&help_buffer);
  }

//----------------------------------------------------------------------

void pt_motion_blur(t_color_buffer *buffer, t_direction direction,
  unsigned int intensity)

  {
    t_matrix matrix;
    unsigned int i, j;
    double value;

    if (intensity == 0)
      return;

    matrix_init(&matrix,intensity * 2 + 1,intensity * 2 + 1);

    for (j = 0; j < matrix.height; j++)
      for (i = 0; i < matrix.width; i++)
        matrix_set_value(&matrix,i,j,0.0);

    value = 1.0 / matrix.width;

    for (i = 0; i < matrix.width; i++)
      switch (direction)
        {
          case DIRECTION_HORIZONTAL:
            matrix_set_value(&matrix,i,intensity,value);
            break;

          case DIRECTION_VERTICAL:
            matrix_set_value(&matrix,intensity,i,value);
            break;

          case DIRECTION_DIAGONAL_LU_RD:
            matrix_set_value(&matrix,i,i,value);
            break;

          case DIRECTION_DIAGONAL_LD_RU:
            matrix_set_value(&matrix,i,matrix.width - i - 1,value);
            break;
        }

    pt_convolution(buffer,&matrix);

    matrix_destroy(&matrix);
  }

//----------------------------------------------------------------------

void pt_sharpen(t_color_buffer *buffer, unsigned int intensity)

  {
    t_matrix matrix;
    unsigned int i, j;

    if (intensity == 0)
      return;

    matrix_init(&matrix,intensity * 2 + 1,intensity * 2 + 1);

    for (j = 0; j < matrix.height; j++)
      for (i = 0; i < matrix.width; i++)
        matrix_set_value(&matrix,i,j,-1.0);

    matrix_set_value(&matrix,intensity,intensity,matrix.width *
      matrix.height);

    pt_convolution(buffer,&matrix);

    matrix_destroy(&matrix);
  }

//----------------------------------------------------------------------

void pt_emboss(t_color_buffer *buffer, unsigned int intensity)

  {
    t_matrix matrix;
    unsigned int i,j;

    if (intensity == 0)
      return;

    matrix_init(&matrix,intensity * 2 + 1,intensity * 2 + 1);

    for (j = 0; j < matrix.height; j++)
      {
        for (i = 0; i < matrix.width - 1 - j; i++)
          matrix_set_value(&matrix,i,j,-1.0);

        matrix_set_value(&matrix,i,j,0.0);

        for (i = i + 1; i < matrix.width; i++)
          matrix_set_value(&matrix,i,j,1.0);
      }

    pt_convolution(buffer,&matrix);
    matrix_destroy(&matrix);
  }

//----------------------------------------------------------------------

void pt_edge_detection(t_color_buffer *buffer,
  t_edge_detection_type type, int intensity)

  {
    t_matrix matrix;         // convolution matrix
    int i, j, matrix_size,
      apply_both;            /* says whether to apply both types of
                                detection */
    double help_number;
    t_color_buffer help_buffer, /* will be used a a memory if both types
                                   of detection are set */
      help_buffer2;

    if (intensity == 0)
      return;

    matrix_size = intensity * 2 + 1;

    if (type == DETECTION_BOTH)
      {
        apply_both = 1;
        type = DETECTION_HORIZONTAL;
      }
    else
      apply_both = 0;

    if (intensity > 10)
      intensity = 10;
    else if (intensity < 1)
      intensity = 1;

    if (apply_both)
      {
        color_buffer_copy(buffer,&help_buffer);
        color_buffer_copy(buffer,&help_buffer2);
      }

    matrix_init(&matrix,matrix_size,matrix_size);

    while (1)
      {
        for (i = 0; i < matrix_size; i++)
          {
            if (i < intensity)
              help_number = -1 * (i + 1);
            else if (i == intensity)
              help_number = 0;
            else
              help_number = 2 * intensity - i + 1;

            if (type == DETECTION_HORIZONTAL)
              {
                for (j = 0; j < matrix_size; j++)
                  matrix_set_value(&matrix,i,j,help_number);
              }
            else
              {
                for (j = 0; j < matrix_size; j++)
                  matrix_set_value(&matrix,j,i,help_number);
              }
        }


        if (apply_both)
          {
            if (type == DETECTION_HORIZONTAL)
              {                      // horizontal done, now do vertical
                pt_convolution(&help_buffer,&matrix);
                type = DETECTION_VERTICAL;
              }
            else
              {
                pt_convolution(&help_buffer2,&matrix);
                pt_mix_buffers(&help_buffer,&help_buffer2,buffer,
                  50,MIX_ADD,NULL);
                color_buffer_destroy(&help_buffer);
                color_buffer_destroy(&help_buffer2);
                break;
              }
          }
        else
          {
            pt_convolution(buffer,&matrix);
            break;
          }
      }

    matrix_destroy(&matrix);
  }

//----------------------------------------------------------------------

void pt_invert_colors(t_color_buffer *buffer)

  {
    unsigned char red, green, blue;
    unsigned int i, j;

    for (j = 0; j < buffer->height; j++)
      for (i = 0; i < buffer->width; i++)
        {
          color_buffer_get_pixel(buffer,i,j,&red,&green,&blue);
          color_buffer_set_pixel(buffer,i,j,255 - red, 255 - green,
            255 - blue);
        }
  }

//----------------------------------------------------------------------

void pt_crop_amplitude(t_color_buffer *buffer,
  unsigned char lower_limit, unsigned char upper_limit)

  {
    unsigned int x,y;
    unsigned char r,g,b;

    if (buffer == NULL)
      return;

    for (y = 0; y < buffer->height; y++)
      for (x = 0; x < buffer->width; x++)
        {
          color_buffer_get_pixel(buffer,x,y,&r,&g,&b);

          if (r < lower_limit)
            r = lower_limit;
          else if (r > upper_limit)
            r = upper_limit;

          color_buffer_set_pixel(buffer,x,y,r,r,r);
        }
  }

//----------------------------------------------------------------------

void pt_grayscale(t_color_buffer *buffer)

  {
    unsigned int i, j;
    unsigned char red, green, blue;

    for (j = 0; j < buffer->height; j++)
      for (i = 0; i < buffer->width; i++)
        {
          color_buffer_get_pixel(buffer,i,j,&red,&green,&blue);

                                            // empiric coeficient values
          red = (unsigned char) (0.229 * red + 0.587 * green +
            0.114 * blue);

          color_buffer_set_pixel(buffer,i,j,red,red,red);
        }
  }

//----------------------------------------------------------------------

void pt_map_to_transition(t_color_buffer *buffer,
  t_color_transition *transition)

  {
    unsigned int i, j;
    unsigned char red, green, blue;

    for (j = 0; j < buffer->height; j++)
      for (i = 0; i < buffer->width; i++)
        {
          color_buffer_get_pixel(buffer,i,j,&red,&green,&blue);
          color_transition_get_color(red,&red,&green,&blue,transition);
          color_buffer_set_pixel(buffer,i,j,red,green,blue);
        }
  }

//----------------------------------------------------------------------

void pt_turtle_draw(t_color_buffer *buffer, t_grammar *grammar,
  double start_x, double start_y, int start_angle,
  double noise_intensity, double particle_density)

  {
    int x1,y1,x2,y2;

    if (buffer == NULL)
      return;

    start_x = saturate_double(start_x,0.0,1.0);
    start_y = saturate_double(start_y,0.0,1.0);
    noise_intensity = saturate_double(noise_intensity,0.0,1.0);
    particle_density = saturate_double(particle_density,0.0,1.0);

    _pt_turtle_init(grammar,buffer->width,buffer->height,start_x *
      buffer->width, start_y * buffer->height, start_angle,
      noise_intensity);

    while (_pt_turtle_next_instruction(&x1,&y1,&x2,&y2))
      {
        _pt_draw_fancy_line(buffer,x1,y1,x2,y2,turtle.state.color[0],
          turtle.state.color[1],turtle.state.color[2],
          turtle.state.line_width,turtle.state.dot_gap,
          noise_intensity,particle_density,&turtle_noise_buffer,
          turtle.state.line_type);
      }

    _pt_turtle_destroy();
  }

//----------------------------------------------------------------------

int pt_turtle_get_point_list(t_color_buffer *buffer, t_grammar *grammar,
  double start_x, double start_y, int start_angle,
  unsigned int list[][2], unsigned int *length,
  unsigned int max_length)

  {
    int x1,y1,x2,y2;

    if (buffer == NULL || length == NULL)
      return 0;

    *length = 0;

    if (max_length == 0)
      return 1;

    if (start_x > 1.0)
      start_x = 1.0;
    else if (start_x < 0.0)
      start_x = 0.0;

    if (start_y > 1.0)
      start_y = 1.0;
    else if (start_y < 0.0)
      start_y = 0.0;

    list[0][0] = start_x * buffer->width;  // initial point
    list[0][1] = start_y * buffer->height;
    (*length)++;

    _pt_turtle_init(grammar,buffer->width,buffer->height,start_x *
      buffer->width, start_y * buffer->height, start_angle,0.0);

    while (_pt_turtle_next_instruction(&x1,&y1,&x2,&y2))
      {
        if (*length >= max_length)
          break;

        list[*length][0] = x2;
        list[*length][1] = y2;

        (*length)++;
      }

    _pt_turtle_destroy();

    return 1;
  }

//----------------------------------------------------------------------

void pt_normal_map(t_color_buffer *buffer, unsigned int
  neighbourhood_size, t_color_buffer *destination)

  {
    unsigned int x,y,i;
    int j;
    int sum_of_differences;
    unsigned char vector_char[3];
    unsigned char r,g,b;
    double vector_double[3];
    int difference;

    if (neighbourhood_size == 0)
      neighbourhood_size = 1;

    color_buffer_init(destination,buffer->width,buffer->height);

    for (y = 0; y < buffer->height; y++)
      for (x = 0; x < buffer->width; x++)
        {
          // mean difference in x direction neighbourhood:
          sum_of_differences = 0;

          for (j = -1 * neighbourhood_size; j <= (int) neighbourhood_size; j++)
            for (i = 1; i <= neighbourhood_size; i++)
              {
                color_buffer_get_pixel(buffer,x - i,y + j,&r,&g,&b);
                difference = r;
                color_buffer_get_pixel(buffer,x + i,y + j,&r,&g,&b);
                difference -= r;
                sum_of_differences += difference;
              }

          vector_double[0] = sum_of_differences /
            ((double) (neighbourhood_size * (neighbourhood_size * 2 + 1)));

          // mean difference in y direction neighbourhood:
          sum_of_differences = 0;

          for (j = -1 * neighbourhood_size; j <= (int) neighbourhood_size; j++)
            for (i = 1; i <= neighbourhood_size; i++)
              {
                color_buffer_get_pixel(buffer,x + j,y - i,&r,&g,&b);
                difference = r;
                color_buffer_get_pixel(buffer,x + j,y + i,&r,&g,&b);
                difference -= r;
                sum_of_differences += difference;
              }

          vector_double[1] = sum_of_differences /
            ((double) (neighbourhood_size * (neighbourhood_size * 2 + 1)));

          vector_double[2] = 1.0;   // we consider this 1

          // normalise the vector:

          normalise_vector_3(&vector_double[0],&vector_double[1],
            &vector_double[2]);

          // map the vector to char range:

          vector_char[0] = round_to_char(vector_double[0] * 128 + 127);
          vector_char[1] = round_to_char(vector_double[1] * 128 + 127);
          vector_char[2] = round_to_char(vector_double[2] * 128 + 127);

          // write the vector to the buffer:

          color_buffer_set_pixel(destination,x,y,vector_char[0],
            vector_char[1],vector_char[2]);
        }
  }

//----------------------------------------------------------------------

void pt_light(t_color_buffer *normal_map, t_color_buffer *destination,
  unsigned char ambient_r, unsigned char ambient_g,
  unsigned char ambient_b, unsigned char diffuse_r,
  unsigned char diffuse_g, unsigned char diffuse_b,
  unsigned char specular_r, unsigned char specular_g,
  unsigned char specular_b, double phong_exponent,
  t_reflection_curve reflection_curve, double viewer_z,
  double light_vector_x, double light_vector_y)

  {
    unsigned int ambient_intensity[3];
    unsigned int diffuse_intensity[3];
    unsigned int specular_intensity[3];
    double specular_brightness;
    unsigned int x,y;
    double half_width, half_height;
    double viewer_x, viewer_y;
    unsigned int interpolation_border_x, interpolation_border_y;
    unsigned char r,g,b;
    unsigned int i;
    double dot_product;
    double light_vector[3];
    double normal_vector[3];
    double viewer_vector[3];
    double reflection_vector[3];

    color_buffer_init(destination,normal_map->width,normal_map->height);

    half_width = destination->width / 2.0;
    half_height = destination->height / 2.0;

    interpolation_border_x = destination->width * 0.2;
    interpolation_border_y = destination->height * 0.2;

    if (viewer_z < 0.1)
      viewer_z = 0.1;

    light_vector[0] = light_vector_x;
    light_vector[1] = light_vector_y;
    light_vector[2] = 1.0;

    normalise_vector_3(&light_vector[0],&light_vector[1],
      &light_vector[2]);

    // ambient light:

    ambient_intensity[0] = round_to_char(ambient_r);
    ambient_intensity[1] = round_to_char(ambient_g);
    ambient_intensity[2] = round_to_char(ambient_b);

    for (y = 0; y < destination->height; y++)
      for (x = 0; x < destination->width; x++)
        {
          // get the normal:

          color_buffer_get_pixel(normal_map,x,y,&r,&g,&b);
          normal_vector[0] = (r - 127) / ((double) 128);
          normal_vector[1] = (g - 127) / ((double) 128);
          normal_vector[2] = (b - 127) / ((double) 128);

          // diffuse light:

          dot_product = normal_vector[0] * light_vector[0] +
            normal_vector[1] * light_vector[1] + normal_vector[2] *
            light_vector[2];

          diffuse_intensity[0] = round_to_char(dot_product * diffuse_r);
          diffuse_intensity[1] = round_to_char(dot_product * diffuse_g);
          diffuse_intensity[2] = round_to_char(dot_product * diffuse_b);

          // specular light:

          // set the viewer position, interpolate if near the border

          if (x <= interpolation_border_x)
            {
              viewer_x = (x / ((double) interpolation_border_x)) *
                half_width;
            }
          else if (x >= destination->width - interpolation_border_x)
            {
              viewer_x = half_width + ((x - destination->width +
              interpolation_border_x) /
              ((double) interpolation_border_x)) * half_width;
            }
          else
            viewer_x = half_width;  // position in the middle

          if (y <= interpolation_border_y)
            {
              viewer_y = (y / ((double) interpolation_border_y)) *
                half_height;
            }
          else if (y >= destination->height - interpolation_border_y)
            {
              viewer_y = half_height + ((y - destination->height +
              interpolation_border_y) /
              ((double) interpolation_border_y)) * half_height;
            }
          else
            viewer_y = half_height;

          viewer_vector[0] = viewer_x - x;
          viewer_vector[1] = viewer_y - y;
          viewer_vector[2] = destination->width * viewer_z;

          normalise_vector_3(&viewer_vector[0],&viewer_vector[1],
            &viewer_vector[2]);

          for (i = 0; i < 3; i++)    // compute the reflection vector
            reflection_vector[i] = 2 * dot_product * normal_vector[i]
            - light_vector[i];

          normalise_vector_3(&reflection_vector[0],
            &reflection_vector[1],&reflection_vector[2]);

          dot_product = (viewer_vector[0] * reflection_vector[0] +
            viewer_vector[1] * reflection_vector[1] + viewer_vector[2] *
            reflection_vector[2]);

          switch (reflection_curve)
            {
              case REFLECTION_CURVE_COSINE_SMOOTH:
                dot_product = (dot_product + 1.0) / 2.0;
                break;

              case REFLECTION_CURVE_COSINE_ABS:
                dot_product = dot_product < 0.0 ?
                  -1 * dot_product : dot_product;
                break;

              case REFLECTION_CURVE_LINEAR_HALF:
                dot_product = acos(dot_product) / PI * -1.0 + 1.0;
                break;

              case REFLECTION_CURVE_LINEAR_FULL:
                dot_product = (acos(dot_product) / PI * -1.0 + 2.0)
                  / 2.0;
                break;
            }

          dot_product = saturate_double(dot_product,0.0,1.0);

          specular_brightness = pow(dot_product,phong_exponent);

          specular_intensity[0] =
            round_to_char(specular_brightness * specular_r);
          specular_intensity[1] =
            round_to_char(specular_brightness * specular_g);
          specular_intensity[2] =
            round_to_char(specular_brightness * specular_b);

          // write the intensity:

          color_buffer_set_pixel(destination,x,y,
            round_to_char(ambient_intensity[0] + diffuse_intensity[0] +
            specular_intensity[0]),round_to_char(ambient_intensity[1] +
            diffuse_intensity[1] + specular_intensity[1]),
            round_to_char(ambient_intensity[2] + diffuse_intensity[2] +
            specular_intensity[2]));
        }
  }

//----------------------------------------------------------------------

void pt_light_simple(t_color_buffer *normal_map,
  t_color_buffer *destination, unsigned char red, unsigned char green,
  unsigned char blue)

  {
    double ambient_amount, diffuse_amount;

    ambient_amount = 0.05;
    diffuse_amount = 0.5;

    pt_light(normal_map,destination,
      red * ambient_amount,
      green * ambient_amount,
      blue * ambient_amount,
      red * diffuse_amount,
      green * diffuse_amount,
      blue * diffuse_amount,
      255,
      255,
      255,
      2.0,
      REFLECTION_CURVE_COSINE_ABS,
      1.0,0.5,0.5);
  }

//----------------------------------------------------------------------

void pt_glass(t_color_buffer *normal_map, t_color_buffer *buffer,
  t_color_buffer *destination, double height)

  {
    double normal_vector[3];
    unsigned int x,y,offset_x,offset_y,pixel_height;
    unsigned char r,g,b;

    if (normal_map == NULL || buffer == NULL)
      return;

    pixel_height = height * buffer->width * 0.01;

    color_buffer_init(destination,buffer->width,buffer->height);

    for (y = 0; y < destination->height; y++)
      for (x = 0; x < destination->width; x++)
        {
          color_buffer_get_pixel(normal_map,x,y,&r,&g,&b);
          normal_vector[0] = (r - 127) / ((double) 128);
          normal_vector[1] = (g - 127) / ((double) 128);
          normal_vector[2] = (b - 127) / ((double) 128);

          offset_x = pixel_height *
            (normal_vector[0] / normal_vector[2]);

          offset_y = pixel_height *
            (normal_vector[1] / normal_vector[2]);

          color_buffer_get_pixel(buffer,x + offset_x,y + offset_y,
            &r,&g,&b);

          color_buffer_set_pixel(destination,x,y,r,g,b);
        }
  }

//----------------------------------------------------------------------

void pt_cellular_automaton_rps(t_color_buffer *buffer,
  t_neighbourhood_type neighbourhood, unsigned int neighbourhood_size,
  unsigned char number_of_players, int random, unsigned int iterations)

  {
    int position_differences[128][2];  // neighbourhood pos. differences
    unsigned int x,y;
    int dx,dy;
    unsigned char r,g,b,r2,g2,b2;
    unsigned int array_length,iteration;
    unsigned int player1,player2,winner,level2,random_number;
    t_color_buffer buffer2;
    t_color_buffer *main_buffer,*secondary_buffer,*helper;

    if (number_of_players > 25)
      number_of_players = 25;

    array_length = make_neighbourhood(neighbourhood,neighbourhood_size,
      position_differences);
    color_buffer_init(&buffer2,buffer->width,buffer->height);
    main_buffer = buffer;
    secondary_buffer = &buffer2;
    _pt_cellular_automaton_prepare(buffer,number_of_players + 1);
    pt_multiply_value(buffer,10.0); // give each cell 10 states

    for (iteration = 0; iteration < iterations; iteration++)
      {
        for (y = 0; y < buffer->height; y++)
          for (x = 0; x < buffer->width; x++)
            {
              // pick a random cell in the neighbourhood:

              random_number =
                noise_int_range(random,0,array_length - 1);

              random++;

              dx = position_differences[random_number][0];
              dy = position_differences[random_number][1];

              color_buffer_get_pixel(main_buffer,x,y,&r,&g,&b);
              color_buffer_get_pixel(main_buffer,x + dx,y + dy,
                &r2,&g2,&b2);

              player1 = r / 10;
              player2 = r2 / 10;
              level2 = r2 % 10;

              // apply the rules:

              if (player1 == number_of_players)  // empty cell
                {
                  if (player2 != number_of_players) // vs non-empty cell
                    {
                      if (level2 < 9)
                        r = r2 + 1;  // spawn new cell with level + 1
                    }
                }
              else      // non-empty cell
                {
                  if (player2 != number_of_players) // vs non-empty cell
                    {
                      winner = rock_paper_scissors(number_of_players,
                        player1,player2);

                      if (winner != player1)
                        r = winner * 10;
                    }
                }

              color_buffer_set_pixel(secondary_buffer,x,y,r,0,0);
            }

        helper = main_buffer;     // switch the buffers
        main_buffer = secondary_buffer;
        secondary_buffer = helper;
      }

    color_buffer_copy_data(main_buffer,buffer);
    pt_multiply_value(buffer,0.1);
    _pt_cellular_automaton_convert_back(buffer,number_of_players + 1);
    color_buffer_destroy(&buffer2);
  }

//----------------------------------------------------------------------

void pt_cellular_automaton_cyclic(t_color_buffer *buffer,
  t_neighbourhood_type neighbourhood, unsigned int neighbourhood_size,
  unsigned char states, unsigned int threshold, unsigned int iterations)

  {
    int position_differences[128][2]; // neighbourhood pos. differences
    unsigned int x,y,i;
    int dx,dy;
    unsigned char r,g,b,r2,g2,b2;
    unsigned int array_length,iteration,color_count;
    t_color_buffer buffer2;
    t_color_buffer *main_buffer,*secondary_buffer,*helper;

    array_length = make_neighbourhood(neighbourhood,neighbourhood_size,
      position_differences);
    color_buffer_init(&buffer2,buffer->width,buffer->height);
    main_buffer = buffer;
    secondary_buffer = &buffer2;

    _pt_cellular_automaton_prepare(buffer,states);

    for (iteration = 0; iteration < iterations; iteration++)
      {
        for (y = 0; y < buffer->height; y++)
          for (x = 0; x < buffer->width; x++)
            {
              color_buffer_get_pixel(main_buffer,x,y,&r,&g,&b);

              // count the neighbour next level colors:

              color_count = 0;

              for (i = 0; i < array_length; i++)
                {
                  dx = position_differences[i][0];
                  dy = position_differences[i][1];

                  color_buffer_get_pixel(main_buffer,x + dx,y + dy,
                    &r2,&g2,&b2);

                  if (r2 == r + 1 || (r == states - 1 && r2 == 0))
                    color_count++;
                }

              if (color_count >= threshold)
                r++;

              if (r >= states)
                r = 0;

              color_buffer_set_pixel(secondary_buffer,x,y,r,0,0);
            }

        helper = main_buffer;     // switch the buffers
        main_buffer = secondary_buffer;
        secondary_buffer = helper;
      }

    color_buffer_copy_data(main_buffer,buffer);
    _pt_cellular_automaton_convert_back(buffer,states);
    color_buffer_destroy(&buffer2);
  }

//----------------------------------------------------------------------

void pt_cellular_automaton_general(t_color_buffer *buffer,
  unsigned char states, int rules[256], unsigned int iterations)

  {
    t_color_buffer buffer2;
    t_color_buffer *main_buffer,*secondary_buffer,*helper;
    int position_differences[8][2],rule;
    unsigned int iteration,new_state;
    unsigned char index;
    unsigned char r,g,b;
    unsigned int x,y,i;

    if (states < 2)
      states = 2;

    // Moore neighbourhood relative positions

    position_differences[0][0] = -1;
    position_differences[0][1] = -1;
    position_differences[1][0] = 0;
    position_differences[1][1] = -1;
    position_differences[2][0] = 1;
    position_differences[2][1] = -1;
    position_differences[3][0] = -1;
    position_differences[3][1] = 0;
    position_differences[4][0] = 1;
    position_differences[4][1] = 0;
    position_differences[5][0] = -1;
    position_differences[5][1] = 1;
    position_differences[6][0] = 0;
    position_differences[6][1] = 1;
    position_differences[7][0] = 1;
    position_differences[7][1] = 1;

    color_buffer_init(&buffer2,buffer->width,buffer->height);
    _pt_cellular_automaton_prepare(buffer,states);
    main_buffer = buffer;
    secondary_buffer = &buffer2;

    for (iteration = 0; iteration < iterations; iteration++)
      {
        for (y = 0; y < buffer->height; y++)
          for (x = 0; x < buffer->width; x++)
            {
              // compute index of the rule depending on neighbour state:

              index = 0;

              for (i = 0; i < 8; i++)
                {
                  color_buffer_get_pixel(main_buffer,
                    x + position_differences[i][0],
                    y + position_differences[i][1],
                    &r,&g,&b);

                  if (r == 0)                // cell alive
                    index += power_int(2,i); // set corresponding bit
                }

              rule = rules[index];

              color_buffer_get_pixel(main_buffer,x,y,&r,&g,&b);

              if (rule == 0)     // nothing happens
                {
                }
              else if (rule > 0) // the cell is born
                {
                  r = 0;
                }
              else          // the cell dies (or gets to the next state)
                {
                  new_state = r + 1;

                  if (new_state >= (unsigned int) states)
                    new_state = (unsigned int) states - 1;

                  r = new_state;
                }

              color_buffer_set_pixel(secondary_buffer,x,y,r,0,0);
            }

        helper = main_buffer;     // switch the buffers
        main_buffer = secondary_buffer;
        secondary_buffer = helper;
      }

    color_buffer_copy_data(main_buffer,buffer);
    _pt_cellular_automaton_convert_back(buffer,states);
    color_buffer_destroy(&buffer2);
  }

//----------------------------------------------------------------------

void pt_mosaic_square(t_color_buffer *destination,
  t_fill_type fill_type, unsigned char fill_colors[],
  unsigned char number_of_colors, t_square_mosaic *mosaic)

  {
    int horizontal;
    unsigned char color;
    unsigned char r,g,b;
    unsigned int polygon_points,tile_number;
    unsigned int extra_border_x,extra_border_y,tile_width,tile_height;
    t_color_buffer tile_buffer, help_buffer;
    double (*polygon)[2];       // dynamic array of polygon points
    unsigned int i,j;
    t_mosaic_transformation current_transformation;

    if (destination == NULL || mosaic == NULL ||
      !square_mosaic_is_valid(mosaic))
      return;

    // make the polygon:

    _pt_make_tile_polygon(mosaic,&polygon,&polygon_points);

    // initialise the help buffer:

    color_buffer_init(&help_buffer,destination->width,
      destination->width);
    pt_color_fill(&help_buffer,0,0,0);

    tile_width = help_buffer.width / mosaic->tiles_x;
    tile_height = help_buffer.height / mosaic->tiles_y;
    extra_border_x = ceil(tile_width / 2);
    extra_border_y = ceil(tile_height / 2);

    // initialise the tile buffer with extra borders:

    color_buffer_init(&tile_buffer,2 * tile_width,2 * tile_height);

    // draw the polygon to the buffer:

    for (i = 0; i < polygon_points; i++)
      {
        _pt_draw_fancy_line(&tile_buffer,
          extra_border_x + polygon[i][0] * tile_width,
          extra_border_y + tile_height - polygon[i][1] * tile_height,
          extra_border_x + polygon[(i + 1) % polygon_points][0] * tile_width,
          extra_border_y + tile_height - polygon[(i + 1) % polygon_points][1] * tile_height,
          0,0,0,1,0,0,0,NULL,LINE_NORMAL);
      }

    _pt_floodfill(&tile_buffer,0,0,255,0,0); // fill the outside

   if (fill_type == FILL_NO_BORDERS) // get rid of borders if needed
      _pt_replace_color(&tile_buffer,0,0,0,255,255,255);

    // make the mosaic:

    tile_number = 0;
    current_transformation = MOSAIC_TRANSFORM_SHIFT;  // = no transform.

    for (j = 0; j < mosaic->tiles_y; j++)
      {
        for (i = 0; i < mosaic->tiles_x; i++)
          {
            current_transformation = compute_transformation(mosaic,i,j,
              &horizontal);

            if (fill_colors == NULL || fill_type == FILL_NONE)
              color = 255;
            else
              {
                color = fill_colors[tile_number % number_of_colors];

                if (color == 0)    // black not allowed
                  color = 1;
              }

            _pt_draw_tile(&tile_buffer,
              i * tile_width -1 * extra_border_x,
              j * tile_height -1 * extra_border_y,
              color,&help_buffer,current_transformation,horizontal);

            tile_number++;
          }
      }

    // get rid of possible remaining black pixels:

    if (fill_type == FILL_NO_BORDERS)
      for (j = 0; j < help_buffer.height; j++)
        for (i = 0; i < help_buffer.width; i++)
          {
            color_buffer_get_pixel(&help_buffer,i,j,&r,&g,&b);

            if (r == 0 && g == 0 && b == 0)
              {
                if (i == 0)
                  {
                    if (fill_colors == NULL)
                      {
                        r = 255;
                        g = 255;
                        b = 255;
                      }
                    else
                      {
                        r = fill_colors[0];
                        g = fill_colors[0];
                        b = fill_colors[0];
                      }
                  }
                else
                  color_buffer_get_pixel(&help_buffer,i - 1,j,&r,&g,&b);

                color_buffer_set_pixel(&help_buffer,i,j,r,g,b);
              }
          }

    pt_resize(&help_buffer,destination,INTERPOLATION_LINEAR);
    color_buffer_destroy(&tile_buffer);
    color_buffer_destroy(&help_buffer);
    free(polygon);
  }

//----------------------------------------------------------------------

void pt_replace_colors(t_color_buffer *buffer,
  unsigned char colors[][3],t_color_buffer *buffers[],
  unsigned int length)

  {
    unsigned int i,j,k;
    unsigned char r,g,b;

    for (j = 0; j < buffer->height; j++)
      for (i = 0; i < buffer->width; i++)
        {
          color_buffer_get_pixel(buffer,i,j,&r,&g,&b);

          // find the color:

          for (k = 0; k < length; k++)
            if (r == colors[k][0] && g == colors[k][1]
              && b == colors[k][2])
              {
                if (buffers[k] != NULL)
                  color_buffer_get_pixel(buffers[k],i,j,&r,&g,&b);

                break;
              }

          color_buffer_set_pixel(buffer,i,j,r,g,b);
        }
  }

//----------------------------------------------------------------------

void pt_bump_noise(t_color_buffer *buffer, double bump_size_from,
  double bump_size_to, unsigned int bump_quantity, int alter_amplitude,
  int random)

  {
    unsigned int bump_count,bump_size;
    int x,y;

    bump_size_from = saturate_double(bump_size_from,0.001,1.0);
    bump_size_to = saturate_double(bump_size_to,0.001,1.0);

      // cannot use 0.0 to prevent division by zero

    pt_color_fill(buffer,255,255,255);

    for (bump_size = bump_size_from * buffer->width;
      bump_size >= bump_size_to; bump_size *= 0.5)
      for (bump_count = (buffer->width / bump_size) * bump_quantity;
        bump_count > 0; bump_count--)
        {
          x = noise(random) * buffer->width;
          random++;
          y = noise(random) * buffer->height;
          random++;

          _pt_draw_bump(buffer,x,y,bump_size,alter_amplitude);
        }
  }

//----------------------------------------------------------------------

void pt_dithering(t_color_buffer *buffer, unsigned char levels,
  t_dithering_method method)

  {
    unsigned int i,j,k,matrix_size,limit;
    unsigned char r,g,b,r2,g2,b2,adding;
    unsigned char color_levels[3];
    int random;
    t_matrix bayer_matrix;
    double interval;
    double (*error_memory1)[3];
    double (*error_memory2)[3];
    double (*this_line_errors)[3];
    double (*next_line_errors)[3];
    double (*helper)[3];
    double error[3];

    random = 0;

    switch (method)

      {
        case DITHERING_THRESHOLD:

          for (j = 0; j < buffer->height; j++)
            for (i = 0; i < buffer->width; i++)
              {
                color_buffer_get_pixel(buffer,i,j,&r,&g,&b);

                if (r == g && g == b) // grayscale
                  {
                    r = dither_threshold(r,levels);
                    g = r;
                    b = r;
                  }
                else                  // non-grayscale
                  {
                    r = dither_threshold(r,levels);
                    g = dither_threshold(g,levels);
                    b = dither_threshold(b,levels);
                  }

                color_buffer_set_pixel(buffer,i,j,r,g,b);
              }

          break;

        case DITHERING_RANDOM:

          for (j = 0; j < buffer->height; j++)
            for (i = 0; i < buffer->width; i++)
              {
                color_buffer_get_pixel(buffer,i,j,&r,&g,&b);

                r = dither_random(r,levels,random);
                g = dither_random(g,levels,random);
                b = dither_random(b,levels,random);
                random++;

                color_buffer_set_pixel(buffer,i,j,r,g,b);
              }

          break;

        case DITHERING_ERROR_PROPAGATION:

          error_memory1 = malloc(buffer->width * sizeof(double) * 3);
          error_memory2 = malloc(buffer->width * sizeof(double) * 3);

          this_line_errors = error_memory1;
          next_line_errors = error_memory2;

          for (i = 0; i < buffer->width; i++) // clear the error memory
            {
              this_line_errors[i][0] = 0.0;
              this_line_errors[i][1] = 0.0;
              this_line_errors[i][2] = 0.0;
            }

          for (j = 0; j < buffer->height; j++)
            {
              for (k = 0; k < buffer->width; k++)
                {
                  next_line_errors[k][0] = 0.0;
                  next_line_errors[k][1] = 0.0;
                  next_line_errors[k][2] = 0.0;
                }

              for (i = 0; i < buffer->width; i++)
                {
                  color_buffer_get_pixel(buffer,i,j,&r,&g,&b);

                  // add the error:

                  r = round_to_char(r + this_line_errors[i][0]);
                  g = round_to_char(g + this_line_errors[i][1]);
                  b = round_to_char(b + this_line_errors[i][2]);

                  r2 = dither_threshold(r,levels); // threshold
                  g2 = dither_threshold(g,levels);
                  b2 = dither_threshold(b,levels);

                  error[0] = r - r2;  // compute the error
                  error[1] = g - g2;
                  error[2] = b - b2;

                  // distribute the error:

                  for (k = 0; k < 3; k++)
                    {
                      this_line_errors[(i + 1) % buffer->width][k] +=
                        0.4375 * error[k];               // 7 / 16

                      next_line_errors[i == 0 ? buffer->width - 1 :
                        i - 1][k] += 0.1875 * error[k];  // 3 / 16

                                                         // 5 / 16
                      next_line_errors[i][k] += 0.3125 * error[k];

                      next_line_errors[(i + 1) % buffer->width][k] +=
                        0.0625 * error[k];               // 1 / 16
                    }

                  color_buffer_set_pixel(buffer,i,j,r2,g2,b2);
                }

              helper = this_line_errors;  // swap the line error buffers
              this_line_errors = next_line_errors;
              next_line_errors = helper;
            }

          free(error_memory1);
          free(error_memory2);

          break;

        case DITHERING_ORDERED:

          // find the matrix size:

          for (matrix_size = 1; matrix_size <= 16; matrix_size++)
            if (matrix_size * matrix_size >= levels)
              break;

          matrix_init(&bayer_matrix,matrix_size,matrix_size);
          make_bayer_matrix(&bayer_matrix);
          interval = 255.0 / (double) levels;
          limit = matrix_size * matrix_size;

          for (j = 0; j < buffer->height; j++)
            for (i = 0; i < buffer->width; i++)
              {
                color_buffer_get_pixel(buffer,i,j,&r,&g,&b);

                // find the level for each channel:

                for (k = 1; k <= levels; k++)
                  if (r <= interval * k)
                    break;

                color_levels[0] = k - 1;

                for (k = 1; k <= levels; k++)
                  if (g <= interval * k)
                    break;

                color_levels[1] = k - 1;

                for (k = 1; k <= levels; k++)
                  if (b <= interval * k)
                    break;

                color_levels[2] = k - 1;

                adding = matrix_get_value(&bayer_matrix,i % matrix_size,
                  j % matrix_size);

                for (k = 0; k < 3; k++)
                  color_levels[k] = color_levels[k] + adding > limit ?
                    color_levels[k] + 1 : color_levels[k];

                color_buffer_set_pixel(buffer,i,j,color_levels[0] *
                  interval,color_levels[1] * interval,color_levels[2] *
                  interval);
              }

          matrix_destroy(&bayer_matrix);

          break;
      }
  }

//----------------------------------------------------------------------
