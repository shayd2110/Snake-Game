#include "Position.h"

struct Position
{
  int x;    //The X coord 
  int y;    //The Y coord

};


/******************* Constructor  ****************/

// This function will set and creates position for the snake's body
Position CreatePosition (int x, int y)
{
    //Allocating the memory for the positions
   Position pos = (Position)AllocateMemory(sizeof(Position), __FILE__, __LINE__); //calloc (1, sizeof (Position));
  
  pos->x = x; // setting the X coord
  pos->y = y;// setting the Y coord
  return pos; // return pointer for this position for future use
}

/******************* Destructor  ****************/

//This function will free the memory that was allocate for the positions 
void DeletePosition (Position pos)
{
  FreeMemory(pos); //Sending the pointer to the function
}


/******************* Getters  ****************/

int     get_X(Position pos)
{
    return pos->x;
}

int     get_Y(Position pos)
{
    return pos->y;  
}

/******************* Setters  ****************/

void    set_X(Position pos ,int x)
{
    pos->x=x;
}

void    set_Y(Position pos ,int y)
{
    pos->y=y;
}

