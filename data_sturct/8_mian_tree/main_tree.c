#include <stdio.h>
#include<stdlib.h>
#include"stack.h"

typedef char TreeType;
typedef struct TreeNode
{
    TreeType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}TreeNode;
void Treeinit(TreeNode** root)
{
    if(root==NULL)
        return;
    *root=NULL;
}
TreeNode* CreateNode(TreeType vlaue)
{
    TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode)); 
    root->data=vlaue;
    root->lchild=NULL;
    root->rchild=NULL;
    return root;
}

TreeNode *CreateTree(TreeType array[],size_t size,size_t *index,TreeType null_node)
{
    if(index==NULL)
        return NULL;
    if(*index >=size)
        return NULL;
    if(array[*index]==null_node)
        return NULL;
    TreeNode *new_node=CreateNode(array[*index]);
    ++(*index);
    new_node->lchild=CreateTree(array,size,index,null_node);
    ++(*index);
    new_node->rchild=CreateTree(array,size,index,null_node);
    return new_node;
}
void PreOrder(TreeNode *root)
{
    if(root==NULL)
        return;
    printf("%c ",root->data);
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}
void TreePreOrderByLoop(TreeNode *root)
{
    if(root==NULL)
        return;
    Stack stack;
    stackinit(&stack);
    stackpush(&stack,root);
    TreeNode *cur=NULL;
    while(1)
    {
        stacktop(&stack,&cur);
        if((&stack)->size==0)
            break;
        printf("%c ",cur->data);
        stackpop(&stack);
        if(cur->rchild!=NULL)
        stackpush(&stack,cur->rchild);
        if(cur->lchild!=NULL)
        stackpush(&stack,cur->lchild);
    }
}
void TreeInOrderByLoop(TreeNode *root)
{
    if(root==NULL)
        return ;
    Stack stack;
    stackinit(&stack);
    TreeNode *cur=root;
    //stackpush(&stack,cur);
    while(1)
    {
        while(cur!=NULL)//不能用cur->lchild,while(1)再次循环时，压入得就不是cur而是cur->lchild
        {
            stackpush(&stack,cur);
            cur=cur->lchild;  
        }
        TreeNode *top=NULL;
        stacktop(&stack,&top);
        if((&stack)->size==0)
            break;
        printf("%c ",top->data);
        stackpop(&stack);
        if(top->rchild!=NULL)
        cur=top->rchild;
    }
}
void TreePosOrderByLoop(TreeNode *root)
{
    if(root==NULL)
        return;
    Stack stack;
    stackinit(&stack);
    TreeNode *cur=root;
    TreeNode *pre=NULL;
    while(1)
    {
        while(cur!=NULL)
        {
            stackpush(&stack,cur);
            cur=cur->lchild;
        }
        TreeNode *top=NULL;
        stacktop(&stack,&top);
        if((&stack)->size==0)
            return;
        if(top->rchild==pre||top->rchild==NULL)
        {
            printf("%c ",top->data);
            stackpop(&stack);
            pre=top;
        }
        else
            cur=top->rchild;
    }
}
void TreePreOrderByLoop1(TreeNode* root)
{
    if(root==NULL)
        return ;
    Stack stack;
    stackinit(&stack);
    stackpush(&stack,root);
    TreeNode* top=NULL;
    while(1)
    {
        stacktop(&stack,&top);
        if((&stack)->size==0)
            return;
        printf("%c ",top->data);
        stackpop(&stack);
        if(top->rchild!=NULL)
            stackpush(&stack,top->rchild);
        if(top->lchild!=NULL)
            stackpush(&stack,top->lchild);
    }
}
void  TreeInOrderByLoop1(TreeNode *root)
{
    if(root==NULL)
        return ;
    Stack stack;
    stackinit(&stack);
    TreeNode *cur=root;
    while(1)
    {
        while(cur!=NULL)
        {
            stackpush(&stack,cur);
            cur=cur->lchild;
        }
        TreeNode* top=NULL;
        if((&stack)->size==0)
            return;  
        stacktop(&stack,&top);
        printf("%c ",top->data);
        stackpop(&stack);   
        cur=top->rchild;
    }
}
int main()
{
    int index=0;
    TreeNode *root;
    Treeinit(&root);
    TreeType array[]="abd#g##e##cf#h###";
    root=CreateTree(array,sizeof(array)/sizeof(TreeType)-1,&index,'#');  
 //   PreOrder(root);
    
    //TreePreOrderByLoop1(root);
    TreeInOrderByLoop1(root);
   // TreePosOrderByLoop(root);
    
    return 0;
}

