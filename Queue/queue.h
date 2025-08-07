#ifndef QUEUE_H
#define QUEUE_H

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
int queue_top (queue *queue);

// Pop (remove front)
int queue_pop (queue *queue);

// Push (insert at back)
int queue_push (queue *queue, LIST_VALUE_TYPE val);

// Check if queue is empty
int queue_empty (queue *queue);

// Top + Pop in one step
int queue_top_and_pop (queue *queue);

#endif
