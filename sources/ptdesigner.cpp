//**********************************************************************
/** @file
 * Implementation of procedural textures block designer.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include "ptdesigner.h"
#include <fstream>
#include <sstream>
#include "rapidxml_print.hpp"

using namespace pt_design;
using namespace std;

//----------------------------------------------------------------------

  /**
   * A private function that converts int to string. This works the same
   * way as std::to_string but is used rather because to_string causes
   * problems with MinGW.
   *
   * @param value value to be converted
   *
   * @return string representing given value
   */

string pt_to_string(int value)

  {
    string result;
    bool is_negative;
    unsigned int leftover;

    result = "";
    is_negative = value < 0;

    if (is_negative)
      value = -1 * value;

    if (value == 0)
      result = "0";
    else while (true)
      {
        if (value == 0)
          break;

        leftover = value % 10;

        value = value / 10;

        result = ((char) (leftover + '0')) + result;
      }

    if (is_negative)
      result = "-" + result;

    return result;
  }

//----------------------------------------------------------------------

  /**
   * A private function that converts double to string. This works the
   * same way as std::to_string but is used rather because to_string
   * causes problems with MinGW.
   *
   * @param value value to be converted
   *
   * @return string representing given value
   */

string pt_to_string(double value)

  {
    string result;
    stringstream str_stream;

    str_stream << value;

    result = str_stream.str();
    return result;
  }

//----------------------------------------------------------------------

string c_texture_graph::coordinations_to_string(
  double coordination_list[][2], unsigned int length)

  {
    unsigned int i;
    string result;
    bool first;

    result = "";
    first = true;

    for (i = 0; i < length; i++)
      {
        if (first)
          first = false;
        else
          result += ",";

        result = result + pt_to_string(coordination_list[i][0]) + ":" +
          pt_to_string(coordination_list[i][1]);
      }

    return result;
  }

//----------------------------------------------------------------------

string c_texture_graph::char_array_to_string(unsigned char char_array[],
        unsigned int length)

  {
    unsigned int i;
    string result;
    bool first;

    result = "";
    first = true;

    for (i = 0; i < length; i++)
      {
        if (first)
          first = false;
        else
          result += ",";

        result += pt_to_string((int) char_array[i]);
      }

    return result;
  }

//----------------------------------------------------------------------

void c_texture_graph::string_to_coordinations(
  double coordination_list[][2], string coordinations,
  unsigned int *length, unsigned int max_length)

  {
    stringstream str_stream;
    char character;
    unsigned int position;
    double value_x, value_y;

    str_stream.str(coordinations);

    position = 0;

    while (true)
      {
		if (position >= max_length - 1)
          break;
		  
		str_stream >> value_x;
        str_stream >> character;
        
        if (str_stream.eof())
          break;
        
        str_stream >> value_y;
        str_stream >> character;
        
        coordination_list[position][0] = value_x;
        coordination_list[position][1] = value_y;

        position++;
      }

    *length = position;
  }

//----------------------------------------------------------------------

void c_texture_graph::string_to_char_array(unsigned char char_array[],
  string char_string, unsigned int *length, unsigned int max_length)

  {
    stringstream str_stream;
    unsigned char character;
    unsigned int helper;
    unsigned int position;

    str_stream.str(char_string);

    for (position = 0; position < max_length; position++)
      char_array[position] = 0;

    position = 0;

    while (true)
      {
		if (position >= max_length)
          break;
		  
		if (str_stream.eof())
          break;
		  
		str_stream >> helper;          
		str_stream >> character;   // ","
        
        char_array[position] = helper;
        position++;
      }
      
    *length = position;
  }
  
//----------------------------------------------------------------------

void c_texture_graph::string_to_double_array(double double_array[],
  string double_string, unsigned int *length, unsigned int max_length)

  {
    stringstream str_stream;
    double helper;
    unsigned int position;

    str_stream.str(double_string);

    for (position = 0; position < max_length; position++)
      double_array[position] = 0;

    position = 0;

    if (!str_stream.eof())
      do
        {
          if (position >= max_length - 1)
            break;

          str_stream >> helper;

          double_array[position] = helper;

          position++;
        } while (!str_stream.eof());

    *length = position;
  }

//----------------------------------------------------------------------

c_parameters::c_parameters(c_block *owner)

  {
    this->locked = false;
    this->block = owner;
    this->parameters = new vector<t_parameter>();
  }

//----------------------------------------------------------------------

c_parameters::~c_parameters()

  {
    delete this->parameters;
  }

//----------------------------------------------------------------------

void c_parameters::changed()

  {
    this->block->invalidate();
  }

//----------------------------------------------------------------------

bool c_parameters::is_locked()

  {
    return this->locked;
  }

//----------------------------------------------------------------------

unsigned int c_parameters::number_of_parameters()

  {
    return this->parameters->size();
  }

//----------------------------------------------------------------------

t_parameter_type c_parameters::get_type(string name)

  {
    unsigned int i;

    for (i = 0; i < this->parameters->size(); i++)
      if (this->parameters->at(i).name == name)
        return this->parameters->at(i).type;

    return PARAMETER_INT;
  }

//----------------------------------------------------------------------

t_parameter_type c_parameters::get_type(unsigned int index)

  {
    if (index < this->parameters->size())
      return this->parameters->at(index).type;

    return PARAMETER_INT;
  }

//----------------------------------------------------------------------

string c_parameters::get_name(unsigned int index)

  {
    string result;

    result = "";

    if (index < this->parameters->size())
      result = this->parameters->at(index).name;

    return result;
  }

//----------------------------------------------------------------------

bool c_parameters::get_bool_value(unsigned int index)

  {
     if (index < this->parameters->size())
      return this->parameters->at(index).bool_value;

    return true;
  }

//----------------------------------------------------------------------

bool c_parameters::get_bool_value(string parameter_name)

  {
    int index;

    index = this->index_by_name(parameter_name);

    if (index >= 0 && this->parameters->at(index).type ==
      PARAMETER_BOOL)
      return this->parameters->at(index).bool_value;

    return 0;
  }

//----------------------------------------------------------------------

bool c_parameters::set_bool_value(string parameter_name, bool value)

  {
    int index;

    index = this->index_by_name(parameter_name);

    if (index >= 0 && this->parameters->at(index).type ==
      PARAMETER_BOOL)
      {
        this->parameters->at(index).bool_value = value;
        this->changed();

        return true;
      }

    return false;
  }

//----------------------------------------------------------------------

int c_parameters::index_by_name(string name)

  {
    unsigned int i;

    for (i = 0; i < this->parameters->size(); i++)
      if (this->parameters->at(i).name == name)
        return i;

    return -1;
  }

//----------------------------------------------------------------------

bool c_parameters::add_parameter(string name,t_parameter_type type)

  {
    int index;
    t_parameter parameter;

    if (this->locked)
      return false;

    index = this->index_by_name(name);

    if (index < 0)
      {
        parameter.name = name;
        parameter.type = type;

        this->changed();

        this->parameters->push_back(parameter);
        return true;
      }

    return false;
  }

//----------------------------------------------------------------------

bool c_parameters::set_int_value(string parameter_name, int value)

  {
    int index;

    index = this->index_by_name(parameter_name);

    if (index >= 0 && this->parameters->at(index).type == PARAMETER_INT)
      {
        this->parameters->at(index).int_value = value;
        this->changed();

        return true;
      }

    return false;
  }

//----------------------------------------------------------------------

unsigned int c_block::get_min_inputs()

  {
	 return this->min_inputs;
  }
  
//----------------------------------------------------------------------

unsigned int c_block::get_max_inputs()

  {
	 return this->max_inputs;
  }

//----------------------------------------------------------------------

bool c_parameters::set_double_value(string parameter_name, double value)

  {
    int index;

    index = this->index_by_name(parameter_name);

    if (index >= 0 && this->parameters->at(index).type ==
      PARAMETER_DOUBLE)
      {
        this->parameters->at(index).double_value = value;
        this->changed();

        return true;
      }

    return false;
  }

//----------------------------------------------------------------------

bool c_parameters::set_string_value(string parameter_name, char *value)

  {
    int index;

    index = this->index_by_name(parameter_name);

    if (index >= 0 && this->parameters->at(index).type ==
      PARAMETER_STRING)
      {
        this->parameters->at(index).string_value = value;
        this->changed();

        return true;
      }

    return false;
  }

//----------------------------------------------------------------------

bool c_parameters::set_string_value(string parameter_name, string value)

  {
    return this->set_string_value(parameter_name,
      (char *) value.c_str());
  }

//----------------------------------------------------------------------

int c_parameters::get_int_value(unsigned int index)

  {
    if (index < this->parameters->size())
      return this->parameters->at(index).int_value;

    return 0;
  }

//----------------------------------------------------------------------

double c_parameters::get_double_value(unsigned int index)

  {
    if (index < this->parameters->size())
      return this->parameters->at(index).double_value;

    return 0;
  }

//----------------------------------------------------------------------

string c_parameters::get_string_value(unsigned int index)

  {
    if (index < this->parameters->size())
      return this->parameters->at(index).string_value;

    return 0;
  }

//----------------------------------------------------------------------

void c_parameters::lock()

  {
    this->locked = true;
  }

//----------------------------------------------------------------------

int c_parameters::get_int_value(string parameter_name)

  {
    int index;

    index = this->index_by_name(parameter_name);

    if (index >= 0 && this->parameters->at(index).type == PARAMETER_INT)
      return this->parameters->at(index).int_value;

    return 0;
  }

//----------------------------------------------------------------------

double c_parameters::get_double_value(string parameter_name)

  {
    int index;

    index = this->index_by_name(parameter_name);

    if (index >= 0 && this->parameters->at(index).type ==
      PARAMETER_DOUBLE)
      return this->parameters->at(index).double_value;

    return 0;
  }

//----------------------------------------------------------------------

string c_parameters::get_string_value(string parameter_name)

  {
    int index;

    index = this->index_by_name(parameter_name);

    if (index >= 0 && this->parameters->at(index).type ==
      PARAMETER_STRING)
      return this->parameters->at(index).string_value;

    return 0;
  }

//----------------------------------------------------------------------

c_block::c_block()

  {
    unsigned int i;

    this->initialised = false;
    this->valid = false;
    this->error = false;
    this->max_inputs = MAX_INPUT_BLOCKS;
    this->min_inputs = 0;
    this->inputs = 0;
    this->graph = NULL;
    this->set_id(0);
    this->parameters = new c_parameters(this);
    this->uses_global_seed = true;
    this->is_end_block = false;

    for (i = 0; i < MAX_INPUT_BLOCKS; i++)
      {
        this->input_blocks[i] = NULL;
      }
  }

//----------------------------------------------------------------------

bool c_block::is_terminal()

  {
    return this->is_end_block;
  }

//----------------------------------------------------------------------

c_parameters *c_block::get_parameters()

  {
    return this->parameters;
  }

//----------------------------------------------------------------------

c_block::~c_block()

  {
    delete this->parameters;
  }

//----------------------------------------------------------------------

bool c_block::is_using_global_seed()

  {
    return this->uses_global_seed;
  }

//----------------------------------------------------------------------

void c_block::use_global_seed()

  {
    if (this->is_using_global_seed())
      return;

    this->uses_global_seed = true;
    this->invalidate();
  }

//----------------------------------------------------------------------

int c_block::get_random_seed()

  {
    if (this->uses_global_seed)
      return this->graph->get_random_seed();

    return this->custom_seed;
  }

//----------------------------------------------------------------------

void c_block::use_custom_seed(int value)

  {
    if (!this->is_using_global_seed() && this->get_random_seed()
      == value)
      return;

    this->uses_global_seed = false;
    this->custom_seed = value;
    this->invalidate();
  }

//----------------------------------------------------------------------

string c_block::get_name()

  {
    return this->name;
  }

//----------------------------------------------------------------------

bool c_block::compute(bool force)

  {
    bool change_occured, error_occured;
    unsigned int i;

    if (this->inputs < this->min_inputs)
      {
        this->invalidate();
        this->error = true;
      }

    change_occured = false;
    error_occured = false;

    for (i = 0; i < MAX_INPUT_BLOCKS; i++)  // check input blocks
      if (this->input_blocks[i] != NULL)
        if (this->input_blocks[i]->compute(force))
          change_occured = true;

    if (change_occured || force || !this->is_valid())
      {
        error_occured = !this->execute();
        change_occured = true;
      }

    if (error_occured)
      {
        this->invalidate();
        this->error = true;
      }
    else
      {
        this->valid = true;
        this->error = false;
      }

    return change_occured;
  }

//----------------------------------------------------------------------

bool c_block::execute()

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
    
    // invalidate all child blocks:
    
    if (this->graph != NULL)
      this->graph->block_invalidated(this);
  }

//----------------------------------------------------------------------

void c_texture_graph::block_invalidated(c_block *block)

  {
	unsigned int i,j;
  
    // find all children blocks and invalidate them:
  
    for (i = 0; i < this->blocks->size(); i++)
      {
        for (j = 0; j < MAX_INPUT_BLOCKS; j++)
          if (this->blocks->at(i)->get_input(j) == block)
            {
			  // recursively invalidate the child block:

		      this->blocks->at(i)->invalidate();
		      break;
			}
      }
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
    this->supersampling_level = 1;
    this->resolution_x = 256;       // default resolution
    this->resolution_y = 256;
    this->random_seed = 0;
  }

//----------------------------------------------------------------------

vector<c_block *> *c_texture_graph::get_end_blocks()

  {
	return this->end_block;
  }

//----------------------------------------------------------------------

bool c_block::is_graphic_input(unsigned int number)

  {
    if (number >= MAX_INPUT_BLOCKS)
      return false;

    return (this->input_blocks[number] != NULL) &&
      (this->input_blocks[number]->has_image());
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

void c_block::set_default_parameters()

  {
    this->name = "block";
    this->set_default();
    this->parameters->lock();
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

int c_texture_graph::add_block(c_block *block)

  {
    if (block == NULL)
      return -1;

    this->blocks->push_back(block);
    block->set_texture_graph(this);
    block->set_id(this->last_id);     // assign an unique id
    block->set_default_parameters();
    block->adjust();
    this->last_id++;

    this->update();
    
    return block->get_id();
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

void c_texture_graph::set_supersampling(unsigned int level)

  {
    if (level == 0)    // zero makes no sense
      level = 1;

    if (level > MAX_SUPERSAMPLING)
      level = MAX_SUPERSAMPLING;

    if (level == this->supersampling_level)
      return;    // no need to change anything

    this->supersampling_level = level;  // set the new level

    this->adjust_all();
  }

//----------------------------------------------------------------------

void c_block::adjust()

  {
  }

//----------------------------------------------------------------------

c_graphic_block::c_graphic_block()

  {
    color_buffer_init(&(this->buffer),0,0);
  }

//----------------------------------------------------------------------

unsigned int c_texture_graph::get_supersampling()

  {
    return this->supersampling_level;
  }

//----------------------------------------------------------------------

void c_graphic_block::adjust()

  {
    unsigned int resolution_x,resolution_y,supersampling;

    if (this->initialised && this->graph != NULL)
      {
        this->graph->get_resolution(&resolution_x,&resolution_y);
        supersampling = this->graph->get_supersampling();

        // compute the real resolution (with supersampling):

        resolution_x = resolution_x * supersampling;
        resolution_y = resolution_y * supersampling;
      }

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

void c_texture_graph::delete_block(unsigned int block_number)

  {
    c_block *block;
    unsigned int i,j;

    if (block_number >= this->blocks->size())
      return;

    block = this->blocks->at(block_number);
    
    for (i = 0; i < this->blocks->size(); i++)  // cancel connections
      for (j = 0; j < MAX_INPUT_BLOCKS; j++)
        if (this->blocks->at(i)->get_input(j) == block)
          this->blocks->at(i)->disconnect(j);
    
    this->blocks->erase(this->blocks->begin() + block_number);
    
    // now delete the block from the end block list if it is there:
    
    for (i = 0; i < this->end_blocks->size(); i++) 
      if (this->end_blocks->at(i) == block)
        {
          this->end_blocks->erase(this->end_blocks->begin() + i);
          break;
        }
    
    delete block;
  }
  
//----------------------------------------------------------------------

void c_texture_graph::delete_block_with_id(unsigned int block_id)

  {
	unsigned int i;
	
	for (i = 0; i < this->blocks->size(); i++)
	  if (this->blocks->at(i)->get_id() == block_id)
	    {
	      this->delete_block(i);
		  break;
		}
  }

//----------------------------------------------------------------------

bool c_texture_graph::compute(bool force)

  {
    unsigned int i;

    for (i = 0; i < this->end_blocks->size(); i++)
      this->end_blocks->at(i)->compute(force);

    return !this->is_error();
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

bool c_block::connect(c_block *input_block, unsigned int slot_number)

  {
    if (slot_number >= MAX_INPUT_BLOCKS || input_block->is_terminal()
      || this->inputs >= this->max_inputs ||
      slot_number >= this->max_inputs)
      return false;

    this->inputs++;

    if (this->input_blocks[slot_number] != NULL)
      this->disconnect(slot_number);

    this->input_blocks[slot_number] = input_block;

    if (this->has_ancestor(this))
      {
        // if the block is its own ancestor then there is a cycle

        this->disconnect(slot_number);
        return false;
      }

    this->invalidate();
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
    this->invalidate();
    this->graph->update();
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

string c_parameters::get_value_string(unsigned int index)

  {
    if (index >= this->parameters->size())
      return "";

    switch (this->parameters->at(index).type)
      {
        case PARAMETER_INT:
          return pt_to_string(this->parameters->at(index).int_value);
          break;

        case PARAMETER_DOUBLE:
          return pt_to_string(this->parameters->at(index).double_value);
          break;

        case PARAMETER_BOOL:
          return pt_to_string(this->parameters->at(index).bool_value);
          break;

        case PARAMETER_STRING:
          return this->parameters->at(index).string_value;
          break;
      }

    return "";
  }

//----------------------------------------------------------------------

c_block *c_block::get_block_instance(string block_name)

  {
    if (block_name.compare(FILE_SAVE_NAME) == 0)
      return new c_block_file_save();
    if (block_name.compare(FILE_LOAD_NAME) == 0)
      return new c_block_file_load();
    else if (block_name.compare(BUMP_NOISE_NAME) == 0)
      return new c_block_bump_noise();
    else if (block_name.compare(COLOR_FILL_NAME) == 0)
      return new c_block_color_fill();
    else if (block_name.compare(PERLIN_NOISE_NAME) == 0)
      return new c_block_perlin_noise();
    else if (block_name.compare(MIX_CHANNELS_NAME) == 0)
      return new c_block_mix_channels();
    else if (block_name.compare(VORONOI_DIAGRAM_NAME) == 0)
      return new c_block_voronoi_diagram();
    else if (block_name.compare(RGB_NAME) == 0)
      return new c_block_rgb();
    else if (block_name.compare(HSL_NAME) == 0)
      return new c_block_hsl();
    else if (block_name.compare(FAULT_FORMATION_NOISE_NAME) == 0)
      return new c_block_fault_formation_noise();
    else if (block_name.compare(SUBSTRATE_NAME) == 0)
      return new c_block_substrate();
    else if (block_name.compare(MIX_NAME) == 0)
      return new c_block_mix();
    else if (block_name.compare(MARBLE_NAME) == 0)
      return new c_block_marble();
    else if (block_name.compare(WOOD_NAME) == 0)
      return new c_block_wood();
    else if (block_name.compare(PARTICLES_NAME) == 0)
      return new c_block_particles();
    else if (block_name.compare(CIRCLE_TRANSFORM_NAME) == 0)
      return new c_block_circle_transform();
    else if (block_name.compare(RADIUS_TRANSFORM_NAME) == 0)
      return new c_block_radius_transform();
    else if (block_name.compare(SINE_TRANSFORM_NAME) == 0)
      return new c_block_sine_transform();
    else if (block_name.compare(INVERT_NAME) == 0)
      return new c_block_invert();
    else if (block_name.compare(DITHER_NAME) == 0)
      return new c_block_dither();
    else if (block_name.compare(CROP_AMPLITUDE_NAME) == 0)
      return new c_block_crop_amplitude();
    else if (block_name.compare(NORMAL_MAP_NAME) == 0)
      return new c_block_normal_map();
    else if (block_name.compare(LIGHT_NAME) == 0)
      return new c_block_light();
    else if (block_name.compare(GLASS_NAME) == 0)
      return new c_block_glass();
    else if (block_name.compare(GRAYSCALE_NAME) == 0)
      return new c_block_grayscale();
    else if (block_name.compare(COLOR_TRANSITION_NAME) == 0)
      return new c_block_color_transition();
    else if (block_name.compare(MAP_TRANSITION_NAME) == 0)
      return new c_block_map_transition();
    else if (block_name.compare(BRIGHTNESS_CONTRAST_NAME) == 0)
      return new c_block_brightness_contrast();
    else if (block_name.compare(END_BLOCK_NAME) == 0)
      return new c_block_end();
    else if (block_name.compare(L_SYSTEM_NAME) == 0)
      return new c_block_l_system();
    else if (block_name.compare(TURTLE_NAME) == 0)
      return new c_block_turtle();
    else if (block_name.compare(SIMPLE_NOISE_NAME) == 0)
      return new c_block_simple_noise();
    else if (block_name.compare(SQUARE_MOSAIC_NAME) == 0)
      return new c_block_square_mosaic();
    else if (block_name.compare(CELLULAR_RPS_NAME) == 0)
      return new c_block_cellular_automaton_rps();
    else if (block_name.compare(CELLULAR_CYCLIC_NAME) == 0)
      return new c_block_cellular_automaton_cyclic();
    else if (block_name.compare(CELLULAR_GENERAL_NAME) == 0)
      return new c_block_cellular_automaton_general();
    else if (block_name.compare(BLUR_NAME) == 0)
      return new c_block_blur();
    else if (block_name.compare(REPLACE_COLORS_NAME) == 0)
      return new c_block_replace_colors();
    else if (block_name.compare(TILE_NAME) == 0)
      return new c_block_tile();
    else if (block_name.compare(EDGE_DETECTION_NAME) == 0)
      return new c_block_edge_detection();
    else if (block_name.compare(SHARPEN_NAME) == 0)
      return new c_block_sharpen();
    else if (block_name.compare(EMBOSS_NAME) == 0)
      return new c_block_emboss();
    else if (block_name.compare(CONVOLUTION_NAME) == 0)
      return new c_block_convolution();
    else if (block_name.compare(GEOMETRIC_TRANSFORM_NAME) == 0)
      return new c_block_geometric_transform();

    return NULL;
  }

//----------------------------------------------------------------------

bool c_texture_graph::connect_by_id(int id_input, int id_to,
  unsigned int slot)

  {
    c_block *block1, *block2;

    block1 = this->get_block_by_id(id_input);
    block2 = this->get_block_by_id(id_to);

    if (block1 == NULL || block2 == NULL || slot >= MAX_INPUT_BLOCKS)
      return false;

    return block2->connect(block1,slot);
  }

//----------------------------------------------------------------------

void c_texture_graph::clear()

  {
    while (this->blocks->size() > 0)
      {
        this->delete_block(0);
      }
  }

//----------------------------------------------------------------------

c_texture_graph::~c_texture_graph()

  {
    this->clear();

    delete this->blocks;
    delete this->end_blocks;
  }

//----------------------------------------------------------------------

bool c_texture_graph::load_from_file(string filename)

  {
    string line,filetext,block_name,parameter_name,parameter_value,
      help_string;
    char *parameter_type;
    int block_id,slot_number;
    ifstream myfile(filename);
    xml_document<> document;
    xml_node<> *node, *node2;
    xml_attribute<> *help_attribute;
    char *filetext_c;
    c_block *block;

    if (!myfile.is_open())
      return false;

    this->clear();

    while (getline(myfile,line))
      {
        filetext += line + "\n";
      }

    myfile.close();

    filetext_c = document.allocate_string(filetext.c_str(),
      filetext.length() + 1);

    document.parse<0>(filetext_c);

    node = document.first_node("texturegraph");

    // graph attributes:

    help_string = node->first_attribute("width")->value();
    this->resolution_x = atoi(help_string.c_str());
    help_string = node->first_attribute("height")->value();
    this->resolution_y = atoi(help_string.c_str());
    help_string = node->first_attribute("seed")->value();
    this->random_seed = atoi(help_string.c_str());
    help_string = node->first_attribute("supersampling")->value();
    this->set_supersampling(atoi(help_string.c_str()));

    node = document.first_node("texturegraph")->first_node();

    // node should point to the first block node now

    while (node != NULL) // process all blocks
      {
        block_name = node->first_attribute("type")->value();

        block_id =
          atoi(node->first_attribute("id")->value());

        block = c_block::get_block_instance(block_name);

        help_attribute = node->first_attribute("seed");

        if (help_attribute != NULL)
          {
            block->use_custom_seed(atoi(help_attribute->value()));
          }

        if (block == NULL)
          return 0;

        this->add_block(block);
        block->set_id(block_id);

        node2 = node->first_node();

        while (node2 != NULL)   // load parameters
          {
            if (strcmp(node2->name(),"parameter") == 0)
              {
                parameter_name =
                  node2->first_attribute("name")->value();
                parameter_value =
                  node2->first_attribute("value")->value();
                parameter_type =
                  node2->first_attribute("type")->value();

                if (strcmp(parameter_type,"int") == 0)
                  block->get_parameters()->set_int_value(parameter_name,
                    atoi(parameter_value.c_str()));
                else if (strcmp(parameter_type,"double") == 0)
                  block->get_parameters()->set_double_value(
                    parameter_name,atof(parameter_value.c_str()));
                else if (strcmp(parameter_type,"string") == 0)
                  block->get_parameters()->set_string_value(
                    parameter_name,parameter_value);
                else if (strcmp(parameter_type,"bool") == 0)
                  block->get_parameters()->set_bool_value(
                    parameter_name,parameter_value[0] == '1');
              }

            node2 = node2->next_sibling();
          }

        node = node->next_sibling();  // next block
      }

    // now that the blocks are created, connect them:

    node = document.first_node()->first_node();

    while (node != NULL)
      {
        block_id =
          atoi(node->first_attribute()->next_attribute()->value());

        block = this->get_block_by_id(block_id);

        node2 = node->first_node();

        while (node2 != NULL)   // load inputs
          {
            if (strcmp(node2->name(),"input") == 0)
              {
                block_id =
                  atoi(node2->first_attribute("id")->value());
                slot_number =
                  atoi(node2->first_attribute("slot")->value());
                block->connect(this->get_block_by_id(block_id),
                  slot_number);
              }

            node2 = node2->next_sibling();
          }

        node = node->next_sibling();  // next block
      }

    return true;
  }

//----------------------------------------------------------------------

c_block *c_texture_graph::get_block_by_id(unsigned int block_id)

  {
    unsigned int i;

    for (i = 0; i < this->blocks->size(); i++)
      if (this->blocks->at(i)->get_id() == block_id)
        return this->blocks->at(i);

    return NULL;
  }

//----------------------------------------------------------------------

bool c_texture_graph::save_to_file(string filename)

  {
    xml_document<> document;
    ofstream save_file(filename.c_str());
    string document_text;
    xml_node<> *node, *node2;
    c_block *help_block,*current_block;
    unsigned int i,j;
    string help_string,slot_number;
    unsigned int res_x,res_y;

    if (save_file.is_open())
      {
        // doctype node:

        node = document.allocate_node(node_doctype,(char *) "",
          (char *) "ptgraph");

        document.append_node(node);

        // graph node:

        node = document.allocate_node(node_element,"texturegraph");

        // texture graph attributes:

        this->get_resolution(&res_x,&res_y);

        help_string = pt_to_string((int) res_x).c_str();
        node->append_attribute(document.allocate_attribute("width",
          document.allocate_string(help_string.c_str(),
          help_string.length() + 1)));

        help_string = pt_to_string((int) res_y).c_str();
        node->append_attribute(document.allocate_attribute("height",
          document.allocate_string(help_string.c_str(),
          help_string.length() + 1)));

        help_string = pt_to_string((int) this->random_seed).c_str();
        node->append_attribute(document.allocate_attribute("seed",
          document.allocate_string(help_string.c_str(),
          help_string.length() + 1)));

        help_string = pt_to_string((int)
          this->supersampling_level).c_str();
        node->append_attribute(document.allocate_attribute(
          "supersampling",document.allocate_string(help_string.c_str(),
          help_string.length() + 1)));

        document.append_node(node);

        // append blocks:

        for (i = 0; i < this->blocks->size(); i++)
          {
            current_block = this->blocks->at(i);

            node = document.allocate_node(node_element,"block");

            // block element attributes:

            node->append_attribute(document.allocate_attribute("type",
              current_block->get_name().c_str()));

            help_string = pt_to_string((int) current_block->get_id());

            node->append_attribute(document.allocate_attribute("id",
              document.allocate_string(help_string.c_str(),
              help_string.length() + 1)));

            if (!current_block->is_using_global_seed())
              {
                help_string = pt_to_string((int)
                  current_block->get_random_seed());

                node->append_attribute(document.allocate_attribute(
                  "seed",document.allocate_string(help_string.c_str(),
                  help_string.length() + 1)));
              }

            // input block elements:

            for (j = 0; j < MAX_INPUT_BLOCKS; j++)
              {
                help_block = current_block->get_input(j);

                if (help_block != NULL)
                  {
                    node2 =
                      document.allocate_node(node_element,"input");

                    help_string = pt_to_string((int)
                      help_block->get_id());

                    node2->append_attribute(
                      document.allocate_attribute(
                        "id",document.allocate_string(
                        help_string.c_str(),help_string.length() + 1)));

                    slot_number = pt_to_string((int) j);

                    node2->append_attribute(
                      document.allocate_attribute(
                        "slot",document.allocate_string(
                        slot_number.c_str(),slot_number.length() + 1)));

                    node->append_node(node2);
                  }
              }

            // block parameters:

            for (j = 0; j < current_block->get_parameters()->number_of_parameters(); j++)
              {
                node2 = document.allocate_node(node_element,
                  "parameter");

                node2->append_attribute(
                  document.allocate_attribute("name", (char *)
                  current_block->get_parameters()->get_name(j).c_str()));

                switch (current_block->get_parameters()->get_type(j))
                  {
                    case PARAMETER_INT:
                      node2->append_attribute(
                        document.allocate_attribute("type","int"));
                      break;

                    case PARAMETER_DOUBLE:
                      node2->append_attribute(
                        document.allocate_attribute("type","double"));
                      break;

                    case PARAMETER_BOOL:
                      node2->append_attribute(
                        document.allocate_attribute("type","bool"));
                      break;

                    case PARAMETER_STRING:
                      node2->append_attribute(
                        document.allocate_attribute("type","string"));
                      break;
                  }

                node2->append_attribute(
                  document.allocate_attribute("value",
                  document.allocate_string(
                  (char *) current_block->get_parameters()->get_value_string(j).c_str())));

                node->append_node(node2);
              }

            document.first_node("texturegraph")->append_node(node);
          }

        save_file << document;
        save_file.close();
      }
    else
      return false;

    return true;
  }

//======================================================================
// SPECIFIC BLOCK FUNCTIONS:
//======================================================================

c_block_color_transition::c_block_color_transition(): c_special_block()

  {
    color_transition_init(&(this->transition));
  }

//----------------------------------------------------------------------

c_block_color_transition::~c_block_color_transition()

  {
    color_transition_destroy(&(this->transition));
  }

//----------------------------------------------------------------------

void c_block_color_transition::get_color(unsigned int coordination,
   unsigned char *r, unsigned char *g, unsigned char *b)
        
  {
	color_transition_get_color(coordination,r,g,b,&this->transition);
  }

//----------------------------------------------------------------------

c_block_l_system::c_block_l_system(): c_special_block()

  {
    grammar_init(&(this->grammar),(char *) "",0);
  }

//----------------------------------------------------------------------

c_block_l_system::~c_block_l_system()

  {
    grammar_destroy(&(this->grammar));
  }

//----------------------------------------------------------------------

t_color_transition *c_block_color_transition::get_color_transition()

  {
    return &this->transition;
  }

//----------------------------------------------------------------------

t_grammar *c_block_l_system::get_grammar()

  {
    return &(this->grammar);
  }

//======================================================================
// 'SET DEFAULT' FUNCTIONS:
//======================================================================

void c_block_perlin_noise::set_default()

  {
    this->name = PERLIN_NOISE_NAME;
    this->min_inputs = 0;
    this->max_inputs = 0;

    this->parameters->add_parameter("amplitude",PARAMETER_INT);
    this->parameters->add_parameter("frequency",PARAMETER_INT);
    this->parameters->add_parameter("max iterations",PARAMETER_INT);
    this->parameters->add_parameter("interpolation",PARAMETER_INT);
    this->parameters->add_parameter("smooth",PARAMETER_BOOL);
    this->parameters->lock();

    this->parameters->set_int_value("amplitude",127);
    this->parameters->set_int_value("frequency",6);
    this->parameters->set_int_value("max iterations",-1);
    this->parameters->set_int_value("interpolation",INTERPOLATION_LINEAR);
    this->parameters->set_bool_value("smooth",true);
  }

//----------------------------------------------------------------------

void c_block_geometric_transform::set_default()

  {
    this->name = GEOMETRIC_TRANSFORM_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("shift x",PARAMETER_DOUBLE);
    this->parameters->add_parameter("shift y",PARAMETER_DOUBLE);
    this->parameters->add_parameter("flip horizontal",PARAMETER_BOOL);
    this->parameters->add_parameter("flip vertical",PARAMETER_BOOL);
    this->parameters->add_parameter("angle",PARAMETER_INT);

    this->parameters->set_double_value("shift x",0);
    this->parameters->set_double_value("shift y",0);
    this->parameters->set_int_value("frequency",6);
    this->parameters->set_bool_value("flip horizontal",false);
    this->parameters->set_bool_value("flip vertical",false);
    this->parameters->set_int_value("angle",0);
  }

//----------------------------------------------------------------------

void c_block_voronoi_diagram::set_default()

  {
    this->name = VORONOI_DIAGRAM_NAME;
    this->min_inputs = 0;
    this->max_inputs = 1;

    this->parameters->add_parameter("type",PARAMETER_INT);
    this->parameters->add_parameter("metric",PARAMETER_INT);
    this->parameters->add_parameter("point place",PARAMETER_INT);
    this->parameters->add_parameter("width",PARAMETER_INT);
    this->parameters->add_parameter("point positions",PARAMETER_STRING);
    this->parameters->add_parameter("number of points",PARAMETER_INT);
    this->parameters->add_parameter("initial x",PARAMETER_DOUBLE);
    this->parameters->add_parameter("initial y",PARAMETER_DOUBLE);
    this->parameters->add_parameter("initial angle",PARAMETER_INT);

    this->parameters->set_int_value("type",VORONOI_2_NEAREST_RATIO);
    this->parameters->set_int_value("metric",METRIC_EUCLIDEAN);
    this->parameters->set_int_value("point place",PLACE_RANDOM);
    this->parameters->set_int_value("width",75);
    this->parameters->set_string_value("point positions",(char *) "");
    this->parameters->set_int_value("number of points",15);
    this->parameters->set_double_value("initial x",0.5);
    this->parameters->set_double_value("initial y",0.5);
    this->parameters->set_int_value("initial angle",90);
  }

//----------------------------------------------------------------------

void c_block_replace_colors::set_default()

  {
    this->name = REPLACE_COLORS_NAME;
    this->min_inputs = 0;
    this->max_inputs = 5;

    this->parameters->add_parameter("color 1 red",PARAMETER_INT);
    this->parameters->add_parameter("color 1 green",PARAMETER_INT);
    this->parameters->add_parameter("color 1 blue",PARAMETER_INT);
    this->parameters->add_parameter("color 2 red",PARAMETER_INT);
    this->parameters->add_parameter("color 2 green",PARAMETER_INT);
    this->parameters->add_parameter("color 2 blue",PARAMETER_INT);
    this->parameters->add_parameter("color 3 red",PARAMETER_INT);
    this->parameters->add_parameter("color 3 green",PARAMETER_INT);
    this->parameters->add_parameter("color 3 blue",PARAMETER_INT);
    this->parameters->add_parameter("color 4 red",PARAMETER_INT);
    this->parameters->add_parameter("color 4 green",PARAMETER_INT);
    this->parameters->add_parameter("color 4 blue",PARAMETER_INT);

    this->parameters->set_int_value("color 1 red",255);
    this->parameters->set_int_value("color 1 green",255);
    this->parameters->set_int_value("color 1 blue",255);
    this->parameters->set_int_value("color 2 red",0);
    this->parameters->set_int_value("color 2 green",0);
    this->parameters->set_int_value("color 2 blue",0);
    this->parameters->set_int_value("color 3 red",170);
    this->parameters->set_int_value("color 3 green",170);
    this->parameters->set_int_value("color 3 blue",170);
    this->parameters->set_int_value("color 4 red",85);
    this->parameters->set_int_value("color 4 green",85);
    this->parameters->set_int_value("color 4 blue",85);
  }

//----------------------------------------------------------------------

void c_block_color_fill::set_default()

  {
    this->name = COLOR_FILL_NAME;
    this->min_inputs = 0;
    this->max_inputs = 0;

    this->parameters->add_parameter("red",PARAMETER_INT);
    this->parameters->add_parameter("green",PARAMETER_INT);
    this->parameters->add_parameter("blue",PARAMETER_INT);

    this->parameters->set_int_value("red",255);
    this->parameters->set_int_value("green",255);
    this->parameters->set_int_value("blue",255);
  }

//----------------------------------------------------------------------

void c_block_convolution::set_default()

  {
    this->name = CONVOLUTION_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("matrix width",PARAMETER_INT);
    this->parameters->add_parameter("matrix height",PARAMETER_INT);
    this->parameters->add_parameter("matrix data",PARAMETER_STRING);

    this->parameters->set_int_value("matrix width",3);
    this->parameters->set_int_value("matrix height",3);
    this->parameters->set_string_value("matrix data",(char *)
      "0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0");
  }

//----------------------------------------------------------------------

void c_block_sharpen::set_default()

  {
    this->name = SHARPEN_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("intensity",PARAMETER_INT);
    this->parameters->set_int_value("intensity",3);
  }

//----------------------------------------------------------------------

void c_block_emboss::set_default()

  {
    this->name = EMBOSS_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("intensity",PARAMETER_INT);
    this->parameters->set_int_value("intensity",3);
  }

//----------------------------------------------------------------------

void c_block_blur::set_default()

  {
    this->name = BLUR_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("intensity",PARAMETER_INT);
    this->parameters->add_parameter("motion",PARAMETER_BOOL);
    this->parameters->add_parameter("direction",PARAMETER_INT);

    this->parameters->set_int_value("intensity",10);
    this->parameters->set_bool_value("motion",false);
    this->parameters->set_int_value("direction",DIRECTION_HORIZONTAL);
  }

//----------------------------------------------------------------------

void c_block_edge_detection::set_default()

  {
    this->name = EDGE_DETECTION_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("intensity",PARAMETER_INT);
    this->parameters->add_parameter("type",PARAMETER_INT);

    this->parameters->set_int_value("intensity",3);
    this->parameters->set_int_value("type",DETECTION_BOTH);
  }

//----------------------------------------------------------------------

void c_block_tile::set_default()

  {
    this->name = TILE_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("times",PARAMETER_INT);
    this->parameters->set_int_value("times",2);
  }

//----------------------------------------------------------------------

void c_block_simple_noise::set_default()

  {
    this->name = SIMPLE_NOISE_NAME;
    this->min_inputs = 0;
    this->max_inputs = 0;

    this->parameters->add_parameter("amplitude",PARAMETER_INT);
    this->parameters->add_parameter("grayscale",PARAMETER_BOOL);

    this->parameters->set_int_value("amplitude",127);
    this->parameters->set_bool_value("grayscale",true);
  }

//----------------------------------------------------------------------

void c_block_square_mosaic::set_default()

  {
    this->name = SQUARE_MOSAIC_NAME;
    this->min_inputs = 0;
    this->max_inputs = 0;

    this->parameters->add_parameter("side 1",PARAMETER_STRING);
    this->parameters->add_parameter("side 2",PARAMETER_STRING);
    this->parameters->add_parameter("side 3",PARAMETER_STRING);
    this->parameters->add_parameter("side 4",PARAMETER_STRING);
    this->parameters->add_parameter("transformation 1",PARAMETER_INT);
    this->parameters->add_parameter("transformation 2",PARAMETER_INT);
    this->parameters->add_parameter("transformation 3",PARAMETER_INT);
    this->parameters->add_parameter("transformation 4",PARAMETER_INT);
    this->parameters->add_parameter("tiles x",PARAMETER_INT);
    this->parameters->add_parameter("tiles y",PARAMETER_INT);
    this->parameters->add_parameter("fill type",PARAMETER_INT);
    this->parameters->add_parameter("fill colors",PARAMETER_STRING);

    this->parameters->set_string_value("side 1",
      (char *) "0.1 0.1 0.2 0.15 0.3 0.20 0.4 0.15 0.5 0.0");
    this->parameters->set_string_value("side 2",
      (char *) "0.5 0.1");
    this->parameters->set_string_value("side 3",
      (char *) "0.19 0.0 0.2 0.2 0.4 0.2 0.41 0.0");
    this->parameters->set_string_value("side 4",
      (char *) "");

    this->parameters->set_int_value("transformation 1",
      MOSAIC_TRANSFORM_ROTATE_SIDE);
    this->parameters->set_int_value("transformation 2",
      MOSAIC_TRANSFORM_SHIFT);
    this->parameters->set_int_value("transformation 3",
      MOSAIC_TRANSFORM_ROTATE_SIDE);
    this->parameters->set_int_value("transformation 4",
      MOSAIC_TRANSFORM_SHIFT);

    this->parameters->set_int_value("tiles x",2);
    this->parameters->set_int_value("tiles y",2);
    this->parameters->set_int_value("fill type",FILL_NO_BORDERS);
    this->parameters->set_string_value("fill colors",
      (char *) "255,0,0,255");
  }

//----------------------------------------------------------------------

void c_block_turtle::set_default()

  {
    this->name = TURTLE_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("initial x",PARAMETER_DOUBLE);
    this->parameters->add_parameter("initial y",PARAMETER_DOUBLE);
    this->parameters->add_parameter("initial angle",PARAMETER_INT);
    this->parameters->add_parameter("noise intensity",PARAMETER_DOUBLE);
    this->parameters->add_parameter("particle density",
      PARAMETER_DOUBLE);

    this->parameters->set_double_value("initial x",0.5);
    this->parameters->set_double_value("initial y",0.5);
    this->parameters->set_int_value("initial angle",90);
    this->parameters->set_double_value("noise intensity",1.0);
    this->parameters->set_double_value("particle density",1.0);
  }

//----------------------------------------------------------------------

void c_block_file_save::set_default()

  {
    this->name = FILE_SAVE_NAME;
    this->is_end_block = true;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("path",PARAMETER_STRING);
    this->parameters->set_string_value("path",(char *) "texture.png");
  }

//----------------------------------------------------------------------

void c_block_file_load::set_default()

  {
    this->name = FILE_LOAD_NAME;
    this->min_inputs = 0;
    this->max_inputs = 0;

    this->parameters->add_parameter("path",PARAMETER_STRING);
    this->parameters->add_parameter("interpolation",PARAMETER_INT);

    this->parameters->set_string_value("path",(char *) "image.png");
    this->parameters->set_int_value("interpolation",
      INTERPOLATION_LINEAR);
  }

//----------------------------------------------------------------------

void c_block_hsl::set_default()

  {
    this->name = HSL_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("hue",PARAMETER_DOUBLE);
    this->parameters->add_parameter("saturation",PARAMETER_DOUBLE);
    this->parameters->add_parameter("lightness",PARAMETER_DOUBLE);

    this->parameters->set_double_value("hue",0.0);
    this->parameters->set_double_value("saturation",0.0);
    this->parameters->set_double_value("lightness",0.0);
  }

//----------------------------------------------------------------------

void c_block_rgb::set_default()

  {
    this->name = RGB_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("red",PARAMETER_INT);
    this->parameters->add_parameter("green",PARAMETER_INT);
    this->parameters->add_parameter("blue",PARAMETER_INT);

    this->parameters->set_int_value("red",0);
    this->parameters->set_int_value("green",0);
    this->parameters->set_int_value("blue",0);
  }

//----------------------------------------------------------------------

void c_block_fault_formation_noise::set_default()

  {
    this->name = FAULT_FORMATION_NOISE_NAME;
    this->min_inputs = 0;
    this->max_inputs = 0;
  }

//----------------------------------------------------------------------

void c_block_end::set_default()

  {
    this->name = END_BLOCK_NAME;
    this->is_end_block = true;
    this->min_inputs = 1;
    this->max_inputs = 1;
  }

//----------------------------------------------------------------------

void c_block_bump_noise::set_default()

  {
    this->name = BUMP_NOISE_NAME;
    this->min_inputs = 0;
    this->max_inputs = 0;

    this->parameters->add_parameter("bump size from",PARAMETER_DOUBLE);
    this->parameters->add_parameter("bump size to",PARAMETER_DOUBLE);
    this->parameters->add_parameter("quantity",PARAMETER_INT);
    this->parameters->add_parameter("alter amplitude",PARAMETER_BOOL);

    this->parameters->set_double_value("bump size from",0.7);
    this->parameters->set_double_value("bump size to",0.01);
    this->parameters->set_int_value("quantity",1);
    this->parameters->set_bool_value("alter amplitude",false);
  }

//----------------------------------------------------------------------

void c_block_sine_transform::set_default()

  {
    this->name = SINE_TRANSFORM_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("phase",PARAMETER_DOUBLE);
    this->parameters->add_parameter("periods",PARAMETER_INT);
    this->parameters->add_parameter("amplitude",PARAMETER_INT);

    this->parameters->set_double_value("phase",0.0);
    this->parameters->set_int_value("periods",5);
    this->parameters->set_int_value("amplitude",127);
  }

//----------------------------------------------------------------------

void c_block_mix_channels::set_default()

  {
    this->name = MIX_CHANNELS_NAME;
    this->min_inputs = 3;
    this->max_inputs = 3;
  }

//----------------------------------------------------------------------

void c_block_substrate::set_default()

  {
    this->name = SUBSTRATE_NAME;
    this->min_inputs = 0;
    this->max_inputs = 0;

    this->parameters->add_parameter("number of iterations",
      PARAMETER_INT);
    this->parameters->add_parameter("number of lines",PARAMETER_INT);
    this->parameters->add_parameter("fill type",PARAMETER_INT);
    this->parameters->add_parameter("grayscale",PARAMETER_BOOL);
    this->parameters->add_parameter("iterate",PARAMETER_BOOL);

    this->parameters->set_int_value("number of iterations",10);
    this->parameters->set_int_value("number of lines",10);
    this->parameters->set_int_value("fill type",
      (int) FILL_KEEP_BORDERS);
    this->parameters->set_bool_value("grayscale",false);
    this->parameters->set_bool_value("iterate",true);
  }

//----------------------------------------------------------------------

void c_block_mix::set_default()

  {
    this->name = MIX_NAME;
    this->min_inputs = 2;
    this->max_inputs = 3;

    this->parameters->add_parameter("percentage",PARAMETER_INT);
    this->parameters->add_parameter("method",PARAMETER_INT);

    this->parameters->set_int_value("percentage",50);
    this->parameters->set_int_value("method",MIX_AVERAGE);
  }

//----------------------------------------------------------------------

void c_block_marble::set_default()

  {
    this->name = MARBLE_NAME;
    this->min_inputs = 0;
    this->max_inputs = 1;

    this->parameters->add_parameter("periods",PARAMETER_INT);
    this->parameters->add_parameter("intensity",PARAMETER_INT);
    this->parameters->add_parameter("amplitude",PARAMETER_INT);
    this->parameters->add_parameter("direction",PARAMETER_INT);

    this->parameters->set_int_value("periods",5);
    this->parameters->set_int_value("intensity",4);
    this->parameters->set_int_value("amplitude",127);
    this->parameters->set_int_value("direction",DIRECTION_HORIZONTAL);
  }

//----------------------------------------------------------------------

void c_block_wood::set_default()

  {
    this->name = WOOD_NAME;
    this->min_inputs = 0;
    this->max_inputs = 1;

    this->parameters->add_parameter("circles",PARAMETER_INT);
    this->parameters->add_parameter("hardness",PARAMETER_INT);
    this->parameters->add_parameter("intensity",PARAMETER_INT);
    this->parameters->add_parameter("amplitude",PARAMETER_INT);
    this->parameters->add_parameter("direction",PARAMETER_INT);

    this->parameters->set_int_value("circles",4);
    this->parameters->set_int_value("hardness",8);
    this->parameters->set_int_value("intensity",20);
    this->parameters->set_int_value("amplitude",127);
    this->parameters->set_int_value("direction",DIRECTION_HORIZONTAL);
  }

//----------------------------------------------------------------------

void c_block_particles::set_default()

  {
    this->name = PARTICLES_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("particles",PARAMETER_INT);
    this->parameters->add_parameter("initial x",PARAMETER_DOUBLE);
    this->parameters->add_parameter("initial y",PARAMETER_DOUBLE);
    this->parameters->add_parameter("angle",PARAMETER_INT);
    this->parameters->add_parameter("spread",PARAMETER_INT);
    this->parameters->add_parameter("initial velocity",
      PARAMETER_DOUBLE);

    this->parameters->set_int_value("particles",500);
    this->parameters->set_double_value("initial x",0.5);
    this->parameters->set_double_value("initial y",0.5);
    this->parameters->set_int_value("angle",0);
    this->parameters->set_int_value("spread",360);
    this->parameters->set_double_value("initial velocity",5);
  }

//----------------------------------------------------------------------

void c_block_circle_transform::set_default()

  {
    this->name = CIRCLE_TRANSFORM_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("radius",PARAMETER_INT);
    this->parameters->add_parameter("jumps",PARAMETER_INT);

    this->parameters->set_int_value("radius",5);
    this->parameters->set_int_value("jumps",1);
  }

//----------------------------------------------------------------------

void c_block_radius_transform::set_default()

  {
    this->name = RADIUS_TRANSFORM_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("radius min",PARAMETER_INT);
    this->parameters->add_parameter("radius max",PARAMETER_INT);
    this->parameters->add_parameter("rotate left",PARAMETER_BOOL);
    this->parameters->add_parameter("horizontal",PARAMETER_BOOL);

    this->parameters->set_int_value("radius min",1);
    this->parameters->set_int_value("radius max",20);
    this->parameters->set_bool_value("rotate left",true);
    this->parameters->set_bool_value("horizontal",true);
  }

//----------------------------------------------------------------------

void c_block_invert::set_default()

  {
    this->name = INVERT_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;
  }

//----------------------------------------------------------------------

void c_block_dither::set_default()

  {
    this->name = DITHER_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("levels",PARAMETER_INT);
    this->parameters->add_parameter("method",PARAMETER_INT);

    this->parameters->set_int_value("levels",8);
    this->parameters->set_int_value("method",DITHERING_ORDERED);
  }

//----------------------------------------------------------------------

void c_block_crop_amplitude::set_default()

  {
    this->name = CROP_AMPLITUDE_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("lower limit",PARAMETER_INT);
    this->parameters->add_parameter("upper limit",PARAMETER_INT);

    this->parameters->set_int_value("lower limit",50);
    this->parameters->set_int_value("upper limit",200);
  }

//----------------------------------------------------------------------

void c_block_normal_map::set_default()

  {
    this->name = NORMAL_MAP_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("neighbourhood size",PARAMETER_INT);
    this->parameters->set_int_value("neighbourhood size",5);
  }

//----------------------------------------------------------------------

void c_block_glass::set_default()

  {
    this->name = GLASS_NAME;
    this->min_inputs = 2;
    this->max_inputs = 2;

    this->parameters->add_parameter("height",PARAMETER_DOUBLE);
    this->parameters->set_double_value("height",1.0);
  }

//----------------------------------------------------------------------

void c_block_cellular_automaton_rps::set_default()

  {
    this->name = CELLULAR_RPS_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("iterations",PARAMETER_INT);
    this->parameters->add_parameter("neighbourhood",PARAMETER_INT);
    this->parameters->add_parameter("neighbourhood size",PARAMETER_INT);
    this->parameters->add_parameter("players",PARAMETER_INT);

    this->parameters->set_int_value("iterations",50);
    this->parameters->set_int_value("neighbourhood",
      NEIGHBOURHOOD_MOORE);
    this->parameters->set_int_value("neighbourhood size",5);
    this->parameters->set_int_value("players",3);
  }

//----------------------------------------------------------------------

void c_block_cellular_automaton_cyclic::set_default()

  {
    this->name = CELLULAR_CYCLIC_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("iterations",PARAMETER_INT);
    this->parameters->add_parameter("neighbourhood",PARAMETER_INT);
    this->parameters->add_parameter("neighbourhood size",PARAMETER_INT);
    this->parameters->add_parameter("states",PARAMETER_INT);
    this->parameters->add_parameter("threshold",PARAMETER_INT);

    this->parameters->set_int_value("iterations",30);
    this->parameters->set_int_value("neighbourhood",
      NEIGHBOURHOOD_VON_NEUMANN);
    this->parameters->set_int_value("neighbourhood size",2);
    this->parameters->set_int_value("states",6);
    this->parameters->set_int_value("threshold",2);
  }

//----------------------------------------------------------------------

void c_block_cellular_automaton_general::set_default()

  {
    this->name = CELLULAR_GENERAL_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("iterations",PARAMETER_INT);
    this->parameters->add_parameter("rules",PARAMETER_STRING);
    this->parameters->add_parameter("states",PARAMETER_INT);

    this->parameters->set_int_value("iterations",20);
    this->parameters->set_string_value("rules",(char *) "");
    this->parameters->set_int_value("states",2);
  }

//----------------------------------------------------------------------

void c_block_brightness_contrast::set_default()

  {
    this->name = BRIGHTNESS_CONTRAST_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("brightness",PARAMETER_DOUBLE);
    this->parameters->add_parameter("contrast",PARAMETER_DOUBLE);

    this->parameters->set_double_value("brightness",0.0);
    this->parameters->set_double_value("contrast",0.0);
  }

//----------------------------------------------------------------------

void c_block_grayscale::set_default()

  {
    this->name = GRAYSCALE_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;
  }

//----------------------------------------------------------------------

void c_block_color_transition::set_default()

  {
    this->name = COLOR_TRANSITION_NAME;
    this->min_inputs = 0;
    this->max_inputs = 0;

    this->parameters->add_parameter("data",PARAMETER_STRING);
    this->parameters->set_string_value("data",(char *)
      "0 0 0 0;255 255 255 255;");
  }

//----------------------------------------------------------------------

void c_block_l_system::set_default()

  {
    this->name = L_SYSTEM_NAME;
    this->min_inputs = 0;
    this->max_inputs = 0;

    this->parameters->add_parameter("path",PARAMETER_STRING);
    this->parameters->add_parameter("iterations",PARAMETER_INT);

    this->parameters->set_string_value("path",
      (char *) "grammar.txt");
    this->parameters->set_int_value("iterations",10);
  }

//----------------------------------------------------------------------

void c_block_map_transition::set_default()

  {
    this->name = MAP_TRANSITION_NAME;
    this->min_inputs = 2;
    this->max_inputs = 2;
  }

//----------------------------------------------------------------------

void c_block_light::set_default()

  {
    this->name = LIGHT_NAME;
    this->min_inputs = 1;
    this->max_inputs = 1;

    this->parameters->add_parameter("ambient red",PARAMETER_INT);
    this->parameters->add_parameter("ambient green",PARAMETER_INT);
    this->parameters->add_parameter("ambient blue",PARAMETER_INT);

    this->parameters->add_parameter("diffuse red",PARAMETER_INT);
    this->parameters->add_parameter("diffuse green",PARAMETER_INT);
    this->parameters->add_parameter("diffuse blue",PARAMETER_INT);

    this->parameters->add_parameter("specular red",PARAMETER_INT);
    this->parameters->add_parameter("specular green",PARAMETER_INT);
    this->parameters->add_parameter("specular blue",PARAMETER_INT);

    this->parameters->add_parameter("reflection curve",PARAMETER_INT);
    this->parameters->add_parameter("viewer height",PARAMETER_DOUBLE);
    this->parameters->add_parameter("phong exponent",PARAMETER_DOUBLE);
    this->parameters->add_parameter("direction vector x",
      PARAMETER_DOUBLE);
    this->parameters->add_parameter("direction vector y",
      PARAMETER_DOUBLE);

    this->parameters->set_int_value("ambient red",5);
    this->parameters->set_int_value("ambient green",0);
    this->parameters->set_int_value("ambient blue",10);

    this->parameters->set_int_value("diffuse red",150);
    this->parameters->set_int_value("diffuse green",100);
    this->parameters->set_int_value("diffuse blue",100);

    this->parameters->set_int_value("specular red",255);
    this->parameters->set_int_value("specular green",245);
    this->parameters->set_int_value("specular blue",240);

    this->parameters->set_int_value("reflection curve",
      REFLECTION_CURVE_COSINE_ABS);
    this->parameters->set_double_value("viewer height",1.0);
    this->parameters->set_double_value("phong exponent",2.0);
    this->parameters->set_double_value("direction vector x",0.5);
    this->parameters->set_double_value("direction vector y",0.5);
  }

//======================================================================
// 'EXECUTE' FUNCTIONS:
//======================================================================

bool c_block_light::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_destroy(&(this->buffer));

    pt_light(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer),
      this->parameters->get_int_value("ambient red"),
      this->parameters->get_int_value("ambient green"),
      this->parameters->get_int_value("ambient blue"),
      this->parameters->get_int_value("diffuse red"),
      this->parameters->get_int_value("diffuse green"),
      this->parameters->get_int_value("diffuse blue"),
      this->parameters->get_int_value("specular red"),
      this->parameters->get_int_value("specular green"),
      this->parameters->get_int_value("specular blue"),
      this->parameters->get_double_value("phong exponent"),
      (t_reflection_curve)
        this->parameters->get_int_value("reflection curve"),
      this->parameters->get_double_value("viewer height"),
      this->parameters->get_double_value("direction vector x"),
      this->parameters->get_double_value("direction vector y"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_geometric_transform::execute()

  {
    int angle;

    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer));

    angle = this->parameters->get_int_value("angle");

    if (angle != 0)
      pt_rotate(
        &(this->buffer),
        degrees_to_radians(angle));

    pt_shift(
      &(this->buffer),
      this->parameters->get_double_value("shift x") * this->buffer.width,
      this->parameters->get_double_value("shift y") * this->buffer.height);

    if (this->parameters->get_bool_value("flip horizontal"))
      pt_flip(
        &(this->buffer),
        DIRECTION_HORIZONTAL);

    if (this->parameters->get_bool_value("flip vertical"))
      pt_flip(
        &(this->buffer),
        DIRECTION_VERTICAL);

    return true;
  }

//----------------------------------------------------------------------

bool c_block_map_transition::execute()

  {
    if (
      !this->is_graphic_input(0) ||
      this->input_blocks[1] == NULL ||
      this->input_blocks[1]->get_name().compare("color transition")
      != 0)
      return false;

    color_buffer_copy_data(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer));

    pt_map_to_transition(&(this->buffer),
      ((c_block_color_transition *) this->input_blocks[1])->get_color_transition());

    return true;
  }

//----------------------------------------------------------------------

bool c_block_edge_detection::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer));

    pt_edge_detection(
      &(this->buffer),
      (t_edge_detection_type) this->parameters->get_int_value("type"),
      this->parameters->get_int_value("intensity"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_convolution::execute()

  {
    t_matrix matrix;
    double number_buffer[256];
    unsigned int length,i,j,position;
    int width,height;

    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer));

    width =
      saturate_int(this->parameters->get_int_value("matrix width"),1,16);
    height =
      saturate_int(this->parameters->get_int_value("matrix height"),1,16);

    matrix_init(&matrix,width,height);

    c_texture_graph::string_to_double_array(
      number_buffer,
      this->parameters->get_string_value("matrix data"),
      &length,
      256);

    position = 0;

    for (j = 0; j < matrix.height; j++)
      for (i = 0; i < matrix.width; i++)
        {
          matrix_set_value(&matrix,i,j,number_buffer[position]);
          position++;
        }

    pt_convolution(&(this->buffer),&matrix);

    matrix_destroy(&matrix);

    return true;
  }

//----------------------------------------------------------------------

bool c_block_tile::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_destroy(&(this->buffer));

    pt_tile(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      this->parameters->get_int_value("times"),
      &(this->buffer));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_replace_colors::execute()

  {
    unsigned int i;
    t_color_buffer *buffers[4];
    unsigned char colors[4][3];

    if (!this->is_graphic_input(0))
      return false;

    for (i = 1; i < 5; i++)
      if (this->is_graphic_input(i))
        {
          buffers[i - 1] = ((c_graphic_block *)
            this->input_blocks[i])->get_color_buffer();
        }
      else
        {
          buffers[i - 1] = NULL;
        }

    color_buffer_copy_data(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer));

    colors[0][0] = this->parameters->get_int_value("color 1 red");
    colors[0][1] = this->parameters->get_int_value("color 1 green");
    colors[0][2] = this->parameters->get_int_value("color 1 blue");
    colors[1][0] = this->parameters->get_int_value("color 2 red");
    colors[1][1] = this->parameters->get_int_value("color 2 green");
    colors[1][2] = this->parameters->get_int_value("color 2 blue");
    colors[2][0] = this->parameters->get_int_value("color 3 red");
    colors[2][1] = this->parameters->get_int_value("color 3 green");
    colors[2][2] = this->parameters->get_int_value("color 3 blue");
    colors[3][0] = this->parameters->get_int_value("color 4 red");
    colors[3][1] = this->parameters->get_int_value("color 4 green");
    colors[3][2] = this->parameters->get_int_value("color 4 blue");

    pt_replace_colors(&(this->buffer),colors,buffers,5);

    return true;
  }

//----------------------------------------------------------------------

bool c_block_normal_map::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_destroy(&(this->buffer));

    pt_normal_map(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      this->parameters->get_int_value("neighbourhood size"),
      &(this->buffer));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_blur::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer));

    if (this->parameters->get_bool_value("motion"))
      pt_motion_blur(
        &(this->buffer),
        (t_direction) this->parameters->get_int_value("direction"),
        this->parameters->get_int_value("intensity"));
    else
      pt_blur(
        &(this->buffer),
        this->parameters->get_int_value("intensity"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_sharpen::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer));

    pt_sharpen(
      &(this->buffer),
      this->parameters->get_int_value("intensity"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_emboss::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer));

    pt_emboss(
      &(this->buffer),
      this->parameters->get_int_value("intensity"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_cellular_automaton_rps::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer));

    pt_cellular_automaton_rps(
      &(this->buffer),
      (t_neighbourhood_type)
        this->parameters->get_int_value("neighbourhood"),
      this->parameters->get_int_value("neighbourhood size"),
      this->parameters->get_int_value("players"),
      this->get_random_seed(),
      this->parameters->get_int_value("iterations"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_cellular_automaton_cyclic::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer));

    pt_cellular_automaton_cyclic(
      &(this->buffer),
      (t_neighbourhood_type)
        this->parameters->get_int_value("neighbourhood"),
      this->parameters->get_int_value("neighbourhood size"),
      this->parameters->get_int_value("states"),
      this->parameters->get_int_value("threshold"),
      this->parameters->get_int_value("iterations"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_cellular_automaton_general::execute()

  {
    int rules[256];
    unsigned char rules_char[256];
    unsigned int length, i;

    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer));

    c_texture_graph::string_to_char_array(
      rules_char,
      this->parameters->get_string_value("rules"),
      &length,
      256);

    for (i = 0; i < length; i++)  // convert char array to int array
      {
        rules[i] = ((char) rules_char[i]);
        cout << rules[i] << endl;
      }

    pt_cellular_automaton_general(
      &(this->buffer),
      this->parameters->get_int_value("states"),
      rules,
      this->parameters->get_int_value("iterations"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_simple_noise::execute()

  {
    pt_simple_noise(
      this->get_random_seed(),
      this->parameters->get_int_value("amplitude"),
      this->parameters->get_bool_value("grayscale"),
      &(this->buffer));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_color_transition::execute()

  {
    color_transition_from_string(&(this->transition),
      (char *) this->parameters->get_string_value("data").c_str());

    return true;
  }

//----------------------------------------------------------------------

bool c_block_l_system::execute()

  {
    grammar_destroy(&(this->grammar));

    if(!grammar_load_from_file(&(this->grammar),
      (char *) this->parameters->get_string_value("path").c_str(),
      this->get_random_seed()))
      return false;

    grammar_generate_string(
      &(this->grammar),
      this->parameters->get_int_value("iterations"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_square_mosaic::execute()

  {
    t_square_mosaic mosaic;
    unsigned char fill_colors[256];
    unsigned int array_length;

    // specify the mosaic:

    mosaic.side_shape[0] =
      (char *) this->parameters->get_string_value("side 1").c_str();
    mosaic.side_shape[1] =
      (char *) this->parameters->get_string_value("side 2").c_str();
    mosaic.side_shape[2] =
      (char *) this->parameters->get_string_value("side 3").c_str();
    mosaic.side_shape[3] =
      (char *) this->parameters->get_string_value("side 4").c_str();

    mosaic.transformation[0] = (t_mosaic_transformation)
      this->parameters->get_int_value("transformation 1");
    mosaic.transformation[1] = (t_mosaic_transformation)
      this->parameters->get_int_value("transformation 2");
    mosaic.transformation[2] = (t_mosaic_transformation)
      this->parameters->get_int_value("transformation 3");
    mosaic.transformation[3] = (t_mosaic_transformation)
      this->parameters->get_int_value("transformation 4");

    mosaic.tiles_x = this->parameters->get_int_value("tiles x");
    mosaic.tiles_y = this->parameters->get_int_value("tiles y");

    // check the mosaic validity:

    if (!square_mosaic_is_valid(&mosaic))
      return false;

    c_texture_graph::string_to_char_array(
      fill_colors,
      this->parameters->get_string_value("fill colors"),
      &array_length,
      256);

    pt_mosaic_square(
      &(this->buffer),
      (t_fill_type) this->parameters->get_int_value("fill type"),
      fill_colors,
      array_length,
      &mosaic);

    return true;
  }

//----------------------------------------------------------------------

bool c_block_glass::execute()

  {
    if (!this->is_graphic_input(0) || !this->is_graphic_input(1))
      return false;

    color_buffer_destroy(&(this->buffer));

    pt_glass(
      ((c_graphic_block *) this->input_blocks[1])->get_color_buffer(),
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer),
      this->parameters->get_double_value("height"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_grayscale::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer));

    pt_grayscale(&(this->buffer));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_crop_amplitude::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer));

    pt_crop_amplitude(
      &(this->buffer),
      this->parameters->get_int_value("lower limit"),
      this->parameters->get_int_value("upper limit"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_turtle::execute()

  {
    if (this->input_blocks[0] == NULL ||
      this->input_blocks[0]->get_name().compare(L_SYSTEM_NAME) != 0)
      return false;

    pt_turtle_draw(
      &(this->buffer),
      ((c_block_l_system *) this->input_blocks[0])->get_grammar(),
      this->parameters->get_double_value("initial x"),
      this->parameters->get_double_value("initial y"),
      this->parameters->get_int_value("initial angle"),
      this->parameters->get_double_value("noise intensity"),
      this->parameters->get_double_value("particle density"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_dither::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer));

    pt_dithering(
      &(this->buffer),
      this->parameters->get_int_value("levels"),
      (t_dithering_method) this->parameters->get_int_value("method"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_invert::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      &(this->buffer));

    pt_invert_colors(&(this->buffer));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_sine_transform::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_destroy(&(this->buffer));

    pt_transformation_sine(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      this->parameters->get_double_value("phase"),
      this->parameters->get_int_value("periods"),
      this->parameters->get_int_value("amplitude"),
      &(this->buffer));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_circle_transform::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_destroy(&(this->buffer));

    pt_transformation_circle(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      this->parameters->get_int_value("radius"),
      this->parameters->get_int_value("jumps"),
      &(this->buffer));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_radius_transform::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_destroy(&(this->buffer));

    pt_transformation_radius(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      this->parameters->get_int_value("radius min"),
      this->parameters->get_int_value("radius max"),
      this->parameters->get_bool_value("rotate left"),
      this->parameters->get_bool_value("horizontal"),
      &(this->buffer));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_wood::execute()

  {
    t_color_buffer *noise_buffer;

    if (this->is_graphic_input(0))
      noise_buffer =
        ((c_graphic_block *) this->input_blocks[0])->get_color_buffer();
    else
      noise_buffer = NULL;

    pt_wood(
      this->get_random_seed(),
      this->parameters->get_int_value("circles"),
      this->parameters->get_int_value("hardness"),
      this->parameters->get_int_value("intensity"),
      (t_direction) this->parameters->get_int_value("direction"),
      this->parameters->get_int_value("amplitude"),
      &(this->buffer),
      noise_buffer);

    return true;
  }

//----------------------------------------------------------------------

bool c_block_particles::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_destroy(&(this->buffer));

    pt_particle_movement(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      this->parameters->get_int_value("particles"),
      this->parameters->get_double_value("initial x"),
      this->parameters->get_double_value("initial y"),
      this->parameters->get_int_value("angle"),
      this->parameters->get_int_value("spread"),
      this->parameters->get_double_value("initial velocity"),
      &(this->buffer));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_marble::execute()

  {
    t_color_buffer *noise_buffer;

    if (this->is_graphic_input(0))
      noise_buffer =
        ((c_graphic_block *) this->input_blocks[0])->get_color_buffer();
    else
      noise_buffer = NULL;

    pt_marble(
      this->get_random_seed(),
      this->parameters->get_int_value("periods"),
      this->parameters->get_int_value("intensity"),
      (t_direction) this->parameters->get_int_value("direction"),
      this->parameters->get_int_value("amplitude"),
      &(this->buffer),
      noise_buffer);

    return true;
  }

//----------------------------------------------------------------------

bool c_block_voronoi_diagram::execute()

  {
    unsigned int point_list[256][2];
    double double_list[256][2];
    unsigned int list_length;

    if (this->input_blocks[0] != NULL &&
      this->input_blocks[0]->get_name().compare(L_SYSTEM_NAME) == 0)
      {
        // placing points with l-system:

        pt_turtle_get_point_list(
          &(this->buffer),
          ((c_block_l_system *) this->input_blocks[0])->get_grammar(),
          this->parameters->get_double_value("initial x"),
          this->parameters->get_double_value("initial y"),
          this->parameters->get_int_value("initial angle"),
          point_list,
          &list_length,
          256);

        pt_voronoi_diagram(
          (t_voronoi_type) this->parameters->get_int_value("type"),
          (t_metric) this->parameters->get_int_value("metric"),
          PLACE_CUSTOM,
          list_length,
          0,
          point_list,
          &(this->buffer));
      }
    else
      switch (this->parameters->get_int_value("point place"))
        {
          case PLACE_RANDOM:
            pt_voronoi_diagram(
              (t_voronoi_type) this->parameters->get_int_value("type"),
              (t_metric) this->parameters->get_int_value("metric"),
              PLACE_RANDOM,
              this->get_random_seed(),
              this->parameters->get_int_value("number of points"),
              NULL,
              &(this->buffer));
            break;

          case PLACE_SQUARE:
          case PLACE_CIRCLE:
          case PLACE_CROSS_HORIZONTAL:
          case PLACE_CROSS_DIAGONAL:
            pt_voronoi_diagram(
              (t_voronoi_type) this->parameters->get_int_value("type"),
              (t_metric) this->parameters->get_int_value("metric"),
              (t_point_place_type) this->parameters->get_int_value("point place"),
              this->parameters->get_int_value("width"),
              this->parameters->get_int_value("number of points"),
              NULL,
              &(this->buffer));
            break;

          case PLACE_CUSTOM:
            c_texture_graph::string_to_coordinations(
              double_list,
              this->parameters->get_string_value("point positions"),
              &list_length,
              256);

            coord_array_double_to_int(point_list,double_list,
              list_length,this->buffer.width,this->buffer.height);

            pt_voronoi_diagram(
              (t_voronoi_type) this->parameters->get_int_value("type"),
              (t_metric) this->parameters->get_int_value("metric"),
              PLACE_CUSTOM,
              list_length,
              0,
              point_list,
              &(this->buffer));
            break;
        }

    return true;
  }

//----------------------------------------------------------------------

bool c_block_bump_noise::execute()

  {
    pt_bump_noise(&(this->buffer),
      this->parameters->get_double_value("bump size from"),
      this->parameters->get_double_value("bump size to"),
      this->parameters->get_int_value("quantity"),
      this->parameters->get_bool_value("alter amplitude"),
      this->get_random_seed());

    return true;
  }

//----------------------------------------------------------------------

bool c_block_mix::execute()

  {
    t_color_buffer *alpha_buffer;

    if (!this->is_graphic_input(0) || !this->is_graphic_input(1))
      return false;

    if (this->is_graphic_input(2))
      alpha_buffer =
        ((c_graphic_block *)this->input_blocks[2])->get_color_buffer();
    else
      alpha_buffer = NULL;

    color_buffer_destroy(&(this->buffer));

    pt_mix_buffers(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      ((c_graphic_block *) this->input_blocks[1])->get_color_buffer(),
      &(this->buffer),
      this->parameters->get_int_value("percentage"),
      (t_mix_type) this->parameters->get_int_value("method"),
      alpha_buffer);

    return true;
  }

//----------------------------------------------------------------------

bool c_block_fault_formation_noise::execute()

  {
    pt_fault_formation_noise(this->get_random_seed(),
      &(this->buffer));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_rgb::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(((c_graphic_block *)
      this->input_blocks[0])->get_color_buffer(),&(this->buffer));

    pt_add_rgb(&(this->buffer),
      this->parameters->get_int_value("red"),
      this->parameters->get_int_value("green"),
      this->parameters->get_int_value("blue"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_brightness_contrast::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(((c_graphic_block *)
      this->input_blocks[0])->get_color_buffer(),&(this->buffer));

    pt_add_brightness_contrast(
      &(this->buffer),
      this->parameters->get_double_value("brightness"),
      this->parameters->get_double_value("contrast"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_hsl::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    color_buffer_copy_data(((c_graphic_block *)
      this->input_blocks[0])->get_color_buffer(),&(this->buffer));

    pt_add_hsl(&(this->buffer),
      this->parameters->get_double_value("hue"),
      this->parameters->get_double_value("saturation"),
      this->parameters->get_double_value("lightness"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_perlin_noise::execute()

  {
    pt_perlin_noise(
      this->get_random_seed(),
      this->parameters->get_int_value("amplitude"),
      this->parameters->get_int_value("frequency"),
      this->parameters->get_int_value("max iterations"),
      (t_interpolation_method)
        this->parameters->get_int_value("interpolation"),
      &(this->buffer),
      this->parameters->get_bool_value("smooth"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_mix_channels::execute()

  {
    if (!this->is_graphic_input(0) || !this->is_graphic_input(1) ||
      !this->is_graphic_input(2))
      return false;

    color_buffer_destroy(&(this->buffer));

    pt_mix_channels(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      ((c_graphic_block *) this->input_blocks[1])->get_color_buffer(),
      ((c_graphic_block *) this->input_blocks[2])->get_color_buffer(),
      &this->buffer);

    return true;
  }

//----------------------------------------------------------------------

bool c_block_color_fill::execute()

  {
    pt_color_fill(&(this->buffer),
      this->parameters->get_int_value("red"),
      this->parameters->get_int_value("green"),
      this->parameters->get_int_value("blue"));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_file_save::execute()

  {
    t_color_buffer help_buffer;
    bool success;

    if (!this->is_graphic_input(0))
      return false;

    pt_supersampling(   // perform supersampling
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      this->graph->get_supersampling(),
      &help_buffer);

    success = true;

    if (!color_buffer_save_to_png(&help_buffer,
      ((char *) (this->parameters->get_string_value("path")).c_str())))
      {
        success = false;
      }

    color_buffer_destroy(&help_buffer);

    return success;
  }

//----------------------------------------------------------------------

bool c_block_end::execute()

  {
    if (!this->is_graphic_input(0))
      return false;

    pt_supersampling(
      ((c_graphic_block *) this->input_blocks[0])->get_color_buffer(),
      this->graph->get_supersampling(),
      &(this->buffer));

    return true;
  }

//----------------------------------------------------------------------

bool c_block_file_load::execute()

  {
    t_color_buffer help_buffer;

    if(!color_buffer_load_from_png(&help_buffer,
      (char *) this->parameters->get_string_value("path").c_str()))
      return false;

    pt_resize(&help_buffer,&(this->buffer),
      (t_interpolation_method)
      this->parameters->get_int_value("interpolation"));

    color_buffer_destroy(&help_buffer);

    return true;
  }

//----------------------------------------------------------------------

bool c_block_substrate::execute()

  {
    int number;

    if (this->parameters->get_bool_value("iterate"))
      number = this->parameters->get_int_value("number of iterations");
    else
      number = this->parameters->get_int_value("number of lines");

    if (number < 0)
      number = 0;

    pt_substrate(
      this->get_random_seed(),
      this->parameters->get_bool_value("iterate"),
      number,
      (t_fill_type) this->parameters->get_int_value("fill type"),
      this->parameters->get_bool_value("grayscale"),
      &(this->buffer));

    return true;
  }

//----------------------------------------------------------------------
