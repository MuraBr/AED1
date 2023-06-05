#include <stdio.h>

int main()
{
    int num, algarismos[6], i;
    scanf("%d", &num);

    //Lógica para armazenar os algarismos do numero no vetor
    for (i = 5; i >= 0; i--)
    {
        algarismos[i] = num % 10;
        num /= 10;
    }

    //Lógica para verificar cada índice do vetor e printar o número por extenso de acordo
    for (i = 0; i < 6; i++)
    {
        switch (algarismos[i])
        {
        case 0:
            break;
        case 1:
            if ((i == 0) || (i == 3))
            {
                if ((algarismos[i + 1] == 0) && (algarismos[i + 2] == 0))
                {
                    printf("Cem ");
                }
                else
                {
                    printf("Cento ");
                }
            }
            else if ((i == 1) || (i == 4))
            {
                i++;
                switch (algarismos[i])
                {
                case 0:
                    printf("Dez ");
                    break;

                case 1:
                    printf("Onze ");
                    break;

                case 2:
                    printf("Doze ");
                    break;

                case 3:
                    printf("Treze ");
                    break;

                case 4:
                    printf("Quatorze ");
                    break;

                case 5:
                    printf("Quinze ");
                    break;

                case 6:
                    printf("Dezesseis ");
                    break;

                case 7:
                    printf("Dezoito ");
                    break;

                case 8:
                    printf("Dezoito ");
                    break;

                case 9:
                    printf("Dezenove ");
                    break;
                }
            }
            else
            {
                if (((i == 2) && (algarismos[0] != 0) || (algarismos[1] != 0)) || (i == 5))
                {
                    printf("Um ");
                }
            }
            break;
        case 2:
            if ((i == 0) || (i == 3))
            {
                printf("duzentos ");
                i;
            }
            else if ((i == 1) || (i == 4))
            {
                printf("vinte ");
            }
            else
            {
                printf("dois ");
            }
            break;
        case 3:
            //Continuação para os outros números é semlhante ao case 2
            break;
        default:
            break;
        }
        //Lógica para as conjunções "e" ou "mil"
        if ((i == 2) && ((algarismos[0] != 0)||(algarismos[1]!= 0)||(algarismos[2] != 0)))
        {
            if (((algarismos[3] == 0) && (algarismos[4] == 0)&&(algarismos[5] ==0)) || ((algarismos[3] != 0)&&((algarismos[4] != 0)||(algarismos[5] != 0))))
            {
                printf("Mil ");
            }
            else
            {
                printf("Mil e ");
            }
        }

        if ((i != 5) && (algarismos[i] != 0))
        {
            if (((i != 0) && (i != 3)) || ((algarismos[i + 1] != 0) || (algarismos[i + 2] != 0)))
            {
                if (((i != 1) && (i != 4)) || ((algarismos[i + 1] != 0) && (algarismos[i] != 1)))
                {
                    if (i != 2)
                    {
                        printf("e ");
                    }
                }
            }
        }
    }

    return 0;
}