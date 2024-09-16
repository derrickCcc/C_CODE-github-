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

//队列初始化
void QueueInit(Queue* pq);
//队列销毁
void QueueDestroy(Queue* pq);
//入队
void QueuePush(Queue* pq, QDatatype x);
//出队
void QueuePop(Queue* pq);
//队列大小
int QueueSize(Queue* pq);
//判断队空
bool QueueEmpty(Queue* pq);
//队头数据
QDatatype QueueFront(Queue* pq);
//队尾数据
QDatatype QueueBack(Queue* pq);
