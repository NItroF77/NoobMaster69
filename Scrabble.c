#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//modular list
int FindWord(char *search_for_string);
void MainMenu();
void Game_Mode();
void Credit();
void insert_data_player();
void Initiate_boardC();
void Initiate_boardH();
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
	int Daticulty;
	int BoardS[15][15];
	char BoardM[15][15];
}Dat;
//variabel global
int tcount=0;
int M;
Players p;
Dat dat;
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
	
	printf("%50.cPilih Game Mode : \n%50.c1. Player Vs Player \n%50.c2.Player Vs bot\n",empty,empty,empty);
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
void SetDiff(){
	int choose;
	char empty=' ';
	printf("%45cPilih tingkat kesulitan \n%45c1. Casual \n%45c2. Hard\n",empty,empty,empty);
	scanf("%d",&choose);
	if(choose==1){
		Initiate_boardC();
	}
	else if(choose==2){
		Initiate_boardH();
}
}
void Initiate_boardC(){
	int i,j,k=10;
	int board[10][10]={
				{2,1,1,1,1,3,1,1,1,2},
				{1,2,1,1,3,1,1,1,2,1},
				{1,1,2,1,1,1,1,2,1,1},
				{1,1,1,2,1,1,2,1,1,1},
				{3,1,1,1,3,3,1,1,1,2},
				{1,3,1,1,3,3,1,1,3,1},
				{1,1,1,2,1,1,2,1,1,1},
				{1,1,2,1,1,1,1,2,1,1},
				{1,2,1,1,3,1,1,1,2,1},
				{2,1,1,1,1,3,1,1,1,2},
				};
	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
			dat.BoardS[i][j]=board[i][j];
		}
	}
	M=10;
}
void Initiate_boardH(){
	int i,j,k=15;
	int board[15][15]={
				{3,1,1,1,1,3,1,1,1,3,1,1,1,1,3},
				{1,2,1,1,1,1,2,1,2,1,1,1,1,2,1},
				{1,1,2,1,1,1,1,3,1,1,1,1,2,1,1},
				{1,1,1,2,1,1,1,1,1,1,1,2,1,1,1},
				{1,1,1,1,2,1,1,1,1,1,2,1,1,1,1},
				{3,1,1,1,1,2,1,1,1,2,1,1,1,1,3},
				{1,2,1,1,1,1,2,1,2,1,1,1,1,2,1},
				{1,1,3,1,1,1,1,5,1,1,1,1,3,1,1},
				{1,2,1,1,1,1,2,1,2,1,1,1,1,2,1},
				{3,1,1,1,1,2,1,1,1,2,1,1,1,1,3},
				{1,1,1,1,2,1,1,1,1,1,2,1,1,1,1},
				{1,1,1,2,1,1,1,1,1,1,1,2,1,1,1},
				{1,1,2,1,1,1,1,3,1,1,1,1,2,1,1},
				{1,2,1,1,1,1,2,1,2,1,1,1,1,2,1},
				{3,1,1,1,1,3,1,1,1,3,1,1,1,1,3}};
	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
			dat.BoardS[i][j]=board[i][j];
		}
	}
	M=15;
}
void insert_data_player(){
	system("cls");
	SetDiff();
		printf("masukan nama Player %d :\n",1);
		fflush(stdin);
		gets(p.usr[0]);
		printf("masukan nama Player %d :\n",2);
		fflush(stdin);
		gets(p.usr[1]);
		printf("Selamat Datang %s dan %s\n",p.usr[0],p.usr[1]);
		p.scr1=0;
		p.scr2=0;
}
void show_board(){
	int i,j;
	for(i=0;i<M;i++){
		for(j=0;j<M;j++){
			if(dat.BoardM[i][j]=='\0'){
				printf(" %d ",dat.BoardS[i][j]);
			}
			else{
				printf(" %c ",dat.BoardM[i][j]);
			}
		}
		printf("\n");
	}
	printf("%s with score : %d Vs %s with score : %d",p.usr[0],p.scr1,p.usr[1],p.scr2);
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