#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

#define	CUS_COME_TERM	20 //주문 간격		
#define SANDWICH	0
#define GIMBOP		1
#define RAMEN		2

#define SAND_TERM	15 //샌드위치 제조 시간
#define GIM_TERM	22 //김밥 제조 시간
#define RA_TERM		27 //라면 제조 시간


int main(void)
{
	int makeProc=0;		//음식 제조 진행 상황
	int sandOrder=0, gimOrder=0, raOrder=0;
	int sec;
	int numOfOrder = 0; //대기실에 대기하고 있는 손님의 수

	int num = 0; //방문한 손님의 번호
	int max = 0; //대기실의 최대 크기를 계산하기 위한 변수 
	
	TData timedata[3600 / 20]; //대기시간 정보를 저장할 구조체 배열
	int i = 0; //inqueue시 사용할 timedata의 인덱스
	int j = 0; //dequeue시 사용할 timedata의 인덱스

	int minTime = 3600;
	int avrTime = 0;
	int maxTime = 0;
	int sum;

	Queue que;

	QueueInit(&que);
	srand(time(NULL));

	for(sec=0; sec<3600; sec++)
	{
		//20초 간격으로 주문
		if(sec % CUS_COME_TERM == 0) 
		{
			timedata[i].enTime = sec;
			switch(rand() % 3)
			{
			case SANDWICH:
				//대기 시간을 계산하기 위해 음식 제작 시간을 멤버변수 orderTerm에 저장
				timedata[i].orderTerm = SAND_TERM;
				Enqueue(&que, SAND_TERM);
				sandOrder += 1;
				break;

			case GIMBOP:
				//대기 시간을 계산하기 위해 음식 제작 시간을 멤버변수 orderTerm에 저장
				timedata[i].orderTerm = GIM_TERM;
				Enqueue(&que, GIM_TERM);
				gimOrder += 1;
				break;

			case RAMEN:
				//대기 시간을 계산하기 위해 음식 제작 시간을 멤버변수 orderTerm에 저장
				timedata[i].orderTerm = RA_TERM;
				Enqueue(&que, RA_TERM);
				raOrder += 1;
				break;
			}
			numOfOrder++;
			num++;
			i++;
		}
		//대기실의 최대 크기를 계산하기 위해 대기 인원의 최대 값을 max 변수에 저장
		if(numOfOrder > max)
			max = numOfOrder;

		//만들고 있는 음식이 없고 대기하고 있는 사람이 있다면 Dequeue 함수 실행
		if(makeProc==0 && !QIsEmpty(&que))
		{
			//대기 시간을 계산하기 위해 멤버변수  deTime에 Dequeue된 시간을 저장
			timedata[j].deTime = sec;
			makeProc = Dequeue(&que);
			numOfOrder--;
			//저장된 데이터를 바탕으로 대기시간을 계산
			timedata[j].waitingTime = ((timedata[j].deTime - timedata[j].enTime) + timedata[j].orderTerm);
			
			//계산한 waitingTime을 활용하여 최소, 최대 대기시간을 계산
			if(timedata[j].waitingTime < minTime)
				minTime = timedata[j].waitingTime;
			if(timedata[j].waitingTime > maxTime)
				maxTime = timedata[j].waitingTime;
			//평균 대기시간을 계산하기 위해 sum 값에 waitingTime 값을 저장
			sum += timedata[j].waitingTime;

			j++;
		}


		if (makeProc > 0)
                                makeProc--;

		//평균 대기 시간을 계산
		avrTime = sum / num;


	}
	
	printf("Simulation Report! \n");
	printf("\n");
	//샌드위치, 김밥, 라면 각각의 총 주문 수를 출력 
	printf(" - Sandwich: %d \n", sandOrder);
	printf(" - Gimbop: %d \n", gimOrder);
	printf(" - Ramen: %d \n", raOrder);
	printf("\n");
	
	//점심시간에 도착하는 대기 인원을 수용할 수 있는 대기실의 크기를 출력
	printf(" - max Waiting room size: %d \n", max);	
	printf("\n");

	//최소, 평균, 최대 대기시간을 출력
	printf(" - min waiting time: %d\n", minTime);
	printf(" - avr waiting time: %d\n", avrTime);
	printf(" - max waiting time: %d\n", maxTime);
	
	return 0;
}
