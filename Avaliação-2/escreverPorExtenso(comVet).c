#include <stdio.h>
int main()
{

    int num, j, algarismos[6];
    const char unidades[10][12] = {
        "", "Um ", "Dois ", "Tres ", "Quatro ", "Cinco ", "Seis ", "Sete ", "Oito ", "Nove "};
    const char dezenasEspeciais[10][12] = {
        "Dez ", "Onze ", "Doze ", "Treze ", "Quatorze ", "Quinze ", "Dezesseis ", "Dezessete ", "Dezoito ", "Dezenove "};
    const char dezenas[10][12] = {
        "", "", "Vinte ", "Trinta ", "Quarenta ", "Cinquenta ", "Sessenta ", "Setenta ", "Oitenta ", "Noventa "};
    const char centenas[10][14] = {
        "", "", "Duzentos ", "Trezentos ", "Quatrocentos ", "Quinhentos ", "Seiscentos ", "Setescentos ", "Oitocentos ", "Novecentos "};

    puts("Escreva um numero: ");
    scanf("%d", &num);

    for (j = 5; j >= 0; j--)
    {
        algarismos[j] = num % 10;
        num /= 10;
    }

    for (j = 0; j < 6; j++)
    {
        switch (j)
        {
        case 0:
            if (algarismos[j] == 1)
            {
                if ((algarismos[j + 1] == 0) && (algarismos[j + 2] == 0))
                {
                    printf("Cem ");
                }
                else
                {
                    printf("Cento ");
                }
            }
            else
            {
                printf(centenas[algarismos[j]]);
            }
            break;

        case 1:
            if (algarismos[j] == 1)
            {
                j++;
                printf(dezenasEspeciais[algarismos[j]]);
            }
            else
            {
                printf(dezenas[algarismos[j]]);
            }
            break;

        case 2:
            printf(unidades[algarismos[j]]);
            break;

        case 3:
            if (algarismos[j] == 1)
            {
                if ((algarismos[j + 1] == 0) && (algarismos[j + 2] == 0))
                {
                    printf("Cem ");
                }
                else
                {
                    printf("Cento ");
                }
            }
            else
            {
                printf(centenas[algarismos[j]]);
            }
            break;

        case 4:
            if (algarismos[j] == 1)
            {
                j++;
                printf(dezenasEspeciais[algarismos[j]]);
            }
            else
            {
                printf(dezenas[algarismos[j]]);
            }
            break;

        case 5:
            printf(unidades[algarismos[j]]);
            break;

        default:
            break;
        }
        if ((j == 2) && ((algarismos[0] != 0) || (algarismos[1] != 0) || (algarismos[2] != 0)))
        {
            if (((algarismos[3] == 0) && (algarismos[4] == 0) && (algarismos[5] == 0)) || ((algarismos[3] != 0) && ((algarismos[4] != 0) || (algarismos[5] != 0))))
            {
                printf("Mil ");
            }
            else
            {
                printf("Mil e ");
            }
        }

        if ((j != 5) && (algarismos[j] != 0))
        {
            if (((j != 0) && (j != 3)) || ((algarismos[j + 1] != 0) || (algarismos[j + 2] != 0)))
            {
                if (((j != 1) && (j != 4)) || ((algarismos[j + 1] != 0) && (algarismos[j] != 1)))
                {
                    if (j != 2)
                    {
                        printf("e ");
                    }
                }
            }
        }
    }

    return 0;
}
