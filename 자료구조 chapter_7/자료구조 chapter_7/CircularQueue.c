#include<stdio.h>
#include<stdlib.h>
#include"CircularQueue.h"

void QueueInit(Queue* pq)
{
	//텅 빈 경우 front와 rear은 같은위치를 가리킴
	pq->front = 0;
	pq->rear = 0;
}

int QisEmpty(Queue* pq)
{
	//Queue가 비었다면
	if (pq->front == pq->rear)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int NextPosIdx(int pos)
{
	//배열의 마지막 요소의 인덱스 값이라면
	if (pos == QUE_LEN - 1)
	{
		//인덱스 값을 0으로 초기화
		return 0;;
	}
	else
	{
		return pos + 1;
	}
}

void Enqueue(Queue* pq, Data data)
{
	//Queue가 꽉 찼다면
	if (NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	//rear 한칸 이동 후 데이터 저장
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}


Data Dequeue(Queue* pq)
{
	if (QisEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	//front한칸 이동 후  가리키는 데이터 반환
	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}


Data QPeek(Queue* pq)
{
	if (QisEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	return pq->queArr[NextPosIdx(pq->front)];
}