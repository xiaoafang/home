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
void SeqQueuePush(QueueNode *queue,QueueType *value)
{
    if(queue==NULL)
        return;
    if(queue->tail>=MAX_SIZE)
    {
        queue->tail=0;
    }
    queue->data[queue->tail++]=*value;
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
void SeqQueuefront(QueueNode *queue,QueueType *value)
{
    if(queue==NULL)
        return;
    if(queue->size==0)
        return ;
    *value=queue->data[queue->head];

}
#if 0 
int main()
{
    QueueType a;
    QueueNode queue;
    SeqQueueinit(&queue);
    SeqQueuePush(&queue,9);
    SeqQueuePush(&queue,3);
    SeqQueuePush(&queue,4);
    SeqQueuePush(&queue,7);
    SeqQueuefront(&queue,&a);
    printf("%d ",a);
    return 0;
}
#endif
