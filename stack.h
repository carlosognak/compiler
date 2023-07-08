#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdio.h>



/* Check if the stack is empty */
int isempty();

/* Check if the stack is full */
int isfull();

/* Function to return the topmost element in the stack */
int peek();

/* Function to delete from the stack */
int pop();

int push(char data);
#endif // STACK_H_INCLUDED
