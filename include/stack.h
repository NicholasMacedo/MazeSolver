#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

#ifndef _nmacedovLab3
#define _nmacedovLab3


/*
This struct holds a stack that has a list inside of it.
*/
typedef struct stack
{
  struct listNode * list;
} stack;

/*
 createStack: Creates a stack by using the createList and assigns initial values for the list within the stack.
 Pre: Takes in nothing.
 Post: Returns the pointer to the stackHead.
*/
stack * createStack();

/**
 destroyStack: Destroys the stack and frees allocated memory in the stack.
 Pre: Takes in stack head.
 Post: Returns nothing.
**/
void destroyStack(stack * theStack);

/***
 push: Adds number given to the stack (top).
 Pre: Takes in stak head and number to add to front.
 Post: Returns stack head with newly added element.
***/
stack * push(stack * theStack, int x, int y, int nodeInfo);

/****
 peek: Returns the value of the top of the stack.
 Pre: Takes in stack head.
 Post: Returns value of the top of the stack.
****/
int * peek(stack * theStack);

/*****
 pop: removes the value from the top of the stack.
 Pre: Takes in stack head.
 Post: Returns stack with removed top value.
*****/
stack * pop(stack * theStack);

/******
 printStack: Prints the given stack.
 Pre: Takes in stak head.
 Post: Returns nothing.
******/
void printStack(stack * theStack);

/*******
 stackLength: Finds the length of the stack.
 Pre: Takes in stack head.
 Post: Returns length of stack in an int.
*******/
int stackLength(stack * theStack);

#endif
