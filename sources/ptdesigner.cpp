//**********************************************************************
/** @file
 * Implementation of procedural textures block designer.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include "ptdesigner.h"
#include <fstream>
#include "rapidxml_print.hpp"

using namespace pt_design;

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

    for (i = 0; i < MAX_INPUT_BLOCKS; i++)
      {
        this->input_blocks[i] = NULL;
      }
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
    this->uses_global_seed = true;
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
    this->uses_global_seed = false;
    this->custom_seed = value;
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

    // make the id string:

    strncpy(this->id_string,to_string(this->id).c_str(),16);
  }

//----------------------------------------------------------------------

char *c_block::get_id_string()

  {
    return this->id_string;
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

c_graphic_block::c_graphic_block()

  {
    color_buffer_init(&(this->buffer),0,0);
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

bool c_block_color_fill::compute(bool force)

  {
    bool change_occured;

    change_occured = false;

    if (!this->valid || force)
      {
        pt_color_fill(&(this->buffer),
          this->parameters->get_int_value("red"),
          this->parameters->get_int_value("green"),
          this->parameters->get_int_value("blue"));
        change_occured = true;
      }

    this->valid = true;
    this->error = false;

    return change_occured;
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
        (char *) (this->parameters->get_string_value("path")).c_str()))
      {
        this->set_error();
        return change_occured;
      }

    return change_occured;
  }

//----------------------------------------------------------------------

void c_block_rgb::set_default()

  {
    this->name = "adjust rgb";
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
    if (!this->parameters->is_locked())
      {
        this->parameters->add_parameter("bump size from",PARAMETER_DOUBLE);
        this->parameters->add_parameter("bump size to",PARAMETER_DOUBLE);
        this->parameters->add_parameter("quantity",PARAMETER_INT);
        this->parameters->add_parameter("alter amplitude",PARAMETER_BOOL);
        this->name = "bump noise";
        this->parameters->lock();
      }

    this->parameters->set_double_value("bump size from",0.7);
    this->parameters->set_double_value("bump size to",0.01);
    this->parameters->set_int_value("quantity",1);
    this->parameters->set_bool_value("alter amplitude",false);
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

        pt_add_rgb(&(this->buffer),
          this->parameters->get_int_value("red"),
          this->parameters->get_int_value("green"),
          this->parameters->get_int_value("blue"));
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
        pt_perlin_noise(
          this->get_random_seed(),
          this->parameters->get_int_value("amplitude"),
          this->parameters->get_int_value("frequency"),
          this->parameters->get_int_value("max iterations"),
          (t_interpolation_method)
            this->parameters->get_int_value("interpolation"),
          &(this->buffer),
          this->parameters->get_bool_value("smooth"));

        change_occured = true;
      }

    this->valid = true;
    this->error = false;

    return change_occured;
  }

//----------------------------------------------------------------------

string c_parameters::get_value_string(unsigned int index)

  {
    if (index >= this->parameters->size())
      return "";

    switch (this->parameters->at(index).type)
      {
        case PARAMETER_INT:
          return to_string(this->parameters->at(index).int_value);
          break;

        case PARAMETER_DOUBLE:
          return to_string(this->parameters->at(index).double_value);
          break;

        case PARAMETER_BOOL:
          return to_string(this->parameters->at(index).bool_value);
          break;

        case PARAMETER_STRING:
          return this->parameters->at(index).string_value;
          break;
      }

    return "";
  }

//----------------------------------------------------------------------

bool c_block_bump_noise::compute(bool force)

  {
    bool change_occured;

    change_occured = false;

    if (force || !this->valid)
      {
        pt_bump_noise(&(this->buffer),
          this->parameters->get_double_value("bump size from"),
          this->parameters->get_double_value("bump size to"),
          this->parameters->get_int_value("quantity"),
          this->parameters->get_bool_value("alter amplitude"),
          this->get_random_seed());

        change_occured = true;
      }

    this->valid = true;
    this->error = false;

    return change_occured;
  }

//----------------------------------------------------------------------

bool c_texture_graph::load_from_file(string filename)

  {
    return true;
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
    string help_string;

    if (save_file.is_open())
      {
        node = document.allocate_node(node_element,"texturegraph");
        document.append_node(node);

        // append blocks:

        for (i = 0; i < this->blocks->size(); i++)
          {
            current_block = this->blocks->at(i);

            node = document.allocate_node(node_element,"block");

            // block element attributes:

            node->append_attribute(document.allocate_attribute("type",
              current_block->get_name().c_str()));

            node->append_attribute(document.allocate_attribute("id",
              current_block->get_id_string()));

            // input block elements:

            for (j = 0; j < MAX_INPUT_BLOCKS; j++)
              {
                help_block = current_block->get_input(j);

                if (help_block != NULL)
                  {
                    node2 =
                      document.allocate_node(node_element,"input");

                    node2->append_attribute(
                      document.allocate_attribute(
                        "id",help_block->get_id_string()));

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

            document.first_node()->append_node(node);

          }

        save_file << document;
        save_file.close();
      }
    else
      return false;

    return true;
  }

//----------------------------------------------------------------------

void c_block_color_fill::set_default()

  {
    if (!this->parameters->is_locked())
      {
        this->parameters->add_parameter("red",PARAMETER_INT);
        this->parameters->add_parameter("green",PARAMETER_INT);
        this->parameters->add_parameter("blue",PARAMETER_INT);
        this->name = "color fill";
        this->parameters->lock();
      }

    this->parameters->set_int_value("red",255);
    this->parameters->set_int_value("green",255);
    this->parameters->set_int_value("blue",255);
  }

//----------------------------------------------------------------------

void c_block_file_save::set_default()

  {
    if (!this->parameters->is_locked())
      {
        this->parameters->add_parameter("path",PARAMETER_STRING);
        this->name = "file save";
        this->parameters->lock();
      }

    this->parameters->set_string_value("path",(char *) "texture.txt");
  }

//----------------------------------------------------------------------
