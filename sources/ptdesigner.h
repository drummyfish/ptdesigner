#ifndef PTDESIGNER_H
#define PTDESIGNER_H

//**********************************************************************
/** @file
 * Header file providing procedural textures designer C++ interface. It
 * allows the programmer to create textures by describing it as a graph
 * of nodes (blocks), of which each represents basic operations for
 * creating textures.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

extern "C"
{
#include "colorbuffer.h"
#include "colortransition.h"
#include "matrix.h"
#include "grammar.h"
#include "proctextures.h"
#include "general.h"
}

#include <iostream>
#include <vector>
#include <string>

#define MAX_INPUT_BLOCKS 5  /// maximum number of input blocks

using namespace std;

namespace pt_design
{

class c_texture_graph;      // forward declaration

//----------------------------------------------------------------------

 /**
  * Represents a general texture designer block, which is a node of
  * texture describing graph.
  */

class c_block
  {
    protected:
      int position_x;    /// for GUI systems to store position
      int position_y;    /// for GUI systems to store position
      unsigned int id;   /// block id
      bool valid;               /// whether the block is currently valid
      bool error;               /// whether there was any error
      c_block *input_blocks[MAX_INPUT_BLOCKS]; /// input blocks
      unsigned int inputs;      /// current number of inputs
      unsigned int max_inputs;  /// maximum number of inputs
      unsigned int min_inputs;  /// minimum number of inputs

      void set_error();

        /**<
         * Sets the error flag and invalidates the block.
         */

    public:
      c_block(c_texture_graph *texture_graph);

        /**<
         * Class constructor, initialises a new block. The block will
         * set its parameters depending on the graph settings.
         *
         * @param texture_graph texture graph that this block will
         *        belong to, cannot be NULL
         */

      virtual bool load_parameters(string parameters);

        /**<
         * Sets the block parameters specified by string.
         *
         * @param parameters parameter describing string
         *
         * @return true if the parameters were set succesfully, false
         *         otherwise
         */

      void set_id(unsigned int new_id);

        /**<
         * Sets the id for the block.
         *
         * @param id new id to be set
         */

      unsigned int get_id();

        /**<
         * Returns the block id.
         *
         * @return the block id
         */

      virtual bool has_image();

        /**<
         * Checks if the given block can provide a color buffer with
         * image.
         *
         * @return true if this block has a color buffer, false
         *         otherwise
         */

      void connect_input(c_block *input_block, int slot_number);

        /**<
         * Connects another block to this block's input.
         *
         * @param input_block block to be connected to this block's
         *        input slot
         * @param slot_number number of this block's input slot to
         *        connect the input block to
         */

      void disconnect(unsigned int slot_number);

        /**<
         * Disconnects an input block on given input slot.
         *
         * @param slot_number slot to be disconnected
         */

      void invalidate();

        /**<
         * Invalidates the block so that it's output will be recomputed
         * next time it's needed, even if it wasn't necessarry.
         */

      bool is_valid();

        /**<
         * Checks if the block output is currently valid.
         *
         * @return true if the output is valid, false otherwise
         */

      bool is_error();

        /**<
         * Checks if there was any error when generating the block
         * output.
         *
         * @return true if there was an error, false otherwise
         */

      virtual ~c_block();

        /**<
         * Class destructor, destroys the block and frees all it's
         * memory.
         */

      virtual void compute();

        /**<
         * Computes the block output and executes all other asociated
         * actions.
         */
  };

//----------------------------------------------------------------------

 /**
  * Represents a graphic texture designer block that generates and
  * stores image data.
  */

class c_graphic_block: public c_block
  {
    protected:
      t_color_buffer buffer;   /// image buffer of the block

    public:
      c_graphic_block(c_texture_graph *texture_graph);

        /**<
         * Class constructor, initialises a new block. The block will
         * set its parameters depending on the graph settings.
         *
         * @param texture_graph texture graph that this block will
         *        belong to, cannot be NULL
         */

      virtual bool has_image();

        /**<
         * Checks if the given block can provide a color buffer with
         * image.
         *
         * @return true if this block has a color buffer, false
         *         otherwise
         */

      t_color_buffer *get_color_buffer();

        /**<
         * Returns a pointer to the block color buffer, in which the
         * image is stored.
         *
         * @return color buffer of the block
         */

      virtual ~c_graphic_block();

        /**<
         * Class destructor, destroys the block and frees all it's
         * memory.
         */
  };

//----------------------------------------------------------------------

 /**
  * Represents a special texture designer block that stores and
  * processes other than image data.
  */

class c_special_block: public c_block
  {
    protected:

    public:
      c_special_block(c_texture_graph *texture_graph);

        /**<
         * Class constructor, initialises a new block. The block will
         * set its parameters depending on the graph settings.
         *
         * @param texture_graph texture graph that this block will
         *        belong to, cannot be NULL
         */

      virtual bool has_image();

        /**<
         * Checks if the given block can provide a color buffer with
         * image.
         *
         * @return true if this block has a color buffer, false
         *         otherwise
         */

      virtual ~c_special_block();

        /**<
         * Class destructor, destroys the block and frees all it's
         * memory.
         */
  };

//----------------------------------------------------------------------

 /**
  * Represents a texture description graph consisting of blocks.
  */

class c_texture_graph
  {
    protected:
      unsigned int multisampling_level; /// multisampling level, 1 = off
      unsigned int resolution_x;        /// x resolution of the testure
      unsigned int resolution_y;        /// y resolution of the texture
      unsigned int last_id;             /// id to be assigned
      int random_seed;                  /// random number generator seed
      vector<c_block *> *blocks;        /// all the graph blocks

    public:

      c_texture_graph();

        /**<
         * Class constructor, initialises a new texture graph.
         */

      ~c_texture_graph();

        /**<
         * Class destructor, frees all the memory and destroys all the
         * graph block.
         */

      bool compute(bool always);

        /**<
         * Computes all the block outputs and executes all asociated
         * actions. As many as possible of the blocks will be computed,
         * even if there are errors.
         *
         * @param always if true, all blocks will be forced to recompute
         *        even if it's not necesarry, otherwise only invalid
         *        blocks will be recomputed
         *
         * @return true if every block was computed succesfully,
         *         otherwise false
         */

      void set_multisampling(unsigned int level);

        /**<
         * Sets the texture multisapling level.
         *
         * @param level level of multisampling, 1 means no multisampling,
         *        2 means 2 x 2 etc.
         */

      void set_resolution(unsigned int x, unsigned int y);

        /**<
         * Sets the texture resolution.
         *
         * @param x horizontal texture resolution in pixels
         * @param y vertical texture resolution in pixels
         */

      void set_random_seed(int value);

        /**<
         * Sets the random seed value that affects random actions during
         * texture computation. Different values will result in slightly
         * different textures.
         *
         * @param value value to be set as seed
         */

      unsigned int get_multisampling();

        /**<
         * Gets the information about multisampling level set for the
         * texture.
         *
         * @return multisampling level
         */

      void get_resolution(unsigned int *x, unsigned int *y);

        /**<
         * Gets the information about texture resolution.
         *
         * @param x in this variable the horizontal resolution value in
         *        pixels will be returned
         * @param y in this variable the vertical resolution value in
         *        pixels will be returned
         */

      int get_random_seed();

        /**<
         * Gets the information about random seed value. This value
         * affects random actions during texture computation.
         *
         * @return random seed value
         */

      unsigned int get_number_of_blocks();

        /**<
         * Returns number of block in texture graph.
         *
         * @return number of block in texture graph
         */

      c_block *get_block(unsigned int block_number);

        /**<
         * Returns a block of the texture graph with given index.
         *
         * @param block_number index of block that should be returned
         *
         * @return pointer to block at given index or null if the index
         *         is out of range
         */

      void add_block(c_block *block);

        /**<
         * Adds given block to texture graph. This may change the
         * block's properties such as it's id etc.
         *
         * @param block block to be added
         */

      void remove_block(unsigned int block_number);

        /**<
         * Removes block with given index from texture graph. This
         * doesn't delete the block, it will just no longer belong to
         * the texture graph.
         *
         * @param block_number index of block to be removed from the
         *        texture graph
         */

      void delete_block(unsigned int block_number);

        /**<
         * Removes block with given index from texture graph and deletes
         * it.
         *
         * @param block_number index of block to be removed and deleted
         */
  };

/*======================================================================

                     concrete block definitions:

======================================================================*/

 /**
  * Voronoi diagram block.
  */

class c_block_voronoi
  {
    protected:
      t_voronoi_type type;  /// way of computing pixel intensity
    public:
  };

//----------------------------------------------------------------------

 /**
  * Color fill block that generates an image filled with constant color.
  */

class c_block_color_fill: public c_graphic_block
  {
    protected:
      unsigned char red;    /// amount of red in fill color
      unsigned char green;  /// amount of green in fill color
      unsigned char blue;   /// amount of blue in fill color

    public:
      c_block_color_fill(c_texture_graph *texture_graph);
      virtual void compute();

      void set_color(unsigned char red, unsigned char green,
        unsigned char blue);

        /**<
         * Sets the color which the image will be filled with.
         *
         * @param red amount of red
         * @param green amount of green
         * @param blue amount of blue
         */
  };

//----------------------------------------------------------------------

 /**
  * Special block that saves its input to png file.
  */

class c_block_file_save: public c_special_block
  {
    protected:
      string path;

    public:
      c_block_file_save(c_texture_graph *texture_graph);
      virtual void compute();

      void set_path(string path);

        /**<
         * Sets the path where the content should be saved.
         *
         * @param path file path
         */
  };

//----------------------------------------------------------------------

 /**
  * Special block managing an L-system.
  */

class c_block_l_system: public c_special_block
  {
    protected:
      t_grammar grammar;
    public:
  };

//----------------------------------------------------------------------

 /**
  * Special block managing a color transition.
  */

class c_block_color_transition: public c_special_block
  {
    protected:
      t_color_transition transition;
    public:
  };

//----------------------------------------------------------------------

} // namespace

#endif
