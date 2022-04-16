#include <stddef.h>
#include <stdlib.h>
#include "node.h"

typedef struct _LLIST
{
    NODE *head;
} LLIST;

//creates an empty linked list
//returns it
LLIST createList();

//searches for the value k in the list H.
//returns 1 if k is found, 0 otherwise
int searchList(LLIST H, int k);

// inserts the value k at the beginning of the list H
// returns the new list
LLIST insertAtFront(LLIST H, int k);

//inserts the value k at the end of the list H
//returns the new list
LLIST insertAtEnd(LLIST H, int k);

//deletes the first element from the list
//returns the value stored in that node using the pointer k
//returns the new list 
LLIST deleteFromFront(LLIST H, int *k);

//deletes the last element from the list
//returns the value stored in that node using the pointer k
//returns the new list as the return value.
LLIST deleteFromEnd(LLIST H, int *k);

//deletes the value k from the list H if it is present. If the value k occurs multiple times, only its first occurrence in the list is deleted
//returns the new list
LLIST deleteList(LLIST H, int k);