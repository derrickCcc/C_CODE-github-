#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
 

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

//�ѵĳ�ʼ��
void HeapInit(Heap* php);
// �ѵ�����
void HeapDestory(Heap* php);

//����
void Swap(HPDataType* p1, HPDataType* p2);

//���ϵ����㷨
void AdjustUp(Heap* php, int child);
// �ѵĲ���
void HeapPush(Heap* php, HPDataType x);

//���µ����㷨
void AdjustDown(Heap* php, int parent, int size);
// �ѵ�ɾ��
void HeapPop(Heap* php);

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* php);
// �ѵ����ݸ���
int HeapSize(Heap* php);
// �ѵ��п�
bool HeapEmpty(Heap* php);