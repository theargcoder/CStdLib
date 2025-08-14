#ifndef STACK_H
#define STACK_H

#ifndef LIST_VALUE_TYPE
#define LIST_VALUE_TYPE int // default type is int
#endif

#include "../LinkedLists/linked_list.h" // for linked_list and list_node

typedef struct stack
{
  linked_list *list;
} stack;

// Constructor
stack *stack_constructor (LIST_VALUE_TYPE val);

// Destructor
void stack_destructor (stack *stk);

// Top (peek at top element)
LIST_VALUE_TYPE stack_top (stack *stk);

// Pop (remove top element)
int stack_pop (stack *stk);

// Push (add to top)
int stack_push (stack *stk, LIST_VALUE_TYPE val);

// Check if empty
int stack_empty (stack *stk);

// Top + Pop in one step
LIST_VALUE_TYPE stack_top_and_pop (stack *stk);

#endif
