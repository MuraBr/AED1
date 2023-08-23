// Variáveis
char cpfClientes[50][15], correnteClientes[50][10];
int saques[50][20], numClientes = 0;

// Objetivo: gera um cpf e uma conta correte
// verifica se não existe nenhum cpf ou conta corrente iguais já cadastrados
// inclui o cliente no sistema
// Parametros: vetor onde será armazenado o cpf, a conta corrente
// Retorno: nenhum
void incluirCliente()
{
    char cpfTeste[15], contaTeste[10];
    geraContaCorrente(contaTeste);
    gera_cpf_valido(cpfTeste);

    if (existeCadastro(cpfTeste, contaTeste) == 0)
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
int existeCadastro(char cpfAnalise[], char contaAnalise[])
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

//Objetivo: exibe os dados de cada cliente
//Parametros: vetores onde os cpfs e as contas estão armazenados
//Retorno: nenhum
void mostraDadosClientes(char cpfClientes[], char correnteClientes[]){

}

//Objetivo: se não existir saque na conta do cliente, permite alterar o cpf ou a conta corrente, preservando a formatação
//Parametros: vetores onde os cpfs e as contas estão armazenados
//Retorno:nenhum
void alterarDadosCliente(char cpfClientes[], char correnteClientes[]){

}

//Objetivo: altera o cpf de um cliente, mantendo formatação
//Parametros: vetor onde o cpf está armazenado e deve ser modificado
//Retorno:nenhum
void alterarCpf(char cpfClientes[]){

}

//Objetivo: altera a conta corrente do cliente, mantendo formatação
//Parametros: vetor onde a conta está armazenada e deve ser modificada
//Retorno: nenhum
void alterarContaCorrente(char correnteClientes[]){

}

//Objetivo:verifica se existe saques na conta do cliente
//Parametros: vetor onde os saques dos clientes estão armazenados
//Retorno: 1 se existe 0 em caso contrário
int existeSaque(int saquesCliente[]){

}

//Objetivo: exclui cliente se não existe saques em sua conta
//Parametros: vetor conta e cpf
//Retorno: nenhum
void excluirCliente(char cpfClientes[], char correnteClientes[]){

}
