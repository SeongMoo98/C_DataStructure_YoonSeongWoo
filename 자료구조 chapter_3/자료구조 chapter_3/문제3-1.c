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
	printf("���� �������� �� : %d \n", LCount(&list));


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
	printf("�����͵��� �� : %d", sum);
	printf("\n\n");

	//���� �Ѱ�
	//2�� ��� ����
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
	//3�� ��� ����
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

	////���� - 1���� Ž���� ������ �������� 2, 3�� ����� ã�Ƴ�
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

	//���� �� ������ ������ ��ü ���
	printf("���� �������� �� : %d \n", LCount(&list));

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