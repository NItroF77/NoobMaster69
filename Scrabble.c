#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//modular list
void MainMenu();
void Game_Mode();
void Credit();
void insert_data_player();
void Initiate_boardC();
void Initiate_boardH();
void show_table();
int PutWord(char wordC[], int size_of_word);
int FindWord(char *search_for_string,int size_s);
void add_score(char word[],int Location[][2]);
int Check_Multi(int score,int LocationX,int LocationY);
void end_game();
// user defined data
typedef struct Player_Data{
	char usr[2][30];
	int scr[2];
	int words[2];
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
int turn=1;
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
		if(i==1){printf("%c%8.cSelamat Datang%7.c%c",186,empty,empty,186);}
		else if(i==2){printf("%c%7.cDI Game Scrabble%6.c%c",186,empty,empty,186);}
		else if(i==6){printf("%c%7.cBy NoobMaster69%7.c%c",186,empty,empty,186);}
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
		case 2 : printf("mohon maaf kami belum mengembangkan Player Vs Bot");getch();system("cls");Game_Mode();break;
		default : printf("tidak ada pilihan angka tersebut");getch();system("cls");Game_Mode();break;
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
	switch(choose){
		case 1 : Initiate_boardC();break;
		case 2 : Initiate_boardH();break;
		default : printf("maaf tidak ada pilihan angka tersebut");getch();system("cls");SetDiff();break;
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
				{7,1,1,1,1,7,1,1,1,7,1,1,1,1,7},
				{1,2,1,1,1,1,6,1,6,1,1,1,1,2,1},
				{1,1,2,1,1,1,1,7,1,1,1,1,2,1,1},
				{1,1,1,2,1,1,1,1,1,1,1,2,1,1,1},
				{1,1,1,1,6,1,1,1,1,1,6,1,1,1,1},
				{7,1,1,1,1,6,1,1,1,6,1,1,1,1,7},
				{1,6,1,1,1,1,6,1,6,1,1,1,1,6,1},
				{1,1,7,1,1,1,1,5,1,1,1,1,7,1,1},
				{1,6,1,1,1,1,6,1,6,1,1,1,1,6,1},
				{7,1,1,1,1,6,1,1,1,6,1,1,1,1,7},
				{1,1,1,1,6,1,1,1,1,1,6,1,1,1,1},
				{1,1,1,2,1,1,1,1,1,1,1,2,1,1,1},
				{1,1,2,1,1,1,1,3,1,1,1,1,2,1,1},
				{1,2,1,1,1,1,6,1,6,1,1,1,1,2,1},
				{7,1,1,1,1,7,1,1,1,7,1,1,1,1,7}};
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
		p.scr[0]=0;
		p.scr[1]=0;
}
void show_board(){
	int i,j;
	char empty=' ';
	printf("%6.c1  ",empty);
	for(i=1;i<M;i++){
		if(i<9){
			printf(" %d  ",i+1);
		}
		else{
		printf(" %d ",i+1);
		}
	}
	printf("\n%4.c",empty);
	printf("%c",201);
	for(i=1;i<M+6;i++){
		printf("%c%c%c",205,205,205);
	}
	printf("\n");
	for(i=0;i<M;i++){
		if(i<9){
			printf(" %d  %c",i+1,186);
		}
		else{
		printf(" %d %c",i+1,186);
		}
		for(j=0;j<M;j++){
			if(dat.BoardM[i][j]=='\0'){
				switch(dat.BoardS[i][j]){
					case 1 : printf(" *  ");break;
					case 6 : printf(" 2W ");break;
					case 7 : printf(" 3W ");break;
					default : printf(" %d  ",dat.BoardS[i][j]);break;
				}
			}
			else{
				printf(" %c  ",dat.BoardM[i][j]);
			}
		}
		printf("\n");
		printf("    %c\n",186);
	}
	printf("%s with score : %d Vs %s with score : %d\n",p.usr[0],p.scr[0],p.usr[1],p.scr[1]);
	InputTiles();
}
void InputTiles()
{	
	char cnfrm,Position,cekPosX,cekPosY;
	int i,PosX,PosY,cekPos=0,countL;
	int PosWord[7][2];
	char word[1024];
	char tiles[7];
	if(turn==0){
		turn=1;
	}
	else if(turn==1){
		turn=0;
	}
	printf("%s's Turn\n",p.usr[turn]);
	srand(time(0));
		for(i=0;i<7;i++){
		tiles[i]="AAAAAAAAAABBCCDDDDEEEEEEEEEEFFGGGHHIIIIIIIIIJKLLLLLMMNNNNNNOOOOOOOPPQRRRRRRSSSSTTTTTTUUUUVVWWXYYZ"[rand() % 97];
	}
	menu :
			countL=0;
			for(i=0;i<7;i++){
				printf("%c ",tiles[i]);
			}
			printf("\n");
			fflush(stdin);
			printf("Vertical (V) or Horizontal (H) and the initial point with format (column,row), ex: H,8,8 or h,8,8\n");
			fflush(stdin);
			scanf("%c,%d,%d",&Position,&PosX,&PosY);
			cekPosX=PosX+'0';
			cekPosY=PosY+'0';
			if(Position>90){
				Position-=32;
			}
			if(Position=='H' || Position=='V'){
				cekPos=1;
			}
			if(cekPos==0 || isdigit(cekPosX)==0 || isdigit(cekPosY)==0 ){
				printf("incorrect input position\n");
				getch();
				goto menu;
			}
			else if(PosX>15 || PosY>15){
				printf("Position Exceed board\n");
			}
			fflush(stdin);
			printf("Please input a word\n");
			gets(word);
			for(i=0;word[i]!='\0';i++){
				countL++;
			}
			for(i=0;word[i]!='\0';i++){
				if(word[i]>90){
					word[i]=word[i]-32;
				}
			}
			printf("%s is word you want to input? Y or N\n",word);
			scanf("%c",&cnfrm);
			if(cnfrm=='N' || cnfrm=='n'){
				goto menu;
			}
			
			while(1){
				if(PutWord(word,countL)){
					if(Position=='V'){
						for(i=0;i<word[i]!='\0';i++){
							PosWord[i][0]=PosX-1;
							PosWord[i][1]=PosY-1;
							dat.BoardM[PosY-1][PosX-1]=word[i];
							PosY++;
						}
					}
						else if(Position=='H'){
							for(i=0;i<word[i]!='\0';i++){
								dat.BoardM[PosY-1][PosX-1]=word[i];
								PosX++;
							}
						}
					add_score(word,PosWord);
					printf("Word that you input has been placed\n");
					tcount+=countL;
					break;
				}
				else{
					printf("word that you input failed to be placed\n");
					goto menu;break;
				}
			}
	system("cls");
	if(tcount>100){
		end_game();
	}
	else{
		show_board();
	}
}

int PutWord(char wordC[], int size_of_word)
{
	if(FindWord(wordC,size_of_word)==1){
		return 1;
	}
	else if(FindWord(wordC,size_of_word)==2){
		printf("exceed limit input");
		return 0;
	}
	else{
		return 0;
	}
}
int FindWord(char *search_for_string,int size_s)
{
	int i;
	char word[1024];
	ptr_to_file = fopen("words.txt", "r");
	while (fgets(word, sizeof(word), ptr_to_file) != NULL)
	{
		if (strstr(word, search_for_string) != NULL)
		{
			if(size_s>7){
				return 2;
			}
			else if(size_s==7 || size_s<3){
				return 1;
			}
			else if(strlen(word)==size_s+1){
				return 1;
			}
			else{
				return 0;
			}
		}
	}
	return 0;
}
void add_score(char word[],int Location[][2]){
	int i,total_score=0,scoreL;
	for(i=0;i<word[i]!='\0';i++){
		scoreL=0;
		if(word[i]=='A'|| word[i]=='E' || word[i]=='I' || word[i]=='L'  || word[i]=='N' || word[i]=='O' || word[i]=='R' || word[i]=='S' || word[i]=='T' || word[i]=='U'){
			scoreL+=1;
		}
		else if(word[i]=='D' || word[i]=='G'){
			scoreL+=2;

		}
		else if(word[i]=='B' || word[i]=='C' || word[i]=='M' || word[i]=='P'){
			scoreL+=3;
		}
		else if(word[i]=='F' || word[i]=='H' || word[i]=='V' || word[i]=='W' || word[i]=='d' || word[i]=='Y'){
			scoreL+=4;
		}
		else if(word[i]=='K'){
			scoreL+=5;
		}
		else if(word[i]=='J' || word[i]=='X'){
			scoreL+=8;
		}
		else if(word[i]=='Q' || word[i]=='Z'){
			scoreL+=10;
		}
		scoreL=Check_Multi(scoreL,Location[i][0],Location[i][1]);
		total_score+=scoreL;
	}
	p.scr[turn]=total_score;
}
int Check_Multi(int score,int LocationX,int LocationY)
{
	if(dat.BoardS[LocationY][LocationX]==1 || dat.BoardS[LocationY][LocationX]==6 || dat.BoardS[LocationY][LocationX]==7){
		return score*1;
	}
	else if(dat.BoardS[LocationY][LocationX]==2){
		return score*2;
	}
	else if(dat.BoardS[LocationY][LocationX]==3){
		return score*3;
	}
	else if(dat.BoardS[LocationY][LocationX]==5){
		return score*5;
	}
}
void end_game()
{
	if(p.scr[0]>p.scr[1]){
	printf("The winner is %s with score %d",p.usr[0],p.scr[0]);
	}
	else{
	printf("The winner is %s with score %d",p.usr[1],p.scr[1]);
	}
}
int main(){
	MainMenu();
	show_board();
	return 0;
}