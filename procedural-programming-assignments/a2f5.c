#include <genlib.h>
#include "stdio.h"
#include "simpio.h"

long ReadWage();

int main()
{
    long wage,total,ScaleTax;
    double diff;
    long array[10][3] = {10000,0,0,39000,18,5220,49000,21,7320,59000,24,9720,85000,28,170000,100000,33,21950,120000,38,29550,150000,43,42450,170000,49,52250,170001,50,0};

    wage = ReadWage();

    printf("\n\tKathares etisies apodoxes: %.1ld Euro\n", wage);

    if (wage >= 1 && wage <= array[0][0])
    {
        ScaleTax = 0;
        diff = 0;
    }
    else if (wage <= array[1][0])
    {
        ScaleTax = 0;
        diff = (wage - array[0][0])*0.18;
    }
    else if (wage <= array[2][0])
    {
        ScaleTax = array[1][2];
        diff = (wage - array[1][0])*0.21;
    }
    else if (wage <= array[3][0])
    {
        ScaleTax = array[2][2];
        diff = (wage - array[2][0])*0.24;
    }
    else if (wage <= array[4][0])
    {
        ScaleTax = array[3][2];
        diff = (wage - array[3][0])*0.28;
    }
    else if (wage <= array[5][0])
    {
        ScaleTax = array[4][2];
        diff = (wage - array[4][0])*0.33;
    }
    else if (wage <= array[6][0])
    {
        ScaleTax = array[5][2];
        diff = (wage - array[5][0])*0.38;
    }
    else if (wage <= array[7][0])
    {
        ScaleTax = array[6][2];
        diff = (wage - array[6][0])*0.43;
    }
    else if (wage <= array[8][0])
    {
        ScaleTax = array[7][2];
        diff = (wage - array[7][0])*0.49;
    }
    else
    {
        ScaleTax = array[8][2];
        diff = (wage - array[8][0])*0.5;
    }
    total = ScaleTax + diff;

    printf("\t\tForos Klimakos: %.1ld Euro\n", ScaleTax);
    printf("\t\tDiafora: %g Euro\n", diff);
    printf("\tSynolikos foros: %.1ld Euro\n", total);


    return 0;
    system("PAUSE");
}

long ReadWage()
{
    long wage;
    printf("Dwse kathares etisies apodoxes: ");
    wage = GetLong();
    return wage;
}


