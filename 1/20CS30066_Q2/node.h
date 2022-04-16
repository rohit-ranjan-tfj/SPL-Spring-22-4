#ifndef NODE_DEFINED
#define NODE_DEFINED
typedef struct _NODE
{
    int value;
    int size;
    struct _NODE *next;
} NODE;
#endif