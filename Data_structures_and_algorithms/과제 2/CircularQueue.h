#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE	1
#define FALSE	0

#define QUE_LEN	100

typedef int Data;

//대기 시간을 계산하기 위해 필요한 데이터들를 저장하는 구조체
typedef struct _timedata {
	int enTime; //인큐된 시간
	int deTime; //디큐된 시간
	int orderTerm; //조리 완료 까지 걸리는 시간
	int waitingTime; //대기 시간 (대기시간 = (deTime - enTime) + orderTerm)
} TData;

typedef struct _cQueue
{
	int front;
	int rear;
	Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif
