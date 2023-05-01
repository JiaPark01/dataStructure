#ifndef QUEUE_H
#define QUEUE_H
#define QUEUE_SIZE 100

typedef struct queue {
	int array[QUEUE_SIZE];
	int front;
	int rear;
} Queue;

void initQueue(Queue *pq);
void push(Queue *pq, int data);
int pop(Queue *pq);

#endif
