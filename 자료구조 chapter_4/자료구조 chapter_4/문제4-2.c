#include<stdio.h>
#include<stdlib.h>

//LinkedRead
typedef struct _node
{
	int data;
	struct _node* next;
}Node;

int main(void)
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;

	//���̳�� �߰� - ���̳�忡�� ��ȿ�� �����͸� �������� �ʴ´�
	head = (Node*)malloc(sizeof(Node));
	tail = head;

	int readData;

	//������ �Է¹ޱ�
	while (1)
	{
		printf("�ڿ��� �Է� : ");
		scanf_s("%d", &readData);
		if (readData < 1)
		{
			break;
		}
		//��� �߰�
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;
		
		//����Ʈ�� ���� ��带 �߰�
		tail->next = newNode;
		tail = newNode;
	}

	//������ ���
	printf("�Է� ���� �������� ��ü ���!\n");
	if (head == tail)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�!\n");
	}
	else
	{
		cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d\n", cur->data);
		}
	}
	printf("\n\n");

	//�޸�����
	if (head == tail)
	{
		return 0;
	}
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d�� �����մϴ�.\n", delNode->data);
			free(delNode);
		}
	}



	return 0;
}
