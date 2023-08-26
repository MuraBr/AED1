// Objetivo: exclui cliente se não existe saques em sua conta
// Parametros: vetor conta, cpf e saques clientes
// Retorno: nenhum
void excluirCliente(char cpfClientes[50][15], char correnteClientes[50][10], int saquesClientes[50][15])
{
    int numDoCliente, i, j;
    char cpfClientesCopy[50][15];
    printf("Escolha o numero do cliente que deseja exluir:\n");
    scanf("%d", &numDoCliente);
    if ((numDoCliente > numClientes) || (numDoCliente < 1))
    {
        printf("Cliente inexistente!\n");
    }
    else
    {
        if (existeSaque(saquesClientes, numDoCliente - 1) != 0)
        {
            printf("Nao e possivel exluir os dados do cliente selecionado!\n");
        }
        else
        {
            j=0;
            for(i = 0; i < numClientes; i++)
            {
                if(i!=numDoCliente-1)
                {
                   strcpy(cpfClientesCopy[j],cpfClientes[i]);
                   j++;
                }
            }
            numClientes-=1;
            for(i = 0; i < numClientes; i++)
            {
                strcpy(cpfClientes[i],cpfClientesCopy[i]);
            }
        }
    }
}