/*
Student Name: Nicholas Macedo - Van Horne
Student ID: nmacedov
Student Number: 0889469
*/

#include "stack.h"

/*
This function creates the stack using the createList function from the list ADT. It can be used by calling it and equaling it to the stack you made.
*/
stack * createStack()
{
    stack * stackHead = malloc(sizeof(stack)*1);
    listNode * tempList = createList();    
    stackHead->list = tempList;
    return(stackHead);
}


/*
This function destroys the stack using the destroyList function from the list ADT. It can be used by calling it and giving it a pointer to the stack.
*/
void destroyStack (stack * theStack)
{
    if (theStack == NULL)
    {
        printf("Error. Nothing to Destroy. NULL Stack.\n");
        return;
    }
    destroyList(theStack->list);
    free(theStack);
    return;
}

/*
This function is used to add to the stack. The user gives it the stack and the number they would like to put into the stack.
*/
stack * push(stack * theStack, int x, int y, int nodeInfo)
{
    if (theStack == NULL)
    {
        printf("Error. Null Stack. Returning NULL.\n");
        return(NULL);
    }
    theStack->list = addToFront(theStack->list,x,y,nodeInfo);
    return(theStack);
}

/*
This function is used to get the value of the top of the stack.
*/
int * peek(stack * theStack)
{
    int * topValue = 0;    
    if (theStack == NULL)
    {
        printf("Error. NULL Stack. Returning NULL.\n");
        return(NULL);
    }
    topValue = getFrontValue(theStack->list);
    return(topValue);
}

/*
This function is used to remove the first value from the stack.
*/
stack * pop(stack * theStack)
{
    if (theStack == NULL)
    {
        printf("Error. NULL Stack. Returning NULL.\n");
        return(NULL);
    }
    theStack->list = removeFromFront(theStack->list);
    return(theStack);
}

/*
This function is used to get the length of the stack.
*/
int stackLength(stack * theStack)
{   
    int stackLen;
    if (theStack == NULL)
    {
        printf("Error. NULL Stack. Returning 0.\n");
        return(0);
    }
    stackLen = listLength(theStack->list);
    return(stackLen);
}


/*
This function is used to print the contents of the stack.
*/
void printStack (stack * theStack)
{
    if (theStack == NULL)
    {
        printf("Error. Nothing to Print. NULL Stack.\n");
        return;
    }
    printList(theStack->list);
    return;
}
