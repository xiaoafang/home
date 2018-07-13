#pragma once
#include<stdlib.h>
#include <stdio.h>
#include<stddef.h>
#define MAX_SIZE 100

//typedef char TreeType;
//typedef struct TreeNode
//{
//    TreeType data;
//    struct TreeNode *lchild;
//     struct TreeNode *rchild;
// }TreeNode;
//
struct TreeNode;
typedef struct TreeNode QueueType;
typedef struct QueueNode
{
    QueueType *data;
    size_t size;
    size_t head;
    size_t tail;
}QueueNode;

void SeqQueueinit(QueueNode *queue);
void SeqQueuePush(QueueNode *queue,QueueType *value);
void SeqQueuePop(QueueNode *queue);
void SeqQueuefront(QueueNode *queue,QueueType *value);

