#include<stdio.h>
#include"ArrayList.h"


//ADT(Abstract Data Type)
//List�� ���Ǹ� ���� ����� ���� ������ �� �־���Ѵ�


int main(void)
{
	//ArrayList�� ���� �� �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);


	//������ ���� - ������ ����, �ߺ��� �������� ������ ����Ѵ�
	LInsert(&list, 11);	LInsert(&list, 11);
	LInsert(&list, 22);	LInsert(&list, 22);
	LInsert(&list, 33);


	//����� �������� ���� ���
	printf("���� �������� �� : %d \n", LCount(&list));

	//������ ��ȸ
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
	printf("\n\n");

	//������ ����- ó������ �ٽ� Ž���ؾ���
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