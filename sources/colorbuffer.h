#ifndef COLORBUFFER_H
#define COLORBUFFER_H

//**********************************************************************
/** @file
 * Header file of color buffer abstract data type. It server as an RGB
 * image container and provides basic operations for manipulating the
 * image.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include "kdtree.h"

                           /** color buffer structure, it holds the
                               pointer to image in the memory */
typedef struct
  {
    unsigned int width;    ///< bitmap width
    unsigned int height;   ///< bitmap height
    unsigned char *data;   ///< raw pixel data in RGB 24bit mode
  } t_color_buffer;

//----------------------------------------------------------------------

int color_buffer_init(t_color_buffer *buffer, int width, int height);

  /**<
   * Initialises a new buffer.
   *
   * @param buffer buffer structure to be initialised
   * @param width width of the image
   * @param height height of the image
   *
   * @return 1 if everything was ok, or 0 if memory could not be
   *         allocated
   */

//----------------------------------------------------------------------

void color_buffer_copy(t_color_buffer *buffer,
  t_color_buffer *destination);

  /**<
   * Copies one color buffer into another newly created one.
   *
   * @param buffer buffer buffer to be copied
   * @param destination buffer to copy the first buffer to, must be
   *        dealocated before this function is called
   */

//----------------------------------------------------------------------

void color_buffer_copy_data(t_color_buffer *buffer,
  t_color_buffer *destination);

  /**<
   * Copies one color buffer into another already existing one.
   *
   * @param buffer buffer buffer to be copied
   * @param destination buffer to copy the first buffer to, must be
   *        already initialised and should be of the same resolution as
   *        the source buffer
   */

//----------------------------------------------------------------------

void color_buffer_set_pixel(t_color_buffer *buffer, int position_x,
  int position_y, unsigned char red, unsigned char green,
  unsigned char blue);

  /**<
   * Sets pixel at given coordination to given color. If one of the
   * coordinations is out of image's resolution range, it will
   * "overflow" over the edge to the other side (wraparound).
   *
   * @param position_x x position of the pixel
   * @param position_y y position of the pixel
   * @param red new red value
   * @param green new green value
   * @param blue new blue value
   */

//----------------------------------------------------------------------

void color_buffer_add_pixel(t_color_buffer *buffer, int position_x,
  int position_y, unsigned char red, unsigned char green,
  unsigned char blue);

  /**<
   * Adds given values to pixel at given position in the color buffer.
   * If one of the coordinations is out of image's resolution range, it
   * will "overflow" over the edge to the other side (wraparound).
   *
   * @param position_x x position of the pixel
   * @param position_y y position of the pixel
   * @param red value to be added to red channel of the pixel
   * @param green value to be added to green channel of the pixel
   * @param blue value to be added to blue channel of the pixel
   */

//----------------------------------------------------------------------

void color_buffer_substract_pixel(t_color_buffer *buffer,
  int position_x, int position_y, unsigned char red,
  unsigned char green, unsigned char blue);

  /**<
   * Substracts given values from pixel at given position in the color
   * buffer. If one of the coordinations is out of image's resolution
   * range, it will "overflow" over the edge to the other side
   * (wraparound).
   *
   * @param position_x x position of the pixel
   * @param position_y y position of the pixel
   * @param red value to be substracted from red channel of the pixel
   * @param green value to be substracted from green channel of the
   *        pixel
   * @param blue value to be substracted from blue channel of the pixel
   */

//----------------------------------------------------------------------

void color_buffer_get_pixel(t_color_buffer *buffer, int position_x,
  int position_y, unsigned char *red, unsigned char *green,
  unsigned char *blue);

  /**<
   * Gets RGB value of given pixel. If one of the coordinations exceeds
   * the image's resolution range, it will "overflow" over the edge to
   * the other side (wraparound). If any of red, green or blue parameter
   * is NULL, the function will not crash.
   *
   * @param position_x x position of the pixel
   * @param position_y y position of the pixel
   * @param red variable to store the red value to, may be NULL
   * @param green variable to store the green value to, may be NULL
   * @param blue variable to store the blue value to, may be NULL
   */

//----------------------------------------------------------------------

void color_buffer_destroy(t_color_buffer *buffer);

  /**<
   * Dealocates the memory used for the buffer.
   *
   * @param buffer buffer to be destroyed
   */

//----------------------------------------------------------------------

int color_buffer_save_to_png(t_color_buffer *buffer, char *filename);

  /**<
   * Saves the buffer content to png file of given name.
   *
   * @param buffer buffer to be saved
   * @param filename name of the file
   *
   * @return 1 if evreything was ok, or 0 if file could not be saved
   */

//----------------------------------------------------------------------

int color_buffer_load_from_png(t_color_buffer *buffer, char *filename);

  /**<
   * Loads image from png file and stores it in given color buffer.
   *
   * @param buffer buffer to store the image to, it should be dealocated
   *        before this function is called
   * @param filename name of the file
   *
   * @return 1 if evreything was ok, or 0 if file could not be opened
   */

//----------------------------------------------------------------------

#endif
