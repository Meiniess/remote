/*****************************************/
//LQueue.h

typedef int QElemType;
//typedef struct BTNode* QElemType;
typedef struct QNode
{
	QElemType data;
	struct QNode *_pNext;
}QNode;

typedef struct LQueue
{
	QNode *pFront;
	QNode *pRear;
}LQueue;


//初始化
void LQueueInit(LQueue *q);

//入队列
void LQueuePush(LQueue *q, QElemType data);

//出队列
void LQueuePop(LQueue *q);

//返回队头元素
QElemType LQueueTop(LQueue *q);

//返回返回队列长度
int LQueueSize(LQueue *q);

//队列是否为空
int LQueueEmpty(LQueue *q);


/************************************************/
//LQueue.c

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

//创建新结点
static QNode *BuyLQNode(QElemType data)
{
	QNode *pLQNode = (QNode *)malloc(sizeof(QNode));
	if (NULL == pLQNode)
	{
		printf("申请空间失败!\n");
		assert(pLQNode);
	}
	pLQNode->data = data;
	pLQNode->_pNext = NULL;

	return pLQNode;
}

//初始化
void LQueueInit(LQueue *q)
{
	assert(q);
	q->pFront = q->pRear = NULL;
}

//入队列
void LQueuePush(LQueue *q, QElemType data)
{
	assert(q);
	if (NULL == q->pFront)
	{
		q->pFront = q->pRear = BuyLQNode(data);
		return;
	}
	q->pRear->_pNext = BuyLQNode(data);
	q->pRear = q->pRear->_pNext;
}

//出队列
void LQueuePop(LQueue *q)
{
	assert(q);
	QNode *pDel;
	if (NULL == q->pFront)
	{
		return;
	}

	if (q->pFront == q->pRear)
	{
		q->pRear = NULL;
	}

	pDel = q->pFront;
	q->pFront = q->pFront->_pNext;
	free(pDel);
}

//返回队头元素
QElemType LQueueTop(LQueue *q)
{
	assert(q);
	return q->pFront->data;
}

//返回队尾元素
QElemType LQueueBack(LQueue *q)
{
	assert(q);
	return q->pRear->data;
}

//返回返回队列长度
int LQueueSize(LQueue *q)
{
	int count = 0;
	QNode *pCur;
	assert(q);
	pCur = q->pFront;
	while (pCur)
	{
		pCur = pCur->_pNext;
		count++;
	}
	return count;
}

//队列是否为空
int LQueueEmpty(LQueue *q)
{
	return NULL == q->pFront;
}
