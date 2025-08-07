#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

linked_list *
linked_list_constructor (int rootval)
{

  linked_list *list = malloc (sizeof (linked_list));

  if (list == NULL)
    return NULL;

  list_node *new_node = malloc (sizeof (list_node));

  if (new_node == NULL)
    return NULL;

  new_node->val = rootval;
  new_node->next = NULL;
  list->root = list->back = new_node;
  list->size = 1;

  return list;
}

void
linked_list_destructor (linked_list *list)
{
  list_node *tt = list->root, *tmp = NULL;
  while (tt)
    {
      tmp = tt->next;
      free (tt);
      tt = tmp;
    }

  free (list);
  // done
}

void
linked_list_insert_back (linked_list *list, int val)
{

  list_node *new_node = malloc (sizeof (list_node));

  if (!new_node)
    return;

  new_node->val = val;
  new_node->next = NULL;

  list->back->next = new_node;

  list->back = new_node;
  list->size++;
}

void
linked_list_delete_back (linked_list *list)
{

  if (list->size == 0)
    return;
  if (list->size == 1)
    {
      free (list->root);
      list->root = list->back = NULL;
      list->size = 0;
      return;
    }

  list_node *tt = list->root, *prev = NULL;
  while (tt)
    {
      if (tt->next == NULL)
        break;
      prev = tt;
      tt = tt->next;
    }
  free (tt);
  list->back = prev;
  prev->next = NULL;

  list->size--;
}

void
linked_list_insert_at_location (linked_list *list, int val, int location)
{

  list_node *new_node = malloc (sizeof (list_node));

  if (!new_node)
    return;

  new_node->val = val;
  if (location <= 0)
    {
      new_node->next = list->root;
      list->root = new_node;
      if (list->size == 0)
        list->back = new_node;
    }
  else
    {

      if (location > list->size)
        return;

      int ct = 1;

      list_node *tt = list->root;
      while (tt && ct < location)
        {
          tt = tt->next;
          ct++;
        }

      list_node *prevnex = tt->next;
      tt->next = new_node;
      new_node->next = prevnex;

      if (new_node->next == NULL)
        list->back = new_node;

      list->size++;
    }
}

void
linked_list_print (linked_list *list)
{
  list_node *curr = list->root;
  while (curr)
    {
      printf ("%d -> ", curr->val);
      curr = curr->next;
    }
  printf ("NULL\n");
}
