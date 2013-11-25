#ifndef COLORTRANSITION_H
#define COLORTRANSITION_H

//**********************************************************************
/** @file
 * Header file of color abstract transition data type. It provides an
 * interface for creating, storing and using color transitions.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "general.h"
                                /** a structure representing a point in
                                    color transition, it maps one
                                    grayscale value to RGB color */
typedef struct
  {
    unsigned char value;        ///< grayscale value
    unsigned char red;          ///< red channel
    unsigned char green;        ///< green channel
    unsigned char blue;         ///< blue channel
  } t_transition_point;

                                /** color transition structure, it holds
                                    pointer to points which the
                                    transitions consists of */
typedef struct
  {
    int number_of_points;       ///< number of transition points
    t_transition_point *points; ///< array of transition points
  } t_color_transition;

//----------------------------------------------------------------------

int color_transition_init(t_color_transition *transition);

  /**<
   * Initialises a new color transition.
   *
   * @param transition color transition structure to be initialised
   *
   * @return 1 if everything was ok, or 0 if memory could not be
   *         allocated
   */

//----------------------------------------------------------------------

void color_transition_add_point(unsigned char coordination,
  unsigned char red, unsigned char green, unsigned char blue,
  t_color_transition *transition);

  /**<
   * Adds a new point to transition.
   *
   * @param coordination coordination of the point (= grayscale value)
   * @param red amount of red color for the point
   * @param green amount of green color for the point
   * @param blue amount of blue color for the point
   * @param transition transition to add the point to
   */

//----------------------------------------------------------------------

void color_transition_get_color(unsigned char coordination,
  unsigned char *red, unsigned char *green, unsigned char *blue,
  t_color_transition *transition);

  /**<
   * Returns a color that will be mapped to given coordination (i.e.
   * grayscale value) accoording to given color transition.
   *
   * @param coordination coordination of the point (= grayscale value)
   * @param red variable in which to store the amount of red of the
   *        result
   * @param green variable in which to store the amount of green of the
   *        result
   * @param blue variable in which to store the amount of blue of the
   *        result
   * @param transition transition that will map the point to color
   */

//----------------------------------------------------------------------

void color_transition_destroy(t_color_transition *transition);

  /**<
   * Frees the memory allocated for transition.
   *
   * @param transition color transition to be destroyed
   */

//----------------------------------------------------------------------

int color_transition_load_from_file(t_color_transition *transition,
  char *filename);

  /**
   * Loads a color transition from a file. Also serves as an init
   * function.
   *
   * @param transition transition to be loaded, must be deallocated
   * @param filename name of the file from which the transition will be
   *        loaded
   *
   * @return 1 if the transition was loaded succesfully, 0 otherwise
   */

//----------------------------------------------------------------------

int color_transition_save_to_file(t_color_transition *transition,
  char *filename);

  /**
   * Saves color transition to file.
   *
   * @param transition transition to be saved
   * @param filename name of the file
   *
   * @return 1 if the file was saved succesfully, 0 otherwise
   */

//----------------------------------------------------------------------

#endif
