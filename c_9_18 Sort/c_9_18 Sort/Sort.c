#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"

//ÉýÐò
//´òÓ¡Êý×é
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

// ²åÈëÅÅÐò
void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;

	}
}

// Ï£¶ûÅÅÐò
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		//gap /= 2;
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}


