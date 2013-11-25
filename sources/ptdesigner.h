#ifndef PTDESIGNER_H
#define PTDESIGNER_H

//**********************************************************************
/** @file
 * Header file providing procedural textures designer interface. It
 * allows the programmer to create textures by describing it as a graph
 * of nodes (blocks), of which each represents basic operations for
 * creating textures.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include "colorbuffer.h"
#include "colortransition.h"
#include "matrix.h"
#include "grammar.h"
#include "proctextures.h"
#include "general.h"

                                   /** basic transformation types */
typedef enum
  {
    BASIC_TRANSFORMATION_SHIFT,
    BASIC_TRANSFORMATION_ROTATE
  } t_basic_transformation;

                                  /** list of [x,y] points */
typedef struct
  {
    unsigned int *points[2];
    unsigned int length;
  } t_point_list;
                                  /**  possible block types */
typedef enum
  {
    BLOCK_SAVE_FILE,              /**< Saves the image in file.
                                       Parameters:

                                       (special) path - file path
                                  */
    BLOCK_LOAD_FILE,              /**< Loads the image from file.
                                       Parameters:

                                       (special) path - file path
                                  */
    BLOCK_COLOR,                  /**< Creates an image filled with
                                       constant color. Parameters:

                                       (int) color - color to fill the
                                         image with
                                   */
    BLOCK_PERLIN_NOISE,           /**< Generates a Perlin noise.
                                       Parameters:

                                       (int) amplitude - base amplitude
                                       (int) frequency - base frequency
                                       (int) iterations - maximum number
                                         of iterations, -1 means no
                                         limit
                                       (int) interpolation -
                                         interpolation method
                                       (int) general[0] - whether or not
                                         to smooth the noise
                                  */
    BLOCK_SIMPLE_NOISE,           /**< Generates a simple white noise.
                                       Parameters:

                                       (general[0]) - whether the noise
                                         should be grayscale (1) or
                                         colored (0)
                                  */
    BLOCK_BUMP_NOISE,             /**< Generates a bump noise.
                                       Parameters:


                                  */
    BLOCK_FAULT_FORMATION_NOISE,
    BLOCK_VORONOI,                /**< Generates a Voronoi diagram.
                                       Parameters:

                                       (int) voronoi_type - type
                                       (int) metric - metric used
                                       (int) point_place - how to place
                                             points
                                       (special) point_list - optional
                                         custom point placement
                                  */
    BLOCK_SUBSTRATE,              /**< Generates an image using
                                       Substrate algorithm. Parameters:
                                  */
    BLOCK_MIX,                    /**< Mixes two buffers together.
                                       Parameters:
                                  */
    BLOCK_MIX_CHANNELS,           /**< Creates an image by mixing 3
                                       RGB Channels from 3 images
                                       (different or not). Parameters:
                                  */
    BLOCK_BASIC_TRANSFORMATION,   /**< Performs a basic transformation
                                       (shift, rotation, ...) with the
                                       image. Parameters:
                                  */
    BLOCK_MULTIPLY_VALUE,         /**< Multiplies the image by given
                                       value. Parameters:
                                  */
    BLOCK_ADJUST_RGB,             /**< Adjusts the RGB components of the
                                       image. Parameters:
                                  */
    BLOCK_ADJUST_HSL,             /**< Adjusts the HSL components of the
                                       image. Parameters:
                                  */
    BLOCK_CONVOLUTION,            /**< Performs a convolution with the
                                       image. Parameters:
                                  */
    BLOCK_EDGE_DETECTION,         /**< Performs an edge detection with
                                       the image. Parameters:
                                  */
    BLOCK_SHARPEN,                /**< Sharpens the image. Parameters:
                                  */
    BLOCK_BLUR,                   /**< Blurs the image, either in all
                                       directions or in one given
                                       direction (motion blur).
                                       Parameters:
                                  */
    BLOCK_GLASS,                  /**< Applies a glass-blur effect to
                                       the image. Parameters:
                                  */
    BLOCK_EMBOSS,                 /**< Applies the emboss effect to the
                                       image. Parameters:
                                  */
    BLOCK_TRANSFORMATION_CIRCLE,  /**< Performs a circle transformation
                                       with the grayscale image.
                                       Parameters:
                                  */
    BLOCK_TRANSFORMATION_RADIUS,  /**< Performs a radius transformation
                                       with the grayscale image.
                                       Parameters:
                                  */
    BLOCK_DITHERING,              /**< Decreases the number of colors in
                                       the image using dithering.
                                       Parameters:
                                  */
    BLOCK_TURTLE_GRAPHICS,        /**< Uses turtle graphics to draw an
                                       L-system. Parameters:
                                  */
    BLOCK_SQUARE_MOSAIC,          /**< Generates an mosaic image.
                                       Parameters:
                                  */
    BLOCK_REPLACE_COLORS,         /**< Replaces specific colors in the
                                       image with content of other
                                       images. Parameters:
                                  */
    BLOCK_COLOR_TRANSITION        /**< Maps a grayscale image to color
                                       transition. Parameters:
                                  */
  } t_block_type;

                                         /** Integer block parameters.
                                             */
typedef struct
  {
    t_voronoi_type voronoi_type;         ///< voronoi diagram type
    t_metric metric;                     ///< way of measuring disatnces
    t_point_place_type point_place;      ///< way of placing points
    t_direction direction;               ///< direction
    t_mix_type mix_type;                 ///< way of mixing buffers
    t_basic_transformation transform;    ///< transformation type
    t_reflection_curve reflection_curve; ///< reflection curve
    t_fill_type fill_type;               ///< way of color filling
    t_dithering_method dithering_method; ///< dithering method
    t_edge_detection_type edge_detection;///< edge detection type
    t_neighbourhood_type neighbourhood;  ///< neighbourhood type
    t_interpolation_method interpolation;///< interpolation method
    unsigned char amplitude;             ///< amplitude
    unsigned int frequency;              ///< frequency
    unsigned int spread;                 ///< spread
    unsigned char color[3];              ///< color 1 (r,g,b)
    unsigned char color2[3];             ///< color 2 (r,g,b)
    unsigned char color3[3];             ///< color 3 (r,g,b)
    unsigned char levels;                ///< number of levels
    unsigned char neighbourhood_size;    ///< neighbourhood size
    unsigned int intensity;              ///< intensity
    int iterations;                      ///< number of iterations
    int radius;                          ///< radius in pixels
    int count_x;                         ///< x direction count
    int count_y;                         ///< y direction count
    int general[5];                      ///< general integer parameters
  } t_int_parameters;
                                         /** Floating point block
                                             parameters. */
typedef struct
  {
    double angle;              ///< angle in degrees
    double phase;              ///< phase in degrees
    double shift_x;            ///< x shift in range <0,1>
    double shift_y;            ///< y shift in range <0,1>
    double start_x;            ///< initial x position in range <0,1>
    double start_y;            ///< initial y position in range <0,1>
    double intensity;          ///< intensity in range <0,1>
    double density;            ///< density in range <0,1>
    double ratio;              ///< ratio in range <0,1>
    double velocity;           ///< velocity
    double hue;                ///< amount of hue in range <-1,1>
    double saturation;         ///< amount of saturation in range <-1,1>
    double lightness;          ///< amount of lightness in range <-1,1>
    double brightness;         ///< amount of brightness in range <-1,1>
    double contrast;           ///< amount of contrast in range <-1,1>
    double general[5];         ///< general floating point parameters
  } t_fp_parameters;
                                         /** Special parameters passed
                                             as pointers. */
typedef struct
  {
    t_grammar *grammar;                 ///< grammar
    t_color_transition *transition;     ///< color transition
    t_square_mosaic *mosaic;            ///< mosaic specification
    char *path;                         ///< file path
    t_matrix *matrix;                   ///< matrix
    t_point_list point_list;            ///< list of [x,y] coordinations
    void *pointerf[5];                  ///< general pointer parameters
  } t_special_parameters;

                                         /** Block - node of the texture
                                             description graph. */
typedef struct s_block
  {
    t_block_type type;                   ///< block type
    t_int_parameters int_params;         ///< integer parameters
    t_fp_parameters fp_params;           ///< floating point parameters
    t_special_parameters special_params; ///< special parameters
    t_color_buffer buffer;               ///< image stored in the block
    int error;                           ///< says if there was an error
    int valid;                           ///< whether the image is valid
    struct s_block *inputs[5];           ///< input blocks
  } t_block;

                                   //   global information:
unsigned int texture_resolution_x; ///< texture x resolution (final)
unsigned int texture_resolution_y; ///< texture y resolution (final)
unsigned int supersampling;        ///< level of supersampling
int global_random_seed;            ///< global random seed

//----------------------------------------------------------------------

void designer_init();

  /**
   * Initialises the procedural texture designer module.
   */

//----------------------------------------------------------------------

void designer_set_resolution(unsigned int x, unsigned int y);

  /**<
   * Sets the global information about texture resolution which all
   * blocks will respect when generating outputs. This function must be
   * called before any other function of this header file is called.
   *
   * @param x x resolution of the texture
   * @param y y resolution of the texture
   */

//----------------------------------------------------------------------

void designer_set_supersampling(unsigned int level);

  /**
   * Sets the global supersampling level. The blocks will generate
   * images in appropriate resolution and the save blocks will resize
   * the image down making it smoother.
   *
   * @param level supersampling level, 1 means no supersampling
   */

//----------------------------------------------------------------------

void designer_set_random_seed(int seed);

  /**
   * Sets the global random seed. This number affects random actions and
   * changing it will result in slightly different images generated.
   *
   * @param seed seed to be set
   */

//----------------------------------------------------------------------

void designer_get_global_information(unsigned int *resolution_x,
  unsigned int *resolution_y, unsigned int *supersampling,
  int *random_seed);

  /**
   * Gets the texture designer global information.
   *
   * @param resolution_x in this variable global x resolution of the
   *        texture will be returned
   * @param resolution_y in this variable global y resolution of the
   *        texture will be returned
   * @param supersampling in this variable global level of supersampling
   *        will be returned
   * @param random_seed in this variable global random seed will be
   *        returned
   */

//----------------------------------------------------------------------

void block_init(t_block *block, t_block_type type);

  /**<
   * Initialises a new block. It's parameters will be set to default
   * values.
   *
   * @param block block to be initialised
   * @param type type of the block
   */

//----------------------------------------------------------------------

void block_connect_input(t_block *block, unsigned int input_number,
  t_block *input);

  /**<
   * Connect given block to another block's input slot.
   *
   * @param block block to which the other block will be connected as an
   *        input
   * @param input number number of the input slot, must be in range
   *        <0,2>
   * @param input block which will be connected to the other's block as
   *        an input
   */

//----------------------------------------------------------------------

void block_compute(t_block *block);

  /**<
   * Computes given block output by recursively computing all of it's
   * inputs if necessary and performing the block's operation with the
   * input. The result image will be stored in the block's color buffer.
   *
   * @param block block to be executed
   */

//----------------------------------------------------------------------

void invalidate_block(t_block *block);

  /**<
   * Invalidates specified block so it's forced to recompute it's output
   * the next time even if it wasn't necessary.
   *
   * @param block block to be invalidated
   */

//----------------------------------------------------------------------

void block_destroy(t_block *block);

  /**<
   * Destroys given block, but not it's inputs. This function does not
   * free special parameters (for example color transition object)
   * referenced by this block.
   *
   * @param block block to be destroyed.
   */

//----------------------------------------------------------------------

void block_destroy_tree(t_block *block);

  /**<
   * Destroys given block and it's whole input block recursively. This
   * function does not free special parameters (for example color
   * transition objects) referenced by the blocks.
   *
   * @param block root of the block tree to be destroyed.
   */

//----------------------------------------------------------------------

#endif
