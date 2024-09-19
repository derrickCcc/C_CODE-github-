#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"

void testInsetSort()
{
	int a[10] = { 7,3,5,2,6,9,1,8,4,0 };
	InsertSort(a, 10);
	PrintArray(a, 10);
}

void testShellSort()
{
	int a[10] = { 7,3,5,2,6,9,1,8,4,0 };
	ShellSort(a, 10);
	PrintArray(a, 10);
}

int main()
{
	testInsetSort();
	printf("\n");
	testShellSort();
	return 0;
}