// Objetivo: exclui cliente se não existe saques em sua conta
// Parametros: vetor conta, cpf e saques clientes
// Retorno: nenhum
void excluirCliente(char cpfClientes[50][15], char correnteClientes[50][10], int saquesClientes[50][15])
{
    //declaração de variaveis
    int numDoCliente, i, j, existe;
    char cpfClientesCopy[50][15], correnteClientesCopy[50][10], contaCliente[10];
    printf("Digite o numero de conta do cliente que deseja exluir:\n");
    //escaneamento de
    scanf("%s", contaCliente);
    existe = existeContaCorrente(contaCliente, correnteClientes);
    numDoCliente = obtemNumeroDoCliente(contaCliente, correnteClientes);
    if (existe==0)
    {
        printf("Cliente inexistente!\n");
    }
    else
    {
        if (existeSaque(saquesClientes, numDoCliente) != 0)
        {
            printf("Nao e possivel exluir os dados do cliente selecionado!\n");
        }
        else
        {
            if(numDoCliente==numClientes-1)
            {
                memset(correnteClientes[numDoCliente],0,10);
                memset(saquesClientes[numDoCliente],0,15);
                memset(cpfClientes[numDoCliente],0,15);
            }
            else
            {
                i=0;
                while((strcmp(correnteClientes[numDoCliente+1+i],"")!=0)&&(i<50-numClientes+numDoCliente+1))
                {
                    strcpy(correnteClientes[numDoCliente+i],correnteClientes[numDoCliente+1+i]);
                    strcpy(cpfClientes[numDoCliente+i],cpfClientes[numDoCliente+1+i]);
                    //saquesClientes[numDoCliente+i] = saquesClientes[numDoCliente+1+i];
                    i++;
                }
                memset(correnteClientes[numDoCliente+i],0,10);
                memset(saquesClientes[numDoCliente+i],0,15);
                memset(cpfClientes[numDoCliente+i],0,15);
            }
            numClientes--;
        }
    }
}
