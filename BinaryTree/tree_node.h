#ifndef TREE_NODE_H
#define TREE_NODE_H

#ifndef TREE_VALUE_TYPE
#define TREE_VALUE_TYPE int // default type is int
#endif

typedef struct tree_node
{
  TREE_VALUE_TYPE val;
  int duplicates;
  int height;

  struct tree_node *left, *right;
} tree_node;

#endif
