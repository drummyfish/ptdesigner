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
    this->uses_global_seed = true;

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
    *x = this->resolution_x / this->supersampling_level;
    *y = this->resolution_y / this->supersampling_level;
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
    this->random_seed = 1;
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

void c_block_perlin_noise::set_default()

  {
    if (!this->parameters->is_locked())
      {
        this->parameters->add_parameter("amplitude",PARAMETER_INT);
        this->parameters->add_parameter("frequency",PARAMETER_INT);
        this->parameters->add_parameter("max iterations",PARAMETER_INT);
        this->parameters->add_parameter("interpolation",PARAMETER_INT);
        this->parameters->add_parameter("smooth",PARAMETER_BOOL);
        this->parameters->lock();
      }

    this->parameters->set_int_value("amplitude",127);
    this->parameters->set_int_value("frequency",6);
    this->parameters->set_int_value("max iterations",-1);
    this->parameters->set_int_value("interpolation",INTERPOLATION_LINEAR);
    this->parameters->set_bool_value("smooth",true);

    this->name = "perlin noise";
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

void c_texture_graph::set_supersampling(unsigned int level)

  {
    unsigned int base_resolution_x,base_resolution_y;

    if (level == 0)    // zero makes no sense
      level = 1;

    if (level > MAX_SUPERSAMPLING)
      level = MAX_SUPERSAMPLING;

    if (level == this->supersampling_level)
      return;    // no need to change anything

    // division by zero shouldn't occur
    base_resolution_x = this->resolution_x / this->supersampling_level;
    base_resolution_y = this->resolution_y / this->supersampling_level;

    this->supersampling_level = level;  // set the new level

    /* the image must be generated larger in order to perform
       supersampling => increase resolution: */

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

        resolution_x *= supersampling;
        resolution_y *= supersampling;
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

  /**
   * Private function - creates an instance of concrete c_block subclass
   * depending on provided string name of the block.
   *
   * @param block_name identifies which instance subclass instance
   *        should be created
   *
   * @return concrete newly allocated c_block subclass or NULL if the
   *         string does not identify any subclass
   */

c_block *get_block_instance(string block_name)

  {
    if (block_name.compare("file save") == 0)
      return new c_block_file_save();
    else if (block_name.compare("bump noise") == 0)
      return new c_block_bump_noise();
    else if (block_name.compare("color fill") == 0)
      return new c_block_color_fill();
    else if (block_name.compare("perlin noise") == 0)
      return new c_block_perlin_noise();
    else if (block_name.compare("mix channels") == 0)
      return new c_block_mix_channels();
    else if (block_name.compare("voronoi diagram") == 0)
      return new c_block_voronoi_diagram();
    else if (block_name.compare("fault formation noise") == 0)
      return new c_block_fault_formation_noise();
    else if (block_name.compare("substrate") == 0)
      return new c_block_substrate();
    else if (block_name.compare("mix") == 0)
      return new c_block_mix();
    else if (block_name.compare("marble") == 0)
      return new c_block_marble();
    else if (block_name.compare("wood") == 0)
      return new c_block_wood();
    else if (block_name.compare("particles") == 0)
      return new c_block_particles();
    else if (block_name.compare("circle transform") == 0)
      return new c_block_circle_transform();
    else if (block_name.compare("radius transform") == 0)
      return new c_block_radius_transform();
    else if (block_name.compare("sine transform") == 0)
      return new c_block_sine_transform();
    else if (block_name.compare("invert") == 0)
      return new c_block_invert();
    else if (block_name.compare("dither") == 0)
      return new c_block_dither();
    else if (block_name.compare("crop amplitude") == 0)
      return new c_block_crop_amplitude();

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

    block2->connect(block1,slot);

    return true;
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

    while (getline(myfile,line))
      {
        filetext += line;
      }

    myfile.close();

    filetext_c = document.allocate_string(filetext.c_str(),
      filetext.length());
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

        block = get_block_instance(block_name);

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

            document.first_node()->append_node(node);

          }

        save_file << document;
        save_file.close();
      }
    else
      return false;

    return true;
  }

//======================================================================
// 'SET DEFAULT' FUNCTIONS:
//======================================================================

void c_block_voronoi_diagram::set_default()

  {
    this->parameters->add_parameter("type",PARAMETER_INT);
    this->parameters->add_parameter("metric",PARAMETER_INT);
    this->parameters->add_parameter("point place",PARAMETER_INT);
    this->parameters->add_parameter("width",PARAMETER_DOUBLE);
    this->parameters->add_parameter("point positions",PARAMETER_STRING);
    this->parameters->add_parameter("number of points",PARAMETER_INT);
    this->name = "voronoi diagram";

    this->parameters->set_int_value("type",VORONOI_2_NEAREST_RATIO);
    this->parameters->set_int_value("metric",METRIC_EUCLIDEAN);
    this->parameters->set_int_value("point place",PLACE_RANDOM);
    this->parameters->set_double_value("width",0.75);
    this->parameters->set_string_value("point positions",(char *) "");
    this->parameters->set_int_value("number of points",15);
  }

//----------------------------------------------------------------------

void c_block_color_fill::set_default()

  {
    this->parameters->add_parameter("red",PARAMETER_INT);
    this->parameters->add_parameter("green",PARAMETER_INT);
    this->parameters->add_parameter("blue",PARAMETER_INT);
    this->name = "color fill";

    this->parameters->set_int_value("red",255);
    this->parameters->set_int_value("green",255);
    this->parameters->set_int_value("blue",255);
  }

//----------------------------------------------------------------------

void c_block_file_save::set_default()

  {
    this->parameters->add_parameter("path",PARAMETER_STRING);
    this->name = "file save";

    this->parameters->set_string_value("path",(char *) "texture.png");
  }

//----------------------------------------------------------------------

void c_block_rgb::set_default()

  {
    this->name = "adjust rgb";
  }

//----------------------------------------------------------------------

void c_block_fault_formation_noise::set_default()

  {
    this->name = "fault formation noise";
  }

//----------------------------------------------------------------------

void c_block_bump_noise::set_default()

  {
    this->parameters->add_parameter("bump size from",PARAMETER_DOUBLE);
    this->parameters->add_parameter("bump size to",PARAMETER_DOUBLE);
    this->parameters->add_parameter("quantity",PARAMETER_INT);
    this->parameters->add_parameter("alter amplitude",PARAMETER_BOOL);
    this->name = "bump noise";

    this->parameters->set_double_value("bump size from",0.7);
    this->parameters->set_double_value("bump size to",0.01);
    this->parameters->set_int_value("quantity",1);
    this->parameters->set_bool_value("alter amplitude",false);
  }

//----------------------------------------------------------------------

void c_block_sine_transform::set_default()

  {
    this->parameters->add_parameter("phase",PARAMETER_DOUBLE);
    this->parameters->add_parameter("periods",PARAMETER_INT);
    this->parameters->add_parameter("amplitude",PARAMETER_INT);
    this->name = "sine transform";

    this->parameters->set_double_value("phase",0.0);
    this->parameters->set_int_value("periods",5);
    this->parameters->set_int_value("amplitude",127);
  }

//----------------------------------------------------------------------

void c_block_mix_channels::set_default()

  {
    this->name = "mix channels";
  }

//----------------------------------------------------------------------

void c_block_substrate::set_default()

  {
    this->parameters->add_parameter("number of iterations",
      PARAMETER_INT);
    this->parameters->add_parameter("number of lines",PARAMETER_INT);
    this->parameters->add_parameter("fill type",PARAMETER_INT);
    this->parameters->add_parameter("grayscale",PARAMETER_BOOL);
    this->parameters->add_parameter("iterate",PARAMETER_BOOL);
    this->name = "substrate";

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
    this->parameters->add_parameter("percentage",PARAMETER_INT);
    this->parameters->add_parameter("method",PARAMETER_INT);
    this->name = "mix";

    this->parameters->set_int_value("percentage",50);
    this->parameters->set_int_value("method",MIX_AVERAGE);
  }

//----------------------------------------------------------------------

void c_block_marble::set_default()

  {
    this->parameters->add_parameter("periods",PARAMETER_INT);
    this->parameters->add_parameter("intensity",PARAMETER_INT);
    this->parameters->add_parameter("amplitude",PARAMETER_INT);
    this->parameters->add_parameter("direction",PARAMETER_INT);
    this->name = "marble";

    this->parameters->set_int_value("periods",5);
    this->parameters->set_int_value("intensity",4);
    this->parameters->set_int_value("amplitude",127);
    this->parameters->set_int_value("direction",DIRECTION_HORIZONTAL);
  }

//----------------------------------------------------------------------

void c_block_wood::set_default()

  {
    this->parameters->add_parameter("circles",PARAMETER_INT);
    this->parameters->add_parameter("hardness",PARAMETER_INT);
    this->parameters->add_parameter("intensity",PARAMETER_INT);
    this->parameters->add_parameter("amplitude",PARAMETER_INT);
    this->parameters->add_parameter("direction",PARAMETER_INT);
    this->name = "wood";

    this->parameters->set_int_value("circles",4);
    this->parameters->set_int_value("hardness",8);
    this->parameters->set_int_value("intensity",20);
    this->parameters->set_int_value("amplitude",127);
    this->parameters->set_int_value("direction",DIRECTION_HORIZONTAL);
  }

//----------------------------------------------------------------------

void c_block_particles::set_default()

  {
    this->parameters->add_parameter("particles",PARAMETER_INT);
    this->parameters->add_parameter("initial x",PARAMETER_DOUBLE);
    this->parameters->add_parameter("initial y",PARAMETER_DOUBLE);
    this->parameters->add_parameter("angle",PARAMETER_INT);
    this->parameters->add_parameter("spread",PARAMETER_INT);
    this->parameters->add_parameter("initial velocity",
      PARAMETER_DOUBLE);
    this->name = "particles";

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
    this->parameters->add_parameter("radius",PARAMETER_INT);
    this->parameters->add_parameter("jumps",PARAMETER_INT);
    this->name = "circle transform";

    this->parameters->set_int_value("radius",5);
    this->parameters->set_int_value("jumps",1);
  }

//----------------------------------------------------------------------

void c_block_radius_transform::set_default()

  {
    this->parameters->add_parameter("radius min",PARAMETER_INT);
    this->parameters->add_parameter("radius max",PARAMETER_INT);
    this->parameters->add_parameter("rotate left",PARAMETER_BOOL);
    this->parameters->add_parameter("horizontal",PARAMETER_BOOL);
    this->name = "radius transform";

    this->parameters->set_int_value("radius min",1);
    this->parameters->set_int_value("radius max",20);
    this->parameters->set_bool_value("rotate left",true);
    this->parameters->set_bool_value("horizontal",true);
  }

//----------------------------------------------------------------------

void c_block_invert::set_default()

  {
    this->name = "invert";
  }

//----------------------------------------------------------------------

void c_block_dither::set_default()

  {
    this->parameters->add_parameter("levels",PARAMETER_INT);
    this->parameters->add_parameter("method",PARAMETER_INT);
    this->name = "dither";

    this->parameters->set_int_value("levels",8);
    this->parameters->set_int_value("method",DITHERING_ORDERED);
  }

//----------------------------------------------------------------------

void c_block_crop_amplitude::set_default()

  {
    this->parameters->add_parameter("lower limit",PARAMETER_INT);
    this->parameters->add_parameter("upper limit",PARAMETER_INT);
    this->name = "crop amplitude";

    this->parameters->set_int_value("lower limit",50);
    this->parameters->set_int_value("upper limit",200);
  }

//======================================================================
// 'EXECUTE' FUNCTIONS:
//======================================================================

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
            PLACE_SQUARE,
            this->parameters->get_double_value("width"),
            this->parameters->get_int_value("number of points"),
            NULL,
            &(this->buffer));
          break;

        case PLACE_CUSTOM:
          // TODOOOOOOOOOOOOOOOOO
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

bool c_block_substrate::execute()

  {
    int number;

    if (this->parameters->get_bool_value("iterate"))
      number = this->parameters->get_int_value("number of iterations");
    else
      number = this->parameters->get_int_value("number of lines");

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
