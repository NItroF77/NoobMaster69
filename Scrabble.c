#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//modular list
int FindWord(char word[]);
void Initiate_table();
void show_table();
//variabel global
char t[15][15][5][7];
int TotalScoreP1=0;
int TotalScorep2=0;
int tcount=0;
//modular-modular code
void Initiate_table(){
    
}
Void show_table(){

}
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
	create_table();
	return 0;
}