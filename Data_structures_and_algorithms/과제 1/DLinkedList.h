#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE 	1
#define FALSE	0

typedef int LData;

//노드의 data를 구조체로 생성
//이름, 학번, 나이:
typedef struct _sdata
{
	char name[10];
	int studentNum;
	int age;
} SData;


//노드 생성 구조체
typedef struct _node
{
	struct _sdata data;
	struct _node * next;
} Node;

//linked list 구성 요소 생성 구조체
typedef struct _linkedList
{	
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	int (*comp)(LData d1, LData data);
} LinkedList;

typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, SData data);

int LFirst(List * plist, SData * pdata);
int LNext(List * plist, SData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));

#endif

