#include "bearchtree.h"

void SearchTreeinit(SearchTreeNode **root)
{
    if(root==NULL)
        return;
    *root=NULL;
}
SearchTreeNode* CreatetreeNode(SearchTreeType key)
{
    SearchTreeNode *newnode=(SearchTreeNode*)malloc(sizeof(SearchTreeNode));
    newnode->data=key;
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    return newnode;
}
void SearchTreeinsert(SearchTreeNode **root,SearchTreeType key)
{                                                   //调用函数不是一次插入好几个元素，而是一次插一个
    SearchTreeNode *new_node=CreatetreeNode(key);  //如果根节点为空创建根节点，如果根节点不为空，判断
    SearchTreeNode *cur=*root;                      //插入元素和根节点的大小，小递归调用左子树，否则右
    if(root==NULL)
        return;
    if(*root==NULL)
    {
        *root=new_node;
        return;
    }  
    if(key<cur->data)
        SearchTreeinsert(&cur->lchild,key);
    else if(key>cur->data)
        SearchTreeinsert(&cur->rchild,key);
    else{
        return;
    }
}
SearchTreeNode* SearchTreeFind(SearchTreeNode *root,SearchTreeType value)
{
    if(root==NULL)
        return;
    if(value<root->data)
        SearchTreeFind(root->lchild,value);
    else if(value>root->data)
        SearchTreeFind(root->rchild,value);
    else
    {
        return root;
    }
}
void SearchTreeRemove(SearchTreeNode **proot,SearchTreeType to_remove)
{
    if(proot==NULL)
        return;
    if(*proot==NULL)
        return;
    SearchTreeNode *root=*proot;
    if(to_remove<root->data)
    {
        SearchTreeRemove(&root->lchild,to_remove);
        return;
    }
    else if(to_remove>root->data)
    {
        SearchTreeRemove(&root->rchild,to_remove);
        return;
    }
    else
    {
//            printf("%p ",*proot);
//           printf("%p ",root);
        if(root->rchild==NULL&&root->lchild==NULL)
        {
            *proot=NULL;
            free(root);
            return ;
        }
        else if(root->lchild!=NULL&&root->rchild==NULL)
        {
            *proot=root->lchild;
            free(root);
            return;
        }else if(root->rchild==NULL&&root->lchild!=NULL)
        {
            *proot=root->rchild;
            free(root);
            return;
        }else{
            SearchTreeNode *min=root->rchild;
            while(min->lchild!=NULL)
                min=min->lchild;
            root->data=min->data;
            SearchTreeRemove(&root->rchild,min->data);
            return;
        }
    }
}
void TreeLnOrder(SearchTreeNode *root)
{
    if(root==NULL)
        return;
    TreeLnOrder(root->lchild);
    printf("%c ",root->data);
    TreeLnOrder(root->rchild);
}
void SearchTreeinsert1(SearchTreeNode **root,SearchTreeType value)
{
    if(root==NULL)
        return;
    if(*root==NULL)
        *root=CreatetreeNode(value);
    SearchTreeNode *cur=*root;
    SearchTreeNode *pre=NULL;
    while(1)
    {
        if(value<cur->data)
        {
            pre=cur;
            cur=cur->lchild;
        }else if(value>cur->data)
        {
            pre=cur;
            cur=cur->rchild;
        }else
        {
            return;
        }
        if(cur==NULL)
            break;
    }
    SearchTreeNode *new_node=CreatetreeNode(value);
    if(value<pre->data)
    {
        pre->lchild=new_node;
    }else
    {
        pre->rchild=new_node;
    }
    return;
}
SearchTreeNode * SearchTreeFind1(SearchTreeNode *root,SearchTreeType value)
{
    if(root==NULL)
        return;
    SearchTreeNode *cur=root;
    while(cur!=NULL)
    {
        if(value<cur->data)
            cur=cur->lchild;
        else if(value>cur->data)
            cur=cur->rchild;
        else
            return cur;
    }
}
void SearchTreeRemove1(SearchTreeNode **root,SearchTreeType value)
{
    if(root==NULL)
        return;
    if(*root==NULL)
        return ;
    SearchTreeNode *move=*root;
    SearchTreeNode *pre=NULL;
    while(1)
    {
        if(value<move->data)
        {
            pre=move;
            move=move->lchild;
        }else if(value>move->data)
        {
            pre=move;
            move=move->rchild;
        }else
        {
            break;
        }
        if(move==NULL)
            return;
    }
    if(move->lchild==NULL&&move->rchild==NULL)
    {
        if(*root==move)
            free(move);
        if(move->data<pre->data)
            pre->lchild=NULL;
        else
            pre->rchild=NULL;
        free(move);
    }else if(move->lchild!=NULL&&move->rchild==NULL)
    {
        if(*root==move)
            *root=move->lchild;
        free(move);
        if(move->data<pre->data)
            pre->lchild=move->lchild;
        else
            pre->rchild=move->lchild;
        free(move);
    }else if(move->rchild==NULL&&move->rchild!=NULL)
    {
        if(*root==move)
            *root=move->rchild;
        free(move);
        if(move->data<pre->data)
            pre->lchild=move->rchild;
        else
            pre->rchild=move->rchild;
        free(move);
        pre=move->rchild;
        free(move);
    }else 
    {
        SearchTreeNode *min=move->rchild;
        SearchTreeNode *min_pre=move;
        while(min->lchild!=NULL)
        {
            min_pre=min;
            min=min->lchild;
        }  
        move->data=min->data;
        if(min_pre->lchild==min)
            min_pre->lchild=min->rchild;
        else      //?
            min_pre->rchild=min->rchild;
        free(min);
        return;
    }
}
int main()
{
    SearchTreeNode *root;
    SearchTreeinit(&root);
    //SearchTreeinsert1(&root,'3');//    3   3      3       3       3
    //SearchTreeinsert1(&root,'4');//          4  2    4  2   4   2    4
    //SearchTreeinsert1(&root,'2');//                           8        8
    //SearchTreeinsert1(&root,'8');//                                  6
    //SearchTreeinsert1(&root,'6');
    //TreeLnOrder(root);
   // root=SearchTreeFind1(root,'5');
   // printf("%c ",*root);
  //  putchar(10);
    SearchTreeinsert1(&root,'6');
    SearchTreeinsert1(&root,'6');
    SearchTreeinsert1(&root,'6');
    SearchTreeinsert1(&root,'6');
    SearchTreeinsert1(&root,'6');
    SearchTreeinsert1(&root,'6');
    SearchTreeinsert1(&root,'6');
    SearchTreeinsert1(&root,'6');
    
    //SearchTreeRemove1(&root,'3');
    //SearchTreeRemove(&root,'5');
    TreeLnOrder(root);
    return 0;
}
