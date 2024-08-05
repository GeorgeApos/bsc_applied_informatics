//Apostolidis Georgios-David || iis20001

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

void ReadInt(int *x,int *y,int *z);
void swap(int *x, int *y);

int main()
{
    int A,B,C;

    ReadInt(&A,&B,&C);

    swap(&A,&B);
    swap(&B,&C);
    swap(&A,&B);

    printf("Taksinomisi : %d,%d,%d\n", A , B, C);
}

void ReadInt(int *x,int *y,int *z)
{
    printf("Dwse 3 times: ");
    *x = GetInteger();
    *y = GetInteger();
    *z = GetInteger();
}

void swap(int *x, int *y)
{
    if (*x > *y)
    {
        int temp;
        temp = *y;
        *y = *x;
        *x = temp;
    }
}
