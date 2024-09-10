#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

void Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void AdjustUp(int* a, int child)
{
	assert(a);

	int parent = (child - 1) / 2;
	while (parent >= 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void AdjustDown(int* a, int parent,int n)
{
	assert(a);
	
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child] < a[child + 1] && child+1 < n)
			++child;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

//升序
void HeapSort(int* a, int n)
{
	assert(a);

	//建堆  向上调整
	for (int i = 1; i < n; i++)
		AdjustUp(a, i);

	//排升序  向下调整
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDown(a, 0, end);
		end--;
	}
}

int main()
{
	int a[10] = { 12,97,53,6,76,3,46,78,54,8 };
	//for (int i = 1; i < 10; i++)
	//	AdjustUp(a, i);
	HeapSort(a, 10);
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	return 0;
}