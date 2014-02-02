#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "ptdesigner.h"

using namespace pt_design;

int main()
  {
    t_color_transition t,t2;
    char buffer[1000],buffer2[1000];
    
    color_transition_init(&t);
    color_transition_init(&t2);
    
    color_transition_add_point(10,100,255,20,&t);
    color_transition_add_point(50,112,10,10,&t);
    color_transition_add_point(35,20,34,78,&t);
    color_transition_add_point(99,25,41,80,&t);
    color_transition_add_point(0,100,68,11,&t);
    color_transition_add_point(255,3,2,1,&t);
    color_transition_add_point(125,20,34,11,&t);
    
    color_transition_remove_point(35,&t);
    color_transition_remove_point(200,&t);
    
    color_transition_add_point(200,100,100,100,&t);
    
    color_transition_to_string(&t,buffer,1000);
    
    color_transition_from_string(&t2,buffer);
    
    color_transition_to_string(&t2,buffer2,1000);
    
    puts(buffer);
    puts(buffer2);
    
    color_transition_destroy(&t);
    color_transition_destroy(&t2);

    return 0;
  }
