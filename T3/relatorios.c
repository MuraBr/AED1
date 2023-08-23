//Em progresso...
//Objetivo: exibe o relatório sobre os saques realizados no caixa eletronico por cada cliente
//Parametros: 
//Retorno: 
void relatorioSaques(int totalSacadoNaMaquina)
{
    int i, j;
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
