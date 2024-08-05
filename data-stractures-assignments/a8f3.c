#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define QueueLimit 100

typedef int QueueElementType; /* ο τύπος των στοιχείων της ουράς ενδεικτικά τύπου int */
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
boolean SearchQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

int main(){
    QueueType q;
    QueueElementType item;
    boolean done;
    int i;

    CreateQ(&q);
    for(i=1;i<QueueLimit;i++){
        if(i%3==0)
        {
            AddQ(&q,i);
        }
    }
    TraverseQ(q);
    printf("Give the search value: ");
    scanf("%d", &item);
    done = SearchQ(&q,item);
    if(done == 1){
        printf("Found -> ");
        TraverseQ(q);
    }
    else {
        printf("Not Found -> ");
        TraverseQ(q);
    }


    system("pause");
    return 0;
}

boolean SearchQ(QueueType *Queue, QueueElementType Item){
    boolean stop;
    QueueElementType temp;

    stop=0;

    while(!EmptyQ(*Queue)&&stop==0)
    {
        RemoveQ(&(*Queue),&temp);
        if(temp==Item)
        {
            stop=1;
        }
    }
    return stop;
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

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
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
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
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






