#include "AVL_binary_tree.h"
#include "tree_node.h"
#include <stdlib.h>

tree_node *
_helper_make_node (TREE_VALUE_TYPE val)
{
  tree_node *n = malloc (sizeof (tree_node));
  if (!n)
    return NULL;
  n->val = val;
  n->duplicates = 0;
  n->height = 0;
  n->left = n->right = NULL;
  return n;
}

int
_helper_get_height (tree_node *node)
{
  if (!node)
    return -1;
  else
    return node->height;
}

AVL_binary_tree *
AVL_binary_tree_constructor (TREE_VALUE_TYPE root_val)
{
  AVL_binary_tree *tree = (AVL_binary_tree *)malloc (sizeof (AVL_binary_tree));
  if (!tree)
    return NULL;

  tree->root = _helper_make_node (root_val);

  if (!tree->root)
    return NULL;

  return tree;
}

tree_node *
_helper_single_rotate_with_left (tree_node **k2)
{
  tree_node *k1 = (*k2)->left;

  (*k2)->left = k1->right;
  k1->right = *k2;

  {
    int left_h = _helper_get_height ((*k2)->left);
    int right_h = _helper_get_height ((*k2)->right);
    if (left_h > right_h)
      (*k2)->height = left_h + 1;
    else
      (*k2)->height = right_h + 1;
  }

  {
    int left_h = _helper_get_height (k1->left);
    int right_h = _helper_get_height (k1->right);
    if (left_h > right_h)
      k1->height = left_h + 1;
    else
      k1->height = right_h + 1;
  }

  *k2 = k1;

  return *k2;
}

tree_node *
_helper_double_rotate_with_left (tree_node **k3)
{
  _helper_single_rotate_with_right (&(*k3)->left);

  return _helper_single_rotate_with_left (k3);
}

tree_node *
_helper_single_rotate_with_right (tree_node **k2)
{
  tree_node *k1 = (*k2)->right;

  (*k2)->right = k1->left;
  k1->left = *k2;

  {
    int left_h = _helper_get_height ((*k2)->left);
    int right_h = _helper_get_height ((*k2)->right);
    if (left_h > right_h)
      (*k2)->height = left_h + 1;
    else
      (*k2)->height = right_h + 1;
  }

  {
    int left_h = _helper_get_height (k1->left);
    int right_h = _helper_get_height (k1->right);
    if (left_h > right_h)
      k1->height = left_h + 1;
    else
      k1->height = right_h + 1;
  }

  *k2 = k1;

  return *k2;
}

tree_node *
_helper_double_rotate_with_right (tree_node **k3)
{
  _helper_single_rotate_with_left (&(*k3)->right);
  return _helper_single_rotate_with_right (k3);
}

int
AVL_binary_tree_insert (AVL_binary_tree **tree, TREE_VALUE_TYPE val)
{
  if (!tree)
    return -1; // invalid parameter

  if (!*tree)
    {
      *tree = AVL_binary_tree_constructor (val);
      if (!*tree)
        return -2;
      return 0;
    }

  tree_node **link = &(*tree)->root;

  if (!*link)
    {
      *link = _helper_make_node (val);
      if (!*link)
        return -1;
      return 0;
    }

  stack *stk = NULL;

  while (*link)
    {
      tree_node *rt = *link;

      if (rt->val == val)
        {
          if (rt->duplicates)
            rt->duplicates++;
          else
            rt->duplicates = 1;
          break;
        }

      if (!stk)
        {
          stk = stack_constructor (link);
          if (!stk)
            return -4;
        }
      else if (stack_push (stk, link))
        {
          return -5;
        }

      if (rt->val > val)
        {
          if (rt->left)
            link = &rt->left;
          else
            {
              rt->left = _helper_make_node (val);
              if (!rt->left)
                return -1;
              break;
            }
        }
      else
        {
          if (rt->right)
            link = &rt->right;
          else
            {
              rt->right = _helper_make_node (val);
              if (!rt->right)
                return -1;
              break;
            }
        }
    }

  while (!stack_empty (stk))
    {
      tree_node **tnn = (tree_node **)stack_top_and_pop (stk);

      int left_height = _helper_get_height ((*tnn)->left);
      int right_height = _helper_get_height ((*tnn)->right);

      if (val < (*tnn)->val)
        {
          if ((left_height - right_height) == 2)
            {
              if (val < (*tnn)->left->val)
                *tnn = _helper_single_rotate_with_left (tnn);
              else
                *tnn = _helper_double_rotate_with_left (tnn);
            }
        }
      else
        {
          if ((right_height - left_height) == 2)
            {
              if (val > (*tnn)->right->val)
                *tnn = _helper_single_rotate_with_right (tnn);
              else
                *tnn = _helper_double_rotate_with_right (tnn);
            }
        }

      // recalc heights after rotation
      int new_left = _helper_get_height ((*tnn)->left);
      int new_right = _helper_get_height ((*tnn)->right);
      (*tnn)->height = (new_left > new_right) ? new_left + 1 : new_right + 1;
    }

  stack_destructor (stk);
  return 0;
}

tree_node *
AVL_binary_tree_find_VAL (AVL_binary_tree *tree, TREE_VALUE_TYPE *VAL_TO_FIND)
{
  if (!tree)
    return NULL;

  tree_node *root = tree->root;

  while (root)
    {
      if (root->val > *VAL_TO_FIND)
        root = root->left;
      else if (root->val < *VAL_TO_FIND)
        root = root->right;
      else
        return root;
    }

  return NULL;
}

tree_node *
AVL_binary_tree_find_MAX (AVL_binary_tree *tree)
{
  if (!tree)
    return NULL;

  tree_node *root = tree->root;

  while (root)
    root = root->right;

  return root;
}

tree_node *
AVL_binary_tree_find_MIN (AVL_binary_tree *tree)
{
  if (!tree)
    return NULL;

  tree_node *root = tree->root;

  while (root)
    root = root->left;

  return root;
}

void
_helper_binary_tree_destructor (stack *stk, tree_node *tr)
{
  if (!tr)
    return;

  _helper_binary_tree_destructor (stk, tr->left);
  _helper_binary_tree_destructor (stk, tr->right);

  stack_push (stk, (LIST_VALUE_TYPE)tr);
}

int
AVL_binary_tree_destructor (AVL_binary_tree *tree)
{
  if (!tree || !tree->root)
    return 0; // sucess nothing to free LOL

  stack *stk = stack_constructor ((LIST_VALUE_TYPE)tree->root);
  if (!stk)
    return -1; // failed stk allocation

  tree_node *tr = tree->root;

  _helper_binary_tree_destructor (stk, tr->left);
  _helper_binary_tree_destructor (stk, tr->right);

  while (!stack_empty (stk))
    {
      LIST_VALUE_TYPE ln = stack_top_and_pop (stk);
      free ((void *)ln);
    }

  stack_destructor (stk);

  free (tree);

  return 0; // sucess
}
