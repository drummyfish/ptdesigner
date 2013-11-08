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

    mosaic.side_shape[0] = "";
    mosaic.side_shape[1] = "";
    mosaic.side_shape[2] = "";
    mosaic.side_shape[3] = "";

    mosaic.transformation[0] = MOSAIC_TRANSFORM_SHIFT;
    mosaic.transformation[1] = MOSAIC_TRANSFORM_ROTATE_SIDE;
    mosaic.transformation[2] = MOSAIC_TRANSFORM_SHIFT;
    mosaic.transformation[3] = MOSAIC_TRANSFORM_ROTATE_SIDE;

    mosaic.tiles_x = 4;
    mosaic.tiles_y = 4;

    printf("%d\n",square_mosaic_is_valid(&mosaic));

    return 0;
  }
