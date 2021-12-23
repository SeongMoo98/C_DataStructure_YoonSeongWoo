#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
#include"Point.h"
#include"NameCard.h"

//�� ������ ǥ���ϱ� ���� ��ũ�� ����
#define TRUE 1
#define FALSE 0

#define LIST_LEN 100

//�پ��� �������� �ڷ������� �ٲܼ��ִ�
typedef NameCard* LData;

typedef struct __ArrayList
{
	LData arr[LIST_LEN]; //����Ʈ�� ������� �迭
	int numOfData;		 //����� �������� ��
	int curPosition;	 //�������� ������ġ ���
}ArrayList;

typedef ArrayList List;

//�ʱ�ȭ�� ������ ����
void ListInit(List* plist);
void LInsert(List* plist, LData data);

//������ ����
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

//������ ����
LData LRemove(List* plist);
int LCount(List* plist);
#endif