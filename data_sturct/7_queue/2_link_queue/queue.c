#include <stdio.h>
#include<stdlib.h>
typedef char QueueType;
typedef struct QueueNode
{
    QueueType data;
    struct QueueNode *next;
}QueueNode;

typedef struct LinkQueue
{
   struct QueueNode *head;
   struct QueueNode *tail;
}LinkQueue;

QueueNode* CreateNode(QueueType value)
{
    QueueNode *new_node;
    new_node=(QueueNode*)malloc(sizeof(QueueNode));
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}
LinkQueue* Queueinit(LinkQueue *queue)
{
    queue=(LinkQueue*)malloc(sizeof(LinkQueue));
    queue->head=queue->tail=CreateNode(0);
   // queue->head->next=NULL;
    return queue;
}

void QueuePush(LinkQueue *queue,QueueType value)
{
    QueueNode *tmp=CreateNode(value);
    if(queue==NULL)
        return;
    queue->tail->next=tmp;
    queue->tail=tmp;
}

int main()
{
    LinkQueue *queue;
    queue= Queueinit(queue);
    QueuePush(queue,'1');
    return 0;
}
