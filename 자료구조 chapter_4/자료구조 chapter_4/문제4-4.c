#include<stdio.h>
#include<stdlib.h>
#include"Point.h"
#include"LinkedList.h"

int WhoisPrecede(LData d1, LData d2)
{
	if (d1->xpos < d2->xpos)
	{
		//d1이 정렬 순서상 앞선다
		return 0;
	}
	else if (d1->xpos == d2->xpos)
	{
		if (d1->ypos < d2->ypos)
		{
			return 0;
		}
		else
		{
			return 1;
		}

	}
	else
	{
		//d2가 정렬 순서상 앞서거나 같다
		return 1;
	}
}

int main(void)
{
	List list;
	Point compPos;
	Point* ppos;
	ListInit(&list);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	//저장된 데이터의 출력
	printf("현재 데이터의 수 : %d \n", LCount(&list));
	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
		{
			ShowPointPos(ppos);
		}
		printf("\n");
	}

	//데이터 삭제
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);
		}
		while (LNext(&list, &ppos))
		{
			if (PointComp(ppos, &compPos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	//삭제 후 출력
	printf("현재 데이터의 수 : %d \n", LCount(&list));
	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
		{
			ShowPointPos(ppos);
		}
		printf("\n");
	}



	return 0;
}