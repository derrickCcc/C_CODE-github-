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

void testSelectSort()
{
	int a[10] = { 7,3,5,2,6,9,1,8,4,0 };
	SelectSort(a, 10);
	PrintArray(a, 10);
}

void testHeapSort()
{
	int a[10] = { 7,3,5,2,6,9,1,8,4,0 };
	HeapSort(a, 10);
	PrintArray(a, 10);
}

void testBubbleSort()
{
	int a[10] = { 7,3,5,2,6,9,1,8,4,0 };
	BubbleSort(a, 10);
	PrintArray(a, 10);
}

void testQuickSort()
{
	int a[10] = { 7,3,5,2,6,9,1,8,4,0 };
	QuickSort(a, 0, 9);
	PrintArray(a, 10);
}

void testQuickSortNonR()
{
	int a[10] = { 7,3,5,2,6,9,1,8,4,0 };
	QuickSortNonR(a, 0, 9);
	PrintArray(a, 10);
}

void testMergeSort()
{
	int a[8] = { 10,6,7,1,3,9,4,2 };
	MergeSort(a, 8);
	PrintArray(a, 8);
}

void testMergeSortNonR()
{
	int a[10] = { 7,3,5,2,6,9,1,8,4,0 };
	MergeSortNonR(a, 10);
	PrintArray(a, 10);
}

int main()
{
	//testInsetSort();
	//printf("\n");
	//testShellSort();
	//printf("\n");
	//testSelectSort();
	//printf("\n");
	//testHeapSort();
	//testBubbleSort();
	//testQuickSort();
	//testQuickSortNonR();
	//testMergeSort();
	testMergeSortNonR();
	return 0;
}