#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#define lefta 5

int kafes, resta,x2, x1, x50, x20, x10;
double kostos;

int main()
{
    printf("Dose kafedes: ");
    kafes = GetInteger();
    kostos = kafes*0.7;
    resta = (lefta - kostos)*100;
    printf("Resta\n");
    if (resta <= 500)
    {
        x2 = resta / 200;
        printf("Kermata 2E: %d\n", x2);
        x1 = (resta%200) / 100;
        printf("Kermata 1E: %d\n", x1);
        x50 = ((resta%200)% 100) / 50;
        printf("Kermata 50L: %d\n", x50);
        x20 = (((resta%200)% 100)%50) / 20;
        printf("Kermata 20L: %d\n", x20);
        x50 = ((((resta%200)% 100)%50)%20) / 10;
        printf("Kermata 10L: %d\n", x10);
    }
    else
        printf("den ftanoun ta xrhmata gia tosous kafedes");
}
