#ifndef MATRIX_H
#define MATRIX_H

//**********************************************************************
/** @file
 * Header file of matrix data type. It provides an interface for
 * handling some necesarry matrix operations.
 *
 * @author Miloslav Ciz
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
