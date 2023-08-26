// Objetivo: exibe o relatório sobre os saques realizados no caixa eletronico por cada cliente
// Parametros: vetores onde estão armazenados os cpfs, as contas correntes e os saques de cada cliente
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
        while ((saquesClientes[i][j] != 0) && (j != 15))
        {
            printf("R$ %d\n", saquesClientes[i][j]);
            saqueTotalNaConta += saquesClientes[i][j];
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
