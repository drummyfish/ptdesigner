//**********************************************************************
/** @file
 * Implementation of general function.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include "general.h"
#include <math.h>

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

        case METRIC_CHEBISHEV:
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

    x = x ^ (x<<13);
    double result = (1.0 - (((x * (x * x * 15731 + 789221) +
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

    if (dx != 0)
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

    while (angle > PI_TIMES_2)  // adjust the angle
      {
        angle -= PI_TIMES_2;
      }

    while (angle < 0)
      {
        angle += PI_TIMES_2;
      }

    angle_area = angle / (PI_DIVIDED_4);

    switch (angle_area)
      {
        case 0:
          *point_x = initial_x + point;
          *point_y = initial_y - point * tan(angle);
          break;

        case 1:
          angle = PI_DIVIDED_2 - angle;
          *point_x = initial_x + point * tan(angle);
          *point_y = initial_y - point;
          break;

        case 2:
          angle = angle - PI_DIVIDED_2;
          *point_x = initial_x - point * tan(angle);
          *point_y = initial_y - point;
          break;

        case 3:
          angle = PI -angle;
          *point_x = initial_x - point;
          *point_y = initial_y - point * tan(angle);
          break;

        case 4:
          angle = angle - PI;
          *point_x = initial_x - point;
          *point_y = initial_y + point * tan(angle);
          break;

        case 5:
          angle = PI_TIMES_3_2 - angle;
          *point_x = initial_x - point * tan(angle);
          *point_y = initial_y + point;
          break;

        case 6:
          angle = angle - PI_TIMES_3_2;
          *point_x = initial_x + point * tan(angle);
          *point_y = initial_y + point;
          break;

        case 7:
          angle = PI_TIMES_2 - angle;
          *point_x = initial_x + point;
          *point_y = initial_y + point * tan(angle);
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

make_game_of_life_rules(int rules[256])

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
