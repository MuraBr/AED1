// Variaveis para funções que envolvam cedulas
const int tipoDaCedula[8] = {
    500, 150, 50, 20, 10, 5, 2, 1};
int quantidadeDeCedulas[8] = {
    100, 200, 400, 800, 1600, 3200, 6400, 12800};

// Variavel global para calculos variados
int algarismos[6];

// Objetivo: separa os algorismos de um número e armazena em um vetor [a, b, c, d, e, f]
// Parametros: recebe um valor e o vetor onde serão guardados os algarismos
// Retorno: os algarismos do valor
void separanum(int valor, int num[])
{
    int i;
    for (i = 5; i >= 0; i--)
    {
        num[i] = valor % 10;
        valor /= 10;
    }
}
//Objetivo: calcula o saldo restante na maquina 
//Parametros: nenhum
//Retorno: saldo na máquina
int calculaSaldo()
{
    int saldo;
    saldo = 500 * quantidadeDeCedulas[0] + 150 * quantidadeDeCedulas[1] + 50 * quantidadeDeCedulas[2] + 20 * quantidadeDeCedulas[3] + 10 * quantidadeDeCedulas[4] + 5 * quantidadeDeCedulas[5] + 2 * quantidadeDeCedulas[6] + 1 * quantidadeDeCedulas[7];
    return saldo;
}
//Objetivo: lê um valor até que ele seja adequado para um saque
//Parametros: nenhum
//retorno: valor do saque
int realizaSaque()
{
    int saque;
    printf("\nDigite o valor a ser sacado: ");
    scanf("%d", &saque);

    // teste do "valorSaque"
    while (saque <= 0)
    {
        printf("\nO valor digitado esta incorreto. Digite novamente: ");
        scanf("%d", &saque);
    }
    return saque;
}
//Objetivo: verifica se é possível realizar o saque desejado com o saldo disponível
//Parametros: o valor do saque
//Retorno: 1 caso exista saldo suficiente e 0 em caso negativo
int checaSaldo(int valorSaque)
{
    int validade = 1;
    // atualiza o valor do saldo existente e verifica se é menr
    if (valorSaque > calculaSaldo())
    {
        printf("Nao existe saldo suficiente no caixa eletronico para conceder o quantia exigida!\n");
        validade = 0;
    }
    return validade;
}
//Objetivo: calcular o número mínimo de cédulas de cada tipo que precisam ser usadas para distribuir uma quantia de dinheiro
//Parametros: o valor do saque e um vetor onde deverá ser armazenado a quantidade minima de cada cédula
//Retorno: 1 se é possível distribuir o dinheiro e 0 caso contrário
int calculaMinimo(int valorSaque, int quantidadeCedulasUsadas[])
{
    int i, j, valorSacado = 0, quantidadeCedulasPre[8];
    i = 0;

    for (j = 0; j < 8; j++)
    {
        quantidadeCedulasPre[j] = quantidadeDeCedulas[j];
        quantidadeCedulasUsadas[j] = 0;
    }
    // definicao da quantidade de cedulas
    while (valorSaque > valorSacado)
    {
        // Começando nas cedulas com maior valor, adiciona cedulas até que um determinado tipo passe o valor do saque ou acabe na maquina
        while ((valorSaque >= valorSacado) && (quantidadeDeCedulas[i] > 0))
        {
            valorSacado += tipoDaCedula[i];
            quantidadeCedulasUsadas[i]++;
            quantidadeDeCedulas[i]--;
        }
        // Se o valor sacado excedeu o valor do saque, retira uma cedula da contagem
        if (((quantidadeDeCedulas[i] != 0)) || ((quantidadeDeCedulas[i] == 0) && (valorSacado > valorSaque)))
        {
            valorSacado -= tipoDaCedula[i];
            quantidadeCedulasUsadas[i]--;
            quantidadeDeCedulas[i]++;
        }
        i++;
        // Caso o valor sacado nao alcance o valor do saque, após todas os espaços do vetor foram avaliados, o saque é cancelado
        if ((i == 8) && (valorSacado < valorSaque))
        {
            valorSacado = valorSaque + 1;
            printf("\nNao foi possivel realizar o saque com as cedulas disponiveis!");
            // Reseta as cedulas que foram retiradas
            for (i = 0; i < 8; i++)
            {
                quantidadeDeCedulas[i] = quantidadeCedulasPre[i];
            }
            return 0;
        }
    }
    return 1;
}
//Objetivo: escreve o resultado final do saque mostando como o dinheiro será distribuído
//Parametros: o valor do saque e o vetor onde foram armazenadas a quantia de cada cédula que será usada
//Retorno: nenhum
void escreveResultadoSaque(int valorSaque, int quantidadeCedulasUsadas[])
{
    int i;
    printf("O saque de ");
    separanum(valorSaque, algarismos);
    escrevePorExtenso(algarismos, 0);
    printf("foi realizado com sucesso!\nO dinheiro sera distribuido em:\n");
    for (i = 0; i < 8; i++)
    {
        if (quantidadeCedulasUsadas[i] != 0)
        {
            printf("%d ", quantidadeCedulasUsadas[i]);
            // Quantiica as cedulas de acordo
            if (quantidadeCedulasUsadas[i] == 1)
            {
                printf("cedula ");
            }
            else
            {
                printf("cedulas ");
            }
            printf("de %d R$\n", tipoDaCedula[i]);
        }
    }
}



