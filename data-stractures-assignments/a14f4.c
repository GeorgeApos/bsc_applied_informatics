/*****************************
* APOSTOLIDIS GEORGIOS-DAVID *
*          iis20001          *
*****************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 40


typedef char StackElementType;           /*ο τύπος των στοιχείων της στοίβας
                                        ενδεικτικά τύπου int */
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);


 int main()
 {
    boolean found;
    StackPointer AStack;
    StackElementType AnItem;
    int  i;
    char str[N]; //40: ενδεικτικό μήκοσ τησ ακολουθίασ παρενθετικών συμβόλων

    CreateStack(&AStack);
    printf("EISAGETE MIA  PARASTASI:");
    scanf("%s",str);
    found=TRUE;
    for(i=0; str[i] !='\0'; i++)
    {
        AnItem=str[i];
        if(str[i]=='{' || str[i]=='(' || str[i]=='[' ){
            Push(&AStack,AnItem);
        }
        else if(str[i]=='}' || str[i]==')' || str[i]==']')
        {
            if(EmptyStack(AStack)){
                found=FALSE;
                break;
            }
            else
            {
                Pop(&AStack,&AnItem);
                if(str[i]=='}' && AnItem!='{'){
                    found=FALSE;
                    break;
                }
                else if(str[i]==')' && AnItem!='('){
                    found=FALSE;
                    break;
                }
                else if(str[i]==']' && AnItem!='['){
                    found=FALSE;
                    break;
                }


            }
        }
    }
    if(found==FALSE || !EmptyStack(AStack) ){
        printf("WRONG \n");
    }
    else{
        printf("CORRECT \n");
    }


 }


 void CreateStack(StackPointer *Stack)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη στοίβα.
   Επιστρέφει: Μια κενή συνδεδεμένη στοίβα, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* Δέχεται:     Μια συνδεδεμένη στοίβα, Stack.
   Λειτουργία:  Ελέγχει αν η Stack είναι κενή.
   Επιστρέφει:  TRUE αν η στοίβα είναι κενή, FALSE διαφορετικά
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον
                δείκτη Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει στην κορυφή της συνδεδεμένης στοίβας, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον δείκτη Stack.
   Λειτουργία: Αφαιρεί από την κορυφή της συνδεδεμένης στοίβας,
                αν η στοίβα δεν είναι κενή, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα και το στοιχείο Item.
   Έξοδος:     Μήνυμα κενής στοίβας, αν η συνδεδεμένη στοίβα είναι κενή
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}
