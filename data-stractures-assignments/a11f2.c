#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define StackLimit 50

typedef int StackElementType;
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef struct{
    FALSE,TRUE;
}boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

int main(){
    StackType stack;

    CreateStack(&stack);
}


void CreateStack(StackType *Stack){
    Stack -> Top = -1;
}

boolean EmptyStack(StackType Stack){
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack){
    return (Stack.Top == (StackLimit - 1));
}

void Pop(StackType *Stack, StackElementType *Item){
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    }
    else
        printf("Empty Stack...");
}

void Push(StackType *Stack, StackElementType Item){
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    }
    else
        printf("Full Stack...");
}
