//**********************************************************************
/** @file
 * Implementation of line (circle) list.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include "linelist.h"
#include <stdio.h>
#include <stdlib.h>
#include "general.h"

#define ALLOCATE_BY 256      ///< allocation unit of the list

//----------------------------------------------------------------------

int line_list_init(t_line_list *list)

  {
    list->length = 0;

    list->x_positions = (int *) malloc(ALLOCATE_BY * sizeof(int));

    if (list->x_positions == NULL)
      return 0;

    list->y_positions = (int *) malloc(ALLOCATE_BY * sizeof(int));

    if (list->y_positions == NULL)
      {
        free(list->x_positions);
        return 0;
      }

    list->fp_numbers = (double *) malloc(ALLOCATE_BY * sizeof(double));

    if (list->fp_numbers == NULL)
      {
        free(list->x_positions);
        free(list->y_positions);
        return 0;
      }

    list->lengths = (int *) malloc(ALLOCATE_BY * sizeof(int));

    if (list->lengths == NULL)
      {
        free(list->x_positions);
        free(list->y_positions);
        free(list->fp_numbers);
        return 0;
      }

    return 1;
  }

//----------------------------------------------------------------------

int line_list_add(t_line_list *list, int point_x, int point_y,
  double fp_parameter, int length)

  {
    int new_length;

    if (list->length != 0 && list->length % ALLOCATE_BY == 0)
      {                                   // must reallocate the memory
        new_length = (((list->length / ALLOCATE_BY) + 1) * ALLOCATE_BY);

        list->x_positions = (int *) realloc(list->x_positions,
          new_length * sizeof(int));

        if (list->x_positions == NULL)
          return 0;

        list->y_positions = (int *) realloc(list->y_positions,
          new_length * sizeof(int));

        if (list->y_positions == NULL)
          {
            free(list->x_positions);
            return 0;
          }

        list->fp_numbers = (double *) realloc(list->fp_numbers,
          new_length * sizeof(double));

        if (list->fp_numbers == NULL)
          {
            free(list->x_positions);
            free(list->y_positions);
            return 0;
          }

        list->lengths = (int *) realloc(list->lengths, new_length *
          sizeof(int));

        if (list->lengths == NULL)
          {
            free(list->x_positions);
            free(list->y_positions);
            free(list->fp_numbers);
            return 0;
          }
      }

    list->x_positions[list->length] = point_x;
    list->y_positions[list->length] = point_y;
    list->fp_numbers[list->length] = fp_parameter;
    list->lengths[list->length] = length;
    list->length++;

    return 1;
  }

//----------------------------------------------------------------------

void line_list_pop(t_line_list *list)

  {
    if (list->length > 0)
      list->length--;
  }

//----------------------------------------------------------------------

void line_list_set(t_line_list *list, unsigned int element_number,
  int point_x, int point_y, double fp_parameter, int length)

  {
    if (element_number >= list->length)
      return;

    list->x_positions[element_number] = point_x;
    list->y_positions[element_number] = point_y;
    list->fp_numbers[element_number] = fp_parameter;
    list->lengths[element_number] = length;
  }

//----------------------------------------------------------------------

int line_list_get_length(t_line_list *list)

  {
    return list->length;
  }

//----------------------------------------------------------------------

void line_list_get(t_line_list *list, unsigned int element_number,
  int *point_x, int *point_y, double *fp_parameter, int *length)

  {
    if (element_number >= list->length)
      return;

    *point_x = list->x_positions[element_number];
    *point_y = list->y_positions[element_number];

    if (fp_parameter != NULL)
      *fp_parameter = list->fp_numbers[element_number];

    if (fp_parameter != NULL)
      *length = list->lengths[element_number];
  }

//----------------------------------------------------------------------

void line_list_destroy(t_line_list *list)

  {
    list->length = 0;

    free(list->x_positions);
    free(list->y_positions);
    free(list->fp_numbers);
    free(list->lengths);
  }

//----------------------------------------------------------------------
