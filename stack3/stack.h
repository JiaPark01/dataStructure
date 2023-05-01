#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 100
// **structure defined in header files**

typedef struct {
	int array[STACK_SIZE];
	int tos;
} Stack;

void initStack(Stack *ps);

void push(Stack *ps, int data);
int pop(Stack *ps);

#endif
