#include <stdio.h>
#include <stdlib.h>
typedef struct point
{
    int row;
    int low;
}point;
typedef  point stackType;
#define MAX_SIZE  100
typedef struct StackNode
{
    stackType  *data; 
    int size;
}Stack,stacknode; 
void stackinit(Stack *stack); 
void resize(Stack *stack);
void stackdostroy(Stack *stack);
void stackpush(Stack *stack,stackType value);
void stackpop(Stack *stack);
void stacktop(Stack *stack,stackType *value);
