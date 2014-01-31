#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "ptdesigner.h"

using namespace pt_design;

int main()
  {

    c_texture_graph *graph = new c_texture_graph();

    graph->load_from_file("hlina.xml");
 //   cout << graph->connect_by_id(1,2,0) << endl;
    
 //   graph->delete_block_with_id(0);

    graph->compute(true);

//    graph->load_from_file("texture.xml");

    graph->print_as_text();

    delete graph;

    return 0;
  }
