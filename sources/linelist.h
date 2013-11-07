#ifndef LINELIST_H
#define LINELIST_H

//**********************************************************************
/** @file
 * Header file of line list used for storing variable number of
 * information about lines. This information consists of one point
 * in 2D space, line angle, line length and an information about whether
 * the line is already completely drawn. This data structure serves
 * mainly for substrate algorithm purposes, but may be used for other
 * purposes as well (it may be used as a stack).
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include <stdio.h>
#include "general.h"

                               /** the line list structure */
typedef struct
  {
    unsigned int length;       ///< list length
    int *x_positions;          ///< array of x positions of points
    int *y_positions;          ///< array of y positions of points
    double *fp_numbers;        ///< array of angles
    int *lengths;              /**< array of information about whether
                                    the line is completed */
  } t_line_list;

//----------------------------------------------------------------------

int line_list_init(t_line_list *list);

  /**<
   * Initialises a new line list.
   *
   * @param list line list to be initialised
   *
   * @return 1 if everything was ok, or 0 if memory could not be
   *         allocated
   */

//----------------------------------------------------------------------

int line_list_add(t_line_list *list, int point_x, int point_y,
  double fp_parameter, int length);

  /**<
   * Adds line (circle) information to given list.
   *
   * @param list line list to add the information to
   * @param point_x x position of point being added
   * @param point_y y position of point being added
   * @param fp_parameter floating point number asociated with point
   *        being added
   * @param length line length
   *
   * @return 1 if everything was ok, or 0 if memory could not be
   *         allocated
   */

//----------------------------------------------------------------------

void line_list_pop(t_line_list *list);

  /**<
   * Deletes the last element of the list if there is any.
   *
   * @param list list of which the last element should be deleted
   */

//----------------------------------------------------------------------

void line_list_set(t_line_list *list, unsigned int element_number,
  int point_x, int point_y, double fp_parameter, int length);

  /**<
   * Sets given element in given list to given value.
   *
   * @param list line list to add the information to
   * @param element_number element position in the buffer
   * @param point_x new x position of point
   * @param point_y new y position of point
   * @param fp_parameter new value of floating point number
   * @param length new value of line length
   */

//----------------------------------------------------------------------

int line_list_get_length(t_line_list *list);

  /**<
   * Returns length of given line list.
   *
   * @param list list to get the width of
   *
   * @return number of list's elemnts
   */

//----------------------------------------------------------------------

void line_list_get(t_line_list *list, unsigned int element_number,
  int *point_x, int *point_y, double *fp_parameter, int *length);

  /**<
   * Returns information at given position in the line list.
   *
   * @param list line list to get the information from
   * @param element_number element position in the buffer
   * @param point_x variable in which x position will be returned
   * @param point_y variable in which y position will be returned
   * @param fp_parameter variable in which floating point number will
   *        be returned, may be NULL in which case it won't be used
   * @param length variable in which length will be stored, may be NULL
   *        in which case it won't be used
   */

//----------------------------------------------------------------------

void line_list_destroy(t_line_list *list);

  /**<
   * Destroys given line list.
   *
   * @param list line list to be destroyed
   */

//----------------------------------------------------------------------

#endif
