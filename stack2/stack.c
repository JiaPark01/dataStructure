#define STACK_SIZE 100

static int stack[STACK_SIZE];
static int tos = 0;				// top of stack
// static to only make the stack accessible in stack.c, not from main.c

void push(int data)
{
	stack[tos] = data;
	++tos;
}

int pop(void)
{
	--tos;
	return stack[tos];
}
