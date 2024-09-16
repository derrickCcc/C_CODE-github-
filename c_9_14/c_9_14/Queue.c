#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"

//队列初始化
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = pq->tail = NULL;
	pq->size = 0;
}

//队列销毁
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
	pq->size = 0;
}

//入队
void QueuePush(Queue* pq, QDatatype x)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	if (pq->head == NULL)
	{
		assert(pq->tail == NULL);

		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}

	pq->size++;
}

//出队
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head != NULL);

	/*QNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;

	if (pq->head == NULL)
		pq->tail = NULL;*/

	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}

	pq->size--;
}

//队列大小
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}

//判断队空
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->size == 0;
}

//队头数据
QDatatype QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

//队尾数据
QDatatype QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}