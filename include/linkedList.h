#include <stdlib.h>
#include <stdio.h>

#ifndef _nmacedovLab2
#define _nmacedovLab2

/*
This list node holds a number and a pointer to the next number.
*/
typedef struct listNode
{
    int x;
    int y;
    int nodeInfo;
    struct listNode * next;
} listNode;

/*
 createList: Creates the dummy head of the list (Malloc) and assigns initial values for the dummy head.
 Pre: Takes in nothing.
 Post: Returns the pointer to the dummyNode.
*/
listNode * createList();

/**
 destroyList: Destroys the list and frees allocated memory.
 Pre: Takes in list head.
 Post: Returns nothing.
**/
void destroyList(listNode * theList);

/***
 addToList: Adds number given to back of the list.
 Pre: Takes in the list head and the number to be added.
 Post: Returns the list with added value to the list.
***/
listNode * addToList(listNode * theList, int x, int y, int nodeInfo);

/****
 addToFront: Adds number given to front of the list.
 Pre: Takes in list head and number to add to front.
 Post: Returns list head.
****/
listNode * addToFront(listNode * theList, int x, int y, int nodeInfo);

/*****
 getFrontValue: Returns the value of the first list node (after the head).
 Pre: Takes in list head.
 Post: Returns value of the first list node.
*****/
int * getFrontValue(listNode * theList);

/******
 initNode: creates a node from the given number.
 Pre: Takes in value of the node.
 Post: Returns pointer to the node.
******/
listNode * initNode(int x, int y, int nodeInfo);

/*******
 removeFromFront: removes the first node from the list and frees it (node after head).
 Pre: Takes in list head.
 Post: Returns list with removed and replaced first value.
*******/
listNode * removeFromFront(listNode * theList);

/********
 printList: Prints the list.
 Pre: Takes in list head.
 Post: Returns nothing.
********/
void printList(listNode * theList);

/*********
 listLength: FInds the length of the list.
 Pre: Takes in list head.
 Post: Returns length of list in an int.
*********/
int listLength(listNode * theList);


#endif
