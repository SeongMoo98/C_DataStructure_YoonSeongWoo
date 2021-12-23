#include<stdio.h>
#include"ArrayList.h"


//ADT(Abstract Data Type)
//List의 정의를 몰라도 기능을 통해 이해할 수 있어야한다


int main(void)
{
	//ArrayList의 생성 및 초기화
	List list;
	int data;
	ListInit(&list);


	//데이터 저장 - 나란히 저장, 중복된 데이터의 저장을 허용한다
	LInsert(&list, 11);	LInsert(&list, 11);
	LInsert(&list, 22);	LInsert(&list, 22);
	LInsert(&list, 33);


	//저장된 데이터의 갯수 출력
	printf("현재 데이터의 수 : %d \n", LCount(&list));

	//데이터 조회
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
	printf("\n\n");

	//데이터 삭제- 처음부터 다시 탐색해야함
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

	//삭제 후 나머지 데이터 전체 출력
	printf("현재 데이터의 수 : %d \n", LCount(&list));

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