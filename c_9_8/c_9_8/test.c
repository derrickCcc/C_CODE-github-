#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

void test1()
{
	//Heap* php =  NULL;
	//php�Ѿ���ָ����  �ǲ���Ҫ����ַ��Ŷ
	//������Heapû�пռ�  ������ֻ�нṹ���ָ��

	Heap php;
	HeapInit(&php);
	HeapPush(&php, 2);
	HeapPush(&php, 22);
	HeapPush(&php, 35);
	HeapPush(&php, 5);
	HeapPush(&php, 8);
	HeapPush(&php, 76);
	HeapPush(&php, 78);
	HeapPush(&php, 3);
	HeapPush(&php, 66); 
	HeapPush(&php, 4);

	HeapPop(&php);
}
int main()
{
	test1();
	return 0;
}