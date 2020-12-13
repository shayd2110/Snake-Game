#include "Screen.h"
#include "Snake.h"
#include "Apple.h"
#include <stdio.h>



 struct Screen // Struct that will hold the relative values for naking the screen works
{
  int row;  //This var will hold the value of rows of the screencharacter
  int col;  //This var will hold the value of rows of the screen
  char **playTable; // This var will hold the play table 2D array

} ;


/******************* Constructor  ****************/


 //Function that will create the screen by the values that will be sent by the user
Screen CreateScreen (int col, int row)
{
  // A set of test to make sure that the value is legal
  if (!CheckPositive (row))
    {
      fprintf (stderr, "The Row number needs to bee positive number");
      return NULL;
    }
  
  if (!CheckPositive (col))
    {
      fprintf (stderr, "The column number needs to bee positive number");
      return NULL;
    }
  
  //Creation of Screen Object
  Screen screen = (Screen )AllocateMemory(sizeof(Screen),__FILE__,__LINE__);  

//Setting the values to the struct
  screen->col=col;
  screen->row = row;

  //Allocating the play table in Matrix form
  screen->playTable = (char **)AllocateMemory2D(row,col,sizeof(char*),__FILE__,__LINE__); //malloc (row * sizeof (char *));

  return screen; // Return the pointer for future usage
}

/******************* Destructor  ****************/

// Function that frees the screen allocating after the usage
void DeleteScreen (Screen  screen)  
{
    FreeMemory2D((void**)(screen->playTable));  // Firstly freeing the 2D array
    FreeMemory(screen);                       // Secondly freeing the Object
}

/******************* Getters  ****************/
int getRow(Screen screen)
{
    return screen->row;
}

int getCol(Screen screen)
{
    return screen->col;
}


/******************* Functions  ****************/

//This function will fill the play table array with the # character on the frame and with + and * to the body of the snake
bool DrawScreen (Screen  screen, Snake  snake)
{
  int i, j, index; // The first two var's are for running over the matrix. the third one is the Snake array

   
  // these are 'comfort' variables that keep the head's coords for future usage
  int head_x = get_pos_X(snake,0);
  int head_y = get_pos_Y(snake,0);

//loops for setting the table of the game
  //First the frame
  for (i = 0; i < (screen->row); i++)
    for (j = 0; j <= (screen->col); j++)
      {
        // This is the case that the indexes are pointing to frame
	if (i == 0 || i == (screen->row) - 1 || j == 0 || j == (screen->col) - 1)
	  screen->playTable[i][j] = '#';
        // This is the case that the indexes are pointing to the rest of the table
	else
	  screen->playTable[i][j] = ' ';
      }

// Here we are checking if snake's head touches the body or the frame
  if (GameOver (screen, snake, head_x, head_y))
    return false; // In this case the game will stop

  // Iff the game is on, than we will set the snake to the play table
      for (index = 0; index < getLen(snake); index++)
    {
      head_x =get_pos_X(snake,index);                  //   snake->Pos[index].x;
      head_y = get_pos_Y(snake,index); 

      if (!index) 
	screen->playTable[head_y][head_x] = '+'; //Set the head
      else
	screen->playTable[head_y][head_x] = '*'; //set the body
    }

  
  return true;
}








// This function will print the screen to the relative stream
void PrintScreen (Screen  screen, FILE * fp)
{
  int i, j;

// Running over the 2D Array and print it to stream
  for (i = 0; i <= screen->row - 1; i++)
    {
      for (j = 0; j <= screen->col - 1; j++)
	
	  fprintf (fp,"%c", screen->playTable[i][j]);

	
      fprintf (fp, "\n");
    }


}

// This function will check if snake is touching himself or the borders
bool GameOver (Screen  screen, Snake  snake, int head_x, int head_y)
{
  int i; // Index for running on the snake's Array
  
  //First 'if' checks if snake's head is on te frame
  if (head_y == 0 || head_y >= (screen->row) - 1 || head_x == 0 || head_x >= (screen->col) - 1)
    return true;
  //Second if checks if snake's head touching himself
  for (i = 1; i < getLen(snake); i++)
    if ((head_x == get_pos_X(snake,i)) && (head_y==get_pos_Y(snake,i))) // the body
      return true; //If we got here, the game is over
  return false; // If we goti here the game is on
} 

 

bool    ScreenPositionEmpty(Screen screen, Position pos)
{
        if(screen->playTable[get_Y(pos)][get_X(pos)]==' ') // this happend only iff the coord in the matrix isn't the vorder nor the snake
        return true;
    return false;
 
}


bool    DrawApple(Screen screen, Apple apple)
{  
    if(ScreenPositionEmpty(screen,getApplePos(apple))) // check  whether there is empty place for the apple
    {
        screen->playTable[getApple_Position_Y(apple)][getApple_Position_X(apple)]='o'; // join the apple to the mat
        return true;
    } 
    return false;
}


