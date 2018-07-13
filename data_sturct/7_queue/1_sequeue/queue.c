#include"queue.h"
void SeqQueueinit(QueueNode *queue)
{
    if(queue==NULL)
        return ;
    queue->data=(QueueType*)malloc(MAX_SIZE*sizeof(QueueType));
    queue->size=0;
    queue->head=0;
    queue->tail=0;
}
void SeqQueuePush(QueueNode *queue,QueueType value)
{
    if(queue==NULL)
        return;
    if(queue->tail>=MAX_SIZE)
    {
        queue->tail=0;
    }
    queue->data[queue->tail++]=value;
    queue->size++;
}
void SeqQueuePop(QueueNode *queue)
{
    if(queue==NULL)
        return;
    if(queue->size==0)
        return ;
    queue->head++;
    queue->size--;
    if(queue->head>=MAX_SIZE)
    {
        queue->head=0;
    }
}
#if 0 
int main()
{
    QueueNode queue;
    SeqQueueinit(&queue);
    SeqQueuePush(&queue,9);
    SeqQueuePop(&queue);
    SeqQueuePop(&queue);
    return 0;
}
#endif
