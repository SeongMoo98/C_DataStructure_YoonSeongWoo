#include<stdio.h>
#include"DBLinkedList.h"


int main(void)
{
	//����� ���� ����Ʈ�� ���� �� �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);

	//8���� ������ ����
	for (int i = 1; i <= 8; i++)
	{
		LInsert(&list, i);
	}
	
	//����� �������� ��ȸ
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		//������ ���� �̵��ϸ� ������ ��ȸ
		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
		printf("\n\n");
		//���� ���� �̵��ϸ� ������ ��ȸ
		while (LPrevious(&list, &data))
		{
			printf("%d ", data);
		}
		printf("\n\n");
	}

	return 0;
}