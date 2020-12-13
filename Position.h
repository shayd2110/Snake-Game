
#ifndef Position_h
#define Position_h

#include <stdlib.h>
#include <stdio.h>

#include "misc.h"   


typedef struct Position* Position;   //Struct that will hold the coordinates of the snake

/******************* Constructor  ****************/
Position CreatePosition (int x, int y); // This function will set and creates position for the snake's body
/******************* Destructor  ****************/
void DeletePosition (Position  pos);//This function will free the memory that was allocate for the positions  
/******************* Getters  ****************/
int     get_X(Position pos);
int     get_Y(Position pos);
/******************* Setters  ****************/
void    set_X(Position pos ,int x);
void    set_Y(Position pos ,int y);




#endif
