/*****************************
* APOSTOLIDIS GEORGIOS-DAVID *
*          iis20001          *
*****************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct
{
    char data[20];
    char dummy;
} BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void AddToTree(char ch[], char code[], int codelen, BinTreePointer *Root);
void BuildDecodingTree(BinTreePointer *Root,   FILE  *CodeFile);
void Decode(BinTreePointer Root, FILE* MessageFile);
void PrintTree(FILE *t, BinTreePointer Root, int indent);

int main()
{
    FILE  *CodeFile, *MessageFile;
    BinTreePointer Root;

    CodeFile = fopen("codesRW.txt", "r");
    if (CodeFile == NULL)
        printf("Can't open codesRW.txt\n");
    else
    {
        BuildDecodingTree(&Root, CodeFile);


        MessageFile = fopen("program.txt", "r");
        if (MessageFile == NULL)
            printf("Can't open program.txt\n");
        else
            Decode(Root, MessageFile);
    }


    system("PAUSE");
}

void AddToTree(char ch[], char code[], int codelen, BinTreePointer *Root)
{
  int i;
  BinTreePointer TempPtr,p;
  i =0;
  p =*Root;
  while (i<codelen)

    if (code[i]=='0')
    {
        if (p->LChild==NULL)
        {
            TempPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
            TempPtr->Data.dummy='*';
            TempPtr->LChild=NULL;
            TempPtr->RChild=NULL;
            p->LChild=TempPtr;
        }
        i=i+1;
        p=p->LChild;
    }
    else
      if (code[i]=='1')
      {
          if (p->RChild==NULL)
          {
              TempPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
              TempPtr->Data.dummy='*';
              TempPtr->LChild=NULL;
              TempPtr->RChild=NULL;
              p->RChild=TempPtr;
          }
          i=i+1;
          p=p->RChild;
      }

      strcpy(p->Data.data,ch);
}


void BuildDecodingTree(BinTreePointer *Root, FILE  *CodeFile)
{
  char  ch[10],termch;
  char code[4];
    int nscan;


    (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
    (*Root)->Data.dummy='*';
    (*Root)->LChild=NULL;
    (*Root)->RChild=NULL;
            while (TRUE)
            {
                nscan = fscanf(CodeFile, "%10[^\n]\n%4[^\n]%c",ch, code,&termch);
                if (nscan == EOF) break;
                if (nscan >3 || termch != '\n')
                {
                    printf("Improper file format\n");
                    break;
                }
                else
                    AddToTree(ch, code, strlen(code), &(*Root));
            }
}

void Decode(BinTreePointer Root, FILE* MessageFile)
{
  char bit;
  BinTreePointer p;


        while (TRUE)
        {
            p=Root;
            while (p->LChild!=NULL || p->RChild!=NULL)
            {
                bit=fgetc(MessageFile);
                if (bit != EOF)
                {
                    printf("%c",bit);
                    if (bit=='0')
                        p=p->LChild;
                    else
                        if (bit=='1')
                            p=p->RChild;
                        else
                            if (bit!='\n')
                                printf("MH APODEKTO bit: \n", bit);
                }
                else break;
            }
             if (bit != EOF) printf("---%s\n",p->Data.data);
             else break;
        }
}

void PrintTree(FILE *t, BinTreePointer Root, int indent)
{
  int i;
  if (Root!=NULL)
  {
      PrintTree(t, Root->RChild, indent+8);
      for (i=1;i<=indent;i++) fprintf(t," ");
      fprintf(t,"%s\n", Root->Data);
      PrintTree(t, Root->LChild, indent+8);
  }
}
