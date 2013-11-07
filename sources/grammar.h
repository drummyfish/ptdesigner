#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "general.h"

//**********************************************************************
/** @file
 * Header file of grammar module, which provides a possibility to
 * generate strings based on given rule set.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#define GRAMMAR_MAXIMUM_PARAMETERS 5

                                /** a character of generated grammar
                                    string, each one can have values of
                                    it's parameters */
typedef struct
  {
    char character;
    unsigned char number_of_parameters;
    int parameter_values[GRAMMAR_MAXIMUM_PARAMETERS];
  } t_grammar_char;

                                /** a character of a grammar string used
                                    in rules, each one can have
                                    expression of it's parameters */
typedef struct
  {
    char character;
    unsigned char number_of_parameters;
    char *parameter_expressions[GRAMMAR_MAXIMUM_PARAMETERS];
  } t_grammar_rule_char;

typedef struct
  {
    char left;                  ///< left side symbol
    unsigned char number_of_parameters;
    char parameter_list[GRAMMAR_MAXIMUM_PARAMETERS];  /**< parameter
                                names (single characters) */
    char *condition;            ///< rule condition
    int right_length;           ///< length of the right side string
    t_grammar_rule_char *right;
    unsigned char chance;       /**< likeliness of rule application,
                                     default is 1, 2 means twice as
                                     likely etc. */
  } t_grammar_rule;
                                /** represents a grammar itself */
typedef struct
  {
    t_grammar_char *axiom;
    t_grammar_char *string;     ///< generated string
    int axiom_length;
    int string_length;
    t_grammar_rule *rules;
    int number_of_rules;
    int random;                 ///< seed passed to noise generator
  } t_grammar;

//----------------------------------------------------------------------

void grammar_init(t_grammar *grammar, char *axiom, int random);

  /**<
   * Initialises a new grammar with given axiom and empty rule set.
   *
   * @param grammar grammar to be initialised
   * @param axiom starting string from which the final string will be
   *        generated
   * @param random number that affects the pseudo-number generation,
   *        different values will result in different strings generated
   *        with rules that depend on probability
   */

//----------------------------------------------------------------------

void grammar_destroy(t_grammar *grammar);

  /**<
   * Destroys given grammar and frees it's memory.
   *
   * @param grammar grammar to be destroyed
   */

//----------------------------------------------------------------------

int grammar_add_rule(t_grammar *grammar, char *rule_string);

  /**<
   * Adds a rule to the grammar's rule set.
   *
   * @param grammar
   * @return 1 if the rule was added succesfully, otherwise false
   */

//----------------------------------------------------------------------

int grammar_generate_string(t_grammar *grammar,
  unsigned int iterations);

  /**<
   * Generates internal string using provided rule set, axiom and
   * given number of iterations. To retrieve generated string use
   * other methods.
   *
   * @param grammar grammar for which the string will be generated
   * @param iterations number of iterations to generate the string
   *
   * @return 1 if the action was succesful, otherwise 0
   */

//----------------------------------------------------------------------

int grammar_load_from_file(t_grammar *grammar, char *filename,
  int random);

  /**<
   * Loads the grammar (axiom and rules) from fiven file. This serves
   * as an initialise function so the grammar is allowed to be
   * uninitialised.
   *
   * @param grammar grammar to be loaded
   * @param filename name of the file
   * @param random number that affects the random choosing of the rules
   *
   * @return 1 if everything was OK, otherwise 0
   */

//----------------------------------------------------------------------

int grammar_save_to_file(t_grammar *grammar, char *filename);

  /**<
   * Saves grammar rules and axiom to given file.
   *
   * @param grammar grammar to be saved
   * @param filename name of the file
   *
   * @return 1 if everything was OK, 0 otherwise
   */

//----------------------------------------------------------------------

void grammar_print_string(t_grammar *grammar);

  /**<
   * Prints the string stored in given grammar to stdout.
   *
   * @param grammar grammar that contains the string
   */

//----------------------------------------------------------------------

#endif
