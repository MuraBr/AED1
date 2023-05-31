#include <stdio.h>
#include <math.h>

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
    int operacao, valorSacado, valorSaldo, cedulasExistentes[8], k, j;
    
    

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

    valorSaldo; 
    scanf("%d", &operacao);
    //Saidas
    printf("O valor sacado foi: %d\n", valorSacado);
    printf("O valor do saldo restante no caixa eletronico e: %d\n", valorSaldo);
    printf("As cedulas restantes na maquina são:\n");
    printf("Quinhentos: %d\n", cedulasExistentes[0]);
    printf("Cento e cinquenta: %d\n", cedulasExistentes[1]);
    printf("Cinquenta: %d\n", cedulasExistentes[2]);
    printf("Vinte: %d\n", cedulasExistentes[3]);
    printf("Dez: %d\n", cedulasExistentes[4]);
    printf("Cinco: %d\n", cedulasExistentes[5]);
    printf("Dois: %d\n", cedulasExistentes[6]);
    printf("Um: %d\n", cedulasExistentes[7]);
    
    //Abastecimento 
    j = 1;
    for(k = 0; k<8; k++){
        cedulasExistentes[k] = 200*k;
        j *= 2;
    }
    puts("\nO caixa eletronico foi reabastecido!");

    return 0;
}
