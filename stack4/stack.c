#include <stdio.h>		// fprintf
#include <stdlib.h>		// exit, malloc
#include <assert.h>
#include "stack.h"

void initStack(Stack *ps, int size)		// reset local var (only global var is resetted)
{
	ps->pArr = malloc(sizeof(int) * size);
	assert(ps->pArr);	// in case not assigned any space, stop
	ps->size = size;
	ps->tos = 0;
}

void cleanupStack(Stack *ps)
{
	free(ps->pArr);
}

void push(Stack *ps, int data)
{
	/*
	if (ps->tos == ps->size) {
		fprintf(stderr, "stack is full\n");
		exit(1);
	}
	*/
	assert(ps->tos != ps->size);
	ps->pArr[ps->tos] = data;
	++ps->tos;
}

int pop(Stack *ps)
{
	/*
	if (ps->tos == 00)) {
		fprintf(stderr, "stack is empty\n");
		exit(1);
	}
	*/
	assert(ps->tos);
	--ps->tos;
	return ps->pArr[ps->tos];
}
