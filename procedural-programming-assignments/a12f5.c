#include <genlib.h>
#include "stdio.h"
#include "simpio.h"


int main()
{

//Dilosi metavlitwn
    int students,topics,i,j;
    double grades100[30][10],grades20[30][10],mo20[30],mo100[30],total20[30],total100[30];

//Arithmos Mathitwn me elegxo
    do
    {
        printf("Dwse ton arithmo twn mathitwn: ");
        students = GetInteger();
    }while (students > 30 || students <= 0);

//Arithmos thematwn me elegxo
    do
    {
         printf("Dwse ton arithmo twn thematwn: ");
        topics = GetInteger();
    }while(topics > 10 || topics <= 0);

//Vathmologies mathitwn me elegxo
    for (i=0; i < students; i++)
    {
        for (j=0; j < topics; j++)
        {
            do
            {
                printf("Dwse th bathmologia tou %dou thematos tou %dou mathiti: ",(j+1),(i+1));
                grades100[i][j] = GetReal();
            }while(grades100[i][j]< 0 || grades100[i][j] > 100);
        }
    }

//Ypologismos vathmwn kai mesou orou me klimaka 100
    for (i=0; i < students; i++)
    {
        for (j=0; j < topics; j++)
        {
            total100[i] += grades100[i][j];
        }
        mo100[i] = total100[i]/j;
    }

//Ypologismos vathmwn kai mesou orou me klimaka 20
    for (i=0; i < students; i++)
    {
        total20[i] = (total100[i]*20)/100.0;
        mo20[i] = (mo100[i]*20)/100.0;
        for (j=0; j<topics; j++)
        {
            grades20[i][j] = (grades100[i][j]*20)/100.0;
        }
    }

//Ektiposi apotelesmatwn
    for (i=0; i<students; i++)
    {
        for (j=0; j<topics; j++)
        {
            printf("%6.1lf ", grades100[i][j]);
        }
        printf("%6.1lf\n", mo100[i]);
        for (j=0; j<topics; j++)
        {
            printf("%6.1lf ", grades20[i][j]);
        }
        printf("%6.1lf\n", mo20[i]);
    }

}
