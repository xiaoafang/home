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

void reverse1_0(LinkList **head)
{
	LinkNode *cur = *head;
    LinkNode *tmp,*key=NULL;
    if(*head==NULL)
        return ;
    while(cur!=NULL)
    {
        tmp=cur->next;
        cur->next=key;
        key=cur;
        cur=tmp;
    }
    *head = key;
}

LinkList* reverse1_1(LinkList *head)
{
    LinkNode *cur = head;
    LinkNode *tmp,*key=NULL;
    if(head==NULL)
        return ;
    while(cur!=NULL)
    {
        tmp=cur->next;
        cur->next=key;
        key=cur;
        cur=tmp;
    }
    return key;
}
void reverse2(LinkList **head)
{
	LinkNode *cur,*pre,*tail;
	pre = *head;
	cur = pre->next;
	tail = NULL;
	while(pre->next!=NULL)
	{
		tail=cur->next;
		pre->next=tail;
		cur->next=*head;
        *head=cur;
		cur=pre->next;
	}
}
void reverse3(LinkList *head)
{
    if(head == NULL)
        return;
    reverse3(head->next);
    printf("%d ",head->data);
}

LinkNode* merge(LinkList *head1,LinkList *head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    LinkNode *new_head=NULL;
    LinkNode *new_tail=NULL;
    LinkNode *cur1=head1;
	LinkNode *cur2=head2;
    if(cur1->data>cur2->data)
    {
        new_head=cur2;
        cur2=cur2->next;
    }
    else
    {
        new_head=cur1;
        cur1=cur1->next;
    }
    new_tail=new_head;
	while(cur1!=NULL && cur2!=NULL)
	{
        if(cur1->data<cur2->data)
        {
            new_tail->next=cur1;
            new_tail=cur1;
            cur1=cur1->next;
        }
        else
        {
            new_tail->next =cur2;
            new_tail=cur2;
            cur2=cur2->next;
        }
    }
    if(cur1!=NULL)
    {
        new_tail->next=cur1;
    }
    if(cur2!=NULL)
    {
        new_tail->next=cur2;
    }
    return new_head;
}
LinkNode* FindMidNode(LinkNode *head)
{
    if(head==NULL)
        return ;
    LinkNode *fast=head;
    LinkNode *slow=head;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast==NULL)
            break;
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}
LinkNode* FindLastKNode(LinkNode *head,size_t k)
{
    if(head==NULL)
        return NULL;
    LinkNode* fast=head;
    LinkNode* slow=head;
    int i;
    for(i=0;i<k;i++)
    {
        if(fast==NULL)
            break;
        fast=fast->next;
    }
    while(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
void DeletelastKNode(LinkNode** head,size_t k)
{
    LinkNode* cur=*head;
    int len=0;
    if(head == NULL||k<=0)
        return;
    if(*head == NULL)
        return;
    while(cur != NULL)
    {
        len++;
        cur=cur->next;
    }
    if(k>len)
        return;
    if(k==len)
    {
        LinkNode* cur=*head;
        *head=(*head)->next;
        free(cur);
    }
    int i=0;
    LinkNode* fast=*head;
    for(i=0;i<len-k-1;i++)
    {
        fast=fast->next;
    }
    LinkNode *to_delete=fast->next;
    fast->next=to_delete->next;
    free(to_delete);
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
//    	 reverse2(&L);
//	     L= merge(L,l);
	     
//         L=FindMidNode(L);
         L=FindLastKNode(L,5);
         //DeletelastKNode(&L,-1);
//		 print(L);
         printf("%d ",L->data);
         return 0;
}
