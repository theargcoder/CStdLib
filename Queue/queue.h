#ifndef QUEUE_H
#define QUEUE_H

#ifndef LIST_VALUE_TYPE
#define LIST_VALUE_TYPE long // default type is int
#endif

#include "../LinkedLists/linked_list.h" // For linked_list and list_node

typedef struct queue
{
  linked_list *list;
} queue;

// Constructor
queue *queue_constructor (LIST_VALUE_TYPE val);

// Destructor
void queue_destructor (queue *queue);

// Top (peek at front)
LIST_VALUE_TYPE queue_top (queue *queue);

// Pop (remove front)
int queue_pop (queue *queue);

// Push (insert at back)
// returns 0 for sucess
// returns -1 for invalid shit
// returns -4 for malloc error
int queue_push (queue *queue, LIST_VALUE_TYPE val);

// Check if queue is empty
// returns 1 if empty / invalid
// returns 0 otherwise
int queue_empty (queue *queue);

// Top + Pop in one step
LIST_VALUE_TYPE queue_top_and_pop (queue *queue);

#endif
