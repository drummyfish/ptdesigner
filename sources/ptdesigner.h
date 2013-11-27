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

using namespace std;

#ifdef AAAAAAA

//----------------------------------------------------------------------

/** Represents a texture designer block, which is a node of texture
  * describing graph.
  */

class c_block
  {
    private:
      t_color_buffer *buffer;   /// image buffer of the block
      bool valid;               /// whether the block is currently valid
      bool error;               /// whether there was any error
      c_block *input_blocks[5]; /// input blocks of this block

    public:
      c_block(c_texture_graph *texture_graph);

        /**<
         * Class constructor, initialises a new block.
         *
         * @param texture_graph texture graph that this block will
         *        belong to, cannot be NULL
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

      t_color_buffer *get_color_buffer();

        /**<
         * Returns a pointer to the block color buffer, in which the
         * image is stored.
         *
         * @return color buffer of the block
         */

      ~c_block();

        /**<
         * Class destructor, destroys the block and frees all it's
         * memory.
         */

      virtual void compute();

        /**<
         * Computes the block output, which will be stored in its
         * color buffer.
         */
  };

//----------------------------------------------------------------------

/**
 * Represents a texture description graph consisting of blocks.
 */

class c_texture_graph
  {
    private:
      unsigned int multisampling_level; /// multisampling level, 1 = off
      unsigned int resolution_x;        /// x resolution of the testure
      unsigned int resolution_y;        /// y resolution of the texture
      int random_seed;                  /// random number generator seed
      vector<c_block *> blocks; /// all the graph blocks

    public:

      c_texture_graph();

      /**<
       * Class constructor, initialises a new texture graph.
       */

      void set_multisampling(unsigned int level);
      void set_resolution(unsigned int x, unsigned int y);
      void set_random_seed(int value);
      unsigned int get_multisampling();
      void get_resolution(unsigned int *x, unsigned int *y);
      int get_random_seed();

      unsigned int get_number_of_blocks();
      void delete_block(unsigned int block_number);
      void add_block(c_block *block);
      c_block *get_block(unsigned int block_number);

      ~c_texture_graph();

      /**<
       * Class destructor, frees all the memory and destroys all the
       * graph block.
       */
  };

//----------------------------------------------------------------------
#endif

#endif
