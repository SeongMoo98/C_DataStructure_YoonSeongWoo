#include<stdio.h>

void HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)
	{
		printf("원반1을 %c에서 %c로 이동\n", from, to);
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by); // 작은원반 n-1개를 A에서 B로 이동
		printf("원반%d을(를) %c에서 %c로 이동\n", num, from, to); //큰원반 한개를 A에서 C로 이동
		HanoiTowerMove(num - 1, by, from, to); //작은원반 n-1개를 B에서 C로 이동
	}
}




int main(void)
{
	//막대A의 원반 3개를 막대B를 이용하여 막대C로 옮기기
	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}