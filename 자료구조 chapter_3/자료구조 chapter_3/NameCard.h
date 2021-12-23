#pragma once
#ifndef __NAME_CARD_H_
#define __NAME_CARD_H_

#define NAME_LEN 30
#define PHONE_LEN 30


typedef struct __namecard
{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
}NameCard;

//����ü ���� �����Ҵ� �� �ʱ�ȭ �� �ּҰ� ��ȯ
NameCard* MakeNameCard(char* name, char* phone);

//����ü ������ ���� ���
void ShowNameCardInfo(NameCard* pcard);

//�̸��� ������ 0, �ٸ��� 1��ȯ
int NameCompare(NameCard* pcard, char* name);

//��ȭ��ȣ ������ ����
void ChangePhoneNum(NameCard* pcard, char* phone);


#endif
