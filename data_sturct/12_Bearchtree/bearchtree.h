#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef char SearchTreeType;

typedef struct SearchTreeNode
{
    SearchTreeType data;
    struct SearchTreeNode *lchild;
    struct SearchTreeNode *rchild;
}SearchTreeNode;

void SearchTreeinit(SearchTreeNode **root);
void SearchTreeinsert(SearchTreeNode **root,SearchTreeType key);
