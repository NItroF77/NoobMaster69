#include "search_ver2.h"
#include <stdio.h>
#include <string.h>
int main(){
	char word[30];
	gets(word);
	if(FindWord(word)){
		printf("\nKata yang dicari ketemu");
	}
	else{
		printf("\nKata yang dicari tidak ketemu");
	}
	return 0;
}