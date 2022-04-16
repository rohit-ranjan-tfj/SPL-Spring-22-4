#include "llist.h"

//creates an empty linked list
//returns it
LLIST createList()
{
    LLIST new_list;
    new_list.head = NULL;
    return new_list;
}

//searches for the value k in the list H.
//returns 1 if k is found, 0 otherwise
int searchList(LLIST H, int k)
{
    NODE *head = H.head;
    while(head!=NULL)
    {
        if(head->value == k)
        {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

// inserts the value k at the beginning of the list H
// returns the new list
LLIST insertAtFront(LLIST H, int k)
{
    NODE* head_old = H.head;
    NODE* new =(NODE*)malloc(sizeof(NODE));
    new->value = k;
    new->next = head_old;
    H.head = new;
    return H;
}

//inserts the value k at the end of the list H
//returns the new list
LLIST insertAtEnd(LLIST H, int k)
{
    NODE* head = H.head;
    NODE* new =(NODE*)malloc(sizeof(NODE));
    new->value = k;
    new->next = NULL;
    if(head == NULL)
    {
        H.head = new;
        return H;
    }
    while(head->next!=NULL)
    {
        head = head->next;
    }
    head->next = new;
    return H;
}

//deletes the first element from the list
//returns the value stored in that node using the pointer k
//returns the new list 
LLIST deleteFromFront(LLIST H, int *k)
{
    NODE* head = H.head;
    if(head == NULL)
    {
        k = NULL;
        return H;
    }
    *k = head->value;
    head = head->next;
    NODE* to_free = H.head;
    free(to_free);
    H.head = head;
    return H;
}

//deletes the last element from the list
//returns the value stored in that node using the pointer k
//returns the new list as the return value.
LLIST deleteFromEnd(LLIST H, int *k)
{
    NODE* head = H.head;
    if(head == NULL)
    {
        k = NULL;
        return H;
    }
    if(head->next == NULL)
    {
        *k = head->value;
        free(head);
        H.head = NULL;
        return H;
    }
    NODE* prev = head;
    head = head->next;
    while(head->next!=NULL)
    {
        head = head->next;
        prev = prev->next;
    }
    *k = head->value;
    free(head);
    prev->next = NULL;
    return H;
}

//deletes the value k from the list H if it is present. If the value k occurs multiple times, only its first occurrence in the list is deleted
//returns the new list
LLIST deleteList(LLIST H, int k)
{
    NODE *head = H.head;
    if(head == NULL)
    {
        return H;
    }
    if(head->value == k)
    {
        H.head = head->next;
        free(head);
        return H;
    }
    if(head->next == NULL)
    {
        return H;
    }
    NODE* prev = head;
    head = head->next;
    while(head!=NULL)
    {
        if(head->value == k)
        {
            prev->next = head->next;
            free(head);
            return H;
        }
        head = head->next;
        prev = prev->next;
    }
    return H;   
}


//  //TEST CODE
// #include <stdio.h>
// int main()
// {
//     LLIST list = createList();

//     list = insertAtFront(list,2);
//     list = insertAtEnd(list,3);
//     list = insertAtEnd(list,4);

//     NODE* head = list.head;
//     while(head!=NULL)
//     {
//         printf("%d\n",head->value);
//         head = head->next;
//     }

//     int k = 4;
//     list = deleteList(list,k);
//     // printf("%d\n",k);
//     head = list.head;
//     while(head!=NULL)
//     {
//         printf("%d\n",head->value);
//         head = head->next;
//     }
//     // printf("%d\n",searchList(list,2));
//     // printf("%d\n",searchList(list,4));
//     // printf("%d\n",searchList(list,3));
// }