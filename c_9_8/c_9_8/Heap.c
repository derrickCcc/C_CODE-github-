#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

//�ѵĳ�ʼ��
void HeapInit(Heap* php)
{
	assert(php); //php���ǿյ�  

	php->a = (HPDataType*)malloc(sizeof(HPDataType)*4);
	if (php->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	php->size = 0;
	php->capacity = 4;
}
// �ѵ�����
void HeapDestory(Heap* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	free(php);
	php = NULL;
}

//����
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//���ϵ����㷨
void AdjustUp(Heap* php,int child)
{
	assert(php);

	int parent = (child - 1) / 2;
	while (php->a[child] > php->a[parent] && parent >= 0)
	{
		Swap(&php->a[child], &php->a[parent]);
		child = parent;
		parent = (child - 1) / 2;
	}
}
// �ѵĲ���
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);

	if (php->size == php->capacity)
	{
		HPDataType* cur = (HPDataType*)realloc(php->a, sizeof(HPDataType) * 2 * php->capacity);
		if (cur == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = cur;
		php->capacity *= 2;
	}

	php->a[php->size] = x;
	php->size++;

	AdjustUp(php, php->size - 1);
}

//���µ����㷨
void AdjustDown(Heap* php,int parent,int size)
{
	assert(php);

	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && php->a[child] < php->a[child]+1)
			++child;
		if (php->a[parent] < php->a[child])
		{
			Swap(&php->a[parent], &php->a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

// �ѵ�ɾ��
void HeapPop(Heap* php)
{
	assert(php);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	AdjustDown(php, 0, php->size);
}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* php)
{
	assert(php);
	return php->a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* php)
{
	assert(php);
	return php->size;
}
// �ѵ��п�
bool HeapEmpty(Heap* php)
{
	assert(php);
	return php->size == 0;
}