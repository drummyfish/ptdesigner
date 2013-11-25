//**********************************************************************
/** @file
 * Implementation of color transition data type.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include "colortransition.h"

//----------------------------------------------------------------------

int color_transition_init(t_color_transition *transition)
  {
    transition->number_of_points = 0;

    if ( (transition->points = (t_transition_point *)
      malloc(256 * sizeof(t_transition_point))) )
      return 1;
    else
      return 0;
  }

//----------------------------------------------------------------------

void color_transition_add_point(unsigned char coordination,
  unsigned char red, unsigned char green, unsigned char blue,
  t_color_transition *transition)

  {
    int i,j;
    t_transition_point new_point;

    if (transition->number_of_points == 255)  // no more room for points
      return;

    new_point.red = red;
    new_point.green = green;
    new_point.blue = blue;
    new_point.value = coordination;

               // find a place to put the point to so they remain sorted
    for (i = 0; i < transition->number_of_points; i++)
      if (coordination <= transition->points[i].value)
        break;

    if (i != transition->number_of_points &&
      transition->number_of_points > 0 &&
      transition->points[i].value == coordination)
        return; // point with this coordination already exists => return

    transition->number_of_points++;

    /* shift all points with higher value right so they make room for
       the new one */

    for (j = transition->number_of_points - 1; j > i; j--)
      transition->points[j] = transition->points[j - 1];

    transition->points[i] = new_point;
  }

//----------------------------------------------------------------------

void color_transition_get_color(unsigned char coordination,
  unsigned char *red, unsigned char *green, unsigned char *blue,
  t_color_transition *transition)

  {
    t_transition_point low_point, high_point;
    int i;
    double ratio, complement_ratio;

    if (transition->number_of_points == 0)
      {
        *red = 128;
        *green = 128;
        *blue = 128;
        return;
      }

    for (i = 0; i <= transition->number_of_points; i++)
      if (i == transition->number_of_points ||
        coordination < transition->points[i].value)
        break;

    /* now in i is stored index of the first point larger than the
       point being interpoled */

    if (i == 0)
      {        // no lower point -> transition is constant in this area
        *red = transition->points[0].red;
        *green = transition->points[0].green;
        *blue = transition->points[0].blue;
        return;
      }
    else if (i == transition->number_of_points)
      {        // no higher point -> transition is constant in this area
        *red = transition->points[transition->number_of_points - 1].red;
        *green =
          transition->points[transition->number_of_points - 1].green;
        *blue =
          transition->points[transition->number_of_points - 1].blue;
        return;
      }
    else
      {
        low_point.value = transition->points[i - 1].value;
        low_point.red = transition->points[i - 1].red;
        low_point.green = transition->points[i - 1].green;
        low_point.blue = transition->points[i - 1].blue;

        high_point.value = transition->points[i].value;
        high_point.red = transition->points[i].red;
        high_point.green = transition->points[i].green;
        high_point.blue = transition->points[i].blue;
      }

    if (high_point.value - low_point.value != 0)
      {
        ratio = ((double) (coordination - low_point.value)) /
          (high_point.value - low_point.value);

        complement_ratio = 1.0 - ratio;
      }

    *red = (unsigned char)
      low_point.red * complement_ratio + high_point.red * ratio;

    *green = (unsigned char)
      low_point.green * complement_ratio + high_point.green * ratio;

    *blue = (unsigned char)
      low_point.blue * complement_ratio + high_point.blue * ratio;

    return;
  }

//----------------------------------------------------------------------

void color_transition_destroy(t_color_transition *transition)

  {
    free(transition->points);
    transition->points = NULL;
  }

//----------------------------------------------------------------------

int color_transition_load_from_file(t_color_transition *transition,
  char *filename)

  {
    FILE *file;
    int help_array[4];

    if (!color_transition_init(transition))
      return 0;

    file = fopen(filename,"r");

    if (file == NULL)
      return 0;

    while (1)
      {
        if (fscanf(file,"%d %d %d %d\n",&help_array[0],&help_array[1],
          &help_array[2],&help_array[3]) != 4)
          break;

        color_transition_add_point(round_to_char(help_array[0]),
          round_to_char(help_array[1]),round_to_char(help_array[2]),
          round_to_char(help_array[3]),transition);
      }

    fclose(file);

    return 1;
  }

//----------------------------------------------------------------------

int color_transition_save_to_file(t_color_transition *transition,
  char *filename)

  {
    FILE *file;
    int i;

    file = fopen(filename,"w");

    if (file == NULL)
      return 0;

    for (i = 0; i < transition->number_of_points; i++)
      {
        fprintf(file,"%d %d %d %d\n",transition->points[i].value,
          transition->points[i].red,transition->points[i].green,
          transition->points[i].blue);
      }

    fclose(file);

    return 1;
  }

//----------------------------------------------------------------------
