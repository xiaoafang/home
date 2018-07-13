#include "heap.h"
int Less(HeapType a,HeapType b)
{
    return a<b ? 1:0;
}
int Greater(HeapType a,HeapType b)
{
    return a>b ? 1:0;
}
void Heapinit(Heap *heap,compare cmp)
{
    if(heap==NULL)
        return ;
    heap->size=0;
    heap->cmp=cmp;  
}
void Heapdesdroy(Heap *heap)
{
    if(heap==NULL)
        return ;
    heap->size=0;
}
void swap(HeapType *a,HeapType *b)
{
    HeapType temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void adjustup(Heap *heap,size_t index)
{
    int child=index;
    int parent=(child-1)/2;
    while(child>0)
    {
        if(heap->cmp(heap->data[child] , heap->data[parent])) //函数指针，如果孩子结点小于父节点，小堆
            swap(&heap->data[child],&heap->data[parent]);
        else
            break;
        child=parent;
        parent=(child-1)/2;
    }
}
void Heapinsert(Heap *heap,HeapType value)
{
    if(heap==NULL)
        return ;
    if(heap->size>MAX_SIZE)
        return;
    heap->data[heap->size++]=value;
    adjustup(heap,heap->size-1);//!
}
void adjustdown(Heap *heap)
{
    int parent = 0;
    int child = (parent*2)+1;
    while(child>0 && child<heap->size && parent>=0 && parent<heap->size)
    {
        if(child+1<heap->size&&heap->data[child+1]<heap->data[child])
            child=child+1;
        if(!heap->cmp(heap->data[parent],heap->data[child]))            //用函数指针
            swap(&heap->data[parent],&heap->data[child]);
        else
            break;
        parent=child;
        child=(parent*2)+1;
    }
}
void Heaperase(Heap *heap)
{
    if(heap==NULL)
        return;
    if(heap->size==0)
        return;
    swap(&heap->data[0],&heap->data[heap->size-1]);
    heap->size--;
    adjustdown(heap);

}
void Heapsort(Heap *heap,HeapType array[],size_t size)
{
    int i=0,j=0;
    for(;i<size;i++)
    {
        Heapinsert(heap,array[i]);
    }
    //while(heap->size>0)
    for(j;j<size;j++)
    {
        Heaperase(heap);//每擦除一个，size就--，所以不能用print函数打印结果
    }
    memcpy(array,heap->data,size*sizeof(HeapType));
}
void print(Heap *heap)
{
    if(heap==NULL)
        return;
    int i=0;
    for(i;i<heap->size;i++)
    {
        printf("%c ",heap->data[i]);
    }
}
int main()
{
    Heap heap;
    Heapinit(&heap,Less);
   // Heapinsert(&heap,'9');        //  9       9         5       2           2           1
   // Heapinsert(&heap,'5');       //5     2           9       9     5     7     5     2    5
   // Heapinsert(&heap,'2');      //7 1                                  9           9   7       
   // Heapinsert(&heap,'7');
   // Heapinsert(&heap,'1');
   // Heaperase(&heap);
    char a[]="2145687943";
    Heapsort(&heap,a,10);
    int i=0;
    for(;i<10;i++)
        printf("%c ",a[i]);
    //    print(&heap);
    return 0;
}
