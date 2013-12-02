//**********************************************************************
/** @file
 * Implementation of procedural textures block designer.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include "ptdesigner.h"

using namespace pt_design;

//----------------------------------------------------------------------

c_block::c_block(c_texture_graph *texture_graph)

  {
    unsigned int i;

    this->position_x = 0;
    this->position_y = 0;
    this->valid = false;
    this->error = false;
    this->max_inputs = MAX_INPUT_BLOCKS;
    this->min_inputs = 0;
    this->inputs = 0;

    for (i = 0; i < MAX_INPUT_BLOCKS; i++)
      {
        this->input_blocks[i] = NULL;
      }

    texture_graph->add_block(this);
  }

//----------------------------------------------------------------------

c_block::~c_block()

  {
  }

//----------------------------------------------------------------------

c_graphic_block::c_graphic_block(c_texture_graph *texture_graph):
  c_block(texture_graph)

  {
    unsigned int resolution_x,resolution_y;

    texture_graph->get_resolution(&resolution_x,&resolution_y);

    if (!color_buffer_init(&(this->buffer),resolution_x,resolution_y))
      this->set_error();
  }

//----------------------------------------------------------------------

c_special_block::c_special_block(c_texture_graph *texture_graph):
  c_block(texture_graph)

  {
  }

//----------------------------------------------------------------------

void c_block::compute()

  {
  }

//----------------------------------------------------------------------

bool c_block::has_image()

  {
    return false;
  }

//----------------------------------------------------------------------

bool c_block::load_parameters(string parameters)

  {
    return true;
  }

//----------------------------------------------------------------------

void c_block::set_error()

  {
    this->error = true;
    this->valid = false;
  }

//----------------------------------------------------------------------

bool c_block::is_valid()

  {
    return this->valid;
  }

//----------------------------------------------------------------------

bool c_block::is_error()

  {
    return this->error;
  }

//----------------------------------------------------------------------

void c_block::set_id(unsigned int new_id)

  {
    this->id = new_id;
  }

//----------------------------------------------------------------------

unsigned int c_block::get_id()

  {
    return this->id;
  }

//----------------------------------------------------------------------

void c_texture_graph::get_resolution(unsigned int *x, unsigned int *y)

  {
    *x = this->resolution_x;
    *y = this->resolution_y;
  }

//----------------------------------------------------------------------

c_graphic_block::~c_graphic_block()

  {
    color_buffer_destroy(&(this->buffer));
  }

//----------------------------------------------------------------------

bool c_graphic_block::has_image()

  {
    return true;   // graphic block does have an image
  }

//----------------------------------------------------------------------

bool c_special_block::has_image()

  {
    return false;  // special block does not have an image
  }

//----------------------------------------------------------------------

c_texture_graph::c_texture_graph()
  {
    this->blocks = new vector<c_block *>();

    this->last_id = 0;
    this->multisampling_level = 1;
    this->resolution_x = 256;       // default resolution
    this->resolution_y = 256;
    this->random_seed = 1;
  }

//----------------------------------------------------------------------

c_texture_graph::~c_texture_graph()

  {
    unsigned int i;

    for (i = 0; i < this->blocks->size(); i++) // destroy all block
      delete this->blocks->at(i);

    delete this->blocks;
  }

//----------------------------------------------------------------------

unsigned int c_texture_graph::get_number_of_blocks()

  {
    return this->blocks->size();
  }

//----------------------------------------------------------------------

t_color_buffer *c_graphic_block::get_color_buffer()

  {
    return &(this->buffer);
  }

//----------------------------------------------------------------------

c_block *c_texture_graph::get_block(unsigned int block_number)

  {
    if (block_number >= this->blocks->size())
      return NULL;

    return this->blocks->at(block_number);
  }

//----------------------------------------------------------------------

void c_texture_graph::add_block(c_block *block)

  {
    if (block == NULL)
      return;

    this->blocks->push_back(block);
    block->set_id(this->last_id);     // assign an unique id
    this->last_id++;
  }

//----------------------------------------------------------------------

c_special_block::~c_special_block()

  {
  }

//----------------------------------------------------------------------

void c_texture_graph::remove_block(unsigned int block_number)

  {
    if (block_number >= this->blocks->size())
      return;

    this->blocks->erase(this->blocks->begin() + block_number);
  }

//----------------------------------------------------------------------

bool c_texture_graph::compute(bool always)

  {
    bool success;
    unsigned int i;

    success = true;

    for (i = 0; i < this->blocks->size(); i++)
      {
        if (always || !this->blocks->at(i)->is_valid())
          this->blocks->at(i)->compute();

        if (this->blocks->at(i)->is_error())
          success = false;
      }

    return success;
  }

//----------------------------------------------------------------------

c_block_color_fill::c_block_color_fill(c_texture_graph *texture_graph):
  c_graphic_block(texture_graph)

  {
    this->red = 255;   // default color is white
    this->green = 255;
    this->blue = 255;

    this->min_inputs = 0;
    this->max_inputs = 0;
  }

//----------------------------------------------------------------------

void c_block_color_fill::compute()

  {
    pt_color_fill(&(this->buffer),this->red,this->green,this->blue);
    this->valid = true;
    this->error = false;
  }

//----------------------------------------------------------------------

c_block_file_save::c_block_file_save(c_texture_graph *texture_graph):
  c_special_block(texture_graph)

  {
    this->path = "texture.png";   // default filename

    this->min_inputs = 1;
    this->max_inputs = 1;
  }

//----------------------------------------------------------------------

void c_block_file_save::set_path(string path)

  {
    this->path = path;
  }

//----------------------------------------------------------------------

void c_block_file_save::compute()

  {
    if (this->inputs < 1)
      {
        this->set_error();
        return;
      }

    if (!this->input_blocks[0]->is_valid())
      this->input_blocks[0]->compute();

    if (this->input_blocks[0]->is_error() ||
      !this->input_blocks[0]->has_image())
      {
        this->set_error();
        return;
      }

    if (!color_buffer_save_to_png(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
        (char *) this->path.c_str()))
      {
        this->set_error();
        return;
      }
  }

//----------------------------------------------------------------------
