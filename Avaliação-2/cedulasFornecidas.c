//calculo das ceculas

#include <stdio.h>

int main ()
{
    //definicao das variaveis
    float valorSaque = 0, valorSacado = 0;
    int cedula[8] = {1, 2, 5, 10, 20, 50, 150, 500}, quantidadeCedula[8] = {}, i = 7;

    //leitura do "valorSaque"
    printf("Digite o valor a ser sacado: ");
    scanf("%f", &valorSaque);

    //teste do "valorSaque"
    while(valorSaque <= 0)
    {
    printf("O valor digitado esta incorreto. Digite novamente: ");
    scanf("%f", &valorSaque);
    }
    
    //definicao da quantidade de cedulas
    while(valorSaque > valorSacado)
    {
        while(valorSaque >= valorSacado)
        {
            valorSacado += cedula[i];
            quantidadeCedula[i]++;    
        }
        valorSacado -= cedula[i];
        quantidadeCedula[i]--;
        i--;
    }

    //demonstracao
    for(i = 7; i >= 0; i--)
    {
        printf("%d:\t%d\n",cedula[i] ,quantidadeCedula[i]);
    }

    return 0;
}
