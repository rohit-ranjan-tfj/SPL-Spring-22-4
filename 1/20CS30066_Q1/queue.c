#include "llist.h"
#include "queue.h"

//creates an empty queue
//returns it
QUEUE createQueue()
{
    QUEUE Q = createList();
    return Q;
}

//returns 1 if the queue Q is empty, 0 otherwise
int isEmptyQueue(QUEUE Q)
{
    if(Q.head == NULL)
    {
        return 1;
    }
    return 0;
}

//adds a value k to the back of the queue
//returns the new queue
QUEUE enqueue(QUEUE Q, int k)
{
    return insertAtEnd(Q,k);
}

//removes the element at the front
//returns that element using the pointer k
//returns the new queue as the return value
QUEUE dequeue(QUEUE Q, int *k)
{
    return deleteFromFront(Q,k);
}

// //TEST CODE
// #include <stdio.h>
// int main()
// {
//     QUEUE S = createQueue();
//     printf("%d\n",isEmptyQueue(S));
//     S = enqueue(S,1);
//     S = enqueue(S,2);
//     S = enqueue(S,3);
//     S = enqueue(S,4);
//     printf("%d\n",isEmptyQueue(S));
//     int k;
//     S = dequeue(S,&k);
//     printf("%d\n",k);
//     S = dequeue(S,&k);
//     printf("%d\n",k);
//     S = dequeue(S,&k);
//     printf("%d\n",k);
//     S = dequeue(S,&k);
//     printf("%d\n",k);
//     printf("%d\n",isEmptyQueue(S));
// }