#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "UpperLowerCase.c"

/*
    AAAAAAAAAAAAAAA. AAAAAAAAAAAAAAAAA. AAAAAAAAAAAAAAAAA.
            ^                ^                  ^
            |                |                  |
       PontLinhas[0]    PontLinhas[1]      PontLinhas[2]
            
*/

int DefinePontos(char texto[], char *PontLinhas[]){
    int i, k;
    PontLinhas[0] = texto;

    for (k = 1; strstr(PontLinhas[k - 1],". ") != NULL; k++){
        if(*(PontLinhas[0]+(abs(PontLinhas[0] - strstr(PontLinhas[k-1],". "))-2))==' '){
            PontLinhas[k] = strstr(strstr(PontLinhas[k-1],". ")+2,". ")+2;
        }
        else{
            PontLinhas[k] = strstr(PontLinhas[k-1],". ")+2;
        }
    }
    return(k-1);
}

void CapitalizarTexto(char text[], char *PontLinhas[]){
    char *texto;
    int i = 0,k;
    minusculo(text);
    k=DefinePontos(text,PontLinhas);
    for(i = 0; i<=k;i++){ 
        if((*(PontLinhas[i])<=122)&&(*(PontLinhas[i])>=95)){
            *(PontLinhas[i])=*(PontLinhas[i])-32;     
        }     
    }
}



