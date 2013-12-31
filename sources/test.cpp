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
/*
    graph->add_block(new c_block_file_save());     // 0
    graph->add_block(new c_block_perlin_noise());  // 1
    graph->add_block(new c_block_bump_noise());    // 2
    graph->add_block(new c_block_color_fill());    // 3
    graph->add_block(new c_block_mix_channels());  // 4
    graph->add_block(new c_block_voronoi());       // 5

    cout << graph->connect_by_id(1,4,0) << endl;
    cout << graph->connect_by_id(2,4,1) << endl;
    cout << graph->connect_by_id(5,4,2) << endl;
    cout << graph->connect_by_id(4,0,0) << endl;

    graph->set_resolution(256,256);
    graph->set_supersampling(2);
*/
    graph->load_from_file("texture.xml");

//    graph->print_as_text();

    cout << "computing1:" << graph->compute(false) << endl;

    graph->get_block_by_id(5)->use_custom_seed(10);
    graph->get_block_by_id(0)->get_parameters()->set_string_value("path","texture2.png");

    graph->print_as_text();

    cout << "computing2:" << graph->compute(false) << endl;

    delete graph;

    return 0;
  }
