#include "queue.h"
#include <limits.h>
#include <stdlib.h>

queue *
queue_constructor (LIST_VALUE_TYPE val)
{
  queue *que = malloc (sizeof (queue));
  if (!que)
    return NULL;

  que->list = linked_list_constructor (val);

  return (que->list) ? que : NULL;
}

void
queue_destructor (queue *queue)
{
  if (!queue)
    return;
  linked_list_destructor (queue->list);
  free (queue);
}

LIST_VALUE_TYPE
queue_top (queue *queue)
{
  if (!queue)
    return INT_MIN; // invalid ass stuff

  linked_list *list = queue->list;
  if (!list)
    return INT_MIN; // error 1
  if (!list->root)
    return INT_MIN; // error 2

  return list->root->val;
}

int
queue_pop (queue *queue)
{
  if (!queue)
    return -1; // invalid ass stuff

  linked_list *list = queue->list;
  if (!list)
    return -2; // error 2

  if (!list->root)
    return -3; // error 3

  list_node *tt = list->root;
  list->root = list->root->next;
  list->size--;

  free (tt);

  return 0;
}

int
queue_push (queue *queue, int val)
{
  if (!queue)
    return -1; // invalid ass stuff

  list_node *nd = malloc (sizeof (list_node));
  if (!nd)
    return -3; // error 4

  linked_list *list = queue->list;
  if (!list)
    {
      queue->list = linked_list_constructor (val);
      return (list) ? 0 : -2;
    }

  nd->val = val;
  nd->next = NULL;

  list->back->next = nd;
  list->back = nd;
  list->size++;

  return 0;
}

int
queue_empty (queue *queue)
{
  if (!queue)
    return 1; // invalid ass shit

  linked_list *list = queue->list;
  if (!list)
    return 1; // error 2

  return list->size == 0;
}

LIST_VALUE_TYPE
queue_top_and_pop (queue *queue)
{
  LIST_VALUE_TYPE ret = queue_top (queue);
  if (queue_pop (queue) < 0)
    return INT_MIN; // error
  return ret;
}
