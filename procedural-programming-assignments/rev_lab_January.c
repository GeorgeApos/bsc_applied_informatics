#include <stdio.h>
#include <string.h>
#include "genlib.h"
#include "simpio.h"

#define maxSize 100
#define maxChar 40

/*Δομές - Εγγραφές */
typedef struct{
    char name[maxChar];
    int ypoloipo;
    double epitokia;
    int date;
}bankT;


/* Δήλωση Συναρτήσεων */
FILE *openFile(char name[]);
int readData(FILE *infile,bankT x[],char name[]);
void afterYear(FILE *outfile,bankT dep_new[],bankT dep_old[],int i_old,int i_new);
void addDeposit(double *syn_new, double *syn_old, int i_new, int i_old, bankT dep_new[], bankT dep_old[]);

/* ΚΥΡΙΟ ΠΡΟΓΡΑΜΜΑ */
int main(){
    /* Δηλώσεις μεταβλητών */
    FILE *infile_new,*infile_old;
    FILE *outfile;
    bankT dep_new[maxSize];
    bankT dep_old[maxSize];
    char name[maxChar];


    int i,j,i_new,i_old,flag;
    double syn_old,syn_new;

    /* Εισαγωγή αρχείων */
    infile_new = openFile("bank_new.dat");
    infile_old = openFile("bank_old.dat");
    outfile = fopen("mztfgm.dat","w");

    /* Εισαγωγή δεδομένων */
    i_new = readData(infile_new,dep_new,"bank_new.dat");
    i_old = readData(infile_old,dep_old,"bank_old.dat");

    /* [BIG ERROR] Εκτύπωση καταθέτων που δεν βρίσκονται στο παλιό αρχείο (εκτέλεση στη MAIN)
    for (i=0; i<i_new; i++){
    flag = 1;
        for (j=0; j<i_old; j++){
            //Αν είναι ίδια τα ονόματα, επιστρέφει 0
            if(strcmp((dep_old+j)->name, (dep_new+i)->name)==0){
                flag == 0;
                break;
            }
            if (flag == 0) printf("%s\n");
        }
    }

    /* Αποθήκευση καταθετών που άνοιξαν λογαριασμό μετά το 2000 */
    afterYear(outfile,dep_new,dep_old,i_old,i_new);

    /* ’θροισμα καταθέσεων και εκτύπωση του 40% από κάθε αρχείο */
    addDeposit(&syn_new,&syn_old,i_new,i_old,dep_new,dep_old);

    printf("Percentage of 'bank_new.dat': %.2f\n",syn_new*(40/100.0));
    printf("Percentage of 'bank_old.dat': %.2f\n",syn_old*(40/100.0));

    fclose(outfile);
    fclose(infile_new);
    fclose(infile_old);
    /* Κλείσιμο Προγράμματος */
    system("PAUSE");
    return 0;
} /* ΤΕΛΟΣ ΚΥΡΙΟΥ ΠΡΟΓΡΑΜΜΑΤΟΣ */

/* ΣΥΝΑΡΤΗΣΕΙΣ */

    /* OPEN FILE */
FILE *openFile(char name[]){
    FILE *infile;
    infile = fopen(name,"r");
    if (!infile){
        printf("Cannot open input file %s",name);
        system("PAUSE");
        exit(1);
    }

    return infile;
}
    /* READ DATA */
int readData(FILE *infile,bankT x[],char name[]){
    int i = 0;
    int nscan;
    char termch;
    char n[maxChar];
    int y,d;
    double e;

    while (TRUE){
        nscan = fscanf(infile, "%40[^,], %d, %lf, %d%c",n,&y,&e,&d,&termch); // ΠΡΟΣΟΧΗ ΣΤΗΝ ΕΞΟΔΟ

        if (nscan==EOF) break;
        if (nscan != 5 || termch != '\n'){
            printf("File improperly formated.\n");
            exit(1);
        }

        strcpy(x[i].name,n);
        x[i].ypoloipo = y;
        x[i].epitokia = e;
        x[i].date = d;
        i++;
    }
    return i;
}

void afterYear(FILE *outfile,bankT dep_new[],bankT dep_old[],int i_old,int i_new){
    int i,j;
    for (i=0; i<i_new; i++){
        if (dep_new[i].date >= 2000){
            fprintf(outfile,"%s, %d, %.01lf, %.1d\n",dep_new[i].name,dep_new[i].ypoloipo,dep_new[i].epitokia,dep_new[i].date);
        }
    }
}

void addDeposit(double *syn_new, double *syn_old, int i_new, int i_old, bankT dep_new[], bankT dep_old[]){
    int i,j;
    *syn_old = *syn_new = 0;
    for (j=0; j<i_old; j++){
        *syn_old += dep_old[j].ypoloipo;
    }
    for (i=0; i<i_new; i++){
        *syn_new += dep_new[i].ypoloipo;
    }
}
