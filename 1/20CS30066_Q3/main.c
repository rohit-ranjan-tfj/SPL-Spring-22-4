#include "graph.h"
#include <stdio.h>

int main()
{
    char* str[100];
    printf("\nEnter file path: ");
    scanf("%[^\n]s", &str);
    printf("%s",str);
    GRAPH G = readGraph(str);
    printf("\n\nSuccessfully read the graph.\n");
    printf("\nDFS Traversal:\n");
    DFS(G);
    printf("\nBFS Traversal:\n");
    BFS(G);
    printf("\nMST on the graph:\n");
    MST(G);
}