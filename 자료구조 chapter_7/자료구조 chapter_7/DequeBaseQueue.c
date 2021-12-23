#include<stdio.h>
#include"DequeBaseQueue.h"

void QueueInit(Queue* pq)
{
	DequeInit(pq);

}
int QisEmpty(Queue* pq)
{
	return DQisEmpty(pq);
}

void Enqueue(Queue* pq, Data data)
{
	DQAddLast(pq,data);
}


Data Dequeue(Queue* pq)
{
	return DQRemoveFirst(pq);

}


Data QPeek(Queue* pq)
{
	return DQGetFIrst(pq);
}