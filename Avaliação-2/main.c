// União de todas as funções
#include <stdio.h>

int main()
{
    // Declaração de variaveis
    int menu = 0, pg = 0, pg1 = 0, mg = 0;
    int quantidade, totalCedulas[8], l, tipo;
    // Menu
    while (pg == 0)
    {
        printf("\nMenu Principal");
        printf("\n1- Saque");
        printf("\n2- Gerente");
        printf("\n3- Finalizar");
        printf("\nDigite uma opcao: ");
        scanf("%d", &pg);

        switch (pg)
        {
            case 1:
            {
                printf("\n1");
                pg = 0;
                break;
            }
            case 2:
            {
                while (pg == 2)
                {
                    printf("\nMenu Gerente");
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
                        {
                            printf("\n1");
                            pg = 2;
                            break;
                        }
                        case 2:
                        {
                            printf("\n2");
                            pg = 2;
                            break;
                        }
                        case 3:
                        {
                            printf("\n3");
                            pg = 2;
                            break;
                        }
                        case 4:
                        {
                            totalCedulas[0] = 100;
                            for (l = 1; l < 8; l++)
                            {
                                totalCedulas[l] = totalCedulas[l - 1] * 2;
                            }
                            printf("Menu Abastecer o Caixa Eletronico\n500-Cedulas de 500\n150-Cedulas de 150\n50-Cedulas de 50\n20-Cedulas de 20\n10-Cedulas de 10\n5-Cedulas de 5\n2-Cedulas de 2\n1-Cedulas de 1\n0-Voltar ao Menu Gerente");
                            puts("\nInforme qual tipo de cedula deve ser reabastecida: ");
                            scanf("%d", &tipo);
                            switch (tipo)
                            {
                                case 500:
                                {
                                    printf("Informe a quantidade de cedulas que serao colocadas: ");
                                    scanf("%d", &quantidade);
                                    if ((quantidade + totalCedulas[0] > 100) || (quantidade <= 0))
                                    {
                                        printf("Quantidade invalida!");
                                    }
                                    else
                                    {
                                        totalCedulas[0] += quantidade;
                                    }
                                    break;
                                }
                                case 150:
                                {
                                    printf("Informe a quantidade de cedulas que serao colocadas: ");
                                    scanf("%d", &quantidade);
                                    if ((quantidade + totalCedulas[1] > 200) || (quantidade <= 0))
                                    {
                                        printf("Quantidade invalida!");
                                    }
                                    else
                                    {
                                        totalCedulas[1] += quantidade;
                                    }
                                    break;
                                }
                                case 50:
                                {
                                    printf("Informe a quantidade de cedulas que serao colocadas: ");
                                    scanf("%d", &quantidade);
                                    if ((quantidade + totalCedulas[2] > 400) || (quantidade <= 0))
                                    {
                                        printf("Quantidade invalida!");
                                    }
                                    else
                                    {
                                        totalCedulas[2] += quantidade;
                                    }
                                    break;
                                }
                                case 20:
                                {
                                    printf("Informe a quantidade de cedulas que serao colocadas: ");
                                    scanf("%d", &quantidade);
                                    if ((quantidade + totalCedulas[3] > 800) || (quantidade <= 0))
                                    {
                                        printf("Quantidade invalida!");
                                    }
                                    else
                                    {
                                        totalCedulas[3] += quantidade;
                                    }
                                    break;
                                }
                                case 10:
                                {
                                    printf("Informe a quantidade de cedulas que serao colocadas: ");
                                    scanf("%d", &quantidade);
                                    if ((quantidade + totalCedulas[4] > 1600) || (quantidade <= 0))
                                    {
                                        printf("Quantidade invalida!");
                                    }
                                    else
                                    {
                                        totalCedulas[4] += quantidade;
                                    }
                                    break;
                                }
                                case 5:
                                {
                                    printf("Informe a quantidade de cedulas que serao colocadas: ");
                                    scanf("%d", &quantidade);
                                    if ((quantidade + totalCedulas[5] > 3200) || (quantidade <= 0))
                                    {
                                        printf("Quantidade invalida!");
                                    }
                                    else
                                    {
                                        totalCedulas[5] += quantidade;
                                    }
                                    break;
                                }
                                case 2:
                                {
                                    printf("Informe a quantidade de cedulas que serao colocadas: ");
                                    scanf("%d", &quantidade);
                                    if ((quantidade + totalCedulas[6] > 6400) || (quantidade <= 0))
                                    {
                                        printf("Quantidade invalida!");
                                    }
                                    else
                                    {
                                        totalCedulas[6] += quantidade;
                                    }
                                    break;
                                }
                                case 1:
                                {
                                    printf("Informe a quantidade de cedulas que serao colocadas: ");
                                    scanf("%d", &quantidade);
                                    if ((quantidade + totalCedulas[7] > 12800) || (quantidade <= 0))
                                    {
                                        printf("Quantidade invalida!");
                                    }
                                    else
                                    {
                                        totalCedulas[7] += quantidade;
                                    }
                                    break;
                                }
                                case 0:
                                {
                                    printf("Retornando ao Menu do Gerente...");
                                    break;
                                }
                                default:
                                {
                                    puts("Opcao invalida!");
                                    break;
                                }
                            }
                            break;
                        }
                        case 5:
                        {
                            printf("\nVoltando para o menu principal");
                            pg = 0;
                            break;
                        }
                        default:
                        {
                            printf("\nValor Invalido");
                            pg = 2;
                            break;
                        }
                    }
                }
                break;
            }
            case 3:
            {
                printf("\nFim da execucao.");
                return 0;
                break;
            }
            default:
            {
                printf("\nValor invalido");
                pg = 0;
                break;
            }
        }
    }
    // Validação do CPF

    // Cédulas Fornecidas no Saque

    // Funções do Gerente

    // Saidas

    return 0;
}
