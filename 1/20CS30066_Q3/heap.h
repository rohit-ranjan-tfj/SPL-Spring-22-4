#include <stdio.h>

typedef struct _HEAP
{
    int arr[100];
    int start_index;
    int heap_size;
} HEAP;

// to get index of parent of node at index i
int parent(int i,HEAP H);

// to get index of left child of node at index i
int left(int i,HEAP H);

// to get index of right child of node at index i
int right(int i,HEAP H);

//creates an empty heap
//returns it
HEAP createHeap();

//returns the minimum value in the heap H
int findMin(HEAP H);

//deletes the minimum value from the heap
//returns the modified heap
HEAP extractMin (HEAP H);

//inserts the value k in the heap H
//returns the new heap
HEAP insertHeap(HEAP H, int k);

//returns 1 if the heap is full, 0 otherwise
int isFullHeap(HEAP H);

//returns 1 if the heap is empty, 0 otherwise
int isEmptyHeap(HEAP H);

//prints the heap array
void print(HEAP H);

//utility function to restore min heap
HEAP MinHeapify(HEAP H, int i);