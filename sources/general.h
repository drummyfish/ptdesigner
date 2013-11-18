#ifndef GENERAL_H
#define GENERAL_H

//**********************************************************************
/** @file
 * Header file including definitions of general data structures and
 * functions that should be useful for other modules.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "matrix.h"

#define PI           3.1415926535897932384626 ///< approximate pi value
#define PI_DIVIDED_4 0.7853981633974483096156 ///< pi / 4
#define PI_DIVIDED_2 1.5707963267948966192313 ///< pi / 2
#define PI_TIMES_3_2 4.7123889803846898576939 ///< pi * 3/4
#define PI_TIMES_2   6.2831853071795864769252 ///< pi * 2

                         /** possible ways of measuring distances */
typedef enum
  {
    METRIC_EUCLIDEAN,    ///< distance = sqrt((x1 - x2)^2 + (y1 - y2)^2)
    METRIC_TAXICAB,      ///< distance = abs(x1 - x2) + abs(y1 - y2)
    METRIC_CHEBISHEV     ///< distance = max((x1 - x2),(y1 - y2))
  } t_metric;

                            /** ways in which two values can be
                                interpolated */
typedef enum
  {
    INTERPOLATION_NEAREST,  ///< nearest neighbour interpolation
    INTERPOLATION_LINEAR,   ///< linear interpolation
    INTERPOLATION_SINE      ///< interpolation using sine function
  } t_interpolation_method;

                            /** possible neighbourhood types for
                                cellular automata */

typedef enum
  {
    NEIGHBOURHOOD_MOORE,        ///< Chebishev distance (square)
    NEIGHBOURHOOD_VON_NEUMANN   ///< taxicab distance
  } t_neighbourhood_type;

                            /** possible mosaic tile transformations */
typedef enum
  {
    MOSAIC_TRANSFORM_SHIFT,          ///< the tile is shifted
    MOSAIC_TRANSFORM_ROTATE_SIDE,    /**< the tile is rotated around the
                                          center of the side */
    MOSAIC_TRANSFORM_ROTATE_VERTEX,  /**< the tile is rotated around the
                                          vertex of the side */
    MOSAIC_TRANSFORM_SHIFT_MIRROR,   /**< the tile is shifted and
                                          mirrored */
  } t_mosaic_transformation;

                              /** square mosaic definition, specifies
                                  the tile shape, way in which tiles are
                                  placed and a number of tiles in x and
                                  y direction, not all specifications
                                  are valid (check can be done with
                                  specific functions) */
typedef struct
  {
    char *side_shape[4];      /**< string-specified side shape (CW from
                                   top), the string format should be:
                                   "%lf %lf %lf %lf ..." where odd
                                   position numbers are x coordination
                                   in range <0,1> and others are y
                                   coordinations in range <0,0.5> */

    t_mosaic_transformation transformation[4]; /**< side transformations
                                                    (CW from top) */

    unsigned char tiles_x;    ///< number of tiles in x direction
    unsigned char tiles_y;    ///< number of tiles in y direction
  } t_square_mosaic;

//----------------------------------------------------------------------

int transform_coordination(int coordination, int limit);

  /**<
   * Transforms given coordination so that if it exceeds range
   * <0,limit), it will be remapped to fit that range by
   * "over/underflowing".
   *
   * @param coordination coordination to be transformed
   * @param limit is maximum possible value of the coordination + 1
   *
   * @return transformed coordination in range <0,limit)
   */

//----------------------------------------------------------------------

double get_distance(t_metric metric, int x1, int y1, int x2, int y2,
  int space_width, int space_height);

  /**<
   * Function that returns a distance between two given points in
   * two-dimensional space but it considers a distance across the
   * space edges and returns it, if it's the shortest way.
   *
   * @param metric a metric used for measuring the distance
   * @param x1 x coordination of the first point
   * @param y1 y coordination of the first point
   * @param x2 x coordination of the second point
   * @param y2 y coordination of the second point
   * @param space_width width of the space in which the point are
   *        located
   * @param space_height height of the space
   *
   * @return distance between points
   */

//----------------------------------------------------------------------

double noise(int x);

  /**<
   * Returns random number. Source:
   * http://farao.czweb.org/perlin.htm
   *
   * @param x sequence number of the random number
   *
   * @return random value in range <-1,1> depending on x
   */

//----------------------------------------------------------------------

int noise_int_range(int x, int from, int to);

  /**<
   * Returns random integer number from given range.
   *
   * @param x sequence number of the random number
   * @param from low limit of generated number
   * @param to high limit of generated number
   *
   * @return random value in range <from,to> depending on x
   */

//----------------------------------------------------------------------

void line_point(int initial_x, int initial_y, double angle,
  unsigned int point, int *point_x, int *point_y);

  /**<
   * Computes nth point at given line. Calling this function for given
   * line with sequence numbers from 0 to N and drawing returned points
   * will draw a continuous line.
   *
   * @param initial_x x coordination of initial point of the line
   * @param initial_y y coordination of initial point of the line
   * @param angle angle of the line in radians measured counterclockwise
   *        starting parallel with the x axis
   * @param point sequence number of point that will be computed
   * @param point_x variable in which x coordination will be returned
   * @param point_y variable in which y coordination will be returned
   */

//----------------------------------------------------------------------

void circle_point_by_angle(int center_x, int center_y, double radius,
  double angle,  int *x, int *y);

  /**<
   * Computes point of a circle with given parameters by specified
   * angle.
   *
   * @param center_x x coordination of the circle center
   * @param center_y y coordination of the circle center
   * @param radius radius of the circle
   * @param angle angle of the line in radians measured counterclockwise
   *        starting parallel with the x axis
   * @param x variable in which x coordination of the computed point
   *        will be returned
   * @param y variable in which y coordination of the computed point
   *        will be returned
   */

//----------------------------------------------------------------------

void rgb_to_hsl(unsigned char red, unsigned char green,
  unsigned char blue, double *hue, double *saturation,
  double *lightness);

  /**<
   * Converts specified RGB value to HSL value.
   *
   * @param red amount of red
   * @param green amount of green
   * @param blue amount of blue
   * @param hue variable in which hue is returned as a number in range
   *        <0,1> representing value in range <0,360> degrees
   * @param saturation variable in which saturation is returned as a
   *        number in range <0,1>
   * @param lightness variable in which lightness is returned as a
   *        number in range <0,1>
   */

//----------------------------------------------------------------------

double two_points_to_angle(int x1, int y1, int x2, int y2);

  /**<
   * Returns an angle of line defined by two given points.
   *
   * @param x1 x coordination of the first point
   * @param y1 y coordination of the first point
   * @param x2 x coordination of the second point
   * @param y2 y coordination of the second point
   *
   * @return angle defined by the two points in radians
   */

//----------------------------------------------------------------------

void hsl_to_rgb(double hue, double saturation, double lightness,
  unsigned char *red, unsigned char *green, unsigned char *blue);

  /**<
   * Converts specified HSL value to RGB value.
   *
   * @param hue amount of hue, it is a number in range <0,1>
   *        representing value in range <0,360> degrees
   * @param saturation amount of saturation, it is a number in range
   *        <0,1>
   * @param lightness amount of lightness, it is a number in range <0,1>
   * @param red variable in which amount of red will be returned
   * @param green variable in which amount of green will be returned
   * @param blue variable in which amount of blue will be returned
   */

//----------------------------------------------------------------------

double degrees_to_radians(double degrees);

  /**<
   * Converts angle in degrees to radians.
   *
   * @param degrees angle in degrees
   *
   * @return angle in radians
   */

//----------------------------------------------------------------------

double radians_to_degrees(double radians);

  /**<
   * Converts angle in radians to degrees.
   *
   * @param radians angle in randians
   *
   * @return angle in degrees
   */

//----------------------------------------------------------------------

unsigned char round_to_char(int value);

  /**<
   * Transforms given value so that it fits the unsigned char range. If
   * the value is greater than 255, 255 is returned. If the value is
   * smaller than 0, 0 is returned. Othervise the value is returned.
   *
   * @return rounded value
   */

//----------------------------------------------------------------------

void normalise_vector_3(double *x, double *y, double *z);

  /**<
   * Normalises given vector (makes it's magnitude 1).
   *
   * @param x x element of the vector
   * @param y y element of the vector
   * @param z z element of the vector
   */

//----------------------------------------------------------------------

double interpolate(double value, t_interpolation_method method);

  /**<
   * Interpolates given value between 0 and 1 to range between 0 and 1
   * using given method.
   *
   * @param value value in range <0,1>
   * @param method method of interpolation
   *
   * @return interpolated value in range <0,1> at given point
   */

//----------------------------------------------------------------------

double interpolate_values(double value, t_interpolation_method method,
  int value1, int value2);

  /**<
   * Interpolates given value between 0 and 1 to range between value1
   * and value2 using given method.
   *
   * @param value value in range <0,1>
   * @param method method of interpolation
   *
   * @return interpolated value in range <value1,value2> at given point
   */

//----------------------------------------------------------------------

void interpolate_color_2d(double x, double y, unsigned char top_left[3],
  unsigned char top_right[3], unsigned char bottom_left[3],
  unsigned char bottom_right[3], unsigned char *r, unsigned char *g,
  unsigned char *b, t_interpolation_method method);

  /**<
   * Performs 2D interpolation between four square vertices.
   *
   * @param x x position in range <0,1>
   * @param y y position in range <0,1>
   * @param top_left top left color in format [r,g,b]
   * @param top_right top right color in format [r,g,b]
   * @param bottom_left bottom left color in format [r,g,b]
   * @param bottom_right bottom right color in format [r,g,b]
   * @param r in this variable final amount of red will be returned
   * @param g in this variable final amount of green will be returned
   * @param b in this variable final amount of blue will be returned
   * @param method interpolation method
   */

//----------------------------------------------------------------------

unsigned int rock_paper_scissors(unsigned int options,
  unsigned int player1, unsigned int player2);

  /**<
   * Determines the winner of generalised rock paper scissors game.
   *
   * @param options number of options of the game (for the classic
   *        rock, paper, scissors this is 3), note that this must be
   *        an odd number greater or equal to 3
   * @param player1 number of option chosen by player 1
   * @param player1 number of option chosen by player 2
   *
   * @return either value of player1 or player2 depending on who the
   *         winner is
   */

//----------------------------------------------------------------------

unsigned int make_neighbourhood(t_neighbourhood_type type, unsigned int
  size, int position_differences[128][2]);

  /**<
   * Creates a list of position differences that represent given
   * neighbourhood type.
   *
   * @param type neighbourhood type
   * @param size neighbourhood size, should be in interval <0,10>
   * @param position_differences in this list the relative position
   *        differences will be stored in format [dx,dy]
   *
   * @return length of the list of position differences (number of
   *         points of the neighbourhood)
   */

//----------------------------------------------------------------------

int power_int(int number, unsigned int power);

  /**<
   * Computes integer power of an integer number.
   *
   * @param number number to be raised
   * @param power power to raise the number to
   *
   * @return number to the power of power
   */

//----------------------------------------------------------------------

void make_game_of_life_rules(int rules[256]);

  /**<
   * Fills given array with binary representation of Conway's Game of
   * life cellular automaton rules. The array can be passed to the
   * function that expects specifying rules in such format.
   *
   * @param rules this array will be filled with the rules
   */

//----------------------------------------------------------------------

int saturate_int(int value, int minimum, int maximum);

  /**<
   * Applies saturation arithmetic to given integer value making it fit
   * given range.
   *
   * @param value value to be saturated
   * @param minimum minimum allowed value
   * @param maximum maximum allowed value
   *
   * @return saturated value, i.e. if it was greater then maximum,
   *         maximum is returned, if it was lower than minimum, minimum
   *         is returned, otherwise value is returned
   */

//----------------------------------------------------------------------

double saturate_double(double value, double minimum, double maximum);

  /**<
   * Applies saturation arithmetic to given double value making it fit
   * given range.
   *
   * @param value value to be saturated
   * @param minimum minimum allowed value
   * @param maximum maximum allowed value
   *
   * @return saturated value, i.e. if it was greater then maximum,
   *         maximum is returned, if it was lower than minimum, minimum
   *         is returned, otherwise value is returned
   */

//----------------------------------------------------------------------

int square_mosaic_is_valid(t_square_mosaic *mosaic);

  /**<
   * Checks whether given square mosaic specification is valid, i.e.
   * transformation combinations are allowed and x and y tiling does
   * connect to itself on the other side.
   *
   * @param mosaic mosaic specification
   *
   * @return 1 if the specification is valid, 0 otherwise
   */

//----------------------------------------------------------------------

t_mosaic_transformation compute_transformation(t_square_mosaic *mosaic,
  unsigned int x, unsigned int y, int *horizontal);

  /**<
   * Computes a final transformation for a tile at specified position
   * in square mosaic.
   *
   * @param mosaic mosaic specification
   * @param x x position of the tile
   * @param y y position of the tile
   * @param horizontal in this variable posiible further specification
   *        of transformation is returned, it will either be 1
   *        (horizontal) or 0 (vertical)
   *
   * @return final transformation of the tile
   */

//----------------------------------------------------------------------

unsigned char dither_random(unsigned char value, unsigned char levels,
  int random);

  /**<
   * Performs a random dithering with one value.
   *
   * @param value value to be dithered
   * @param levels number of levels of dithering
   * @param random value that will be passed to noise function and that
   *        will affect the randomness of dithering
   *
   * @return dithered value
   */

//----------------------------------------------------------------------

unsigned char dither_threshold(unsigned char value,
  unsigned char levels);

  /**<
   * Performs a threshold operation with one value.
   *
   * @param value value to be thresholded
   * @param levels number of levels of thresholding
   *
   * @return thresholded value
   */

//----------------------------------------------------------------------

int is_power_of_2(unsigned int value);

  /**<
   * Checks if given value is power of two.
   *
   * @param value value to be tested
   *
   * @return 1 if the value is power of two, 0 otherwise
   */

//----------------------------------------------------------------------

void make_bayer_matrix(t_matrix *matrix);

  /**<
   * Fills given matrix with integer values from 1 to (matrix width *
   * matrix height) in a way that Bayer specified for ordered dithering.
   * Non-power of two matrices are also allowed (the values are placed
   * randomly in this case).
   *
   * @param matrix matrix in which Bayer matrix will be stored, must be
   *        initialised
   */

//----------------------------------------------------------------------

#endif
