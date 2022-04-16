#include "heap.h"

// to get index of parent of node at index i
int parent(int i,HEAP H) 
{ 
    i = i - H.start_index;
    return ((i-1)/2 +H.start_index); 
}
  
// to get index of left child of node at index i
int left(int i,HEAP H) 
{ 
    i = i - H.start_index;
    return ((2*i + 1)+H.start_index); 
}

// to get index of right child of node at index i
int right(int i,HEAP H) 
{ 
    i = i - H.start_index;
    return ((2*i + 2)+H.start_index); 
}

//creates an empty heap
//returns it
HEAP createHeap()
{
    HEAP new_heap;
    new_heap.heap_size=0;
    new_heap.start_index=-1;
    return new_heap;
}

//returns the minimum value in the heap H
int findMin(HEAP H)
{
    return H.arr[H.start_index%100];
}

//deletes the minimum value from the heap
//returns the modified heap
HEAP extractMin (HEAP H)
{
    H.start_index++;
    H.heap_size--;
    H = MinHeapify(H,H.start_index);
    return H;
}

//inserts the value k in the heap H
//returns the new heap
HEAP insertHeap(HEAP H, int k)
{
    if(isFullHeap(H))
    {
        //printf("Heap Overflow! Item not inserted.");
        return H;
    }
    if(isEmptyHeap(H))
    {
        H.start_index = 0;
        H.arr[0] = k;
        H.heap_size++;
        return H;
    }
    int i = H.start_index + H.heap_size;
    H.arr[i%100] = k;
    H.heap_size++;

    while (i != H.start_index && H.arr[parent(i,H)%100] > H.arr[i%100])
    {
       int temp = H.arr[parent(i,H)%100];
       H.arr[parent(i,H)%100] = H.arr[i%100];
       H.arr[i%100] = temp;
       i = parent(i,H);
    }
    return H;
}

//returns 1 if the heap is full, 0 otherwise
int isFullHeap(HEAP H)
{
    if(H.heap_size == 100)
    {
        return 1;
    }
    return 0;
}

//returns 1 if the heap is empty, 0 otherwise
int isEmptyHeap(HEAP H)
{
    if(H.heap_size == 0)
    {
        return 1;
    }
    return 0;
}

//utility function to restore min heap
HEAP MinHeapify(HEAP H, int i)
{
    int l = left(i,H);
    int r = right(i,H);
    int smallest = i;
    if (l < H.start_index + H.heap_size && H.arr[l%100] < H.arr[i%100])
        smallest = l;
    if (r < H.start_index + H.heap_size && H.arr[r%100] < H.arr[smallest%100])
        smallest = r;
    if (smallest != i)
    {
        int temp = H.arr[i%100];
        H.arr[i%100] = H.arr[smallest%100];
        H.arr[smallest%100] = temp;
        MinHeapify(H,smallest);
    }
    return H;
}

//prints the heap array
void print(HEAP H)
{
    for(int i=H.start_index;i<H.start_index+H.heap_size;i++)
    {
        printf("%d ",H.arr[i%100]);
    }
    printf("\n");
}

// //TEST CODE
// #include <stdio.h>
// int main()
// {
//     HEAP H = createHeap();

//     H = insertHeap(H,85);
//     print(H);
//     H = insertHeap(H,46);
//     print(H);
//     H = insertHeap(H,35);
//     print(H);
//     H = insertHeap(H,65);
//     print(H);
//     printf("%d\n",findMin(H));
//     H = extractMin(H);

//     printf("%d\n",findMin(H));
//     H = extractMin(H);

//     printf("%d\n",findMin(H));
//     H = extractMin(H);

//     printf("%d\n",findMin(H));
//     H = extractMin(H);
// }