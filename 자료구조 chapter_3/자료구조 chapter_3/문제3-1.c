#include<stdio.h>
#include"ArrayList.h"
#include<stdio.h>
#include"ArrayList.h"



int main(void)
{
	List list;
	int data,sum=0;
	ListInit(&list);

	for (int i = 1; i < 10; i++)
	{
		LInsert(&list, i);
	}
	printf("현재 데이터의 수 : %d \n", LCount(&list));


	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		sum += data;
		while (LNext(&list, &data))
		{
			printf("%d ", data);
			sum += data;
		}
	}
	printf("\n\n");
	printf("데이터들의 합 : %d", sum);
	printf("\n\n");

	//내가 한거
	//2의 배수 삭제
	if (LFirst(&list, &data))
	{
		for (int i = 1; i < 5; i++)
		{
			if (data == 2*i)
			{
				LRemove(&list);
			}
		}
		while (LNext(&list, &data))
		{
			for (int i = 1; i < 5; i++)
			{
				if (data == 2 * i)
				{
					LRemove(&list);
				}
			}
		}
	}
	//3의 배수 삭제
	if (LFirst(&list, &data))
	{
		for (int i = 1; i <4; i++)
		{
			if (data == 2 * i)
			{
				LRemove(&list);
			}
		}
		while (LNext(&list, &data))
		{
			for (int i = 1; i < 4; i++)
			{
				if (data == 3 * i)
				{
					LRemove(&list);
				}
			}
		}
	}

	////답지 - 1번에 탐색에 나머지 연산으로 2, 3의 배수를 찾아냄
	//if (LFirst(&list, &data))
	//{
	//	if (data % 2 == 0 || data % 3 == 0)
	//	{
	//		LRemove(&list);
	//	}
	//	while (LNext(&list, &data))
	//	{
	//		if (data % 2 == 0 || data % 3 == 0)
	//		{
	//			LRemove(&list);
	//		}
	//	}
	//}

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