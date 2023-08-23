#include <stdio.h>

int main()
{
    int pg = 0;

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
                        case 1:

                            break;
                        case 2:

                            break;
                        case 3:

                            break;
                        case 4:

                            break;
                        case 5:
                            printf("\nVoltando para o menu principal\n");
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
                
                break;
            case 3:
                while (pg == 3)
                {
                    printf("\nMenu Relatorios\n1-Valores sacados\n2-Valor do saldo existente\n3-Quantidade de cedulas existentes\n4-Voltar ao menu principal\nDigite uma opcao: ");
                    scanf("%d", &pg);
                    switch (pg)
                    {
                        case 1:
                            
                            pg = 3;
                            break;
                        case 2:
                            
                            pg = 3;
                            break;
                        case 3:
                            
                            pg = 3;
                            break;
                        case 4:
                            
                            pg = 0;
                            break;
                        default:
                            
                            pg = 3;
                            break;
                    }
                }
                break;
            case 4:
                printf("\nFim da execucao.");
                return 0;
                break;
            default:
                printf("\nValor invalido!\n");
                pg = 0;
                break;
        }
    }
}
