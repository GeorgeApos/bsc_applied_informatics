#include "genlib.h"
#include "simpio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 80

int existingChar(int size, char character, char array[]);

int main()
{
    int i, j;
    int commchars, uniquechars;
    int size1, size2, search_len, sec_len;
    char word1[LENGTH], word2[LENGTH];
    char common[LENGTH], unique[LENGTH];

    printf("Please enter two word to find the common characters.\n");
    printf("Word 1: ");
    gets(word1);
    printf("Word 2: ");
    gets(word2);
    size1=strlen(word1);
    size2=strlen(word2);

    commchars=0;
    uniquechars=0;
    for(i=0; i<size1; i++)
    {
        for(j=0; j<size2; j++)
        {
            if(word1[i]==word2[j])
            {
                common[commchars]=word1[i];
                commchars++;
                if(existingChar(uniquechars, word1[i], unique) != 1)
                {
                    unique[uniquechars]=word1[i];
                    uniquechars++;
                }
                break;
            }
        }
    }
    common[commchars]='\0';
    unique[uniquechars]='\0';
    printf("\nCommon characters of %s in %s:%s\n\n", word1, word1, common);
    printf("----\n");
    printf("Set of (unique) common characters of %s and %s:%s\n\n", word1, word2, unique);
    printf("----\n");

    system("PAUSE");
    return 0;
}

int existingChar(int size, char character, char array[])
{
    int i;

    for(i=0; i<size; i++)
    {
        if(character==array[i])
        {
            return 1;
        }
    }

    return 0;
}

