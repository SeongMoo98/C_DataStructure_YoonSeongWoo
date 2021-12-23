#include<stdio.h>
#include<stdlib.h>
#include"DBLinkedList.h"


void ListInit(List* plist)
{
	plist->head = NULL;
	plist->numOfData = 0;
}


void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	//내가 구현한 코드
	 
	////첫 번째 노드
	//if (plist->head == NULL)
	//{
	//	//첫 번째 이후 노드 추가에서와 똑같은 코드가 된다
	//	//=>plist->head로 초기화하는 것도 좋은 방법이다
	//	//처음에는 plist->head 는 NULL이다
	//	// 
	//	//newNode->next = NULL;
	//	newNode->next = plist->head;
	//	newNode->prev = NULL;
	//	plist->head = newNode;
	//}
	////첫 번쨰 이후
	//else
	//{
	//	newNode->prev = NULL;
	//	newNode->next = plist->head;
	//	plist->head->prev = newNode;
	//}


	//책의 코드
	newNode->next =plist->head;
	if (plist->head != NULL)
	{
		plist->head->prev = newNode;
	}

	newNode->prev = NULL;
	plist->head = newNode;
	(plist->numOfData)++;
}
 

int LFirst(List* plist, Data* pdata)
{
	if (plist->head == NULL)
	{
		return FALSE;
	}

	plist->cur = plist->head;

	*pdata = plist->cur->data;
	return TRUE;
}


int LNext(List* plist, Data* pdata)
{
	if (plist->cur->next == NULL)
	{
		return FALSE;
	}

	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LPrevious(List* plist, Data* pdata)
{
	if (plist->cur->prev== NULL)
	{
		return FALSE;
	}

	plist->cur = plist->cur->prev;

	*pdata = plist->cur->data;
	return TRUE;
}

//
//Data LRemove(List* plist)
//{
//	Node* rpos = plist->cur;
//	Data rdata = rpos->data;
//
//	if (rpos == plist->tail)
//	{
//		if (plist->tail == plist->tail->next)
//		{
//			plist->tail = NULL;
//		}
//		else
//		{
//			plist->tail = plist->before;
//		}
//	}
//	plist->before->next = plist->cur->next;
//	plist->cur = plist->before;
//
//	free(rpos);
//	(plist->numOfData)--;
//	return rdata;
//}


int LCount(List* plist)
{
	return plist->numOfData;
}

