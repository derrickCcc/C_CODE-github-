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

//堆的初始化
void HeapInit(Heap* php);
// 堆的销毁
void HeapDestory(Heap* php);

//交换
void Swap(HPDataType* p1, HPDataType* p2);

//向上调整算法
void AdjustUp(Heap* php, int child);
// 堆的插入
void HeapPush(Heap* php, HPDataType x);

//向下调整算法
void AdjustDown(Heap* php, int parent, int size);
// 堆的删除
void HeapPop(Heap* php);

// 取堆顶的数据
HPDataType HeapTop(Heap* php);
// 堆的数据个数
int HeapSize(Heap* php);
// 堆的判空
bool HeapEmpty(Heap* php);