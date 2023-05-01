#define QUEUE_SIZE 100

int queue[QUEUE_SIZE];
int front;
int rear;

void push(int data)
{	
	queue[rear] = data;
	++rear;
}

int pop(void)
{
	int i = front;
	++front;
	return queue[i];
	
	// or simply... return queue[front++];
}
