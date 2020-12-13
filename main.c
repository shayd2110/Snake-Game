#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>

 #include "Apple.h"
#include "misc.h"
#include "Position.h"
#include "Screen.h"
#include "Snake.h"

/************************************************************************************************************************/
int main()
{
                int x,y, counter=0;     
                int x_Max,y_Max;        // this variables will hold  the randomzie limits
                bool elongate;              // determine whether the snake ate apple
                int prev_len;               // keep the original lenght for notify the user later
                Apple apple = NULL;
	// Create a screen
                Screen screen = CreateScreen(120, 40);
	// Create a snake of size 30
	Snake snake = CreateSnake(60, 20, 30);
	// Initial direction of movement is Right
	Direction direction = Right;
                prev_len=getLen(snake);
                x_Max=getCol(screen) + 1;
                y_Max = getRow(screen) + 1;
                
                
	// Make sure the STDIN buffer is empty
	fflush(stdin);

	// As long as we can draw a legal screen, keep on going
	while(DrawScreen(screen, snake)) {
		system("clear");
                                if(!apple)                  /// if the apple isn't exist
                                {
                                    elongate= false;        
                                    do
                                    {
                                    srand ( time(NULL) );       //randomization
                                    x= rand() % x_Max;
                                    y= rand() % y_Max;
                                    apple=CreateApple(x,y); // create the position of the apple
                                 
                                    }
                                     while(!ScreenPositionEmpty(screen,getApplePos(apple))); //keep randomization till free place found
                                }
                                 
                                
                                 
                                    
                               DrawApple(screen, apple);            // join the apple to the screen matrix
		// Print the current screen 
		PrintScreen(screen, stdout);
		// Wait 0.2 seconds
		sleep_ms(100);
		// If the user hit a key - read it and change direction if the key represent a legal direction
		if(kbhit()) {
			char ch = getchar();
			if((ch == Left) || (ch == Right) || (ch == Up) || (ch == Down)) {
				direction = (Direction)ch;
			}
			// Else - we will leave the original direction
		}
                              Position  pos=SnakeNext(snake,direction);
                      if( get_X(pos)  ==  getApple_Position_X(apple)      &&      get_Y(pos)  ==  getApple_Position_Y(apple) ) // check whether the snake's head reached to the apple
                                {
                                    elongate= true;
                                    counter++;
                                    DeleteApple(apple); 
                                    apple=NULL;
                            
                                }
                                else 
                                    elongate=false;
		MoveSnake(snake,direction,elongate);
                                DeletePosition(pos);
	}
                printf("Game Over dude!\t Your snake ate %d apples,your snake started with lenght :%d and now : %d \n",counter,prev_len,getLen(snake));
	DeleteScreen(screen);
	DeleteSnake(snake);

	return 0;
}
