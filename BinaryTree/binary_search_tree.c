#include "binary_search_tree.h"
#include <stdlib.h>

tree_node *
make_node (int val)
{
  tree_node *n = malloc (sizeof (tree_node));
  if (!n)
    return NULL;
  n->val = val;
  n->duplicates = 0;
  n->left = n->right = NULL;
  return n;
}

binary_search_tree *
binary_search_tree_constructor (int root_val)
{
  binary_search_tree *tree
      = (binary_search_tree *)malloc (sizeof (binary_search_tree));
  if (!tree)
    return NULL;

  tree->root = make_node (root_val);

  if (!tree->root)
    return NULL;

  return tree;
}

int
insert_binary_search_tree (binary_search_tree *tree, int val)
{
  if (!tree)
    return -2; // NULL TREE ERROR

  tree_node *rt = tree->root;

  if (!rt)
    return -3; // NULL ROOT ERROR

  while (rt)
    {
      if (rt->val == val)
        {
          if (rt->duplicates)
            rt->duplicates++;
          else
            rt->duplicates = 1;
          return 0; // success
        }
      if (rt->val > val)
        {
          if (rt->left)
            rt = rt->left;
          else
            {
              rt->left = make_node (val);
              if (!rt->left)
                return -1; // MALLOC ERROR
            }
        }
      else if (rt->val < val)
        {
          if (rt->right)
            rt = rt->right;
          else
            {
              rt->right = make_node (val);
              if (!rt->right)
                return -1; // MALLOC ERROR
            }
        }
    }

  return 0; // success
}

void
_binary_search_tree_destructor_helper_dfs (stack *stk, tree_node *tr)
{
  if (!tr)
    return;

  _binary_search_tree_destructor_helper_dfs (stk, tr->left);
  _binary_search_tree_destructor_helper_dfs (stk, tr->right);

  stack_push (stk, (LIST_VALUE_TYPE)tr);
}

int
binary_search_tree_destructor (binary_search_tree *tree)
{
  if (!tree || !tree->root)
    return 0; // sucess nothing to free LOL

  stack *stk = stack_constructor ((LIST_VALUE_TYPE)tree->root);
  if (!stk)
    return -1; // failed stk allocation

  tree_node *tr = tree->root;

  _binary_search_tree_destructor_helper_dfs (stk, tr->left);
  _binary_search_tree_destructor_helper_dfs (stk, tr->right);

  while (!stack_empty (stk))
    {
      LIST_VALUE_TYPE ln = stack_top_and_pop (stk);
      free ((void *)ln);
    }

  stack_destructor (stk);

  free (tree);

  return 0; // sucess
}
