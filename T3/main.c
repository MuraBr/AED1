// Alunos: João Vitor Antunes da Silva, Arthur Kenji Murakami, Mathews Henrique Costa da Costa, Fernando Massahiro Cruz Miyashiro, Guilherme Zanan Piveta
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
// Inicio das funções...

// Objetivo: separa os algorismos de um número e armazena em um vetor [a, b, c, d, e, f]
// Parametros: recebe um valor e o vetor onde serão guardados os algarismos
// Retorno: nenhum
void separanum(int valor, int num[])
{
    int i;
    for (i = 5; i >= 0; i--)
    {
        // Armazena em cada espaço do vetor um algarsimo do numero de acordo com a casa decimal em que se encontra
        num[i] = valor % 10;
        // Reduz o numero para a proxima casa ser avaliada
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
        // Escreve cem se as proximas duas casas forem zero e cento se existir algum algarismo não nulo
        if ((b == 0) && (c == 0))
        {
            printf("Cem ");
        }
        else
        {
            printf("Cento ");
        }
    }
    else
    {
        // Verifica o tipo de formatação
        if (tipo != 1)
        {
            // Formata como real
            printf(centenas[a]);
        }
        else
        {
            // Formata como cedula
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
        // Verifica o tipo de formatação
        if (tipo != 1)
        {
            // Formata como real
            printf(unidades[c]);
        }
        else
        {
            // Formata como cedula
            printf(unidadesCedula[c]);
        }
    }
    else
    {
        // Se o numero que deve ser escrito é 1000 + x, 0 < x < 1000, não escreve nada
        if ((c != 1) || ((b != 0) || (a != 0)))
        {
            // Repete o mesmo processo de formatação de tipo
            if (tipo != 1)
            {
                printf(unidades[c]);
            }
            else
            {
                printf(unidadesCedula[c]);
            }
        }
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
    }
    else
    {
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
        // Escreve "mil e" apenas se houver numeros não nulos após a unidade de milhar ou se a centena for o único algarismo não nulo no resto do número
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
                // No caso do módulo ter usado a dezena especial, pula-se a casa das unidades
                j++;
            }
            if (j == 2)
                escreveMil(num[0], num[1], num[2], num[3], num[4], num[5]);
        }
        escreveE(j, num[j], num[j + 1], num[j + 2]);
    }
    // Formata em reais
    if (tipo == 0)
    {
        if ((num[5] > 1) || (num[4] > 0) || (num[3] > 0) || (num[2] > 0) || (num[1] > 0) || (num[0] > 0))
        {
            printf("reais ");
        }
        else
        {
            printf("real ");
        }
    }
}
// Objetivo: calcula o saldo restante na maquina
// Parametros: nenhum
// Retorno: saldo na máquina
int calculaSaldo()
{
    int saldo;
    // Multiplica a quantidade de cada cedula pelo seu tipo e soma com as demais
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
    // atualiza o valor do saldo existente e verifica se é menor
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
        // Escreve apenas as cedulas utilizadas
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
    int i;
    char conta_processo[10];
    // Elimina possiveis residuos no vetor que será utilizado para gerar uma conta
    memset(conta_processo, 0, strlen(conta_processo));
    for (i = 0; i < 8; i++)
    {
        if (i == 3)
        {
            conta_processo[i] = '.';
        }
        else if (i == 7)
        {
            conta_processo[i] = '-';
        }
        else
        {
            conta_processo[i] = geraNumero();
        }
    }
    conta_processo[8] = geraAlfabeto();
    // Copia a conta gerada para o vetor em que desejamos armazená-la
    strcpy(c, conta_processo);
}
// Objetivo: verifica se a conta corrente digitada está formatada corretamente
// Paramentros: o vetor contendo a conta corrente que deve ser analisada
// Return: 1 se a conta foi digitada corretamente e 0 em caso contrário
int verifica_conta_valida(char conta[])
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (i == 3)
        {
            // Se não houver o caracter '.' na 3 posição do vetor retorna falso
            if (conta[i] + 0 != 46)
            {
                return 0;
            }
        }
        else if (i == 7)
        {
            // Se não houver o caracter '-' na 3 posição do vetor retorna falso
            if (conta[i] + 0 != 45)
            {
                return 0;
            }
        }
        else
        {
            // Se não houver numeros entre 0 e 9 nos lugares devidos retorna falso
            if ((conta[i] + 0 < 48) || (conta[i] > 57))
            {
                return 0;
            }
        }
    }
    // Se não houver uma letra maiúscula na posição 8 do vetor retorna falso
    if ((conta[8] + 0 > 90) || (conta[8] + 0 < 65))
    {
        return 0;
    }
    return 1;
}
// objetivo:insere pontuacoes '.' e '- ' em um cpf
// parametros: cpf_origem o cpf recebido no format 99999999999
//             cpf_destino o cpf com as pontuacoes inseridas no formato 999.999.999-99
// retorno: nenhum
void insere_pontuacao_cpf(char cpf_origem[], char cpf_destino[])
{
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
            // Passa um caracter para teste e depois para o vetor destino, avançando uma posição no cpf origem
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
    int digito = 0, intcpf, cont = 10, calccpf; // declaracao de variaveis
    for (int i = 0; i < 9; i++)
    { // converte digitos do cpf de char para int e faz o calculo necessario
        intcpf = cpf[i] - '0';
        digito += intcpf * cont;
        cont -= 1;
    }
    if (digito * 10 % 11 == 10)
    {
        digito = 0;
    }
    else
    {
        digito = digito * 10 % 11;
    }
    return (digito);
}
// objetivo:calcula o segundo digito verificador de um cpf no formato 999999999
// parametros: cpf sem os digitos verificadores
// retorno: o calculo do segundo digito verificador
int obtem_segundo_digito_verificador(char cpf[])
{
    int digito = 0, intcpf, cont = 11, calccpf, i; // declaracao de variaveis
    for (int i = 0; i < 10; i++)
    { // converte digitos do cpf de char para int e faz o calculo necessario
        if (i <= 8)
        {
            intcpf = cpf[i] - '0';
        }
        else
        {
            intcpf = obtem_primeiro_digito_verificador(cpf);
        }
        digito += intcpf * cont;
        cont -= 1;
    }
    if (digito * 10 % 11 == 10)
    {
        digito = 0;
    }
    else
    {
        digito = digito * 10 % 11;
    }
    return (digito);
}

// objetivo:verifica se um cpf no formato 999.999.999-99 e valido
// parametros: cpf a ser verificado
// retorno: 1 se cpf e valido ou 0 se cpf nao e valido
int verifica_cpf_valido(char cpf[])
{
    int d1cpf = cpf[12] - '0', d2cpf = cpf[13] - '0', valido = 1, count = 0, d1, d2, c = 0; // declaracao de variaveis
    char cpf2[12];

    for (int i = 0; i < 14; i++)
    {
        if ((cpf[i] == '.') || (cpf[i] == '-'))
        {
            ++i;
        }
        if (d1cpf == (cpf[i] + 0))
        {
            count++;
        }
        if (c <= 11)
        {
            cpf2[c] = cpf[i];
        }
        c++;
    }
    d1 = obtem_primeiro_digito_verificador(cpf2);
    d2 = obtem_segundo_digito_verificador(cpf2);
    if ((d1cpf == d1) && (d2cpf == d2) && (count < 11))
    { // verificação do cpf
        valido = 1;
    }
    else
    {
        valido = 0;
    }
    return (valido);
}

// objetivo:gera aleatoriamente um cpf valido no formato 999.999.999-99
// parametros: o cpf onde sera armazenado o cpf valido
// retorno: nenhum
void gera_cpf_valido(char cpf[])
{
    int i;
    char cpf_processo[11];
    // Elimina possiveis residuos no vetor de cpf_proccesso
    memset(cpf_processo, 0, strlen(cpf_processo));
    do
    {
        for (i = 0; i < 9; i++)
        {
            // Completa o cpf com numeros
            cpf_processo[i] = geraNumero();
        }
        // Seleciona numeros verificadores de acordo com o resto do cpf
        cpf_processo[9] = obtem_primeiro_digito_verificador(cpf_processo) + '0';
        cpf_processo[10] = obtem_segundo_digito_verificador(cpf_processo) + '0';
        // Formata o cpf
        insere_pontuacao_cpf(cpf_processo, cpf);
        // Sai do loop apenas se o cpf produzido for válido
    } while (verifica_cpf_valido(cpf) != 1);
}

// Obejtivo: encontra a posição em que o cliente se encontra
// Parametros: conta corrente do cliente e o local onde as contas estão armazenadas
// Retorno: retorna a posição da conta do cliente
int obtemNumeroDoCliente(char contaCorrente[10], char correntesClientes[50][10])
{
    int i;
    for (i = 0; i < numClientes; i++)
    {
        if (strcmp(contaCorrente, correntesClientes[i]) == 0)
        {
            return i;
        }
    }
}

// Objetivo:verifica se existe saques na conta do cliente
// Parametros: local onde os saques dos clientes estão armazenados
// Retorno: 1 se existe 0 em caso contrário
int existeSaque(int saquesCliente[50][15], int numDoCliente)
{
    int validade = 0;
    // Verifica se a primeira posição do vetor de saques do cliente selecionado está vazia
    // Como não é possível retirar saques da conta, somente isso é suficiente para verificar saques
    if (saquesCliente[numDoCliente][0] != 0)
    {
        validade = 1;
    }
    return validade;
}
// Objetivo: verifica se o cpf em analise esta no sistema do caixa
// Parametros: local onde os cpfs estão armazenados e o cpf em analise
// retorno: 1 se o cpf existe no sistema e 0 caso contrário
int existeCPF(char cpfAnalise[15], char cpfClientes[50][15])
{
    int i;
    for (i = 0; i < numClientes; i++)
    {
        // Percorre toda a matriz onde estão armazenados os cpf até encontrar um cpf identico ao da analise ou nada
        if ((strcmp(cpfAnalise, cpfClientes[i]) == 0))
        {
            return 1;
        }
    }
    return 0;
}

// Objetivo: verifica se a conta corrente em analise esta no sistema do caixa
// Parametros: local onde as contas estão armazenados e a conta em analise
// retorno: 1 se a conta existe no sistema e 0 caso contrário
int existeContaCorrente(char contaAnalise[10], char correnteClientes[50][10])
{
    int i;
    for (i = 0; i < numClientes; i++)
    {
        // Percorre toda a matriz onde estão armazenadas as conta até encontrar uma conta identica ao da analise ou nada
        if (strcmp(contaAnalise, correnteClientes[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}
// Objetivo: verifica se não existe nenhum cpf ou conta corrente iguais já cadastrados
// Parametros: locais onde os cpfs e as contas estão armazenados, além do numero de cpf e conta que será comparado
// Retorno: 2 se existe, 1 se existe o cpf ou conta corrente, e 0 em caso contrário
int existeCadastro(char cpfAnalise[15], char cpfClientes[50][15], char contaAnalise[10], char correnteClientes[50][10])
{
    int i;
    for (i = 0; i < numClientes; i++)
    {
        if ((existeCPF(cpfAnalise, cpfClientes) == 1) || (existeContaCorrente(contaAnalise, correnteClientes) == 1))
        {
            if ((existeCPF(cpfAnalise, cpfClientes) == 1) && (existeContaCorrente(contaAnalise, correnteClientes) == 1))
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}

// Objetivo: gera um cpf e uma conta correte
// verifica se não existe nenhum cpf ou conta corrente iguais já cadastrados, inclui o cliente no sistema
// Parametros: locais onde serão armazenados o cpf e outro para conta corrente
// Retorno: nenhum
void incluirCliente(char cpfClientes[50][15], char correnteClientes[50][10])
{
    char cpfTeste[15], contaTeste[10];
    int i;
    // Gera um cpf e uma conta corrente para o cliente
    gera_cpf_valido(cpfTeste);
    geraContaCorrente(contaTeste);
    // Verifica se o cpf ou a conta já estão no sistema ou se o sistema está cheio
    if ((existeCadastro(cpfTeste, cpfClientes, contaTeste, correnteClientes) == 0) && (numClientes < 50))
    {
        // Em caso de sucesso atualiza o numero de clientes e adiciona o novo cliente
        strcpy(cpfClientes[numClientes], cpfTeste);
        strcpy(correnteClientes[numClientes], contaTeste);
        numClientes++;
        printf("\nO cliente foi incluido com sucesso!\n");
    }
    else
    {
        printf("\nNao foi possivel incluir o cliente!\n");
    }
}

// Objetivo: exibe os dados de cada cliente
// Parametros: locais onde os cpfs e as contas estão armazenados
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
// Parametros: local onde o cpf está armazenado e o número do cliente que terá os dados alterados
// Retorno:nenhum
void alterarCpf(char cpfClientes[50][15], int numDoCliente)
{
    char novoCPF[15];
    printf("Digite o novo CPF do cliente:\n");
    scanf("%s", novoCPF);
    // Verifica se o cpf digitado é válido
    if (verifica_cpf_valido(novoCPF) == 1)
    {
        // Verifica se o cpf já está cadastrado no sistema
        if (existeCPF(novoCPF, cpfClientes) == 0)
        {
            strcpy(cpfClientes[numDoCliente], novoCPF);
            printf("Cpf alterado com sucesso!\n");
        }
        else
        {
            printf("O Cpf nao pode ser inserido no sistema!\n");
        }
    }
    else
    {
        printf("O Cpf inserido eh invalido!\n");
    }
}
// Objetivo: altera a conta corrente do cliente, mantendo formatação
// Parametros: vetor onde a conta está armazenada e deve ser modificada
// Retorno: nenhum
void alterarContaCorrente(char correnteClientes[50][10], int numDoCliente)
{
    char novaConta[15];
    printf("Digite o novo numero da conta corrente do cliente:\n");
    scanf("%s", novaConta);
    // Verifica se a conta foi digitada com a formatação correta
    if (verifica_conta_valida(novaConta) == 1)
    {
        // Verifica se a conta já está no sistema
        if (existeContaCorrente(novaConta, correnteClientes) == 0)
        {
            strcpy(correnteClientes[numDoCliente], novaConta);
            printf("Conta corrente alterada com sucesso!\n");
        }
        else
        {
            printf("A conta corrente nao pode ser inserida no sistema!\n");
        }
    }
    else
    {
        printf("A conta corrente inserida eh invalida!\n");
    }
}
// Objetivo: se não existir saque na conta do cliente, permite alterar o cpf ou a conta corrente, preservando a formatação
// Parametros: locais onde os cpfs, os saques e as contas dos clientes estão armazenados
// Retorno:nenhum
void alterarDadosCliente(char cpfClientes[50][15], char correnteClientes[50][10], int saquesCliente[50][15])
{
    int numDoCliente, escolha = 0;
    char contaDoCliente[10];
    printf("Digite o numero da conta corrente do cliente que deseja alterar os dados:\n");
    scanf("%s", contaDoCliente);
    // Verifica se o cliente pode existir no sistema
    if (existeContaCorrente(contaDoCliente, correnteClientes) != 1)
    {
        printf("A conta informada nao pertence a nenhum cliente!\n");
    }
    else
    {
        numDoCliente = obtemNumeroDoCliente(contaDoCliente, correnteClientes);
        // Verifica se não há saques na conta do cliente
        if (existeSaque(saquesCliente, numDoCliente) != 0)
        {
            printf("Nao e possivel fazer alteracoes nos dados do cliente selecionado!\n");
        }
        else
        {
            while (escolha != 3)
            {
                printf("Escolha o dado que deve ser alterado:\n1-CPF\n2-Conta Corrente\n3-Cancelar\n");
                scanf("%d", &escolha);
                system("cls");
                switch (escolha)
                {
                case 1:
                    alterarCpf(cpfClientes, numDoCliente);
                    break;
                case 2:
                    alterarContaCorrente(correnteClientes, numDoCliente);
                    break;
                case 3:
                    printf("Finalizar operacao de alterar...\n");
                    break;
                default:
                    printf("Opcao invalida!\n");
                    system("pause");
                    break;
                }
            }
        }
    }
}
// Objetivo: exclui cliente se não existe saques em sua conta
// Parametros: locais onde as contas e os cpfs dos clientes estão armazenados
// Retorno: nenhum
void excluirCliente(char cpfClientes[50][15], char correnteClientes[50][10])
{
}
// Objetivo: exibe o relatório sobre os saques realizados no caixa eletronico por cada cliente
// Parametros: locais onde os cpfs, os saques e as contas dos clientes estão armazenados
// Retorno: nenhum
void relatorioSaques(char cpfClientes[50][15], char correnteClientes[50][10], int saquesClientes[50][15])
{
    int i, j, totalSacadoNaMaquina, saqueTotalNaConta;
    totalSacadoNaMaquina = 173600 - calculaSaldo();
    printf("---------------------------------------------------------------------------------------------------------------------------- \nRelatorio 'Valores sacados' \n----------------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < numClientes; i++)
    {
        printf("%s   %s\t", correnteClientes[i], cpfClientes[i]);
        j = 0;
        saqueTotalNaConta = 0;
        // Enquanto houver um valor não nulo nos saques de um cliente e todos os saques não foram mostrados ainda, exibe o valor desses saques
        while ((saquesClientes[i][j] != 0) && (j != 15))
        {
            printf("R$ %d\n", saquesClientes[i][j]);
            // Calcula o valor total dos saques na conta em analise
            saqueTotalNaConta += saquesClientes[i][j];
            // Avança para o próximo saque do cliente
            j++;
            if (j != 0)
            {
                printf("\t\t\t\t");
            }
        }
        printf("\t\tR$ %d\n\n", saqueTotalNaConta);
    }
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
    int saldo = calculaSaldo();
    printf("---------------------------------------------------------------------------------------------------------------------------- \nRelatorio 'Valor do saldo existente ' \n---------------------------------------------------------------------------------------------------------------------------- \nR$ %d ( ", saldo);
    separanum(saldo, algarismos);
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
        printf("Cedula %d %d ( ", tipoDaCedula[k], quantidadeDeCedulas[k]);
        separanum(quantidadeDeCedulas[k], algarismos);
        escrevePorExtenso(algarismos, 1);
        if (quantidadeDeCedulas[k] > 1)
        {
            printf("cedulas ");
        }
        else
        {
            printf("cedula ");
        }
        printf(")\n--------------------------------------------------------------------------------------------------------------------------\n");
    }
}

// Inicio do Sistema...
int main()
{
    // Saldo
    int saldoExistente = 500 * quantidadeDeCedulas[0] + 150 * quantidadeDeCedulas[1] + 50 * quantidadeDeCedulas[2] + 20 * quantidadeDeCedulas[3] + 10 * quantidadeDeCedulas[4] + 5 * quantidadeDeCedulas[5] + 2 * quantidadeDeCedulas[6] + 1 * quantidadeDeCedulas[7];
    // Variaveis de funcionamento do menu
    int pg = 0;
    // Variaveis gerais
    int i, j, k, l, m, valorASerSacado, cedulasUsadasNoSaque[8], cliente;
    // Variaveis para armazenar dados dos clientes
    char cpfs[50][15], contasCorrente[50][10];
    int saques[50][15];
    // Variaveis para acessar saque
    char cpfParaSaque[15], contaParaSaque[10];

    // Loop para zerar a matriz com os saques
    for (m = 0; m < 50; m++)
    {
        for (l = 0; l < 15; l++)
        {
            saques[m][l] = 0;
        }
    }
    // Inicio do caixa
    while (pg == 0)
    {
        // Menu principal
        printf("\nMenu Principal\n1-Cliente\n2-Saque\n3-Relatorios\n4-Finalizar\nDigite uma opcao: ");
        scanf("%d", &pg);
        system("cls");
        switch (pg)
        {
        case 1:
            while (pg == 1)
            {
                // Menu clientes
                printf("\nMenu Cliente\n1-Incluir\n2-Mostrar\n3-Alterar\n4-Excluir\n5-Voltar\nDigite uma opcao: ");
                scanf("%d", &pg);
                system("cls");
                switch (pg)
                {
                case 1:
                    incluirCliente(cpfs, contasCorrente);
                    system("pause");
                    pg = 1;
                    break;
                case 2:
                    mostraDadosClientes(cpfs, contasCorrente);
                    system("pause");
                    pg = 1;
                    break;
                case 3:
                    alterarDadosCliente(cpfs, contasCorrente, saques);
                    system("pause");
                    pg = 1;
                    break;
                case 4:
                    pg = 1;
                    break;
                case 5:
                    printf("\nVoltando para o menu principal...\n");
                    pg = 0;
                    break;
                default:
                    printf("\nValor Invalido!\n");
                    system("pause");
                    pg = 1;
                    break;
                }
            }
            break;
        case 2:
            while (pg == 2)
            {
                printf("Digite um numero de CPF e da Conta corrente para realizar um saque:\n");
                // Reseta as variaveis de acesso ao saque
                memset(cpfParaSaque, 0, strlen(cpfParaSaque));
                memset(contaParaSaque, 0, strlen(contaParaSaque));
                // Lê as variveis de acesso
                printf("CPF: ");
                scanf("%s", cpfParaSaque);
                printf("Conta Corrente: ");
                scanf("%s", contaParaSaque);
                printf("\n");
                // Verifica se os dados existem no cadastro ou se algum foi digitado incorretamente
                if (existeCadastro(cpfParaSaque, cpfs, contaParaSaque, contasCorrente) != 2)
                {
                    if (existeCadastro(cpfParaSaque, cpfs, contaParaSaque, contasCorrente) == 1)
                    {
                        printf("O cpf ou o numero da conta corrente foram digitados incorretamente!\n");
                    }
                    else
                    {
                        printf("Nenhum dado existe no cadastro!\n");
                    }
                }
                else
                {
                    // Em caso de sucesso no saque, armazena o valor sacado na conta do cliente
                    k = 0;
                    for (j = 0; j < numClientes; j++)
                    {
                        // Identifica o cliente que realizou o saque para decidir onde armazenar o saque
                        if ((strcmp(cpfParaSaque, cpfs[j]) == 0) && (strcmp(contaParaSaque, contasCorrente[j]) == 0))
                        {

                            // Realiza a operação de saque, verificando saldo, quantidade de cedulas e etc
                            valorASerSacado = realizaSaque();
                            if (checaSaldo(valorASerSacado) == 1)
                            {
                                if ((calculaMinimo(valorASerSacado, cedulasUsadasNoSaque)) == 1)
                                {
                                    escreveResultadoSaque(valorASerSacado, cedulasUsadasNoSaque);

                                    // Encontra o primeiro espaço vazio no espaço da matriz que os saques deste cliente estão armazenados
                                    // Ou cancela a operação se não é possível fazer mais saques na conta
                                    while ((saques[j][k] != 0) && (k != 15))
                                    {
                                        k++;
                                        if (k == 15)
                                        {
                                            printf("Nao e possivel realizar mais saques nessa conta!\n");
                                        }
                                    }
                                    // Se houver espaço atribui o valor sacado na conta
                                    if (k < 15)
                                    {
                                        saques[j][k] = valorASerSacado;
                                    }
                                }
                            }
                        }
                        else if (j == 49)
                        {
                            printf("O cliente nao existe!\n");
                        }
                    }
                }
                system("pause");
                system("cls");
                printf("Escolha uma opcao:\n1-Fazer outro saque\n2-Voltar ao Menu\n");
                scanf("%d", &pg);
                system("cls");
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
                system("cls");
                switch (pg)
                {
                case 1:
                    relatorioSaques(cpfs, contasCorrente, saques);
                    pg = 3;
                    break;
                case 2:
                    relatorioSaldo();
                    pg = 3;
                    break;
                case 3:
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
