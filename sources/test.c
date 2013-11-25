#include <stdio.h>
#include <string.h>
#include "ptdesigner.h"

int main()
  {
    t_color_buffer buffer;
    t_matrix matrix;

    color_buffer_init(&buffer,512,512);

    pt_bump_noise(&buffer,0.6,0.1,1,0,1274);

    color_buffer_save_to_png(&buffer,"pic.png");


    color_buffer_destroy(&buffer);

    return 0;
  }
