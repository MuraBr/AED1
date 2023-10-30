#include <stdio.h>
#include <stdlib.h>

void Armazena(FILE *arquivo){
    FILE *D_Palavras;
    D_Palavras = fopen("D_Palavras.txt", "a");
    
}

int main()
{
    FILE *Pfiletemp;
    
    char filename[]="/home/AD/rgm48931/Área de Trabalho/aed1/readme.code.txt";
    if ((Pfiletemp = fopen(filename, "r"))==NULL){
        printf("\nERRO abrindo %s\n",filename);
        exit(100);
    }
    
    
}
