#include<stdio.h>
#include<stdlib.h>
#include"DLinkedList.h"


int main(void)
{
	//List 생성 및 초기화
	List list;
	int data;
	ListInit(&list);

	//데이터 저장
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	//저장된 데이터의 출력
	printf("현재 데이터의 수 : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list,&data))
		{
			printf("%d ", data);
		}
	}
	printf("\n\n");

	//데이터 22 의 삭제
	if (LFirst(&list, &data))
	{
		if (data == 22)
		{
			LRemove(&list);	
		}
		while (LNext(&list, &data))
		{
			if (data == 22)
			{
				LRemove(&list);
			}
		}
	}

	//삭제 후 남아있는 데이터 전체출력
	printf("현재 데이터의 수 : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
	printf("\n\n");


	return 0;
}