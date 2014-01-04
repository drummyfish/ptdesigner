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

    graph->add_block(new c_block_file_save());           // 0
    graph->add_block(new c_block_file_load());           // 1
    graph->add_block(new c_block_brightness_contrast()); // 2

    cout << graph->connect_by_id(1,2,0) << endl;
    cout << graph->connect_by_id(2,0,0) << endl;

    graph->set_resolution(512,480);
    graph->set_supersampling(1);

    graph->get_block_by_id(2)->get_parameters()->set_double_value("contrast",0.8);

//    graph->load_from_file("texture.xml");

//    graph->print_as_text();

    graph->print_as_text();

    cout << "computing:" << graph->compute(false) << endl;

    graph->print_as_text();

    delete graph;

    return 0;
  }
