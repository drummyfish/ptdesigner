//**********************************************************************
/** @file
 * Implementation of general function.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include "general.h"
#include <math.h>

                                         // pre-computed Bayer matrices:

const unsigned char bayer_matrix_2x2[2][2] = {{1, 3},
                                              {4, 2}};

const unsigned char bayer_matrix_4x4[4][4] = {{0,  12, 3,  15},
                                              {8,  4,  11, 7},
                                              {2,  14, 1,  13},
                                              {10, 6,  9,  5}};

const unsigned char bayer_matrix_8x8[8][8] = {{0,  48, 12, 60, 3,  51, 15, 63},
                                              {32, 16, 44, 28, 35, 19, 47, 31},
                                              {8,  56, 4,  52, 11, 59, 7,  55},
                                              {40, 24, 36, 20, 43, 27, 39, 23},
                                              {2,  50, 14, 62, 1,  49, 13, 61},
                                              {34, 18, 46, 30, 33, 17, 45, 29},
                                              {10, 58, 6,  54, 9,  57, 5,  53},
                                              {42, 26, 38, 22, 41, 25, 37, 21}};

//----------------------------------------------------------------------

int transform_coordination(int coordination, int limit)

  {
    if (coordination < 0)
      {
        coordination = -1 * coordination;
        coordination = coordination % limit;
        coordination = limit - coordination;
      }

    if (coordination != 0)
      coordination = coordination % limit;

    return coordination;
  }

//----------------------------------------------------------------------

double get_distance(t_metric metric, int x1, int y1, int x2, int y2,
  int space_width, int space_height)

  {
    int x_distance, y_distance;

    if (x1 == x2 && y1 == y2)
      {
        x_distance = 0;
        y_distance = 0;
      }
    else
      {
        x_distance = abs(x1 - x2) < space_width - abs(x1 - x2) ?
          abs(x1 - x2) : space_width - abs(x1 - x2);

        y_distance = abs(y1 - y2) < space_height - abs(y1 - y2) ?
          abs(y1 - y2) : space_height - abs(y1 - y2);
      }

    switch (metric)
      {
        case METRIC_EUCLIDEAN:
          return
            sqrt(x_distance * x_distance + y_distance * y_distance);
          break;

        case METRIC_TAXICAB:
          return (double) x_distance + y_distance;
          break;

        case METRIC_CHEBYSHEV:
          return (double)
            (x_distance > y_distance ? x_distance : y_distance);
          break;
      }

    return 0;
  }

//----------------------------------------------------------------------

double noise(int x)

  {
    /* those are just some random operations that make good noise */
    double result;

    x = x ^ (x<<13);
    result = (1.0 - (((x * (x * x * 15731 + 789221) +
      1376312589) & 0x7fffffff) / 1073741824.0));
    return result;
  }

//----------------------------------------------------------------------

int noise_int_range(int x, int from, int to)

  {
    return round((((noise(x) + 1.0) / 2) * (to - from)) + from);
  }

//----------------------------------------------------------------------

double two_points_to_angle(int x1, int y1, int x2, int y2)
  {
    int dx,dy;
    double angle;

    dx = x2 - x1;
    dy = y2 - y1;

    if (dy == 0)
      angle = 0;
    else if (dx != 0)
      angle = atan(abs(dy)/((double) abs(dx)));
    else
      angle = PI_DIVIDED_2;

    if (dy >= 0)
      {
        if (dx >= 0)  // 4th quadrant
          angle = PI_TIMES_2 - angle;
        else          // 3rd quadrant
          angle = PI + angle;
      }
    else
      {
        if (dx >= 0)  // 1st quadrant
          angle = angle;
        else          // 2nd quadrant
          angle = PI - angle;
      }

    return angle;
  }

//----------------------------------------------------------------------

void line_point(int initial_x, int initial_y, double angle,
  unsigned int point, int *point_x, int *point_y)

  {
    int angle_area;    // eight areas to which 2 * PI angle is divided

    while (angle >= PI_TIMES_2)  // adjust the angle
      {
        angle -= PI_TIMES_2;
      }

    while (angle <= 0)
      {
        angle += PI_TIMES_2;
      }

    angle_area = (int) (angle / (PI_DIVIDED_4));

    switch (angle_area)
      {
        case 0:                                  // 0 to PI/4
          *point_x = initial_x + point;
          *point_y = initial_y - round(point * tan(angle));
          break;

        case 1:                                  // PI/4 to PI/2
          angle = PI_DIVIDED_2 - angle;
          *point_x = initial_x + round(point * tan(angle));
          *point_y = initial_y - point;
          break;

        case 2:                                  // PI/2 to 3/4 * PI
          angle = angle - PI_DIVIDED_2;
          *point_x = initial_x - round(point * tan(angle));
          *point_y = initial_y - point;
          break;

        case 3:                                  // 3/4 * PI to PI
          angle = PI -angle;
          *point_x = initial_x - point;
          *point_y = initial_y - round(point * tan(angle));
          break;

        case 4:                                  // PI to 5/4 * PI
          angle = angle - PI;
          *point_x = initial_x - point;
          *point_y = initial_y + round(point * tan(angle));
          break;

        case 5:                                  // 5/4 * PI to 3/2 * PI
          angle = PI_TIMES_3_2 - angle;
          *point_x = initial_x - round(point * tan(angle));
          *point_y = initial_y + point;
          break;

        case 6:                                  // 3/2 * PI to 7/4 * PI
          angle = angle - PI_TIMES_3_2;
          *point_x = initial_x + round(point * tan(angle));
          *point_y = initial_y + point;
          break;

        default:
          angle = PI_TIMES_2 - angle;            // 7/4 * PI to 2 * PI
          *point_x = initial_x + point;
          *point_y = initial_y + round(point * tan(angle));
          break;
      }
  }

//----------------------------------------------------------------------

void circle_point_by_angle(int center_x, int center_y, double radius,
  double angle,  int *x, int *y)

  {
    *x = center_x + sin(PI_DIVIDED_2 + angle) * radius;
    *y = center_y - sin(angle) * radius;
  }

//----------------------------------------------------------------------

void rgb_to_hsl(unsigned char red, unsigned char green,
  unsigned char blue, double *hue, double *saturation,
  double *lightness)

  {
    int max_variable;                    // 0 - red, 1 - green, 2 - blue
    double fp_red, fp_green, fp_blue, max, min, difference, help;

    fp_red = red / 255.0;
    fp_green = green / 255.0;
    fp_blue = blue / 255.0;

    if (fp_red > fp_green)
      {
        if (fp_blue > fp_red)
          {
            max = fp_blue;
            max_variable = 2;            // max is blue
          }
        else
          {
            max = fp_red;
            max_variable = 0;            // max is red
          }
      }
    else
      {
        if (fp_blue > fp_green)
          {
            max = fp_blue;
            max_variable = 2;            // max is blue
          }
        else
          {
            max = fp_green;
            max_variable = 1;            // max is green
          }
      }

    min = fp_red < fp_green ? fp_red : fp_green;
    min = fp_blue < min ? fp_blue : min;

    difference = max - min;

    *lightness = (max + min) / 2;                // lightness

    if (difference <= 0)                         // saturation
      *saturation = 0;
    else
      {
        help = (2 * *lightness - 1);

        if (help < 0)
          help = -1 * help;

        *saturation = difference / (1 - help);

        if (*saturation < 0)
          *saturation = -1 * *saturation;
      }

    if (difference <= 0)                         // hue
      *hue = 0;
    else
      {
        switch (max_variable)
          {
            case 0:  // red
              *hue = (fp_green - fp_blue) / difference;

              while (*hue > 6.0) // mod 6
                *hue = *hue - 6;

              break;

            case 1:  // green
              *hue = (fp_blue - fp_red) / difference + 2;
              break;

            case 2:  // blue
              *hue = (fp_red - fp_green) / difference + 4;
              break;

            default: break;
          }

        *hue = *hue / 6.0;
      }
  }

//----------------------------------------------------------------------

void hsl_to_rgb(double hue, double saturation, double lightness,
  unsigned char *red, unsigned char *green, unsigned char *blue)

  {
    double chroma, help, x, m, fp_red, fp_green, fp_blue;

    help = 2 * lightness - 1.0;

    if (help < 0.0)
      help = -1 * help;

    chroma = (1 - help) * saturation;

    hue = hue * 6;
    help = hue;

    while (help > 2.0)  // mod 2
      help = help - 2.0;

    help = help - 1.0;

    if (help < 0.0)
      help = -1 * help;

    x = chroma * (1 - help);

    if (hue >= 0.0 && hue < 1.0)
      {
        fp_red = chroma;
        fp_green = x;
        fp_blue = 0.0;
      }
    else if (hue < 2.0)
      {
        fp_red = x;
        fp_green = chroma;
        fp_blue = 0.0;
      }
    else if (hue < 3.0)
      {
        fp_red = 0.0;
        fp_green = chroma;
        fp_blue = x;
      }
    else if (hue < 4.0)
      {
        fp_red = 0.0;
        fp_green = x;
        fp_blue = chroma;
      }
    else if (hue < 5.0)
      {
        fp_red = x;
        fp_green = 0.0;
        fp_blue = chroma;
      }
    else if (hue < 6.0)
      {
        fp_red = chroma;
        fp_green = 0.0;
        fp_blue = x;
      }
    else
      {
        fp_red = 0.0;
        fp_green = 0.0;
        fp_blue = 0.0;
      }

    m = lightness - 0.5 * chroma;

    *red = (fp_red + m) * 255;
    *green = (fp_green + m) * 255;
    *blue = (fp_blue + m) * 255;
  }

//----------------------------------------------------------------------

double degrees_to_radians(double degrees)

  {
    return degrees * PI / ((double) 180);
  }

//----------------------------------------------------------------------

double radians_to_degrees(double radians)

  {
    return radians / PI_TIMES_2 * 360;
  }

//----------------------------------------------------------------------

unsigned char round_to_char(int value)

  {
    if (value > 255)
      return 255;

    if (value < 0)
      return 0;

    return value;
  }

//----------------------------------------------------------------------

void normalise_vector_3(double *x, double *y, double *z)

  {
    double length;

    length = sqrt((*x) * (*x) + (*y) * (*y) + (*z) * (*z));

    *x /= length;
    *y /= length;
    *z /= length;
  }

//----------------------------------------------------------------------

double interpolate(double value, t_interpolation_method method)

  {
    if (value < 0.0)
      value = 0.0;
    else if (value > 1.0)
      value = 1.0;

    switch(method)
      {
        case INTERPOLATION_NEAREST:
          return value < 0.5 ? 0.0 : 1.0;
          break;

        case INTERPOLATION_LINEAR:
          return value;
          break;

        case INTERPOLATION_SINE:
          return sin(value * PI_DIVIDED_2);
          break;

        default:
          return value;
          break;
      }
  }

//----------------------------------------------------------------------

double interpolate_values(double value, t_interpolation_method method,
  int value1, int value2)

  {
    double ratio;

    ratio = interpolate(value,method);

    return value1 * (1.0 - ratio) + value2 * ratio;
  }

//----------------------------------------------------------------------

void interpolate_color_2d(double x, double y, unsigned char top_left[3],
  unsigned char top_right[3], unsigned char bottom_left[3],
  unsigned char bottom_right[3], unsigned char *r, unsigned char *g,
  unsigned char *b, t_interpolation_method method)

  {
    unsigned char r1,g1,b1,r2,g2,b2;
    double ratio,ratio2;

    if (x < 0.0)
      x = 0.0;
    else if (x > 1.0)
      x = 1.0;

    if (y < 0.0)
      y = 0.0;
    else if (y > 1.0)
      y = 1.0;

    // first interpolate in x direction:

    ratio = interpolate(x,method);
    ratio2 = 1.0 - ratio;

    r1 = round_to_char(ratio * top_right[0] + ratio2 * top_left[0]);
    g1 = round_to_char(ratio * top_right[1] + ratio2 * top_left[1]);
    b1 = round_to_char(ratio * top_right[2] + ratio2 * top_left[2]);

    r2 = round_to_char
      (ratio * bottom_right[0] + ratio2 * bottom_left[0]);
    g2 = round_to_char
      (ratio * bottom_right[1] + ratio2 * bottom_left[1]);
    b2 = round_to_char
      (ratio * bottom_right[2] + ratio2 * bottom_left[2]);

    // now interpolate in y direction:

    ratio = interpolate(y,method);
    ratio2 = 1.0 - ratio;

    *r = round_to_char(ratio * r2 + ratio2 * r1);
    *g = round_to_char(ratio * g2 + ratio2 * g1);
    *b = round_to_char(ratio * b2 + ratio2 * b1);
  }

//----------------------------------------------------------------------

unsigned int rock_paper_scissors(unsigned int options,
  unsigned int player1, unsigned int player2)

  {
    // this algorithm should be explained in the documentation

    unsigned int helper;
    int b;

    if (player2 > player1)   // ascending order
      {
        helper = player2;
        player2 = player1;
        player1 = helper;
      }

    b = options / 2;

    return player1 - player2 > (unsigned int) b ? player1 : player2;
  }

//----------------------------------------------------------------------

unsigned int make_neighbourhood(t_neighbourhood_type type,
  unsigned int size, int position_differences[128][2])

  {
    int i,j;
    unsigned int length;

    length = 0;

    if (size > 10)
      size = 10;

    switch (type)
      {
        case NEIGHBOURHOOD_MOORE:

          for (j = -1 * (int) size; j <= (int) size; j++)
            for (i = -1 * (int) size; i <= (int) size; i++)
              if (!(i == 0 && j == 0)) // exclude the central cell
                {
                  position_differences[length][0] = i;
                  position_differences[length][1] = j;

                  length++;
                }

          break;

        case NEIGHBOURHOOD_VON_NEUMANN:

          for (j = -1 * (int) size; j <= (int) size; j++)
            for (i = -1 * (int) size + abs(j); i <= (int) size - abs (j); i++)
              if (!(i == 0 && j == 0))
                {
                  position_differences[length][0] = i;
                  position_differences[length][1] = j;

                  length++;
                }

          break;
      }

    return length;
  }

//----------------------------------------------------------------------

int power_int(int number, unsigned int power)

  {
    int result;
    unsigned int i;

    result = 1;

    for (i = 0; i < power; i++)
      result *= number;

    return result;
  }

//----------------------------------------------------------------------

void make_game_of_life_rules(int rules[256])

  {
    int i;
    unsigned char number,neighbour_number,neighbour_count;

    number = 0;   // neighbourhood state

    for (i = 0; i < 256; i++)
      {
        // count the alive neighbours:

        neighbour_count = 0;

        for (neighbour_number = 0; neighbour_number < 8; neighbour_number++)
          if (number & power_int(2,neighbour_number))
            neighbour_count++;

        if (neighbour_count < 2 || neighbour_count > 3)
          rules[number] = -1;   // cell dies
        else if (neighbour_count == 3)
          rules[number] = 1;    // cell is born
        else
          rules[number] = 0;    // nothing happens

        number++;
      }
  }

//----------------------------------------------------------------------

int saturate_int(int value, int minimum, int maximum)

  {
    if (value > maximum)
      return maximum;

    if (value < minimum)
      return minimum;

    return value;
  }

//----------------------------------------------------------------------

double saturate_double(double value, double minimum, double maximum)

  {
    if (value > maximum)
      return maximum;

    if (value < minimum)
      return minimum;

    return value;
  }

//----------------------------------------------------------------------

int square_mosaic_is_valid(t_square_mosaic *mosaic)

  {
    int i, opposite_side, dimension_tiles;

    if (mosaic == NULL)
      return 0;

    if (mosaic->tiles_x != mosaic->tiles_y)
      return 0;

    for (i = 0; i < 4; i++)  // for each side
      {
        opposite_side = (i + 2) % 4;

        dimension_tiles = i % 2 == 0 ?
          mosaic->tiles_y : mosaic->tiles_x;

        if (mosaic->side_shape[i] == NULL)
          return 0;

        switch (mosaic->transformation[i])
          {
            case MOSAIC_TRANSFORM_SHIFT:
              if (mosaic->transformation[opposite_side] !=
                MOSAIC_TRANSFORM_SHIFT)
                return 0;

              break;

            case MOSAIC_TRANSFORM_SHIFT_MIRROR:
              if (mosaic->transformation[opposite_side] !=
                MOSAIC_TRANSFORM_SHIFT_MIRROR)
                return 0;

              if (dimension_tiles % 2 != 0)  // multiples of 2 only
                return 0;

              break;

            case MOSAIC_TRANSFORM_ROTATE_SIDE:
              if (dimension_tiles % 2 != 0)
                return 0;

              break;

            case MOSAIC_TRANSFORM_ROTATE_VERTEX:
              if (mosaic->transformation[(i + 1) % 4] !=
                MOSAIC_TRANSFORM_ROTATE_VERTEX)
                return 0;

              if (dimension_tiles % 2 != 0)
                return 0;

              break;
          }
      }

    return 1;
  }

//----------------------------------------------------------------------

t_mosaic_transformation compute_transformation(t_square_mosaic *mosaic,
  unsigned int x, unsigned int y, int *horizontal)

  {
    t_mosaic_transformation tx,ty;

    tx = mosaic->transformation[1];
    ty = mosaic->transformation[0];

    *horizontal = 1;

    if (x % 2 == 0)   // every transform. repeats itself after at most 2
      tx = MOSAIC_TRANSFORM_SHIFT;

    if (y % 2 == 0)
      ty = MOSAIC_TRANSFORM_SHIFT;

    if (tx == MOSAIC_TRANSFORM_SHIFT)
      {
        *horizontal = 0;
        return ty;
      }

    if (ty == MOSAIC_TRANSFORM_SHIFT)
      {
        *horizontal = 1;
        return tx;
      }

    if (tx == MOSAIC_TRANSFORM_ROTATE_VERTEX ||   // C4 + C4
      ty == MOSAIC_TRANSFORM_ROTATE_VERTEX)
      return MOSAIC_TRANSFORM_SHIFT;

    if (tx == MOSAIC_TRANSFORM_ROTATE_SIDE &&     // C + C
        ty == MOSAIC_TRANSFORM_ROTATE_SIDE)
      return MOSAIC_TRANSFORM_SHIFT;

    if (tx == MOSAIC_TRANSFORM_SHIFT_MIRROR &&    // G(h) + G(v)
        ty == MOSAIC_TRANSFORM_SHIFT_MIRROR)
      return MOSAIC_TRANSFORM_ROTATE_VERTEX;

    if (tx == MOSAIC_TRANSFORM_SHIFT_MIRROR &&    // G(v) + C
      ty == MOSAIC_TRANSFORM_ROTATE_SIDE)
      {
        *horizontal = 0;
        return (MOSAIC_TRANSFORM_SHIFT_MIRROR);
      }

    if (ty == MOSAIC_TRANSFORM_SHIFT_MIRROR &&    // G(h) + C
      tx == MOSAIC_TRANSFORM_ROTATE_SIDE)
      {
        *horizontal = 1;
        return (MOSAIC_TRANSFORM_SHIFT_MIRROR);
      }

    return MOSAIC_TRANSFORM_SHIFT; // the function never should get here
  }

//----------------------------------------------------------------------

unsigned char dither_random(unsigned char value, unsigned char levels,
  int random)

  {
    double interval_length;
    unsigned char level,random_number;

    levels--;

    interval_length = 255.0 / (double) (levels);

    for (level = 0; level < levels; level++) // find the value level
      if (value <= (level + 1) * interval_length)
        break;

    value = value - level * interval_length;
    random_number = noise_int_range(random,0,ceil(interval_length));

    if (value >= random_number)
      level++;

    return round_to_char(level * interval_length);
  }

//----------------------------------------------------------------------

unsigned char dither_threshold(unsigned char value,
  unsigned char levels)

  {
    double interval_check,interval_set;
    unsigned int i;

    interval_check = 255.0 / levels;
    interval_set = 255.0 / (levels - 1);

    for (i = 1; i < levels; i++)   // find the level
      if (value < i * interval_check)
        break;

    value = (i - 1) * interval_set;

    return value;
  }

//----------------------------------------------------------------------

int is_power_of_2(unsigned int value)

  {
    unsigned int i,number_of_ones;

    number_of_ones = 0;

    // count the ones in binary:

    for (i = 0; i < 64; i++) // assume maximum of 64 bits for uint
      {
        if (value & 1)
          number_of_ones++;

        value = value >> 1;  // right shift by 1

        if (number_of_ones > 1)
          break;
      }

    return number_of_ones == 1;
  }

//----------------------------------------------------------------------

void make_bayer_matrix(t_matrix *matrix)

  {
    unsigned int i,j,k,x,y;
    int random;

    if (matrix == NULL)
      return;

    for (j = 0; j < matrix->height; j++)
      for (i = 0; i < matrix->width; i++)
        matrix_set_value(matrix,i,j,0.0);

    if (matrix->width == matrix->height && matrix->width == 2)
      {
        for (j = 0; j < matrix->height; j++)
          for (i = 0; i < matrix->width; i++)
            matrix_set_value(matrix,i,j,bayer_matrix_2x2[i][j]);
      }
    else if (matrix->width == matrix->height && matrix->width == 4)
      {
        for (j = 0; j < matrix->height; j++)
          for (i = 0; i < matrix->width; i++)
            matrix_set_value(matrix,i,j,bayer_matrix_4x4[i][j]);
      }
    else if (matrix->width == matrix->height && matrix->width == 8)
      {
        for (j = 0; j < matrix->height; j++)
          for (i = 0; i < matrix->width; i++)
            matrix_set_value(matrix,i,j,bayer_matrix_8x8[i][j]);
      }
    else
      {
        random = 0;

        for (k = 0; k < matrix->width * matrix->height; k++)
          while (1)
            {
              x = noise_int_range(random,0,matrix->width - 1);
              random++;
              y = noise_int_range(random,0,matrix->height - 1);
              random++;

              if (matrix_get_value(matrix,x,y) == 0.0)
                {
                  matrix_set_value(matrix,x,y,(double) k + 1);
                  break;
                }
            }
      }
  }

//----------------------------------------------------------------------

void coord_array_double_to_int(unsigned int destination[][2],
  double source[][2], unsigned int length, unsigned int resolution_x,
  unsigned int resolution_y)

  {
    unsigned int i;

    for (i = 0; i < length; i++)
      {
        destination[i][0] = transform_coordination(source[i][0] *
          (resolution_x - 1),resolution_x);
        destination[i][1] = transform_coordination(source[i][1] *
          (resolution_y - 1),resolution_y);
      }
  }

//----------------------------------------------------------------------
