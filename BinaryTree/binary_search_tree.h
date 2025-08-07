#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "tree_node.h"

#ifndef LIST_VALUE_TYPE
#define LIST_VALUE_TYPE long
#endif

#include "../Stack/stack.h"

typedef struct binary_search_tree
{
  tree_node *root;
} binary_search_tree;

binary_search_tree *binary_search_tree_constructor (int root_val);
int insert_binary_search_tree (binary_search_tree *tree, int val);
int binary_search_tree_destructor (binary_search_tree *tree);

#endif
