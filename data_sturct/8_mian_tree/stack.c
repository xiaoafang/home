#include "stack.h"

void stackinit(Stack *stack)
{
  if(stack==NULL)
    return;
    stack->data=(stackType*)malloc(MAX_SIZE*sizeof(stackType)); 
    if(stack==NULL)
    {
      exit(1);
    }
    stack->size=0;
}
void stackdostroy(Stack *stack)
{
   if(stack==NULL)
      return;
    free(stack->data);
    stack->size=0;
}
void resize(Stack *stack)
{
  Stack new;
    if(stack==NULL)
      return;
    if(stack->size<MAX_SIZE)
      return ;
  //  stack->capacity = capacity*2+1; 
   (&new)->data = (stackType*)malloc((MAX_SIZE+MAX_SIZE)*sizeof(stackType));
    int n=stack->size;
    int i=0;
    while(n--)
    {
        (&new)->data[i++]=stack->data[i++];
    }
    stack = &new;
}
void stackpush(Stack *stack,stackType value)
{
    if(stack==NULL)
      return ;
    if(stack->size>=MAX_SIZE)
    {
        resize(stack);
    }
    stack->data[stack->size++]=value;
}
void stackpop(Stack *stack)
{
    if(stack==NULL)
      return;
    stack->size--;

}
void stacktop(Stack *stack,stackType *value)
{
   if (stack==NULL) {
      return;
    }
   *value= stack->data[stack->size-1];
}
#if 0
#include<stdio.h>
//#define TEXT_HEADER printf("\n===========%s==========\n",_FUNCTION_)
void text()
{
 // TEXT_HEADER;
  int v;
  Stack s;        
  stackinit(&s);  
  stackpush(&s,4);
  stackpush(&s,5);  
  stackpush(&s,3);  
  stackpop(&s);     
  stackpop(&s);     
  stacktop(&s,&v);  
  printf("%d ",v);   
}
  
int main()
{
  text();
    return 0;
}
#endif
