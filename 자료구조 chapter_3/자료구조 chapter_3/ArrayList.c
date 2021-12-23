#include<stdio.h>
#include"ArrayList.h"

//초기화와 데이터 저장
void ListInit(List* plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}
void LInsert(List* plist, LData data)
{
	if ((plist->numOfData) >= LIST_LEN)
	{
		puts("저장이 불가능합니다");
		return;
	}
	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

//데이터 참조
int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)
	{
		return FALSE;
	}
	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}
int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numOfData)-1)
	{
		return FALSE;
	}
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

//데이터 삭제
LData LRemove(List* plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	LData rdata = plist->arr[rpos];

	for (int i = rpos; i < num - 1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];
	}

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}
int LCount(List* plist)
{
	return plist->numOfData;
}
