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
    this->graph = texture_graph;

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

void c_block::invalidate()

  {
    this->valid = false;
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

void c_texture_graph::set_random_seed(int value)

  {
    if (value == this->random_seed)
      return;

    this->random_seed = value;
    this->invalidate_all();
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

void c_texture_graph::set_resolution(unsigned int x, unsigned int y)

  {
    if (x == this->resolution_x && y == this->resolution_y)
      return;      // no need to change anything

    this->resolution_x = x;
    this->resolution_y = y;
    this->adjust_all();
  }

//----------------------------------------------------------------------

int c_texture_graph::get_random_seed()

  {
    return this->random_seed;
  }

//----------------------------------------------------------------------

void c_texture_graph::set_multisampling(unsigned int level)

  {
    unsigned int base_resolution_x,base_resolution_y;

    if (level == 0)    // zero makes no sense
      level = 1;

    if (level > MAX_MULTISAMPLING)
      level = MAX_MULTISAMPLING;

    if (level == this->multisampling_level)
      return;    // no need to change anything

    // division by zero shouldn't occur
    base_resolution_x = this->resolution_x / this->multisampling_level;
    base_resolution_y = this->resolution_y / this->multisampling_level;

    this->multisampling_level = level;  // set the new level

    /* the image must be generated larger in order to perform
       multisampling => increase resolution: */

    this->resolution_x = base_resolution_x * level;
    this->resolution_y = base_resolution_y * level;

    this->adjust_all();
  }

//----------------------------------------------------------------------

void c_block::adjust()

  {
  }

//----------------------------------------------------------------------

void c_graphic_block::adjust()

  {
    unsigned int resolution_x,resolution_y;

    this->graph->get_resolution(&resolution_x,&resolution_y);

    if (this->buffer.width != resolution_x ||
      this->buffer.height != resolution_y)
      {
        this->valid = false;

        // reallocate the buffer with the new resolution:

        color_buffer_destroy(&(this->buffer));

        if (!color_buffer_init(&(this->buffer),resolution_x,
          resolution_y))
          this->set_error();
      }
  }

//----------------------------------------------------------------------

void c_special_block::adjust()

  {
  }

//----------------------------------------------------------------------

c_special_block::~c_special_block()

  {
  }

//----------------------------------------------------------------------

void c_texture_graph::invalidate_all()

  {
    unsigned int i;

    for (i = 0; i < this->blocks->size(); i++)
      this->blocks->at(i)->invalidate();
  }

//----------------------------------------------------------------------

void c_texture_graph::adjust_all()

  {
    unsigned int i;

    for (i = 0; i < this->blocks->size(); i++)
      this->blocks->at(i)->adjust();
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

bool c_block::manage_input_graphic_blocks(unsigned int number)

  {
    unsigned int i;

    if (number >= MAX_INPUT_BLOCKS)
      number = MAX_INPUT_BLOCKS;

    for (i = 0; i < number; i++)
      {
        if (this->input_blocks[i] == NULL)
          return false;                      // no block connected

        if (!this->input_blocks[i]->has_image())
          return false;                      // not an graphic block

        if (!this->input_blocks[i]->is_valid())
          this->input_blocks[i]->compute();

        if (this->input_blocks[i]->is_error())
          return false;                      // error in the input block
      }

    return true;  // OK here
  }

//----------------------------------------------------------------------

void c_block::connect(c_block *input_block, unsigned int slot_number)

  {
    if (slot_number >= MAX_INPUT_BLOCKS)
      return;

    if (this->input_blocks[slot_number] == NULL)
      this->inputs++;

    this->input_blocks[slot_number] = input_block;
  }

//----------------------------------------------------------------------

void c_block::disconnect(unsigned int slot_number)

  {
    if (slot_number >= MAX_INPUT_BLOCKS)
      return;

    if (this->input_blocks[slot_number] != NULL)
      this->inputs--;

    this->input_blocks[slot_number] = NULL;
  }

//----------------------------------------------------------------------

void c_block_color_fill::set_color(unsigned char red,
  unsigned char green, unsigned char blue)

  {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->invalidate();
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
    if (!this->manage_input_graphic_blocks(1))
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

c_block_bump_noise::c_block_bump_noise(c_texture_graph *texture_graph):
  c_graphic_block(texture_graph)

  {
    this->bump_size_from = 0.5;
    this->bump_size_to = 0.1;
    this->quantity = 1;
    this->alter_amplitude = false;
  }

//----------------------------------------------------------------------

void c_block_bump_noise::set_parameters(float bump_size_upper,
  float bump_size_lower, unsigned int quantity, bool alter_amplitude)

  {
    this->bump_size_from = bump_size_upper;
    this->bump_size_to = bump_size_lower;
    this->quantity = quantity;
    this->alter_amplitude = alter_amplitude;

    this->invalidate();
  }

//----------------------------------------------------------------------

void c_block_bump_noise::get_parameters(float *bump_size_upper,
  float *bump_size_lower, unsigned int *quantity, bool *alter_amplitude)

  {
    *bump_size_upper = this->bump_size_from;
    *bump_size_lower = this->bump_size_to;
    *quantity = this->quantity;
    *alter_amplitude = this->alter_amplitude;
  }

//----------------------------------------------------------------------

c_block_perlin_noise::c_block_perlin_noise(
  c_texture_graph *texture_graph): c_graphic_block(texture_graph)

  {
    this->amplitude = 127;
    this->frequency = 5;
    this->interpolation = INTERPOLATION_LINEAR;
    this->max_iterations = -1;                    // not limited
    this->smooth = true;
  }

//----------------------------------------------------------------------

c_block_rgb::c_block_rgb(c_texture_graph *texture_graph):
  c_graphic_block(texture_graph)

  {
    this->red = 0;
    this->green = 0;
    this->blue = 0;
  }

//----------------------------------------------------------------------

void c_block_rgb::set_parameters(int red, int green, int blue)

  {
    this->red = red;
    this->green = green;
    this->blue = blue;

    this->invalidate();
  }

//----------------------------------------------------------------------

void c_block_rgb::get_parameters(int *red, int *green, int *blue)

  {
    *red = this->red;
    *green = this->green;
    *blue = this->blue;
  }

//----------------------------------------------------------------------

void c_block_rgb::compute()

  {
    if (!this->manage_input_graphic_blocks(1))
      {
        this->set_error();
        return;
      }

    color_buffer_copy_data(((c_graphic_block *)
      this->input_blocks[0])->get_color_buffer(),&(this->buffer));

    pt_add_rgb(&(this->buffer),this->red,this->green,
      this->blue);

    this->valid = true;
    this->error = false;
  }

//----------------------------------------------------------------------

void c_block_perlin_noise::compute()

  {
    pt_perlin_noise(this->graph->get_random_seed(),this->amplitude,
      this->frequency,this->max_iterations,this->interpolation,
      &(this->buffer),this->smooth ? 1 : 0);

    this->valid = true;
    this->error = false;
  }

//----------------------------------------------------------------------

void c_block_bump_noise::compute()

  {
    pt_bump_noise(&(this->buffer),this->bump_size_from,
      this->bump_size_to,this->quantity,this->alter_amplitude ? 1 : 0,
      graph->get_random_seed());

    this->valid = true;
    this->error = false;
  }

//----------------------------------------------------------------------
