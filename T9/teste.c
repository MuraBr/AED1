#include <stdio.h>
#include <stdlib.h>

/*
    Função que armazena codigo descriptografado em um arquivo .txt
    Esse arquivo fica armazenado no diretório que o programa está sendo rodado
*/
void Armazena(FILE *arquivo, char* Dir){//arquivo: Arquivo criptografado, Dir: Nome do arquivo Descriptografado
    FILE *D_Palavras;
    int letra=0,NumInt=0,c=1,co=0;

    D_Palavras = fopen(Dir, "w");//Criando Arquivo onde serão armazenados os dados

    /*
        Este While loop vai pegar um carácter do Arquivo criptografado até chegar em um caracter ']'
        então, a partir disso o programa vai ler todos os caracteres dentro dos '[]' ao contrario
        multiplicando cada numero por multiplos de 10, Ex: [32] vai ser lido como 3*10 + 2*1.
        Assim numeros é possivel inserir os numeros no arquivo descriptografado no formato char.
    */
    do{
        letra = fgetc(arquivo);
        if(letra==']'){
            do{            
                ++co;
                fseek(arquivo,-2,SEEK_CUR);
                if((letra != ']')&&(letra != 0)){
                    NumInt+=(letra-'0')*c;
                    c*=10;
                }
                letra=fgetc(arquivo);
            }while(letra!='[');
            fprintf(D_Palavras,"%c",NumInt);
            fseek(arquivo,co,SEEK_CUR);
            NumInt=0;
            c=1;
            co=0;
        }
    }while(letra!=EOF);
}

int main()
{
    FILE *Pfiletemp;
    char *Dir="D_Palavras.txt";
    if ((Pfiletemp = fopen("readme.code.txt", "r"))==NULL){
        printf("\nERRO abrindo %s\n","readme.code.txt");
        exit(100);
    }
    Armazena(Pfiletemp,Dir);
    
}
