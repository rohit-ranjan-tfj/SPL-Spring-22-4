typedef LLIST QUEUE;

//creates an empty queue
//returns it
QUEUE createQueue();

//returns 1 if the queue Q is empty, 0 otherwise
int isEmptyQueue(QUEUE Q);

//adds a value k to the back of the queue
//returns the new queue
QUEUE enqueue(QUEUE Q, int k);

//removes the element at the front
//returns that element using the pointer k
//returns the new queue as the return value
QUEUE dequeue(QUEUE Q, int *k);

