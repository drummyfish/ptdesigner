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
    double intensity;
    int i;

    t_color_buffer buffer,buffer2,buffer3,buffer4;

    color_buffer_init(&buffer,512,512);
    color_buffer_init(&buffer2,512,512);

    pt_voronoi_diagram_simple(15478,20,&buffer2);

    pt_normal_map(&buffer2,15,&buffer3);

    intensity = 0.0;

    for (i = 0; i < 5; i++)
      {
    pt_light(&buffer3,&buffer4,
      5,3,0,
      50,175,50,
      200,255,200,
      1.0,
      REFLECTION_CURVE_COSINE_SMOOTH,
      intensity,
      0.7,0.7);

        intensity += 0.5;

      switch (i)
        {
          case 0:
            color_buffer_save_to_png(&buffer4,"pic.png");
            break;

          case 1:
            color_buffer_save_to_png(&buffer4,"pic2.png");
            break;

          case 2:
            color_buffer_save_to_png(&buffer4,"pic3.png");
            break;

          case 3:
            color_buffer_save_to_png(&buffer4,"pic4.png");
            break;

          case 4:
            color_buffer_save_to_png(&buffer4,"pic5.png");
            break;
        }

      }



    color_buffer_destroy(&buffer);
    color_buffer_destroy(&buffer2);
    color_buffer_destroy(&buffer3);
    color_buffer_destroy(&buffer4);

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
