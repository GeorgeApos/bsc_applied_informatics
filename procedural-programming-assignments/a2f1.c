#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
    long pleura1, pleura2;
    double emvadon;
main () {

        printf("Dwse to mhkos ths 1hs kathetis pleuras: ");
        pleura1 = GetLong();
        printf("Dwse to mhkos ths 2hs kathetis pleuras: ");
        pleura2 = GetLong();
        emvadon = (double)(pleura1*pleura2)/2;
        printf("To embado einai: %g\n", emvadon);
}
