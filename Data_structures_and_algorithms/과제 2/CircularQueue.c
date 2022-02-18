#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

//큐를 초기화하는 함수
void QueueInit(Queue * pq)
{
	pq->front = 0;
	pq->rear = 0;
}

//큐가 비었는지 확인하는 함수
int QIsEmpty(Queue * pq)
{
	if(pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

//큐의 인덱스를 변경하는 함수
int NextPosIdx(int pos)
{
	if(pos == QUE_LEN-1)
		return 0;
	else
		return pos+1;
}

//큐에 데이터를 삽입하는 함수
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

//큐에서 데이터를 제거하는 함수
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

//큐의 front에 있는 데이터를 확인하는 함수
Data QPeek(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}
