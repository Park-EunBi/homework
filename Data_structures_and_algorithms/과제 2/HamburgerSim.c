#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

#define	CUS_COME_TERM	20 //�ֹ� ����		
#define SANDWICH	0
#define GIMBOP		1
#define RAMEN		2

#define SAND_TERM	15 //������ġ ���� �ð�
#define GIM_TERM	22 //��� ���� �ð�
#define RA_TERM		27 //��� ���� �ð�


int main(void)
{
	int makeProc=0;		//���� ���� ���� ��Ȳ
	int sandOrder=0, gimOrder=0, raOrder=0;
	int sec;
	int numOfOrder = 0; //���ǿ� ����ϰ� �ִ� �մ��� ��

	int num = 0; //�湮�� �մ��� ��ȣ
	int max = 0; //������ �ִ� ũ�⸦ ����ϱ� ���� ���� 
	
	TData timedata[3600 / 20]; //���ð� ������ ������ ����ü �迭
	int i = 0; //inqueue�� ����� timedata�� �ε���
	int j = 0; //dequeue�� ����� timedata�� �ε���

	int minTime = 3600;
	int avrTime = 0;
	int maxTime = 0;
	int sum;

	Queue que;

	QueueInit(&que);
	srand(time(NULL));

	for(sec=0; sec<3600; sec++)
	{
		//20�� �������� �ֹ�
		if(sec % CUS_COME_TERM == 0) 
		{
			timedata[i].enTime = sec;
			switch(rand() % 3)
			{
			case SANDWICH:
				//��� �ð��� ����ϱ� ���� ���� ���� �ð��� ������� orderTerm�� ����
				timedata[i].orderTerm = SAND_TERM;
				Enqueue(&que, SAND_TERM);
				sandOrder += 1;
				break;

			case GIMBOP:
				//��� �ð��� ����ϱ� ���� ���� ���� �ð��� ������� orderTerm�� ����
				timedata[i].orderTerm = GIM_TERM;
				Enqueue(&que, GIM_TERM);
				gimOrder += 1;
				break;

			case RAMEN:
				//��� �ð��� ����ϱ� ���� ���� ���� �ð��� ������� orderTerm�� ����
				timedata[i].orderTerm = RA_TERM;
				Enqueue(&que, RA_TERM);
				raOrder += 1;
				break;
			}
			numOfOrder++;
			num++;
			i++;
		}
		//������ �ִ� ũ�⸦ ����ϱ� ���� ��� �ο��� �ִ� ���� max ������ ����
		if(numOfOrder > max)
			max = numOfOrder;

		//����� �ִ� ������ ���� ����ϰ� �ִ� ����� �ִٸ� Dequeue �Լ� ����
		if(makeProc==0 && !QIsEmpty(&que))
		{
			//��� �ð��� ����ϱ� ���� �������  deTime�� Dequeue�� �ð��� ����
			timedata[j].deTime = sec;
			makeProc = Dequeue(&que);
			numOfOrder--;
			//����� �����͸� �������� ���ð��� ���
			timedata[j].waitingTime = ((timedata[j].deTime - timedata[j].enTime) + timedata[j].orderTerm);
			
			//����� waitingTime�� Ȱ���Ͽ� �ּ�, �ִ� ���ð��� ���
			if(timedata[j].waitingTime < minTime)
				minTime = timedata[j].waitingTime;
			if(timedata[j].waitingTime > maxTime)
				maxTime = timedata[j].waitingTime;
			//��� ���ð��� ����ϱ� ���� sum ���� waitingTime ���� ����
			sum += timedata[j].waitingTime;

			j++;
		}


		if (makeProc > 0)
                                makeProc--;

		//��� ��� �ð��� ���
		avrTime = sum / num;


	}
	
	printf("Simulation Report! \n");
	printf("\n");
	//������ġ, ���, ��� ������ �� �ֹ� ���� ��� 
	printf(" - Sandwich: %d \n", sandOrder);
	printf(" - Gimbop: %d \n", gimOrder);
	printf(" - Ramen: %d \n", raOrder);
	printf("\n");
	
	//���ɽð��� �����ϴ� ��� �ο��� ������ �� �ִ� ������ ũ�⸦ ���
	printf(" - max Waiting room size: %d \n", max);	
	printf("\n");

	//�ּ�, ���, �ִ� ���ð��� ���
	printf(" - min waiting time: %d\n", minTime);
	printf(" - avr waiting time: %d\n", avrTime);
	printf(" - max waiting time: %d\n", maxTime);
	
	return 0;
}
