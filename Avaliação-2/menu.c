#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int menu=0, pg=0, pg1=0, mg=0;

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
                            printf("\n4");
                            pg = 2;
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
}