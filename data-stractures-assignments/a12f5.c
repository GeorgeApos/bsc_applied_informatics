/*****************************
* APOSTOLIDIS GEORGIOS-DAVID *
*          iis20001          *
*****************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    FALSE, TRUE
} boolean;
typedef struct{
  char name[20];
  int code;
}BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;
struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
};
void InorderTraversals(BinTreePointer Root,int code);
void BuildBST(BinTreePointer *Root);
void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType Item, boolean *Found,BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);

int main(){
    BinTreeElementType EmpRec;
    BinTreePointer ARoot,LPtr;
    int i,j;
    boolean found;

    BuildBST(&ARoot);
    i=0;
    while(i<3){
        j=0;
        if (i==0){printf("Give data for office employees:\n");}
        else if(i==1){printf("Give data for factory employees:\n");}
        else{printf("Give data for sales representatives:\n");}
        i++;
        while(j<3){
            printf("Give an employee name: ");
            fgets(EmpRec.name,20,stdin);
            EmpRec.name[strlen(EmpRec.name)-1]='\0';
            printf("Give employee code: ");
            scanf("%d",&EmpRec.code);
            getchar();
            BSTInsert(&ARoot,EmpRec);
            j++;
        }
    }
    printf("Give name for an employee to lookup:\n ");
    fgets(EmpRec.name,20,stdin);
    EmpRec.name[strlen(EmpRec.name)-1]='\0';
    BSTSearch(ARoot,EmpRec,&found,&LPtr);

    if (found){printf("%s,%d\n",EmpRec.name,&EmpRec.code);}
    else{printf("not found.\n");}

    printf("All employees:\n");
    InorderTraversal(ARoot);
    printf("\n");
    printf("All office employees:\n");
    InorderTraversals(ARoot,1);
    printf("\n");
    printf("All factory employees:\n");
    InorderTraversals(ARoot,2);
    printf("\n");
    printf("All sales representatives:\n");
    InorderTraversals(ARoot,3);
    printf("\n");
    printf("Give an employee name to deletion:");
    fgets(EmpRec.name,20,stdin);
    EmpRec.name[strlen(EmpRec.name)-1]='\0';
    BSTDelete(&ARoot,EmpRec);

    return 0;
}

void BuildBST(BinTreePointer *Root){
    FILE *fp;
    int nscan;
    char termch;
    BinTreeElementType EmpRec;

    CreateBST(&(*Root));
    fp = fopen("I12F5.txt", "r");
    if(!fp){
        printf("Unable to open file: \n\n");
        exit(1);
    }
    else{
        while (TRUE){
            nscan = fscanf(fp, "%20[^,], %d\n",EmpRec.name, &EmpRec.code);
            if ( nscan == EOF ) break;
            if ( nscan != 2 ){ printf("Error\n"); }
            BSTInsert(&(*Root),EmpRec);
        }

        fclose(fp);
    }
}

void InorderTraversals(BinTreePointer Root,int code){
    if (Root!=NULL){
        InorderTraversals(Root->LChild,code);
        if (Root->Data.code==code){printf("%s %d\n",Root->Data.name, Root->Data.code);}
        InorderTraversals(Root->RChild,code);
    }
}

void InorderTraversal(BinTreePointer Root){
    if (Root!=NULL){
        InorderTraversal(Root->LChild);
        printf("%s %d\n",Root->Data.name, Root->Data.code);
        InorderTraversal(Root->RChild);
    }
}


void CreateBST(BinTreePointer *Root){
    *Root = NULL;
}
boolean EmptyBST(BinTreePointer Root){
    return (Root==NULL);
}
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item){
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL)
    {
        Parent = LocPtr;
        if (strcmp(Item.name,LocPtr->Data.name)<0)
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item.name,LocPtr->Data.name)>0)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %s EINAI HDH STO DDA\n", Item.name);
    else
    {
        LocPtr =(BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item.name,Parent->Data.name)<0)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr){

    (*LocPtr) = Root;
    (*Found) = FALSE;

    while (!(*Found) && (*LocPtr) != NULL){
        if (strcmp(KeyValue.name, (*LocPtr)->Data.name) < 0)
            (*LocPtr) = (*LocPtr)->LChild;
        else{
            if (strcmp(KeyValue.name, (*LocPtr)->Data.name) > 0)
                (*LocPtr) = (*LocPtr)->RChild;
            else
                (*Found) = TRUE;
        }
    }
}
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,BinTreePointer *LocPtr, BinTreePointer *Parent){
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL){
        if (strcmp(KeyValue.name, (*LocPtr)->Data.name)< 0) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else{
            if (strcmp(KeyValue.name, (*LocPtr)->Data.name) > 0) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else{*Found = TRUE;}
        }
    }
}
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue){

   BinTreePointer  n,Parent,nNext,SubTree;
   boolean Found;

    BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
    if (!Found)
        printf("TO STOIXEIO %s DEN EINAI STO DDA\n", KeyValue.name);
    else{
        if (n->LChild != NULL && n->RChild != NULL){
            nNext = n->RChild;
            Parent = n;
            while (nNext->LChild !=NULL){
                Parent = nNext;
                nNext = nNext->LChild;
            }
            n->Data = nNext->Data;
            n = nNext;
        }
        SubTree = n->LChild;
        if (SubTree == NULL)
            SubTree = n->RChild;
        if (Parent == NULL)
            *Root = SubTree;
        else if (Parent->LChild == n)
             Parent->LChild = SubTree;
        else
             Parent->RChild = SubTree;
        free(n);
     }
}




