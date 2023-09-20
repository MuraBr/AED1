#include <stdio.h>
#include <string.h>

char *maisculo(char texto[]){
    int i = 0;
    for(i;i<strlen(texto);i++){
        char letra = texto[i];
        if((letra>=97)&&(letra<=122)){
            texto[i]=letra-32;
        }
    }
    return(texto);
}

char *minusculo(char texto[]){
    int i = 0;
    for(i;i<strlen(texto);i++){
        char letra = texto[i];
        if((letra>=65)&&(letra<=90)){
            texto[i]=letra+32;
        }
    }
    return(texto);
}

