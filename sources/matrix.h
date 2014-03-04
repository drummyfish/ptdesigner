#ifndef MATRIX_H
#define MATRIX_H

//**********************************************************************

/** @file
 * Header file of matrix data type. It provides an interface for
 * handling some necesarry matrix operations.
 *
 * @author Miloslav Ciz
 */
 
/*
 * Copyright 2014 Miloslav Číž
 *
 * This file is part of PT Designer.
 *
 * PT Designer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PT Designer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with these files. If not, see <http://www.gnu.org/licenses/>.
 */
 
//**********************************************************************

                           /** represents a matrix, contains a pointer
                               to matrix data in memory */
typedef struct
  {
    unsigned int width;    ///< matrix width
    unsigned int height;   ///< matrix height
    double *data;          ///< pointer to matrix data
  } t_matrix;

//----------------------------------------------------------------------

int matrix_init(t_matrix *matrix, unsigned int width, unsigned int
  height);

  /**<
   * Initialises a new matrix. It's memory must be freed with destroy
   * function before this function is called. The matrix is initialised
   * with undefined values.
   *
   * @param matrix matrix structure to be initialised
   * @param width width of the matrix
   * @param height height of the matrix
   *
   * @return 1 if everything was ok, or 0 if memory could not be
   *         allocated
   */

//----------------------------------------------------------------------

void matrix_set_value(t_matrix *matrix, unsigned int position_x,
  unsigned int position_y, double value);

  /**<
   * Sets value at given coordinates in matrix.
   *
   * @param matrix matrix to be modified
   * @param position_x x position
   * @param position_y y position
   * @param value value to be set in the matrix
   */

//----------------------------------------------------------------------

double matrix_get_value(t_matrix *matrix, unsigned int position_x,
  unsigned int position_y);

  /**<
   * Returns the value at given coordinations in matrix.
   *
   * @param matrix matrix in which the needed value is located
   * @param position_x x position of the value
   * @param position_y y position of the value
   *
   * @return value at given place
   */

//----------------------------------------------------------------------

void matrix_destroy(t_matrix *matrix);

  /**<
   * Dealocates the memory used by the matrix.
   *
   * @param matrix matrix to be destroyed
   */

//----------------------------------------------------------------------

void matrix_print(t_matrix *matrix);

  /**<
   * Prints the matrix content to standard output.
   *
   * @param matrix matrix to be printed
   */

//----------------------------------------------------------------------

#endif
