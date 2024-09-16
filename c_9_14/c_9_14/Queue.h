#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef struct BTNode* QDatatype;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDatatype data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//���г�ʼ��
void QueueInit(Queue* pq);
//��������
void QueueDestroy(Queue* pq);
//���
void QueuePush(Queue* pq, QDatatype x);
//����
void QueuePop(Queue* pq);
//���д�С
int QueueSize(Queue* pq);
//�ж϶ӿ�
bool QueueEmpty(Queue* pq);
//��ͷ����
QDatatype QueueFront(Queue* pq);
//��β����
QDatatype QueueBack(Queue* pq);
