ex3: Screen.o Snake.o Position.o Apple.o misc.o main.o
	gcc Screen.o Snake.o Position.o misc.o main.o ex3
 
Screen.o: Screen.c Screen.h Snake.h Position.h misc.h Apple.h
	gcc -c Screen.c
Snake.o: Snake.c Snake.h Position.h misc.h Screen.h Apple.h
	gcc -c Snake.c
Position.o: Position.c Position.h misc.h
	gcc -c Position.c
Apple.o: Apple.c Apple.h misc.h Position.h
	gcc -c Apple.c
misc.o : misc.c misc.h
	gcc -c misc.c
main.o: main.c misc.h Position.h Screen.h Snake.h Apple.h
	gcc -c main.c
	
