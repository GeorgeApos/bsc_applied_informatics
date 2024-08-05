#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define QueueLimit 20

typedef int QueueElementType; /* � ����� ��� ��������� ��� ����� ���������� ����� int */
typedef struct {
    int Front, Rear;
    QueueElementType Element[QueueLimit];
} QueueType;

typedef enum{
    FALSE,TRUE
} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);
int RandomInt(int low,int high);


int main(){
    QueueType Queue_Artioi;
    QueueType Queue_Perittoi;
    QueueElementType item;
    boolean done;
    int i,j,num,end;

    int artioi = 0;
    int perittoi = 0;

    end = QueueLimit;

    CreateQ(&Queue_Artioi);
    CreateQ(&Queue_Perittoi);

    time_t t;
    srand((unsigned) time(&t));

    for (i=0; i<QueueLimit; i++){
        num = rand()%20;
        if (num % 2 == 0){
            AddQ(&Queue_Artioi,num);
            artioi++;
        }
        else{
            AddQ(&Queue_Perittoi, num);
            perittoi++;
        }
    }
    printf("Size of EvenQueue: %d\n", artioi);
    TraverseQ(Queue_Artioi);
    printf("Size of OddQueue: %d\n", perittoi);
    TraverseQ(Queue_Perittoi);

    j = rand() % artioi;
    printf("random number of items = %d\n", j);
    for (i=0; i<artioi; i++){
        RemoveQ(&Queue_Artioi,&item);
        item = rand()%20;
        AddQ(&Queue_Artioi, item);
    }
    printf("Size of EvenQueue: %d\n", artioi);
    TraverseQ(Queue_Artioi);

    j = rand() % perittoi;
    printf("random number of items = %d\n", j);
    for (i=0; i<perittoi; i++){
        RemoveQ(&Queue_Perittoi,&item);
        item = rand()%20;
        AddQ(&Queue_Perittoi, item);
    }
    printf("Size of OddQueue: %d\n", perittoi);
    TraverseQ(Queue_Perittoi);

    system("Pause");
    return 0;
}


void TraverseQ(QueueType Queue)
{
 	int i;
	i = Queue.Front;
	while (i != Queue.Rear) {
        printf("%d ", Queue.Element[i]);
		i = (i + 1) % QueueLimit;
	}
	printf("\n");
}

int RandomInt(int low,int high)
/* �������: ���� ��������� low ��� high
   ����������: ���������� ���� ������ ������� ������ low KAI high
   ����������: ���� ������ ������ ������ low KAI high

*/
{
    int k;
    double d;

    d = (double) rand() / ((double) RAND_MAX + 1);
    k = (int) (d * (high - low + 1));
    return (low + k);
}

void CreateQ(QueueType *Queue)
/*  ����������:  ���������� ��� ���� ����.
    ����������:  ���� ����
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ����.
   ����������: True �� � ���� ����� ����, False �����������
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ������.
   ����������: True �� � ���� ����� ������, False �����������
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����.
   ����������: ������� �� �������� Item ��� ��� ������ ���� ��� �����
                �� � ���� ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� ����.
   ������:     ������ ����� ���� �� � ���� ����� ����
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* �������:    ��� ���� Queue ��� ��� �������� Item.
   ����������: ��������� �� �������� Item ���� ���� Queue
                �� � ���� ��� ����� ������.
   ����������: ��� ������������� ����.
   ������:     ������ ������� ����� �� � ���� ����� ������
*/
{
    int NewRear;

	if(!FullQ(*Queue))
	{
		NewRear = (Queue ->Rear + 1) % QueueLimit;
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = NewRear;
	}
	else
		printf("Full Queue");
}




