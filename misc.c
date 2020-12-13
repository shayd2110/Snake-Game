#include "misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <curses.h>
#include <fcntl.h>
#include <unistd.h>

/*******************************************************************************************************************************/
void* AllocateMemory(unsigned int size, const char* file, int line_num)
{
	void*	ptr = malloc(size);

	// If we failed the user will know exactly where the error happened
	if(ptr == NULL) {
		fprintf(stderr, "Fatal error in %s (%d): failed to allocate memory of size %u\n\n", file, line_num, size);
		exit(-1);
	}

	// Set all memory to 0
	memset(ptr, 0, size);

	return ptr;
}
//change
/*******************************************************************************************************************************/
void    FreeMemory(void* mem)
{
        free(mem);
}

/*******************************************************************************************************************************/
void sleep_ms(int milliseconds) // cross-platform sleep function
{
#ifdef WIN32
        Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
        struct timespec ts;
        ts.tv_sec = milliseconds / 1000;
        ts.tv_nsec = (milliseconds % 1000) * 1000000;
        nanosleep(&ts, NULL);
#else
        usleep(milliseconds * 1000);
#endif
}

/*******************************************************************************************************************************/
bool kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;
 
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
	ch = getchar();
 
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
 
	if(ch != EOF)
	{
		ungetc(ch, stdin);
		return true;
	}
 
	return false;
}

// Allocate a 2D memory as described in the assignment
void**	AllocateMemory2D(unsigned int nrows, unsigned int ncols, unsigned int element_size, const char* file, int line_num)
{
    int i; // Index
    //Firstly allocate the pointers's Array
    void  **ptr= (void**)AllocateMemory(ncols*(sizeof(void*)), file ,line_num);
    
    //Sednodly allocate the big Array
    ptr[0]=AllocateMemory(element_size * nrows * ncols ,file,line_num);
    
    //Finally set the Array's parts according to the start size
    for(i=1;i<ncols;i++)
        ptr[i]=ptr[0]+(i* nrows * element_size);
    return ptr;
    
    
    
}

// Free memory allocated by AllocateMemory2D()
void FreeMemory2D(void** mem)
{
    // First we will free the big array
    FreeMemory(mem[0]);
    //than we will free the small array
    FreeMemory(mem);
}


/*
int random(int from, int to)
{
	int r = from + rand() % to;
	return r;
}
 */


void* ReallocateMemory(void* mem, unsigned int size, const char* file, int line_num)
{
        void*   ptr = realloc(mem, size);

        // If we failed the user will know exactly where the error happened
        if(ptr == NULL) {
                fprintf(stderr, "Fatal error in %s (%d): failed to allocate memory of size %u\n\n", file, line_num, size);
                exit(-1);
        }

        return ptr;
}