#include<stdio.h>
#include"Deque.h"


int main(void)
{
	//Deque의 생성 및 초기화
	Deque deq;
	DequeInit(&deq);


	//데이터 넣기
	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);

	//데이터 꺼내기
	while (!DQisEmpty(&deq))
	{
		printf("%d ", DQRemoveFirst(&deq));
	}

	printf("\n\n");

	//데이터 넣기 2차
	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);


	//데이터 꺼내기 2차
	while (!DQisEmpty(&deq))
	{
		printf("%d ", DQRemoveLast(&deq));
	}




	return 0;
}