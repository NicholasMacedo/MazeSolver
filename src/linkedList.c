/*
Student Name: Nicholas Macedo - Van Horne
Student ID: nmacedov
Student Number: 0889469
*/

#include "linkedList.h"

/*
This function creates the list using a dummy head. It can be used by calling it and equaling it to the list you made.
*/
listNode * createList()
{
    listNode * dummyNode = malloc(sizeof(listNode)*1);
    dummyNode->x = 0;
    dummyNode->y = 0;
    dummyNode->nodeInfo = 0;
    dummyNode->next = NULL;    
    return(dummyNode);
}

/*
This function destroys the list. It can be used by calling it and giving it a pointer to the list.
*/
void destroyList (listNode * theList)
{
    if (theList == NULL)
    {
        printf("Error. NULL List. Returning.\n");
        return;
    }

    while (theList->next != NULL)
    {
        removeFromFront(theList);
    }
    free(theList);
    return;
}

/*
This function is used to add to the front of the list. The user gives it the list and the number they would like to put in the front.
*/
listNode * addToFront(listNode * theList, int x, int y, int nodeInfo)
{
    listNode * newNode = initNode(x,y,nodeInfo);
    if (theList == NULL)
    {
        printf("Error. Null List. Returning Null.\n");
        return(NULL);
    }

    newNode->next = theList->next;
    theList->next = newNode;
    theList->nodeInfo ++;
    return(theList);
}

/*
This function is used to get the value of the front of the list.
*/
int * getFrontValue(listNode * theList)
{
    int * frontValue = malloc(sizeof(int)*3);    

    if (theList == NULL)
    {
        printf("Error. NULL List. Returning 0.\n");
        return(0);
    }
    else if (theList->next == NULL)
    {
        printf("Error. Retuning 0. No Front Node Found in List.\n");
        return(0);
    }
    else
    {
        frontValue[0] = (theList->next)->x;
        frontValue[1] = (theList->next)->y;
        frontValue[2] = (theList->next)->nodeInfo;
    }
    return(frontValue);
}

/*
This function is used to get the length of the list.
*/
int listLength(listNode * theList)
{   
    if (theList == NULL)
    {
        printf("Error. NULL List. Returning 0.\n");
        return(0);
    }

    return(theList->nodeInfo);
}

/*
This function is used to add to the back of the list. The user gives it the list and the number they would like to put in the back.
*/
listNode * addToList(listNode * theList, int x, int y, int nodeInfo)
{
    listNode * tailNode = malloc(sizeof(listNode)*1);
    listNode * newNode = initNode(x,y,nodeInfo);
    
    if (theList == NULL)
    {
        printf("Error. NULL list. Returning NULL.\n");
        return(NULL);
    }

    tailNode = theList;

    while (tailNode->next != NULL)
    {
        tailNode = tailNode->next;
    }
    
    tailNode->next = newNode;
    theList->nodeInfo ++;
    return(theList);
}

/*
This function is used to create a new node for the list.
*/
listNode * initNode(int x, int y, int nodeInfo)
{
    listNode * newNode;
    newNode = malloc(sizeof(listNode)*1);
    newNode->x = x;
    newNode->y = y;
    newNode->nodeInfo = nodeInfo;
    newNode->next = NULL;
    return(newNode);
}

/*
This function is used to remove the first node from the list.
*/
listNode * removeFromFront (listNode * theList)
{
    listNode * toBeRemoved;
    if (theList == NULL)
    {
        printf("Error. The list is NULL.\n");
        return(NULL);
    }
    else if (theList->next == NULL)
    {
        printf("Error. Retuning list. List is empty.\n");
        return(theList);
    }
    else
    {
        toBeRemoved = theList->next;
        theList->next = (theList->next)->next;
        free(toBeRemoved);
        theList->nodeInfo --;
    } 
    return(theList);
}

/*
This function is used to create a new node for the list.
*/
void printList (listNode * theList)
{
    listNode * currListPos;
    
    if (theList == NULL)
    {
        printf("Error. NULL list. Returning.\n");
        return;
    }
    else if (theList->next == NULL)
    {
        printf("The List is empty. Returning.\n");
        return;
    }
    else
    {
        currListPos = theList->next;

        while (currListPos->next != NULL)
        {
            printf("(%d,%d) NodeInfo:%d\n",currListPos->x,currListPos->y,currListPos->nodeInfo);
            currListPos = currListPos->next;
        }

        printf("(%d,%d) NodeInfo:%d\n",currListPos->x,currListPos->y,currListPos->nodeInfo);
    }    
    return;
}


