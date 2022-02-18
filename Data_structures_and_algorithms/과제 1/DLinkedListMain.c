#include <stdio.h>
#include <string.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2)
{	
	if(d1 < d2)
		return 0;
	else
		return 1;
}


int main (void)
{
	List list;
	SData sdata; 
	//리스트 초기화 
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);


 	//1) 5개의 학생 데이터 삽입 
	strcpy(sdata.name, "lee");sdata.studentNum = 20203333; sdata.age = 22;
	LInsert(&list, sdata);
	strcpy(sdata.name, "park");sdata.studentNum = 20201111; sdata.age = 20;
	LInsert(&list, sdata);
	strcpy(sdata.name, "kim");sdata.studentNum = 20202222; sdata.age = 21;
	LInsert(&list, sdata);
	strcpy(sdata.name, "kang");sdata.studentNum = 20205555; sdata.age = 24;
	LInsert(&list, sdata);
	strcpy(sdata.name, "choi");sdata.studentNum = 20204444; sdata.age = 23;
	LInsert(&list, sdata);


	//2) 리스트 내 전체 학생 데이터 출력
	printf("<5개의 데이터 삽입 후 학번을 기준으로 오름차순으로 정렬한 뒤 전체 데이터 출력>\n");
       	printf("\n");	
	printf("현재 데이터의 수: %d\n", LCount(&list));


	printf("name\tstudentNum\tage\n");
	printf("----------------------------\n");
	if(LFirst(&list, &sdata))
	{
		printf("%s\t%d\t%d\n", sdata.name, sdata.studentNum, sdata.age);

		while (LNext(&list, &sdata))
			printf("%s\t%d\t%d\n", sdata.name, sdata.studentNum, sdata.age);
	}
	printf("\n\n");
	
	//3) 리스트에 포함된 학번으로 검색 
	
	printf("<리스트에 포함된 학번 20204444으로 검색>\n");
	printf("\n");
	printf("name\tstudentNum\tage\n");
	printf("----------------------------\n");
	if(LFirst(&list, &sdata))
	{
		while (LNext(&list, &sdata))
		{
			if (sdata.studentNum == 20204444)
				printf("%s\t%d\t%d\n", sdata.name, sdata.studentNum, sdata.age);
		}
	}
	printf("\n\n");

	//4) 리스트에 포함되지 않은 학번으로 검색 
	
	printf("<리스트에 포함되지 않은 학번 20200944으로 검색>\n");
	printf("\n");
	printf("name\tstudentNum\tage\n");
	printf("----------------------------\n");
	if(LFirst(&list, &sdata))
	{
		while (LNext(&list, &sdata))
		{
			if (sdata.studentNum == 20200944)
				printf("%s\t%d\t%d\n", sdata.name, sdata.studentNum, sdata.age);		}
	}	
	printf("\n\n");

	//5) 리스트에 포함되지 않은 학번으로 삭제

	if(LFirst(&list, &sdata))
	{	
		if(sdata.studentNum == 20200944)
			LRemove(&list);
		while (LNext(&list, &sdata))
		{
			if(sdata.studentNum == 20200944)
				LRemove(&list);
		}
	}

	printf("<리스트에 포함되지 않은 학번 20200944으로 제거 후 리스트 출력>\n");
	printf("\n");
	printf("현재 데이터의 수: %d\n", LCount(&list));
	printf("name\tstudentNum\tage\n");
	printf("----------------------------\n");
	
	if(LFirst(&list, &sdata))
	{
		printf("%s\t%d\t%d\n", sdata.name, sdata.studentNum, sdata.age);
		while (LNext(&list, &sdata))
			printf("%s\t%d\t%d\n", sdata.name, sdata.studentNum, sdata.age);
	}
	printf("\n\n");

	//6) 리스트에 포함된 학번으로 삭제

	if(LFirst(&list, &sdata))
	{	
		if(sdata.studentNum == 20202222)
			LRemove(&list);
		while (LNext(&list, &sdata))
		{
			if(sdata.studentNum == 20202222)
				LRemove(&list);
		}
	}
	
	printf("<리스트에 포함된 학번 20202222으로 삭제 후 리스트 출력>\n");
	printf("\n");
	printf("현재 데이터의 수: %d\n", LCount(&list));
	printf("name\tstudentNum\tage\n");
	printf("----------------------------\n");

	if(LFirst(&list, &sdata))
	{
		printf("%s\t%d\t%d\n", sdata.name, sdata.studentNum, sdata.age);
		while (LNext(&list, &sdata))
			printf("%s\t%d\t%d\n", sdata.name, sdata.studentNum, sdata.age);
	}
	printf("\n\n");

	//7) 리스트 전체 출력 
	printf("<전체 리스트 출력>\n");
	printf("\n");
	printf("현재 데이터의 수: %d\n", LCount(&list));
	printf("name\tstudentNum\tage\n");
	printf("----------------------------\n");

	if(LFirst(&list, &sdata))
	{
		printf("%s\t%d\t%d\n", sdata.name, sdata.studentNum, sdata.age);
		while (LNext(&list, &sdata))
			printf("%s\t%d\t%d\n", sdata.name, sdata.studentNum, sdata.age);
	}
	printf("\n\n");

	return 0;
}
