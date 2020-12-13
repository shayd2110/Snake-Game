#include "Snake.h"
#include "Screen.h"

 struct Snake // Struct that will hold the relative values for the snake
{
  Position* Pos; // This is the array that will keep the values of the snake Array
  int lenght; //This var will keep the lenght of the snake
  Direction dir; //This var will keep the value of the direction of the snake

} ;

/******************* Constructor  ****************/

Snake CreateSnake (int x, int y, int len)
{

  int i; //Index var
  Snake snake = (Snake )AllocateMemory(sizeof(Snake),__FILE__, __LINE__); //Creation of Snake Object
  
  // A set of checks to verifying the values, split by cases to make the user know exactly where he goes worng
  if (!CheckPositive (x))
    {
      fprintf (stderr, "the value %d that you have insert to x, is not vaild, please insert Non-Negetive value\n",x);
      return NULL;
    }
    
  if (!CheckPositive (y))
    {
      fprintf (stderr,"the value %d that you have insert to y, is not vaild, please insert Non-Negetive value\n", y);
      return NULL;
    }
  
  if (!CheckLen(len, x))   
    {
      fprintf (stderr,"the value %d that you have insert to lenght, is not vaild, please insert positive value\n", len);
      return NULL;
    }
  
  snake->dir = Right; // Initialize the  direction to  right
  setLen(snake, len); // Set the snake lenght by the user's value
  snake->Pos = (Position*)AllocateMemory(len*sizeof(Position), __FILE__ , __LINE__); //Allocating the position's Array
  
  for (i = 0; i < len; i++) // Now we will set the position in the allocated array 
  {
           snake->Pos[i]=(CreatePosition(x - i ,y)); 

  }
  return snake; // Return the pointer of the snake for future usage


}

/******************* Destructor  ****************/

//This function will free the memory that was allocate for the snake 
void DeleteSnake (Snake  snake)
{
    FreeMemory(snake->Pos); //Firstly freeing the Array
    FreeMemory(snake);          // Secondly freeing the snake pointer
}

/******************* Getters  ****************/


int     getLen(Snake snake)
{
    return snake->lenght; 
}


int get_pos_X(Snake snake,int index)
{
    return get_X(snake->Pos[index]);
}

int get_pos_Y(Snake snake,int index)
{
    return get_Y(snake->Pos[index]);
}

/******************* Setters  ****************/

void set_pos_X(Snake snake, int x, int index)
{
    set_X(snake->Pos[index],  x);
}


void set_pos_Y(Snake snake, int y, int index)
{
    set_Y(snake->Pos[index],  y);
}
 

void    setLen(Snake snake, int lenght)
{
    snake->lenght=lenght;
}


/******************* Functions  ****************/

    
void MoveSnake (Snake  snake, Direction dir,bool elongate)
{

  if(elongate)
  {
      snake->Pos=(Position*)ReallocateMemory(snake->Pos,(getLen(snake)*sizeof(Position)+1),__FILE__,__LINE__); // reallocating the array for the new snake
      snake->lenght++;      //increase the lenght of the snake
 
    
  }

  if(!CheckDirection(snake,dir))
  {                                 //This bracket is just for safety 
      dir=snake->dir;  // keep the direcion as the same he was before
  }         
  
  
  followPos(snake); // Make the bofy of the snake follow the head

  switch (dir) //Switch cases for mooving the snake to the right direction
    {
             case Right:
              snake->dir=Right; //Assigning the direction the Right
            set_X(snake->Pos[0],(get_X(snake->Pos[0]))+1);            //snake->Pos[0]->x++; //if we turn right the value of X of the head need to increase
              break;
          
             case Left:
                 snake->dir=Left;
                set_X(snake->Pos[0],(get_X(snake->Pos[0]))-1);     //snake->Pos[0].x--;  //if we turn right the value of X of the head need to decrease
	break;
            
            case Up:
                snake->dir=Up;
                 set_Y(snake->Pos[0],(get_Y(snake->Pos[0]))-1);    //snake->Pos[0].y--;  //if we turn right the value of Y of the head need to decrease
	break;
        
           case Down:
                snake->dir=Down;
                set_Y(snake->Pos[0],(get_Y(snake->Pos[0]))+1);        //snake->Pos[0].y++;//if we turn right the value of Y of the head need to increase
                break;

    }
  
  }
  
  


// This function will check if the lenght is not grater the the X coord of the snake's head
bool CheckLen (int len, int x) 
{
  if (len > x)
    return false; // the value is invaild 
  return true; // the value is vaild
}

// This is an assistant function that will check if the direction is legal
bool CheckDirection ( Snake  snake,Direction dir)
{
	if(((snake->dir == Right) && (dir != Left)) ||                 // If the user typed right and the direction is not left
		((snake->dir == Left) && (dir != Right)) ||  // If the user typed left and the direction is not right 
		((snake->dir == Up) && (dir != Down)) ||  // If the user typed up and the direction is not down
		((snake->dir == Down) && (dir != Up)))  // If the user typed down and the direction is not up
		{
			return true;                           //So the direction is not the same direction nor the opposite
		}
		return false;                                       // The direction is the same direction or the opposite
}

 // This function wiil check if the values is legal for the snake's values
bool CheckPositive (int number)
{
  if (number < 0)
    return false; // The value is invaild
  return true;  // The value is vaild
}


// This function will make the body of the snake follow the head
void followPos(Snake snake)
{
    int i;
          for(i=snake->lenght-1;i>0;i--) // lenght -1 because the head is already moved
          {
              snake->Pos[i]= CreatePosition(get_pos_X(snake,i-1),get_pos_Y(snake,i-1));

          }
  
}


Position SnakeNext (Snake snake ,Direction dir)
{
    int next_x =get_X(snake->Pos[0]);
    int next_y =get_Y(snake->Pos[0]);
    switch(dir)  // at any case checks just the head
    {
        case Up:
            next_y--;
            break;
        case Down:
            next_y++;
            break;
        case Left:
            next_x--;
            break;
        case Right:
            next_x++;
            break;
           
    }
     return CreatePosition(next_x,next_y);
}




    



    
 