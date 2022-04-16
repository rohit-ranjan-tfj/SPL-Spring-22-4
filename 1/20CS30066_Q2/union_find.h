#include <stddef.h>
#include <stdlib.h>
#include "node.h"

typedef NODE* NODE_PTR;

typedef struct _UNION_FIND
{
    NODE_PTR* nodes;
    int next_pos;
} UNION_FIND;

//creates a UNION_FIND data structure that can store n node pointers and initially, all these pointers are NULL
UNION_FIND createUF(int n);

/*
Creates a singleton set (a node) for the element x, adds to F a pointer to that node,
and returns the modified UNION_FIND structure. An int pointer is passed
additionally to return the insertion index. The library is not required to
choose the insertion indices in the sequence 0, 1, 2, … , but must guarantee
that after this index is returned, no future efforts will be made to relocate x
to another index.
*/
UNION_FIND makeSetUF(UNION_FIND F, int x, int *i);

/*
returns the ID of the set to which the element pointed to by the i-th pointer in F belongs. The ID is a
pointer to the root node of the tree containing that element. Assume that the
index i corresponding to the element being searched is known to you when
you call this function.
*/
NODE_PTR findUF(UNION_FIND F, int i);

/*
merges the sets containing the elements pointed to by the i-th and the j-th pointers of F. Assume again that
the indices i and j corresponding to the elements are known to you when
you call this function. The merging heuristic to be used is: Make the tree 
with the smaller number of nodes a subtree of the tree with the larger number of nodes.
*/
void unionUF(UNION_FIND F, int i, int j);

