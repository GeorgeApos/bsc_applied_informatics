#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define maxSize 50

/* Δομές - Εγγραφές */
typedef struct{
    int num;
    char name[25];
    int tm;
    int fetes;
    float posotherm;
    float posokoin;
}rentDataT;

/* Δηλώσεις συναρτήσεων */
void getData(rentDataT rentals[],double *h,double *p,int *num);
void calcData(rentDataT rentals[],double h,double p,int num_rentals,int *syn_tm,int *syn_fetes,float syn1[],float *syn2);
void printData(rentDataT rentals[],double heat,double price,int num_rentals,int syn_tm,int syn_fetes,float syn1[],float syn2);

/* ΚΥΡΙΟ ΠΡΟΓΡΑΜΜΑ */
int main(){

    double heat,price;
    int num_rentals,syn_tm,syn_fetes;
    float syn1[maxSize],syn2;
    rentDataT rentals[maxSize];

    getData(rentals,&heat,&price,&num_rentals);
    calcData(rentals,heat,price,num_rentals,&syn_tm,&syn_fetes,syn1,&syn2);
    printData(rentals,heat,price,num_rentals,syn_tm,syn_fetes,syn1,syn2);

}

/* ΣΥΝΑΡΤΗΣΕΙΣ */

/* Εισαγωγή Δεδομένων */
void getData(rentDataT rentals[],double *h,double *p,int *num){

    int i;

    printf("Dwse to plhthos twn enoikwn? ");
    *num = GetInteger();

    printf("Dwse to poso thermanshs? ");
    *h = GetReal();
    printf("Dwse to poso koinoxrhstwn? ");
    *p = GetReal();

    for (i=0; i<*num; i++){
        printf("Dwse to onomatepwnymo? ");
        gets(rentals[i].name);
        printf("Dwse ta t.m.? ");
        rentals[i].tm = GetInteger();
        printf("Dwse tis fetes? ");
        rentals[i].fetes = GetInteger();
    }

}

/* Υπολογισμός Δεδομένων */
void calcData(rentDataT rentals[],double h,double p,int num_rentals,int *syn_tm,int *syn_fetes,float syn1[],float *syn2){

    int i;

    *syn_tm = 0;
    *syn_fetes = 0;
    *syn2 = 0;

    for (i=0; i<num_rentals; i++)
    {
        *syn_tm += rentals[i].tm;
        *syn_fetes += rentals[i].fetes;
    }


    for (i=0; i<num_rentals; i++)
    {
       rentals[i].posotherm = (rentals[i].tm*(h))/(*syn_tm);
       rentals[i].posokoin = (rentals[i].fetes*(p))/(*syn_fetes);
    }

    for(i=0; i<num_rentals; i++)
    {
        syn1[i] = rentals[i].posokoin + rentals[i].posotherm;
        *syn2 += syn1[i];
    }

}

/* Εμφάνιση Δεδομένων */
void printData(rentDataT rentals[],double heat,double price,int num_rentals,int syn_tm,int syn_fetes,float syn1[],float syn2){

    int i;

    printf("\n\n");
    printf("%s %25s %5s %5s %5s %8s %13s\n","A/A","ONOMATEPWNYMO","T.M.","FETES","POSO THERM.","POSO KOIN.","SYNOLO");
    for(i=1; i<=78; i++) printf("-");
    printf("\n");

    for(i=0; i<num_rentals; i++)
    {
        printf("%3d %25s %5d %5d %10.02g %11.02g %13d\n",i+1,rentals[i].name,rentals[i].tm,rentals[i].fetes,rentals[i].posotherm,rentals[i].posokoin,syn1[i]);
    }
    for(i=1; i<=78; i++) printf("-");
    printf("\n");
    printf("%s %27d %5d %10.02f %11.02f %13.02f\n","SYNOLA:",syn_tm,syn_fetes,heat,price,syn2);
}


