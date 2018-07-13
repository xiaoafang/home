#pragma once
#include<stdlib.h>
#include <stdio.h>
#include<stddef.h>
#define MAX_SIZE 100
typedef int QueueType;
typedef struct QueueNode
{
    QueueType *data;
    size_t size;
    size_t head;
    size_t tail;
}QueueNode;
