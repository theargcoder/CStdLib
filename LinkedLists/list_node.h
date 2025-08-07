#ifndef LIST_NODE
#define LIST_NODE

#ifndef LIST_VALUE_TYPE
#define LIST_VALUE_TYPE int // default type is int
#endif

typedef struct list_node
{
  LIST_VALUE_TYPE val;
  struct list_node *next;
} list_node;

#endif
