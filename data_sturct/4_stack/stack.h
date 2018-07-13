#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE  1
typedef int  stackType;
typedef struct StackNode
{
    int *data; 
    int size;
}stack,stacknode; void stackinit(Stack *stack); void resize(Stack *stack);
void stackdostory(Stack *stack);
void stackpush(Stack *stack,stackType value);
void stackpop(Stack *stack);
void stacktop(Stack *stack,stackType *value);
