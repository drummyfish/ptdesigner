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
      c_block();

        /**<
         * Class constructor, initialises a new block.
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

      ~c_block();

        /**<
         * Class destructor, destroys the block and frees all it's
         * memory.
         */
  };

#endif
