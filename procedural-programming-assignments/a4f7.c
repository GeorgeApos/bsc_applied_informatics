#include <stdio.h>
#include <string.h>
#include "simpio.h"
#include "genlib.h"

#define maxSize 50

int main()
{
    char array[maxSize],entered_num[maxSize];
    int i,x,y,z;

    printf("\nDwse akeraiao arithmo: ");
    gets(entered_num);
    printf("\nDwse ton arithmo L: ");
    y = GetInteger();
    printf("\n\n");

    x = strlen(entered_num);
    z = y - x;

    for (i=0; i<z; i++) {array[i] = 0};

    strcat(array,entered_num);

    array[z]= '\0';

    printf("\nOlokliros arithmos: %s\n\n",array);

    system("PAUSE");
    return 0;
}
