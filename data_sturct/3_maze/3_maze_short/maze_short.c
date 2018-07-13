#include <stdio.h>
#include<stdlib.h>
#include"stack.h"
#define ROW 6 
#define LOW 6 

typedef struct Maze
{
    int map[ROW][LOW];
}Maze;

void mazeinit(Maze *maze)
{
    int map[ROW][LOW]={
        {0,1,0,1,0,0},
        {0,1,1,1,0,0},
        {1,1,0,1,0,0},
        {0,1,0,1,1,1},
        {0,1,0,1,0,1},
        {0,1,0,0,0,0},
    }; 
    int i,j;
    for(i=0;i<ROW;i++)
      for(j=0;j<LOW;j++)
      {
       maze->map[i][j]=map[i][j];
      }
}
void print(Maze *maze)
{
    int i,j;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<LOW;j++)
        {
            printf("%2d ",maze->map[i][j]);
        }
    printf("\n");
    }
}
int canmove(Maze *maze,point p)
{ 
    if(p.row<0||p.low>ROW-1||p.low<0||p.low>LOW-1) 
        return 0;
    if(maze->map[p.row][p.low]==1){
        return 1;  
    }
    return 0;//zhe ge da keng
}
void makemark(Maze *maze,point p)
{
    maze->map[p.row][p.low]=2; 
}
int isexitt(Maze *maze,point p,point entry)
{
    if(p.row == entry.row && p.low == entry.low)
        return 0;
     if(p.low == LOW-1 || p.low == 0 || p.row == 0 || p.row == ROW-1)
    {
        printf("找到一条出路！\n");
        return 1;
    }
     return 0;//zhe ge keng
}
void fuzhi(Stack *from,Stack *to)
{
    stackdostroy(to);
    int i;
    to->data=(stackType*)malloc(from->size*sizeof(stackType));
    to->size=from->size;
    for(i=0;i<from->size;i++)
    {
        to->data[i]=from->data[i];
    }
}
void _getpath(Maze *maze,Stack *cur,Stack *_short,point p,point entry)
{
    //printf("(%d %d)",p.row,p.low);
    //判断当前点能不能落脚
    if(!canmove(maze,p))
        return;
    //如果能落脚，就对当前点标记，并入栈
        makemark(maze,p);
        stackpush(cur,p);
    //判断当前点是不是是不是出口点
    if(isexitt(maze,p,entry))
    {
        //如果有比上一次出口更短的路径就更新_short栈的内容
        if(cur->size < _short->size || _short->size == 0)
        {
            fuzhi(cur,_short);
            printf("gengduande\n");
        }
        //如果找的出口没有比上次更短，就要回溯，cur栈也要出栈
        stackpop(cur);
        return;
    }
    //四个方向探测
        point up=p;
        up.row -=1;
        _getpath(maze,cur,_short,up,entry);

        point right=p;
        right.low +=1;
        _getpath(maze,cur,_short,right,entry);

        point down=p;
        down.row +=1;
        _getpath(maze,cur,_short,down,entry);

        point left=p;
        left.low -=1;
        _getpath(maze,cur,_short,left,entry);
    //如果四个方向都不行，就函数栈帧出栈和cur出栈
        stackpop(cur);
        return ;
}

int main()
{ 
    Stack cur_stack;
    Stack short_stack;
    stackinit(&cur_stack);
    stackinit(&short_stack);
    point entry={0,1};
    Maze maze;
    mazeinit(&maze);
    print(&maze);
    _getpath(&maze,&cur_stack,&short_stack,entry,entry);
    printf("\n");
    print(&maze);
    return 0;
}
