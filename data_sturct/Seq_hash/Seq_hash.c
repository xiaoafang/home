#include <stdio.h>
//创建哈希表，和哈希结点

#define MAX_SIZE 13
typedef int Typeval;
typedef int Typekey;

typedef int (*Hashfun)(Typekey);

typedef enum Stat
{
    empty,
    valid,
}Stat;
typedef struct HashNode
{
    Typeval val;
    Typekey key;
    Stat st;
}HashNode;
typedef struct Hashtable
{
    HashNode data[MAX_SIZE];
    int size;
    Hashfun func;  
}Hashtable;

int Hashfunc(Typekey key)
{
    return key%MAX_SIZE;
}
void Hashinit(Hashtable *hash)
{
    if(hash==NULL)
        return ;
    hash->size=0;
    hash->func=Hashfunc;
    int i;
    for(i=0;i<MAX_SIZE;i++)
    {
        hash->data[i].st=empty;
        hash->data[i].val=0;
    }
}
void Hashinsert(Hashtable *hash,Typekey key,Typeval value)
{
    //判断是否超过负载因子，如果超过就直接返回
    //根据key值计算要插入的哈希表的位置
    //如果位置为空直接插入，如果插入重复元素直接返回,如果插入位置不为空，线性探测
    if(hash==NULL)
        return ;
    if(hash->size>=0.8*MAX_SIZE)
    {
        return ;
    }
    int offset;
    offset=hash->func(key);
    while(1)
    {
        if(hash->data[offset].st==empty)
        {
            hash->data[offset].val=value;
            hash->data[offset].key=key;
            hash->data[offset].st=valid;
            hash->size++;
            return ;
        }
        else if(hash->data[offset].key==key && hash->data[offset].st==valid)
            return;
        else {
            offset++;
            if(offset>=MAX_SIZE)
            {
                offset=0;
            }
        }
    }
}
void Hashfind(Hashtable *hash,Typekey key,Typeval *value)
{
    //根据key值计算要查找的元素的位置
    //如果位置为空，直接返回，如果位置不为空，判断key值是否为要找的元素，如果不是线性探测
    if(hash==NULL)
        return;
    int offset;
    offset=hash->func(key);
    while(1)
    {
        if(hash->data[offset].st==empty)
            return ;
        else if(hash->data[offset].key==key && hash->data[offset].st==valid)
        {
            *value = hash->data[offset].val;
            return;
        }
        else
        {
            offset++;
            if(offset>=MAX_SIZE)
                offset=0;
        }
    }
}
void Hashremove(Hashtable *hash,Typekey key)
{
    //判断哈希表是否为空，为空直接返回
    //根据key值计算值在哈希表中的位置，如果为空直接返回，不为空和key值相等直接删除，和key值不等线性探测
    if(hash==NULL)
        return ;
    if(hash->size==0)
        return;
    int offset;
    offset=hash->func(key);
    while(1)
    {
        if(hash->data[offset].st==empty)
            return;
        else if(hash->data[offset].key==key && hash->data[offset].st==valid)
        {
            hash->data[offset].st=empty; //?? 
            hash->size--;
        } 
        else
        {
            offset++;
            if(offset>=MAX_SIZE)
                offset=0;
        }
    }
}
int main()
{
    Hashtable hash;
    Hashinit(&hash);
    Hashinsert(&hash,180,180);
    Hashinsert(&hash,750,750);
    Hashinsert(&hash,600,600);
    Hashinsert(&hash,430,430);
    Hashinsert(&hash,541,541);
    Hashinsert(&hash,900,900);
    Hashinsert(&hash,460,460);
    Hashinsert(&hash,443,443);
    int i=0;
    for(i=0;i<MAX_SIZE;i++)
    {
        printf("(%d,%d)",i,(&hash)->data[i]);
    }
    Hashremove(&hash,430);
    Hashinsert(&hash,1,1);

    printf("\n");
    for(i=0;i<MAX_SIZE;i++)
    {
        printf("(%d,%d)",i,(&hash)->data[i]);
    }
    //int a;
    //Hashfind(&hash,443,&a);
    //printf("%d",a);

    return 0;
}
