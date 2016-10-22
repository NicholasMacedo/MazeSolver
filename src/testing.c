/*
Student Name: Nicholas Macedo - Van Horne
Student ID: nmacedov
Student Number: 0889469
*/ 

#include "linkedList.h"
#include "stack.h"


int main(void)
{
    /*Test to show that the stack and list is created and can be filled with the push function and a for loop. Print Function is used to print the stack. */

    int smallTestDataArray[10] = {10,9,8,7,6,5,4,3,2,1};
    int bigTestDataArray[10] = {10000,9999,9998,9997,9996,9995,9994,9993,9992,9991};
    int negTestDataArray[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
    int i = 0;
    int null = 0; /* Giving the "NULL" number 0 b/c NULL is kinda equal to Zero but its of type void* and gets hit w/ a warning @ compile. */
    stack * smallTestStack;
    stack * bigTestStack;
    stack * negTestStack;
    int returnNum = 0;
    int * stackValues = 0;

    smallTestStack = createStack();
    bigTestStack = createStack();
    negTestStack = createStack();   
    for (i=0;i<10;i++)
    {
        push(smallTestStack,smallTestDataArray[i],smallTestDataArray[i],smallTestDataArray[i]);
        push(bigTestStack,bigTestDataArray[i],bigTestDataArray[i],bigTestDataArray[i]);
        push(negTestStack,negTestDataArray[i],negTestDataArray[i],negTestDataArray[i]);

    }
    
    printf("\t****Initial Testing Stack Values****\n");
    printf("***Small Test Stack***\n");
    printStack(smallTestStack);
    printf("***Big Test Stack***\n");
    printStack(bigTestStack);
    printf("***Negative Test Stack***\n");
    printStack(negTestStack);

    /*Testing Functions (Look at prints to follow whats happening.)*/
    printf("\n\t**** Individual Function Testing Begins****\n");
    printf("**Beginning Testing: pop **\n");
    printf("Testing Null Case:\n");
    pop(NULL);
    printf("Testing Big Numbers Case:\n");
    pop(bigTestStack);
    printStack(bigTestStack);
    printf("Testing Small Numbers Case:\n");
    pop(smallTestStack);
    printStack(smallTestStack);
    printf("Testing Negative Numbers Case:\n");
    pop(negTestStack);
    printStack(negTestStack);
    printf("**Ending Testing: pop **\n\n");

    printf("**Beginning Testing: peek **\n");
    printf("Testing Null Case:\n");
    peek(NULL);
    printf("Testing Big Numbers Case:\n");
    stackValues = peek(bigTestStack);
    printf("Values: %d(x) %d(y) %d(nodeInfo)\n",stackValues[0],stackValues[1],stackValues[2]);
    printf("Testing Small Numbers Case:\n");
    stackValues = peek(smallTestStack);
    printf("Values: %d(x) %d(y) %d(nodeInfo)\n",stackValues[0],stackValues[1],stackValues[2]);
    printf("Testing Negative Numbers Case:\n");
    stackValues = peek(negTestStack);
    printf("Values: %d(x) %d(y) %d(nodeInfo)\n",stackValues[0],stackValues[1],stackValues[2]);
    printf("**Ending Testing: peek **\n\n");

    printf("**Beginning Testing: stackLength **\n");
    printf("Testing Null Case:\n");
    returnNum = stackLength(NULL);
    printf("Value: %d\n",returnNum);
    printf("Testing Big Numbers Case:\n");
    returnNum = stackLength(bigTestStack);
    printf("Value: %d\n",returnNum);
    printf("Testing Small Numbers Case:\n");
    returnNum = stackLength(smallTestStack);
    printf("Value: %d\n",returnNum);
    printf("Testing Negative Numbers Case:\n");
    returnNum = stackLength(negTestStack);
    printf("Value: %d\n",returnNum);
    printf("**Ending Testing: stackLength **\n\n");
 
    printf("**Beginning Testing: push **\n");
    printf("Testing Null Case:\n");
    push(NULL,null,null,null);
    printf("Testing Big Numbers Case:\n");
    push(bigTestStack,9991,9991,9991);
    printStack(bigTestStack);
    printf("Testing Small Numbers Case:\n");
    push(smallTestStack,1,1,1);
    printStack(smallTestStack);
    printf("Testing Negative Numbers Case:\n");
    push(negTestStack,-10,-10,-10);
    printStack(negTestStack);
    printf("**Ending Testing: push **\n\n");  

    printf("**Beginning Testing: printStack **\n");
    printf("Testing Null Case:\n");
    printStack(NULL);
    printf("**Ending Testing: printStack **\n\n");

    printf("**Beginning Testing: destroyStack **\n");
    printf("Testing Null Case:\n");
    destroyStack(NULL);

    destroyStack(smallTestStack);
    destroyStack(bigTestStack);
    destroyStack(negTestStack);
    free(stackValues);
    printf("**Ending Testing: destroyStack **\n");
    printf("\t****End of Individual Function Testing****\n");   

    return(0);
}
