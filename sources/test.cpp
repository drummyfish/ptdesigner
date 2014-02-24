#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "ptdesigner.h"

using namespace pt_design;
using namespace std;

int main()
  {
    c_texture_graph graph;
    
    graph.add_block(new c_block_bump_noise());
    /*
    cout << graph.get_block_by_id(0)->get_parameters()->get_double_value("bump size from");
    
    graph.save_to_file("a.xml"); */
    graph.load_from_file("a.xml");
    
    cout << graph.get_block_by_id(0)->get_parameters()->get_double_value("bump size from");
    
    return 0;
  }
