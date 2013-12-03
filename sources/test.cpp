#include <stdio.h>
#include <string.h>

#include "ptdesigner.h"

using namespace pt_design;

int main()
  {
    c_texture_graph *graph;
    c_block *block1,*block2,*block3,*block4;


    graph = new c_texture_graph();

    block1 = new c_block_perlin_noise(graph);
    block2 = new c_block_file_save(graph);
    block4 = new c_block_file_save(graph);
    block3 = new c_block_rgb(graph);

    graph->set_resolution(640,480);

    block2->connect(block3,0);
    block3->connect(block1,0);
    block4->connect(block1,0);

    ((c_block_file_save *) block4)->set_path("texture2.png");
    ((c_block_rgb *) block3)->set_parameters(200,-20,10);

    cout << graph->compute(false) << endl;

    delete graph;
    return 0;
  }
