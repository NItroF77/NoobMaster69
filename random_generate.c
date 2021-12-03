#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
 
char RandA[100];
int count[27]={9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1,2};
char alpha[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P', 'Q', 'R','S','T','U','V', 'W', 'X','Y','Z',' '};
int total=98;
 
void TileGenerate() {
 
char ran; int i, j;
 
    srand((unsigned) time(NULL));
 
 
    while(total) {
        ran = 'A' + rand() % 26;

        for (j=0; j<27; j++) { //create random matrix
            if (ran==alpha[j] && count[j]>0) {
                RandA[total]=ran;
                --count[j];
                --total;
            }
        }
    }
 
    for (i=1; i<=100; i++) { //print random matrix
        if (i%10==0)
            printf("\n");
        ran = 'A' + rand() % 26;
        printf("%c ", RandA[i-1]);
    }

 
 
return;
}