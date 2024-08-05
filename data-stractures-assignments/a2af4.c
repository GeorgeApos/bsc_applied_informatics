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
void append_list(ListPointer *List, ListElementType Item);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);


int main()
{
    ListPointer AList;
    ListElementType Item;
    int j,p;

    CreateList(&AList);

    printf("dwse plhthos stoixeiwn:");
    scanf("%d",&p);

    for(j=0;j<p;j++)
    {
        printf("dwse stoixeio gia thn arxh:");
        scanf("%d",&Item);
        LinkedInsert(&AList,Item,NULL);
    }
    LinkedTraverse(AList);
    printf("dwse stoixeio gia to telos:");
    scanf("%d",&Item);
    append_list(&AList,Item);
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

void append_list(ListPointer *List, ListElementType Item)
{
    ListPointer CP;

    CP=NULL;
    if(!EmptyList(*List))
    {
        CP=*List;
        while (CP->Next!=NULL)
        {
            CP=CP->Next;
        }
    }
    LinkedInsert(List,Item, CP);
}
