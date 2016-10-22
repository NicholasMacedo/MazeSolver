/*
Student Name: Nicholas Macedo - Van Horne
Student ID: nmacedov
Student Number: 0889469
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "stack.h"
#include "maze.h"

int main(int argc,char * argv[])
{
    FILE * filePointer1 = openFile(argv[1]);
    FILE * filePointer2 = openFile(argv[1]);
    int mazeLength = fileLength(filePointer1); 
    int mazeHeight = fileHeight(filePointer1);
    char * fileLine = malloc(sizeof(char)*mazeLength);
    int i = 0;
    int counter = 0;
    char ** mazeArray = malloc(sizeof(char*)*mazeHeight);
    stack * deadEnds;


    /*Check for right number of commandline argurments*/
    if (argc != 2)
    {
        printf("Wrong number of arguments. Please try again.\n");
        exit(0);
    }

    /*printf("1:%d(l)x%d(h)\n",mazeLength,mazeHeight); */

    /*loops through the file until end of file and stores maze in 2D Array*/
    while (fgets(fileLine,mazeLength, filePointer2) != NULL)
    {
        mazeArray[counter] = malloc(sizeof(char)*mazeLength);
        fileLine = removeNewline(fileLine);
        strcpy(mazeArray[counter],fileLine);
        counter ++;
    }

    /*printMaze(mazeArray,mazeHeight,mazeLength);*/

    /* Finds all dead ends in the maze and stores in a stack */
    deadEnds = findDeadEnd(mazeArray,mazeHeight,mazeLength);

    /*printStack(deadEnds);*/

    /* Places the initial marker for the dead end "X" */
    mazeArray = initEnds(mazeArray,deadEnds);

    /*printMaze(mazeArray,mazeHeight,mazeLength);*/ 

    /*printStack(deadEnds);*/

    /* Goes through the maze and fills in areas that is not the solution path */
    mazeArray = fillDeadEnds(mazeArray,deadEnds);

    /*printMaze(mazeArray,mazeHeight,mazeLength);*/

    /* Converts the maze from being filled with "X" to a path showing the way using "*" */
    mazeArray = convertMaze(mazeArray,mazeHeight,mazeLength); 

    /* Prints the maze with a solution to the screen */
    printMaze(mazeArray,mazeHeight,mazeLength); 

    /* Loops through the maze array and frees used data */
    for (i=0;i==mazeHeight;i++)
    {
        free(mazeArray[i]);
    } 
    free(fileLine);

    /* Closes files */
    fclose(filePointer1);
    fclose(filePointer2);
    return(0);
}
