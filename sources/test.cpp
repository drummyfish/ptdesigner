#include <stdio.h>
#include <string.h>

#include "ptdesigner.h"

int main()
  {
    t_color_buffer buffer;
    char name[] = "pic.png";

    color_buffer_init(&buffer,512,512);

    //pt_bump_noise(&buffer,0.9,0.05,1,0,758);

    // pt_marble(456, 4, 5, DIRECTION_HORIZONTAL, 128,
    //  &buffer, NULL);

 //   pt_wood(1234,4,2,30,DIRECTION_HORIZONTAL,128,
 //     &buffer,NULL);

    pt_wood_simple(1247,21,127,&buffer);

    color_buffer_save_to_png(&buffer,name);

    color_buffer_destroy(&buffer);

    return 0;
  }
