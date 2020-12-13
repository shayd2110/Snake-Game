#include "Apple.h"




struct Apple
{
    Position pos;

};




/******************* Constructor  ****************/

Apple   CreateApple(int x,int y)
{
    Apple apple = (Apple)AllocateMemory(sizeof(struct Apple), __FILE__, __LINE__);
     apple->pos=CreatePosition(x,y);
     return apple;
}

/******************* Destructor  ****************/

void    DeleteApple(Apple apple)
{
    DeletePosition(apple->pos);
    FreeMemory(apple);
}

/******************* Getters  ****************/

int      getApple_Position_X(Apple apple)
{
    return get_X(apple->pos);
}



int      getApple_Position_Y(Apple apple)
{
    return get_Y(apple->pos);
}

Position    getApplePos(Apple apple)
{
    return apple->pos;
}

/******************* Setters  ****************/

void setApple_Position_X(Apple apple,int x)
{
    set_X(apple->pos,  x);
}

void setApple_Position_Y(Apple apple,int y)
{
    set_X(apple->pos,   y);
}

