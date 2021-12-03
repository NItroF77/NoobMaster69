#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//modular list
int FindWord(char word[]);
void MainMenu();
void Initiate_table();
void show_table();
//variabel global
char t[15][15][5][7];
int TotalScoreP1=0;
int TotalScorep2=0;
int tcount=0;
//modular-modular code
void MainMenu()
{
 char empty=' ';
 int i;
 	printf("%40.c%c",empty,201);
 	for(i=0;i<29;i++){printf("%c",205);}
	printf("%c",187);
	for(i=0;i<8;i++){
		printf("\n");printf("%40.c",empty);
		if(i==1){printf("%c%8.cSelamat Datang%8.c%c",186,empty,186);}
		else if(i==2){printf("%c%7.cDI Game Scrabble%7.c%c",186,empty,186);}
		else if(i==6){printf("%c%7.cBy NoobMaster69%8.c%c",186,empty,186);}
		else{printf("%c%29.c%c",186,empty,186);}}
	printf("\n%40.c%c",empty,200);
 	for(i=0;i<29;i++){printf("%c",205);}printf("%c",188);
}

int main(){
	MainMenu();
	return 0;
}