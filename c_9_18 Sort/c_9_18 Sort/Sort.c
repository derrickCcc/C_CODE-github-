#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include "Stack.h"

//升序
//打印数组
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

//交换
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 插入排序
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

// 希尔排序
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

// 选择排序
void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int maxi = left;
		int mini = left;
		for (int i = left; i <= right; i++)
		{
			if (a[i] > a[maxi])
				maxi = i;
			if (a[i] < a[mini])
				mini = i;
		}

		Swap(&a[left], &a[mini]);
		if(maxi == left)
			maxi = mini;
		Swap(&a[right], &a[maxi]);

		left++;
		right--;
	}
}

// 堆排序
void AdjustUp(int* a, int n, int child)
{
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

void AdjustDwon(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child] < a[child + 1] && child+1 < n)
			child++;

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
void HeapSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
		AdjustUp(a, n, i);

	int end = n - 1;
	while (end)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
				Swap(&a[j], &a[j + 1]);
		}
	}
}

// 快速排序递归实现
// 快速排序hoare版本

//取中间值
int GetMinIndex(int* a, int left, int right)
{
	int midi = (left + right) / 2;
	if (a[left] > a[midi])
	{
		if (a[midi] > a[right])
			return midi;
		else if (a[right] > a[left])
			return left;
		else
			return right;
	}
	else
	{
		if (a[right] > a[midi])
			return midi;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
}

int PartSort1(int* a, int left, int right)
{
	////随机取数(下标)
	//int randi = left + (rand() % (right - left));
	//Swap(&a[randi], &a[left]);

	//三数取中
	int midi = GetMinIndex(a, left, right);
	Swap(&a[left], &a[midi]);

	int keyi = left;
	while (left < right)
	{
		while (a[right] >= a[keyi] && left < right)
			right--;

		while (a[left] <= a[keyi] && left < right)
			left++;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	keyi = left;

	return keyi;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	//三数取中
	int midi = GetMinIndex(a, left, right);
	Swap(&a[left], &a[midi]);

	int key = a[left];
	int keyi = left;
	while (left < right)
	{
		while (a[right] >= key && left < right)
			right--;
		a[left] = a[right];

		while (a[left] <= key && left < right)
			left++;
		a[right] = a[left];
	}
	a[left] = key;
	keyi = left;
	return keyi;
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	//三数取中
	int midi = GetMinIndex(a, left, right);
	Swap(&a[left], &a[midi]);

	int keyi = left;
	int prev = keyi;
	int cur = prev + 1;
	while (cur <= right)
	{
		//if (a[cur] < a[keyi] && ++prev != cur)
		//	Swap(&a[cur], &a[prev]);
		//++cur;

		if (a[cur] < a[keyi])
		{
			++prev;
			Swap(&a[cur], &a[prev]);
			++cur;
		}
		else
			++cur;
	}
	Swap(&a[prev], &a[keyi]);
	keyi = prev;

	return keyi;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int keyi = PartSort1(a, left, right);
	//int keyi = PartSort2(a, left, right);
	//int keyi = PartSort3(a, left, right);

	QuickSort(a, left, keyi - 1);
	QuickSort(a, left + 1, right);
}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, left);
	STPush(&st, right);
	while (!STEmpty(&st))
	{
		int end = STTop(&st);
		STPop(&st);
		int begin = STTop(&st);
		STPop(&st);

		int keyi = PartSort1(a, begin, end);
		//int keyi = PartSort2(a, begin, end);
		//int keyi = PartSort3(a, begin, end);
		if (keyi + 1 < end)
		{
			STPush(&st, keyi + 1);
			STPush(&st, end);
		}
		if (keyi - 1 > begin)
		{
			STPush(&st, begin);
			STPush(&st, keyi - 1);
		}
	}

	STDestroy(&st);
}
