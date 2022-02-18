#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

//ť�� �ʱ�ȭ�ϴ� �Լ�
void QueueInit(Queue * pq)
{
	pq->front = 0;
	pq->rear = 0;
}

//ť�� ������� Ȯ���ϴ� �Լ�
int QIsEmpty(Queue * pq)
{
	if(pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

//ť�� �ε����� �����ϴ� �Լ�
int NextPosIdx(int pos)
{
	if(pos == QUE_LEN-1)
		return 0;
	else
		return pos+1;
}

//ť�� �����͸� �����ϴ� �Լ�
void Enqueue(Queue * pq, Data data)
{

	if(NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
	
}

//ť���� �����͸� �����ϴ� �Լ�
Data Dequeue(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

//ť�� front�� �ִ� �����͸� Ȯ���ϴ� �Լ�
Data QPeek(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}
