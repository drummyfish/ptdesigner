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
    t_color_buffer buffer;
    t_matrix matrix;

    //color_buffer_init(&buffer,512,512);

    //pt_voronoi_diagram_random(VORONOI_2_NEAREST_RATIO,METRIC_EUCLIDEAN,
    //  5478,10,&buffer);

    color_buffer_load_from_png(&buffer,"example pictures/light 5.png");

    pt_dithering(&buffer,20,DITHERING_ORDERED);

    color_buffer_save_to_png(&buffer,"pic.png");

    color_buffer_destroy(&buffer);

    return 0;
  }
