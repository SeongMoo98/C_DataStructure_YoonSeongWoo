#include<stdio.h>

int BinarySearch(int arr[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (target == arr[mid])
		{
			return mid;
		}
		else
		{
			if (target < arr[mid])
			{
				last = mid - 1;
			}
			else
			{
				first = mid + 1;
			}
		}
	}

	return -1;	// Ž���� �������� ��
}


int main(void)
{
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = BinarySearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
	{
		printf("Ž�� ����\n");
	}
	else
	{
		printf("Ÿ�� ���� �ε��� : %d \n", idx);
	}


	idx = BinarySearch(arr, sizeof(arr), sizeof(int), 4);
	if (idx == -1)
	{
		printf("Ž�� ����\n");
	}
	else
	{
		printf("Ÿ�� ���� �ε��� : %d \n", idx);
	}
	return 0;

}