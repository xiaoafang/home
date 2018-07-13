#include <stdio.h>
#include"stack.h"
#define ROW 6
#define LOW 6

//typedef struct point
//{
//    int row;
//    int low;
//}point;

typedef struct maze
{
    int map[ROW][LOW];
}Maze;

void mazeinit(Maze *maze)
{
    int map[ROW][LOW]={
        {0,1,0,0,0,0},
        {0,1,1,1,0,0},
        {0,1,0,1,0,0},
        {0,1,0,1,1,0},
        {0,1,0,0,0,0},
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
int canmove(Maze *maze,point cur)
{
    if(cur.row<0||cur.row>ROW-1||cur.low<0||cur.low>LOW-1)
        return 0;
    if(maze->map[cur.row][cur.low]==1)
        return 1;
    return 0;
}
void makemark(Maze *maze,point cur)
{
    maze->map[cur.row][cur.low]=2;
}
int isexitt(Maze *maze,Stack *s,point cur,point entry)
{
    if(cur.row==entry.row && cur.low==entry.low)
        return 0;
    if(cur.row==ROW-1||cur.low==LOW-1||cur.row==0||cur.low==0)
    {
        printf("zhaodaoyitiaochulu\n");
        return 0;
    }
    return 0;
}
void _getpath(Maze *maze,Stack *s,point cur,point entry)
{
    //非法输入
    if(maze==NULL)
        return;
    //如果入口点不能走，就非法点
    if(!canmove(maze,cur))
        return ;
    //如果能走做一个标记，并且入栈
    makemark(maze,cur);
    stackpush(s,cur);
   //如果栈不为空取栈顶元素，已该点为基准进行判断
    while(stacktop(s,&cur))
    {
        //如果该点为出口点，找到一条路径
        if(isexitt(maze,s,cur,entry))
        {
            return;
        }
        //如果该点不是出口点，则依次进行上左下右判断
        point up=cur;
        up.row -=1;
        if(canmove(maze,up))
        {
            makemark(maze,cur);
            stackpush(s,up); 
            continue;
        }
    

        point right=cur;
        right.low +=1;
        if(canmove(maze,right))
        {
             makemark(maze,right);
             stackpush(s,right);
             continue;
        }

        point down=cur;
        down.row +=1;
        if(canmove(maze,down))
        {
             makemark(maze,down);
             stackpush(s,down);
             continue;
        }
    

        point left=cur;
        left.low -=1;
        if(canmove(maze,left))
        {
             makemark(maze,left);
             stackpush(s,left);
             continue;
        }
        //如果没有路可以走，则出栈，继续探测
        stackpop(s);
    }
}
int main()
{
    Stack s;
    stackinit(&s);
    point entry={0,1};
    Maze maze;
    mazeinit(&maze);
    _getpath(&maze,&s,entry,entry);
    print(&maze);
    return 0;
}
