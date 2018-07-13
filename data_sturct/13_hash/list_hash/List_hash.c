#include <stdio.h>
#define MAX_SIZE 100         //开散列

typedef int KeyType;
typedef int valType;

typedef size_t (*Hashfun)(KeyType key);

typedef struct HashNode
{
    KeyType key;
    valType val;
    struct HashNode *next;
}HashNode;

typedef struct Hash
{
    HashNode* data[MAX_SIZE];
    KeyType size;
    Hashfun cmp;
}Hash;

void Hashinit(Hash *hash,Hashfun fun)
{
    if(hash==NULL)
        return;
    hash->size=0;
    hash->cmp=fun;
    int i=0;
    for(i;i<MAX_SIZE;i++)
    {
        hash->data[i]=NULL;
    }
}
void Hashdostroy(Hash *hash)
{
    if(hash==NULL)
        return;
    //如果哈希表为空，返回不用删除
    if(hash->size==0)
        return;
    hash->size=0;
    hash->cmp=NULL;
    int i=0;
    //遍历哈希表，每个哈希结点为一个链表
    for(i;i<MAX_SIZE;i++)
    {
        HashNode* cur=hash->data[i];
        //如果该节点为空也得继续循环
        if(cur==NULL)
            continue;
        //如果该节点不为空，则循环释放每一个结点
        while(cur!=NULL)
        {
            HashNode pre=cur;
                free(cur);
                cur=pre->next;
        }
    }
}
HashNode *CreateHashNode(valType value,KeyType key)
{
    HashNode *new_node=(HashNode*)malloc(sizeof(HashNode));
    new_node->value=value;
    new_node->next=NULL:
    return new_node;
}
int  Hashfunction(valType value)
{
    int postion=MAX_SIZE%value;
    return postion;
}
void Hashinsert(Hash *hash,valType value,KeyType key)
{
    if(hash==NULL)
        return ;
    //根据key值计算出哈希表中的相应位置
    int offset=hash->cmp(key);
    //找到哈希表的相应位置后
    HashNode *cur=hash->data[offset];
    //判断当前结点是不是为空，如果为空，直接插入，否则找到链表的最后一个结点，尾插
    while(cur!=NULL)
    {
        if(cur->key==key)
            return;
        cur=cur->next;
    }
    //有头结点
      HashNode* newnode =CreateHashNode(value);
        newnode->next=hash->data[offset];
        hash->data[offset]=newnode;
        hash->size++;
}    
void HashRemove(Hash *hash,KeyType key)
{ 
    if(hash==NULL)
        return;
    //根据key值计算出哈希表的相应位置
   int offset=hash->cmp(key);
   HashNode* cur=hash->data[offset];
   //要删除一个结点，必须知道他的前一个结点，用pre保存
   HashNode* pre=NULL;
   //找到要删除元素
   while(cur!=NULL)
   {
       if(cur->key==key)
           break;
       pre=cur;
       cur=cur->next;
   }
   //如果哈希表中该点为空，则表中没有要查找的点，直接返回
   if(cur==NULL)
       return;
    //如果表中只有一个结点，并且该节点就是要删除的结点，
   if(pre==NULL)
   {
        HashNode* tmp=hash->data[offset];
        hash-data[offset]=tmp->next;
        free(tmp);
   }
   else
   {
       pre->next=cur->next;
       free(cur);
   }
//if(hash->data[key]==NULL)
//        return;
//    else
//    {
//        if(hash->data[key].next==NULL)
//            free(hash->data[key]);
//        else
//        {
//            HashNode *to_remove=hash->data[key];
//            hash->data[key]=hash->data[key].next;
//            free(to_remove);
//        }
//    }
//}
int HashFind(Hash *hash,KeyType key,valType *val)
{
    if(hash==NULL)
        return ;
    if(hash->size==0)
        return ;
    int offset=hash->cmp(key);
    HashNode *cur=hash->data[offset];
    while(cur!=NULL)
    {
        if(cur->key==key)
            return 1;
        cur=cur->next;
    }
    return 0;
}
int main()
{
    Hash hash;
    Hashinit(&hash);
    return 0;
}
