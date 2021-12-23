#include<stdio.h>
#include<stdlib.h> // - malloc�Լ��� ���� stdlib
#include<string.h>
#include"NameCard.h"



//����ü ���� �����Ҵ� �� �ʱ�ȭ �� �ּҰ� ��ȯ
NameCard* MakeNameCard(const char* name, const char* phone)
{
	NameCard* NewNameCard;
	NewNameCard = (NameCard*)malloc(sizeof(NameCard));
	strcpy_s(NewNameCard->name, NAME_LEN ,name);
	strcpy_s(NewNameCard->phone, PHONE_LEN ,phone);
	return NewNameCard;
}

//����ü ������ ���� ���
void ShowNameCardInfo(NameCard* pcard)
{
	printf("[ �̸� ] : %s\n", pcard->name);
	printf("[ ��ȭ��ȣ ] : %s\n", pcard->phone);
}

//�̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
int NameCompare(NameCard* pcard, char* name)
{
	return strcmp(pcard->name, name);
		
}


//��ȭ��ȣ ������ ����
void ChangePhoneNum(NameCard* pcard, const char* phone)
{
	strcpy_s(pcard->phone, PHONE_LEN, phone);
}
