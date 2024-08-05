//Apostolidis Georgios-David || iis20001

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

void GetTime(long SysSecs, int *hours, int *minutes, int *seconds);

int main()
{
    long secs;
    int h,m,s;
    printf("Enter Device Secs: ");
    secs = GetLong();

    GetTime(secs, &h, &m, &s);

    printf("Time is %ld:%ld:%ld", h, m, s);

    return 0;
    system("PAUSE");
}

void GetTime(long SysSecs, int *hours, int *minutes, int *seconds){
    *hours = SysSecs / 3600;
    *minutes = (SysSecs - (3600 * *hours)) / 60;
    *seconds = (SysSecs - (3600 * *hours) - (*minutes * 60));
}
