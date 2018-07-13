#include <stdio.h>
#include <stdlib.h>
typedef int Typekey;
typedef int Typeval;

#define MAX_SIZE 13
typedef int (*Hashfunc)(Typekey);

typedef struct HashNode
{
    Typekey key;
    Typeval val;
    struct HashNode *next;
}HashNode;

typedef struct Hashtable
{
    HashNode* data[MAX_SIZE];
    int size;
    Hashfunc func;   
}Hashtable;

int Hashfun(Typekey key)
{
    return key%MAX_SIZE;
}
void Hashinit(Hashtable *hash)
{
    if(hash==NULL)
        return ;
    hash->size=0;
    hash->func=Hashfun;
    int i=0;
    for(i=0;i<MAX_SIZE;i++)
    {
        hash->data[i]=NULL;
    }
}
HashNode* CreateHashNode(Typekey key, Typeval value)
{
    HashNode* new_node=(HashNode*)malloc(sizeof(HashNode));
    new_node->key=key;
    new_node->val=value;
    new_node->next=NULL;
    return new_node;
}
void Hashinsert(Hashtable *hash,Typekey key,Typeval value)
{
    //判断是否大于MAX_SIZE，大于直接返回
    //根据Key值计算要插入的位置
    //判断要插入的元素是否重复，重复直接返回
    //不重复直接头插
    if(hash==NULL)
        return ;
    if(hash->size>=MAX_SIZE)
        return ;
    int offset;
    offset=hash->func(key);
    HashNode* cur=hash->data[offset];
    while(1)
    {
        while(cur!=NULL)
        {
            if(cur->key==key)
                return ;
            cur=cur->next;
        }
        HashNode *newnode=CreateHashNode(key,value);
        newnode->next=hash->data[offset];//不带头结点的头插，新节点指向头结点，
        hash->data[offset]=newnode;
        break ;
    }
    hash->size++;
}
void HashFind(Hashtable *hash,Typekey key,Typeval *value)
{
    //判断哈希表是否为空，为空直接返回
    //根据key值计算出哈希表的位置，位置为空直接返回，位置不为空，遍历
    if(hash==NULL)
        return ;
    int offset;
    offset=hash->func(key);
    HashNode* cur=hash->data[offset];
        while(cur!=NULL)
        {
            if(cur->key==key)
            {
                *value = hash->data[offset]->val;
                break;
            }  
            cur=cur->next;
        }
}
void Hashremove(Hashtable *hash,Typekey key)
{
    //根据key计算出哈希表中的位置
    //遍历链表，如果找到key，保存它前一个元素，跳出循环，没找到，直接返回
    //如果头结点为key，头删，否则直接删
    if(hash==NULL)
        return;
    int offset;
    offset=hash->func(key);
    HashNode* cur=hash->data[offset];
    HashNode* pre=NULL;
    while(cur!=NULL)
    {
        if(cur->key==key)
            break;
        pre=cur;
        cur=cur->next;
    }
    if(cur==NULL)
        return;
    //走到这key值一定存在，找到了key
    if(pre==NULL)
    {
        HashNode *tmp=hash->data[offset];
        hash->data[offset]=tmp->next;
        free(tmp);
    }
    else
    {
        pre->next=cur->next;
        free(cur);
    }
}
void Hashdestroy(Hashtable *hash)
{
    if(hash==NULL)
        return ;
    hash->size=0;
    hash->func=NULL;
    int i;
    for(i=0;i<MAX_SIZE;i++)
    {
        HashNode *cur=hash->data[i];
        if(cur==NULL)
            continue;
        while(cur!=NULL)
        {
            HashNode *pre=cur;
            free(cur);
            cur=NULL;
            cur=pre->next;
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
   // printf("%d %d",((&hash)->data[1])->key,((&hash)->data[1])->next->key);
    int a;
    //Hashremove(&hash,443);
    HashFind(&hash,443,&a);
    //printf("%d",a);
    Hashdestroy(&hash);
    printf("%d %d",((&hash)->data[1])->key,((&hash)->data[1])->next->key);
    return 0;
}
