#include <stdio.h>
#include <stdlib.h>

void Armazena(FILE *arquivo){
    FILE *D_Palavras;
    int i=0,l=0,c=0;
    float n=0; 
    D_Palavras = fopen("D_Palavras.txt", "w");
    do{
        l=fgetc(arquivo);
        if((l!='[')&&((l!=EOF))&&(l!=']')){
            c*=10;
            n+=l/c;
            fprintf(D_Palavras,"%c",l);
        }
        else{
            
        }
    }while(l!=EOF);
    
}

int main()
{
    FILE *Pfiletemp;
    
    char filename[]="/home/AD/rgm48931/Área de Trabalho/aed1/readme.code.txt";
    if ((Pfiletemp = fopen(filename, "r"))==NULL){
        printf("\nERRO abrindo %s\n",filename);
        exit(100);
    }
    Armazena(Pfiletemp);
    
}
