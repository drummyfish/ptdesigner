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

    cout << graph->connect_by_id(1,4,0) << endl;
    cout << graph->connect_by_id(2,4,1) << endl;
    cout << graph->connect_by_id(3,4,2) << endl;
    cout << graph->connect_by_id(4,0,0) << endl;

    graph->get_block_by_id(1)->use_custom_seed(10);

    graph->set_resolution(128,100);
    graph->set_supersampling(3);
*/
    graph->load_from_file("texture.xml");

//    graph->print_as_text();

    cout << "computing:" << graph->compute(false) << endl;

    graph->print_as_text();

    graph->save_to_file("texture2.xml");

    delete graph;

    return 0;
  }
