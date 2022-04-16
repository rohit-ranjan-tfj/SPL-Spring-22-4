#include "llist.h"
#include "stack.h"

//creates an empty stack
//returns it.
STACK createStack()
{
    STACK stack = createList();
    return stack;
}

//returns 1 if the stack S is empty, 0 otherwise
int isEmptyStack(STACK S)
{
    if(S.head == NULL)
    {
        return 1;
    }
    return 0;
}

//pushes a value k in the stack S
//returns the new stack
STACK push(STACK S, int k)
{
    return insertAtFront(S,k);
}

//pops the top element from the stack
//returns that element using the pointer k
//returns the new stack as the return value
STACK pop(STACK S, int *k)
{
    return deleteFromFront(S,k);
}


// //TEST CODE
// #include <stdio.h>
// int main()
// {
//     STACK S = createStack();
//     printf("%d\n",isEmptyStack(S));
//     S = push(S,1);
//     S = push(S,2);
//     S = push(S,3);
//     S = push(S,4);
//     printf("%d\n",isEmptyStack(S));
//     int k;
//     S = pop(S,&k);
//     printf("%d\n",k);
//     printf("%d\n",isEmptyStack(S));
// }