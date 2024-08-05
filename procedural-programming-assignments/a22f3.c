#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int number,min;

int main()
{
    printf("Dwse arithmo: ");
    number = GetInteger();
    printf("H fthinousa akolouthia einai: %d,", number);
    min = 1;
    while (min < 0)
    {
        min = number - 1;
        printf("%d", min);
    }
}
