#ifndef AVL_BINARY_TREE
#define AVL_BINARY_TREE

#ifndef LIST_VALUE_TYPE
#define LIST_VALUE_TYPE void *
#endif

#ifndef TREE_VALUE_TYPE
#define TREE_VALUE_TYPE void *
#endif

#include "tree_node.h"

#include "../Stack/stack.h"

typedef struct AVL_binary_tree
{
  tree_node *root;
} AVL_binary_tree;

AVL_binary_tree *self_balancing_tree_constructor (TREE_VALUE_TYPE root_val);

tree_node *_helper_single_rotate_with_left (tree_node **k2);
tree_node *_helper_double_rotate_with_left (tree_node **k2);
tree_node *_helper_single_rotate_with_right (tree_node **k2);
tree_node *_helper_double_rotate_with_right (tree_node **k3);

int self_balancing_tree_insert (AVL_binary_tree *tree, TREE_VALUE_TYPE val);

int self_balancing_tree_destructor (AVL_binary_tree *tree);

tree_node *self_balancing_tree_find_VAL (AVL_binary_tree *tree,
                                         TREE_VALUE_TYPE *VAL_TO_FIND);

tree_node *self_balancing_tree_find_MAX (AVL_binary_tree *tree);

tree_node *self_balancing_tree_find_MIN (AVL_binary_tree *tree);

#endif
