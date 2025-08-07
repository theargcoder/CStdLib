#include "stack.h"
#include <limits.h>
#include <stdlib.h>

stack *
stack_constructor (LIST_VALUE_TYPE val)
{
  stack *stk = malloc (sizeof (stack));
  if (!stk)
    return NULL;

  stk->list = linked_list_constructor (val);

  return (stk->list) ? stk : NULL;
}

void
stack_destructor (stack *stk)
{
  if (!stk)
    return;
  linked_list_destructor (stk->list);
  free (stk);
}

LIST_VALUE_TYPE
stack_top (stack *stk)
{
  if (!stk)
    return INT_MIN; // invalid ass stuff

  linked_list *list = stk->list;
  if (!list)
    return INT_MIN; // error 1
  if (!list->back)
    return INT_MIN; // error 2

  return list->back->val;
}

int
stack_pop (stack *stk)
{
  if (!stk)
    return -1;

  linked_list *list = stk->list;
  if (!list)
    return -2;

  if (!list->back)
    return -3;

  if (list->size == 1)
    {
      free (list->back);
      list->root = list->back = NULL;
      list->size = 0;
      return 0;
    }

  list_node *tt = list->root;
  while (tt && tt->next != list->back)
    tt = tt->next;

  free (list->back);
  list->back = tt;
  list->back->next = NULL;
  list->size--;

  return 0;
}

int
stack_push (stack *stk, int val)
{
  if (!stk)
    return -1; // invalid ass stuff

  linked_list *list = stk->list;
  if (!list)
    {
      stk->list = linked_list_constructor (val);
      return (stk->list) ? 0 : -2;
    }

  list_node *nd = malloc (sizeof (list_node));
  if (!nd)
    return -3; // error 4

  nd->val = val;
  nd->next = NULL;

  list->back->next = nd;
  list->back = nd;
  list->size++;

  return 0;
}

int
stack_empty (stack *stk)
{
  if (!stk)
    return 1; // invalid ass shit

  linked_list *list = stk->list;
  if (!list)
    return 1; // error 2

  return list->size == 0;
}

LIST_VALUE_TYPE
stack_top_and_pop (stack *stk)
{
  LIST_VALUE_TYPE ret = stack_top (stk);
  if (stack_pop (stk) < 0)
    return INT_MIN; // error
  return ret;
}
