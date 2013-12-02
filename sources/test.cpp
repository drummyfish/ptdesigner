#include <stdio.h>
#include <string.h>

#include "ptdesigner.h"

using namespace pt_design;

int main()
  {
    c_texture_graph *graph;
    c_block *block1,*block2;


    graph = new c_texture_graph();

    block1 = new c_block_bump_noise(graph);
    block2 = new c_block_file_save(graph);

    block2->connect(block1,0);

    graph->set_resolution(720,300);

    cout << graph->compute(false) << endl;


    graph->set_resolution(800,800);
    ((c_block_file_save *) block2)->set_path("texture2.png");

    cout << graph->compute(false) << endl;

    delete graph;
    return 0;
  }
