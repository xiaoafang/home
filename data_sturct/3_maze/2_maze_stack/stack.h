#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE  1
typedef struct point{
    int row;
    int low;
}point;

typedef point  stackType;
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
int  stacktop(Stack *stack,stackType *value);
