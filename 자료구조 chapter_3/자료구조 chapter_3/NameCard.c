#include<stdio.h>
#include<stdlib.h> // - malloc함수를 위한 stdlib
#include<string.h>
#include"NameCard.h"



//구조체 변수 동적할당 및 초기화 후 주소값 반환
NameCard* MakeNameCard(const char* name, const char* phone)
{
	NameCard* NewNameCard;
	NewNameCard = (NameCard*)malloc(sizeof(NameCard));
	strcpy_s(NewNameCard->name, NAME_LEN ,name);
	strcpy_s(NewNameCard->phone, PHONE_LEN ,phone);
	return NewNameCard;
}

//구조체 변수의 정보 출력
void ShowNameCardInfo(NameCard* pcard)
{
	printf("[ 이름 ] : %s\n", pcard->name);
	printf("[ 전화번호 ] : %s\n", pcard->phone);
}

//이름이 같으면 0, 다르면 0이 아닌 값 반환
int NameCompare(NameCard* pcard, char* name)
{
	return strcmp(pcard->name, name);
		
}


//전화번호 정보를 변경
void ChangePhoneNum(NameCard* pcard, const char* phone)
{
	strcpy_s(pcard->phone, PHONE_LEN, phone);
}
