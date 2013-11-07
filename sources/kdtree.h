#ifndef KDTREE_H
#define KDTREE_H

//**********************************************************************
/** @file
 * Header file of k-d tree implementation. This data structure serves as
 * a time optimalization and should help to create Voronoi diagrams
 * faster.
 *
 * @author Miloslav Ciz
 */
//**********************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "general.h"

                                     /** k-d tree data structure node */
typedef struct kd_node
  {
    int x;                           ///< x coordination of the point
    int y;                           ///< y coordination of the point
    int x_coordination_matters;      /**< boolean attribute, if true
                                          then the node level of the
                                          tree is x coordination level,
                                          otherwise it's y level */
    struct kd_node *left;            ///< pointer to left subtree
    struct kd_node *right;           ///< pointer to right subtree
  } t_kd_tree_node;

                                     /** k-d tree data structure */
typedef struct
  {
    t_kd_tree_node *root;            ///< root node of the tree
  } t_kd_tree;

//----------------------------------------------------------------------

void kd_tree_init(t_kd_tree *tree, int points[][2], int points_length);

  /**<
   * Initializes a new k-d tree with given points.
   *
   * @param tree tree to be initialized
   * @param points two dimensional array of points to add to the tree,
   *        first array index determines points and the other determines
   *        the point coordination (0 ~ x, 1 ~ y)
   * @param points_length length of points array
   */

//----------------------------------------------------------------------

void kd_tree_find_nearest_neighbour(t_kd_tree *tree, int x, int y,
  int *nearest_x, int *nearest_y, int space_width, int space_height);

  /**<
   * Finds the nearest neighbour to given point in relatively short time
   * compared to brute-force method. Euclidean distance is used.
   *
   * @param tree tree to be searched
   * @param x x coordination of a point which we want to find the
   *        nearest neighbour of
   * @param y y coordination of a point which we want to find the
   *        nearest neighbour of
   * @param nearest_x variable in which x coordination of the nearest
   *        neighbour will be returned
   * @param nearest_y variable in which y coordination of the nearest
   *        neighbour will be returned
   * @param space_width width of the 2d space
   * @param space_height height of the 2d space
   */

//----------------------------------------------------------------------

void kd_tree_destroy(t_kd_tree *tree);

  /**<
   * Frees the memory of given k-d tree.
   *
   * @param tree tree to be destroyed.
   */

//----------------------------------------------------------------------

#endif
