#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//modular list
int FindWord(char *search_for_string);
void MainMenu();
void Game_Mode();
void Credit();
void insert_data_player();
void Initiate_table();
void show_table();
// user defined data
typedef struct Player_Data{
	char usr[2][30];
	int scr1;
	int scr2;
	int words1;
	int words2;
}Players;
typedef struct Game_Data{
	int Difficulty;
}G_data;
//variabel global
char t[15][15];
int TotalScoreP1=0;
int TotalScorep2=0;
int tcount=0;
Players p;
G_data Gt;
int turn=0;
FILE *ptr_to_file;
//modular-modular code
void MainMenu(){
 char empty=' ';
 int i,pilihan;
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
	printf("\n%50.cMain Menu :\n%50.c1.Play \n%50.c2.Credit \n%50.c3.Exit\n",empty,empty,empty,empty);
	scanf("%d",&pilihan);
	switch(pilihan){
		case 1 : system("cls");Game_Mode();break;
		case 2 : system("cls");Credit();break;
		case 3 : exit(1);break;
		default :system("cls");MainMenu();break;
	}
}

void Game_Mode()
{	
	int pilihan;
	char empty=' ';
	printf("%50.cPilih Game Mode : \n%50.c1.Player Vs Player \n%50.c2.Player Vs bot\n",empty,empty,empty);
	scanf("%d",&pilihan);
	switch(pilihan){
		case 1 : insert_data_player();break;
		case 2 : printf("mohon maaf kami belum mengembangkan Player Vs Bot");break;
		default : printf("tidak ada pilihan angka tersebut");break;
	}
}

void Credit()
{
	char empty=' ';
	printf("%40.c Credit By : \n %40.cFariz Muhammad Ibnu \n %40.cHanri Fajar \n %40.cRaihan Fuad S.",empty,empty,empty,empty);
}

void insert_data_player(){
	int i;
	for(i=1;i<3;i++){
		printf("masukan nama Player %d :\n",i);
		if (scanf("%s", p.usr[i]) != 1)
            break;
	}
	printf("Selamat Datang %s dan %s",p.usr[1],p.usr[2]);
}
void show_board()
{
	int i;
	int board[] ={4, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 1, 0, 0, 4, 5,
			    0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 5,
			    0, 0, 3, 0, 0, 0, 1, 0, 1, 0, 0, 0, 3, 0, 0, 5,
			    1, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 1, 5,
			    0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 5,
			    0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 5,
			    0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 5,
			    4, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0, 4, 5,
			    0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 5,
			    0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 5,
			    0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 5,
			    1, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 1, 5,
			    0, 0, 3, 0, 0, 0, 1, 0, 1, 0, 0, 0, 3, 0, 0, 5,
			    0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 5,
			    4, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 1, 0, 0, 4};
	for(i=0;i<225;i++){
		if(i%14==0){
			printf("\n");
		}
		else{
		switch(board[i]){
			case 0 : printf(" - ");break;
			case 1 : printf(" 1 ");break;
			case 2 : printf(" 2 ");break;
			case 3 : printf(" 3 ");break;
			case 4 : printf(" 4 ");break;
			case 5 : printf(" 5 ");break;
		}
		}

	}
}
int FindWord(char *search_for_string)
{
	int i;
	char word[1024];
	ptr_to_file = fopen("words.txt", "r");
	printf("FIND WORDS = %s\n", search_for_string);
	while (fgets(word, sizeof(word), ptr_to_file) != NULL)
	{
		if (strstr(word, search_for_string) != NULL)
		{
			return 1;
		}
	}
	return 0;
}
int main(){
	MainMenu();
	show_board();
	return 0;
}
