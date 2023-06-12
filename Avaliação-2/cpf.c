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
    char vetor[11];
    int i = 0;
    //int vetor[11];
    //pede para o usuario fornecer o cpf, primeiro os 9 primeors digiros depois os dois ultimos
    printf("Forneca o cpf: ");
    scanf("%s",&vetor);
    //for para fazer a valicação do primeiro numero verificador do cpf
    for(i=0;i<9; i++){
            //insere na variavel teste o valor respectivo do vetor
        teste= vetor[i] - '0';
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
        teste = vetor[i] - '0';
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
    if(verifica1==vetor[9]-'0' && verifica2==vetor[10]-'0'){
            printf("o cpf %s e valido",vetor);
    }
    else{
        printf("o cpf %s nao e valido",vetor);
    }
}
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
    char vetor[11];
    int i = 0;
    //pede para o usuario fornecer o cpf
    printf("Forneca o cpf: ");
    scanf("%s",&vetor);
    //for para fazer a valicação do primeiro numero verificador do cpf
    for(i=0;i<9; i++){
            //insere na variavel teste o valor respectivo do vetor
        teste= vetor[i] - '0';
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
        teste = vetor[i] - '0';
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
    if(verifica1==vetor[9]-'0' && verifica2==vetor[10]-'0'){
            printf("o cpf %s e valido",vetor);
    }
    else{
        printf("o cpf %s nao e valido",vetor);
    }
}
