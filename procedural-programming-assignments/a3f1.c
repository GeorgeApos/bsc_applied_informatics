#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

    int siskeues,ypol1, ypol2, ypol3, ypol4;

main () {

    printf("Dwse to plhthos twn syskeuwn: ");
    siskeues = GetInteger();
    ypol1 = siskeues / 50;
    ypol2 = (siskeues- 50)/ 20;
    ypol3 = (siskeues - 70)/ 5;
    ypol4 = (siskeues - 75)/ 1;
    printf("50 %d\n", ypol1);
    printf("20 %d\n", ypol2);
    printf("5 %d\n", ypol3);
    printf("1 %d\n", ypol4);

}
