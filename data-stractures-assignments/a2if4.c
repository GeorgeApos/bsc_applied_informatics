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

typedef struct ListNode {
    ListElementType Data;
    ListPointer Next;
} ListNode;

void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void intersect_list(ListPointer AList, ListPointer BList, ListPointer *FinalList);
void LinkedTraverse(ListPointer List);


int main()
{
    ListPointer AList, BList, FinalList;
    ListElementType Item;
    int N1,N2,j;

    CreateList(&AList);

    printf("NUMBER OF ITEMS FOR LIST A:");
    scanf("%d",&N1);

    j=0;
    while(j<N1){
        printf("ITEM FOR LIST A:");
        scanf("%d",&Item);
        LinkedInsert(&AList,Item,NULL);
        j++;
    }

    CreateList(&BList);

    printf("NUMBER OF ITEMS FOR LIST B:");
    scanf("%d",&N2);

    j=0;
    while(j<N2){
        printf("ITEM FOR LIST B:");
        scanf("%d",&Item);
        LinkedInsert(&BList,Item,NULL);
        j++;
    }
    printf("\n A \n");
    LinkedTraverse(AList);

    printf("\n B \n");
    LinkedTraverse(BList);

    intersect_list(AList, BList,&FinalList);

    printf("\n Final\n");
    LinkedTraverse(FinalList);


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


void intersect_list(ListPointer AList, ListPointer BList, ListPointer *FinalList)
{
    ListPointer p1, p2;

    CreateList(FinalList);
    p1=AList;

    while (p1->Next!=NULL)
    {
        p2=BList;
        while(p2->Next!=NULL)
        {
            if(p2->Data==p1->Data)
            {
               LinkedInsert(FinalList,p2->Data,NULL);
               break;
            }
        p2=p2->Next;
        }
    p1=p1->Next;
    }
    LinkedInsert(FinalList,p2->Data,NULL);
}
