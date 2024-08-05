#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define QueueLimit 20

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
/* ΔΕΧΕΤΑΙ: ΤΟΥΣ ΑΚΕΡΑΙΟΥς low ΚΑΙ high
   ΛΕΙΤΟΥΡΓΙΑ: ΥΠΟΛΟΓΙΖΕΙ ΕΝΑΝ ΤΥΧΑΙΟ ΑΚΕΡΑΙΟ ΜΕΤΑΞΥ low KAI high
   ΕΠΙΣΤΡΕΦΕΙ: ΕΝΑΝ ΤΥΧΑΙΟ ΑΡΙΘΜΟ ΜΕΤΑΞΥ low KAI high

*/
{
    int k;
    double d;

    d = (double) rand() / ((double) RAND_MAX + 1);
    k = (int) (d * (high - low + 1));
    return (low + k);
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




