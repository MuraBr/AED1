// União de todas as funções
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Declaração de variaveis
    // Navegação nos menus
    int menu, pg;
    // validação do CPF

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
    for (l = 1; l < 8; l++)
        totalCedulas[l] = totalCedulas[l - 1] * 2;
    saldoExistente = 500 * totalCedulas[0] + 150 * totalCedulas[1] + 50 * totalCedulas[2] + 20 * totalCedulas[3] + 10 * totalCedulas[4] + 5 * totalCedulas[5] + 2 * totalCedulas[6] + 1 * totalCedulas[7];

    // Menu
    while (pg == 0)
    {
        printf("\n-----Menu Principal-----");
        printf("\n1- Saque");
        printf("\n2- Gerente");
        printf("\n3- Finalizar");
        printf("\nDigite uma opcao: ");
        scanf("%d", &pg);

        switch (pg)
        {
        case 1:
            printf("\n----Validar CPF-----");
            int calculocpf = 0;
            int verifica1 = 0;
            int verifica2;
            int teste = 0;
            int valicont = 9;
            int pot = 0;
            long int pote10 = 10;
            int cont = 10;
            int cpf1;
            int cpf2;
            int i = 0;
            int vetor[11];
            // pede para o usuario fornecer o cpf, primeiro os 9 primeors digiros depois os dois ultimos
            printf("\nForneca o cpf, digite os 9 primeiros digitos: ");
            scanf("%d", &cpf1);
            printf("\nForneca o cpf, digite os 2 ultimos digitos: ");
            scanf("%d", &cpf2);
            // coloca os valores inseridos anteriormente dentro de um vetor
            for (i = 0; i < 9; i++)
            {
                // variavel que sera a potencia, começa no 9 e vai diminuindo
                valicont = valicont - 1;
                // resultado da potencia de 10
                pot = pow(pote10, valicont);
                // if para garantir que o valor da potencia vai estar certo, pois por algum motivo aluns estavam vindo com valor -1
                if (pot % 2 == 1)
                {
                    pot = pot + 1;
                }
                // if para garantir a potencia certa
                if (pot == 2)
                {
                    pot = pot - 1;
                }
                vetor[i] = (cpf1 / pot) % 10;
            }
            // inserindo os dois ultimos digitos no vetor
            vetor[9] = (cpf2 / 10) % 10;
            vetor[10] = cpf2 % 10;
            // for para fazer a valicação do primeiro numero verificador do cpf
            for (i = 0; i < 9; i++)
            {
                // insere na variavel teste o valor respectivo do vetor
                teste = vetor[i];
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
                teste = vetor[i];
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
            if (verifica1 != vetor[9] || verifica2 != vetor[10])
            {
                // if para ter o 0 do cpf no printf
                if (vetor[0] == 0)
                {
                    printf("\nO cpf 0%d%d nao eh valido", cpf1, cpf2);
                }
                // caso não precise do 0, aqui é o print normal
                else
                {
                    printf("\nO cpf %d%d nao eh valido", cpf1, cpf2);
                }
            }
            else
            {
                // if para ter o 0 do cpf no printf
                if (vetor[0] == 0)
                {
                    printf("\nO cpf 0%d%d eh valido", cpf1, cpf2);
                }
                // caso não precise do 0, aqui é o print normal
                else
                {
                    printf("\nO cpf %d%d eh valido", cpf1, cpf2);
                }
                printf("\n----Saque-----");
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
                // atualia o valor do saldo existente
                saldoExistente = 500 * totalCedulas[0] + 150 * totalCedulas[1] + 50 * totalCedulas[2] + 20 * totalCedulas[3] + 10 * totalCedulas[4] + 5 * totalCedulas[5] + 2 * totalCedulas[6] + 1 * totalCedulas[7];
                if (valorSaque > saldoExistente)
                {
                    printf("Nao existe saldo suficiente no caixa eletronico para conceder o quantia exigida!\n");
                }
                else
                {
                    for (i = 0; i < 8; i++)
                    {
                        quantidadeCedulasPre[i] = totalCedulas[i];
                    }
                    i = 0;

                    // definicao da quantidade de cedulas
                    while (valorSaque > valorSacado)
                    {
                        while ((valorSaque >= valorSacado) && (totalCedulas[i] > 0))
                        {
                            valorSacado += tipoDaCedula[i];
                            quantidadeCedulasUsadas[i]++;
                            totalCedulas[i]--;
                        }
                        if (((totalCedulas[i] != 0)) || ((totalCedulas[i] == 0) && (valorSacado > valorSaque)))
                        {
                            valorSacado -= tipoDaCedula[i];
                            quantidadeCedulasUsadas[i]--;
                            totalCedulas[i]++;
                        }
                        i++;
                        if ((i == 8) && (valorSacado < valorSaque))
                        {
                            valorSacado = valorSaque + 1;
                            printf("\nNao foi possivel realizar o saque com as cedulas disponiveis!");
                            for (i = 0; i < 8; i++)
                            {
                                totalCedulas[i] = quantidadeCedulasPre[i];
                            }
                        }
                    }
                    // demonstracao
                    if (valorSacado == valorSaque)
                    {
                        num = valorSaque;
                        for (j = 5; j >= 0; j--)
                        {
                            algarismos[j] = num % 10;
                            num /= 10;
                        }
                        printf("\nO saque de ");
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
                        printf("(%d) ", valorSaque);
                        if (valorSaque == 1)
                        {
                            printf("real ");
                        }
                        else
                        {
                            printf("reais ");
                        }
                        printf("foi realizado com sucesso!\nO dinheiro sera distribuido em:\n");

                        for (i = 0; i < 8; i++)
                        {
                            if (quantidadeCedulasUsadas[i] != 0)
                            {
                                printf("%d ", quantidadeCedulasUsadas[i]);
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
                        valorTotalSacado += valorSacado;
                    }
                }
            }
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

                switch (pg)
                {
                case 1:
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
                    pg = 2;
                    break;
                case 2:
                    printf("\n-----Valor do saldo existente-----");
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
                    pg = 2;
                    break;
                case 3:
                    printf("\n-----Quantidade de cedulas existentes-----");
                    totalNaMaquina = 0;
                    for (k = 0; k < 9; k++)
                    {
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
                    break;
                case 4:
                    do
                    {
                        printf("\nMenu Abastecer o Caixa Eletronico\n500-Cedulas de 500\n150-Cedulas de 150\n50-Cedulas de 50\n20-Cedulas de 20\n10-Cedulas de 10\n5-Cedulas de 5\n2-Cedulas de 2\n1-Cedulas de 1\n0-Voltar ao Menu Gerente");
                        printf("\nSelecione uma opcao: ");
                        scanf("%d", &tipo);
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
                            printf("\nRetornando ao Menu do Gerente...");
                            break;
                        default:
                            printf("\nOpcao invalida!");
                            break;
                        }
                    } while (tipo != 0);
                    pg = 2;

                    break;
                case 5:
                    printf("\nVoltando para o menu principal...");
                    pg = 0;
                    break;
                default:
                    printf("\nOpcao Invalida!");
                    pg = 2;
                    break;
                }
            }
            break;
        case 3:
            printf("\nFim da execucao.");
            return 0;
            break;
        default:
            printf("\nOpcao invalida!");
            pg = 0;
            break;
        }
    }
}
