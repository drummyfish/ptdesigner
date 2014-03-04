#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "ptdesigner.h"

using namespace pt_design;
using namespace std;

void progress(int a, int b)
  {
	cout << a << " " << b << endl;
  }

int main()
  {
    c_texture_graph graph;
    
    graph.add_block(new c_block_substrate());
    graph.add_block(new c_block_file_save());

    graph.set_resolution(500,500);

    graph.connect_by_id(0,1,0);
    
    graph.compute(false,progress);
    
    return 0;
  }
