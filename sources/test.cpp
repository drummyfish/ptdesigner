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

    graph->add_block(new c_block_file_save());  // 0
    graph->add_block(new c_block_substrate());  // 1

    cout << graph->connect_by_id(1,0,0) << endl;

    graph->set_resolution(512,640);
    graph->set_supersampling(3);

//    graph->load_from_file("texture.xml");

//    graph->print_as_text();

    graph->print_as_text();

    cout << "computing:" << graph->compute(false) << endl;

    graph->print_as_text();

    delete graph;

    return 0;
  }
