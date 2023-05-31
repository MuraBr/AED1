#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int menu=0, pg=0;

    while (pg == 0)
    {
        printf("\nmMenu Principal");
        printf("\n1- Saque");
        printf("\n2- Gerente");
        printf("\n3- Finalizar");
        printf("\nDigite uma opcao: ");
        scanf("%d", &menu);

        if ((menu<0) || (menu > 3))
        {
            printf("\nValor Invalido");
            pg = 0;
        }
        if ((menu > 0) || (menu <= 3))
        {
            switch (menu)
            {
                case 0:
                {
                    printf("Voltando para o menu");
                    pg = 0;
                    break;
                }
                case 1:
                {
                    printf("1");
                    pg = 0;
                    break;
                }
                case 2:
                {
                    printf("2");
                    pg = 0;
                    break;
                }
                case 3:
                {
                    printf("3, fim da execucao.");
                    return 0;
                    break;
                }
            }
        }
    }
}
