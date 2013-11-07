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
#include "general.h"

typedef enum                       /** possible block types */
  {
    BLOCK_COLOR,
    BLOCK_PERLIN_NOISE,
    BLOCK_SIMPLE_NOISE,
    BLOCK_FAULT_FORMATION_NOISE,
    BLOCK_VORONOI_DIAGRAM,
    BLOCK_SUBSTRATE,
    BLOCK_MIX,
    BLOCK_MIX_CHANNELS,
    BLOCK_SHIFT,
    BLOCK_ROTATE,
    BLOCK_FLIP,
    BLOCK_MULTIPLY_VALUE,
    BLOCK_ADJUST_RGB,
    BLOCK_ADJUST_HSL,
    BLOCK_LOAD_FILE,
    BLOCK_CONVOLUTION,
    BLOCK_EDGE_DETECTION,
    BLOCK_SHARPEN,
    BLOCK_BLUR,
    BLOCK_MOTION_BLUR,
    BLOCK_EMBOSS,
    BLOCK_TRANSFORMATION_CIRCLE,
    BLOCK_THRESHOLD,
    BLOCK_TRANSITION
  } t_block_type;

                                   ///< aliases for parameter numbers
#define PARAMETER_METRIC       1   ///< metric
#define PARAMETER_ANGLE            ///< angle (rotation, ...)
#define PARAMETER_RANDOM       9   ///< value passed to noise function
#define PARAMETER_SHIFT_X          ///< x axis shift in pixels
#define PARAMETER_SHIFT_Y          ///< y axis shift in pixels
#define PARAMETER_RED              ///< amount of red color
#define PARAMETER_GREEN            ///< amount of green color
#define PARAMETER_BLUE             ///< amount of blue color
#define PARAMETER_AMPLITUDE        ///< amplitude
#define PARAMETER_VORONOI_TYPE     ///< type of Voronoi diagram
#define PARAMETER_INTENSITY        ///< intensity of an effect
#define PARAMETER_MIX_TYPE         ///< type of mixing buffers
#define PARAMETER_DIRECTION        ///< direction (blur, flip, ...)
#define PARAMETER_TRANSITION   0   ///< pointer to color transition
#define PARAMETER_MATRIX       1   ///< pointer to convolution matrix

                                   /** a block - node of the graph */
typedef struct
  {
    t_block_type type;
    int int_parameters[10];        ///< integer parameters
    double fp_parameters[10];      ///< floating point parameters
    void *special_parameters[10];  ///< special parameters as pointers
    t_color_buffer buffer;         ///< image stored in the block
    int valid;                     ///< whether the image is valid
    t_block *inputs[3];            ///< input blocks
  } t_block;

unsigned int texture_resolution_x;     // texture x resolution
unsigned int texture_resolution_y;     // texture y resolution

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
   * Computes given block output by computing all it's outputs if needed
   * and performing the block's operation with the outputs. The resulted
   * image will be stored in the block's color buffer.
   *
   * @param block block to be executed
   */

//----------------------------------------------------------------------

void invalidate_block(t_block *block);

  /**<
   * Invalidates specified block so it will be forced to recompute it's
   * output the next time even if it wasn't necessary.
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
   * Destroys given block and it's whole input subtree of blocks. This
   * function does not free special parameters (for example color
   * transition objects) referenced by the blocks.
   *
   * @param block root of the block tree to be destroyed.
   */

//----------------------------------------------------------------------

#endif
