#pragma once
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#include"Employee.h"

#define TRUE 1
#define FALSE 0

typedef Employee* Data;

typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

typedef struct _CLL
{
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
}CList;

typedef CList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data); //꼬리에 추가
void LInsertFront(List* plist, Data data); //머리에 추가

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);

Data LRemove(List* plist);
int LCount(List* plist);

#endif