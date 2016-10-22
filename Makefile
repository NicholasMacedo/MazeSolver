CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -pedantic -g

#Directories where the compiler can find things
INCLUDES    = -Iinclude

all : testing program


testing :
	gcc $(CFLAGS) src/linkedList.c src/stackADT.c src/testing.c -o bin/runTests -Iinclude


program: 
	gcc $(CFLAGS) src/linkedList.c src/stackADT.c src/maze.c src/mazeFunctions.c -o bin/mazeSolver -Iinclude

clean:
	@ rm *.o



