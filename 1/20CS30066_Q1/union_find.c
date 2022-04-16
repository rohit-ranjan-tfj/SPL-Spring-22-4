#include "union_find.h"

//creates a UNION_FIND data structure that can store n node pointers and initially, all these pointers are NULL
UNION_FIND createUF(int n)
{
    UNION_FIND F;
    NODE_PTR* nodes = (NODE_PTR*)malloc(n*sizeof(NODE_PTR));
    for(int i =0;i<n;i++)
    {
        nodes[i] = NULL;
    }
    F.nodes = nodes;
    F.next_pos = 0;
    return F;
}

/*
Creates a singleton set (a node) for the element x, adds to F a pointer to that node,
and returns the modified UNION_FIND structure. An int pointer is passed
additionally to return the insertion index. The library is not required to
choose the insertion indices in the sequence 0, 1, 2, … , but must guarantee
that after this index is returned, no future efforts will be made to relocate x
to another index.
*/
UNION_FIND makeSetUF(UNION_FIND F, int x, int *i)
{
    NODE_PTR new_ptr = (NODE_PTR)malloc(sizeof(NODE));
    new_ptr->value = x;
    new_ptr->size = 1;
    new_ptr->next = NULL;
    F.nodes[F.next_pos] = new_ptr;
    *i = F.next_pos;
    F.next_pos++;
    return F;
}

/*
returns the ID of the set to which the element pointed to by the i-th pointer in F belongs. The ID is a
pointer to the root node of the tree containing that element. Assume that the
index i corresponding to the element being searched is known to you when
you call this function.
*/
NODE_PTR findUF(UNION_FIND F, int i)
{
    NODE_PTR curr = F.nodes[i];
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    return curr;
}

/*
merges the sets containing the elements pointed to by the i-th and the j-th pointers of F. Assume again that
the indices i and j corresponding to the elements are known to you when
you call this function. The merging heuristic to be used is: Make the tree 
with the smaller number of nodes a subtree of the tree with the larger number of nodes.
*/
void unionUF(UNION_FIND F, int i, int j)
{
    NODE_PTR i_root = findUF(F,i);
    NODE_PTR j_root = findUF(F,j);
    if(i_root->size>j_root->size)
    {
        j_root->next = i_root;
    }
    else if(i_root->size==j_root->size)
    {
        j_root->next = i_root;
        i_root->size++;
    }
    else
    {
        i_root->next = j_root;
    }
}


// //TEST CODE
// #include <stdio.h>
// int main()
// {
//     UNION_FIND F = createUF(16);
//     int i;
//     F = makeSetUF(F,1,&i);
//     F = makeSetUF(F,2,&i);
//     F = makeSetUF(F,3,&i);
//     F = makeSetUF(F,4,&i);
//     F = makeSetUF(F,5,&i);
//     F = makeSetUF(F,6,&i);
//     F = makeSetUF(F,7,&i);
//     F = makeSetUF(F,8,&i);
//     F = makeSetUF(F,9,&i);

//     unionUF(F,0,1);
//     unionUF(F,1,2);
//     unionUF(F,3,4);
//     unionUF(F,3,5);
//     unionUF(F,3,6);

//     printf("%d\n",findUF(F,0)->value);
//     printf("%d\n",findUF(F,1)->value);
//     printf("%d\n",findUF(F,2)->value);
//     printf("%d\n",findUF(F,3)->value);
//     printf("%d\n",findUF(F,4)->value);
//     printf("%d\n",findUF(F,5)->value);
//     printf("%d\n",findUF(F,6)->value);
//     printf("%d\n",findUF(F,7)->value);
//     printf("%d\n",findUF(F,8)->value);
// }