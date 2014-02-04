#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "ptdesigner.h"

using namespace pt_design;

int main()
  {
    c_texture_graph graph;
    
    graph.add_block(new c_block_file_save());
    graph.add_block(new c_block_bump_noise());
    
    graph.connect_by_id(1,0,0);

    graph.compute(false);

    return 0;
  }
