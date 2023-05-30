#include <stdio.h>

int main()
{
/* 
Objetivos:
-Informar o valor sacado 
-Informar o valor do saldo existente
-Informar a quantidade de cédulas de cada tipo armazenada no caixa
-Abastecer o caixa eletrônico 
As saídas devem estar apresentadas na forma extensa e numérica

Valores recebidos de outras funções:
-Valor do saque 
-Variação no número de cédulas armazenadas
-Saldo ainda presente na máquina

Processamentos:
-Calcular o saldo existente com base no número restante de cédulas no caixa e seus respectivos tipos
-Abastecer
*/
    int operacao, valorSacado, valorSaldo, cedulasExistentes500, cedulasExistentes150, cedulasExistentes50,cedulasExistentes20, cedulasExistentes10, cedulasExistentes5, cedulasExistentes2, cedulasExistentes1;

    puts("Valor do saque:");
    scanf("%d", &valorSacado);
    puts("Numero de cedulas existentes:");
    puts("Cedulas de 500:");
    scanf("%d", &cedulasExistentes500);
    puts("Cedulas de 150:");
    scanf("%d", &cedulasExistentes150);
    puts("Cedulas de 50:");
    scanf("%d", &cedulasExistentes50);
    puts("Cedulas de 20:");
    scanf("%d", &cedulasExistentes20);
    puts("Cedulas de 10:");
    scanf("%d", &cedulasExistentes10);
    puts("Cedulas de 5:");
    scanf("%d", &cedulasExistentes5);
    puts("Cedulas de 2:");
    scanf("%d", &cedulasExistentes2);
    puts("Cedulas de 1:");
    scanf("%d", &cedulasExistentes1);

    valorSaldo = 1*cedulasExistentes1 + 2*cedulasExistentes2 + 5*cedulasExistentes5 + 10*cedulasExistentes10 + 20*cedulasExistentes20 + 50*cedulasExistentes50 + 150*cedulasExistentes150 + 500*cedulasExistentes500; 
    scanf("%d", &operacao);
    //Saidas
    printf("O valor sacado foi: %d\n", valorSacado);
    printf("O valor do saldo restante no caixa eletronico e: %d\n", valorSaldo);
    printf("As cedulas restantes na maquina são:\n");
    printf("Quinhentos: %d\n", cedulasExistentes500);
    printf("Cento e cinquenta: %d\n", cedulasExistentes150);
    printf("Cinquenta: %d\n", cedulasExistentes50);
    printf("Vinte: %d\n", cedulasExistentes20);
    printf("Dez: %d\n", cedulasExistentes10);
    printf("Cinco: %d\n", cedulasExistentes5);
    printf("Dois: %d\n", cedulasExistentes2);
    printf("Um: %d\n", cedulasExistentes1);
    
    //Abastecimento 
    cedulasExistentes500 = 100;
    cedulasExistentes150 = 200;
    cedulasExistentes50 = 400;
    cedulasExistentes20 = 800;
    cedulasExistentes10 = 1600;
    cedulasExistentes5 = 3200;
    cedulasExistentes2 = 6400;
    cedulasExistentes1 = 12800;
    puts("O caixa eletronico foi reabastecido!");

    return 0;
}