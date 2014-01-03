#ifndef PROCTEXTURES_H
#define PROCTEXTURES_H

//**********************************************************************
/** @file
 * Header file providing advanced color buffer operations. The functions
 * provided are able to handle convolutions, generating Voronoi
 * diagrams, noise bitmaps and other things needed for making procedural
 * textures.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include "matrix.h"
#include "colorbuffer.h"
#include "colortransition.h"
#include "general.h"
#include "grammar.h"
                              /** ways in which Voronoi diagrams can
                                   be created */
typedef enum
  {
    VORONOI_DISTANCE = 0,     /**< pixel color depends on distance to
                                   the nearest point */
    VORONOI_2_NEAREST_RATIO,  /**< pixel color depends on distance ratio
                                   from the nearest two points */
    VORONOI_NEAREST_HASH      /**< the pixel's color is computed only
                                   based on the nearest point position
                                   */
  } t_voronoi_type;

                            /** ways in which points can be placed
                                when generating Voronoi diagrams */
typedef enum
  {
    PLACE_RANDOM = 0,       ///< place points randomly
    PLACE_SQUARE,           ///< place points in a square
    PLACE_CIRCLE,           ///< place points in a circle
    PLACE_CROSS_HORIZONTAL, ///< place points in horizontal cross
    PLACE_CROSS_DIAGONAL,   ///< place points in diagonal cross
    PLACE_CUSTOM            ///< let user place the points
  } t_point_place_type;

                            /** ways in which buffers can be mixed
                                 together */
typedef enum
  {
    MIX_ADD = 0,            ///< pixel color = buffer1 + buffer2
    MIX_SUBSTRACT,          ///< pixel color = buffer1 - buffer2
    MIX_AVERAGE,            ///< pixel color = (buffer1 + buffer2) / 2
    MIX_MULTIPLY            ///< pixel color = buffer1 * buffer2 (float)
  } t_mix_type;

                              /** possible values that can be passed to
                                  edge detection functions */
typedef enum
  {
    DETECTION_HORIZONTAL = 0, ///< detect horizontal edges
    DETECTION_VERTICAL,       ///< detect vertical edges
    DETECTION_BOTH            ///< detect both types of edges
  } t_edge_detection_type;

                              /** possible directions of image blur,
                                  flip and so on */
typedef enum
  {
    DIRECTION_HORIZONTAL = 0, ///< horizontal direction
    DIRECTION_VERTICAL,       ///< vertical direction
    DIRECTION_DIAGONAL_LU_RD, ///< left-up to righ-down direction
    DIRECTION_DIAGONAL_LD_RU  ///< left-down to right-up direction
  } t_direction;

                              /** possible ways of filling areas with
                                  constant color */
typedef enum
  {
    FILL_NONE = 0,            ///< no fill
    FILL_KEEP_BORDERS,        ///< fill and keep black borders
    FILL_NO_BORDERS           ///< fill the areas and also their borders
  } t_fill_type;

                              /** curves for computing specular
                                  reflections with lighting */
typedef enum
  {
    REFLECTION_CURVE_COSINE_SMOOTH = 0,  ///< (cosine + 1) / 2
    REFLECTION_CURVE_COSINE_ABS,    ///< absolute value of cosine
    REFLECTION_CURVE_LINEAR_HALF,   ///< linear dependency to pi / 2
    REFLECTION_CURVE_LINEAR_FULL    ///< linear dependency to pi
  } t_reflection_curve;

                              /** possible methods of dithering */

typedef enum
  {
    DITHERING_THRESHOLD = 0,        ///< threshold dithering
    DITHERING_RANDOM,               ///< random dithering
    DITHERING_ERROR_PROPAGATION,    ///< Floyd–Steinberg dithering
    DITHERING_ORDERED               ///< ordered dithering
  } t_dithering_method;

//----------------------------------------------------------------------

void pt_color_fill(t_color_buffer *buffer, int red, int green,
  int blue);

  /**<
   * Fills given buffer with given color.
   *
   * @param buffer buffer to be filled with the color
   * @param red amount of red in the fill color
   * @param green amount of green in the fill color
   * @param blue amount of blue in the fill color
   */

//----------------------------------------------------------------------

void pt_add_rgb(t_color_buffer *buffer, int red, int green, int blue);

  /**<
   * Adds constants to each pixel of given color buffer.
   *
   * @param buffer input (and output) buffer of the operation
   * @param red value to add to red channel
   * @param green value to add to green channel
   * @param blue value to add to blue channel
   */

//----------------------------------------------------------------------

void pt_add_hsl(t_color_buffer *buffer, double hue, double saturation,
  double lightness);

  /**<
   * Adds HSV value to each pixel of given color buffer.
   *
   * @param buffer input (and output) buffer of the operation
   * @param hue value in range <-1,1> to add to hue
   * @param saturation value in range <-1,1> to add to saturation
   * @param lightness value in range <-1,1> to add to lightness
   */

//----------------------------------------------------------------------

void pt_add_brightness_contrast(t_color_buffer *buffer,
  double brightness, double contrast);

  /**<
   * Adjust brightness and/or contrast of given image by adding
   * specified values.
   *
   * @param buffer image to be adjusted
   * @param brightness amount of brightness to add, must be in range
   *        <-1,1>
   * @param contrast amount of contrast to add, must be in range <-1,1>
   */

//----------------------------------------------------------------------

void pt_add_value(t_color_buffer *buffer, int value);

  /**<
   * Adds a constant value to each pixel of given color buffer.
   *
   * @param buffer input (and output) buffer of the operation
   * @param value value to be added to each pixel
   */

//----------------------------------------------------------------------

void pt_multiply_value(t_color_buffer *buffer, double value);

  /**<
   * Multiplies each pixel of given buffer by given value.
   *
   * @param buffer input (and output) buffer of the operation
   * @param value value to multiply each pixel by, must be greater than
   *        or equal to zero
   */

//----------------------------------------------------------------------

void pt_shift(t_color_buffer *buffer, int shift_x, int shift_y);

  /**<
   * Shifts all pixel positions in given buffer by given x and y offset,
   * shifting pixels over buffers edge will move them to the oposite
   * edge.
   *
   * @param buffer color buffer in which the pixels will be shifted
   * @param shift_x x offset of the shift
   * @param shift_y y offset of the shift
   */

//----------------------------------------------------------------------

void pt_rotate(t_color_buffer *buffer, double angle);

  /**<
   * Rotates specified image by given angle.
   *
   * @param buffer color buffer in which the pixels will be shifted
   * @param angle clockwise angle of the rotation
   */

//----------------------------------------------------------------------

void pt_flip(t_color_buffer *buffer, t_direction direction);

  /**<
   * Flips an image in color buffer in specified direction.
   *
   * @param buffer color buffer in which the image will be flipped
   * @param direction direction in which the image will be flipped, may
   *        only be horizontal or vertical (not diagonal)
   */

//----------------------------------------------------------------------

void pt_tile(t_color_buffer *buffer, unsigned int times,
  t_color_buffer *destination);

  /**<
   * Resizes the texture to smaller resolution and repeats it given
   * number of times horizontaly and verticaly so that it will keep the
   * original resolution.
   *
   * @param buffer input color buffer of the operation
   * @param times how many times the texture will be repeated
   *        horizontaly and verticaly
   * @param destination color buffer in which the result will be stored,
   *        it must be dealocated before this function is called
   */

//----------------------------------------------------------------------

void pt_change_resolution(t_color_buffer *buffer,
  unsigned int new_width, unsigned int new_height);

  /**<
   * Changes resolution of the color buffer keeping the image it
   * contains. The image is not resized, it is either cut or copied so
   * that it will fit the new resolution.
   *
   * @param buffer buffer to change the resolution of
   * @param new_width new width in pixels
   * @param new_height new height in pixels
   */

//----------------------------------------------------------------------

void pt_resize(t_color_buffer *buffer, t_color_buffer *destination,
  t_interpolation_method interpolation);

  /**<
   * Resizes the image in buffer so it fits the size of destination and
   * stores the image in destination.
   *
   * @param buffer image to be resized
   * @param destination buffer in which the resized image will be
   *        stored, its size determines the new image size so it must be
   *        initialised when this function is called
   * @param interpolation method of pixel value interpolation
   */

//----------------------------------------------------------------------

void pt_supersampling(t_color_buffer *buffer, unsigned int level,
  t_color_buffer *destination);

  /**<
   * Performs supersampling with given color buffer. This operation
   * smooths the whole image but reduces it's resolution.
   *
   * @param buffer input buffer of the operation
   * @param level supersampling level, value of one has no effect,
   *        higher values makes the image smaller and smoother (for
   *        example number 2 will make the image 2x smaller)
   * @param destination color buffer in which the result will be stored,
   *        must be deallocated before this function is called
   */

//----------------------------------------------------------------------

void pt_add_buffers(t_color_buffer *buffer1, t_color_buffer *buffer2);

  /**<
   * Adds one color buffer's pixel values to other buffer's pixel
   * values.
   *
   * @param buffer1 buffer to be added to buffer2
   * @param buffer2 buffer to which buffer1 will be added and in which
   *        the result will be stored
   */

//----------------------------------------------------------------------

void pt_substract_buffers(t_color_buffer *buffer1,
  t_color_buffer *buffer2);

  /**<
   * Substracts one color buffer's pixel values from other buffer's
   * pixel values.
   *
   * @param buffer1 to be substracted from the second buffer
   * @param buffer2 buffer from which the first buffer will be
   *        substracted and in which the result will be stored
   */

//----------------------------------------------------------------------

void pt_mix_buffers(t_color_buffer *buffer1, t_color_buffer *buffer2,
  t_color_buffer *destination, int percentage, t_mix_type type,
  t_color_buffer *buffer_alpha);

  /**<
   * Mixes two buffers together in given way, both buffers must be of
   * the same sizes.
   *
   * @param buffer1 first buffer to be mixed with the other
   * @param buffer2 second buffer to be mixed with the other
   * @param destination this buffer will be filled with the result of
   *        mixing, it muse be dealocated before this function is called
   *        and must be different from the input buffers
   * @param percentage percentage value (0-100) specifiying the ratio
   *        of the mix, value 0 - 50 mean that 100% of the buffer1
   *        values will be used and 0% - 100% values of buffer2 will be
   *        used, values 50 - 100 mean that 100% - 0% of buffer1 values
   *        will be used and 100% of buffer2 values will be used, this
   *        parameter is only used when alpha is NULL
   * @param type way in which buffers will be mixed together
   * @param alpha color buffer specifying the percentage parameter for
   *        each pixel of the picture, it is only used when it's not
   *        NULL, only red channel of the specified buffer is used in
   *        a way when 0 means 0% and 255 means 100%
   */

//----------------------------------------------------------------------

void pt_mix_channels(t_color_buffer *buffer_red,
  t_color_buffer *buffer_green, t_color_buffer *buffer_blue,
  t_color_buffer *destination);

  /**<
   * Mixes red, green and blue channel from different color buffers to
   * a single color buffer. All buffers must be of the same resolution.
   *
   * @param buffer_red buffer of which the red channel will be used
   * @param buffer_green buffer of which the green channel will be used
   * @param buffer_blue buffer of which the blue channel will be used
   * @param destination buffer in which the result will be stored, it
   *        must be dealocated before this function is called and must
   *        be different from the input buffers
   */

//----------------------------------------------------------------------

void pt_replace_colors(t_color_buffer *buffer,
  unsigned char colors[][3],t_color_buffer *buffers[],
  unsigned int length);

  /**<
   * Replaces specified colors in given color buffer with content of
   * other buffers.
   *
   * @param buffer buffer in which the replacing happens
   * @param colors array of [r,g,b] colors, each color is paired with
   *        one color buffer of buffers array at the same index.
   * @param buffers array of pointers to color buffers, each one matches
   *        one color from colors array and replaces that color in the
   *        destination buffer with it's content
   * @param length length of colors and buffers arrays
   */

//----------------------------------------------------------------------

void pt_convolution(t_color_buffer *buffer, t_matrix *matrix);

  /**<
   * Performs a convolution at given buffer.
   *
   * @param buffer input (and output) buffer of convolution operation
   * @param matrix convolution matrix
   */

//----------------------------------------------------------------------

void pt_convolution_3x3(t_color_buffer *buffer, double a1, double a2,
  double a3, double b1, double b2, double b3, double c1, double c2,
  double c3);

  /**<
   * Performs a convolution at given buffer with matrix of size 3 x 3.
   *
   * @param buffer input (and output) buffer of convolution operation
   * @param a1 value at position a1 in the matrix
   * @param a2 value at position a2 in the matrix
   * @param a3 value at position a3 in the matrix
   * @param b1 value at position b1 in the matrix
   * @param b2 value at position b2 in the matrix
   * @param b3 value at position b3 in the matrix
   * @param c1 value at position c1 in the matrix
   * @param c2 value at position c2 in the matrix
   * @param c3 value at position c3 in the matrix
   */

//----------------------------------------------------------------------

void pt_voronoi_diagram(t_voronoi_type type, t_metric metric,
  t_point_place_type point_place,  unsigned int parameter1,
  unsigned int parameter2, unsigned int parameter3[][2],
  t_color_buffer *destination);

  /**<
   * Generated Voronoi diagram and stores it in a color buffer.
   *
   * @param type way in which pixel color will be computed depending
   *        on distances to given set of points
   * @param metric a way in which distance between points will be
   *        measured
   * @param point_place way in which points of Voronoi diagram will be
   *        placed
   * @param parameter1 first parameter of point placement, it's
   *        semantics is dependent on point_place parameter value as
   *        follows:
   *
   *        PLACE_RANDOM - value that will be passed to noise
   *          function (will generate different random numbers with
   *          different values),
   *
   *        PLACE_SQUARE - square width in percents of buffer width
   *
   *        PLACE_CIRCLE - circle radius in percents of buffer width
   *
   *        PLACE_CROSS_HORIZONTAL - cross side length in  percents of
   *          buffer width
   *
   *        PLACE_CROSS_DIAGONAL - cross side length in  percents of
   *          buffer width
   *
   *        PLACE_CUSTOM - length of array of points pointed to by
   *          parameter3
   *
   * @param parameter2 second parameter of point placement, it's
   *        semantics is dependent on point_place parameter value as
   *        follows:
   *
   *        PLACE_RANDOM - number of points generated
   *
   *        PLACE_SQUARE - number of points of one side of the square
   *
   *        PLACE_CIRCLE - number of points of the circle
   *
   *        PLACE_CROSS_HORIZONTAL - number of points per cross side
   *          (including the center point)
   *
   *        PLACE_CROSS_DIAGONAL - number of points per cross side
   *          (including the center point)
   *
   *        PLACE_CUSTOM - no meaning
   *
   * @param parameter3 array of point coordinations (0 ~ x, 1 ~ y), is
   *        used only with PLACE_CUSTOM value of point_place parameter
   * @param destination buffer to store the diagram to, must be already
   *        initialized
   */

//----------------------------------------------------------------------

void pt_voronoi_diagram_random(t_voronoi_type type, t_metric metric,
  int random, int points, t_color_buffer *destination);

  /**<
   * Generated Voronoi diagram with random point placement and stores
   * it in a color buffer.
   *
   * @param type way in which pixel color will be computed depending
   *        on distances to given set of points
   * @param metric a way in which distance between points will be
   *        measured
   * @param random value that will be passed to noise function,
   *        different values will generate different point placements
   * @param points number of points in the diagram
   * @param destination buffer to store the diagram to, must be already
   *        initialized
   */

//----------------------------------------------------------------------

void pt_voronoi_diagram_simple(int random, int points,
  t_color_buffer *destination);

  /**<
   * Generates Voronoi diagram using Euclidean metrics and 2 nearest
   * points ration color computation.
   *
   * @param random value that will be passed to noise function,
   *        different values will generate different point placements
   * @param points number of points in the diagram
   * @param destination buffer to store the diagram to, must be already
   *        initialized
   */

//----------------------------------------------------------------------

void pt_simple_noise(int random, unsigned char amplitude, int grayscale,
  t_color_buffer *destination);

  /**<
   * Generates a simple white noise by setting pixels of given buffer to
   * pseudo-random values.
   *
   * @param random number passed to noise function, different numbers
   *        will generate different noise results
   * @param amplitude amplitude of the noise, should be in range
   *        <0,128>
   * @param grayscale boolean parameter that says whether the output
   *        noise should be grayscale (true) or colored (false)
   * @param destination color buffer to store the result to, must be
   *        initialized before this function is called
   */

//----------------------------------------------------------------------

void pt_perlin_noise(int random, unsigned char base_amplitude,
  unsigned int base_frequency, int max_iterations,
  t_interpolation_method interpolation, t_color_buffer *destination,
  int smooth);

  /**<
   * Generates a fractal perlin noise and stores it in given color
   * buffer as an image.
   *
   * @param random number passed to noise function, different numbers
   *        will generate different noise results
   * @param base_amplitude amplitude of the base frequency, should be in
   *        range <0,128>
   * @param base_frequency base, lowest frequency of the noise
   * @param max_iterations maximum number of iterations, negative number
   *        means no limit (generating will stop when the frequency is
   *        higher than buffer resolution or when the amplitude reaches
   *        zero)
   * @param interpolation interpolation type
   * @param destination color buffer to store the result to, must be
   *        initialized before this function is called
   * @param smooth says if the noise should be smoothed so that the
   *        number of artifacts is reduced (this is takes a little more
   *        time but looks nicer)
   */

//----------------------------------------------------------------------

void pt_bump_noise(t_color_buffer *buffer, double bump_size_from,
  double bump_size_to, unsigned int bump_quantity, int alter_amplitude,
  int random);

  /**<
   * Generates a noise by putting circle bumps of decreasing size over
   * each other.
   *
   * @param buffer buffer in which the result will be stored, must be
   *        initialised
   * @param bump_size_from a number in range <0,1> which determines
   *        initial bump size in fraction of the buffer width, this
   *        is the upper limit
   * @param bump_size_to a number in range <0,1> which determines
   *        final bump size in fraction of the buffer width, this is
   *        the lower limit
   * @param bump_quantity a number that specifies how fast the bump
   *        count will grow, use value 1 for common usage
   * @param alter_amplitude says if the amplitude of the bumps will be
   *        lowered with each iteration (1) or not (0), non-altering
   *        amplitude creates a sharper image
   * @param random number that determines placement of the bumps,
   *        different values will give different results
   */

//----------------------------------------------------------------------

void pt_fault_formation_noise(int random, t_color_buffer *destination);

  /**<
   * Generates a noise using fault formation based algorithm and stores
   * the result in given color buffer as an image.
   *
   * @param random number passed to noise function, different numbers
   *        will generate different noise results
   * @param destination color buffer to store the result to, must be
   *        initialized before this function is called
   */

//----------------------------------------------------------------------

void pt_substrate(int random, int iterate, unsigned int number,
  t_fill_type fill_type, int fill_grayscale,
  t_color_buffer *destination);

  /**<
   * Generates black and white image using substrate algorithm. Areas
   * may be randomly filled either in grayscale or with full color
   * range.
   *
   * @param random value passed to noise function, different values
   *        generate different images
   * @param iterate says whether to use iterations or not
   * @param number semantics of this parameter depends on value of
   *        iterate parameter, if it is true, this parameter says how
   *        many iterations there will be, if it is false, this
   *        parameter says how many lines there will be
   * @param fill_type way in which areas of the picture will be filled
   * @param fill_grayscale this parameter is only used when fill_type
   *        is not set to FILL_NONE, then if this parameters is true,
   *        the fill colors will only be gryscale, otherwise different
   *        RGB values will be generated
   * @param destination color buffer in which the generated result will
   *        be stored, must be initialized before this function is
   *        called
   */

//----------------------------------------------------------------------

void pt_substrate_simple(int random, int iterations, int fill,
  t_color_buffer *destination);

  /**<
   * Generated substrate algorithm image.
   *
   * @param random value passed to noise function, different values
   *        generate different images
   * @param iterations number of iterations
   * @param fill if true, the image will be filled with random colors,
   *        otherwise it won't be filled
   * @param destination color buffer in which the result will be stored
   */

//----------------------------------------------------------------------

void pt_mosaic_square(t_color_buffer *destination,
  t_fill_type fill_type, unsigned char fill_colors[],
  unsigned char number_of_colors, t_square_mosaic *mosaic);

  /**<
   * Creates an mosaic image based on square grid.
   *
   * @param destination color buffer in which the result will be stored,
   *        should be already initialised
   * @param fill_type says how the tiles will be filled with color
   * @param fill_colors array of grayscale values with which the tiles
   *        will be colored, the colors are assigned to tiles in left to
   *        right, top to bottom order, if this parameter is NULL, all
   *        tiles will be filled with white color, if there is more
   *        tiles than colors specified, the colors will be assigned
   *        cyclically
   * @param number_of_colors length of fill_colors array
   * @param mosaic mosaic specification, if it's not valid, no mosaic
   *        will be generated (validity can be checked with special
   *        functions)
   */

//----------------------------------------------------------------------

void pt_cellular_automaton_rps(t_color_buffer *buffer,
  t_neighbourhood_type neighbourhood, unsigned int neighbourhood_size,
  unsigned char number_of_players, int random, unsigned int iterations);

  /**<
   * Generates an image using general rock paper scissors cellular
   * automaton.
   *
   * @param buffer input and output buffer of the operation, it should
   *        contain the initial state as a grayscale image (image will
   *        be converted to grayscale anyway), threshold operation
   *        will be performed with the buffer to get desired number of
   *        states
   * @param neighbourhood neighbourhood used
   * @param neighbourhood_size neighbourhood size
   * @param number_of_players number of players for the rock paper
   *        scissors game, this should be an odd number, the automaton
   *        will have number_of_players + 1 states (blank space is the
   *        extra state), maximum allowed value is 25
   * @param random random number passed to the noise function,
   *        different numbers will give different results
   * @param iterations number of iterations
   */

//----------------------------------------------------------------------

void pt_cellular_automaton_cyclic(t_color_buffer *buffer,
  t_neighbourhood_type neighbourhood, unsigned int neighbourhood_size,
  unsigned char states, unsigned int threshold, unsigned int iterations);

  /**<
   * Generates an image using cyclic cellular automaton.
   *
   * @param buffer input and output buffer of the operation, it should
   *        contain the initial state as a grayscale image (image will
   *        be converted to grayscale anyway), threshold operation
   *        will be performed with the buffer to get desired number of
   *        states
   * @param neighbourhood neighbourhood used
   * @param neighbourhood_size neighbourhood size
   * @param states number of states of the automaton, i.e. the period
   *        of the cycle
   * @param threshold minimum number of cells with the next cycle color
   *        in cell's neighbourhood for it to be promoted to the next
   *        color
   * @param iterations number of iterations
   */

//----------------------------------------------------------------------

void pt_cellular_automaton_general(t_color_buffer *buffer,
  unsigned char states, int rules[256], unsigned int iterations);

  /**<
   * Generates an image using general binary cellular automaton with
   * Moore neighbourhood. All possible binary rules for Moore
   * neighbourhood can be specified, the automaton however may not only
   * be binary. Other cell states are achieved with so called history -
   * if a cell would die, it only gets older (advances to the next
   * state), old cells can not give birth to new cells
   *
   * @param buffer input and output buffer of the operation, it should
   *        contain the initial state as a grayscale image (image will
   *        be converted to grayscale anyway), threshold operation
   *        will be performed with the buffer to get desired number of
   *        states
   * @param states number of states of the automaton
   * @param rules array of rules where each index represents one of all
   *        possible states of given cell's neighbourhood, the indice's
   *        number is considered a binary representation of the cell's
   *        neighbour cell values in order NW, N, NE, E, SE, S, SW, W,
   *        the value stored on index can be:
   *        1 (or any positive) - the cell is born
   *        0 - nothing happens to the cell
   *        -1 (or any negative) - the cell dies
   * @param iterations number of iterations
   */

//----------------------------------------------------------------------

void pt_marble(int random, unsigned int periods, unsigned int intensity,
  t_direction direction, unsigned int amplitude,
  t_color_buffer *destination, t_color_buffer *noise_source);

  /**<
   * Generates marble-like structure into given color buffer.
   *
   * @param random value passed to noise function, different values
   *        generate different images
   * @param periods number of periods that will be used for initial
   *        color transition used for generating the structure
   * @param intensity intensity of the effect
   * @param direction direction in which the initial transition will be
   *        generated
   * @param amplitude amplitude of the picture, must be less or equal to
   *        127
   * @param destination color buffer in which the result will be stored,
   *        must be initialised before this function is called
   * @param noise_source external source of the noise, it may be NULL in
   *        which case perlin noise will be generated and used, if this
   *        parameter is used, the noise color buffer must be of the
   *        same size as destination
   */

//----------------------------------------------------------------------

void pt_wood(int random, unsigned int circles, unsigned int hardness,
  unsigned int intensity, t_direction direction, unsigned int amplitude,
  t_color_buffer *destination, t_color_buffer *noise_source);

  /**<
   * Generates wood-like structure into given color buffer.
   *
   * @param random value passed to noise function, different values
   *        generate different images
   * @param circles number of circles of the basic shape being modulated
   * @param hardness higher values result in more intense edges
   * @param intensity intensity of the effect
   * @param direction direction in which the modulation will be applied
   * @param amplitude amplitude of the picture, must be less or equal to
   *        127
   * @param destination color buffer in which the result will be stored,
   *        must be initiated before this function is called
   * @param noise_source external source of the noise, it may be NULL in
   *        which case perlin noise will be generated and used, if this
   *        parameter is used, the noise color buffer must be of the
   *        same size as destination
   */

//----------------------------------------------------------------------

void pt_marble_simple(int random, unsigned int intensity,
  unsigned int amplitude, t_color_buffer *destination);

  /**<
   * Generates marble-like structure using Perlin noise, horizontal
   * direction and 4 periods.
   *
   * @param random value passed to noise function, different values
   *        generate different images
   * @param intensity intensity of the effect
   * @param amplitude amplitude of the picture, must be less or equal to
   *        127
   * @param destination color buffer in which the result will be stored,
   *        musr be initiated before this function is called
   */

//----------------------------------------------------------------------

void pt_wood_simple(int random, unsigned int intensity,
  unsigned int amplitude, t_color_buffer *destination);

  /**<
   * Generates wood-like structure using Perlin noise, horizontal
   * direction and 5 circles.
   *
   * @param random value passed to noise function, different values
   *        generate different images
   * @param intensity intensity of the effect
   * @param amplitude amplitude of the picture, must be less or equal to
   *        127
   * @param destination color buffer in which the result will be stored,
   *        musr be initiated before this function is called
   */

//----------------------------------------------------------------------

void pt_particle_movement(t_color_buffer *noise_buffer,
  unsigned int particles, double position_x, double position_y,
  unsigned int angle, unsigned int spread, double velocity,
  t_color_buffer *destination);

  /**<
   * Creates an grayscale image of moving particles.
   *
   * @param noise grayscale image that serves as a mosulation for the
   *        random particle movement, this should be some kind of perlin
   *        (or other) noise, this buffer's resolution determines the
   *        result image resolution
   * @param particles number of particles
   * @param position_x initial x position of the source in range <0,1>
   * @param position_y initial y position of the source in range <0,1>
   * @param angle initial angle of the particles in degrees (starting
   *        poiting to right)
   * @param spread angle difference in degrees from initial angle within
   *        which the particles will be fired (so 360 means all
   *        directions)
   * @param velocity initial velocity of each particle in percents of
   *        the noise_buffer width
   * @param destination in this variable the result image will be
   *        returned, it should be deallocated before this function is
   *        called
   */

//----------------------------------------------------------------------

void pt_particle_movement_color(t_color_buffer *noise_buffer,
  unsigned int particles, double position_x, double position_y,
  unsigned int angle, unsigned int spread, double velocity,
  t_color_buffer *destination, unsigned char red, unsigned char green,
  unsigned char blue);

  /**<
   * Creates an colored image of moving particles.
   *
   * @param noise grayscale image that serves as a mosulation for the
   *        random particle movement, this should be some kind of perlin
   *        (or other) noise, this buffer's resolution determines the
   *        result image resolution
   * @param particles number of particles
   * @param position_x initial x position of the source in range <0,1>
   * @param position_y initial y position of the source in range <0,1>
   * @param angle initial angle of the particles in degrees (starting
   *        poiting to right)
   * @param spread angle difference in degrees from initial angle within
   *        which the particles will be fired (so 360 means all
   *        directions)
   * @param velocity initial velocity of each particle in percents of
   *        the noise_buffer width
   * @param destination in this variable the result image will be
   *        returned, it should be deallocated before this function is
   *        called
   * @param red amount of red color of the particles
   * @param green amount of green color of the particles
   * @param blue amount of blue color of the particles
   */

//----------------------------------------------------------------------

void pt_particles_simple(unsigned int particles, unsigned int sources,
  double velocity, unsigned char red, unsigned char green,
  unsigned char blue, t_color_buffer *destination, int random);

  /**<
   * Using quite simple interface generates colored particle movement
   * image with given number of particle sources. Uses perlin noise
   * and random placement of the sources, particles spread in all
   * directions.
   *
   * @param particles number of particles at each source
   * @param sources number of sources
   * @param velocity initial velocity of each particle
   * @param red amount of red in the particle color
   * @param green amount of green in the particle color
   * @param blue amount of blue in the particle color
   * @param destination buffer in which the result will be stored, must
   *        be already initialised
   * @param random number affecting random actions during calculations
   */

//----------------------------------------------------------------------

void pt_turtle_draw(t_color_buffer *buffer, t_grammar *grammar,
  double start_x, double start_y, int start_angle,
  double noise_intensity, double particle_density);

  /**<
   * Draws given L-System with turtle graphics into given buffer.
   *
   * @param buffer buffer in which the image will be drawn, it must be
   *        initialised
   * @param grammar grammar with generated string that will be grawn,
   *        for the string semantics see documentation
   * @param start_x initial x position of the turtle in range <0,1>
   * @param start_y initial y position of the turtle in range <0,1>
   * @param start_angle initial angle of the turtle in degrees
   * @param noise_intensity affects drawing of particles, says how much
   *        their velocity is affected by the noise, this should be in
   *        range <0,1> (the less, the straighter particle lines)
   * @param says how many particles there will be when particle lines
   *        are drawn, this should be in range <0,1> (bigger value means
   *        more particles)
   */

//----------------------------------------------------------------------

int pt_turtle_get_point_list(t_color_buffer *buffer, t_grammar *grammar,
  double start_x, double start_y, int start_angle,
  unsigned int list[][2], unsigned int *length,
  unsigned int max_length);

  /**<
   * Creates a list of points that the turtle would travel if it was to
   * draw an L-System based on given grammar.
   *
   * @param buffer buffer that the turtle would draw into, it is only
   *        needed for some information and the data in the buffer will
   *        not be changed
   * @param grammar grammar with generated string that will navigate the
   *        turtle
   * @param start_x initial x position of the turtle in range <0,1>
   * @param start_y initial y position of the turtle in range <0,1>
   * @param start_angle initial angle of the turtle in degrees
   * @param list in this two-dimensional array the list of points will
   *        be returned in format [point number][x and y points]
   * @param length in this variable the length of list will be returned
   * @param max_length maximum allowed length of the list
   */

//----------------------------------------------------------------------

void pt_transformation_circle(t_color_buffer *buffer, int radius,
  unsigned int repeat, t_color_buffer *destination);

  /**<
   * Makes a circle transformation with given color buffer. This
   * transformation computes output color of each pixel by taking
   * pixel at current position of the source buffer, transforming it's
   * color intensity to angle in which direction it jumps by given
   * length. This can be performed multiple times. Pixel color of the
   * pixel we get to this way is the color that will be set at current
   * position of the destination buffer.
   *
   * @param buffer source buffer for transformation, average values of
   *        RGB of each pixel is used as angle
   * @param radius length of the jump in percents of buffer width
   * @param repeat number of times the jump is performed
   * @param destination destination buffer in which the result will be
   *        stored, must be dealocated before this function is called
   */

//----------------------------------------------------------------------

void pt_transformation_radius(t_color_buffer *buffer,
  unsigned int radius_min, unsigned int radius_max, int rotate_left,
  int go_horizontal, t_color_buffer *destination);

  /**<
   * Makes a radius transformation which takes pixels from top left to
   * bottom right corner of the image and with each pixel it performs
   * special operation. This operation consists of converting the pixel
   * value to radius length and moving in an angle by this length. The
   * angle starts at zero and rotates as the position in the buffer
   * changes. Average value of each pixel's RGB is used.
   *
   * @param buffer input buffer of the operation
   * @param radius_min minimum length of the radius that will be used
   *        when the pixel value is 0
   * @param radius_max maximum length of the radius that will be used
   *        when the pixel value is 255
   * @param rotate_left if true, the angle will rotate left, otherwise
   *        right
   * @param go_horizontal if true, the angle will change with horizontal
   *        movement, otherwise vertical
   * @param destination output buffer of the operation, must be
   *        deallocated
   */

//----------------------------------------------------------------------

void pt_transformation_sine(t_color_buffer *buffer, double phase,
  int periods, unsigned char amplitude, t_color_buffer *destination);

  /**<
   * Makes a sine transformation applying sinus function to every
   * pixel of the input buffer. Average value of each pixel's RGB is
   * used.
   *
   * @param buffer input buffer of the transformation
   * @param phase starting phase of the sinus function in radians
   * @param periods number od sinus periods that will be mapped to
   *        0 - 255 range (possible pixel values)
   * @param amplitude amplitude of the function, should be in range
   *        0 - 255
   * @param destination color buffer to store the result to, must be
   *        dealocated before this function is called
   */

//----------------------------------------------------------------------

void pt_blur(t_color_buffer *buffer, unsigned int intensity);

  /**<
   * Blurs image stored in color buffer. Using this function is slightly
   * faster than using convolution to blur the image.
   *
   * @param buffer buffer with image to be blured
   * @param intensity intensity of blur
   */

//----------------------------------------------------------------------

void pt_motion_blur(t_color_buffer *buffer, t_direction direction,
  unsigned int intensity);

  /**<
   * Blurs image in given direction and with specified intensity.
   *
   * @param buffer buffer with image to be blured
   * @param direction direction in which the image will be blured
   * @param intensity intensity of the effect
   */

//----------------------------------------------------------------------

void pt_sharpen(t_color_buffer *buffer, unsigned int intensity);

  /**<
   * Sharpens image in given color buffer.
   *
   * @param buffer input and output buffer of the operation
   * @param intensity intensity of the sharpen effect
   */

//----------------------------------------------------------------------

void pt_emboss(t_color_buffer *buffer, unsigned int intensity);

  /**<
   * Performs emboss effect with given color buffer.
   *
   * @param buffer input and output buffer of the operation
   * @param intensity of the effect
   */

//----------------------------------------------------------------------

void pt_edge_detection(t_color_buffer *buffer,
  t_edge_detection_type type, int intensity);

  /**<
   * Performs an edge detection operation with given buffer and
   * intensity using convolution filters.
   *
   * @param buffer input (and output) buffer of the operation
   * @param type type of edge detection
   * @param intensity intensity of the operation, should be in interval
   *        <1,10>
   */

//----------------------------------------------------------------------

void pt_invert_colors(t_color_buffer *buffer);

  /**<
   * Inverts color in given color buffer.
   *
   * @param buffer input (and output) buffer
   */

//----------------------------------------------------------------------

void pt_dithering(t_color_buffer *buffer, unsigned char levels,
  t_dithering_method method);

  /**
   * Performs dithering with given image.
   *
   * @param buffer input and output color buffer of the operation,
   *        dithering is applied to all channels separately
   * @param levels number of values each pixel can have in one channel
   * @param method dithering method to use
   */

//----------------------------------------------------------------------

void pt_crop_amplitude(t_color_buffer *buffer,
  unsigned char lower_limit, unsigned char upper_limit);

  /**<
   * Crops the amplitude of given grayscale image so it fits given limit
   * values. Any value above upper or below lower limit will be
   * restricted to this value.
   *
   * @param buffer buffer to perform the operation with, should contain
   *        grayscale image
   * @param lower_limit lower limit of the crop
   * @param upper_limit upper limit of the crop
   */

//----------------------------------------------------------------------

void pt_normal_map(t_color_buffer *buffer, unsigned int
  neighbourhood_size, t_color_buffer *destination);

  /**<
   * The function considers the input buffer as a grayscale heightmap
   * and creates it's normal map.
   *
   * @param buffer input buffer, grayscale heightmap
   * @param neighbourhood_size number of pixels that are considered
   *        pixel's neighbours, minimum is 1, lower value is more
   *        accurate, higher value is smoother
   * @param destination in this buffer the normal map will be stored,
   *   this buffer must be deallocated before this function is called
   */

//----------------------------------------------------------------------

void pt_light(t_color_buffer *normal_map, t_color_buffer *destination,
  unsigned char ambient_r, unsigned char ambient_g,
  unsigned char ambient_b, unsigned char diffuse_r,
  unsigned char diffuse_g, unsigned char diffuse_b,
  unsigned char specular_r, unsigned char specular_g,
  unsigned char specular_b, double phong_exponent,
  t_reflection_curve reflection_curve, double viewer_z,
  double light_vector_x, double light_vector_y);

  /**<
   * Based on provided normal map computes the intensity of each pixel
   * when illuminated by specified light source and with given viewer
   * position. The intensity map is stored as an RGB image, when for
   * each element 255 is the maximum value and 0 is the minimum value.
   *
   * @param normal_map buffer in which the normalised normal map is
   *        stored
   * @param destination in this buffer the final intensity map will be
   *        stored, it must be deallocated before this function is
   *        called
   * @param ambient_r amount of red intensity for the ambient light
   * @param ambient_g amount of green intensity for the ambient light
   * @param ambient_b amount of blue intensity for the ambient light
   * @param diffuse_r amount of red intensity for the diffuse light
   * @param diffuse_g amount of green intensity for the diffuse light
   * @param diffuse_b amount of blue intensity for the diffuse light
   * @param specular_r amount of red intensity for the specular light
   * @param specular_g amount of green intensity for the specular light
   * @param specular_b amount of blue intensity for the specular light
   * @param phong_exponent affects the smoothness of the surface by
   *        raising the reflection curve to the power of this parameter
   * @param reflection_curve specifies how specular reflections will
   *        look
   * @param viewer_z z position of the viewer, where 1 is equal to the
   *        image width, x and y positions are considered in the middle
   *        of the image
   * @param light_vector_x x element of the light vector pointing down
   *        towards the image (the z element is considered 1.0)
   * @param light_vector_y y element of the light vector pointing down
   *        towards the image (the z element is considered 1.0)
   */

//----------------------------------------------------------------------

void pt_light_simple(t_color_buffer *normal_map,
  t_color_buffer *destination, unsigned char red, unsigned char green,
  unsigned char blue);

  /**<
   * Based on provided normal map computes the intensity of each pixel
   * when illuminated by specified light source. This function is
   * provides a simplified interface compared to the original one.
   *
   * @param normal_map buffer in which the normalised normal map is
   *        stored
   * @param destination in this buffer the final intensity map will be
   *        stored, it must be deallocated before this function is
   *        called
   * @param red amount of red in the light
   * @param green amount of green in the light
   * @param blue amount of blue in the light
   */

//----------------------------------------------------------------------

void pt_glass(t_color_buffer *normal_map, t_color_buffer *buffer,
  t_color_buffer *destination, double height);

  /**<
   * Creates a glass like distortion effects of given image accoording
   * to given normal map, which is placed above the image like a glass
   * and changes the path of light depending on the normal directions.
   *
   * @param normal_map normal map that serves as a glass that the buffer
   *        image is viewed through
   * @param buffer image that the effect will be applied on, it should
   *        be the same size as the normal map
   * @param destination in this buffer the final image will be stored,
   *        it must be deallocated before this function is called
   * @param height height in percents of the image width at which the
   *        glass (the normal map) will be placed above the image, the
   *        further the distance, the more intense the effect will be
   */

//----------------------------------------------------------------------

void pt_grayscale(t_color_buffer *buffer);

  /**<
   * Converts given image to grayscale.
   *
   * @param buffer buffer with image to be converted to grayscale
   */

//----------------------------------------------------------------------

void pt_map_to_transition(t_color_buffer *buffer,
  t_color_transition *transition);

  /**<
   * Maps given grayscale image to a color transition so it becomes
   * colored. Only red channel of given buffer is being counted with as
   * it is supposed that all channels have same values because the image
   * should be grayscale.
   *
   * @param buffer buffer with image which the transition will be
   *        applied on
   * @param transition transition to be mapped to image
   */

//----------------------------------------------------------------------

#endif
