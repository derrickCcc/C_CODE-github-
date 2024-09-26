#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include "Stack.h"

//����
//��ӡ����
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

//����
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// ��������
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

// ϣ������
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

// ѡ������
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

// ������
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

// ð������
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

// ��������ݹ�ʵ��
// ��������hoare�汾

//ȡ�м�ֵ
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
	////���ȡ��(�±�)
	//int randi = left + (rand() % (right - left));
	//Swap(&a[randi], &a[left]);

	//����ȡ��
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
// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	//����ȡ��
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
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	//����ȡ��
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

// �������� �ǵݹ�ʵ��
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

// �鲢����ݹ�ʵ��
void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
		return;

	int midi = (begin + end) / 2;
	_MergeSort(a, tmp, begin, midi);
	_MergeSort(a, tmp, midi + 1, end);

	int begin1 = begin, end1 = midi;
	int begin2 = midi + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];

	while (begin2 <= end2)
		tmp[i++] = a[begin2++];

	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));

}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail!\n");
		exit(-1);
	}

	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
}
// �鲢����ǵݹ�ʵ��
//version one
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail!\n");
		exit(-1);
	}

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int j = i;
			if (end1 >= n)
			{
				end1 = n - 1;
				begin2 = n;
				end2 = n - 1;
			}
			if (end1 < n && begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}
			if (begin2 < n && end2 >= n)
				end2 = n - 1;

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
					tmp[j++] = a[begin1++];

				else
					tmp[j++] = a[begin2++];
			}
			while (begin1 <= end1)
				tmp[j++] = a[begin1++];

			while (begin2 <= end2)
				tmp[j++] = a[begin2++];
		}

		memcpy(a, tmp, sizeof(int) * n);
		gap *= 2;
	}
	free(tmp);
}

////version two
//void MergeSortNonR(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		perror("malloc fail!\n");
//		exit(-1);
//	}
//
//	int gap = 1;
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//			int j = i;
//			if (end1 >= n)
//			{
//				end1 = n - 1;
//				begin2 = n;
//				end2 = n - 1;
//			}
//			if (end1 < n && begin2 >= n)
//			{
//				begin2 = n;
//				end2 = n - 1;
//			}
//			if (begin2 < n && end2 >= n)
//				end2 = n - 1;
//
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//					tmp[j++] = a[begin1++];
//
//				else
//					tmp[j++] = a[begin2++];
//			}
//			while (begin1 <= end1)
//				tmp[j++] = a[begin1++];
//
//			while (begin2 <= end2)
//				tmp[j++] = a[begin2++];
//
//			memcpy(a + begin1, tmp + begin1, sizeof(int) * (end1 - begin1 + 1));
//		}
//		gap *= 2;
//	}
//	free(tmp);
//}

// ��������
void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max < a[i])
			max = a[i];

		if (min > a[i])
			min = a[i];
	}

	int size = max - min + 1;
	int* cnt = (int*)malloc(sizeof(int) * size);
	if (cnt == NULL)
	{
		perror("malloc fail!\n");
		exit(-1);
	}
	memset(cnt, 0, sizeof(int) * size);

	for (int i = 0; i < n; i++)
	{
		cnt[a[i] - min]++;
	}

	int j = 0;
	for (int i = 0; i < size; i++)
	{
		while (cnt[i]--)
		{
			a[j++] = i + min;
		}
	}

	free(cnt);
}