//**********************************************************************
/** @file
 * Implementation of matrix data type.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------------------------------

int matrix_init(t_matrix *matrix, unsigned int width, unsigned int
  height)

  {
    int length;

    matrix->width = width;
    matrix->height = height;

    length = width * height * sizeof(double);

    matrix->data = (double *) malloc(length);

    if (matrix->data == NULL)
      return 0;

    return 1;
  }

//----------------------------------------------------------------------

void matrix_set_value(t_matrix *matrix, unsigned int position_x,
  unsigned int position_y, double value)

  {
    int index;

    if (position_x >= matrix->width || position_y >= matrix->height)
      return;

    index = position_y * matrix->width + position_x;

    matrix->data[index] = value;
  }

//----------------------------------------------------------------------

double matrix_get_value(t_matrix *matrix, unsigned int position_x,
  unsigned int position_y)

  {
    int index;

    if (position_x >= matrix->width || position_y >= matrix->height)
      return 0;

    index = position_y * matrix->width + position_x;

    return matrix->data[index];
  }

//----------------------------------------------------------------------

void matrix_destroy(t_matrix *matrix)

  {
    if (matrix->data != NULL)
      free(matrix->data);
  }

//----------------------------------------------------------------------

void matrix_print(t_matrix *matrix)

  {
    unsigned int i, j;

    for (j = 0; j < matrix->height; j++)
      {
        for (i = 0; i < matrix->width; i++)
          {
            printf("%lf ",matrix_get_value(matrix,i,j));
          }

        printf("\n");
      }
  }

//----------------------------------------------------------------------
