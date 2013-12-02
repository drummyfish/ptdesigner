#include <stdio.h>
#include <string.h>

#include "ptdesigner.h"

using namespace pt_design;

int main()
  {
    c_texture_graph *graph;
    c_block *block;


    graph = new c_texture_graph();

    block = new c_block_color_fill(graph);

    delete graph;
    return 0;
  }
