#include<stdio.h>
#include<stdlib.h>
#include"CircularQueue.h"

void QueueInit(Queue* pq)
{
	//�� �� ��� front�� rear�� ������ġ�� ����Ŵ
	pq->front = 0;
	pq->rear = 0;
}

int QisEmpty(Queue* pq)
{
	//Queue�� ����ٸ�
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
	//�迭�� ������ ����� �ε��� ���̶��
	if (pos == QUE_LEN - 1)
	{
		//�ε��� ���� 0���� �ʱ�ȭ
		return 0;;
	}
	else
	{
		return pos + 1;
	}
}

void Enqueue(Queue* pq, Data data)
{
	//Queue�� �� á�ٸ�
	if (NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	//rear ��ĭ �̵� �� ������ ����
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

	//front��ĭ �̵� ��  ����Ű�� ������ ��ȯ
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