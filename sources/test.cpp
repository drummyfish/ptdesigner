#include <stdio.h>
#include <string.h>

#include "ptdesigner.h"

using namespace pt_design;

int main()
  {
    c_texture_graph *graph;
    c_block *block1,*block2,*block3,*block4;

 //   block1 = new c_block_bump_noise();

    graph = new c_texture_graph();

    graph->add_block(new c_block_bump_noise());
    graph->add_block(new c_block_file_save());

    graph->get_block(1)->connect(graph->get_block(0),0);

 //   block2 = c_block::get_block_instance <c_block_file_save> (graph);

    // block2 = new c_block_file_save(graph);

 //   cout << block1->get_name() << endl;

 //   graph->set_resolution(640,480);

 //   block2->connect(block1,0);

 //   block2->compute();

 //   cout << graph->compute(false) << endl;

    graph->compute(false);

    graph->print_as_text();

    delete graph;

    return 0;
  }
