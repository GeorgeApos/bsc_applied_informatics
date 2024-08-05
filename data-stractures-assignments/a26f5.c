/*****************************
* APOSTOLIDIS GEORGIOS-DAVID *
*          iis20001          *
*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int code;
    int recNo;
} BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;
struct BinTreeNode{
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef struct{
    int code;
    char surname[20];
    char name[20];
    char sex;
    int year;
    float grade;
} StudentT;

typedef enum{
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
int BuildBST(BinTreePointer *Root);
int menu();
void PrintStudent(int RecNum);
void RecBSTInorder(BinTreePointer Root);
void printStudentsWithGrade();

int main(){
    BinTreePointer Root, LocPtr;
    int choice, size;
    StudentT student;
    boolean found;
    FILE *fp;
    BinTreeElementType indexRec;

    choice = menu();
    while(choice!=6){
        switch(choice){
        case 1:
            size=BuildBST(&Root);
            break;
        case 2:
            fp=fopen("foitites.dat", "a");
            if(fp==NULL){
                printf("Can't open file %s","foitites.dat");
                exit(1);
            }
            else{
                printf("Give student's AM: ");
                scanf("%d", &student.code);
                getchar();
                indexRec.code=student.code;
                RecBSTSearch(Root, indexRec, &found, &LocPtr);
                if(!found){
                    printf("Give student surname: ");
                    fgets(student.surname,20,stdin);
                    student.surname[strlen(student.surname)-1]='\0';

                    printf("Give student name: ");
                    fgets(student.name,20,stdin);
                    student.name[strlen(student.name)-1]='\0';

                    printf("Give student's registration year: ");
                    scanf("%d", &student.year);
                    getchar();

                    printf("Give student's grade: ");
                    scanf("%f", &student.grade);
                    getchar();

                    printf("Give student sex F/M: ");
                    scanf("%c", &student.sex);
                    getchar();
                    printf("size=%d\n", size);

                    indexRec.recNo=size;
                    RecBSTInsert(&Root, indexRec);
                    fprintf(fp, "%d, %s, %s, %c, %d, %f%c",
                            student.code, student.surname, student.name,
                            student.sex, student.year, student.grade, '\n');
                    size++;
                }
                else
                    printf("Student already exists\n");
            }
            printf("\n");
            break;
        case 3:
            printf("Give student's AM: ");
            scanf("%d", &student.code);
            indexRec.code=student.code;
            RecBSTSearch(Root, indexRec, &found, &LocPtr);
            if(found){
                indexRec.recNo=LocPtr->Data.recNo;
                PrintStudent(indexRec.recNo);
            }
            else
                printf("Not found\n");
            printf("\n");
            break;
        case 4:
            printf("Print all students data\n");
            RecBSTInorder(Root);
            printf("\n");
            break;
        case 5:
            printf("Print students with a >= given grade\n");
            printStudentsWithGrade();
            printf("\n");
            break;
        case 6:
            break;
        }
        choice = menu();
    }
}

int menu(){
    printf("MENOY \n");
    printf("-------------------------------\n");
    printf("1. Build BST \n");
    printf("2. Insert new student \n");
    printf("3. Search for a student \n");
    printf("4. Print all students (Traverse Inorder) \n");
    printf("5. Print students with a >= given grade \n");
    printf("6. Quit \n");
    int choice;
    do{
        printf("\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();
        printf("\n");
    }while(choice <= 1 && choice >= 6);
    return choice;
}

void PrintStudent(int RecNum){
    FILE *fp;
    int nscan, lines;
    char termch;
    StudentT student;

    fp=fopen("foitites.dat", "r");
    lines=0;
    if(fp==NULL){
        printf("Can't open file %s","foitites.dat");
        exit(1);
    }
    else
        while(lines!=RecNum){
            nscan=fscanf(fp,"%d, %20[^,], %20[^,], %c, %d, %g%c",
                         &student.code, student.surname, student.name,
                         &student.sex, &student.year, &student.grade, &termch);
            if (nscan==EOF)
                break;
            if (nscan!=7 || termch!='\n'){
                printf("Error\n");
                exit(1);
            }
            else
                lines++;
        }
    if(lines<=RecNum){
        printf("%d, %s, %s, %c, %d, %.2g\n",
               student.code, student.surname, student.name,
               student.sex, student.year, student.grade);
    }
    fclose(fp);

}

void printStudentsWithGrade(){
    FILE *infile;
    int nscan;
    char termch;
    StudentT student;
    float theGrade;

    printf("Give the grade: ");
    scanf("%f", &theGrade);
    infile=fopen("foitites.dat", "r");
    if(infile==NULL){
        printf("Can't open file %s","foitites.dat");
        exit(1);
    }
    else{
        while(TRUE){
            nscan=fscanf(infile,"%d, %20[^,], %20[^,], %c, %d, %g%c",
                         &student.code,student.surname,student.name,
                         &student.sex,&student.year,&student.grade,&termch);
            if (nscan==EOF)
                break;
            if (nscan!=7 || termch!='\n'){
                printf("Error\n");
                exit(1);
            }
            else if(student.grade>=theGrade){
                printf("%d, %s, %s, %c, %d, %g%c",
                       student.code, student.surname, student.name,
                       student.sex, student.year, student.grade, termch);

            }
        }
    }
    fclose(infile);
}

void RecBSTInorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        RecBSTInorder(Root->LChild);
        printf("(%d, %d) ", Root->Data.code, Root->Data.recNo);
        RecBSTInorder(Root->RChild);
    }
}

void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    if (BSTEmpty(*Root))
    {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data.code = Item.code;
        (*Root) ->Data.recNo = Item.recNo;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else if (Item.code < (*Root) ->Data.code)
        RecBSTInsert(&(*Root) ->LChild,Item);
    else if (Item.code > (*Root) ->Data.code)
        RecBSTInsert(&(*Root) ->RChild,Item);
    else
        printf("To %d EINAI HDH STO DDA\n", Item.code);
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                  boolean *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{

    if (BSTEmpty(Root))
        *Found=FALSE;
    else if (KeyValue.code < Root->Data.code)
        RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
    else if (KeyValue.code > Root->Data.code)
        RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
    else
    {
        *Found = TRUE;
        *LocPtr=Root;
    }
}

int BuildBST(BinTreePointer *Root)
{
    FILE *fp;
    StudentT student;
    int size, nscan;
    char termch;
    BinTreeElementType indexRec;

    CreateBST(Root);
    fp=fopen("foitites.dat", "r");
    size=1;
    if(fp==NULL)
    {
        printf("Can't open file %s","foitites.dat");
        exit(1);
    }

    else
        while(TRUE){
            nscan=fscanf(fp,"%d, %20[^,], %20[^,], %c, %d, %g%c",
                         &student.code,student.surname,student.name,
                         &student.sex,&student.year,&student.grade,&termch);
            if (nscan==EOF)
                break;
            if (nscan!=7 || termch!='\n')
            {
                printf("Error\n");
                exit(1);
            }
            else
            {
                indexRec.code = student.code;
                indexRec.recNo = size;
                RecBSTInsert(Root,indexRec);
                size++;
            }
        }
    fclose(fp);
    return size;
}
