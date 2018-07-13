#include <stdio.h>

#define  MAX_SIZE 100

typedef int Typekey;
typedef int Typeval;

typedef enum Stat
{
    Empty,
    Valid,
    Delete,
}Stat;

typedef int (*hashfunc)(Typekey key);

typedef struct hashnode
{
    Typekey key;
    Typeval value;
    Stat stat;
}hashnode;

typedef struct hashtable
{
    hashnode data[MAX_SIZE];
    int size;
    hashfunc cmp;
}hashtable;

int func(Typekey key)
{
    return key%MAX_SIZE;
}
void hashinit(hashtable *hash,hashfunc func)
{
    if(hash==NULL)
        return ;
    hash->cmp=func;
    hash->size=0;
    int i=0;
    for(;i<MAX_SIZE;i++)
    {
        hash->data[i].stat=Empty;
    }
}

void hashinsert(hashtable *hash ,Typekey key,Typeval value)
{
    if(hash==NULL)
        return;
    //计算负载因子，如果大于它则判断哈希表为满
    if(hash->size>=0.8*MAX_SIZE)
        return ;
    //根据key值计算该值在哈希表中的相应位置
    int offset=hash->cmp(key);
    while(1)
    {
        //判断该位置是否已经放过数据，没放过直接赋值在++
        if(hash->data[offset].stat!=Valid)
        {
            hash->data[offset].stat=Valid;
            hash->data[offset].key=key;
            hash->data[offset].value=value;
            hash->size++;
            //判断数是否有重复
        }else if(hash->data[offset].stat==Valid&&hash->data[offset].key==key)
        {
            return;
            //如果当前结点已经放了，线性探测
        }else
        {
            offset++;
            if(offset>MAX_SIZE)
                offset=0;
        }
    }
}
int  hashfind(hashtable *hash ,Typekey key,Typeval *value)
{
    if(hash==NULL)
        return 0;
    //哈希表为空直接返回
    if(hash->size==0)
        return 0;
    //计算位置
    int offset=hash->cmp(key);
    while(1)
    {
        //查找成功
        if(hash->data[offset].key==key&&hash->data[offset].stat==Valid)
        {
            *value=hash->data[offset].value;
            return 1;
        }  
        //查找失败
        else if(hash->data[offset].stat==Empty)
                return 0;
        else
            {
            offset++;
            if(offset>=MAX_SIZE)
                offset=0;
            }       
    }
    return 0;
}
void HashRemove(hashtable *hash ,Typekey key)
{
    if(hash==NULL)
        return;
    if(hash->size==0)
        return;
    size_t offset=hash->cmp(key);
    while(1)
    {
        if(hash->data[offset].key==key && hash->data[offset].stat==Valid)
        {
            hash->data[offset].stat=Delete;
            --hash->size;
        }else if(hash->data[offset].stat==Empty)
        {
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
int main()
{
    int i;
    hashtable hash;
    hashinit(&hash,func);
    hashinsert(&hash,1,12);
    hashfind(&hash,1,&i);
    hashfind(&hash,2,&i);
    hashRemove(&hash,1);
 //   printf("%d",i);
    return 0;
}
