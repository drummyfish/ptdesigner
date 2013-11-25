#include <stdio.h>
#include <string.h>
#include "ptdesigner.h"

int main()
  {
    t_color_transition transition;

    color_transition_load_from_file(&transition,"t.txt");

    // color_transition_init(&transition);

    color_transition_save_to_file(&transition,"t2.txt");

    color_transition_destroy(&transition);

    return 0;
  }
