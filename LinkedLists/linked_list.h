#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "list_node.h" // for list_node
#include <stddef.h>    // for NULL

typedef struct linked_list
{
  int size;
  struct list_node *root, *back;
} linked_list;

// Constructor and destructor
linked_list *linked_list_constructor (int rootval);
void linked_list_destructor (linked_list *list);

// Insertion and deletion
void linked_list_insert_back (linked_list *list, LIST_VALUE_TYPE val);
void linked_list_delete_back (linked_list *list);
void linked_list_insert_at_location (linked_list *list, LIST_VALUE_TYPE val,
                                     int location);

// Debug/utility
void linked_list_print (linked_list *list);

#endif
