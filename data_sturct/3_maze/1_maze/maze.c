#include <stdio.h>
#include<stdlib.h>
#define ROW 6 
#define LOW 6 
typedef struct point
{
    int row;
    int low;
}point;

typedef struct Maze
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
void _getpath(Maze *maze,point p,point entry)
{
    //printf("(%d  %d)\n",p.row,p.low);
    if(!canmove(maze,p))
        return;
    //printf("(%d  %d)\n",p.row,p.low);
        makemark(maze,p);
       // printf("\n");
    if(isexitt(maze,p,entry))
    {
        return;
    }
        point up=p;
        up.row -=1;
        _getpath(maze,up,entry);
       // p->row=up->row+1;

        // (-1, 1)
        point right=p;
        right.low +=1;
        _getpath(maze,right,entry);
       // p->low=right->low-1;

        point down=p;
        down.row +=1;
        _getpath(maze,down,entry);
      //  p->row = down->row-1;

        point left=p;
        left.low -=1;
        _getpath(maze,left,entry);
      //  p->low=left->low+1;

}

int main()
{       
    point entry={0,1};
    Maze maze;
    mazeinit(&maze);
    print(&maze);
    _getpath(&maze,entry,entry);
    print(&maze);
    return 0;
}
