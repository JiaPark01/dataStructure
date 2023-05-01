#include <assert.h>
#include "stack.h"

void initStack(Stack *ps)		// reset local var (only global var is resetted)
{
	ps->tos = 0;
}

void push(Stack *ps, int data)
{
	assert(ps->tos != STACK_SIZE);
	ps->array[ps->tos] = data;
	++ps->tos;
}

int pop(Stack *ps)
{
	assert(ps->tos);
	--ps->tos;
	return ps->array[ps->tos];
}
