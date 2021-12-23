#pragma once
#ifndef __LB_QUEUR_H__
#define __LB_QUEUR_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

typedef struct _lQueue
{
	Node* front;
	Node* rear;
}LQueue;

typedef LQueue Queue;

void QueueInit(Queue* pq);
int QisEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);




#endif