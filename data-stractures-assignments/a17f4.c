/*****************************
* APOSTOLIDIS GEORGIOS-DAVID *
*          iis20001          *
*****************************/

#include <stdio.h>
#include <stdlib.h>

typedef int QueueElementType;           /*� ����� ��� ��������� ��� ������������ �����
                                        ���������� ����� int*/
typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);

int main(){
    QueueType AQueue;
    QueuePointer CurPtr, PredPtr;
    QueueElementType item;
    int plithos, arithmos, i, j;


    CreateQ(&AQueue);

    printf("Dwse to plithos twn filakismenwn:");
    scanf("%d",&plithos);

    printf("Dwse ton arithmo tou kiklou ektelesis:");
    scanf("%d",&arithmos);

    for(i=1;i<=plithos;i++){
        item=i;
        AddQ(&AQueue,item);
    }

    CurPtr=AQueue.Front;
    j=1;

    while(j<plithos){
        for(i=1;i<arithmos;i++){
            printf("%d, ",CurPtr->Data);
            PredPtr=CurPtr;
            CurPtr=CurPtr->Next;
        }
        printf("%d, ",CurPtr->Data);
        printf("EXECUTION %d\n",CurPtr->Data);
        PredPtr->Next = CurPtr->Next;
        CurPtr = PredPtr->Next;
        j++;
    }
    printf("SURVIVAL %d",CurPtr->Data);

    return 0;
}

void CreateQ(QueueType *Queue)
/* ����������: ���������� ��� ���� ����������� ����.
   ����������: ��� ���� ����������� ����
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����������� ����.
   ����������: ������� �� � ����������� ���� ����� ����.
   ����������: True �� � ���� ����� ����, false  �����������
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* �������:    ��� ����������� ���� Queue ��� ���  �������� Item.
   ����������: ��������� �� �������� Item ��� ����� ��� ������������ ����� Queue.
   ����������: ��� ������������� ����
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
    Queue->Rear->Next=Queue->Front;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����������� ����.
   ����������: ������� �� �������� Item ��� ���  ������ ��� ������������ �����,
                �� ��� �����  ����.
   ����������: �� �������� Item ��� ��� ������������� ����������� ����.
   ������:     ������ ����� �����, �� � ���� �����  ����
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
    Queue->Rear->Next=Queue->Front;
}


