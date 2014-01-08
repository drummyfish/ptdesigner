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
/*
    graph->add_block(new c_block_file_save());                   // 0
    graph->add_block(new c_block_perlin_noise());                // 1
    graph->add_block(new c_block_circle_transform());            // 2
    graph->add_block(new c_block_voronoi_diagram());             // 3
    graph->add_block(new c_block_replace_colors());              // 4
    graph->add_block(new c_block_tile());                        // 5
    graph->add_block(new c_block_normal_map());                  // 6
    graph->add_block(new c_block_light());                       // 7
    graph->add_block(new c_block_square_mosaic());               // 8

    cout << graph->connect_by_id(7,0,0) << endl;
    cout << graph->connect_by_id(6,7,0) << endl;
    cout << graph->connect_by_id(5,6,0) << endl;
    cout << graph->connect_by_id(4,5,0) << endl;
    cout << graph->connect_by_id(8,4,0) << endl;
    cout << graph->connect_by_id(2,4,1) << endl;
    cout << graph->connect_by_id(3,4,2) << endl;
    cout << graph->connect_by_id(1,2,0) << endl;

    graph->add_block(new c_block_voronoi_diagram);               // 9

    cout << "nnnn: " << graph->connect_by_id(4,3,0) << endl;
*/
    graph->load_from_file("texture.xml");

 //   cout << graph->connect_by_id(1,2,0) << endl;

/*
    graph->set_resolution(512,512);
    graph->set_supersampling(2);
*/

//    graph->load_from_file("texture.xml");

//    graph->print_as_text();

    graph->print_as_text();

    cout << "computing:" << graph->compute(false) << endl;

    graph->print_as_text();

    delete graph;

    return 0;
  }
