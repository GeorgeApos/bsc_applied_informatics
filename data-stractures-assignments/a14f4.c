/*****************************
* APOSTOLIDIS GEORGIOS-DAVID *
*          iis20001          *
*****************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 40


typedef char StackElementType;           /*� ����� ��� ��������� ��� �������
                                        ���������� ����� int */
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
    char str[N]; //40: ���������� ����� ��� ���������� ������������ ��������

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
/* ����������: ���������� ��� ���� ����������� ������.
   ����������: ��� ���� ����������� ������, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* �������:     ��� ����������� ������, Stack.
   ����������:  ������� �� � Stack ����� ����.
   ����������:  TRUE �� � ������ ����� ����, FALSE �����������
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ���
                ������ Stack ��� ��� �������� Item.
   ����������: ������� ���� ������ ��� ������������ �������, �� �������� Item.
   ����������: ��� ������������� ����������� ������
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ��� ������ Stack.
   ����������: ������� ��� ��� ������ ��� ������������ �������,
                �� � ������ ��� ����� ����, �� �������� Item.
   ����������: ��� ������������� ����������� ������ ��� �� �������� Item.
   ������:     ������ ����� �������, �� � ����������� ������ ����� ����
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
