#include <stdlib.h>		// exit, malloc
#include <string.h>
#include <assert.h>
#include "stack.h"

void initStack(Stack *ps, int size, int eleSize)		// reset local var (only global var is resetted)
{
	ps->pArr = malloc(eleSize * size);
	assert(ps->pArr);	// in case not assigned any space, stop
	
	ps->eleSize = eleSize;
	ps->size = size;
	ps->tos = 0;
}

void cleanupStack(Stack *ps)
{
	free(ps->pArr);
}

void push(Stack *ps, const void *pData)
{
	assert(ps->tos != ps->size);
	
	//ps->pArr[ps->tos] = data;
	//memcpy(&ps->pArr[ps->tos], pData, ps->eleSize);	// ps->pArr[...] == *(ps->pArr + ...)
	memcpy( (unsigned char *)ps->pArr + ps->tos * ps->eleSize, pData, ps->eleSize);
	++ps->tos;
}

void pop(Stack *ps, void *pData)
{
	assert(ps->tos);
	--ps->tos;
	memcpy(pData, (unsigned char *)ps->pArr + ps->tos * ps->eleSize, ps->eleSize);
	//*pData = ps->pArr[ps->tos];
	//return ps->pArr[ps->tos];
}
