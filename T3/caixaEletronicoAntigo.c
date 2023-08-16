//Alunos: João Vitor Antunes da Silva, Arthur Kenji Murakami, Mathews Henrique Costa da Costa, Fernando Massahiro Cruz Miyashiro  
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Declaração de variaveis
    // Navegação nos menus
    int menu, pg;
    // Saque e Total sacado na máquina
    int valorSaque, valorSacado, valorTotalSacado, quantidadeCedulasUsadas[8], quantidadeCedulasPre[8];
    // Abastecimento
    int quantidade, tipo;
    // saldo existente e número de cédulas na máquina
    int saldoExistente, totalCedulas[8], totalNaMaquina;
    // Escrever por extenso
    int num, algarismos[6];
    // Variaveis de iteração
    int i, k, j, l;
    // Inicializações
    const int tipoDaCedula[8] = {
        500, 150, 50, 20, 10, 5, 2, 1};
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
    menu = 0;
    pg = 0;
    totalCedulas[0] = 100;
    valorTotalSacado = 0;
    for (l = 1; l < 8; l++)
        totalCedulas[l] = totalCedulas[l - 1] * 2;
    saldoExistente = 500 * totalCedulas[0] + 150 * totalCedulas[1] + 50 * totalCedulas[2] + 20 * totalCedulas[3] + 10 * totalCedulas[4] + 5 * totalCedulas[5] + 2 * totalCedulas[6] + 1 * totalCedulas[7];

    // Programa do caixa eletrônico
    while (pg == 0)
    {
        //Escolha de opções no Menu Principal
        printf("\n-----Menu Principal-----");
        printf("\n1- Saque");
        printf("\n2- Gerente");
        printf("\n3- Finalizar");
        printf("\nDigite uma opcao: ");
        scanf("%d", &pg);

        switch (pg)
        {
        case 1:
            //Opção 1 selecionada no Menu Principal
            printf("\n----Validar CPF-----");
            int calculocpf = 0;
            int verifica1 = 0;
            int verifica2;
            int teste = 0;
            int valicont = 9;
            int pot = 0;
            long int pote10 = 10;
            int cont = 10;
            char vetor[12];
            int i = 0;
            // pede para o usuario fornecer o cpf
            printf("\nForneca o CPF: ");
            scanf("%s", &vetor);
            // for para fazer a valicação do primeiro numero verificador do cpf
            for (i = 0; i < 9; i++)
            {
                // insere na variavel teste o valor respectivo do vetor
                teste = vetor[i] - '0';
                // faz o calculo
                calculocpf = calculocpf + (teste * cont);
                cont = cont - 1;
            }
            // pega o valor total to calculo e mega o resto da divisão por 11
            verifica1 = calculocpf % 11;
            // verifica se o resto é maior ou igual a 0, para poder subtrair 11
            if (verifica1 >= 2)
            {
                verifica1 = 11 - verifica1;
            }
            // caso não seja o valor verificador é 0
            else
            {
                verifica1 = 0;
            }
            // for para fazer a valicação do segundo numero verificador do cpf
            cont = 11;
            calculocpf = 0;
            for (i = 0; i < 10; i++)
            {
                teste = vetor[i] - '0';
                // if para fazer o calculo com o valor verificador descoberto anteriormente, so entra aqui na ultima repetição
                if (i == 9 && vetor[9] != verifica1)
                {
                    calculocpf = calculocpf + (verifica1 * cont);
                }
                // calculo normal de verificação
                else
                {
                    calculocpf = calculocpf + (teste * cont);
                }
                cont = cont - 1;
            }
            // pega o valor total to calculo e mega o resto da divisão por 11
            verifica2 = calculocpf % 11;
            // verifica se o resto é maior ou igual a 0, para poder subtrair 11
            if (verifica2 >= 2)
            {
                verifica2 = 11 - verifica2;
            }
            // caso não seja o valor verificador é 0
            else
            {
                verifica2 = 0;
            }
            // verifica se os numeros de validação são iguais aos descobertos pelo calculo
            if ((verifica1 != vetor[9] - '0') || (verifica2 != vetor[10] - '0'))
            {
                printf("o CPF %s nao e valido", vetor);
            }
            else
            {
                printf("o CPF %s e valido", vetor);

                printf("\n\n----Saque-----");
                // definicao das variaveis
                valorSacado = 0;

                for (i = 0; i < 8; i++)
                    quantidadeCedulasUsadas[i] = 0;
                // leitura do "valorSaque"
                printf("\nDigite o valor a ser sacado: ");
                scanf("%d", &valorSaque);

                // teste do "valorSaque"
                while (valorSaque <= 0)
                {
                    printf("\nO valor digitado esta incorreto. Digite novamente: ");
                    scanf("%d", &valorSaque);
                }
                // atualiza o valor do saldo existente
                saldoExistente = 500 * totalCedulas[0] + 150 * totalCedulas[1] + 50 * totalCedulas[2] + 20 * totalCedulas[3] + 10 * totalCedulas[4] + 5 * totalCedulas[5] + 2 * totalCedulas[6] + 1 * totalCedulas[7];
                if (valorSaque > saldoExistente)
                {   
                    printf("Nao existe saldo suficiente no caixa eletronico para conceder o quantia exigida!\n");
                }
                else
                {
                    //Apenas calcula quais cedulas serão fornecidas se existe saldo suficiente no caixa
                    //Guarda a quantidade de cedulas atuais para não perder o valor depois dos calculos 
                    for (i = 0; i < 8; i++)
                    {
                        quantidadeCedulasPre[i] = totalCedulas[i];
                    }
                    //Volta a variavel para 0
                    i = 0;

                    // definicao da quantidade de cedulas
                    while (valorSaque > valorSacado)
                    {
                        //Começando nas cedulas com maior valor, adiciona cedulas até que um determinado tipo passe o valor do saque ou acabe na maquina
                        while ((valorSaque >= valorSacado) && (totalCedulas[i] > 0))
                        {
                            valorSacado += tipoDaCedula[i];
                            quantidadeCedulasUsadas[i]++;
                            totalCedulas[i]--;
                        }
                        //Se o valor sacado excedeu o valor do saque, retira uma cedula da contagem
                        if (((totalCedulas[i] != 0)) || ((totalCedulas[i] == 0) && (valorSacado > valorSaque)))
                        {
                            valorSacado -= tipoDaCedula[i];
                            quantidadeCedulasUsadas[i]--;
                            totalCedulas[i]++;
                        }
                        i++;
                        //Caso o valor sacado nao alcance o valor do saque, após todas os espaços do vetor foram avaliados, o saque é cancelado
                        if ((i == 8) && (valorSacado < valorSaque))
                        {
                            valorSacado = valorSaque + 1;
                            printf("\nNao foi possivel realizar o saque com as cedulas disponiveis!");
                            //Reseta as cedulas que foram retiradas
                            for (i = 0; i < 8; i++)
                            {
                                totalCedulas[i] = quantidadeCedulasPre[i];
                            }
                        }
                    }
                    // demonstracao por extenso (roda apenas se o saque não foi cancelado)
                    if (valorSacado == valorSaque)
                    {
                        //Variavel geral num recebe o valor do saque 
                        num = valorSaque;
                        //Separa os alarismos de num em um vetor
                        for (j = 5; j >= 0; j--)
                        {
                            algarismos[j] = num % 10;
                            num /= 10;
                        }
                        printf("\nO saque de ");
                        //Analisa cada algarismo sepadaramente e avalia como deve ser escrito com base na casa decimal 
                        for (j = 0; j < 6; j++)
                        {
                            switch (j)
                            {
                            case 0:
                                //Caso o algarismo seja 1 avalia quando as próximas duas casas estão vazias ou não
                                if (algarismos[j] == 1)
                                {
                                    if ((algarismos[j + 1] == 0) && (algarismos[j + 2] == 0))
                                    {
                                        //Escreve cem se forem vazias e cento se existir algum algarismo não nulo
                                        printf("Cem ");
                                    }
                                    else
                                    {
                                        printf("Cento ");
                                    }
                                }
                                else
                                {
                                    //Utiliza o próprio algarismo para identificar a saída por extenso no vetor das centenas
                                    printf(centenas[algarismos[j]]);
                                }
                                break;

                            case 1:
                                if (algarismos[j] == 1)
                                {
                                    j++;
                                    //Caso o algarismo na dezena for 1, avança em um casa e avalia a unidade
                                    printf(dezenasEspeciais[algarismos[j]]);
                                    //Utiliza o próprio algarismo para identificar a saída por extenso no vetor das dezenas especiais
                                }
                                else
                                {
                                    //Utiliza o próprio algarismo para identificar a saída por extenso no vetor das dezenas
                                    printf(dezenas[algarismos[j]]);
                                }
                                break;

                            case 2:
                                if ((algarismos[j] != 1) || ((algarismos[j - 1] != 0) || (algarismos[j - 2] != 0)))
                                    printf(unidades[algarismos[j]]);
                                    //Utiliza o próprio algarismo para identificar a saída por extenso no vetor das unidades
                                break;
                            case 3:
                            //Caso o algarismo seja 1 avalia quando as próximas duas casas estão vazias ou não
                                if (algarismos[j] == 1)
                                {
                                    if ((algarismos[j + 1] == 0) && (algarismos[j + 2] == 0))
                                    {
                                    //Escreve cem se forem vazias e cento se existir algum algarismo não nulo
                                        printf("Cem ");
                                    }
                                    else
                                    {
                                        printf("Cento ");
                                    }
                                }
                                else
                                {
                                    printf(centenas[algarismos[j]]);
                                    //Utiliza o próprio algarismo para identificar a saída por extenso no vetor das centenas
                                }
                                break;

                            case 4:
                                if (algarismos[j] == 1)
                                {
                                    j++;
                                    //Caso o algarismo na dezena for 1, avança em um casa e avalia a unidade 
                                    printf(dezenasEspeciais[algarismos[j]]);
                                    //Utiliza o próprio algarismo para identificar a saída por extenso no vetor das dezenas especiais
                                }
                                else
                                {
                                    printf(dezenas[algarismos[j]]);
                                    //Utiliza o próprio algarismo para identificar a saída por extenso no vetor das dezenas
                                }
                                break;

                            case 5:
                                printf(unidades[algarismos[j]]);
                                //Utiliza o próprio algarismo para identificar a saída por extenso no vetor das unidades
                                break;

                            default:
                                break;
                            }
                            //Escreve mil quando pelo menos um algarismo antes da casa da centena não for nulo
                            if ((j == 2) && ((algarismos[0] != 0) || (algarismos[1] != 0) || (algarismos[2] != 0)))
                            {
                                //Escreve mil e apenas se houver numeros não nulos após a unidade de milhar ou se a centena for o único algarismo não nulo no resto do número 
                                if (((algarismos[3] == 0) && (algarismos[4] == 0) && (algarismos[5] == 0)) || ((algarismos[3] != 0) && ((algarismos[4] != 0) || (algarismos[5] != 0))))
                                {
                                    printf("Mil ");
                                }
                                else
                                {
                                    printf("Mil e ");
                                }
                            }
                            //Avalia quando escrever "e'"
                            //Escreve apenas se o algarismo analisado não for nulo ou da casa da unidade 
                            //Se o algarismo faz parte da centena de milhar ou centena e os próximos algarismos não são nulos
                            //Se o algarismo faz parte da dezena de milhar ou dezena e o próximo algarismo não é nulo
                            //Se o algarismo não fazer parte da unidade de milhar (já é escrito quando o mil é avaliado)
                            if ((j != 5) && (algarismos[j] != 0))
                            {
                                if (((j != 0) && (j != 3)) || ((algarismos[j + 1] != 0) || (algarismos[j + 2] != 0)))
                                {
                                    if (((j != 1) && (j != 4)) || ((algarismos[j + 1] != 0) && (algarismos[j] != 1)))
                                    {
                                        if (j != 2)
                                        {
                                            printf("e ");
                                        }
                                    }
                                }
                            }
                        }
                        printf("(%d) ", valorSaque);
                        //Quantifica o dinheiro acordo
                        if (valorSaque == 1)
                        {
                            printf("real ");
                        }
                        else
                        {
                            printf("reais ");
                        }
                        printf("foi realizado com sucesso!\nO dinheiro sera distribuido em:\n");
                        //Escreve apenas quais cedulas serão fofrnecidas 
                        for (i = 0; i < 8; i++)
                        {
                            if (quantidadeCedulasUsadas[i] != 0)
                            {
                                printf("%d ", quantidadeCedulasUsadas[i]);
                                //Quantiica as cedulas de acordo
                                if (quantidadeCedulasUsadas[i] == 1)
                                {
                                    printf("cedula ");
                                }
                                else
                                {
                                    printf("cedulas ");
                                }
                                printf("de %d\n", tipoDaCedula[i]);
                            }
                        }
                        //Atualiza quantos reais já foram sacados do caixa
                        valorTotalSacado += valorSacado;
                    }
                }
            }
            //Retorna para o menu principal
            pg = 0;
            break;
        case 2:
            while (pg == 2)
            {
                printf("\n-----Menu Gerente-----");
                printf("\n1- Valor total sacado");
                printf("\n2- Valor do saldo existente");
                printf("\n3- Quantidade de cedulas existentes");
                printf("\n4- Abastecer o caixa eletronico");
                printf("\n5- Voltar ao menu principal");
                printf("\nDigite uma opcao: ");
                scanf("%d", &pg);
                //Opções do Menu do Gerente 
                switch (pg)
                {
                case 1:
                    //Escreve por extenso o valor total sacado, segue os mesmos principios do caso anterior, exceto que não indica as cedulas 
                    printf("\n-----Valor total sacado-----");
                    num = valorTotalSacado;
                    for (j = 5; j >= 0; j--)
                    {
                        algarismos[j] = num % 10;
                        num /= 10;
                    }
                    printf("\nValor total sacado: ");
                    for (j = 0; j < 6; j++)
                    {
                        switch (j)
                        {
                        case 0:
                            if (algarismos[j] == 1)
                            {
                                if ((algarismos[j + 1] == 0) && (algarismos[j + 2] == 0))
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
                                printf(centenas[algarismos[j]]);
                            }
                            break;

                        case 1:
                            if (algarismos[j] == 1)
                            {
                                j++;
                                printf(dezenasEspeciais[algarismos[j]]);
                            }
                            else
                            {
                                printf(dezenas[algarismos[j]]);
                            }
                            break;

                        case 2:
                            if ((algarismos[j] != 1) || ((algarismos[j - 1] != 0) || (algarismos[j - 2] != 0)))
                                printf(unidades[algarismos[j]]);
                            break;

                        case 3:
                            if (algarismos[j] == 1)
                            {
                                if ((algarismos[j + 1] == 0) && (algarismos[j + 2] == 0))
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
                                printf(centenas[algarismos[j]]);
                            }
                            break;

                        case 4:
                            if (algarismos[j] == 1)
                            {
                                j++;
                                printf(dezenasEspeciais[algarismos[j]]);
                            }
                            else
                            {
                                printf(dezenas[algarismos[j]]);
                            }
                            break;

                        case 5:
                            printf(unidades[algarismos[j]]);
                            break;

                        default:
                            break;
                        }
                        if ((j == 2) && ((algarismos[0] != 0) || (algarismos[1] != 0) || (algarismos[2] != 0)))
                        {
                            if (((algarismos[3] == 0) && (algarismos[4] == 0) && (algarismos[5] == 0)) || ((algarismos[3] != 0) && ((algarismos[4] != 0) || (algarismos[5] != 0))))
                            {
                                printf("Mil ");
                            }
                            else
                            {
                                printf("Mil e ");
                            }
                        }

                        if ((j != 5) && (algarismos[j] != 0))
                        {
                            if (((j != 0) && (j != 3)) || ((algarismos[j + 1] != 0) || (algarismos[j + 2] != 0)))
                            {
                                if (((j != 1) && (j != 4)) || ((algarismos[j + 1] != 0) && (algarismos[j] != 1)))
                                {
                                    if (j != 2)
                                    {
                                        printf("e ");
                                    }
                                }
                            }
                        }
                    }
                    printf("(%d) ", valorTotalSacado);
                    if (valorTotalSacado == 1)
                    {
                        printf("real\n\n");
                    }
                    else
                    {
                        printf("reais\n\n");
                    }
                    //Volta para o Menu do gerente 
                    pg = 2;
                    break;
                case 2:
                    //Exibe o valor do saldo existente por extenso, mesma lógica que o caso anterior de escrever por extenso
                    printf("\n-----Valor do saldo existente-----");
                    //Atualiza o saldo existente
                    saldoExistente = 500 * totalCedulas[0] + 150 * totalCedulas[1] + 50 * totalCedulas[2] + 20 * totalCedulas[3] + 10 * totalCedulas[4] + 5 * totalCedulas[5] + 2 * totalCedulas[6] + 1 * totalCedulas[7];
                    num = saldoExistente;
                    for (j = 5; j >= 0; j--)
                    {
                        algarismos[j] = num % 10;
                        num /= 10;
                    }
                    printf("\nSaldo existente: ");
                    for (j = 0; j < 6; j++)
                    {
                        switch (j)
                        {
                        case 0:
                            if (algarismos[j] == 1)
                            {
                                if ((algarismos[j + 1] == 0) && (algarismos[j + 2] == 0))
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
                                printf(centenas[algarismos[j]]);
                            }
                            break;

                        case 1:
                            if (algarismos[j] == 1)
                            {
                                j++;
                                printf(dezenasEspeciais[algarismos[j]]);
                            }
                            else
                            {
                                printf(dezenas[algarismos[j]]);
                            }
                            break;

                        case 2:
                            if ((algarismos[j] != 1) || ((algarismos[j - 1] != 0) || (algarismos[j - 2] != 0)))
                                printf(unidades[algarismos[j]]);
                            break;

                        case 3:
                            if (algarismos[j] == 1)
                            {
                                if ((algarismos[j + 1] == 0) && (algarismos[j + 2] == 0))
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
                                printf(centenas[algarismos[j]]);
                            }
                            break;

                        case 4:
                            if (algarismos[j] == 1)
                            {
                                j++;
                                printf(dezenasEspeciais[algarismos[j]]);
                            }
                            else
                            {
                                printf(dezenas[algarismos[j]]);
                            }
                            break;

                        case 5:
                            printf(unidades[algarismos[j]]);
                            break;

                        default:
                            break;
                        }
                        if ((j == 2) && ((algarismos[0] != 0) || (algarismos[1] != 0) || (algarismos[2] != 0)))
                        {
                            if (((algarismos[3] == 0) && (algarismos[4] == 0) && (algarismos[5] == 0)) || ((algarismos[3] != 0) && ((algarismos[4] != 0) || (algarismos[5] != 0))))
                            {
                                printf("Mil ");
                            }
                            else
                            {
                                printf("Mil e ");
                            }
                        }

                        if ((j != 5) && (algarismos[j] != 0))
                        {
                            if (((j != 0) && (j != 3)) || ((algarismos[j + 1] != 0) || (algarismos[j + 2] != 0)))
                            {
                                if (((j != 1) && (j != 4)) || ((algarismos[j + 1] != 0) && (algarismos[j] != 1)))
                                {
                                    if (j != 2)
                                    {
                                        printf("e ");
                                    }
                                }
                            }
                        }
                    }
                    printf("(%d) ", saldoExistente);
                    if (saldoExistente == 1)
                    {
                        printf("real\n\n");
                    }
                    else
                    {
                        printf("reais\n\n");
                    }
                    //Volta para o Menu do Gerente
                    pg = 2;
                    break;
                case 3:
                    printf("\n-----Quantidade de cedulas existentes-----");
                    //Inicializa a variavel contadora em zero
                    totalNaMaquina = 0;

                    for (k = 0; k < 9; k++)
                    {
                        //Enquanto o vetor ainda está sendo analisado escreve a quantidade de cedulas de cada tipo
                        //Quando todas já foram escritas, atualiza o total de cedulas contadas
                        //Escreve tudo por extenso com a mesma lógica anterior
                        if (k != 8)
                        {
                            totalNaMaquina += totalCedulas[k];
                            printf("\n%d: restam ", tipoDaCedula[k]);
                            num = totalCedulas[k];
                        }
                        else
                        {
                            num = totalNaMaquina;
                            printf("\n\nTotal de cedulas na maquina: ");
                        }
                        for (j = 5; j >= 0; j--)
                        {
                            algarismos[j] = num % 10;
                            num /= 10;
                        }
                        for (j = 0; j < 6; j++)
                        {
                            switch (j)
                            {
                            case 1:
                                if (algarismos[j] == 1)
                                {
                                    j++;
                                    printf(dezenasEspeciais[algarismos[j]]);
                                }
                                else
                                {
                                    printf(dezenas[algarismos[j]]);
                                }
                                break;

                            case 2:
                                if ((algarismos[j] != 1) || ((algarismos[j - 1] != 0) || (algarismos[j - 2] != 0)))
                                    printf(unidades[algarismos[j]]);
                                break;

                            case 3:
                                if (algarismos[j] == 1)
                                {
                                    if ((algarismos[j + 1] == 0) && (algarismos[j + 2] == 0))
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
                                    printf(centenasCedulas[algarismos[j]]);
                                }
                                break;

                            case 4:
                                if (algarismos[j] == 1)
                                {
                                    j++;
                                    printf(dezenasEspeciais[algarismos[j]]);
                                }
                                else
                                {
                                    printf(dezenas[algarismos[j]]);
                                }
                                break;

                            case 5:
                                printf(unidadesCedula[algarismos[j]]);
                                break;

                            default:
                                break;
                            }
                            if ((j == 2) && ((algarismos[0] != 0) || (algarismos[1] != 0) || (algarismos[2] != 0)))
                            {
                                if (((algarismos[3] == 0) && (algarismos[4] == 0) && (algarismos[5] == 0)) || ((algarismos[3] != 0) && ((algarismos[4] != 0) || (algarismos[5] != 0))))
                                {
                                    printf("Mil ");
                                }
                                else
                                {
                                    printf("Mil e ");
                                }
                            }

                            if ((j != 5) && (algarismos[j] != 0))
                            {
                                if (((j != 0) && (j != 3)) || ((algarismos[j + 1] != 0) || (algarismos[j + 2] != 0)))
                                {
                                    if (((j != 1) && (j != 4)) || ((algarismos[j + 1] != 0) && (algarismos[j] != 1)))
                                    {
                                        if (j != 2)
                                        {
                                            printf("e ");
                                        }
                                    }
                                }
                            }
                        }
                        //Escreve as cedulas de cada tipo
                        if (k != 8)
                        {
                            printf("(%d) ", totalCedulas[k]);
                            if (totalCedulas[k] == 1)
                            {
                                printf("cedula ");
                            }
                            else
                            {
                                printf("cedulas ");
                            }
                            printf("de %d", tipoDaCedula[k]);
                        }
                        else
                        {
                            //Escreve o total de cedulas na maquina
                            printf("(%d) ", totalNaMaquina);
                            if (totalNaMaquina == 1)
                            {
                                printf("cedula ");
                            }
                            else
                            {
                                printf("cedulas ");
                            }
                        }
                    }
                    pg = 2;
                    //Volta para o Menu gerente
                    break;
                case 4:
                    do
                    {
                        //Menu abastecer 
                        printf("\n-----Menu Abastecer o Caixa Eletronico-----\n500-Cedulas de 500\n150-Cedulas de 150\n50-Cedulas de 50\n20-Cedulas de 20\n10-Cedulas de 10\n5-Cedulas de 5\n2-Cedulas de 2\n1-Cedulas de 1\n0-Voltar ao Menu Gerente");
                        printf("\nSelecione uma opcao: ");
                        scanf("%d", &tipo);
                        //Primeiro lê qual tipo de cedula deve ser reabastecida
                        //Depois lê quantas cedulas serão adicionadas
                        //Validando a entrada apenas se a quantidade não excede o limite da máquina, ou se é um valor válido
                        //Se a quantidade for valida, soma ela com o resto
                        switch (tipo)
                        {
                        case 500:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[0] > 100) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[0] += quantidade;
                                printf("Caixa eletronico abastecido com sucesso!");
                            }
                            break;
                        case 150:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[1] > 200) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[1] += quantidade;
                                printf("Caixa eletronico abastecido com sucesso!");
                            }
                            break;
                        case 50:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[2] > 400) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[2] += quantidade;
                                printf("Caixa eletronico abastecido com sucesso!");
                            }
                            break;
                        case 20:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[3] > 800) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[3] += quantidade;
                                printf("Caixa eletronico abastecido com sucesso!");
                            }
                            break;
                        case 10:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[4] > 1600) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[4] += quantidade;
                                printf("Caixa eletronico abastecido com sucesso!");
                            }
                            break;
                        case 5:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[5] > 3200) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[5] += quantidade;
                                printf("Caixa eletronico abastecido com sucesso!");
                            }
                            break;
                        case 2:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[6] > 6400) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[6] += quantidade;
                                printf("Caixa eletronico abastecido com sucesso!");
                            }
                            break;
                        case 1:
                            printf("\nInforme a quantidade de cedulas que serao colocadas: ");
                            scanf("%d", &quantidade);
                            if ((quantidade + totalCedulas[7] > 12800) || (quantidade <= 0))
                            {
                                printf("\nQuantidade invalida!");
                            }
                            else
                            {
                                totalCedulas[7] += quantidade;
                                printf("Caixa eletronico abastecido com sucesso!");
                            }
                            break;
                        case 0:
                            //Encerra o loop
                            printf("\nRetornando ao Menu do Gerente...");
                            break;
                        default:
                            printf("\nOpcao invalida!");
                            break;
                        }
                    } while (tipo != 0);
                    pg = 2;
                    //Volta para o Menu do gerente
                    break;
                case 5:
                    printf("\nVoltando para o menu principal...");
                    pg = 0;
                    //Volta para o Menu principal
                    break;
                default:
                    printf("\nOpcao Invalida!");
                    //Continua no menu do gerente até que uma opção válida seja informada 
                    pg = 2;
                    break;
                }
            }
            break;
        case 3:
            printf("\nFim da execucao.");
            return 0;
            //Encerra a execução
            break;
        default:
            printf("\nOpcao invalida!");
            pg = 0;
            //Permanece no menu principal até que uma opção valida seja inserida
            break;
        }
    }
}
