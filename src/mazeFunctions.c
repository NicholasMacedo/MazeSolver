/*
Student Name: Nicholas Macedo - Van Horne
Student ID: nmacedov
Student Number: 0889469
*/ 

#include "stack.h"
#include "maze.h"

/* This function is used to open the file. */
FILE * openFile(char * fileName)
{
    FILE* filePointer = fopen(fileName,"r");
    if (filePointer == NULL)
    {
        printf("Cannot open the file. (Include file in command line.)\n");
        exit(1);
    }
    return(filePointer);
}

/* This function is used to remove the new line from the use of fgets. */
char * removeNewline(char* fileLine)
{
    int i;
    int fileLineLen;

    fileLineLen = strlen(fileLine);

    for (i = 0; i < fileLineLen; i++)
    {
        if (fileLine[i] == '\n')
        {
            fileLine[i] = '\0';
        }
    }

    return(fileLine);
}

/* This function gets the height of the maze using a while loop and a counter. */
int fileHeight(FILE * filePointer)
{
    int height = 0;
    char * fileLineTemp = malloc(sizeof(char)*500);
    while (fgets(fileLineTemp, 500, filePointer) != NULL)
    {
        height ++;
    }
    free(fileLineTemp);
    height = height + 1;
    return(height);
}

/* This function gets the length of the maze by reading in the first line and gettin the length. */
int fileLength(FILE * filePointer)
{
    int length = 0;
    char * fileLineTemp = malloc(sizeof(char)*500);
    fgets(fileLineTemp, 500, filePointer);
    length = strlen(fileLineTemp);
    free(fileLineTemp);
    length = length +2;
    return(length);
}

/* This function searches the given location in the maze array for spaces beside it to determine if it is an intersection. */
int isIntersection(char ** mazeArray, int currX, int currY)
{
    int numPaths = 0;

    if ((mazeArray[currX-1][currY] == ' ') || (mazeArray[currX-1][currY] == 'S') || (mazeArray[currX-1][currY] == 'F'))
    {
        numPaths ++;
    }
    if ((mazeArray[currX+1][currY] == ' ') || (mazeArray[currX+1][currY] == 'S') || (mazeArray[currX+1][currY] == 'F'))
    {
        numPaths ++;
    }
    if ((mazeArray[currX][currY-1] == ' ') || (mazeArray[currX][currY-1] == 'S') || (mazeArray[currX][currY-1] == 'F'))
    {
        numPaths++;
    }
    if ((mazeArray[currX][currY+1] == ' ') || (mazeArray[currX][currY+1] == 'S') || (mazeArray[currX][currY+1] == 'F'))
    {
        numPaths ++;
    }
	
    if (numPaths > 1)
    {
        return(1);
    }
    return(0);
}

/* This function cycles through the dead end locations from the stack and calls a function to fill in the path. */
char ** fillDeadEnds(char ** mazeArray, stack * deadEnds)
{
    int currX = 0;
    int currY = 0;
    int * value;
    int i = 0;
    int stackLen = stackLength(deadEnds);

    for (i=0;i<stackLen;i++)
    {
        value = peek(deadEnds);
        currX = value[0];
        currY = value[1];
        /*printf("%d,%d\n",currX,currY);*/
        mazeArray = fillEnd(mazeArray,currX,currY);
        deadEnds = pop(deadEnds);
    }
    free(value);
    return(mazeArray);
}

/* This function fills in the path from the dead end until an intersection is found. */
char ** fillEnd(char ** mazeArray, int currX, int currY)
{
    int inter = 0;

    while (inter ==0)
    {
        if (mazeArray[currX-1][currY] == ' ')
        {
            currX = currX-1;
            inter = isIntersection(mazeArray,currX,currY);
            /*printf("isInter: %d\n",inter); */
            if (inter == 0)
            {
                mazeArray[currX][currY] = 'X';
            }
        }
        else if (mazeArray[currX+1][currY] == ' ')
        {
            currX = currX+1;
            inter = isIntersection(mazeArray,currX,currY);
            /*printf("isInter: %d\n",inter);*/
            if (inter == 0)
            {
                mazeArray[currX][currY] = 'X';
            }
        }
        else if (mazeArray[currX][currY-1] == ' ')
        {
            currY = currY-1;
            inter = isIntersection(mazeArray,currX,currY);
            /*printf("isInter: %d\n",inter);*/
           if (inter == 0)
           {
               mazeArray[currX][currY] = 'X';
           }
        }
        else if (mazeArray[currX][currY+1] == ' ')
        {
            currY = currY+1;
            inter = isIntersection(mazeArray,currX,currY);
            /*printf("isInter: %d\n",inter);*/
            if (inter == 0)
            {
                mazeArray[currX][currY] = 'X';
            }
        }
        else
        {
            inter = 1;
        }
    }

   return(mazeArray);
}

/* This function places the starting "X" in their origional locations (At Dead Ends). */
char ** initEnds(char ** mazeArray,stack * deadEnds)
{
    int currX;
    int currY;
    listNode * currListPos;
    currListPos = (deadEnds->list)->next;

    while (currListPos->next != NULL)
    {
        currX = currListPos->x;
        currY = currListPos->y;
        /*printf("%d,%d\n",currX,currY);*/
        mazeArray[currX][currY] = 'X';
        currListPos = currListPos->next;
    }

        currX = currListPos->x;
        currY = currListPos->y;
        /*printf("%d,%d\n",currX,currY);*/   
        mazeArray[currX][currY] = 'X';

    return(mazeArray);
}

/* This function locates the dead ends in the maze and stores them in a stack. */
stack * findDeadEnd(char ** mazeArray,int mazeHeight, int mazeLength)
{
    stack * deadEnds = createStack();
    int i = 0;
    int k = 0;
    int answer = 0;
    for (i=1;i<mazeHeight-1;i++)
    {
        for (k=1;k<mazeLength;k++)
        {
            answer = isDeadEnd(mazeArray,i,k);
            if (answer == 1)
            {
                push(deadEnds,i,k,0);
                (deadEnds->list)->x ++;
            }
        }
    }
   
    return(deadEnds);
}

/* This function checks to see if the spot in question is a dead end. */
int isDeadEnd(char ** mazeArray, int currX, int currY)
{
    int numWall = 0;
    if (((mazeArray[currX-1][currY] == '-') || (mazeArray[currX-1][currY] == '|')) && ((mazeArray[currX][currY] == ' ')))
    {
        numWall ++;
    }
    if (((mazeArray[currX+1][currY] == '-') || (mazeArray[currX-1][currY] == '|')) && ((mazeArray[currX][currY] == ' ')))
    {
        numWall ++;
    }
    if (((mazeArray[currX][currY-1] == '-') || (mazeArray[currX][currY-1] == '|')) && ((mazeArray[currX][currY] == ' ')))
    {
        numWall ++;
    }
    if (((mazeArray[currX][currY+1] == '-') || (mazeArray[currX][currY+1] == '|')) && ((mazeArray[currX][currY] == ' ')))
    {
        numWall ++;
    }
    if (numWall == 3)
    {
        return(1);
    }
    return(0);
}

/* This function converts the maze thats filled with "X" to being spaces and the old spaces to be "*". */
char ** convertMaze(char ** mazeArray, int mazeHeight, int mazeLength)
{
    int i = 0;
    int k = 0;
    
    for (i=0;i<mazeHeight;i++)
    {
        for (k=0;k<mazeLength;k++)
        {
            if (mazeArray[i][k] == ' ')
            {
                mazeArray[i][k] = '*';
            }
            if (mazeArray[i][k] == 'X')
            {
                mazeArray[i][k] = ' ';
            }
        }   
    }

    return(mazeArray);
}

/* This function prints the maze. */
void printMaze(char ** mazeArray,int height,int length)
{
    int i;
    for (i=0;i< height;i++)
    {
        printf("%s\n",mazeArray[i]);
    }

    return;
}
