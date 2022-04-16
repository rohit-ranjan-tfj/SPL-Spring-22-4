typedef LLIST STACK;

//creates an empty stack
//returns it.
STACK createStack();

//returns 1 if the stack S is empty, 0 otherwise
int isEmptyStack(STACK S);

//pushes a value k in the stack S
//returns the new stack
STACK push(STACK S, int k);

//pops the top element from the stack
//returns that element using the pointer k
//returns the new stack as the return value
STACK pop(STACK S, int *k);
