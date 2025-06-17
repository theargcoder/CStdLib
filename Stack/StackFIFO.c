#include "../LinkedLists/LinkedList.c"
#include <limits.h>
#include <stdlib.h>

typedef struct Stack_FIFO {
  linked_list *list;
} Stack_FIFO;

int stack_FIFO_top(Stack_FIFO *stk) {
  if (!stk)
    return INT_MIN; // invalid ass stuff

  linked_list *list = stk->list;
  if (!list)
    return INT_MIN; // error 1
  if (!list->root)
    return INT_MIN; // error 2

  return list->root->val;
}

int stack_FIFO_pop(Stack_FIFO *stk) {
  if (!stk)
    return -1; // invalid ass stuff

  linked_list *list = stk->list;
  if (!list)
    return -2; // error 2

  if (!list->root)
    return -3; // error 3

  list->root = list->root->next;
  list->size--;

  return 0;
}

int stack_FIFO_push(Stack_FIFO *stk, int val) {
  if (!stk)
    return -1; // invalid ass stuff

  linked_list *list = stk->list;
  if (!list)
    return -2; // error 2

  if (!list->back)
    return -3; // error 3

  node *nd = malloc(sizeof(node));
  if (!nd)
    return -3; // error 4

  nd->val = val;
  nd->next = NULL;

  list->back->next = nd;
  list->back = nd;
  list->size++;

  return 0;
}

int stack_FIFO_empty(Stack_FIFO *stk) {
  if (!stk)
    return 0; // invalid ass shit

  linked_list *list = stk->list;
  if (!list)
    return 0; // error 2

  return list->size == 0;
}

int stack_FIFO_top_and_pop(Stack_FIFO *stk) {
  int ret = stack_FIFO_top(stk);
  if (stack_FIFO_pop(stk) < 0)
    return INT_MIN; // error
  return ret;
}
