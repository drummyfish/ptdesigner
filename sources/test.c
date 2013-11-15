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
    t_color_buffer buffer,buffer2;
    unsigned char colors[5];

    color_buffer_init(&buffer,1024,2048);

    mosaic.side_shape[0] = "0.13 0.1 0.14 0.0 0.2 0.1 0.21 0.0 0.3 0.1 0.31 -0.1 0.55 -0.1";
                     //     |       |       |
    mosaic.side_shape[1] = "0.125 0.15 0.25 0.2 0.375 0.15 0.5 0.0";
    mosaic.side_shape[2] = "0.1 -0.3 0.2 0.0";
    mosaic.side_shape[3] = "0.2 -0.1";

    mosaic.transformation[0] = MOSAIC_TRANSFORM_SHIFT_MIRROR;
    mosaic.transformation[1] = MOSAIC_TRANSFORM_ROTATE_SIDE;
    mosaic.transformation[2] = MOSAIC_TRANSFORM_SHIFT_MIRROR;
    mosaic.transformation[3] = MOSAIC_TRANSFORM_ROTATE_SIDE;

    mosaic.tiles_x = 4;
    mosaic.tiles_y = 4;

    colors[0] = 100;
    colors[1] = 200;
    colors[2] = 50;
    colors[3] = 150;
    colors[4] = 75;

    pt_mosaic_square(&buffer,FILL_NONE,colors,5,&mosaic);

    pt_supersampling(&buffer,2,&buffer2);

    color_buffer_save_to_png(&buffer2,"pic.png");

    color_buffer_destroy(&buffer);
    color_buffer_destroy(&buffer2);

    return 0;
  }
