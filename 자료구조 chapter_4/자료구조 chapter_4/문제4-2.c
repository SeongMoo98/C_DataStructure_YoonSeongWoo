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

	//더미노드 추가 - 더미노드에는 유효한 데이터를 저장하지 않는다
	head = (Node*)malloc(sizeof(Node));
	tail = head;

	int readData;

	//데이터 입력받기
	while (1)
	{
		printf("자연수 입력 : ");
		scanf_s("%d", &readData);
		if (readData < 1)
		{
			break;
		}
		//노드 추가
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;
		
		//리스트의 끝에 노드를 추가
		tail->next = newNode;
		tail = newNode;
	}

	//데이터 출력
	printf("입력 받은 데이터의 전체 출력!\n");
	if (head == tail)
	{
		printf("저장된 자연수가 존재하지 않습니다!\n");
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

	//메모리해제
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

			printf("%d를 삭제합니다.\n", delNode->data);
			free(delNode);
		}
	}



	return 0;
}
