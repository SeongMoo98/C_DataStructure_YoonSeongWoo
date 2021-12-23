#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkedList.h"
#include"Employee.h"

//Employee* addEmp(int empNum, const char* name);
Employee* WhoIsNightDuty(List* plist, int day, const char* name);
void ShowEmployeeInfo(Employee* emp);

int main(void)
{
	List list;
	Employee* pemp;
	ListInit(&list);

	//당직의 순서는 프로그램에 등록순서를 기준으로 한다
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 11111;
	strcpy_s(pemp->name, MAX_LEN, "Terry");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 2222;
	strcpy_s(pemp->name, MAX_LEN, "Jery");
	LInsert(&list, pemp);


	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 3333;
	strcpy_s(pemp->name, MAX_LEN, "Hary");
	LInsert(&list, pemp);


	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 4444;
	strcpy_s(pemp->name, MAX_LEN, "Sunny");
	LInsert(&list, pemp);

	////정의한 함수 내에서 malloc을 쓰고 리턴하면 안되나??
	//pemp = addEmp(11111, "Terry");
	//LInsertFront(&list, pemp);

	//pemp = addEmp(2222, "Jerry");
	//LInsertFront(&list, pemp);

	//pemp = addEmp(3333, "Hary");
	//LInsertFront(&list, pemp);

	//pemp = addEmp(4444, "Sunny");
	//LInsertFront(&list, pemp);



	//Terry뒤로 3일 뒤 당직자는??
	pemp = WhoIsNightDuty(&list, 3, "Terry");
	ShowEmployeeInfo(pemp);


	//Sunny뒤로 15일 뒤 당직자는??
	pemp = WhoIsNightDuty(&list, 15, "Sunny");
	ShowEmployeeInfo(pemp);



	//할당된 메모리의 전체 소멸
	//
	//if (LFirst(&list, &pemp))
	//{
	//	printf("사번 : %d  이름 : &s\n", pemp->empNum, pemp->name);
	//	LRemove(&list);
	//	while (LNext(&list, &pemp))
	//	{
	//		printf("사번 : %d  이름 : &s\n", pemp->empNum, pemp->name);
	//		LRemove(&list);
	//	}
	//	
	//}

	if (LFirst(&list, &pemp))
	{
		free(pemp);
		for (int i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list,&pemp))
			{
				free(pemp);
			}
		}
	}



	return 0;
}

//Employee* addEmp(int empNum, const char* name)
//{
//	//함수내에서 malloc함수 사용
//	// 
//	//문제는 malloc을 써서 메모리를 할당했기 때문에 해제를 해줘야 한다는 점이다.
//	//그런데 return 문을 만나면 함수가 종료되므로 free 구문은 return 문 보다 먼저 나와야 하는데,
//	//반환하기 전에 반환해야 할 값의 메모리를 해제해버리면 기껏 만들어둔 값이 망가져버리게 된다.
//	//여기서 다시 C에서의 메모리 관리 원칙을 살펴보자.
//
//	//1.malloc(calloc 포함)과 free는 짝이 맞아야 한다.
//	//2.메모리를 할당한 측에서 일차적으로 해제의 책임을 진다.즉 함수내에서 할당했다면 해제의 책임도 함수가 진다.
//	//3.2가 어렵다면 함수를 호출한 쪽에서 책임지고 free 해야 한다.
//	Employee* emp = (Employee*)malloc(sizeof(Employee));
//	emp->empNum = empNum;
//	strcpy_s(emp->name, MAX_LEN, name);
//	return emp;
//}


Employee* WhoIsNightDuty(List* plist, int day, const char* name)
{
	int i, num;
	Employee* ret;
	num = LCount(plist);
	
	//이름찾기
	LFirst(plist, &ret);
	if (strcmp(ret->name, name)!=0)
	{
		//한바퀴 순회
		for (i = 0; i < num - 1; i++)
		{
			LNext(plist,&ret);

			if (strcmp(ret->name, name)==0)
			{
				break;
			}
		}
		//해당하는 이름이 존재하지 않으면
		if (i >= num - 1)
		{
			return NULL;
		}
	}

	//그 뒤로 며칠뒤
	for(i=0; i<day;i++)
	{
		LNext(plist, &ret);
	}
	return ret;
}

void ShowEmployeeInfo(Employee* emp)
{
	printf("사번 : %d  이름 : %s\n", emp->empNum, emp->name);
}
