//Código real oficial 2.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variaveis para funções que envolvam cedulas
const int tipoDaCedula[8] = {
    500, 150, 50, 20, 10, 5, 2, 1};
int quantidadeDeCedulas[8] = {
    100, 200, 400, 800, 1600, 3200, 6400, 12800};

// Variavel global para calculos variados
int algarismos[6];

// Constantes para escrever por extenso
const char unidades[10][12] = {
    "", "Um ", "Dois ", "Tres ", "Quatro ", "Cinco ", "Seis ", "Sete ", "Oito ", "Nove "};
const char dezenasEspeciais[10][12] = {
    "Dez ", "Onze ", "Doze ", "Treze ", "Quatorze ", "Quinze ", "Dezesseis ", "Dezessete ", "Dezoito ", "Dezenove "};
const char dezenas[10][12] = {
    "", "", "Vinte ", "Trinta ", "Quarenta ", "Cinquenta ", "Sessenta ", "Setenta ", "Oitenta ", "Noventa "};
const char centenas[10][14] = {
    "", "", "Duzentos ", "Trezentos ", "Quatrocentos ", "Quinhentos ", "Seiscentos ", "Setescentos ", "Oitocentos ", "Novecentos "};
const char unidadesCedula[10][12] = {
    "", "Uma ", "Duas ", "Tres ", "Quatro ", "Cinco ", "Seis ", "Sete ", "Oito ", "Nove "};
const char centenasCedulas[10][14] = {
    "", "", "Duzentas ", "Trezentas ", "Quatrocentas ", "Quinhentas ", "Seiscentas ", "Setescentas ", "Oitocentas ", "Novecentas "};

//Objetivo: separa os algorismos de um número e armazena em um vetor [a, b, c, d, e, f]
//Parametros: recebe um valor e o vetor onde serão guardados os algarismos
//Retorno: os algarismos do valor
void separanum(int valor, int num[])
{
    int i;
    for (i = 5; i >= 0; i--)
    {
        num[i] = valor % 10;
        valor /= 10;
    }
}

//Objetivo: escreve por extenso as casas de centena 
//Parametros: recebe o algarismo da centena(a), dezena(b) e unidade(c) de um numero, além da formatação desejada
//Onde 0 é a formatação padrão e 1 a formatação para cedulas
//Retorno: nenhum
void escreveCent(int a, int b, int c, int tipo)
{
    if (a == 1)
    {
        if ((b == 0) && (c == 0))
        {
            // Escreve cem se forem vazias e cento se existir algum algarismo não nulo
            printf("Cem ");
        }
        else
        {
            printf("Cento ");
        }
    }
    else
    {
        // Utiliza o próprio algarismo para identificar a saída por extenso no vetor das centenas
        if (tipo != 1)
        {
            printf(centenas[a]);
        }
        else
        {
            printf(centenasCedulas[a]);
        }
    }
}

//Objetivo: escreve por extenso as casas de unidade de um numero
//Parametros: recebe o algarismo da centena(a), dezena(b) e unidade(c) de um numero, a formatação desejada
//Onde 0 é a formatação padrão e 1 a formatação para cedulas
//Além da coordenada i do vetor de algarismos
//Retorno: nenhum
void escreveUni(int i, int c, int b, int a, int tipo)
{
    if (i != 2)
    {
        if (tipo != 1)
        {
            printf(unidades[c]);
        }
        else
        {
            printf(unidadesCedula[c]);
        }
    }
    else
    {
        if ((c != 1) || ((b != 0) || (a != 0)))
        {
            if (tipo != 1)
            {
                printf(unidades[c]);
            }
            else
            {
                printf(unidadesCedula[c]);
            }
        }
        // Utiliza o próprio algarismo para identificar a saída por extenso no vetor das unidades
    }
}


//Objetivo: escreve por extenso as casas de dezena de um numero
//Parametros: recebe o algarismo da dezena(b) e unidade(c) de um numero
//Retorno: retorna 1 se o modulo utilizou as dezenas especiais e 0 se usou as dezenas normais 
int escreveDez(int b, int c)
{
    if (b == 1)
    {
        //Se o numero é 1, então está entre 10 e 19, por isso utiliza as dezenas especiais
        printf(dezenasEspeciais[c]);
        return 1;
        // Utiliza o próprio algarismo para identificar a saída por extenso no vetor 
    }
    else
    {
        // Utiliza o próprio algarismo para identificar a saída por extenso no vetor das dezenas
        printf(dezenas[b]);
        return 0;
    }
}

//Objetivo: testa e escreve mil nos lugares corretos 
//Parametros: recebe todas as casas do numero com os algarismos armazenados no vetor [a, b, c, d, e, f]
//Retorno: nenhum
void escreveMil(int a, int b, int c, int d, int e, int f)
{
    // Escreve mil quando pelo menos um algarismo antes da casa da centena não for nulo
    if ((a != 0) || (b != 0) || (c != 0))
    {
        // Escreve mil e apenas se houver numeros não nulos após a unidade de milhar ou se a centena for o único algarismo não nulo no resto do número
        if (((d == 0) && (e == 0) && (f == 0)) || ((d != 0) && ((e != 0) || (f != 0))))
        {
            printf("Mil ");
        }
        else
        {
            printf("Mil e ");
        }
    }
}

//Objetivo: testa e escreve "e" nos momentos adequados
//Parametros: recebe o algarismo da centena(a), dezena(b) e unidade(c) de um numero
//Além da coordenada i do vetor que está sendo analisada
//Retorno: nenhum
void escreveE(int i, int a, int b, int c)
{
    // Avalia quando escrever "e'"
    // Escreve apenas se o algarismo analisado não for nulo ou da casa da unidade
    // Se o algarismo faz parte da centena de milhar ou centena e os próximos num não são nulos
    // Se o algarismo faz parte da dezena de milhar ou dezena e o próximo algarismo não é nulo
    // Se o algarismo não fazer parte da unidade de milhar (já é escrito quando o mil é avaliado)
    if ((i < 5) && (a != 0))
    {
        if (((i != 0) && (i != 3)) || ((b != 0) || (c != 0)))
        {
            if (((i != 1) && (i != 4)) || ((b != 0) && (a != 1)))
            {
                if (i != 2)
                {
                    printf("e ");
                }
            }
        }
    }
}

//Objetivo: reune todas as funções para escrever um numero por extenso e avalia todos as coordenadas do vetor de algarismos
//Parametros: recebe um vetor com os algarismos de um numero, além do tipo de formatação desejada
//Onde 0 é a formatação padrão e 1 a formatação para cedulas 
//Retorno: nenhum
void escrevePorExtenso(int num[], int tipo)
{
    int j;
    for (j = 0; j < 6; j++)
    {
        if ((j == 0) || (j == 3))
        {
            escreveCent(num[j], num[j + 1], num[j + 2], tipo);
        }
        else if ((j == 2) || (j == 5))
        {
            escreveUni(j, num[j], num[j - 1], num[j - 2], tipo);
            if (j == 2)
                escreveMil(num[0], num[1], num[2], num[3], num[4], num[5]);
        }
        else if ((j == 1) || (j == 4))
        {
            if (escreveDez(num[j], num[j + 1]) == 1)
            {
                j++;
            }
            if (j == 2)
                escreveMil(num[0], num[1], num[2], num[3], num[4], num[5]);
        }
        escreveE(j, num[j], num[j + 1], num[j + 2]);
    }
}

//Objetivo: exibe o relatório sobre os saques realizados no caixa eletronico por cada cliente
//Parametros: 
//Retorno: 
void relatorioSaques(int totalSacadoNaMaquina)
{
    int i, j;
    printf("---------------------------------------------------------------------------------------------------------------------------- \nRelatorio 'Valores sacados' \n----------------------------------------------------------------------------------------------------------------------------");

    printf("---------------------------------------------------------------------------------------------------------------------------- \nR$ %d (", totalSacadoNaMaquina);
    separanum(totalSacadoNaMaquina, algarismos);
    escrevePorExtenso(algarismos, 0);
    printf(")\n----------------------------------------------------------------------------------------------------------------------------");
}

//Objetivo: exibe o relatorio sobre o saldo no caixa
//Parametros: recebe o saldo existente no caixa
//Retorno: nenhum
void relatorioSaldo(int valor)
{
    printf("---------------------------------------------------------------------------------------------------------------------------- \nRelatorio 'Valor do saldo existente ' \n---------------------------------------------------------------------------------------------------------------------------- \nR$ ");
    printf("%d (", valor);
    separanum(valor, algarismos);
    escrevePorExtenso(algarismos, 0);
    if (valor > 1)
    {
        printf("reais");
    }
    else
    {
        printf("real");
    }
    printf(")\n----------------------------------------------------------------------------------------------------------------------------\n");
}

//Objetivo: exibe o relatorio sobre a quantidade de cedulas de cada tipo no caixa
//Parametros: recebe o vetor com o total de cedulas de cada tipo no caixa
//Retorno: nenhum
void relatorioCedulas(int totalCedulas[])
{
    int k;

    printf("---------------------------------------------------------------------------------------------------------------------------- \nRelatorio 'Quantidade de cedulas existentes ' \n----------------------------------------------------------------------------------------------------------------------------\n");

    for (k = 0; k < 8; k++)
    {
        // Enquanto o vetor ainda está sendo analisado escreve a quantidade de cedulas de cada tipo
        // Quando todas já foram escritas, atualiza o total de cedulas contadas
        // Escreve tudo por extenso com a mesma lógica anterior
        printf("Cedula %d %d (", tipoDaCedula[k], quantidadeDeCedulas[k]);
        separanum(totalCedulas[k], algarismos);
        escrevePorExtenso(algarismos, 1);
        if (totalCedulas[k] > 1)
        {
            printf("cedulas");
        }
        else
        {
            printf("cedula");
        }
        printf(")\n--------------------------------------------------------------------------------------------------------------------------\n");
    }
}


int main()
{
    // Saldo
    int saldoExistente = 500 * quantidadeDeCedulas[0] + 150 * quantidadeDeCedulas[1] + 50 * quantidadeDeCedulas[2] + 20 * quantidadeDeCedulas[3] + 10 * quantidadeDeCedulas[4] + 5 * quantidadeDeCedulas[5] + 2 * quantidadeDeCedulas[6] + 1 * quantidadeDeCedulas[7];

    // Variaveis de funcionamento do menu
    int menu = 0, pg = 0, pg1 = 0, mg = 0;
    int i, j, k;

    while (pg == 0)
    {
        printf("\nMenu Principal\n1-Cliente\n2-Saque\n3-Relatorios\n4-Finalizar\nDigite uma opcao: ");
        scanf("%d", &pg);

        switch (pg)
        {
        case 1:
            while (pg == 1)
            {
                printf("\nMenu Cliente\n1-Incluir\n2-Mostrar\n3-Alterar\n4-Excluir\n5-Voltar\nDigite uma opcao: ");
                scanf("%d", &pg);
                switch (pg)
                {
                case 5:
                    printf("\nVoltando para o menu principal...\n");
                    pg = 0;
                    break;
                default:
                    printf("\nValor Invalido!\n");
                    pg = 1;
                    break;
                }
            }
            break;
        case 2:
            while (pg == 2)
            {
                printf("\nSaque\nDigite uma opcao: ");
                scanf("%d", &pg);

                switch (pg)
                {
                case 1:
                    printf("Saque realizado\n");

                    pg = 2;
                    break;

                case 2:

                    printf("\nVoltando para o menu principal...\n");
                    pg = 0;
                    break;

                default:
                    printf("\nValor Invalido!\n");
                    pg = 2;
                    break;
                }
            }
            break;
        case 3:
            while (pg == 3)
            {
                printf("\nMenu Relatorios\n1-Valores sacados\n2-Valor do saldo existente\n3-Quantidade de cedulas existentes\n4-Voltar ao menu principal\nDigite uma opcao: ");
                scanf("%d", &pg);
                switch (pg)
                {
                case 1:
                    relatorioSaques(100);

                    pg = 3;
                    break;
                case 2:
                    // Recebe o saldo total na máquina
                    relatorioSaldo(saldoExistente);

                    pg = 3;
                    break;
                case 3:
                    // Recebe o vetor que armazena a quantidade de cada cedula
                    relatorioCedulas(quantidadeDeCedulas);

                    pg = 3;
                    break;
                case 4:
                    printf("\nVoltando ao Menu Principal...\n");

                    pg = 0;
                    break;
                default:
                    printf("\nValor Invalido!\n");
                    pg = 3;
                    break;
                }
            }
            break;
        case 4:
            printf("\nFim da execucao...");
            return 0;
            break;
        default:
            printf("\nValor invalido!\n");
            pg = 0;
            break;
        }
    }
}
