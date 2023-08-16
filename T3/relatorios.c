#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
const int tipoDaCedula[8] = {
        500, 150, 50, 20, 10, 5, 2, 1};
int cedulas[8]  = {
        100, 200, 400, 800, 1600, 3200, 6400, 12800};
int algarismos[6], num;


void escreveCent(int a, int b, int c)
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
        printf(centenas[a]);
    }
}

void escreveUni(int i, int c, int b, int a)
{
    if (i != 2)
    {
        printf(unidades[c]);
    }
    else
    {
        if ((c != 1) || ((b != 0) || (a != 0)))
            printf(unidades[c]);
        // Utiliza o próprio algarismo para identificar a saída por extenso no vetor das unidades
    }
}
int escreveDez(int b, int c)
{
    if (b == 1)
    {
        // Caso o algarismo na dezena for 1, avança em um casa e avalia a unidade
        printf(dezenasEspeciais[c]);
        return 1;
        // Utiliza o próprio algarismo para identificar a saída por extenso no vetor das dezenas especiais
    }
    else
    {
        // Utiliza o próprio algarismo para identificar a saída por extenso no vetor das dezenas
        printf(dezenas[b]);
        return 0;
    }
}

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

void escreveE(int i, int a, int b, int c)
{
    // Avalia quando escrever "e'"
    // Escreve apenas se o algarismo analisado não for nulo ou da casa da unidade
    // Se o algarismo faz parte da centena de milhar ou centena e os próximos algarismos não são nulos
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

void escrevePorExtenso(int algarismos[])
{
    int j;
    for (j = 0; j < 6; j++)
    {
        if ((j == 0) || (j == 3))
        {
            escreveCent(algarismos[j], algarismos[j + 1], algarismos[j + 2]);
        }
        else if ((j == 2) || (j == 5))
        {
            escreveUni(j, algarismos[j], algarismos[j - 1], algarismos[j - 2]);
            if (j == 2)
                escreveMil(algarismos[0], algarismos[1], algarismos[2], algarismos[3], algarismos[4], algarismos[5]);
        }
        else if ((j == 1) || (j == 4))
        {
            if (escreveDez(algarismos[j], algarismos[j + 1]) == 1)
            {
                j++;
            }
            if (j == 2)
                escreveMil(algarismos[0], algarismos[1], algarismos[2], algarismos[3], algarismos[4], algarismos[5]);
        }
        escreveE(j, algarismos[j], algarismos[j + 1], algarismos[j + 2]);
    }
}

void separaAlgarismos(int num, int algarismos[]){
    int i;
    for (i = 5; i >= 0; i--)
    {
        algarismos[i] = num % 10;
        num /= 10;
    }
}

void relatorioSaque(){
    printf("\n-----Valor total sacado-----");
    

}

void relatorioSaldo(int valor){
    printf("---------------------------------------------------------------------------------------------------------------------------- \nRelatório 'Valor do saldo existente ' \n---------------------------------------------------------------------------------------------------------------------------- \nR$ ");
    printf("%d (", valor);
    separaAlgarismos(valor, algarismos);
    escrevePorExtenso(algarismos);
    if(valor > 1){
        printf("reais");
    }
    else{
        printf("real");
    }
    printf(")\n----------------------------------------------------------------------------------------------------------------------------\n");

}


void relatorioCedulas(int totalCedulas[]){
    int k;

    printf("---------------------------------------------------------------------------------------------------------------------------- \nRelatório 'Quantidade de cédulas existentes ' \n----------------------------------------------------------------------------------------------------------------------------\n");

    for (k = 0; k < 8; k++)
    {
        //Enquanto o vetor ainda está sendo analisado escreve a quantidade de cedulas de cada tipo
        //Quando todas já foram escritas, atualiza o total de cedulas contadas
        //Escreve tudo por extenso com a mesma lógica anterior
        printf("Cedula %d quantidade%d (", tipoDaCedula[k], k+1);
        separaAlgarismos(totalCedulas[k], algarismos);
        escrevePorExtenso(algarismos);
        if(totalCedulas[k] > 1){
            printf("cedulas");
        }
        else{
            printf("cedula");
        }
        printf(")\n--------------------------------------------------------------------------------------------------------------------------\n");
    }
}

int main(){
    int saldo;
    scanf("%d", &saldo);

    relatorioSaldo(saldo);

    relatorioCedulas(cedulas);
    return 0;
}