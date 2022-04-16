#include "graph.h"

//Reads the nodes and edges of a graph from a file with name FName
//The new graph is returned.
GRAPH readGraph(char *FName)
{
    FILE *fptr;
    GRAPH new_graph;

    fptr = fopen(FName,"r");
    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }

    int n,m;
    fscanf(fptr,"%d",&n);
    fscanf(fptr,"%d",&m);

    new_graph.n = n;
    new_graph.m = m;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            new_graph.adj_matrix[i][j] = 0;
        }
    }

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        fscanf(fptr,"%d %d %d",&u,&v,&w);
        new_graph.adj_matrix[u][v] = w;
        new_graph.adj_matrix[v][u] = w;
    }

    fclose(fptr);
    return new_graph;
}

//Does a DFS traversal of the graph G using the STACK data type (in the dynamic library), and prints out the nodes in the DFS traversal order.
void DFS(GRAPH G)
{
    int visited[G.n];
    for(int i=0;i<G.n;i++)
    {
        visited[i]=0;
    }

    STACK S = createStack();
    S = push(S,0);
    while (!isEmptyStack(S))
    {
        int s;
        S = pop(S,&s);
        
        if (!visited[s])
        {
            printf("%d\n",s);
            visited[s] = 1;
        }
 
        for(int i=0;i<G.n;i++)
        {
            if(G.adj_matrix[s][i]!=0)
            {
                if(!visited[i])
                {
                    S = push(S,i);
                }
            }
        }
    }
}

//does a BFS traversal of the graph G using the QUEUE data type (in the dynamic library)
//prints out the nodes in the BFS traversal order
void BFS(GRAPH G)
{
    int visited[G.n];
    for(int i=0;i<G.n;i++)
    {
        visited[i]=0;
    }

    QUEUE Q = createQueue();
    Q = enqueue(Q,0);
    while (!isEmptyQueue(Q))
    {
        int q;
        Q = dequeue(Q,&q);
        
        if (!visited[q])
        {
            printf("%d\n",q);
            visited[q] = 1;
        }
 
        for(int i=0;i<G.n;i++)
        {
            if(G.adj_matrix[q][i]!=0)
            {
                if(!visited[i])
                {
                    Q = enqueue(Q,i);
                }
            }
        }
    }
}

//helper function for mergesort()
void merge(EDGE list[], int left, int mid, int right)
{
    int size_left = mid - left + 1;
    int size_right = right - mid;
  
    EDGE leftArray[size_left];
    EDGE rightArray[size_right];    
  
    for (int i = 0; i < size_left; i++)
    {
        leftArray[i] = list[left + i];
    }
        
    for (int j = 0; j < size_right; j++)
    {
        rightArray[j] = list[mid + 1 + j];
    }
  
    int a=0,b=0; 
    int merged_idx = left; 
  
    while (a < size_left && b < size_right) 
    {
        if (leftArray[a].w <= rightArray[b].w) 
        {
            list[merged_idx] = leftArray[a];
            a++;
        }
        else 
        {
            list[merged_idx] = rightArray[b];
            b++;
        }
        merged_idx++;
    }

    while (a < size_left) {
        list[merged_idx] = leftArray[a];
        a++;
        merged_idx++;
    }
    while (b < size_right) {
        list[merged_idx] = rightArray[b];
        b++;
        merged_idx++;
    }
}

//utility function that sorts edges in ascending order
void mergeSort(EDGE list[], int begin, int end)
{
    if (begin >= end)
        return; 
  
    int mid = begin + (end - begin) / 2;
    mergeSort(list, begin, mid);
    mergeSort(list, mid + 1, end);
    merge(list, begin, mid, end);
}

//Computes the minimum spanning tree of the graph G using Kruskal’s algorithm. The function should use the UNION_FIND data structure of the dynamic library.
//The function prints out the edges added to the tree (the two endpoints and the weight), each edge in a single line, followed by the weight of the MST in the last line.
void MST(GRAPH G)
{
    EDGE list[G.m];
    int curr=0;
    for(int i=0;i<G.n;i++)
    {
        for(int j=i;j<G.n;j++)
        {
            if(G.adj_matrix[i][j]>0)
            {
                EDGE new_edge = {i,j,G.adj_matrix[i][j]}; 
                list[curr] = new_edge;
                curr++;
            }
        }
    }
    mergeSort(list,0,G.m-1);

    //  //CODE TO TEST MERGESORT
    // for(int i =0;i<G.m;i++)
    // {
    //     printf("u=%d v=%d w=%d\n",list[i].u,list[i].v,list[i].w);
    // }

    UNION_FIND F = createUF(G.n);
    for(int i=0;i<G.n;i++)
    {
        int temp;
        F = makeSetUF(F,i,&temp);
    }
    EDGE mst[G.n-1];
    curr = 0;
    for(int i=0;i<G.m;i++)
    {
        if(findUF(F,list[i].u)->value != findUF(F,list[i].v)->value)
        {
            //  //TEST CODE FOR MST INTERNALS
            // printf("u=%d v=%d pu=%d pv=%d\n",list[i].u,list[i].v,findUF(F,list[i].u)->value,findUF(F,list[i].v)->value);
            unionUF(F,list[i].u,list[i].v);
            mst[curr] = list[i];
            curr++;
        }
    }
    if(curr!=G.n-1)
    {
        printf("No MST found!");
    }
    else
    {
        int w=0;
        for(int i =0;i<G.n-1;i++)
        {
            printf("u=%d v=%d w=%d\n",mst[i].u,mst[i].v,mst[i].w);
            w+=mst[i].w;
        }
        printf("Weight of MST: %d\n",w);
    }
}

//utility function that prints adjacency matrix
void printGraph(GRAPH G)
{
    for(int i=0;i<G.n;i++)
    {
        for(int j=0;j<G.n;j++)
        {
            printf("%d ",G.adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// //TEST CODE
// int main()
// {
//     GRAPH G = readGraph("graph_test.txt");
//     printGraph(G);
//     DFS(G);
//     BFS(G);
//     MST(G);
// }