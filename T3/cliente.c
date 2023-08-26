//Faltando a função de excluir clientes...

//Variaveis Globais
int numClientes = 0; 

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
            if (conta[i] + 0 != 46)
            {
                return 0;
            }
        }
        else if (i == 7)
        {
            if (conta[i] + 0 != 45)
            {
                return 0;
            }
        }
        else
        {
            if ((conta[i] + 0 < 48) || (conta[i] > 57))
            {
                return 0;
            }
        }
    }
    if ((conta[8] + 0 > 90) || (conta[8] + 0 < 65))
    {
        return 0;
    }
    return 1;
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
// Objetivo: verifica se o cpf em analise esta no sistema do caixa
// Parametros: vetor onde os cpfs estão armazenados e o cpf em analise
// retorno: 1 se o cpf existe no sistema e 0 caso contrário
int existeCPF(char cpfAnalise[15], char cpfClientes[50][15])
{
    int i;
    for (i = 0; i < numClientes; i++)
    {
        if ((strcmp(cpfAnalise, cpfClientes[i]) == 0))
        {
            return 1;
        }
    }
    return 0;
}

// Objetivo: verifica se a conta corrente em analise esta no sistema do caixa
// Parametros: vetor onde as contas estão armazenados e a conta em analise
// retorno: 1 se a conta existe no sistema e 0 caso contrário
int existeContaCorrente(char contaAnalise[10], char correnteClientes[50][10])
{
    int i;
    for (i = 0; i < numClientes; i++)
    {
        if (strcmp(contaAnalise, correnteClientes[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}
// Objetivo: verifica se não existe nenhum cpf ou conta corrente iguais já cadastrados
// Parametros: vetores onde os cpfs e as contas estão armazenados, além do numero de cpf e conta que será comparado
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
// verifica se não existe nenhum cpf ou conta corrente iguais já cadastrados
// inclui o cliente no sistema
// Parametros: vetor onde será armazenado o cpf, a conta corrente
// Retorno: nenhum
void incluirCliente(char cpfClientes[50][15], char correnteClientes[50][10])
{
    char cpfTeste[15], contaTeste[10];
    int i;

    gera_cpf_valido(cpfTeste);
    geraContaCorrente(contaTeste);

    if ((existeCadastro(cpfTeste, cpfClientes, contaTeste, correnteClientes) == 0) && (numClientes < 50))
    {
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
    printf("Digite o novo CPF do cliente:\n");
    scanf("%s", novoCPF);
    if (verifica_cpf_valido(novoCPF) == 1)
    {
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
    if (verifica_conta_valida(novaConta) == 1)
    {
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
// Parametros: vetores onde os cpfs e as contas estão armazenados
// Retorno:nenhum
void alterarDadosCliente(char cpfClientes[50][15], char correnteClientes[50][10], int saquesCliente[50][15])
{
    int numDoCliente, escolha;
    printf("Escolha o numero do cliente que deseja alterar os dados:\n");
    scanf("%d", &numDoCliente);

    if ((numDoCliente > numClientes) || (numDoCliente < 1))
    {
        printf("Cliente inexistente!\n");
    }
    else
    {
        if (existeSaque(saquesCliente, numDoCliente - 1) != 0)
        {
            printf("Nao e possivel fazer alteracoes nos dados do cliente selecionado!\n");
        }
        else
        {
            printf("Escolha o dado que deve ser alterado:\n1-CPF\n2-Conta Corrente\n3-Cancelar\n");
            scanf("%d", &escolha);
            system("cls");
            switch (escolha)
            {
            case 1:
                alterarCpf(cpfClientes, numDoCliente - 1);
                break;
            case 2:
                alterarContaCorrente(correnteClientes, numDoCliente - 1);
                break;
            case 3:
                printf("Cancelando operacao de alterar...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                system("pause");
                break;
            }
        }
    }
}
// Objetivo: exclui cliente se não existe saques em sua conta
// Parametros: vetor conta e cpf
// Retorno: nenhum
void excluirCliente(char cpfClientes[50][15], char correnteClientes[50][10])
{
}
