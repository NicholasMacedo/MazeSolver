/*
Student Name: Nicholas Macedo - Van Horne
Student ID: nmacedov
Student Number: 0889469
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

#ifndef _nmacedovMaze
#define _nmacedovMaze


/*
 convertMaze: Converts the maze from being filled with X's to *'s to show the path.
 Pre: Takes in the maze array, height and length of the maze.
 Post: Returns the maze array with the changes.
*/
char ** convertMaze(char ** mazeArray, int mazeHeight, int mazeLength);

/**
 fileHeight: Gets the height of the maze in the file.
 Pre: Takes in pointer to the maze file.
 Post: Returns the height of the maze.
**/
int fileHeight(FILE * filePointer);

/***
 fileLength: Gets the length of the maze in the file.
 Pre: Takes in pointer to the maze file.
 Post: Returns the length of the maze.
***/
int fileLength(FILE * filePointer);

/****
 fillDeadEnds: Cycles through the dead end locations from the stack and calls a function to fill in the path.
 Pre: Takes in the maze array and the dead ends stack.
 Post: Returns the maze array with changes made.
****/
char ** fillDeadEnds(char ** mazeArray, stack * deadEnds);

/*****
 fillEnd: Fills in the path from the dead end until an intersection is found.
 Pre: Takes in the maze array and the current X and Y values.
 Post: Returns the maze array with changes.
*****/
char ** fillEnd(char ** mazeArray, int currX, int currY);

/******
 findDeadEnd: Locates the dead ends in the maze and stores them in a stack.
 Pre: Takes in the maze array, height and length of the maze.
 Post: Returns the newly created stack holding the locations of all the dead ends.
******/
stack * findDeadEnd(char ** mazeArray,int mazeHeight, int mazeLength);

/*******
 initEnds: Places the starting "X" in their origional locations (At Dead Ends).
 Pre: Takes in the maze array and the stack of dead ends.
 Post: Returns the maze array with changes.
*******/
char ** initEnds(char ** mazeArray, stack * deadEnds);

/********
 isDeadEnd: Checks to see if the spot in question is a dead end.
 Pre: Takes in the maze array with the current X and Y.
 Post: Returns 1 if it is a dead end and 0 if it isn't.
********/
int isDeadEnd(char ** mazeArray, int currX, int currY);

/*********
 isIntersection: Searches the given location in the maze array for spaces beside it to determine if it is an intersection.
 Pre: Takes in the maze array with the current X and Y.
 Post: Returns 1 if it is an intersection and 0 if it isn't.
*********/
int isIntersection(char ** mazeArray, int currX, int currY);

/**********
 openFile: Opens the given file name.
 Pre: Takes in the file name.
 Post: Returns a pointer to the file.
**********/
FILE* openFile(char * fileName);

/***********
 printMaze: Prints the maze. 
 Pre: Takes in the maze array.
 Post: Returns nothing.
***********/
void printMaze(char ** mazeArray, int height, int length);

/************
 removeNewLine: Removes the extra newline character from fgets. 
 Pre: Takes in the file line.
 Post: Returns file line with no extra newline.
************/
char* removeNewline(char* fileLine);

#endif
