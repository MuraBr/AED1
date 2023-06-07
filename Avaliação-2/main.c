// União de todas as funções
#include <stdio.h>

int main()
{
    // Declaração de variaveis
    int menu, pg, saque, saldoExistente, valorTotalSacado, k, quantidade, totalCedulas[8], l, tipo, num, j, algarismos[6];
    // Inicializações
    const int tipoDaCedula[8] = {
        500, 150, 50, 20, 10, 5, 2, 1};
    const char unidades[10][12] = {
        "", "Um ", "Dois ", "Tres ", "Quatro ", "Cinco ", "Seis ", "Sete ", "Oito ", "Nove "};
    const char dezenasEspeciais[10][12] = {
        "Dez ", "Onze ", "Doze ", "Treze ", "Quatorze ", "Quinze ", "Dezesseis ", "Dezessete ", "Dezoito ", "Dezenove "};
    const char dezenas[10][12] = {
        "", "", "Vinte ", "Trinta ", "Quarenta ", "Cinquenta ", "Sessenta ", "Setenta ", "Oitenta ", "Noventa "};
    const char centenas[10][14] = {
        "", "", "Duzentos ", "Trezentos ", "Quatrocentos ", "Quinhentos ", "Seiscentos ", "Setescentos ", "Oitocentos ", "Novecentos "};
    valorTotalSacado = 0;
    menu = 0;
    pg = 0;

    totalCedulas[0] = 100;
    for (l = 1; l < 8; l++)
        totalCedulas[l] = totalCedulas[l - 1] * 2;

    // Menu
    while (pg == 0)
    {
        printf("\n-----Menu Principal-----");
        printf("\n1- Saque");
        printf("\n2- Gerente");
        printf("\n3- Finalizar");
        printf("\nDigite uma opcao: ");
        scanf("%d", &pg);

        switch (pg)
        {
        case 1:
            printf("----Saque-----");

            pg = 0;
            break;
        case 2:
            while (pg == 2)
            {
                printf("\n-----Menu Gerente-----");
                printf("\n1- Valor total sacado");
                printf("\n2- Valor do saldo existente");
                printf("\n3- Quantidade de cedulas existentes");
                printf("\n4- Abastecer o caixa eletronico");
                printf("\n5- Voltar ao menu principal");
                printf("\nDigite uma opcao: ");
                scanf("%d", &pg);

                switch (pg)
                {
                case 1:
                    printf("\n-----Valor total sacado-----");
                    num = valorTotalSacado;
                    for (j = 5; j >= 0; j--)
                    {
                        algarismos[j] = num % 10;
                        num /= 10;
                    }
                    printf("\nValor total sacado: ");
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
                    printf("(%d) ", saldoExistente);
                    if (saldoExistente == 1)
                    {
                        printf("real\n\n");
                    }
                    else
                    {
                        printf("reais\n\n");
                    }
                    pg = 2;
                    break;
                case 2:
                    printf("\n-----Valor do saldo existente-----");
                    saldoExistente = 500 * totalCedulas[0] + 150 * totalCedulas[1] + 50 * totalCedulas[2] + 20 * totalCedulas[3] + 10 * totalCedulas[4] + 5 * totalCedulas[5] + 2 * totalCedulas[6] + 1 * totalCedulas[7];
                    num = saldoExistente;
                    for (j = 5; j >= 0; j--)
                    {
                        algarismos[j] = num % 10;
                        num /= 10;
                    }
                    printf("\nSaldo existente: ");
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
                    printf("(%d) ", saldoExistente);
                    if (saldoExistente == 1)
                    {
                        printf("real\n\n");
                    }
                    else
                    {
                        printf("reais\n\n");
                    }
                    pg = 2;
                    break;
                case 3:
                    printf("\n-----Quantidade de cedulas existentes-----");
                    for (k = 0; k < 8; k++)
                    {
                        printf("\n%d: restam ", tipoDaCedula[k]);
                        num = totalCedulas[k];
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
                        printf("(%d) ", totalCedulas[k]);
                        if (totalCedulas[k] == 1)
                        {
                            printf("cedula ");
                        }
                        else
                        {
                            printf("cedulas ");
                        }
                        printf("de %d", tipoDaCedula[k]);
                    }
                    pg = 2;
                    break;
                case 4:
                    do
                    {
                        printf("\nMenu Abastecer o Caixa Eletronico\n500-Cedulas de 500\n150-Cedulas de 150\n50-Cedulas de 50\n20-Cedulas de 20\n10-Cedulas de 10\n5-Cedulas de 5\n2-Cedulas de 2\n1-Cedulas de 1\n0-Voltar ao Menu Gerente");
                        printf("\nSelecione uma opcao: ");
                        scanf("%d", &tipo);
                        switch (tipo)
                        {
                        case 500:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[0] > 100) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[0] += quantidade;
                            }
                            break;
                        case 150:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[1] > 200) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[1] += quantidade;
                            }
                            break;
                        case 50:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[2] > 400) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[2] += quantidade;
                            }
                            break;
                        case 20:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[3] > 800) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[3] += quantidade;
                            }
                            break;
                        case 10:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[4] > 1600) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[4] += quantidade;
                            }
                            break;
                        case 5:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[5] > 3200) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[5] += quantidade;
                            }
                            break;
                        case 2:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[6] > 6400) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[6] += quantidade;
                            }
                            break;
                        case 1:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[7] > 12800) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[7] += quantidade;
                            }
                            break;
                        case 0:
                            printf("\nRetornando ao Menu do Gerente...");
                            break;
                        default:
                            printf("\nOpcao invalida!");
                            break;
                        }
                    } while (tipo != 0);
                    pg = 2;
                    break;
                case 5:
                    printf("\nVoltando para o menu principal");
                    pg = 0;
                    break;
                default:
                    printf("\nValor Invalido");
                    pg = 2;
                    break;
                }
            }
            break;
        case 3:
            printf("\nFim da execucao.");
            return 0;
            break;
        default:
            printf("\nValor invalido");
            pg = 0;
            break;
        }
    }

    // Funções do Gerente

    // Saidas
}
