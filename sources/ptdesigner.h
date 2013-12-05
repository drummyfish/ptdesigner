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

#define MAX_INPUT_BLOCKS  5  /// maximum number of input blocks
#define MAX_MULTISAMPLING 6  /// maximum multisampling level

using namespace std;

namespace pt_design
{

class c_texture_graph;      // forward declaration

//----------------------------------------------------------------------

 /**
  * Represents a general texture designer block, which is a node of
  * texture describing graph. To create a block instance use the static
  * factory method get_block_instance.
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
      c_texture_graph *graph;   /// graph that the block belongs to
      string name;              /// name of the block
      bool initialised;         /// whether the block is initialised

      void set_error();

        /**<
         * Sets the error flag and invalidates the block.
         */

      bool manage_input_graphic_blocks(unsigned int number, bool force,
        bool *change_occured);

        /**<
         * Takes care of first number of input blocks, checking if they
         * are connected, if they are graphic blocks, if they are valid
         * and recomputing them in case they aren't, and if they don't
         * have errors set. This function is supposed to help the block
         * check its inputs before computing its output. Even if false
         * is to be returned, as many as possible of the input blocks
         * are managed.
         *
         * @param number number of blocks to be checked
         * @param force if true, the input blocks will always be
         *        recomputed, if false, the blocks will only be
         *        recommputed if needed
         * @param change_occured if this variable is not NULL, the
         *        information about whether any change in input blocks
         *        occured will be returned in it
         *
         * @return true is returned if everything went OK, i.e. all of
         *         the first number blocks are connected graphic blocks
         *         with valid inputs and no errors, otherwise false is
         *          returned
         */

      virtual void set_default();

        /**<
         * Sets block specific parameters to default values.
         */

    public:

      c_block();

        /**<
         * Class constructor, initialises a new block. The block can't
         * be used before it's added to a texture graph.
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

      void set_texture_graph(c_texture_graph *graph);

        /**<
         * Sets the block to belong to specified texture graph.
         *
         * @param graph texture graph which this block should belong to
         */

      c_block *get_input(unsigned int index);

        /**<
         * Gets the block input at specified input slot.
         *
         * @param index input slot index
         *
         * @return pointer to input block at given input slot of this
         *         block
         */

      virtual void adjust();

        /**<
         * Adjusts the block parameters to current graph parameters
         * (i.e. resolution and so on)
         */

      string get_name();

        /**<
         * Returns text name of the block.
         *
         * @return name of the block
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

      void connect(c_block *input_block, unsigned int slot_number);

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

      bool is_user_of(c_block *block);

        /**<
         * Check if this block uses another block as an input.
         *
         * @param block block which this block is checked to be using
         *
         * @return true if this block uses the block block as an input,
         *         false otherwise
         */

      virtual ~c_block();

        /**<
         * Class destructor, destroys the block and frees all it's
         * memory.
         */

      virtual bool compute(bool force);

        /**<
         * Computes the block output and executes all other asociated
         * actions. The block will recursively call this function for
         * all its input blocks if needed.
         *
         * @param force if true, the block will recompute its output and
         *        will also force to do the same for all its input
         *        blocks even if it wasn't not necessary, if false, the
         *        computation will only be done if the block output
         *        isn't valid and only invalid input blocks will be
         *        recomputed
         *
         * @return true if anything was recomputed, false if not
         */

      virtual void set_default_parameters();

        /**<
         * Sets the block parameters to default values
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
      virtual void adjust();

        /**<
         * Adjusts the block parameters to current graph parameters
         * (i.e. resolution and so on)
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
      virtual void adjust();

        /**<
         * Adjusts the block parameters to current graph parameters
         * (i.e. resolution and so on)
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
      vector<c_block *> *end_blocks;    /** blocks that are not an input
                                            of any other block */

    public:

      c_texture_graph();

        /**<
         * Class constructor, initialises a new texture graph.
         */

      void update();

        /**<
         * Updates the texture graph. Should be called after connect or
         * disconnect functions has been called.
         */

      ~c_texture_graph();

        /**<
         * Class destructor, frees all the memory and destroys all the
         * graph block.
         */

      bool compute(bool force);

        /**<
         * Computes all the block outputs and executes all asociated
         * actions. As many as possible of the blocks will be computed,
         * even if there are errors.
         *
         * @param force if true, all blocks will be forced to recompute
         *        even if it's not necesarry, otherwise only invalid
         *        blocks will be recomputed
         *
         * @return true if every block was computed succesfully,
         *         otherwise false
         */

      void invalidate_all();

        /**<
         * Invalidates all the block so their outputs will be forced to
         * be recomputed next time the compute function is called.
         */

      void adjust_all();

        /**<
         * Adjusts all the blocks so that their parameters are in match
         * with current graph parameters.
         */

      void set_multisampling(unsigned int level);

        /**<
         * Sets the texture multisapling level.
         *
         * @param level level of multisampling, 1 means no
         *        multisampling, 2 means 2 x 2 etc. Maximum value is
         *        MAX_MULTISAMPLING.
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
         * Adds given block to texture graph. This will initialise the
         * block's parameters to default values and adjust them so that
         * they match the texture graph settings.
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

      void print_as_text();

        /**<
         * Debugging purposes method. Prints the graph text
         * representation to standard output.
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

      virtual void set_default();

    public:
      virtual bool compute(bool force);

      void set_color(unsigned char red, unsigned char green,
        unsigned char blue);

        /**<
         * Sets the color which the image will be filled with.
         *
         * @param red amount of red
         * @param green amount of green
         * @param blue amount of blue
         */

      void get_color(unsigned char *red, unsigned char *green,
        unsigned char *blue);

        /**<
         * Returns currently set fill color.
         *
         * @param red in this variable amount of red will be returned
         * @param green in this variable amount of green will be
         *        returned
         * @param blue in this variable amount of blue will be returned
         */
  };

//----------------------------------------------------------------------

 /**
  * Bump noise block.
  */

class c_block_bump_noise: public c_graphic_block

  {
    protected:
      float bump_size_from;  /// upper limit of the bump size
      float bump_size_to;    /// lower limit of the bump size
      unsigned int quantity; /// bump quantity
      bool alter_amplitude;  /// whether to alter amplitude

      virtual void set_default();
    public:

      virtual bool compute(bool force);

      void set_parameters(float bump_size_upper, float bump_size_lower,
        unsigned int quantity, bool alter_amplitude);

        /**
         * Sets the block parameters.
         *
         * @param bump_size_upper a number in range <0,1> which
         *        determines initial bump size in fraction of the buffer
         *        width, this is the upper limit
         * @param bump_size_lower a number in range <0,1> which
         *        determines final bump size in fraction of the buffer
         *        width, this is the lower limit
         * @param quantity a number that specifies how fast the bump
         *        count will grow, use value 1 for common usage
         * @param alter_amplitude says if the amplitude of the bumps
         *        will be lowered with each iteration (true) or not
         *        (false), non-altering amplitude creates a sharper
         *        image
         */

      void get_parameters(float *bump_size_upper,
        float *bump_size_lower, unsigned int *quantity,
        bool *alter_amplitude);

        /**
         * Gets the block parameters.
         *
         * @param bump_size_upper in this variable the upper limit for
         *        the bump size will be returned
         * @param bump_size_lower in this variable the lower limit for
         *        the bump size will be returned
         * @param quantity in this parameter the quantity parameter
         *        value will be returned
         * @param alter_amplitude in this variable the value of alter
         *        amplitude parameter will be returned
         */
  };

//----------------------------------------------------------------------

 /**
  * Perlin noise block.
  */

class c_block_perlin_noise: public c_graphic_block

  {
    protected:
      unsigned char amplitude;              /// base amplitude
      unsigned int frequency;               /// base frequency
      int max_iterations;                   /** maximum number of
                                                iterations, negative
                                                number means no limit */
      t_interpolation_method interpolation; /// interpolation method
      bool smooth;                          /// whether to smooth

      virtual void set_default();

    public:
      virtual bool compute(bool force);

      void set_parameters(unsigned char amplitude,
        unsigned int frequency, int max_iterations,
        t_interpolation_method interpolation, bool smooth);

        /**
         * Sets the block parameters.
         *
         * @param amplitude amplitude of the base frequency, should be
         *        in range <0,128>
         * @param frequency base, lowest frequency of the noise
         * @param max_iterations maximum number of iterations, negative
         *        number means no limit (generating will stop when the
         *        frequency is higher than buffer resolution or when the
         *        amplitude reaches zero)
         * @param interpolation interpolation type
         * @param smooth says if the noise should be smoothed so that
         *        the number of artifacts is reduced (this is takes a
         *        little more time but looks nicer)
         */

      void get_parameters(unsigned char *amplitude,
        unsigned int *frequency, int *max_iterations,
        t_interpolation_method *interpolation, bool *smooth);

        /**
         * Gets the block parameters.
         *
         * @param amplitude in this parameter the base amplitude
         *        parameter value will be returned
         * @param frequency in this parameter the base frequency
         *        parameter value will be returned
         * @param max_iterations in this parameter the max frequency
         *        parameter value will be returned
         * @param interpolation in this parameter the interpolation
         *        method will be returned
         * @param smooth in this parameter the smooth parameter value
         *        will be returned
         */
  };

//----------------------------------------------------------------------

 /**
  * RGB adjust block.
  */

class c_block_rgb: public c_graphic_block

  {
    protected:
      int red;            /// value to be added to red
      int green;          /// value to be added to green
      int blue;           /// value to be added to blue

      virtual void set_default();

    public:
      virtual bool compute(bool force);

      void set_parameters(int red, int green, int blue);

        /**
         * Sets the block parameters.
         *
         * @param red value to be added to red
         * @param green value to be added to green
         * @param blue value to be added to blue
         */

      void get_parameters(int *red, int *green, int *blue);

        /**
         * Gets the block parameters.
         *
         * @param red in this parameter the amount of red will be
         *        returned
         * @param green in this parameter the amount of green will be
         *        returned
         * @param blue in this parameter the amount of blue will be
         *        returned
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

      virtual void set_default();
    public:
      virtual bool compute(bool force);

      void set_path(string path);

        /**<
         * Sets the path where the content should be saved.
         *
         * @param path file path
         */
  };

//----------------------------------------------------------------------

} // namespace

#endif
