/*****************************
* APOSTOLIDIS GEORGIOS-DAVID *
*          iis20001          *
*****************************/

#include <stdio.h>
#include <stdlib.h>

typedef enum {
 FALSE, TRUE
} boolean;

typedef int ListElementType;

typedef struct ListNode *ListPointer;

typedef struct ListNode
 {
     ListElementType Data;
     ListPointer Next;
} ListNode;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void inverse_list(ListPointer *List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);

int main()
{
    ListPointer AList;
    ListElementType Item;
    int p,j;

    CreateList(&AList);
    printf("Dwse plhthos stoixeiwn:");
    scanf("%d",&p);

    j=0;
    while(j<p){
        printf("dwse stoixeio:");
        scanf("%d",&Item);
        LinkedInsert(&AList,Item,NULL);
        j++;
    }

    printf("Arxiki \n");
    LinkedTraverse(AList);

    inverse_list(&AList);

    printf("\nTeliki\n");
    LinkedTraverse(AList);
    return 0;
}

void CreateList(ListPointer *List)
{
 *List = NULL;
}

boolean EmptyList(ListPointer List)
{
 return (List==NULL);
}

void LinkedTraverse(ListPointer List)
{
    ListPointer CurrPtr;
    if (EmptyList(List))
        printf("EMPTY LIST\n");
    else
 {
 CurrPtr = List;

while (CurrPtr!=NULL)
 {
 printf("%d ", CurrPtr-> Data);
 CurrPtr = CurrPtr-> Next;
 }
 }
}

void LinkedInsert(ListPointer *List, ListElementType Item,ListPointer PredPtr)
{
    ListPointer TempPtr;
    TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
    TempPtr->Data = Item;
    if (PredPtr==NULL)
 {
 TempPtr->Next = *List;
 *List = TempPtr;
 }
    else
 {
 TempPtr->Next = PredPtr->Next;
 PredPtr->Next = TempPtr;
 }
}

void inverse_list(ListPointer *List)
{
    ListPointer CPtr,HList;

    CreateList(&HList);
    if (!EmptyList(*List)){
        CPtr=*List;
        while (CPtr->Next!=NULL){
           LinkedInsert(&HList,CPtr->Data,NULL);
           CPtr=CPtr->Next;
        }
    }
    *List=HList;
}

