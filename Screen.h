#ifndef Screen_h
#define Screen_h
#include "Snake.h"
#include "misc.h"
#include "Position.h"
#include "Apple.h"

#include <stdio.h>
#include <stdbool.h>

typedef struct Screen* Screen;

/******************* Constructor  ****************/
Screen CreateScreen (int col, int row); //Function that will create the screen by the values that will be sent by the user
/******************* Destructor  ****************/
void DeleteScreen (Screen  screen);    // Function that frees the screen allocating after the usage
/******************* Getters  ****************/
int getRow(Screen screen);
int getCol(Screen screen);
/******************* Functions  ****************/
bool DrawScreen (Screen  screen, Snake  snake); //This function will fill the play table array with the # character on the frame and with + and * to the body of the snake
void PrintScreen (Screen  screen, FILE * fp); // This function will print the screen to the relative stream
bool GameOver (Screen  screen, Snake  snake, int head_x, int head_y); // This function will check if snake is touching himself or the borders
bool    ScreenPositionEmpty(Screen screen, Position pos);
bool    DrawApple(Screen screen, Apple apple);


#endif


