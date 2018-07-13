#include <stdio.h>

typedef struct Position
{
    int x;
    int y;
}Position;

typedef struct Node
{
    Position position;
    struct Node *pnext;
}Node;

enum Direction
{
    UP,DOWN,LEFT,RIGHT
}

typedef struct Snake
{
    Direction direction;
    Node *pnext;
}Snake;

typedef struct Game
{
    int wide;
    int high;
    Snake snake;
    Position food_position;
    int score;   
    int interval;//时间间隔
}  Game;

void _snakeinit(Snake *snake)
{
    int x=5;
    int y=5;
    int initlengh=3;
    if(snake==NULL)
        return;
    snake->pnext=NULL;
    for(i=0;i<initlengh;i++)
    {
        Node *newnode=(Node*)malloc(sizeof(Node));
        newnode->position.x=x+i;
        newnode->position.y=y;
        newnode->pnext=snake->pnext;
        newnode->pnext=newnode;
    }

}
void Generatefood(Position position,int wide,int high)
{
    int x,y;
    x=rand()% wide;
    y=rand()% high;
    position->x=x;
    position->y=y;
}
void Gameinit(Game *game)
{
    game->wide=6;
    game->high=6;
    game->score=0;
    game->interval=200;
    snakeinit(&game->snake);
    Generatefood(&game->food_position,&game->wide,&game->high);
}
int main()
{
    Game game;
    Gameinit(&game);
}
