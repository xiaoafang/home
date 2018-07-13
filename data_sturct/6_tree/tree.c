#include <stdio.h>
#include"queue.h"
#include<stddef.h>
#include<stdlib.h>
typedef char TreeType;
typedef struct TreeNode
{
    TreeType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}TreeNode;

void Treeinit(TreeNode **root)
{
    if(root==NULL)
        return;
    *root=NULL;
}
void TreePreOrder(TreeNode *root)
{
    if(root==NULL)
        return;
    printf("%c ",root->data);
    TreePreOrder(root->lchild);
    TreePreOrder(root->rchild);
}
void TreeLnOrder(TreeNode *root)
{
    if(root==NULL)
        return;
    TreeLnOrder(root->lchild);
    printf("%c ",root->data);
    TreeLnOrder(root->rchild);
}
void TreePostOrder(TreeNode *root)
{
    if(root==NULL)
        return;
    TreePostOrder(root->lchild);
    TreePostOrder(root->rchild);
    printf("%c ",root->data);
}
TreeNode* CreateNode(TreeType vlaue)
{
    TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode)); 
    root->data=vlaue;
    root->lchild=NULL;
    root->rchild=NULL;
    return root;
}
TreeNode* _TreeCreate(TreeType array[],size_t size,size_t *index,TreeType null_node)
{
    if(index==NULL)
        return NULL;
    if(*index >= size)
        return NULL;
    if(array[*index]==null_node)
        return NULL;
    TreeNode* new_node=CreateNode(array[*index]);
    ++(*index);
    new_node->lchild=_TreeCreate(array,size,index,null_node);
    ++(*index);
    new_node->rchild=_TreeCreate(array,size,index,null_node);
    return new_node;
}
TreeNode* TreeCreate(TreeType array[],size_t  size,TreeType null_node)
{
    size_t index=0;
    return  _TreeCreate(array,size,&index,null_node);
}
void TreeLeveOrder(TreeNode *root)
{
    if(root==NULL)
        return;
    QueueNode queue;
    SeqQueueinit(&queue);
    SeqQueuePush(&queue,root);
    while(1)
    {
        TreeNode front;
        SeqQueuefront(&queue,&front);
        if((&queue)->size==0)
            break;
        printf("%c ",(&front)->data);
        SeqQueuePop(&queue);
        if((&front)->lchild!=NULL)
            SeqQueuePush(&queue,(&front)->lchild);
        if((&front)->rchild!=NULL)
            SeqQueuePush(&queue,(&front)->rchild);
    }
}
void TreeDestroy(TreeNode *root)
{
    if(root=NULL)
        return;
    TreeDestroy(root->lchild);
    TreeDestroy(root->rchild);
    free(root);
}
void TreeDestroy2(TreeNode *root)
{
    if(root==NULL)
        return;
    TreeNode *lchild=root->lchild;
    TreeNode *rchild=root->rchild;
    free(root);
    TreeDestroy2(lchild);
    TreeDestroy2(rchild);
}
void TreeSize(TreeNode* root,size_t *size)
{
    if(root==NULL)
        return;
    ++(*size);
    TreeSize(root->lchild,size);  
    TreeSize(root->rchild,size); 
}
int TreeSize2(TreeNode *root)
{
    if(root==NULL)
        return;
    return TreeSize2(root->lchild)+TreeSize2(root->rchild)+1;
}
int TreeLeafSize(TreeNode *root)
{
    if(root==NULL)
        return;
    if(root->lchild==NULL&&root->rchild==NULL)
        return 1;
    return TreeLeafSize(root->lchild)+TreeLeafSize(root->rchild);
}
//二叉树的镜像非递归版
//void TreemirrorByLoop(TreeNode *root)
//{
//    if(root==NULL)
//        return ;
//    QueueNode queue;
//    SeqQueueinit(&queue);
//    SeqQueuePush(&queue,root);
//    TreeNode *front;
//    while(1)
//    {
//        if((&queue)->size==0)
//            return;
//        SeqQueuefront(&queue,&front);
//        printf("%c ",front->data);
//        SeqQueuePop(&queue);
//        if(front->rchild!=NULL)
//            SeqQueuePush(&queue,front->rchild);
//        if(front->lchild!=NULL)
//            SeqQueuePush(&queue,front->lchild);
//    }
//}
int main()
{
    size_t a=0;
    TreeNode *root;
    Treeinit(&root);
    TreeType array[]="abd#g##e##cf#h###";
    root=TreeCreate(array,sizeof(array)/sizeof(TreeType)-1,'#');
    //    TreePreOrder(root);
    //   TreeDestroy2(root);
    // a=TreeSize2(root);
    //  a=TreeLeafSize(root);
    // printf("%d",a);
    TreeLeveOrder(root);
    //  TreeLnOrder(root);
    //TreePostOrder(root);
 // TreemirrorByLoop(root);
    return 0;
}
