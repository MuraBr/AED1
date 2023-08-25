// Código real oficial 2.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variaveis para funções que envolvam cedulas
const int tipoDaCedula[8] = {
    500, 150, 50, 20, 10, 5, 2, 1};
int quantidadeDeCedulas[8] = {
    100, 200, 400, 800, 1600, 3200, 6400, 12800};

// Variáveis para manutenção de clientes
int numClientes = 0;

// Variavel global para calculos variados
int algarismos[6];

// Constantes para escrever por extenso
const char unidades[10][12] = {
    "", "Um ", "Dois ", "Tres ", "Quatro ", "Cinco ", "Seis ", "Sete ", "Oito ", "Nove "};
const char dezenasEspeciais[10][12] = {
    "Dez ", "Onze ", "Doze ", "Treze ", "Quatorze ", "Quinze ", "Dezesseis ", "Dezessete ", "Dezoito ", "Dezenove "};
const char dezenas[10][12] = {
    "", "", "Vinte ", "Trinta ", "Quarenta ", "Cinquenta ", "Sessenta ", "Setenta ", "Oitenta ", "Noventa "};
const char centenas[10][14] = {
    "", "", "Duzentos ", "Trezentos ", "Quatrocentos ", "Quinhentos ", "Seiscentos ", "Setescentos ", "Oitocentos ", "Novecentos "};
const char unidadesCedula[10][12] = {
    "", "Uma ", "Duas ", "Tres ", "Quatro ", "Cinco ", "Seis ", "Sete ", "Oito ", "Nove "};
const char centenasCedulas[10][14] = {
    "", "", "Duzentas ", "Trezentas ", "Quatrocentas ", "Quinhentas ", "Seiscentas ", "Setescentas ", "Oitocentas ", "Novecentas "};

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

// Objetivo: escreve por extenso as casas de centena
// Parametros: recebe o algarismo da centena(a), dezena(b) e unidade(c) de um numero, além da formatação desejada
// Onde 0 é a formatação padrão e 1 a formatação para cedulas
// Retorno: nenhum
void escreveCent(int a, int b, int c, int tipo)
{
    if (a == 1)
    {
        if ((b == 0) && (c == 0))
        {
            // Escreve cem se forem vazias e cento se existir algum algarismo não nulo
            printf("Cem ");
        }
        else
        {
            printf("Cento ");
        }
    }
    else
    {
        // Utiliza o próprio algarismo para identificar a saída por extenso no vetor das centenas
        if (tipo != 1)
        {
            printf(centenas[a]);
        }
        else
        {
            printf(centenasCedulas[a]);
        }
    }
}

// Objetivo: escreve por extenso as casas de unidade de um numero
// Parametros: recebe o algarismo da centena(a), dezena(b) e unidade(c) de um numero, a formatação desejada
// Onde 0 é a formatação padrão e 1 a formatação para cedulas
// Além da coordenada i do vetor de algarismos
// Retorno: nenhum
void escreveUni(int i, int c, int b, int a, int tipo)
{
    if (i != 2)
    {
        if (tipo != 1)
        {
            printf(unidades[c]);
        }
        else
        {
            printf(unidadesCedula[c]);
        }
    }
    else
    {
        if ((c != 1) || ((b != 0) || (a != 0)))
        {
            if (tipo != 1)
            {
                printf(unidades[c]);
            }
            else
            {
                printf(unidadesCedula[c]);
            }
        }
        // Utiliza o próprio algarismo para identificar a saída por extenso no vetor das unidades
    }
}

// Objetivo: escreve por extenso as casas de dezena de um numero
// Parametros: recebe o algarismo da dezena(b) e unidade(c) de um numero
// Retorno: retorna 1 se o modulo utilizou as dezenas especiais e 0 se usou as dezenas normais
int escreveDez(int b, int c)
{
    if (b == 1)
    {
        // Se o numero é 1, então está entre 10 e 19, por isso utiliza as dezenas especiais
        printf(dezenasEspeciais[c]);
        return 1;
        // Utiliza o próprio algarismo para identificar a saída por extenso no vetor
    }
    else
    {
        // Utiliza o próprio algarismo para identificar a saída por extenso no vetor das dezenas
        printf(dezenas[b]);
        return 0;
    }
}

// Objetivo: testa e escreve mil nos lugares corretos
// Parametros: recebe todas as casas do numero com os algarismos armazenados no vetor [a, b, c, d, e, f]
// Retorno: nenhum
void escreveMil(int a, int b, int c, int d, int e, int f)
{
    // Escreve mil quando pelo menos um algarismo antes da casa da centena não for nulo
    if ((a != 0) || (b != 0) || (c != 0))
    {
        // Escreve mil e apenas se houver numeros não nulos após a unidade de milhar ou se a centena for o único algarismo não nulo no resto do número
        if (((d == 0) && (e == 0) && (f == 0)) || ((d != 0) && ((e != 0) || (f != 0))))
        {
            printf("Mil ");
        }
        else
        {
            printf("Mil e ");
        }
    }
}

// Objetivo: testa e escreve "e" nos momentos adequados
// Parametros: recebe o algarismo da centena(a), dezena(b) e unidade(c) de um numero
// Além da coordenada i do vetor que está sendo analisada
// Retorno: nenhum
void escreveE(int i, int a, int b, int c)
{
    // Avalia quando escrever "e'"
    // Escreve apenas se o algarismo analisado não for nulo ou da casa da unidade
    // Se o algarismo faz parte da centena de milhar ou centena e os próximos num não são nulos
    // Se o algarismo faz parte da dezena de milhar ou dezena e o próximo algarismo não é nulo
    // Se o algarismo não fazer parte da unidade de milhar (já é escrito quando o mil é avaliado)
    if ((i < 5) && (a != 0))
    {
        if (((i != 0) && (i != 3)) || ((b != 0) || (c != 0)))
        {
            if (((i != 1) && (i != 4)) || ((b != 0) && (a != 1)))
            {
                if (i != 2)
                {
                    printf("e ");
                }
            }
        }
    }
}

// Objetivo: reune todas as funções para escrever um numero por extenso e avalia todos as coordenadas do vetor de algarismos
// Parametros: recebe um vetor com os algarismos de um numero, além do tipo de formatação desejada
// Onde 0 é a formatação padrão e 1 a formatação para cedulas
// Retorno: nenhum
void escrevePorExtenso(int num[], int tipo)
{
    int j;
    for (j = 0; j < 6; j++)
    {
        if ((j == 0) || (j == 3))
        {
            escreveCent(num[j], num[j + 1], num[j + 2], tipo);
        }
        else if ((j == 2) || (j == 5))
        {
            escreveUni(j, num[j], num[j - 1], num[j - 2], tipo);
            if (j == 2)
                escreveMil(num[0], num[1], num[2], num[3], num[4], num[5]);
        }
        else if ((j == 1) || (j == 4))
        {
            if (escreveDez(num[j], num[j + 1]) == 1)
            {
                j++;
            }
            if (j == 2)
                escreveMil(num[0], num[1], num[2], num[3], num[4], num[5]);
        }
        escreveE(j, num[j], num[j + 1], num[j + 2]);
    }
    if (tipo == 0)
    {
        if ((num[5] > 1) || (num[4] > 0) || (num[3] > 0) || (num[2] > 0) || (num[1] > 0) || (num[0] > 0))
        {
            printf("reais");
        }
        else
        {
            printf("real");
        }
    }
}
// Objetivo: calcula o saldo restante na maquina
// Parametros: nenhum
// Retorno: saldo na máquina
int calculaSaldo()
{
    int saldo;
    saldo = 500 * quantidadeDeCedulas[0] + 150 * quantidadeDeCedulas[1] + 50 * quantidadeDeCedulas[2] + 20 * quantidadeDeCedulas[3] + 10 * quantidadeDeCedulas[4] + 5 * quantidadeDeCedulas[5] + 2 * quantidadeDeCedulas[6] + 1 * quantidadeDeCedulas[7];
    return saldo;
}
// Objetivo: lê um valor até que ele seja adequado para um saque
// Parametros: nenhum
// retorno: valor do saque
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
// Objetivo: verifica se é possível realizar o saque desejado com o saldo disponível
// Parametros: o valor do saque
// Retorno: 1 caso exista saldo suficiente e 0 em caso negativo
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
// Objetivo: calcular o número mínimo de cédulas de cada tipo que precisam ser usadas para distribuir uma quantia de dinheiro
// Parametros: o valor do saque e um vetor onde deverá ser armazenado a quantidade minima de cada cédula
// Retorno: 1 se é possível distribuir o dinheiro e 0 caso contrário
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
// Objetivo: escreve o resultado final do saque mostando como o dinheiro será distribuído
// Parametros: o valor do saque e o vetor onde foram armazenadas a quantia de cada cédula que será usada
// Retorno: nenhum
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
// Objetivo: exibe o relatório sobre os saques realizados no caixa eletronico por cada cliente
// Parametros:
// Retorno:
void relatorioSaques()
{
    int i, j, totalSacadoNaMaquina;
    totalSacadoNaMaquina = 173600 - calculaSaldo();
    printf("---------------------------------------------------------------------------------------------------------------------------- \nRelatorio 'Valores sacados' \n----------------------------------------------------------------------------------------------------------------------------");

    printf("---------------------------------------------------------------------------------------------------------------------------- \nR$ %d (", totalSacadoNaMaquina);
    separanum(totalSacadoNaMaquina, algarismos);
    escrevePorExtenso(algarismos, 0);
    printf(")\n----------------------------------------------------------------------------------------------------------------------------");
}

// Objetivo: exibe o relatorio sobre o saldo no caixa
// Parametros: nenhum
// Retorno: nenhum
void relatorioSaldo()
{
    printf("---------------------------------------------------------------------------------------------------------------------------- \nRelatorio 'Valor do saldo existente ' \n---------------------------------------------------------------------------------------------------------------------------- \nR$ ");
    separanum(calculaSaldo(), algarismos);
    escrevePorExtenso(algarismos, 0);
    printf(")\n----------------------------------------------------------------------------------------------------------------------------\n");
}

// Objetivo: exibe o relatorio sobre a quantidade de cedulas de cada tipo no caixa
// Parametros: nenhum
// Retorno: nenhum
void relatorioCedulas()
{
    int k;

    printf("---------------------------------------------------------------------------------------------------------------------------- \nRelatorio 'Quantidade de cedulas existentes ' \n----------------------------------------------------------------------------------------------------------------------------\n");
    for (k = 0; k < 8; k++)
    {
        // Enquanto o vetor ainda está sendo analisado escreve a quantidade de cedulas de cada tipo
        // Quando todas já foram escritas, atualiza o total de cedulas contadas
        // Escreve tudo por extenso com a mesma lógica anterior
        printf("Cedula %d %d (", tipoDaCedula[k], quantidadeDeCedulas[k]);
        separanum(quantidadeDeCedulas[k], algarismos);
        escrevePorExtenso(algarismos, 1);
        if (quantidadeDeCedulas[k] > 1)
        {
            printf("cedulas");
        }
        else
        {
            printf("cedula");
        }
        printf(")\n--------------------------------------------------------------------------------------------------------------------------\n");
    }
}

// includes...

// objetivo:escolhe dentre as letras do alfabeto ('a'..'z') uma letra aleatoriamente
// parametros: nenhum
// retorno:a letra do alfabeto
char geraAlfabeto()
{
    int i;
    char letras[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    i = rand() % 26;
    return (letras[i] - 32);
}
// objetivo:escolhe dentre os numeros ('0'..'9') uma numero aleatoriamente
// parametros: nenhum
// retorno:o numero
char geraNumero()
{
    int i;
    char numeros[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    i = rand() % 9;
    return (numeros[i]);
}
// objetivo:gera aleatoriamente um numero de conta corrente no formato 999.999-X
// parametros: c onde armazera a conta gerada
// retorno:nenhum
void geraContaCorrente(char c[])
{
    // implemente aqui
    int i;
    memset(c, 0, strlen(c));
    for (i = 0; i < 8; i++)
    {
        if (i == 3)
        {
            c[i] = '.';
        }
        else if (i == 7)
        {
            c[i] = '-';
        }
        else
        {
            c[i] = geraNumero();
        }
    }
    c[8] = geraAlfabeto();
}

// objetivo:verifica se um cpf no formato 999.999.999-99 e valido
// parametros: cpf a ser verificado
// retorno: 1 se cpf e valido ou 0 se cpf nao e valido
int verifica_cpf_valido(char cpf[])
{
    return 1;
}

int verifica_conta_valida(char conta[])
{
    return 1;
}
// objetivo:insere pontuacoes '.' e '- ' em um cpf
// parametros: cpf_origem o cpf recebido no format 99999999999
//             cpf_destino o cpf com as pontuacoes inseridas no formato 999.999.999-99
void insere_pontuacao_cpf(char cpf_origem[], char cpf_destino[])
{
    // implemente aqui
    char teste;
    int cont = 0, i;
    for (i = 0; i < 14; i++)
    {
        if (i == 3 || i == 7)
        {
            cpf_destino[i] = '.';
        }
        else if (i == 11)
        {
            cpf_destino[i] = '-';
        }
        else
        {
            teste = cpf_origem[cont];
            cpf_destino[i] = teste;
            cont++;
        }
    }
}
// objetivo:calcula o primeiro digito verificador de um cpf no formato 999999999
// parametros: cpf o cpf sem os digitos verificadores
// retorno: o calculo do primeiro digito verificador
int obtem_primeiro_digito_verificador(char cpf[])
{
    // implemente aqui
    int digito, intcpf, calccpf, cont = 10, i; // declaracao de variaveis
    for (i = 0; i < 9; i++)
    { // converte digitos do cpf de char para int e faz o calculo necessario
        intcpf = cpf[i] - '0';
        calccpf += intcpf * cont;
        cont--;
    }
    if ((calccpf % 11 == 0) || (calccpf % 11 == 1))
    {
        digito = 0;
    }
    else
    {
        digito = 11 - (calccpf % 11);
    }

    return (digito);
}
// objetivo:calcula o segundo digito verificador de um cpf no formato 999999999
// parametros: cpf sem os digitos verificadores
// retorno: o calculo do segundo digito verificador
int obtem_segundo_digito_verificador(char cpf[])
{
    // implemente aqui
    int digito, intcpf, cont = 10, calccpf, i; // declaracao de variaveis
    for (i = 1; i < 9; i++)
    { // converte digitos do cpf de char para int e faz o calculo necessario
        intcpf = cpf[i] - '0';
        calccpf += intcpf * cont;
        cont--;
    }
    calccpf += obtem_primeiro_digito_verificador(cpf) * cont;
    if ((calccpf % 11 == 0) || (calccpf % 11 == 1))
    {
        digito = 0;
    }
    else
    {
        digito = 11 - (calccpf % 11);
    }
    return (digito);
}

// objetivo:gera aleatoriamente um cpf valido no formato 999.999.999-99
// parametros: cpf onde sera armazenado o cpf valido
// retorno: nenhum
void gera_cpf_valido(char cpf[])
{

    // implemente aqui
    int i;
    char cpf_processo[11];

    do
    {
        for (i = 0; i < 9; i++)
        {
            cpf_processo[i] = geraNumero();
        }
        cpf_processo[9] = obtem_primeiro_digito_verificador(cpf_processo) + '0';
        cpf_processo[10] = obtem_segundo_digito_verificador(cpf_processo) + '0';

        insere_pontuacao_cpf(cpf_processo, cpf);
    } while (verifica_cpf_valido(cpf) != 1);
}

// Objetivo: gera um cpf e uma conta correte
// verifica se não existe nenhum cpf ou conta corrente iguais já cadastrados
// inclui o cliente no sistema
// Parametros: vetor onde será armazenado o cpf, a conta corrente
// Retorno: nenhum
void incluirCliente(char cpfClientes[50][15], char correnteClientes[50][10])
{
    char cpfTeste[15];
    char contaTeste[10];
    int i;
    gera_cpf_valido(cpfTeste);
    geraContaCorrente(contaTeste);

    if (existeCadastro(cpfTeste, cpfClientes, contaTeste, correnteClientes) == 0)
    {
        strcpy(cpfClientes[numClientes], cpfTeste);
        strcpy(correnteClientes[numClientes], contaTeste);
        numClientes++;
    }
    else
    {
        printf("\nNao foi possivel incluir o cliente!\n");
    }
}

// Objetivo: verifica se não existe nenhum cpf ou conta corrente iguais já cadastrados
// Parametros: vetores onde os cpfs e as contas estão armazenados, além do numero de cpf e conta que será comparado
// Retorno: 2 se existe, 1 se existe o cpf ou conta corrente, e 0 em caso contrário
int existeCadastro(char cpfAnalise[15], char cpfClientes[50][15], char contaAnalise[10], char correnteClientes[50][10])
{
    int i, validade;
    validade = 0;
    for (i = 0; i < numClientes; i++)
    {
        if ((strcmp(cpfAnalise, cpfClientes[i]) == 0) || (strcmp(contaAnalise, correnteClientes[i]) == 0))
        {
            if ((strcmp(cpfAnalise, cpfClientes[i]) == 0) && (strcmp(contaAnalise, correnteClientes[i]) == 0))
            {
                validade = 2;
            }
            else
            {
                validade = 1;
            }
        }
    }
    return validade;
}

// Objetivo: exibe os dados de cada cliente
// Parametros: vetores onde os cpfs e as contas estão armazenados
// Retorno: nenhum
void mostraDadosClientes(char cpfClientes[50][15], char correnteClientes[50][10])
{
    int i;
    for (i = 0; i < numClientes; i++)
    {
        printf("Cliente %d: CPF: %s Conta Corrente: %s\n", i + 1, cpfClientes[i], correnteClientes[i]);
    }
}

// Objetivo: altera o cpf de um cliente, mantendo formatação
// Parametros: vetor onde o cpf está armazenado e deve ser modificado
// Retorno:nenhum
void alterarCpf(char cpfClientes[50][15], int numDoCliente)
{
    char novoCPF[15];
    scanf("%s", novoCPF);
    if (verifica_cpf_valido(novoCPF) == 1)
    {
        strcpy(cpfClientes[numDoCliente], novoCPF);
    }
    else
    {
        printf("Cpf novo inserido invalido!\n");
    }
}

// Objetivo: altera a conta corrente do cliente, mantendo formatação
// Parametros: vetor onde a conta está armazenada e deve ser modificada
// Retorno: nenhum
void alterarContaCorrente(char correnteClientes[50][10], int numDoCliente)
{
    char novaConta[15];
    scanf("%s", novaConta);
    if (verifica_conta_valida(novaConta) == 1)
    {
        strcpy(correnteClientes[numDoCliente], novaConta);
    }
    else
    {
        printf("Cpf novo inserido invalido!\n");
    }
}

// Objetivo: se não existir saque na conta do cliente, permite alterar o cpf ou a conta corrente, preservando a formatação
// Parametros: vetores onde os cpfs e as contas estão armazenados
// Retorno:nenhum
void alterarDadosCliente(char cpfClientes[50][15], char correnteClientes[50][10], int saquesCliente[50][15])
{
    int numDoCliente, escolha;
    printf("Escolha o numero do cliente que deseja fazer alterações:\n");
    scanf("%d", &numDoCliente);

    if (numDoCliente > numClientes)
    {
        printf("Cliente inexistente!\n");
    }
    else
    {
        if (existeSaque(saquesCliente, numDoCliente) != 0)
        {
            printf("Nao e possivel fazer alteracoes nos dados do cliente selecionado!\n");
        }
        else
        {
            printf("Escolha o dado que deve ser alterado:\n1-CPF\n2-Conta Corrente\n");
            scanf("%d", &escolha);
            switch (escolha)
            {
            case 1:
                alterarCpf(cpfClientes, numDoCliente);
                break;
            case 2:
                alterarContaCorrente(correnteClientes, numDoCliente);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
            }
        }
    }
}

// Objetivo:verifica se existe saques na conta do cliente
// Parametros: vetor onde os saques dos clientes estão armazenados
// Retorno: 1 se existe 0 em caso contrário
int existeSaque(int saquesCliente[50][15], int numDoCliente)
{
    int validade = 0;
    if (saquesCliente[numDoCliente][0] != 0)
    {
        validade = 1;
    }
    return validade;
}

// Objetivo: exclui cliente se não existe saques em sua conta
// Parametros: vetor conta e cpf
// Retorno: nenhum
void excluirCliente(char cpfClientes[], char correnteClientes[])
{
}

int main()
{
    // Saldo
    int saldoExistente = 500 * quantidadeDeCedulas[0] + 150 * quantidadeDeCedulas[1] + 50 * quantidadeDeCedulas[2] + 20 * quantidadeDeCedulas[3] + 10 * quantidadeDeCedulas[4] + 5 * quantidadeDeCedulas[5] + 2 * quantidadeDeCedulas[6] + 1 * quantidadeDeCedulas[7];

    // Variaveis de funcionamento do menu
    int pg = 0;
    int i, j, k, valorASerSacado, cedulasUsadasNoSaque[8];
    char cpfs[50][15], contasCorrente[50][10];
    int saques[50][15];

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
                    incluirCliente(cpfs, contasCorrente);
                    break;
                case 2:
                    mostraDadosClientes(cpfs, contasCorrente);
                    break;
                case 3:
                    alterarDadosCliente(cpfs, contasCorrente, saques);
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
            while (pg == 2)
            {
                printf("\nSaque\n");
                valorASerSacado = realizaSaque();
                if (checaSaldo(valorASerSacado) == 1)
                {
                    if ((calculaMinimo(valorASerSacado, cedulasUsadasNoSaque)) == 1)
                    {
                        escreveResultadoSaque(valorASerSacado, cedulasUsadasNoSaque);
                    }
                }
                printf("Escolha uma opcao:\n1-Fazer outro saque\n2-Voltar ao Menu\n");
                scanf("%d", &pg);

                switch (pg)
                {
                case 1:
                    pg = 2;
                    break;
                case 2:
                    printf("\nVoltando para o menu principal...\n");
                    pg = 0;
                    break;
                default:
                    printf("\nValor Invalido!\n");
                    pg = 2;
                    break;
                }
            }
            break;
        case 3:
            while (pg == 3)
            {
                printf("\nMenu Relatorios\n1-Valores sacados\n2-Valor do saldo existente\n3-Quantidade de cedulas existentes\n4-Voltar ao menu principal\nDigite uma opcao: ");
                scanf("%d", &pg);
                switch (pg)
                {
                case 1:
                    relatorioSaques();

                    pg = 3;
                    break;
                case 2:
                    // Recebe o saldo total na máquina
                    relatorioSaldo();

                    pg = 3;
                    break;
                case 3:
                    // Recebe o vetor que armazena a quantidade de cada cedula
                    relatorioCedulas();

                    pg = 3;
                    break;
                case 4:
                    printf("\nVoltando ao Menu Principal...\n");

                    pg = 0;
                    break;
                default:
                    printf("\nValor Invalido!\n");
                    pg = 3;
                    break;
                }
            }
            break;
        case 4:
            printf("\nFim da execucao...");
            return 0;
            break;
        default:
            printf("\nValor invalido!\n");
            pg = 0;
            break;
        }
    }
}
