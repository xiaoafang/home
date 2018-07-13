#include<stdio.h>
#include<stdlib.h>
typedef struct LinkNode
{
	int data;
	struct LinkNode *next;
}LinkList,LinkNode;

void pushback(LinkList **head,int value)
{
		  LinkList *cur=*head;
   LinkNode *newnode=(LinkNode*)malloc(sizeof(LinkNode));
	newnode->data =value;
	newnode->next = NULL;
	if(head==NULL)
		return ;
	if(*head==NULL)
         *head=newnode;
	else
		{
			while(cur->next!=NULL)
				 cur=cur->next;
			cur->next= newnode;
		}
}       

void print(LinkList *head)
{
		  LinkNode *cur = head;
		  while(cur!=NULL)
		  {
				printf("%d ",cur->data);		  
				cur=cur->next;
		  }
}
//判断单链表是否带环
size_t HasCycle(LinkNode* head)
{
    if(head==NULL)
        return 0;
    LinkNode* fast=head;
    LinkNode* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
            return 1;
    }
    return 0;
}
//求环长度
size_t GetCyclelen(LinkNode* head)
{
    LinkNode* tmp = HasCycleRet(head);
    LinkNode* cur=tmp;
    size_t count=0;
    while(cur->next!=NULL)
    {
        cur=cur->next;
        count++;
        if(cur==tmp)
            break;
    }
    return count;
}
//求环入口点
LinkNode* GetCycleEntry(LinkNode* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    LinkNode* begin=head;
    LinkNode* end=HasCycleRet(head);//相遇点
    while(begin!=end)
    {
        begin=begin->next;
        end=end->next;
    }
    if(begin==end)
    {
        return end;
    }
    return NULL;
}
//判断两链表是否相交（假设链表不带环）
size_t HasCross(LinkNode* head1, LinkNode* head2)
{
    if(head1==NULL)
    {
        return (size_t)-1;
    }
    if(head2==NULL)
    {
        return (size_t)-1;
    }
    LinkNode* cur1=head1;
    LinkNode* cur2=head2;
    while(cur1->next!=NULL)
    {
        cur1=cur1->next;
    }
    while(cur2->next!=NULL)
    {
        cur2=cur2->next;
    }
    if(cur1==cur2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//判断两链表是否带环
size_t HasCrossWithCycle(LinkNode* head1, LinkNode* head2)
{
    if(head1==NULL||head2==NULL)
    {
        return (size_t)-1;
    }
    // 1.求出两个环的入口点
    LinkNode* pos1=HasCycleRet(head1);
    LinkNode* pos2=HasCycleRet(head2);
    // 2.两个都不带环的情况
    if(pos1==NULL&&pos2==NULL)
    {
        size_t ret=HasCross(head1,head2);
        return ret;
    }
    // 3.其中一个带环一个不带环
    if((pos1==NULL&&pos2!=NULL)||(pos1!=NULL&&pos2==NULL))
    {
        return 0;
    }
    // 4.两个都带环·(说明是环外相交)
    if(pos1==pos2)
    {
        return 1;
    }
    // 两个都带环（环内相交）
    if(pos1!=pos2)
    {
        LinkNode* cur1=pos1;
        LinkNode* cur2=pos2;
        while(cur1->next!=pos1)
        {
            cur1=cur1->next;
            if(cur1==cur2)
            {
                return  1;
            }
        }
        // 两个都带环，但是不相交
        return 0;
    }
} 

int main()
{
		 LinkList *L=NULL,*l=NULL;
		 pushback(&L,1);
		 pushback(&L,3);
		 pushback(&L,5);
		 pushback(&L,7);
		 pushback(&L,3);
//		 pushback(&l,2);
//		 pushback(&l,4);
//		 pushback(&l,6);
//    	 reverse3(L);
//	     L= merge(L,l);
	     
//         L=FindMidNode(L);
//         L=FindLastKNode(L,0);
         DeletelastKNode(&L,-1);
		 print(L);
//         printf("%d ",L->data);
         return 0;
}
