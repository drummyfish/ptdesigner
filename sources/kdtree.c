//**********************************************************************
/** @file
 * Implementation of k-d tree data structure.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include "kdtree.h"

//----------------------------------------------------------------------

  /**
   * Private function which adds a point into k-d subtree.
   *
   * @param node k-d node to add the point to
   * @param x x coordination of point being added
   * @param y y coordination of point being added
   * @param compare_x boolean parameter telling whether to compare
   *   x coordinations (true) or y coordinations (false)
   *
   * @return 1 if the point was added succesfully, otherwise 0
   */

int _kd_tree_add(t_kd_tree_node **node, int x, int y, int compare_x)

  {
    int new_compare;           /* compare the other coordination in the
                                  next level */

    new_compare = compare_x ? 0 : 1;

    if (*node == NULL)
      {
        *node = (t_kd_tree_node *) malloc(sizeof(t_kd_tree_node));

        if (*node == NULL)
          return 0;            // malloc fail

        (*node)->x = x;
        (*node)->y = y;
        (*node)->left = NULL;
        (*node)->right = NULL;
        (*node)->x_coordination_matters = compare_x;
      }
    else if (compare_x)        // compare x
      {
        if (x > (*node)->x)
          _kd_tree_add(&(*node)->right,x,y,new_compare);
        else
          _kd_tree_add(&(*node)->left,x,y,new_compare);
      }
    else                       // compare y
      {
        if (y > (*node)->y)
          _kd_tree_add(&(*node)->right,x,y,new_compare);
        else
          _kd_tree_add(&(*node)->left,x,y,new_compare);
      }

    return 1;                  // added succesfully
  }

//----------------------------------------------------------------------

  /**
   * Private debugging purpose functions that prints k-d subtree to
   * stdout.
   *
   * @param node subtree to be printed
   */

void _kd_tree_print(t_kd_tree_node *node)

  {
    if (node == NULL)
      return;

    printf("%d,%d(",node->x,node->y);
    _kd_tree_print(node->left);
    printf(", ");
    _kd_tree_print(node->right);
    printf(")");
  }

//----------------------------------------------------------------------

  /**
   * Private function - frees a memory of given k-d node.
   *
   * @param node node to be destroyed
   */

void _kd_tree_destroy_node(t_kd_tree_node *node)

  {
    if (node != NULL)
      {
        _kd_tree_destroy_node(node->left);   // destroy left subtree
        _kd_tree_destroy_node(node->right);  // destroy right subtree
        free(node);                         // destroy this node
      }
  }

//----------------------------------------------------------------------

  /**
   * Private function - does the internal stuff for find nearest
   * neighbour public function.
   *
   * @param node node to be searched
   * @param x x coordination of a point which we want to find the
   *   nearest neighbour of
   * @param y y coordination of a point which we want to find the
   *   nearest neighbour of
   * @param nearest_x variable in which x coordination of the nearest
   *   neighbour will be returned
   * @param nearest_y variable in which y coordination of the nearest
   *   neighbour will be returned
   * @param space_width width of the 2d space
   * @param space_height height of the 2d space
   */

void _kd_tree_find_nearest_help(t_kd_tree_node *node, int x, int y,
  int *nearest_x, int *nearest_y, int space_width, int space_height)

  {
    int split;                  // split point coordination
    int space_limit;            /* either 0 or space_width or
                                   space_height */
    int circle_radius;          // compare cicle radius
    int point_coordination;
    int best_x, best_y, help_x, help_y;

    if (node->left == NULL && node->right == NULL)  // leaf node
      {
        *nearest_x = node->x;
        *nearest_y = node->y;
        return;                      // return this node's coordinations
      }

    if (node->x_coordination_matters)   // setting help variables
      {
        split = node->x;
        point_coordination = x;
      }
    else
      {
        split = node->y;
        point_coordination = y;
      }

    if (point_coordination <= split)
      space_limit = 0;
    else
      if (node->x_coordination_matters)
        space_limit = space_width;
      else
        space_limit = space_height;

    circle_radius =                     // set minimum circle radius
      abs(point_coordination - split) <
      abs(space_limit - point_coordination) ?
      abs(point_coordination - split) :
      abs(space_limit - point_coordination);

    best_x = node->x;
    best_y = node->y;                   // here we have variables set

             /* find the best point in left subtree (if there is one) */

    if (node->left != NULL)
      {
        _kd_tree_find_nearest_help(node->left,x,y,&help_x,&help_y,
          space_width,space_height);

        if (get_distance(METRIC_EUCLIDEAN,x,y,help_x,help_y,space_width,
          space_height) < get_distance(METRIC_EUCLIDEAN,x,y,best_x,
          best_y,space_width,space_height))
          {
            best_x = help_x;
            best_y = help_y;
          }
      }

    /* here we may skip searching the right subtree if the circle
       doesn't cross the split line (and neither space limit) */
    if (node->right != NULL)
      {
        if(get_distance(METRIC_EUCLIDEAN,x,y,best_x,best_y,space_width,
          space_height) >= circle_radius)
          {
            _kd_tree_find_nearest_help(node->right,x,y,&help_x,&help_y,
              space_width,space_height);

            if (get_distance(METRIC_EUCLIDEAN,x,y,help_x,help_y,
              space_width,space_height) < get_distance(METRIC_EUCLIDEAN,
              x,y,best_x,best_y,space_width,space_height))
              {
                best_x = help_x;
                best_y = help_y;
              }

          }
      }

    *nearest_x = best_x;
    *nearest_y = best_y;
  }

//----------------------------------------------------------------------

void kd_tree_init(t_kd_tree *tree, int points[][2], int points_length)

  {
    int i;

    tree->root = NULL;

    for (i = 0; i < points_length; i++)       // add all points
      _kd_tree_add(&tree->root,points[i][0],points[i][1],1);
  }

//----------------------------------------------------------------------

void kd_tree_destroy(t_kd_tree *tree)

  {
    _kd_tree_destroy_node(tree->root);
    tree->root = NULL;
  }

//----------------------------------------------------------------------

void kd_tree_find_nearest_neighbour(t_kd_tree *tree, int x, int y,
  int *nearest_x, int *nearest_y, int space_width, int space_height)

  {
    _kd_tree_find_nearest_help(tree->root,x,y,nearest_x,nearest_y,
      space_width,space_height);
  }

//----------------------------------------------------------------------
