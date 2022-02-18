#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"


//리스트를 초기화하는 함수
void ListInit(List * plist)
{
	plist -> head = (Node *)malloc(sizeof(Node));
	plist -> head -> next = NULL;
		plist -> comp = NULL;
	plist -> numOfData = 0;
}

//comp에 정렬함수가 정의되어 있지 않을 때
//리스트에 데이터를 삽입하는 함수 
void FInsert (List * plist, SData data)
{	
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode -> data = data;

	newNode -> next = plist -> head -> next;
	plist -> head -> next = newNode;

	(plist -> numOfData)++;
}

//comp에 정렬 함수가 정의되어 있을 때 오름차순으로 
//정렬하며 삽입하는 함수
void SInsert (List * plist, SData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	Node * pred = plist -> head;
	newNode -> data = data;

	while (pred -> next != NULL && plist -> comp(data.studentNum, pred->next->data.studentNum) != 0)
		pred = pred -> next;
	newNode -> next = pred -> next;
	pred -> next = newNode;
	(plist -> numOfData)++;
}

//comp에 정렬 함수가 정의되어 있는지 확인하는 함수 
void LInsert(List * plist, SData data)
{
	if(plist -> comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

//데이터의 참조를 돕는 함수 
int LFirst(List * plist, SData *pdata)
{
	if(plist -> head -> next == NULL)
		return FALSE;

	plist -> before = plist -> head;
	plist -> cur = plist -> head -> next;

	*pdata = plist -> cur -> data;
	return TRUE;
}

//참조된 데이터의 다음 데이터를 저장해 데이터의 참조를 돕는 함수
int LNext(List * plist, SData * pdata)
{
	if(plist -> cur -> next == NULL)
		return FALSE;

	plist -> before = plist -> cur;
	plist -> cur = plist -> cur -> next;

	*pdata = plist -> cur -> data;
	return TRUE;
}

//데이터를 삭제하는 함수
LData LRemove(List * plist)
{
	Node * rpos = plist -> cur;
	SData rdata = rpos->data;

	plist -> before -> next = plist -> cur -> next;
	plist -> cur = plist -> before;

	free(rpos);
	(plist -> numOfData)--;
	return rdata.studentNum;
}

//리스트에 저장된 데이터의 개수를 세는 함수 
int LCount(List * plist)
{
	return plist -> numOfData;
}

//리스트 정렬 방식을 담은 함수를 comp에 등록하는 함수 
void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist -> comp = comp;
}
