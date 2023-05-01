#include <assert.h>
#include "queue.h"

void initQueue(Queue *pq)
{
	pq->front = 0;
	pq->rear = 0;
}

void push(Queue *pq, int data)
{	
	assert(pq->rear != QUEUE_SIZE);
	pq->array[pq->rear] = data;
	++pq->rear;
}

int pop(Queue *pq)
{
	assert(pq->front != pq->rear);
	int i = pq->front;
	++pq->front;
	return pq->array[i];
	
	// or simply... return pq->array[pq->front++];
}
