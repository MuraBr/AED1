//Funcoes que podem serem uteis ao longo do projeto

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>


#define COMP_LINHAS 80
//Obejtivo: Dado os limites de uma linha, encontrar onde quebrar uma linha sem que nenhuma palara seja cortada
//Parametros: endereço do começo da linha e endereço final
//Retorno: um ponteiro para o endereço do primeiro caracter da palavra que servirá de quebra
char *encontraIncioPalavra(char *comecoLinha, char *finalMaximoSuportado)
{
    char *quebra, *espaco;
    //Encontra a primeria ocorrência de um caracter espaço 
    espaco = strchr(comecoLinha, 32);
    //Testa se existe espaço na linha
    if ((espaco > finalMaximoSuportado) || (espaco == NULL))
        return NULL;
    //Enquanto o espaço existir e estvier dentro do intervalo da linha 
    while ((espaco < finalMaximoSuportado) && (espaco != NULL))
    {
        //Define provisoriamente a quebra para ser o endereço de espaco mais 1
        quebra = strchr(espaco, 32) + 1;
        //Procura um novo espaço
        espaco = strchr(quebra, 32);
    }
    return quebra;
}

//Obejtivo: Dado um texto, define onde existem quebras de linha, de modo a manter cada linha com um limite de COMP_LINHA caracteres
//Parametros: vetor do texto e vetor de ponteiros para as linhas
//Retorno: nenhum
void definePosQuebraDeLinha(char texto[], char *endLinhas[])
{
    int i, k;
    //Define a primeira linha para ser o começo do texto
    endLinhas[0] = texto;
    //Enquanto a distância do endereço anterior até o final do texto for maior que COMP_LINHAS não estamos na última linha
    for (k = 1; strlen(endLinhas[k - 1]) > COMP_LINHAS; k++)
    {
        //Se o último caracter permitido na linha for um espaço faz uma atribuição direta do próximo caracter para ser a quebra
        if (*(endLinhas[k - 1] + COMP_LINHAS - 1) == 32)
        {
            endLinhas[k] = endLinhas[k - 1] + COMP_LINHAS;
        }
        else
        {
            //Se não, utiliza a função encontraInicioPalavra para encontrar um quebra válida
            endLinhas[k] = encontraIncioPalavra(endLinhas[k - 1], endLinhas[k - 1] + COMP_LINHAS);
        }
    }
    //Atribui a última linha o endereço do caracter terminal do texto
    endLinhas[k] = endLinhas[k - 1] + strlen(endLinhas[k - 1]);
}

//Obejtivo: Dado o texto e os endreços de cada uma de suas linhas exibe o texto formatado
//Parametros: vetor com o texto e vetor de ponteiros com os endereços de cada linha
//Retorno: nenhum
void imprimeTextoFormatado(char texto[], char *endLinhas[])
{
    int i, tamLinha; 
    //Enquanto a linha não apontar para o caracter terminal exibe cada linha
    for (i = 0; *(endLinhas[i]) != '\0'; ++i)
    {
        //Calcula o tamahno da linha
        tamLinha = abs(endLinhas[i] - endLinhas[i + 1]);
        //Exibe exatamente o numéro calculado de caracteres da linha
        printf("%.*s\n", tamLinha, endLinhas[i]);
    }
}
//Obejtivo: Dado o texto, verifica espaços extras e remove eles 
//Parametros: vetor com o texto
//Retorno: nenhum
void removeEspacosExtras(char texto[]){
    char *espacoExtra, copia[3000];
    int cont;
    //Enquanto houver sequencias de espaços, substitui eles pelo resto do texto
    for(espacoExtra = strstr(texto, "  "); espacoExtra != NULL; espacoExtra = strstr(texto, "  "))
    {
        //Calcula quantos espaços estão dispostos numa sequencia específica
        for (cont = 1; *(espacoExtra + cont) == 32; cont++);
        //Copia para uma variavel auxiliar tudo após a sequencia de espaço
        strcpy(copia, espacoExtra + cont);
        //Zera o texto
        memset(espacoExtra + 1, 0, strlen(espacoExtra + 1));
        //Copia de volta o texto após a sequencia de espaços para a posição onde os espaços começam a se repetir
        strcpy(espacoExtra + 1, copia);
    }
    
}
