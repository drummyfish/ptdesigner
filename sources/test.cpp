#include <stdio.h>
#include <string.h>

#include "ptdesigner.h"

int main()
  {
    t_color_buffer buffer;

    color_buffer_init(&buffer,150,150);

    pt_bump_noise(&buffer,0.9,0.05,1,0,758);

    color_buffer_save_to_png(&buffer,"pic.png");

    color_buffer_destroy(&buffer);

    return 0;
  }
