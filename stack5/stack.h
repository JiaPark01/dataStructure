#ifndef STACK_H
#define STACK_H

// **structure defined in header files**

typedef struct {
	//int array[STACK_SIZE];
	//int *pArr;				// 8 -> 9, 10
	void *pArr;
	int eleSize;
	int size;
	int tos;
} Stack;

void initStack(Stack *ps, int size, int eleSize);
void cleanupStack(Stack *ps);

//void push(Stack *ps, int data);
//void pop(Stack *ps, int *pData);
void push(Stack *ps, const void *pData);
void pop(Stack *ps, void *pData);

#endif
