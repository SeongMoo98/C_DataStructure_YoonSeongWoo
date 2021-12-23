#include<stdio.h>
#include"CircularQueue.h"


int main(void)
{

	//Queue 생성 및 초기화
	Queue q;
	QueueInit(&q);

	//Queue에 데이터 넣기
	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);
	Enqueue(&q, 5);

	//데이터 꺼내기
	while (!QisEmpty(&q))
	{
		printf("%d ", Dequeue(&q));
	}



	return 0;
}