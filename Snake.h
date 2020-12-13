#ifndef Snake_h
#define Snake_h


#include <stdio.h>
#include "Position.h"
#include "misc.h"

typedef enum { Up = 'w', Down = 's', Left = 'a', Right = 'd' } Direction; //Definition of the keys that will make the snake move

typedef struct Snake* Snake;
/******************* Constructor  ****************/
Snake CreateSnake(int x, int y, int len); // This function will set the snake values
/******************* Destructor  ****************/
void DeleteSnake(Snake  snake);           //This function will free the memory that was allocate for the snake 
/******************* Getters  ****************/
int     getLen (Snake snake);                                  // getter gor length
int get_pos_X(Snake snake,int index);
int get_pos_Y(Snake snake,int index);
/******************* Setters  ****************/
void    setLen(Snake snake, int lenght);                //Setter for lenght
/******************* Functions  ****************/
void MoveSnake (Snake  snake, Direction dir,bool elongate);// This function will actually move the snake in the play table
bool CheckDirection( Snake  snake,Direction dir); // This is an assistant function that will check if the direction is legal
bool CheckLen(int len, int x); // This function will check if the lenght is not grater the the X coord of the snake's head
 bool CheckPositive(int number); // This function wiil check if the values is legal for the snake's values
 void followPos(Snake snake); // This function will make the body of the snake follow the head
 Position SnakeNext (Snake snake ,Direction dir); // function to get the next move of the snake


 




#endif
