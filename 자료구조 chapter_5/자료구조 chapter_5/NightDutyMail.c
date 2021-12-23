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

	//������ ������ ���α׷��� ��ϼ����� �������� �Ѵ�
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

	////������ �Լ� ������ malloc�� ���� �����ϸ� �ȵǳ�??
	//pemp = addEmp(11111, "Terry");
	//LInsertFront(&list, pemp);

	//pemp = addEmp(2222, "Jerry");
	//LInsertFront(&list, pemp);

	//pemp = addEmp(3333, "Hary");
	//LInsertFront(&list, pemp);

	//pemp = addEmp(4444, "Sunny");
	//LInsertFront(&list, pemp);



	//Terry�ڷ� 3�� �� �����ڴ�??
	pemp = WhoIsNightDuty(&list, 3, "Terry");
	ShowEmployeeInfo(pemp);


	//Sunny�ڷ� 15�� �� �����ڴ�??
	pemp = WhoIsNightDuty(&list, 15, "Sunny");
	ShowEmployeeInfo(pemp);



	//�Ҵ�� �޸��� ��ü �Ҹ�
	//
	//if (LFirst(&list, &pemp))
	//{
	//	printf("��� : %d  �̸� : &s\n", pemp->empNum, pemp->name);
	//	LRemove(&list);
	//	while (LNext(&list, &pemp))
	//	{
	//		printf("��� : %d  �̸� : &s\n", pemp->empNum, pemp->name);
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
//	//�Լ������� malloc�Լ� ���
//	// 
//	//������ malloc�� �Ἥ �޸𸮸� �Ҵ��߱� ������ ������ ����� �Ѵٴ� ���̴�.
//	//�׷��� return ���� ������ �Լ��� ����ǹǷ� free ������ return �� ���� ���� ���;� �ϴµ�,
//	//��ȯ�ϱ� ���� ��ȯ�ؾ� �� ���� �޸𸮸� �����ع����� �ⲯ ������ ���� ������������ �ȴ�.
//	//���⼭ �ٽ� C������ �޸� ���� ��Ģ�� ���캸��.
//
//	//1.malloc(calloc ����)�� free�� ¦�� �¾ƾ� �Ѵ�.
//	//2.�޸𸮸� �Ҵ��� ������ ���������� ������ å���� ����.�� �Լ������� �Ҵ��ߴٸ� ������ å�ӵ� �Լ��� ����.
//	//3.2�� ��ƴٸ� �Լ��� ȣ���� �ʿ��� å������ free �ؾ� �Ѵ�.
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
	
	//�̸�ã��
	LFirst(plist, &ret);
	if (strcmp(ret->name, name)!=0)
	{
		//�ѹ��� ��ȸ
		for (i = 0; i < num - 1; i++)
		{
			LNext(plist,&ret);

			if (strcmp(ret->name, name)==0)
			{
				break;
			}
		}
		//�ش��ϴ� �̸��� �������� ������
		if (i >= num - 1)
		{
			return NULL;
		}
	}

	//�� �ڷ� ��ĥ��
	for(i=0; i<day;i++)
	{
		LNext(plist, &ret);
	}
	return ret;
}

void ShowEmployeeInfo(Employee* emp)
{
	printf("��� : %d  �̸� : %s\n", emp->empNum, emp->name);
}
