#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int calculocpf=0;
    int verifica1=0;
    int verifica2;
    int teste=0;
    int valicont=9;
    int pot=0;
    long int pote10=10;
    int cont=10;
    int cpf1;
    int cpf2;
    int i = 0;
    int vetor[11];
    //pede para o usuario fornecer o cpf, primeiro os 9 primeors digiros depois os dois ultimos
    printf("Forneça o cpf, digite os 9 primeiros digitos");
    scanf("%d",&cpf1);
    printf("Forneça o cpf, digite os 2 ultimos digitos");
    scanf("%d",&cpf2);
    //coloca os valores inseridos anteriormente dentro de um vetor
    for(i=0;i<9; i++){
        //variavel que sera a potencia, começa no 9 e vai diminuindo
        valicont=valicont-1;
        //resultado da potencia de 10
        pot= pow(pote10,valicont);
        //if para garantir que o vvalor da potencia vai estar certo, pois por algum motivo aluns estavam vindo com valor -1
        if(pot%2==1){
            pot=pot+1;
        }
        //if para garantir a potencia certa
        if(pot==2){
            pot=pot-1;
        }
    }
    //inserindo os dois ultimos digitos no vetor
    vetor[9]=cpf2/10%10;
    vetor[10]=cpf2%10;
    //for para fazer a valicação do primeiro numero verificador do cpf
    for(i=0;i<9; i++){
            //insere na variavel teste o valor respectivo do vetor
        teste= vetor[i];
        //faz o calculo
        calculocpf= calculocpf+(teste*cont);
        cont=cont-1;
    }
    //pega o valor total to calculo e mega o resto da divisão por 11
    verifica1=calculocpf%11;
    //verifica se o resto é maior ou igual a 0, para poder subtrair 11
    if(verifica1>=2){
        verifica1=11-verifica1;
    }
    //caso não seja o valor verificador é 0
    else{
        verifica1=0;
    }
    //for para fazer a valicação do segundo numero verificador do cpf
    cont=11;
    calculocpf=0;
    for(i=0;i<10; i++){
        teste = vetor[i];
        //if para fazer o calculo com o valor verificador descoberto anteriormente, so entra aqui na ultima repetição
        if(i==9 && vetor[9]!= verifica1){
           calculocpf = calculocpf+(verifica1*cont);
        }
        //calculo normal de verificação
        else{
          calculocpf=calculocpf+(teste*cont);
        }
        cont=cont-1;
    }
    //pega o valor total to calculo e mega o resto da divisão por 11
    verifica2= calculocpf%11;
    //verifica se o resto é maior ou igual a 0, para poder subtrair 11
    if(verifica2>=2){
        verifica2=11-verifica2;
    }
    //caso não seja o valor verificador é 0
    else{
        verifica2=0;
    }
    //verifica se os numeros de validação são iguais aos descobertos pelo calculo
    if(verifica1==vetor[9] && verifica2==vetor[10]){
        //if para ter o 0 do cpf no printf
        if(vetor[0]==0){
            printf("o cpf 0%d%d eh valido",cpf1,cpf2);
        }
        //caso não precise do 0, aqui é o print normal
        else{
            printf("o cpf %d%d eh valido",cpf1,cpf2);
        }
    }
    else{
            //if para ter o 0 do cpf no printf
        if(vetor[0]==0){
            printf("o cpf 0%d%d não eh valido",cpf1,cpf2);
        }
    //caso não precise do 0, aqui é o print normal
        else{
            printf("o cpf %d%d não eh valido",cpf1,cpf2);
        }

    }
}
