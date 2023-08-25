//Prototipos de outra parte do sistema
int verifica_cpf_valido(char cpf[]) {
    return 1;
}

int verifica_conta_valida(char conta[]) {
    return 1;
}
//Variaveis Globais
int numClientes = 0; 

// Objetivo: gera um cpf e uma conta correte
// verifica se não existe nenhum cpf ou conta corrente iguais já cadastrados
// inclui o cliente no sistema
// Parametros: vetor onde será armazenado o cpf, a conta corrente
// Retorno: nenhum
void incluirCliente(char cpfClientes[50][15], char correnteClientes[50][10])
{
    char cpfTeste[15], contaTeste[10];
    int i;

    printf("cpf %s\nconta corrente %s\n", cpfTeste, contaTeste);

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
