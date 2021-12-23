#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
#include"Point.h"
#include"NameCard.h"

//참 거짓을 표현하기 위한 매크로 정의
#define TRUE 1
#define FALSE 0

#define LIST_LEN 100

//다양한 데이터의 자료형으로 바꿀수있다
typedef NameCard* LData;

typedef struct __ArrayList
{
	LData arr[LIST_LEN]; //리스트의 저장소인 배열
	int numOfData;		 //저장된 데이터의 수
	int curPosition;	 //데이터의 참조위치 기록
}ArrayList;

typedef ArrayList List;

//초기화와 데이터 저장
void ListInit(List* plist);
void LInsert(List* plist, LData data);

//데이터 참조
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

//데이터 삭제
LData LRemove(List* plist);
int LCount(List* plist);
#endif