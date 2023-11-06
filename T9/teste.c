#include <stdio.h>
#include <stdlib.h>
#define escolha "\n1-Decifra Arquivo\n\
2-Grava numero linha em arquivo\n\
3-Quantas Linhas o arquivo tem\n\
4-Qual a maior Linha\n\
5-Pesquisar uma palavra\n\
0-Encerrar\n\
\
Qual Opcao: "

/*
    Função que armazena codigo descriptografado em um arquivo .txt
    Esse arquivo fica armazenado no diretório que o programa está sendo executado
*/
void Armazena(FILE* arquivo, char* Dir){//arquivo: Arquivo criptografado, Dir: Nome do arquivo Descriptografado
    FILE *A_Palavras;
    int letra=0,NumInt=0,c=1,co=0;

    A_Palavras = fopen(Dir, "w");//Criando Arquivo onde serão armazenados os dados

    /*
        Este While loop vai pegar um caracter do Arquivo criptografado até chegar em um caracter ']'
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

            fprintf(A_Palavras,"%c",NumInt);
            fseek(arquivo,co,SEEK_CUR);

            NumInt=0;
            c=1;
            co=0;
            
        }

    }while(letra!=EOF);
    fclose(A_Palavras);
}
/*Função que cria um arquivo com o texto descriptografado mais a quantidade de linhas do texto.
 O Arquivo é armazenado no mesmo diretorio do programa executado*/
void NumLinhas(FILE* arquivo, char* Dir){//arquivo: Arquivo descriptografado, Dir: Nome do arquivo com a quantidade de linhas
    //Declaracao de variaveis
    FILE* A_Linhas;
    int linhas = 1,letra=0;
    
    A_Linhas=fopen(Dir, "w");//Criando arquivo onde os dados serao armazenados
    fprintf(A_Linhas,"[Linha:%d]",linhas);
    /*
        Primeiramente, sera incluida a primeira linha, pois o texto não começa com \n
    */
    while(letra!=EOF){
        /*
            Enquanto o while loop estiver sendo executado são copiados os caracteres do arquivo descriptografado até
            o arquivo com linhas
        */
        letra=fgetc(arquivo);//Caracter do arquivo descriptografado

        if(letra!=EOF) fprintf(A_Linhas,"%c",letra);//Impede o computador de copiar o EOF no final do arquivo

        if(letra==10){
            /*cada vez que o Char letra for igual a \n ou 10, o computador vai escrever [Linha:"linhas"], 
            onde linhas é um numero inteiro que aumenta a cada nova linha*/
            linhas+=1;
            fprintf(A_Linhas,"[Linha:%d]",linhas);

        }

    }
    fclose(A_Linhas);
    fclose(arquivo);
}

void InfoTexto(FILE* arquivo, char* dir, int esc){
    int linhas=0, maiorLinha=0, quantchar=0, q_mLinha=0,tq_mLinha=0;
    char l;
    arquivo = fopen(dir, "r");
    do{
        l = fgetc(arquivo);
        quantchar++;
        if(l==10){
            ++linhas;
            quantchar=0;
        }
        
        if(quantchar>q_mLinha){
            maiorLinha = linhas;
            q_mLinha = quantchar;
        }
    }while(l!=EOF);
    switch (esc)
    {
        case 3:
            printf("\nO arquivo %s tem (%d) linhas\n",dir, linhas+1);
            break;
        case 4:
            printf("\nA linha [%d] e a maior com (%d)",maiorLinha+1,q_mLinha);
    }
    fclose(arquivo);
}

int main()
{

    FILE *A_Cripto, *A_Descripto, *A_linhas;
    char *D_dec = "readme.decifra.txt", *D_lin = "readme.nlines.txt";
    int esc,linhas;

    if ((A_Cripto = fopen("readme.code.txt", "r"))==NULL){

        printf("\nERRO abrindo %s\n","readme.code.txt");
        exit(100);

    }
    
    do{
        printf(escolha);
        scanf("%d",&esc);
        switch(esc){
            case 1:
                Armazena(A_Cripto,D_dec);
                break;
            case 2:
                if((A_Descripto = fopen(D_dec,"r"))==NULL){
                    printf("\nERRO abrindo %s, tente gerar o arquivo primeiro\n",D_dec);
                    break;
                }
                else{
                    NumLinhas(A_Descripto, D_lin);
                    break;
                }
            case 3:
                if((A_Descripto = fopen(D_dec,"r"))==NULL){
                    printf("\nERRO abrindo %s, tente gerar o arquivo primeiro\n",D_dec);
                    break;
                }
                else{
                    InfoTexto(A_Descripto, D_lin,esc);
                    break;
                }
                break;
            case 4:
                if((A_Descripto = fopen(D_dec,"r"))==NULL){
                    printf("\nERRO abrindo %s, tente gerar o arquivo primeiro\n",D_dec);
                    break;
                }
                else{
                    InfoTexto(A_Descripto, D_lin,esc);
                    break;
                }
                break;
            case 5:
                break;
            case 0:
                break;


        }
    }while(esc!=0);
}
