//**********************************************************************
/** @file
 * Implementation of grammar module.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include "grammar.h"

                               /** a private structure that represents a
                                   scanner */
typedef struct
  {
    unsigned int position;     ///< position in the string
    char *string;              ///< string being analysed
  } t_scanner;

                               /** token type */
typedef enum
  {
    TOKEN_CHARACTER,           ///< single character token
    TOKEN_NUMBER,              ///< numeric token
    TOKEN_ARROW,               ///< arrow ("->")
    TOKEN_END,                 ///< end of the string
    TOKEN_ERROR                ///< invalid token indicator
  } t_token;

                               /** a symbol table that keeps assigned
                                   values for character */
typedef struct
  {
    int values[256];           ///< values of the symbols
    int validity_map[256];     ///< says whether the symbol is assigned
  } t_symbol_table;

t_scanner scanner;             // global scanner
t_symbol_table symbol_table;   // global symbol table

//----------------------------------------------------------------------

  /**
   * Private function - sets string to be analysed by scanner.
   *
   * @param string string to be analysed
   */

void _scanner_set_string(char *string)

  {
    scanner.position = 0;
    scanner.string = string;
  }

//----------------------------------------------------------------------

  /**
   * Private function - gets the next token from the string that was set
   * with _scanner_set_string function.
   *
   * @param token_type in this variable the type of the next token will
   *   be returned
   * @param value in this variable either number or chararacter value
   * (unsigned char) will be returned
   */

void _scanner_next_token(t_token *token_type, int *value)

  {
    unsigned char character;
    unsigned char number_buffer[32];  // to read a number
    int buffer_length;
    int is_negative;

    *value = 0;

    while (1)   // skip white characters
      {
        character = scanner.string[scanner.position];

        if (character == 0)
          {
            *token_type = TOKEN_END;
            return;
          }

        if (character == ' ' || character == '\n')
          {
            scanner.position++;
          }
        else
          break;
      }

    if (character == '-' && scanner.string[scanner.position + 1] == '>')
      {
        *token_type = TOKEN_ARROW;        // arrow

        scanner.position += 2;
        return;
      }

    if ( (character >= 'A' && character <= 'Z') ||   // single character
         (character >= 'a' && character <= 'z') ||
         (character == '&') ||
         (character == '|') ||
         (character == '!') ||
         (character == '<') ||
         (character == '>') ||
         (character == '=') ||
         (character == '+') ||
         (character == '(') ||
         (character == ')') ||
         (character == '[') ||
         (character == ']') ||
         (character == '{') ||
         (character == '}') ||
         (character == ',') ||
         (character == ':') ||
         (character == '-' && !isdigit(scanner.string[scanner.position + 1])) ||
         (character == '*') ||
         (character == '/') )
      {
        *token_type = TOKEN_CHARACTER;
        *value = (int) character;

        scanner.position++;
        return;
      }

    if (isdigit(character) || character == '-') // number
      {
        buffer_length = 0;

        if (character == '-')
          {
            is_negative = 1;
            scanner.position++;
          }
        else
          is_negative = 0;

        while (1)
          {
            character = scanner.string[scanner.position];

            if (!isdigit(character))
              break;

            number_buffer[buffer_length] = character;
            buffer_length++;

            if (buffer_length > 10)
              break;

            scanner.position++;
          }

        number_buffer[buffer_length] = 0;  // terminate the string

        *token_type = TOKEN_NUMBER;
        *value = atoi((char *) number_buffer);

        if (is_negative)
          *value = *value * -1;

        return;
      }

    *token_type = TOKEN_ERROR;          // error here
  }

//----------------------------------------------------------------------

  /**
   * Private function - evalues an expression and returns it's value.
   * The function uses the global scanner so it's state may be changed
   * after the call.
   *
   * @param expression expression to be evaluated, only integers,
   *   basic operations (+,-,*,/,&,|,<,>,=) and brackets are allowed,
   *   for the exact format of the string see documentation
   * @param table symbol table where values of the variables can be
   *   found
   * @param success true is returned via this variable if the expression
   *   was evaluated properly, otherwise false - this variable cannot be
   *   NULL
   *
   * @return value of the expression
   */

int _evaluate_expression(char *expression,t_symbol_table *table,
  int *success)

  {
    t_token token;
    int value;
    int operand_1;
    unsigned char operation;
    int operand_2;
    int state;     // state of reading, 0 = op1, 1 = operator, 2 = op2, 3 = done
    int scanner_position;      // to keep scanner position on stack

    *success = 1;

    if (expression == NULL || table == NULL || success == NULL)
      {
        *success = 0;
        return 0;
      }

    _scanner_set_string(expression);

    state = 0;

    while (1)
      {
        _scanner_next_token(&token,&value);
        if (token == TOKEN_CHARACTER && value == ')')
          token = TOKEN_END;

        switch (token)
          {
            case TOKEN_CHARACTER:
              {
                if (value == '(')
                  {
                    if (state == 0)    // evaluate recursively
                      {
                        operand_1 = _evaluate_expression(expression +
                        scanner.position,table,success);
                      }
                    else if (state == 2)
                      {
                        operand_2 = _evaluate_expression(expression +
                        scanner.position,table,success);
                      }
                    else
                      {
                        *success = 0;
                        return 0;
                      }

                    if (!(*success))
                      return 0;
                  }
                else if (state == 1)   // reading operator
                  operation = (unsigned char) value;
                else                   // reading variable value
                  {
                    if (!symbol_table.validity_map[(unsigned char) value])
                      {
                        *success = 0;  // unassigned symbol
                        return 0;
                      }

                    if (state == 0)
                      operand_1 = symbol_table.values[(unsigned char) value];
                    else
                      operand_2 = symbol_table.values[(unsigned char) value];
                  }
              }

              break;

            case TOKEN_NUMBER:
              if (state == 0)
                operand_1 = value;
              else if (state == 2)
                operand_2 = value;
              else
                {
                  *success = 0;   // operator was expected
                  return 0;
                }

              break;

            case TOKEN_END:
              if (state == 3)
                switch (operation)
                  {
                    case '+': return operand_1 + operand_2; break;
                    case '-': return operand_1 - operand_2; break;
                    case '*': return operand_1 * operand_2; break;
                    case '/': return operand_1 / operand_2; break;
                    case '&': return operand_1 && operand_2; break;
                    case '|': return operand_1 || operand_2; break;
                    case '=': return operand_1 == operand_2; break;
                    case '<': return operand_1 < operand_2; break;
                    case '>': return operand_1 > operand_2; break;
                    default : *success = 0; return 0; break;
                  }
              else if (state == 1)
                return operand_1;
              else
                {
                  *success = 0;
                  return 0;
                }

              break;

            case TOKEN_ERROR:
            case TOKEN_ARROW:
              *success = 0;
              return 0;
              break;
          }

        state++;
      }
  }

//----------------------------------------------------------------------

  /**
   * Private function - parses parameter expressions from provided
   * string and saves them in for given grammar char. For example
   * string "x + 1,3)" will save two expressions - "x + 1" and "3".
   *
   * @param symbol grammar symbol in which the expressions will be saved
   * @param string string of parameter expressions which must contain
   * right bracket (')'), characters following the right bracket are
   * ignored
   *
   * @return if there was an error, 0 is returned, otherwise length of
   *   the read expression (the whole string containing multiple
   *   expressions) is returned
   */

int _read_parameter_expressions(t_grammar_rule_char *symbol,
  char *string)

  {
    int length, start;
    int total_length;
    int expression_number;
    int left_brackets;         // to distinguish nested expressions
    unsigned char character;
    int error;
    int i;

    expression_number = 0;
    start = 0;
    length = 0;
    error = 0;
    total_length = 0;
    left_brackets = 0;

    while (1)
      {
        if (error)
          break;

        character = string[start + length];

        if (character == '(')
          {
            left_brackets++;
            length++;
          }
        else if (character == ',' ||
          (character == ')' && left_brackets == 0))
          {
            if (length == 0)
              error = 1;

            symbol->parameter_expressions[expression_number] =
              (char *) malloc (length + 1);

            if (symbol->parameter_expressions[expression_number]
              == NULL)
              error = 1;

            strncpy(symbol->parameter_expressions[expression_number],
              string + start,length);

            symbol->parameter_expressions[expression_number]
              [start + length] = 0;  // terminate the string

            expression_number++;

            start = start + length + 1;
            length = 0;

            if (expression_number >= GRAMMAR_MAXIMUM_PARAMETERS)
              break;
          }
        else
          length++;

        total_length++;

        if (character == ')')
          {
            if (left_brackets == 0)
              break;              // end of expression
            else
              left_brackets--;    // nested expression in brackets
          }
      }

    symbol->number_of_parameters = expression_number;

    if (error)
      {
        for (i = 0; i < expression_number; i++)
          free(symbol->parameter_expressions[i]);

        return 0;
      }

    return total_length;
  }

//----------------------------------------------------------------------

  /**
   * Private function - determines which rule to apply to given symbol.
   *
   * @param grammar grammar with rule set that the rule will be chosen
   *   from
   * @param symbol grammar symbol for which the rule should be found
   *
   * @return number of the rule of provided grammar (starting with 0)
   *   or -1 if no rule can be applied
   */

int _grammar_determine_rule(t_grammar *grammar, t_grammar_char *symbol)

  {
    int probability_sum;
    int satisfactory_rules[grammar->number_of_rules];
    int satisfactory_rules_length;
    int i, j;
    int success;
    int value;
    int random_number;
    unsigned char character;

    probability_sum = 0;
    satisfactory_rules_length = 0;

    for (i = 0; i < grammar->number_of_rules; i++)
      {

        if (grammar->rules[i].number_of_parameters !=
          symbol->number_of_parameters)
          continue;

        if (symbol->character != grammar->rules[i].left)
          continue;

        // assign symbols in the symbol table:

        for (j = 0; j < symbol->number_of_parameters; j++)
          {
            character = grammar->rules[i].parameter_list[j];
            value = symbol->parameter_values[j];

            symbol_table.values[character] = value;
            symbol_table.validity_map[character] = 1;
          }

        success = 1;

        if (grammar->rules[i].condition != NULL)
          if (!_evaluate_expression(grammar->rules[i].condition,
            &symbol_table,&success))
          continue;

        if (!success)
          continue;

        for (j = 0; j < 255; j++)  // invalidate the symbol table
          symbol_table.validity_map[j] = 0;

        // here it's been checked that the rule can be used:

        satisfactory_rules[satisfactory_rules_length] = i;
        satisfactory_rules_length++;
        probability_sum += grammar->rules[i].chance;
      }

    if (satisfactory_rules_length == 0)
      return -1;

    if (satisfactory_rules_length == 1)
      return satisfactory_rules[0];

    // here the rule must be chosen randomly:

    random_number = noise_int_range(grammar->random,1,
      probability_sum);

    grammar->random++;

    for (i = 0; i < satisfactory_rules_length; i++)
      {
        random_number -= grammar->rules[satisfactory_rules[i]].chance;

        if (random_number <= 0)
          return satisfactory_rules[i];
      }

    return -1; // the program should never get here
  }

//----------------------------------------------------------------------

  /**
   * Private function - returns a number of grammar characters in
   * provided grammar string. The function ignores brackets, so for
   * a parametrised input of "ab(1,2)c" the result will be 3. Nested
   * brackets like "x(1 + (3 / 2))" are also allowed. There may be
   * spaces in the string.
   *
   * @param string string of grammar characters
   *
   * @return number of grammar characters in the string
   */

int _grammar_string_length(char *string)

  {
    int position;
    int length;
    int left_brackets;  // number of left brackets

    position = 0;
    length = 0;
    left_brackets = 0;

    if (string == NULL)
      return 0;

    while (string[position] != 0)
      {
        if (string[position] == '(')
          left_brackets++;

        if (left_brackets == 0 && string[position] != ' ')
          length++;

        if (string[position] == ')')
          left_brackets--;

        position++;
      }

    return length;
  }

//----------------------------------------------------------------------

void grammar_init(t_grammar *grammar, char *axiom, int random)

  {
    int i;
    int number_of_params;
    t_token token;
    int value;

    grammar->axiom_length = _grammar_string_length(axiom);
    grammar->string_length = 0;
    grammar->string = NULL;
    grammar->number_of_rules = 0;
    grammar->rules = NULL;
    grammar->random = random;

    grammar->axiom = (t_grammar_char *)
      malloc(grammar->axiom_length * sizeof(t_grammar_char));

    _scanner_set_string(axiom);

    // make the axiom structure:

    for (i = 0; i < grammar->axiom_length; i++)
      {
        _scanner_next_token(&token,&value);

        if (token == TOKEN_CHARACTER)
          {
            if (value == '(' && i != 0)
              {
                number_of_params = 0;

                while (1)           // read the parameters
                  {
                    _scanner_next_token(&token,&value);

                    if (token == TOKEN_CHARACTER && value == ')')
                      {
                        grammar->axiom[i - 1].number_of_parameters =
                        number_of_params;

                        _scanner_next_token(&token,&value);

                        break;
                      }
                    else if (token == TOKEN_NUMBER)
                      {
                        grammar->axiom[i - 1].parameter_values[number_of_params] = value;
                        number_of_params++;

                        if (number_of_params > GRAMMAR_MAXIMUM_PARAMETERS)
                          break;
                      }
                  }
              }

            grammar->axiom[i].character = (unsigned char) value;
            grammar->axiom[i].number_of_parameters = 0;
          }
        else
          break;
      }
  }

//----------------------------------------------------------------------

void grammar_destroy(t_grammar *grammar)

  {
    int i, j, k;

    if (grammar->axiom != NULL)
      free(grammar->axiom);

    if (grammar->string != NULL)
      free(grammar->string);

    for (i = 0; i < grammar->number_of_rules; i++)
      {
        if (grammar->rules[i].condition != NULL)
          free(grammar->rules[i].condition);

        for (j = 0; j < grammar->rules[i].right_length; j++)
          for (k = 0; k < grammar->rules[i].right[j].number_of_parameters; k++)
            free(grammar->rules[i].right[j].parameter_expressions[k]);

        free(grammar->rules[i].right);
      }

    free(grammar->rules);
  }

//----------------------------------------------------------------------

int grammar_add_rule(t_grammar *grammar, char *rule_string)

  {
    t_token token;
    int new_position;
    int value;
    int help_position, help_length; // for reading a string
    t_grammar_rule rule;
    int error;

    if (grammar == NULL || rule_string == NULL || rule_string[0] == 0)
      return 1;

    error = 0;

    _scanner_set_string(rule_string);

    _scanner_next_token(&token,&value);

    if (token == TOKEN_CHARACTER)   // character expected
      rule.left = (unsigned char) value;
    else
      error = 1;

    _scanner_next_token(&token,&value);

    rule.number_of_parameters = 0;
    rule.condition = NULL;

    if (!error && token == TOKEN_CHARACTER && value == '(')
      {
        _scanner_next_token(&token,&value);

        while (1)                   // optional parameter list
          {
            if (token == TOKEN_CHARACTER)
              {
                rule.parameter_list[rule.number_of_parameters] =
                  (unsigned char) value;

                rule.number_of_parameters++;
              }
            else
              {
                error = 1;
                break;
              }

            _scanner_next_token(&token,&value);

            if (token == TOKEN_CHARACTER && value == ')')
              break;
            else if (token == TOKEN_CHARACTER && value == ',')
              _scanner_next_token(&token,&value);
            else
              {
                error = 1;
                break;
              }
          }

        _scanner_next_token(&token,&value);

        // optional condition:

        if (!error && token == TOKEN_CHARACTER && value == '[')
          {
            help_length = 0;
            help_position = scanner.position;

            while (rule_string[help_position + help_length] != ']')
              {
                help_length++;

                if (rule_string[help_position + help_length] == 0)
                  {
                    error = 1;
                    break;
                  }
              }

            scanner.position = help_position + help_length + 1;
            _scanner_next_token(&token,&value);

            rule.condition = (char *) malloc(help_length + 1);

            if (rule.condition == NULL)
              error = 1;

            if (!error)
              strncpy(rule.condition,rule_string + help_position,help_length);
          }
      }

    if (!error && token == TOKEN_CHARACTER)   // rule chance
      {
        if (value != ':')
          error = 1;

        _scanner_next_token(&token,&value);

        if (token != TOKEN_NUMBER)
          error = 1;

        rule.chance = value;

        _scanner_next_token(&token,&value);
      }
    else
      {
        rule.chance = 1;            // default value
      }

    if (token != TOKEN_ARROW)       // "->" expected
      return 0;

    rule.right_length =
      _grammar_string_length(rule_string + scanner.position);

    rule.right = (t_grammar_rule_char *) malloc(rule.right_length *
      sizeof (t_grammar_rule_char));

    if (rule.right == NULL)
      return 0;

    help_position = 0;

    while (1)                       // read the right side
      {
        if (error)
          break;

        _scanner_next_token(&token,&value);

        if (token == TOKEN_CHARACTER && value == '(')
          {
            if (help_position == 0) // '(' at the neginning => error
              {
                error = 1;
                break;
              }

            new_position = _read_parameter_expressions(&rule.right
              [help_position - 1],rule_string + scanner.position);

            scanner.position += new_position;
          }
        else if (token == TOKEN_CHARACTER)
          {
            rule.right[help_position].character = (unsigned char) value;
            rule.right[help_position].number_of_parameters = 0;

            help_position++;
          }
        else if (token == TOKEN_END)
          break;
        else
          error = 1;
      }

    if (error)
      {
        free(rule.right);
        free(rule.condition);
      }
    else
      {
        grammar->number_of_rules++;

        grammar->rules = (t_grammar_rule *) realloc(grammar->rules,
          grammar->number_of_rules * sizeof(t_grammar_rule));

        if (grammar->rules == NULL)
          error = 1;

        grammar->rules[grammar->number_of_rules - 1] = rule;
      }

    return !error;
  }

//----------------------------------------------------------------------

int grammar_generate_string(t_grammar *grammar,
  unsigned int iterations)

  {
    t_grammar_char *buffer[2];  // 2 help buffers of grammar string
    int buffer_length[2];       // length of each buffer
    unsigned char main_buffer;  // number of currently main buffer
    unsigned char secondary_buffer;
    unsigned int iteration;
    unsigned char character;
    int value;
    int success;
    t_grammar_char *symbol_to;
    t_grammar_rule_char *symbol_from;
    int i, j, k;
    int rule_number;            // rule to apply
    int realloc_by;
    int allocated;
    int adding;
    int change_occured;

    realloc_by = 256;

    main_buffer = 0;
    secondary_buffer = 1;

    buffer_length[main_buffer] = grammar->axiom_length;

    buffer[main_buffer] = (t_grammar_char *)
      malloc(realloc_by * sizeof(t_grammar_char));

    buffer[secondary_buffer] = (t_grammar_char *)
      malloc(realloc_by * sizeof(t_grammar_char));

    if (buffer[main_buffer] == NULL || buffer[secondary_buffer] == NULL)
      return 0;

    allocated = realloc_by;

    // copy the axiom into the buffer:

    for (i = 0; i < buffer_length[main_buffer]; i++)
      buffer[main_buffer][i] = grammar->axiom[i];

    buffer_length[secondary_buffer] = 0;

    for (iteration = 0; iteration < iterations; iteration++)
      {
        change_occured = 0;

        // apply rules:

        for (i = 0; i < buffer_length[main_buffer]; i++)
          {
            rule_number = _grammar_determine_rule(grammar,
              &buffer[main_buffer][i]);

            if (rule_number >= 0)
              adding = grammar->rules[rule_number].right_length;
            else       // no rule can be applied => copy only the symbol
              adding = 1; // adding only one symbol

            // allocate more memory if needed:

            while (buffer_length[secondary_buffer] + adding >=
              allocated - 1)
              {
                buffer[main_buffer] = (t_grammar_char *)
                  realloc(buffer[main_buffer],
                  (allocated + realloc_by) * sizeof(t_grammar_char));

                buffer[secondary_buffer] = (t_grammar_char *)
                  realloc(buffer[secondary_buffer],
                  (allocated + realloc_by) * sizeof(t_grammar_char));

                if (buffer[main_buffer] == NULL ||
                  buffer[secondary_buffer] == NULL)
                  return 0;

                allocated += realloc_by;
              }

            // now copy the symbols to secondary buffer:

            if (rule_number < 0)
              {
                buffer[secondary_buffer]
                [buffer_length[secondary_buffer]] =
                buffer[main_buffer][i];

                buffer_length[secondary_buffer]++;
              }
            else
              {
                change_occured = 1;

                // fill the symbol table:

                for (j = 0; j < grammar->rules[rule_number].number_of_parameters; j++)
                  {
                    character = grammar->rules[rule_number].parameter_list[j];
                    value = buffer[main_buffer][i].parameter_values[j];

                    symbol_table.validity_map[character] = 1;
                    symbol_table.values[character] = value;
                  }

                for (j = 0; j < adding; j++)
                  {
                    symbol_from = &grammar->rules[rule_number].right[j];
                    symbol_to = &buffer[secondary_buffer]
                    [buffer_length[secondary_buffer] + j];

                    symbol_to->character = symbol_from->character;
                    symbol_to->number_of_parameters = symbol_from->number_of_parameters;

                    for (k = 0; k < symbol_from->number_of_parameters; k++)
                      {
                        symbol_to->parameter_values[k] =
                        _evaluate_expression(symbol_from->parameter_expressions[k],&symbol_table,&success);
                      }
                  }

                buffer_length[secondary_buffer] += adding;

                // invalidate the symbol table:

                for (j = 0; j < 255; j++)
                  symbol_table.validity_map[j] = 0;
              }
          }

        if (main_buffer)       // switch buffers
          {
            secondary_buffer = 1;
            main_buffer = 0;
          }
        else
          {
            secondary_buffer = 0;
            main_buffer = 1;
          }

        // delete the secondary buffer:

        buffer_length[secondary_buffer] = 0;

        if (!change_occured)
          break;
      }

    grammar->string = (t_grammar_char *) realloc(grammar->string,
      buffer_length[main_buffer] * sizeof(t_grammar_char));

    if (grammar->string == NULL)
      return 0;

    grammar->string_length = buffer_length[main_buffer];

    // copy the generated string into the grammar variable:

    for (i = 0; i < buffer_length[main_buffer]; i++)
      {
        grammar->string[i] = buffer[main_buffer][i];
      }

    free(buffer[main_buffer]);
    free(buffer[secondary_buffer]);

    return 1;
  }

//----------------------------------------------------------------------

int grammar_load_from_file(t_grammar *grammar, char *filename,
  int random)

  {
    FILE *read_file;
    int read;
    int i;
    char buffer[256];

    read_file = fopen(filename,"r");

    if (read_file == NULL)
      return 0;

    fgets(buffer,256,read_file);  // read the axiom

    for (i = 0; i < 256; i++)     // get rid of the newline
      {
        if (buffer[i] == '\n')
          {
            buffer[i] = 0;
            break;
          }
      }

    grammar_init(grammar,buffer,random);

    // read the rules:

    while (!feof(read_file))
      {
        fgets(buffer,256,read_file);

        for (i = 0; i < 256; i++)
          {
            if (buffer[i] == '\n')
              {
                buffer[i] = 0;
                break;
              }
          }

        grammar_add_rule(grammar,buffer);
      }

    fclose(read_file);

    return 1;
  }

//----------------------------------------------------------------------

int grammar_save_to_file(t_grammar *grammar, char *filename)

  {
    FILE *save_file;
    t_grammar_rule *rule;
    int i, j, k;

    save_file = fopen(filename, "w");

    if (save_file == NULL)
      return 0;

    // write the axiom:

    for (i = 0; i < grammar->axiom_length; i++)
      {
        fprintf(save_file,"%c",grammar->axiom[i].character);

        if (grammar->axiom[i].number_of_parameters != 0)
          {
            fprintf(save_file,"(");

            for (j = 0; j < grammar->axiom[i].number_of_parameters; j++)
              {
                if (j != 0)
                  fprintf(save_file,",");

                fprintf(save_file,"%d",grammar->axiom[i].parameter_values[j]);
              }

            fprintf(save_file,")");
          }
      }

    fprintf(save_file,"\n\n");

    // write the rules:

    for (i = 0; i < grammar->number_of_rules; i++)
      {
        rule = &grammar->rules[i];

        fprintf(save_file,"%c ",rule->left);

        if (rule->number_of_parameters != 0)
          {
            fprintf(save_file,"(");

            for (j = 0; j < rule->number_of_parameters; j++)
              {
                if (j != 0)
                  fprintf(save_file,", ");

                fprintf(save_file,"%c",rule->parameter_list[j]);
              }

            fprintf(save_file,") ");

            if (rule->condition != NULL)
              fprintf(save_file,"[%s] ",rule->condition);
          }

        fprintf(save_file,"-> ");

        for (j = 0; j < rule->right_length; j++)
          {
            fprintf(save_file,"%c",rule->right[j].character);

            if (rule->right[j].number_of_parameters != 0)
              {
                fprintf(save_file,"(");

                for (k = 0; k < rule->right[j].number_of_parameters; k++)
                  {
                    if (k != 0)
                      fprintf(save_file,",");

                    fprintf(save_file,"%s",rule->right[j].parameter_expressions[k]);
                  }

                fprintf(save_file,")");
              }
          }

        fprintf(save_file,"\n");
      }

    fprintf(save_file,"\n");

    fclose(save_file);

    return 1;
  }

//----------------------------------------------------------------------

void grammar_print_string(t_grammar *grammar)

  {
    int i,j;

    if (grammar == NULL)
      return;

    for (i = 0; i < grammar->string_length; i++)
      {
        printf("%c",grammar->string[i].character);

        if (grammar->string[i].number_of_parameters != 0)
          {
            printf("(");

            for (j = 0; j < grammar->string[i].number_of_parameters; j++)
              {
                if (j != 0)
                  printf(", ");

                printf("%d",grammar->string[i].parameter_values[j]);
              }

            printf(")");
          }
      }

    printf("\n");
  }

//----------------------------------------------------------------------
