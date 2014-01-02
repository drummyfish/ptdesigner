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

    graph->add_block(new c_block_file_save());        // 0
    graph->add_block(new c_block_substrate());        // 1
    graph->add_block(new c_block_voronoi_diagram());  // 2
    graph->add_block(new c_block_mix());              // 3
    graph->add_block(new c_block_substrate());        // 4
    graph->add_block(new c_block_mix());              // 5

    cout << graph->connect_by_id(1,3,0) << endl;
    cout << graph->connect_by_id(2,3,1) << endl;
    cout << graph->connect_by_id(3,5,0) << endl;
    cout << graph->connect_by_id(4,5,1) << endl;
    cout << graph->connect_by_id(5,0,0) << endl;

    graph->get_block_by_id(5)->get_parameters()->set_int_value("percentage",10);

    graph->set_resolution(512,640);
    graph->set_supersampling(2);

//    graph->load_from_file("texture.xml");

//    graph->print_as_text();

    graph->print_as_text();

    cout << "computing:" << graph->compute(false) << endl;

    graph->print_as_text();

    delete graph;

    return 0;
  }
