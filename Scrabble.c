#include "search_ver2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int FindWord(char word[]);
int FindWord(char word[])
{
    char ch[100];
    FILE *ptr_to_file;
    ptr_to_file = fopen("words.txt","r");
    if (ptr_to_file== NULL)
    {
        printf("can not open file \n");
        return 1;
    }

    while(!feof(ptr_to_file))
    {
        fscanf(ptr_to_file,"%s",ch);
        if( strcmp(ch,word) == 0 )
            return 1;
    }
    fclose(ptr_to_file);
    return 0;

}
int main(){

	return 0;
}