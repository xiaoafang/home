#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE  100

//typedef char TreeType;
//typedef struct TreeNode
//{
//    TreeType data;
//    struct TreeNode *lchild;
//    struct TreeNode *rchild;
//}TreeNode;
//struct TreeNode;
typedef struct TreeNode* stackType;

typedef struct StackNode
{
    stackType *data; 
    int size;
}Stack,stacknode;
void stackinit(Stack *stack);
void resize(Stack *stack);
void stackdostory(Stack *stack);
void stackpush(Stack *stack,stackType value);
void stackpop(Stack *stack);
void stacktop(Stack *stack,stackType *value);
