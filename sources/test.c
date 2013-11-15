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
    t_square_mosaic mosaic;
    t_color_buffer buffer,buffer2,buffer3,buffer4,buffer5;
    unsigned char colors[5];

    color_buffer_init(&buffer,512,512);

    mosaic.side_shape[0] = "0.13 0.1 0.14 0.0 0.2 0.1 0.21 0.0 0.3 0.1 0.31 -0.1 0.55 -0.1 0.8 -0.5";
                     //     |       |       |
    mosaic.side_shape[1] = "0.125 0.12 0.25 0.2 0.375 0.15 0.5 0.0 0.8 -0.3";
    mosaic.side_shape[2] = "0.1 -0.3 0.2 0.0";
    mosaic.side_shape[3] = "0.2 -0.1";

    mosaic.transformation[0] = MOSAIC_TRANSFORM_SHIFT;
    mosaic.transformation[1] = MOSAIC_TRANSFORM_SHIFT_MIRROR;
    mosaic.transformation[2] = MOSAIC_TRANSFORM_SHIFT;
    mosaic.transformation[3] = MOSAIC_TRANSFORM_SHIFT_MIRROR;

    mosaic.tiles_x = 2;
    mosaic.tiles_y = 2;

    colors[0] = 100;
    colors[1] = 50;
    colors[2] = 250;
    colors[3] = 150;
    colors[4] = 200;

    pt_mosaic_square(&buffer,FILL_NO_BORDERS,colors,5,&mosaic);



    printf("%d\n",color_buffer_load_from_png(&buffer3,"example pictures/prezentace/noises/noise voronoi many points inverted.png"));
    printf("%d\n",color_buffer_load_from_png(&buffer4,"example pictures/prezentace/noises/noise voronoi distance taxicab.png"));
    printf("%d\n",color_buffer_load_from_png(&buffer5,"example pictures/prezentace/noises/noise voronoi 2 nearest taxicab.png"));

    unsigned char c[5][3];
    t_color_buffer *buffers[5];

    buffers[0] = &buffer3;
    buffers[1] = &buffer4;
    buffers[2] = &buffer5;
    buffers[3] = &buffer4;
    buffers[4] = &buffer5;

    c[0][0] = 100;
    c[0][1] = 100;
    c[0][2] = 100;
    c[1][0] = 200;
    c[1][1] = 200;
    c[1][2] = 200;
    c[2][0] = 50;
    c[2][1] = 50;
    c[2][2] = 50;
    c[3][0] = 150;
    c[3][1] = 150;
    c[3][2] = 150;
    c[4][0] = 250;
    c[4][1] = 250;
    c[4][2] = 250;

    pt_replace_colors(&buffer,c,buffers,5);

    pt_supersampling(&buffer,2,&buffer2);

    color_buffer_save_to_png(&buffer2,"pic.png");

    color_buffer_destroy(&buffer);
    color_buffer_destroy(&buffer2);
    color_buffer_destroy(&buffer3);
    color_buffer_destroy(&buffer4);

    return 0;
  }
