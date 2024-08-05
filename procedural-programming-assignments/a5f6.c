//Apostolidis Georgios-David || iis20001

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define N 100

void ReadArray(int a[],int *m);
void ReadInt(int *x,int *y);
int findMin(int array[N], int a, int k);
int findMax(int array[N], int b, int k);
int findMaxMin(int array[N], int a, int b, int k);
int array[N];

int main()
{
    int c1,c2,c3,k,a,b;

    ReadArray(array,&k);
    ReadInt(&a,&b);

    c1 = findMin(array,a,k);
    printf("To plithos twn stoixeiwn toy pinaka poy einai mikrotero apo A einai: %d\n", c1);
    c2 = findMax(array,b,k);
    printf("To plithos twn stoixeiwn toy pinaka poy einai megalytero apo B einai: %d\n", c2);
    c3 = findMaxMin(array,a,b,k);
    printf("To plithos twn stoixeiwn toy pinaka poy einai anamesa sto A kai sto B einai: %d\n", c3);

    return 0;
    system("PAUSE");
}

void ReadArray(int a[], int *m)
{
    printf("Dwse times gia ton monodiastato(0 gia eksodo): ");
    *m = 0;
    for (int i=0; i<N; i++)
    {

        array[i] = GetInteger();
        if (array[i] == 0) break;
        *m++;
    }
}

void ReadInt(int *x,int *y)
{
    printf("Dwse 2 akeraious: ");
    *x = GetInteger();
    *y = GetInteger();
}

int findMin(int array[N], int a,int k)
{
    int t = 0;
    for (int i=0; i<k; i++)
    {
        if (array[i] <= a)
            t++;
    }
    return t;
}

int findMax(int array[N], int b,int k)
{
    int t = 0;
    for (int i=0; i<k; i++)
    {
        if (array[i] >= b)
            t++;
    }
    return t;
}

int findMaxMin(int array[N], int a, int b, int k)
{
    int t = 0;
    for (int i=0; i<k; i++)
    {
        if (array[i] > a && array[i] < b)
            t++;
    }
    return t;
}
