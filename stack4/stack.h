#ifndef STACK_H
#define STACK_H

// **structure defined in header files**

typedef struct {
	//int array[STACK_SIZE];	// 7 -> 8, 9
	int *pArr;
	int size;
	int tos;
} Stack;

void initStack(Stack *ps, int size);
void cleanupStack(Stack *ps);

void push(Stack *ps, int data);
int pop(Stack *ps);

#endif
