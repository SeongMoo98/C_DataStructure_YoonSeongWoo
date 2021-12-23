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

	//���� ������ �ڵ�
	 
	////ù ��° ���
	//if (plist->head == NULL)
	//{
	//	//ù ��° ���� ��� �߰������� �Ȱ��� �ڵ尡 �ȴ�
	//	//=>plist->head�� �ʱ�ȭ�ϴ� �͵� ���� ����̴�
	//	//ó������ plist->head �� NULL�̴�
	//	// 
	//	//newNode->next = NULL;
	//	newNode->next = plist->head;
	//	newNode->prev = NULL;
	//	plist->head = newNode;
	//}
	////ù ���� ����
	//else
	//{
	//	newNode->prev = NULL;
	//	newNode->next = plist->head;
	//	plist->head->prev = newNode;
	//}


	//å�� �ڵ�
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

