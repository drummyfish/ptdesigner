#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "ptdesigner.h"

using namespace pt_design;

int main()
  {
    c_texture_graph *graph;

    graph = new c_texture_graph();

    graph->add_block(new c_block_file_save);
    graph->add_block(new c_block_perlin_noise);
    graph->add_block(new c_block_bump_noise);
    graph->add_block(new c_block_color_fill);

    graph->save_to_file("texture.xml");

    delete graph;

    return 0;
  }
