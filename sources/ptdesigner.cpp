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

c_block::c_block()

  {
    unsigned int i;

    this->initialised = false;
    this->position_x = 0;
    this->position_y = 0;
    this->valid = false;
    this->error = false;
    this->max_inputs = MAX_INPUT_BLOCKS;
    this->min_inputs = 0;
    this->inputs = 0;
    this->graph = NULL;

    for (i = 0; i < MAX_INPUT_BLOCKS; i++)
      {
        this->input_blocks[i] = NULL;
      }
  }

//----------------------------------------------------------------------

c_block::~c_block()
  {
  }

//----------------------------------------------------------------------

string c_block::get_name()

  {
    return this->name;
  }

//----------------------------------------------------------------------

bool c_block::compute(bool force)

  {
    return true;
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
    this->end_blocks = new vector<c_block *>();

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
    delete this->end_blocks;
  }

//----------------------------------------------------------------------

bool c_block::is_user_of(c_block *block)

  {
    unsigned int i;

    for (i = 0; i < this->inputs; i++)
      if (this->input_blocks[i] == block)
        return true;

    return false;
  }

//----------------------------------------------------------------------

void c_block::set_default()

  {
  }

//----------------------------------------------------------------------

void c_block_mix_channels::set_default()

  {
    this->name = "mix channels";
  }

//----------------------------------------------------------------------

bool c_block_mix_channels::compute(bool force)

  {
    bool change_occured;

    if (!this->manage_input_graphic_blocks(3,force,&change_occured))
      {
        this->set_error();
        return change_occured;
      }

    if (change_occured || !this->valid)
      {
        pt_mix_channels(
          ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
          ((c_graphic_block *) this->input_blocks[1])->get_color_buffer(),
          ((c_graphic_block *) this->input_blocks[2])->get_color_buffer(),
          &this->buffer);

        change_occured = true;

        this->error = false;
        this->valid = true;
      }

    return change_occured;
  }

//----------------------------------------------------------------------

void c_block_perlin_noise::set_default()

  {
    this->name = "perlin noise";
    this->amplitude = 127;
    this->frequency = 5;
    this->max_iterations = -1;
    this->interpolation = INTERPOLATION_LINEAR;
    this->smooth = true;
  }

//----------------------------------------------------------------------

void c_block::set_default_parameters()

  {
    this->name = "block";
    this->set_default();
    this->initialised = true;
    this->invalidate();
  }

//----------------------------------------------------------------------

void c_texture_graph::update()

  {
    unsigned int i, j;
    bool is_end_block;

    // recreate the end_blocks array:

    this->end_blocks->clear();

    for (i = 0; i < this->blocks->size(); i++)
      {
        is_end_block = true;

        for (j = 0; j < this->blocks->size(); j++)
          if (i != j)
            {
              if (this->blocks->at(j)->is_user_of(this->blocks->at(i)))
                {
                  is_end_block = false;
                  break;
                }
            }

        if (is_end_block)
          this->end_blocks->push_back(this->blocks->at(i));
      }
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

void c_block::set_texture_graph(c_texture_graph *graph)

  {
    this->graph = graph;
  }

//----------------------------------------------------------------------

void c_texture_graph::add_block(c_block *block)

  {
    if (block == NULL)
      return;

    this->blocks->push_back(block);
    block->set_texture_graph(this);
    block->set_id(this->last_id);     // assign an unique id
    block->set_default_parameters();
    block->adjust();
    this->last_id++;

    this->update();
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

    if (this->initialised && this->graph != NULL)
      this->graph->get_resolution(&resolution_x,&resolution_y);

    if (!this->initialised || this->buffer.width != resolution_x ||
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

bool c_texture_graph::compute(bool force)

  {
    unsigned int i;

    for (i = 0; i < this->end_blocks->size(); i++)
      this->end_blocks->at(i)->compute(force);

    return this->is_error();
  }

//----------------------------------------------------------------------

bool c_texture_graph::is_error()

  {
    unsigned int i;

    for (i = 0; i < this->blocks->size(); i++)
      if (this->blocks->at(i)->is_error())
        return true;

    return false;
  }

//----------------------------------------------------------------------

bool c_block::manage_input_graphic_blocks(unsigned int number,
  bool force, bool *change_occured)

  {
    unsigned int i;
    bool result;
    bool change;

    if (number >= MAX_INPUT_BLOCKS)
      number = MAX_INPUT_BLOCKS;

    result = true;
    change = false;

    for (i = 0; i < number; i++)
      {
        if (this->input_blocks[i] == NULL)
          result = false;                    // no block connected
        else
          {
            if (!this->input_blocks[i]->has_image())
              result = false;                // not an graphic block
            else
              {                              // compute the input
                if (this->input_blocks[i]->compute(force))
                  change = true;
              }

            if (this->input_blocks[i]->is_error())
              result = false;                // error in the input block
          }
      }

    if (change_occured != NULL)
      *change_occured = change;

    return result;
  }

//----------------------------------------------------------------------

bool c_block::connect(c_block *input_block, unsigned int slot_number)

  {
    if (slot_number >= MAX_INPUT_BLOCKS)
      return false;

    if (this->input_blocks[slot_number] == NULL)
      this->inputs++;

    this->input_blocks[slot_number] = input_block;

    if (this->has_ancestor(this))
      {
        // if the block is its own ancestor then there is a cycle

        this->input_blocks[slot_number] = NULL;  // disconnect
        return false;
      }

    this->graph->update();
    return true;
  }

//----------------------------------------------------------------------

bool c_block::has_ancestor(c_block *block)

  {
    unsigned int i;
    bool result;

    result = false;

    for (i = 0; i < MAX_INPUT_BLOCKS; i++)
      {
        if (this->input_blocks[i] != NULL)
          {
            if (this->input_blocks[i] == block)
              {
                return true;
              }
            else if (this->input_blocks[i]->has_ancestor(block))
              {
                result = true;
                break;
              }
          }
      }

    return result;
  }

//----------------------------------------------------------------------

void c_block::disconnect(unsigned int slot_number)

  {
    if (slot_number >= MAX_INPUT_BLOCKS)
      return;

    if (this->input_blocks[slot_number] != NULL)
      this->inputs--;

    this->input_blocks[slot_number] = NULL;

    this->graph->update();
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

bool c_block_color_fill::compute(bool force)

  {
    bool change_occured;

    change_occured = false;

    if (!this->valid || force)
      {
        pt_color_fill(&(this->buffer),this->red,this->green,this->blue);
        change_occured = true;
      }

    this->valid = true;
    this->error = false;

    return change_occured;
  }

//----------------------------------------------------------------------

void c_block_file_save::set_path(string path)

  {
    this->path = path;
  }

//----------------------------------------------------------------------

bool c_block_file_save::compute(bool force)

  {
    bool change_occured;

    if (!this->manage_input_graphic_blocks(1,force,&change_occured))
      {
        this->set_error();
        return change_occured;
      }

    if (!color_buffer_save_to_png(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
        (char *) this->path.c_str()))
      {
        this->set_error();
        return change_occured;
      }

    return change_occured;
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

void c_block_rgb::set_parameters(int red, int green, int blue)

  {
    this->red = red;
    this->green = green;
    this->blue = blue;

    this->invalidate();
  }

//----------------------------------------------------------------------

void c_block_rgb::set_default()

  {
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->name = "adjust rgb";
  }

//----------------------------------------------------------------------

void c_block_rgb::get_parameters(int *red, int *green, int *blue)

  {
    *red = this->red;
    *green = this->green;
    *blue = this->blue;
  }

//----------------------------------------------------------------------

c_block *c_block::get_input(unsigned int index)

  {
    if (index >= MAX_INPUT_BLOCKS)
      return NULL;

    return this->input_blocks[index];
  }

//----------------------------------------------------------------------

void c_texture_graph::print_as_text()

  {
    unsigned int i,j;
    c_block *block,*block2;

    cout << "----------" << endl;

    cout << "error: " << (this->is_error() ? "yes" : "no") << endl;

    cout << "end block IDs: ";

    for (i = 0; i < this->end_blocks->size(); i++)
      cout << this->end_blocks->at(i)->get_id() << " ";

    cout << endl << endl;

    for (i = 0; i < this->blocks->size(); i++)
      {
        block = this->blocks->at(i);
        cout << block->get_id() << ": " << block->get_name() << " (";

        if (!block->is_valid())
          cout << "in";

        cout << "valid, ";

        if (!block->is_error())
          cout << "no ";

        cout << "error), inputs: ";

        for (j = 0; j < MAX_INPUT_BLOCKS; j++)
          {
            block2 = block->get_input(j);

            if (block2 != NULL)
              cout << block2->get_id() << "(" << j << ") ";
          }

        cout << endl;
      }

    cout << "----------" << endl;
  }

//----------------------------------------------------------------------

void c_block_bump_noise::set_default()

  {
    this->name = "bump noise";
    this->bump_size_from = 0.5;
    this->bump_size_to = 0.01;
    this->quantity = 1;
    this->alter_amplitude = false;
  }

//----------------------------------------------------------------------

bool c_block_rgb::compute(bool force)

  {
    bool change_occured;

    if (!this->manage_input_graphic_blocks(1,force,&change_occured))
      {
        this->set_error();
        return change_occured;
      }

    if (change_occured || !this->valid)
      {
        change_occured = true;

        color_buffer_copy_data(((c_graphic_block *)
          this->input_blocks[0])->get_color_buffer(),&(this->buffer));

        pt_add_rgb(&(this->buffer),this->red,this->green,
          this->blue);
      }

    this->valid = true;
    this->error = false;

    return change_occured;
  }

//----------------------------------------------------------------------

bool c_block_perlin_noise::compute(bool force)

  {
    bool change_occured;

    change_occured = false;

    if (!this->valid || force)
      {
        pt_perlin_noise(this->graph->get_random_seed(),this->amplitude,
          this->frequency,this->max_iterations,this->interpolation,
          &(this->buffer),this->smooth ? 1 : 0);

        change_occured = true;
      }

    this->valid = true;
    this->error = false;

    return change_occured;
  }

//----------------------------------------------------------------------

bool c_block_bump_noise::compute(bool force)

  {
    bool change_occured;

    change_occured = false;

    if (force || !this->valid)
      {
        pt_bump_noise(&(this->buffer),this->bump_size_from,
          this->bump_size_to,this->quantity,
          this->alter_amplitude ? 1 : 0,graph->get_random_seed());

        change_occured = true;
      }

    this->valid = true;
    this->error = false;

    return change_occured;
  }

//----------------------------------------------------------------------

void c_block_color_fill::set_default()

  {
    this->red = 255;
    this->green = 255;
    this->blue = 255;
    this->name = "file save";
  }

//----------------------------------------------------------------------

void c_block_file_save::set_default()

  {
    this->path = "texture.png";
    this->name = "file save";
  }

//----------------------------------------------------------------------
