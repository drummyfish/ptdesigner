#include <stdio.h>
#include <string.h>
#include "colorbuffer.h"
#include "proctextures.h"
#include "matrix.h"
#include "colortransition.h"
#include "kdtree.h"
#include "general.h"
#include "grammar.h"

int main()
  {
    t_color_buffer buffer,buffer2,buffer3;
    t_color_transition transition;

    int i,j;
    unsigned char r,g,b;

    color_buffer_init(&buffer,1024,1024);

    pt_substrate(20,0,5000,FILL_NONE,0,&buffer);

    pt_supersampling(&buffer,2,&buffer2);

    color_buffer_save_to_png(&buffer2,"pic.png");

    color_buffer_destroy(&buffer);
    color_buffer_destroy(&buffer2);

    return 0;
  }
