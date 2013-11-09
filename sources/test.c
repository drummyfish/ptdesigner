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
    t_color_buffer b,b2,b3,b4;
    t_grammar g;

    color_buffer_init(&b,1024,1024);

    grammar_load_from_file(&g,"testgrammar.txt",4567);

    grammar_generate_string(&g,50);

    pt_turtle_draw(&b,&g,0.5,0.35,0.0,0.2,0.8);

    pt_supersampling(&b,2,&b2);

    color_buffer_save_to_png(&b2,"pic.png");

    color_buffer_destroy(&b);
    color_buffer_destroy(&b2);

    return 0;

      /*
    t_square_mosaic mosaic;
    t_color_buffer buffer;

    color_buffer_init(&buffer,512,512);

    mosaic.side_shape[0] = "0.3 0.2";
                     //     |       |       |
    mosaic.side_shape[1] = "0.8 0.1 0.3 0.1";
    mosaic.side_shape[2] = "";
    mosaic.side_shape[3] = "";

    mosaic.transformation[0] = MOSAIC_TRANSFORM_SHIFT;
    mosaic.transformation[1] = MOSAIC_TRANSFORM_ROTATE_SIDE;
    mosaic.transformation[2] = MOSAIC_TRANSFORM_SHIFT;
    mosaic.transformation[3] = MOSAIC_TRANSFORM_ROTATE_SIDE;

    mosaic.tiles_x = 4;
    mosaic.tiles_y = 4;

    pt_mosaic_square(&buffer,FILL_KEEP_BORDERS,NULL,&mosaic);

    color_buffer_destroy(&buffer);

    return 0; */
  }
