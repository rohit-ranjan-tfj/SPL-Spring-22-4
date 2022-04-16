#include <stdio.h>
#include "llist.h"
#include "stack.h"
#include "queue.h"
#include "union_find.h"

typedef struct _GRAPH
{
    int n;
    int m;
    int adj_matrix[100][100];
} GRAPH;

typedef struct _EDGE
{
    int u;
    int v;
    int w;
} EDGE;

//Reads the nodes and edges of a graph from a file with name FName
//The new graph is returned.
GRAPH readGraph(char *FName);

//Does a DFS traversal of the graph G using the STACK data type (in the dynamic library), and prints out the nodes in the DFS traversal order.
void DFS(GRAPH G);

//does a BFS traversal of the graph G using the QUEUE data type (in the dynamic library)
//prints out the nodes in the BFS traversal order
void BFS(GRAPH G);

//helper function for mergesort()
void merge(EDGE list[], int left, int mid, int right);

//utility function that sorts edges in ascending order
void mergeSort(EDGE list[], int begin, int end);

//Computes the minimum spanning tree of the graph G using Kruskal’s algorithm. The function should use the UNION_FIND data structure of the dynamic library.
//The function prints out the edges added to the tree (the two endpoints and the weight), each edge in a single line, followed by the weight of the MST in the last line.
void MST(GRAPH G);

//utility function that prints adjacency matrix
void printGraph(GRAPH G);

