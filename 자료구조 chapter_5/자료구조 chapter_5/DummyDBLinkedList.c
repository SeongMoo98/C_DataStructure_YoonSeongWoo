#include<stdio.h>
#include<stdlib.h>
#include"DummyDBLinkedList.h"


void ListInit(List* plist)
{
	//머리와 꼬리에 더미노드 , 더미노드끼리 서로 가리킴
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));
	
	//더미노드 NULL초기화
	plist->head->prev = NULL;
	plist->head->next = plist->tail;

	plist->tail->next = NULL;
	plist->tail->prev = plist->head;

	plist->numOfData = 0;
}

//꼬리에 추가하는 방식
void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->prev = plist->tail->prev; //=head
	plist->tail->prev->next = newNode; //=head->next
	
	newNode->next = plist->tail; 
	plist->tail->prev = newNode;


	
	(plist->numOfData)++;
}


int LFirst(List* plist, Data* pdata)
{
	if (plist->head->next== plist->tail)
	{
		return FALSE;
	}

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}


int LNext(List* plist, Data* pdata)
{
	if (plist->cur->next == plist->tail)
	{
		return FALSE;
	}

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LPrevious(List* plist, Data* pdata)
{
	if (plist->cur->prev== plist->head)
	{
		return FALSE;
	}

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return TRUE;
}


Data LRemove(List* plist)
{
	Node* rpos = plist->cur;
	Data rdata = rpos->data;

	//cur 앞 뒤 노드 연결
	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;

	//cur을 한칸 이동
	plist->cur = plist->cur->prev;

	
	free(rpos);
	(plist->numOfData)--;
	return rdata;
}


int LCount(List* plist)
{
	return plist->numOfData;
}

