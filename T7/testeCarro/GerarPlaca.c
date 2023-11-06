#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50


char geraAlfabeto() {
    int i=0;
    char letras[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    i=rand()%26;
    return(letras[i]);
}

char geraNumero() {
    int i=0;
    char numeros[] = { '0','1','2','3','4','5','6','7','8','9'};

    i=rand()%9;
    return(numeros[i]);
}

int main(){
    int a[8];
    int k=0;
    for (int j = 0; j < 8; j++)
    {
      k=rand()%2;
      printf("k%d\n",k);
      a[j]=k;
      printf("a%d\n",a[j]);
    }
}