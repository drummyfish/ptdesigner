#ifndef PTDESIGNER_H
#define PTDESIGNER_H

//**********************************************************************
/** @file
 * Implementation of procedural textures block designer.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include "ptdesigner.h"

//----------------------------------------------------------------------

void designer_set_resolution(unsigned int x, unsigned int y)

  {
//    texture_resolution_x = x;
//    texture_resolution_y = y;
  }

//----------------------------------------------------------------------

void block_init(t_block *block, t_block_type type)

  {
    int i;

    block->type = type;

    for (i = 0; i < 10; i++)
      {
        block->int_parameters[i] = 0;
        block->fp_parameters[i] = 0;
        block->special_parameters[i] = NULL;
      }

    block->inputs[0] = NULL;
    block->inputs[1] = NULL;
    block->inputs[2] = NULL;

    block->valid = 0;

    switch (type)          // set default parameters
      {
      }
  }

//----------------------------------------------------------------------

void block_connect_input(t_block *block, unsigned int input_number,
  t_block *input)

  {
    if (input_number > 2)
      return;

    block->inputs[input_number] = input;
    block->valid = 0;                            // invalidate the block
  }

//----------------------------------------------------------------------

void block_compute(t_block *block)

  {

  }

//----------------------------------------------------------------------

void invalidate_block(t_block *block)

  {
    block->valid = 0;
  }

//----------------------------------------------------------------------

void block_destroy(t_block *block)

  {
    color_buffer_destroy(block->buffer);
    block->inputs[0] = NULL;
    block->inputs[1] = NULL;
    block->inputs[2] = NULL;
  }

//----------------------------------------------------------------------

void block_destroy_tree(t_block *block)

  {
  }

//----------------------------------------------------------------------

#endif
