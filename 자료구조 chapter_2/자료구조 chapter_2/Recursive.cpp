#include<iostream>
using namespace std;

//ÆÑÅä¸®¾ó
int Factorial(int num)
{
	if (num == 0)
	{
		return 1;
	}
	else if(num >=1)
	{
		return num * Factorial(num-1);
	}
}

//ÇÇº¸³ªÄ¡ ¼ö¿­
int Fibo(int N)
{
	if (N == 1)
	{
		return 0;
	}
	else if (N == 2)
	{
		return 1;
	}
	else
	{
		return Fibo(N - 1) + Fibo(N - 2);
	}
}

//ÀÌÁøÅ½»ö Àç±ÍÇÔ¼ö
int BSearchRecur(int arr[], int first, int last, int target)
{
	if (first > last)
	{
		return -1;
	}
	int mid = (first + last) / 2;

	if (target == arr[mid])
	{
		return mid;
	}
	else if (target > arr[mid])
	{
		first = mid + 1;
		BSearchRecur(arr, first, last, target);
	}
	else if (target < arr[mid])
	{
		last = mid -1;
		BSearchRecur(arr, first, last, target);
	}
}


int main(void)
{
	////ÆÑÅä¸®¾ó
	//printf("1! = %d \n", Factorial(1));
	//printf("3! = %d \n", Factorial(3));
	//printf("4! = %d \n", Factorial(4));
	//printf("9! = %d \n", Factorial(9));


	////ÇÇº¸³ªÄ¡¼ö¿­
	//for (int i= 1; i < 15; i++)
	//{
	//	printf("%d ", Fibo(i));
	//}


	////ÀÌÁøÅ½»ö Àç±ÍÇÔ¼ö
	//int arr[] = { 1,3,5,7,9,11,13,15 };
	//int idx;

	//idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) , 7);
	//if (idx == -1)
	//{
	//	cout << "Å½»ö ½ÇÆÐ\n";
	//}
	//else
	//{
	//	printf("Å¸°Ù ÀúÀå ÀÎµ¦½º : %d\n", idx);
	//}

	//idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) , 4);
	//if (idx == -1)
	//{
	//	cout << "Å½»ö ½ÇÆÐ\n";
	//}
	//else
	//{
	//	printf("Å¸°Ù ÀúÀå ÀÎµ¦½º : %d\n", idx);
	//}



	return 0;
}