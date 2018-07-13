#pragma once
#include <stdio.h>
#include<string.h>

#define MAX_SIZE 100

typedef char HeapType;
typedef int (*compare)(HeapType a, HeapType b);
typedef struct Heap
{
    HeapType data[MAX_SIZE];
    int size;
    compare cmp;
}Heap;

void Heapinit(Heap *heap,compare cmp);
void Heapdesdroy(Heap *heap);
void Heapinsert(Heap *heap,HeapType value);
void Heaperase(Heap *heap);
void Heapsort(Heap *heap,HeapType array[],size_t size);

