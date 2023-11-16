#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*------------------Objetivos-------------------
1. Inserir um cliente no cadastro
2. Excluir um cliente do cadastro
3. Listar os clientes do cadastro ordenados crescentemente pelo nome
4. Listar os clientes do cadastro ordenados crescentemente pelo nome por seleção de faixa de renda salarial mensal

obs:
1. Para inserir um cliente, gere automaticamente as informações do cliente, e o usuário decide se o cliente será inserido.
2. Na exclusão de um cliente o usuário fornece o cpf do cliente que deseja que seja excluído. Só poderá ser excluído um
cliente caso não há nenhuma venda registrada para ele.
3. O cpf do cliente deve ser valido
*/

//-------------------Estruturas------------------
#define TAM 50
struct ENDERECO
{
    char rua[TAM];
    int numero;
    char bairro[TAM];
    char cidade[TAM];
    char estado[3];
    char cep[11]; // 99.999-999
};
struct TELEFONE
{
    char telefone[14]; // 99 99999-9999
};
struct CLIENTE
{
    char nome[TAM];
    char cpf[15]; // 999.999.999-99
    struct ENDERECO endereco;
    struct TELEFONE residencial;
    struct TELEFONE celular[5];
    float renda_mensal;
};

char opcionais[][TAM] = {{"4.portas"}, {"cambio.automatico"}, {"vidros.eletricos"}, {"abs"}, {"air.bag"}, {"ar.condicionado"}, {"banco.couro"}, {"sensor.estacionamento"}};
struct CARRO
{
    char placa[9];         // AAA-1234
    char modelo[TAM];      // gol, celta, palio, ...
    char fabricante[TAM];  // chevrolet, fiat, ...
    int ano_fabricacao;    // 1980 à 2016
    int ano_modelo;        // 1980 à 2017
    char combustivel[TAM]; // alcool, gasolina, flex, diesel
    char cor[TAM];         // branca, prata, preta
    int opcional[8];       // ver matriz opcionais
    float preco_compra;
};
struct DATA
{
    int dia, mes, ano;
};
struct VENDA_CARRO
{
    char placa_car[9];
    char cpf_cli[15];
    float preco_venda;
    struct DATA data_venda;
};
//----------------------------------Gerais--------------------------------------------
int sistemaMenu()
{
    int opc;
    do
    {
        system("cls");
        printf("=== Menu Principal ===\n1. Carros\n\
2. Clientes\n\
3. Vendas\n\
4. Encerrar\n\
Qual funcao deve ser executada?\n");
        scanf("%d", &opc);
        if ((opc > 4) || (opc < 1))
        {
            printf("Opcao invalida!\n");
            system("pause");
        }
    } while ((opc > 4) || (opc < 1));
    if (opc == 4)
    {
        opc = 0;
    }
    return opc;
}
int sistemaClientes()
{
    int opc;
    do
    {
        system("cls");
        printf("=== Menu Clientes ===\n1. Inserir um cliente no cadastro\n\
2. Excluir um cliente do cadastro\n\
3. Listar os clientes em ordem crescente por nome\n\
4. Listar os clientes em ordem crescente pelo nome por selecao de faixa de renda mensal\n\
5. Voltar\n\
Qual funcao deve ser executada?\n");
        scanf("%d", &opc);
        if ((opc > 5) || (opc < 1))
        {
            printf("Opcao invalida!\n");
            system("pause");
        }
    } while ((opc > 5) || (opc < 1));
    if (opc == 5)
    {
        opc = 0;
    }
    return opc;
}

int sistemaCarros()
{
    int opc;
    do
    {
        system("cls");
        printf("=== Menu Carros ===\n1. Inserir um carro no cadastro\n\
2. Excluir um carro do cadastro\n\
3. Listar os carros disponiveis para venda em ordem crescente por fabricante\n\
4. Listar os carros disponiveis para venda por selecao de um ou mais opcionais\n\
5. Listar os carros disponiveis para venda por selecao da faixa de ano de fabricacao\n\
6. Voltar\n\
Qual funcao deve ser executada?\n");
        scanf("%d", &opc);
        if ((opc > 6) || (opc < 1))
        {
            printf("Opcao invalida!\n");
            system("pause");
        }
    } while ((opc > 6) || (opc < 1));
    if (opc == 6)
    {
        opc = 0;
    }
    return opc;
}
int sistemaVendas()
{
    int opc;
    do
    {
        system("cls");
        printf("=== Menu Vendas ===\n1. Inserir uma venda\n\
2. Excluir uma venda\n\
3. Listar os carros vendidos de um fabricante, ordenados pelo modelo\n\
4. Listar os carros vendidos de um modelo, ordenados por ano de fabricacao\n\
5. Informar a quantidade de carros vendidos com o valor totalizado dos precos vendidos\n\
6. Informar o lucro total das vendas\n\
7. Voltar\n\
Qual funcao deve ser executada?\n");
        scanf("%d", &opc);
        if ((opc > 7) || (opc < 1))
        {
            printf("Opcao invalida!\n");
            system("pause");
        }
    } while ((opc > 7) || (opc < 1));
    if (opc == 7)
    {
        opc = 0;
    }
    return opc;
}

FILE *abrirArquivo(const char *nome, const char *modo)
{
    FILE *arquivo;
    if ((arquivo = fopen(nome, modo)) == NULL)
    {
        printf("Nao foi possivel abrir o arquivo %s\n", nome);
        exit(100);
    }
    return arquivo;
}
int existeDadosClientes(const char *fileName)
{
    int flag = 0;
    FILE *arquivo = fopen(fileName, "rb");
    struct CLIENTE teste;
    if (arquivo != NULL)
    {
        if (fread(&teste, sizeof(struct CLIENTE), 1, arquivo))
        {
            flag = 1;
        }
        fclose(arquivo);
    }
    return flag;
}
int existeDadosCarros(const char *fileName)
{
    int flag = 0;
    FILE *arquivo = fopen(fileName, "rb");
    struct CARRO teste;
    if (arquivo != NULL)
    {
        if (fread(&teste, sizeof(struct CARRO), 1, arquivo))
        {
            flag = 1;
        }
        fclose(arquivo);
    }
    return flag;
}

int existeDadosVendas(const char *fileName)
{
    int flag = 0;
    FILE *arquivo = fopen(fileName, "rb");
    struct VENDA_CARRO teste;
    if (arquivo != NULL)
    {
        if (fread(&teste, sizeof(struct VENDA_CARRO), 1, arquivo))
        {
            flag = 1;
        }
        fclose(arquivo);
    }
    return flag;
}
int existePlacaCarro(const char *fileName, char placaCar[9])
{
    struct CARRO buffer;
    int flag = 0;
    if (existeDadosCarros(fileName))
    {
        FILE *arquivo = abrirArquivo(fileName, "rb");

        while ((flag == 0) && (fread(&buffer, sizeof(struct CARRO), 1, arquivo)))
        {
            if (memcmp(buffer.placa, placaCar, 9) == 0)
            {
                flag = 1;
            }
        }
        fclose(arquivo);
    }
    return flag;
}

int existeCpfCliente(const char *fileName, char cpfC[15])
{
    struct CLIENTE buffer;
    int flag = 0;
    if (existeDadosClientes(fileName))
    {
        FILE *arquivo = fopen(fileName, "rb");
        while ((fread(&buffer, sizeof(struct CLIENTE), 1, arquivo)) && (flag == 0))
        {
            if (memcmp(buffer.cpf, cpfC, 15) == 0)
            {
                flag = 1;
            }
        }
    fclose(arquivo);

    }
    return flag;
}

int existeNomeCliente(const char *fileName, char nomeC[TAM])
{
    struct CLIENTE buffer;
    int flag = 0;
    if (existeDadosClientes(fileName))
    {
        FILE *arquivo = fopen(fileName, "rb");
        while ((fread(&buffer, sizeof(struct CLIENTE), 1, arquivo)) && (flag == 0))
        {
            if (memcmp(buffer.nome, nomeC, TAM) == 0)
            {
                flag = 1;
            }
        }
        fclose(arquivo);
    }
    return flag;
}

int existeCompraCpf(const char *fileName, char cpfC[15])
{
    int flag = 0, tam = sizeof(struct VENDA_CARRO);
    struct VENDA_CARRO buffer;
    if (existeDadosVendas(fileName))
    {
        FILE *arquivo = abrirArquivo(fileName, "rb");
        while ((flag == 0) && (fread(&buffer, tam, 1, arquivo)))
        {
            if (memcmp(buffer.cpf_cli, cpfC, 15) == 0)
            {
                flag = 1;
            }
        }
        fclose(arquivo);
    }
    return flag;
}

int existeVendaPlaca(const char *fileName, char placaC[9])
{
    int flag = 0, tam = sizeof(struct VENDA_CARRO);
    struct VENDA_CARRO buffer;
    if (existeDadosVendas(fileName))
    {
        FILE *arquivo = abrirArquivo(fileName, "rb");
        while ((flag == 0) && (fread(&buffer, tam, 1, arquivo)))
        {
            if (memcmp(buffer.placa_car, placaC, 9) == 0)
            {
                flag = 1;
            }
        }
        fclose(arquivo);
    }
    return flag;
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

void lerCPF(char cpf[15])
{
    char cpfaux[15];
    int flag = 0;
    do
    {
        printf("Digite um cpf valido:\n");
        fflush(stdin);
        scanf("%s", cpfaux);
    } while (!verifica_cpf_valido(cpfaux));
    strcpy(cpf, cpfaux);
}

void lerOpcionais(int opcEscolhidos[8])
{
    int opc, continuar = 0, i;
    do
    {
        system("cls");
        printf("Opcionais possiveis:\n1. 4.portas\n\
2. cambio.automatico\n\
3. vidros.eletricos\n\
4. abs\n\
5. air.bag\n\
6. ar.condicionado\n\
7. banco.couro\n\
8. sensor.estacionamento\n\
Informe um ou mais que deseja ver:\n");
        scanf("%d", &opc);
        if ((opc > 8) || (opc < 1))
        {
            printf("Opcao invalida!\n");
            system("pause");
        }
        else
        {
            opcEscolhidos[opc - 1] = 1;
            printf("Deseja escolher mais algum opcional?\nDigite 1 para sim e 0 para nao:\n");
            scanf("%d", &continuar);
        }
    } while (((opc > 8) || (opc < 1)) || (continuar == 1));
    printf("As opcoes escolhidas foram: \n");
    for (i = 0; i < 8; i++)
    {
        if (opcEscolhidos[i] == 1)
        {
            printf("%s\n", opcionais[i]);
        }
    }
}
float getPrecoVenda(const char *fileName, char placaC[9])
{
    FILE *arquivo;
    arquivo = abrirArquivo(fileName, "rb");
    struct CARRO comp, aux;
    int tam = sizeof(struct CARRO);
    while (fread(&comp, tam, 1, arquivo))
    {
        if (memcmp(comp.placa, placaC, 9) == 0)
        {
            fclose(arquivo);
            return comp.preco_compra;
        }
    }
    fclose(arquivo);
}
void getNomeClienteFromCPF(const char *fileName, char cpfC[15], char nomeC[TAM])
{
    FILE *arquivo = abrirArquivo(fileName, "rb");
    struct CLIENTE aux;
    int flag = 0;
    while ((flag == 0) && (fread(&aux, sizeof(struct CLIENTE), 1, arquivo)))
    {
        if (memcmp(cpfC, aux.cpf, 15) == 0)
        {
            strcpy(nomeC, aux.nome);
            flag = 1;
        }
    }
    fclose(arquivo);
}

void getCarroFromPlaca(const char *fileName, char placaC[9], char fabricanteC[TAM], char modeloC[TAM], int *anoFab)
{
    FILE *arquivo = abrirArquivo(fileName, "rb");
    struct CARRO aux;
    int flag = 0;
    while ((flag == 0) && (fread(&aux, sizeof(struct CARRO), 1, arquivo)))
    {
        if (memcmp(placaC, aux.placa, 9) == 0)
        {
            strcpy(fabricanteC, aux.fabricante);
            strcpy(modeloC, aux.modelo);
            flag = 1;
        }
    }
    fclose(arquivo);
}

float calculaLucroTotal(const char *fileName)
{
    FILE *arquivo;
    arquivo = abrirArquivo(fileName, "rb");
    struct VENDA_CARRO aux;
    int tam = sizeof(struct VENDA_CARRO);
    float lucroSomado = 0;
    while (fread(&aux, tam, 1, arquivo))
    {
        lucroSomado += aux.preco_venda;
    }
    fclose(arquivo);
    return lucroSomado;
}

void alternarClientes(struct CLIENTE *cl1, struct CLIENTE *cl2)
{
    struct CLIENTE aux;

    aux = *cl1;
    *cl1 = *cl2;
    *cl2 = aux;
}

void alternarCarros(struct CARRO *car1, struct CARRO *car2)
{
    struct CARRO carAux;
    carAux = *car1;
    *car1 = *car2;
    *car2 = carAux;
}

void alternarVendas(struct VENDA_CARRO *venda1, struct VENDA_CARRO *venda2)
{
    struct VENDA_CARRO vendaAux;
    vendaAux = *venda1;
    *venda1 = *venda2;
    *venda2 = vendaAux;
}
//------------------Gerar Dados-----------------
void geraNome(char nome[])
{
    int i;
    char nomes[][TAM] = {{"Joao"}, {"Camila"}, {"Felipe"}, {"Vinicius"}, {"Roberto"}, {"Arthur"}, {"Maria"}, {"Bianca"}, {"Flavia"}, {"Guilherme"}, {"Tais"}, {"Melissa"}, {"Priscila"}};
    char sobrenomes[][TAM] = {{"Silva"}, {"Ribas"}, {"Medeiros"}, {"Marques"}, {"Fernandes"}, {"Antunes"}, {"Costa"}, {"Alves"}};
    i = rand() % 13;
    strcpy(nome, nomes[i]);
    strcat(nome, " ");
    i = rand() % 8;
    strcat(nome, sobrenomes[i]);
}

char geraNumero()
{
    char num;
    num = (rand() % 10) + 48;
    return num;
}

void geraRua(char rua[])
{
    char ruas[][TAM] = {{"Ipanema"}, {"Rio de Janeiro"}};
    int i = rand() % 2;
    strcpy(rua, ruas[i]);
}

void geraNumeroCasa(int *numCasa)
{
    *numCasa = (rand() % 100) + 1;
}

void geraBairro(char bairro[])
{
    char bairros[][TAM] = {{"Porto Belo"}, {"Jardim Agua Boa"}, {"Vila Industrial"}, {"Altos do Indaia"}, {"Parque Alvorada"}, {"Monte Verde"}, {"Ouro Verde"}};
    int i = rand() % 7;
    strcpy(bairro, bairros[i]);
}

void geraCidade(char cidade[])
{
    char cidades[][TAM] = {{"Meia Praia"}, {"Curitiba"}, {"Dourados"}, {"Maracaju"}, {"Montese"}, {"Sao Paulo"}, {"Osasco"}, {"Campo Grande"}, {"Bonito"}, {"Vicentina"}, {"Rio Brilhante"}};
    int i = rand() % 11;
    strcpy(cidade, cidades[i]);
}

void geraEstado(char estado[])
{
    char estados[][3] = {{"AC"}, {"AL"}, {"AP"}, {"AM"}, {"BA"}, {"CE"}, {"ES"}, {"GO"}, {"MA"}, {"MT"}, {"MS"}, {"MG"}, {"PA"}, {"PB"}, {"PR"}, {"PE"}, {"PI"}, {"RJ"}, {"RN"}, {"RS"}, {"RO"}, {"RR"}, {"SC"}, {"SP"}, {"SE"}, {"TO"}, {"DF"}};
    int i = rand() % 27;
    strcpy(estado, estados[i]);
}

void geraCEP(char cep[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        cep[i] = geraNumero();
    }
    cep[2] = '.';
    cep[6] = '-';
    cep[10] = '\0';
}

// objetivo:gera aleatoriamente um cpf valido no formato 999.999.999-99
// parametros: o cpf onde sera armazenado o cpf valido
// retorno: nenhum
void geraCpf(char cpf[])
{
    int i;
    char cpf_processo[11];
    // Elimina possiveis residuos no vetor de cpf_proccesso
    memset(cpf, 0, 15);
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

void geraEndereco(struct ENDERECO *end)
{
    geraBairro(end->bairro);
    geraCEP(end->cep);
    geraCidade(end->cidade);
    geraRua(end->rua);
    geraEstado(end->estado);
    geraNumeroCasa(&(end->numero));
}

void geraTelefone(struct TELEFONE *tel)
{
    char numeroT[14];
    int i;
    for (i = 0; i < 13; i++)
    {
        numeroT[i] = geraNumero();
    }
    numeroT[2] = '-';
    numeroT[8] = '-';
    numeroT[13] = '\0';
    strcpy(tel->telefone, numeroT);
}

void geraRenda(float *renda)
{
    *(renda) = (rand() % 20000) * 1.5;
}

char geraAlfabeto()
{
    char letra;
    letra = (rand() % 26) + 65;
    return letra;
}

void gerarPlaca(char placaC[9])
{
    memset(placaC, 0, 9);
    int i;
    for (i = 0; i < 8; i++)
    {
        if (i < 3)
        {
            placaC[i] = geraAlfabeto();
        }
        else if (i == 3)
        {
            placaC[i] = '-';
        }
        else
        {
            placaC[i] = geraNumero();
        }
    }
}

void gerarFabricante(char fabricante[TAM])
{
    memset(fabricante, 0, strlen(fabricante));
    int i;
    i = rand() % 4;
    if (i == 0)
    {
        strcpy(fabricante, "fiat");
    }
    if (i == 1)
    {
        strcpy(fabricante, "volkswagen");
    }
    if (i == 2)
    {
        strcpy(fabricante, "toyota");
    }
    if (i == 3)
    {
        strcpy(fabricante, "chevrolet");
    }
}

void gerarModelo(char fabricante[TAM], char modelo[TAM], float *preco_compra)
{
    int j = rand() % 3;
    memset(modelo, 0, strlen(modelo));
    switch (fabricante[0])
    {
    case 'c':
        if (j == 0)
        {
            strcpy(modelo, "Onix");
            *(preco_compra) = 80000;
        }
        if (j == 1)
        {
            strcpy(modelo, "S10");
            *(preco_compra) = 100000;
        }
        if (j == 2)
        {
            strcpy(modelo, "Cruze");
            *(preco_compra) = 70000;
        }
        break;
    case 't':
        if (j == 0)
        {
            strcpy(modelo, "Corolla");
            *(preco_compra) = 73000;
        }
        if (j == 1)
        {
            strcpy(modelo, "Etios");
            *(preco_compra) = 40000;
        }
        if (j == 2)
        {
            strcpy(modelo, "Hilux");
            *(preco_compra) = 100000;
        }
        break;
    case 'f':
        if (j == 0)
        {
            strcpy(modelo, "Strada");
            *(preco_compra) = 55000;
        }
        if (j == 1)
        {
            strcpy(modelo, "Uno");
            *(preco_compra) = 40000;
        }
        if (j == 2)
        {
            strcpy(modelo, "Mobi");
            *(preco_compra) = 50000;
        }
        break;
    case 'v':
        if (j == 0)
        {
            strcpy(modelo, "Saveiro");
            *(preco_compra) = 58000;
        }
        if (j == 1)
        {
            strcpy(modelo, "Fox");
            *(preco_compra) = 40000;
        }
        if (j == 2)
        {
            strcpy(modelo, "Gol");
            *(preco_compra) = 40000;
        }
        break;
    }
}

void gerarAnoFabricacao(int *ano_fabricacao, float *preco_compra)
{
    int i, calculo;
    i = rand() % 37;
    *(ano_fabricacao) = 1980 + i;
    calculo = *(ano_fabricacao)-2016;
    *(preco_compra) = *(preco_compra) + (1000 * calculo);
}
void gerarAnoModelo(int ano_fabricacao, int *ano_modelo)
{
    int i;
    i = rand() % 3;
    *(ano_modelo) = ano_fabricacao + i;
}

void gerarGasolina(char combustivel[TAM])
{
    int i;
    i = rand() % 4;
    memset(combustivel, 0, strlen(combustivel));
    if (i == 0)
    {
        strcpy(combustivel, "gasolina");
    }
    if (i == 1)
    {
        strcpy(combustivel, "alcool");
    }
    if (i == 2)
    {
        strcpy(combustivel, "flex");
    }
    if (i == 3)
    {
        strcpy(combustivel, "diesel");
    }
}

void gerarCor(char cor[TAM])
{
    int i;
    memset(cor, 0, strlen(cor));
    i = rand() % 3;
    if (i == 0)
    {
        strcpy(cor, "branca");
    }
    if (i == 1)
    {
        strcpy(cor, "prata");
    }
    if (i == 2)
    {
        strcpy(cor, "preta");
    }
}
void gerarOpcional(int opcional[])
{
    int k, j;
    for (j = 0; j < 8; j++)
    {
        k = rand() % 2;
        opcional[j] = k;
    }
}

//--------------------Exibir----------------------------------------------------------------------------------
void mostrarCliente(struct CLIENTE bcliente)
{
    int i;
    printf("------------------------------------------------------------------------------\n");
    printf("Nome: %s\n", bcliente.nome);
    printf("CPF: %s\n", bcliente.cpf);
    printf("Renda Mensal: %.2f\n", bcliente.renda_mensal);
    printf("---Endereco---\n");
    printf("Rua: %s\nNumero: %d\nBairro: %s\nCidade: %s\nEstado: %s\nCEP: %s\n",
           bcliente.endereco.rua, bcliente.endereco.numero, bcliente.endereco.bairro, bcliente.endereco.cidade,
           bcliente.endereco.estado, bcliente.endereco.cep);
    printf("---Contato---\n");
    printf("Telefone residencial: %s\n", bcliente.residencial.telefone);
    for (i = 0; i < 5; i++)
    {
        printf("Celular (%d): %s\n", i + 1, bcliente.celular[i].telefone);
    }
}

void mostrarArquivoClientes(const char *fileName)
{
    struct CLIENTE bcliente;
    FILE *arquivo = abrirArquivo(fileName, "rb");
    int tam = sizeof(struct CLIENTE), i;
    while (fread(&bcliente, tam, 1, arquivo))
    {
        mostrarCliente(bcliente);
    }
    fclose(arquivo);
}
void mostrarClienteOrdemNome(const char *fileName)
{
    FILE *arquivo = abrirArquivo(fileName, "rb");
    int i = 0, j, k, tam = sizeof(struct CLIENTE);
    struct CLIENTE ordem[50];
    while (fread(&ordem[i], tam, 1, arquivo))
    {
        i++;
    }
    fclose(arquivo);
    for (j = 0; j < i; j++)
    {
        for (k = j + 1; k < i; k++)
        {
            if (strcmp(ordem[j].nome, ordem[k].nome) > 0)
            {
                alternarClientes(&ordem[j], &ordem[k]);
            }
        }
    }
    for (j = 0; j < i; j++)
    {
        mostrarCliente(ordem[j]);
    }
}

void mostrarClienteOrdemFaixaRenda(const char *fileName)
{
    FILE *arquivo = abrirArquivo(fileName, "rb");
    int i = 0, j, k, tam = sizeof(struct CLIENTE);
    float faixaUp, faixaDown;
    struct CLIENTE ordem[50], buffer;

    printf("Informe o intervalo de renda para mostrar:\n");
    printf("Maximo:\n");
    scanf("%f", &faixaUp);
    printf("Minimo:\n");
    scanf("%f", &faixaDown);

    while (fread(&buffer, tam, 1, arquivo))
    {
        if ((buffer.renda_mensal > faixaDown) && (buffer.renda_mensal < faixaUp))
        {
            ordem[i] = buffer;
            i++;
        }
    }
    fclose(arquivo);
    if (i != 0)
    {
        for (j = 0; j < i; j++)
        {
            for (k = j + 1; k < i; k++)
            {
                if (strcmp(ordem[j].nome, ordem[k].nome) > 0)
                {
                    alternarClientes(&ordem[j], &ordem[k]);
                }
            }
        }
        for (j = 0; j < i; j++)
        {
            mostrarCliente(ordem[j]);
        }
    }
    else
    {
        printf("Nao ha nenhum cliente com essa faixa de renda!\n");
    }
}
void mostrarCarro(struct CARRO car)
{
    int i, cont = 0;
    printf("------------------------------------------------------------------------------\n");
    printf("Placa: %s\n", car.placa);
    printf("Modelo: %s\n", car.modelo);
    printf("Fabricante: %s\n", car.fabricante);
    printf("Ano de Fabricacao: %d\n", car.ano_fabricacao);
    printf("Ano Modelo: %d\n", car.ano_modelo);
    printf("Combustivel: %s\n", car.combustivel);
    printf("Cor: %s\n", car.cor);
    printf("Opcional: ");
    for (i = 0; i < 8; i++)
    {
        if (car.opcional[i] == 1)
        {
            if (cont == 1)
            {
                printf(", ");
            }
            printf("%s", opcionais[i]);
            cont = 1;
        }
    }
    printf("\n");
    printf("Preco de Compra: %.2f\n", car.preco_compra);
}

void mostrarCarroOrdemFabricante(const char *fileName, const char *fileVendas)
{
    FILE *arquivo = abrirArquivo(fileName, "rb");
    int i = 0, j, k, tam = sizeof(struct CARRO);
    struct CARRO ordem[50], buffer;
    while (fread(&buffer, tam, 1, arquivo))
    {
        if (!existeVendaPlaca(fileVendas, ordem[i].placa))
        {
            ordem[i] = buffer;
            i++;
        }
    }
    fclose(arquivo);
    for (j = 0; j < i; j++)
    {
        for (k = j + 1; k < i; k++)
        {
            if (strcmp(ordem[j].fabricante, ordem[k].fabricante) > 0)
            {
                alternarCarros(&ordem[j], &ordem[k]);
            }
            if (strcmp(ordem[j].fabricante, ordem[k].fabricante) == 0)
            {
                if (strcmp(ordem[j].modelo, ordem[k].modelo) > 0)
                {
                    alternarCarros(&ordem[j], &ordem[k]);
                }
            }
        }
    }
    for (j = 0; j < i; j++)
    {
        mostrarCarro(ordem[j]);
    }
}
void mostrarCarroFaixaAnoFabricacao(const char *fileName, const char *fileVendas)
{
    FILE *arquivo = abrirArquivo(fileName, "rb");
    int i = 0, j, k, tam = sizeof(struct CARRO), faixaUp, faixaDown;
    struct CARRO lista[50], buffer;

    printf("Informe o intervalo de ano de fabricacao para mostrar:\n");
    printf("Maximo:\n");
    scanf("%d", &faixaUp);
    printf("Minimo:\n");
    scanf("%d", &faixaDown);

    while (fread(&buffer, tam, 1, arquivo))
    {
        if ((buffer.ano_fabricacao > faixaDown) && (buffer.ano_fabricacao < faixaUp))
        {
            if (!existeVendaPlaca(fileVendas, buffer.placa))
            {
                lista[i] = buffer;
                i++;
            }
        }
    }
    fclose(arquivo);
    if (i != 0)
    {
        for (j = 0; j < i; j++)
        {
            mostrarCarro(lista[j]);
        }
    }
    else
    {
        printf("Nao ha nenhum carro com fabricacao nesse intervalo de tempo!\n");
    }
}

void mostrarCarroFaixaOpcionais(const char *fileName, const char *fileVendas)
{
    int opcionaisEscolhidos[8], i, flag = 0, stop, tam = sizeof(struct CARRO);
    FILE *arquivo;
    struct CARRO buffer;
    for (i = 0; i < 8; i++)
    {
        opcionaisEscolhidos[i] = 0;
    }

    lerOpcionais(opcionaisEscolhidos);

    arquivo = abrirArquivo(fileName, "rb");
    while (fread(&buffer, tam, 1, arquivo))
    {
        stop = 0;
        for (i = 0; (i < 8) && (stop == 0); i++)
        {
            if ((opcionaisEscolhidos[i] == 1) && (buffer.opcional[i] == 1))
            {
                if (!existeVendaPlaca(fileVendas, buffer.placa))
                {
                    mostrarCarro(buffer);
                    stop = 1;
                    flag = 1;
                }
            }
        }
    }
    fclose(arquivo);
    if (flag == 0)
    {
        printf("Nenhum carro possui algum dos opcionais inseridos!\n");
    }
}
void mostrarVenda(struct VENDA_CARRO vendaC)
{
    printf("------------------------------------------------------------------------------\n");
    printf("Placa do Carro: %s\n", vendaC.placa_car);
    printf("CPF do Cliente: %s\n", vendaC.cpf_cli);
    printf("Valor da venda: %.2f\n", vendaC.preco_venda);
    printf("---Data da Venda---\n");
    printf("Dia: %d\n", vendaC.data_venda.dia);
    printf("Mes: %d\n", vendaC.data_venda.mes);
    printf("Ano: %d\n", vendaC.data_venda.ano);
}

void mostrarNumTotalVendas(const char *fileName)
{
    int numVendas = 0, tam = sizeof(struct VENDA_CARRO), flag = 0, i, k = 0, numVendasPreco[50];
    FILE *arquivo = abrirArquivo(fileName, "rb");
    struct VENDA_CARRO aux;
    float valoresVendas[50];
    for (i = 0; i < 50; i++)
    {
        valoresVendas[i] = 0;
        numVendasPreco[i] = 0;
    }
    while (fwrite(&aux, tam, 1, arquivo))
    {
        flag = 0;
        numVendas++;
        for (i = 0; i < numVendas; i++)
        {
            if (valoresVendas[i] == aux.preco_venda)
            {
                flag = 1;
                numVendasPreco[i]++;
            }
        }
        if (flag == 0)
        {
            valoresVendas[k] = aux.preco_venda;
            numVendasPreco[k] = 1;
            k++;
        }
    }
    fclose(arquivo);
    printf("O numero total de vendas e de: %d\n", numVendas);
    for (i = 0; i < numVendas; i++)
    {
        printf("%d venda(s) valendo %.2f", numVendasPreco[i], valoresVendas[i]);
    }
}

void mostrarVendasFabricante(const char *fileName, char fabricante[TAM])
{
    FILE *arquivo = abrirArquivo(fileName, "rb");
    int i = 0, j, k, tam = sizeof(struct VENDA_CARRO);
    struct VENDA_CARRO buffer;
    struct EXIBIR
    {
        char nomeAux[TAM], modeloAux[TAM], fabricanteAux[TAM], placaAux[9];
        int anoFabricacao;
    };
    struct EXIBIR ordem[50], aux;
    while (fread(&buffer, tam, 1, arquivo))
    {
        getCarroFromPlaca("carros.dat", buffer.placa_car, aux.fabricanteAux, aux.modeloAux, &aux.anoFabricacao);
        if (memcmp(fabricante, aux.fabricanteAux, TAM) == 0)
        {
            getNomeClienteFromCPF("clientes.dat", buffer.cpf_cli, aux.nomeAux);
            strcpy(aux.placaAux, buffer.placa_car);
            ordem[i] = aux;
            i++;
        }
    }
    fclose(arquivo);

    if (i != 0)
    {
        for (j = 0; j < i; j++)
        {
            for (k = j + 1; k < i; k++)
            {
                if (strcmp(ordem[j].modeloAux, ordem[k].modeloAux) > 0)
                {
                    aux = ordem[j];
                    ordem[j] = ordem[k];
                    ordem[k] = aux;
                }
            }
        }
        printf("Carros vendidos da %s\n", fabricante);
        for (j = 0; j < i; j++)
        {
            printf("------------------------------------------------------------------------------\n");
            printf("Nome do Cliente: %s\n", ordem[j].nomeAux);
            printf("Placa do Carro: %s\n", ordem[j].placaAux);
            printf("Nome do Cliente: %s\n", ordem[j].modeloAux);
            printf("Nome do Cliente: %d\n", ordem[j].anoFabricacao);
        }
    }
    else
    {
        printf("Nenhum carro desta fabricante foi vendido!\n");
    }
}

void mostrarVendasModelo(const char *fileName, char modelo[TAM])
{
    FILE *arquivo = abrirArquivo(fileName, "rb");
    int i = 0, j, k, tam = sizeof(struct VENDA_CARRO);
    struct VENDA_CARRO buffer;
    struct EXIBIR
    {
        char nomeAux[TAM], modeloAux[TAM], placaAux[9];
        int anoFabricacao;
    };
    struct EXIBIR ordem[50], aux;
    char fabricante[TAM];
    while (fread(&buffer, tam, 1, arquivo))
    {
        getCarroFromPlaca("carros.dat", buffer.placa_car, fabricante, aux.modeloAux, &aux.anoFabricacao);
        if (memcmp(modelo, aux.modeloAux, TAM) == 0)
        {
            getNomeClienteFromCPF("clientes.dat", buffer.cpf_cli, aux.nomeAux);
            strcpy(aux.placaAux, buffer.placa_car);
            ordem[i] = aux;
            i++;
        }
    }
    fclose(arquivo);
    if (i != 0)
    {
        for (j = 0; j < i; j++)
        {
            for (k = j + 1; k < i; k++)
            {
                if (ordem[j].anoFabricacao > ordem[k].anoFabricacao)
                {
                    aux = ordem[j];
                    ordem[j] = ordem[k];
                    ordem[k] = aux;
                }
            }
        }
        printf("Carros vendidos do modelo %s\n", modelo);
        for (j = 0; j < i; j++)
        {
            printf("------------------------------------------------------------------------------\n");
            printf("Nome do Cliente: %s\n", ordem[j].nomeAux);
            printf("Placa do Carro: %s\n", ordem[j].placaAux);
            printf("Nome do Cliente: %d\n", ordem[j].anoFabricacao);
        }
    }
    else
    {
        printf("Nenhum carro deste modelo foi vendido!\n");
    }
}
//-------------------Incluir----------------------------------------------------------------------------------------
void inserirCliente(const char *fileName)
{
    struct CLIENTE bpessoa;
    int escolha, i;
    do
    {
        do
        {
            geraNome(bpessoa.nome); // char nome[TAM];
        } while (existeNomeCliente(fileName, bpessoa.nome));
        do
        {
            geraCpf(bpessoa.cpf); // char cpf[15]; //999.999.999-99
        } while (existeCpfCliente(fileName, bpessoa.cpf));
        geraRenda(&bpessoa.renda_mensal);
        geraEndereco(&(bpessoa.endereco));
        geraTelefone(&(bpessoa.residencial));
        for (i = 0; i < 5; i++)
        {
            geraTelefone(&(bpessoa.celular[i]));
        }
        mostrarCliente(bpessoa);
        printf("------------------------------------------------------------------------------\n");
        printf("Deseja inserir o cliente? Digite 1 para Sim e 0 para nao\n");
        scanf("%d", &escolha);
        system("cls");
    } while (escolha == 0);
    FILE *arquivo = abrirArquivo(fileName, "ab");
    fwrite(&bpessoa, sizeof(struct CLIENTE), 1, arquivo);
    fclose(arquivo);
}
void inserirCarro(const char *fileName)
{
    int escolha, tam = sizeof(struct CARRO);
    struct CARRO car;
    FILE *arquivo;
    do
    {
        do
        {
            gerarPlaca(car.placa);
        } while (existePlacaCarro(fileName, car.placa));
        gerarFabricante(car.fabricante);
        gerarModelo(car.fabricante, car.modelo, &car.preco_compra);
        gerarAnoFabricacao(&car.ano_fabricacao, &car.preco_compra);
        gerarAnoModelo(car.ano_fabricacao, &car.ano_modelo);
        gerarGasolina(car.combustivel);
        gerarCor(car.cor);
        gerarOpcional(car.opcional);
        mostrarCarro(car);
        printf("------------------------------------------------------------------------------\n");
        printf("Deseja inserir o carro? Digite 1 para Sim e 0 para nao\n");
        scanf("%d", &escolha);
        system("cls");
    } while (!escolha);
    arquivo = abrirArquivo(fileName, "ab");
    fwrite(&car, tam, 1, arquivo);
    fclose(arquivo);
}
void inserirVenda(const char *fileName, char cpfC[15], char placaC[9], float precoVenda)
{
    struct VENDA_CARRO vendaC;
    int tam = sizeof(struct VENDA_CARRO);
    FILE *arquivo;
    strcpy(vendaC.cpf_cli, cpfC);
    strcpy(vendaC.placa_car, placaC);
    vendaC.preco_venda = precoVenda;
    vendaC.data_venda.dia = 1 + (rand() % 28);
    vendaC.data_venda.mes = 1 + (rand() % 12);
    vendaC.data_venda.ano = 2010 + (rand() % 14);
    arquivo = abrirArquivo(fileName, "ab");
    fwrite(&vendaC, tam, 1, arquivo);
    fclose(arquivo);
    printf("Detalhes da Venda:\n");
    mostrarVenda(vendaC);
}
//-------------------Excluir---------------------------------------------------------------------------------------
void excluirCliente(const char *filename, char cpfC[15])
{
    FILE *arquivo = abrirArquivo(filename, "rb");
    struct CLIENTE v[TAM], buffer;
    int tam = sizeof(struct CLIENTE), i = 0, j;

    while (fread(&buffer, tam, 1, arquivo))
    {
        if (memcmp(buffer.cpf, cpfC, 15) != 0)
        {
            v[i] = buffer;
            i++;
        }
    }
    fclose(arquivo);
    remove(filename);
    arquivo = abrirArquivo(filename, "wb");
    for (j = 0; j < i; j++)
    {
        fwrite(&v[j], tam, 1, arquivo);
    }
    fclose(arquivo);
}
void excluirCarro(const char *filename, char placaC[9])
{
    FILE *arquivo = abrirArquivo(filename, "rb");
    struct CARRO v[TAM], buffer;
    int tam = sizeof(struct CARRO), i = 0, j;

    while (fread(&buffer, tam, 1, arquivo))
    {
        if (memcmp(buffer.placa, placaC, 9) != 0)
        {
            v[i] = buffer;
            i++;
        }
    }
    fclose(arquivo);
    remove(filename);
    arquivo = abrirArquivo(filename, "wb");
    for (j = 0; j < i; j++)
    {
        fwrite(&v[j], tam, 1, arquivo);
    }
    fclose(arquivo);
}
void excluirVenda(const char *fileName, char placaC[9])
{
    struct VENDA_CARRO buffer, v[TAM];
    int tam = sizeof(struct VENDA_CARRO), i = 0, j;
    FILE *arquivo;
    while (fread(&buffer, tam, 1, arquivo))
    {
        if (memcmp(buffer.placa_car, placaC, 9) != 0)
        {
            v[i] = buffer;
            i++;
        }
    }
    fclose(arquivo);
    remove(fileName);
    arquivo = abrirArquivo(fileName, "wb");
    for (j = 0; j < i; j++)
    {
        fwrite(&v[j], tam, 1, arquivo);
    }
    fclose(arquivo);
}
//------------------------------Main--------------------------------------------
int main()
{
    int opc;
    char carrosFile[] = "carros.dat";
    char clientesFile[] = "clientes.dat";
    char vendasFile[] = "vendas.dat";
    char cpfAux[15], placaAux[9], modeloAux[TAM], fabricanteAux[TAM];
    float precoAux;
    srand(time(NULL));

    while (opc = sistemaMenu())
    {
        switch (opc)
        {
        case 1:
            while (opc = sistemaCarros())
            {
                switch (opc)
                {
                case 1:
                    inserirCarro(carrosFile);
                    break;
                case 2:
                    if (existeDadosCarros(carrosFile))
                    {
                        printf("Informe a placa do carro que deve ser excluido:\n");
                        fflush(stdin);
                        scanf("%s", placaAux);
                        if (existePlacaCarro(carrosFile, placaAux))
                        {
                            if (!existeVendaPlaca(vendasFile, placaAux))
                            {
                                excluirCarro(carrosFile, placaAux);
                                printf("Cliente excluido!\n");
                            }
                            else
                            {
                                printf("Nao e possivel excluir o cliente!\n");
                            }
                        }
                        else
                        {
                            printf("O carro nao existe no cadastro...\n");
                        }
                    }
                    else
                    {
                        printf("Nao existem carros no cadastro para serem excluidos!\n");
                    }
                    break;
                case 3:
                    if (existeDadosCarros(carrosFile))
                    {
                        mostrarCarroOrdemFabricante(carrosFile, vendasFile);
                    }
                    else
                    {
                        printf("Nao existem carros no cadastro para serem mostrados!\n");
                    }
                    break;
                case 4:
                    if (existeDadosCarros(carrosFile))
                    {
                        mostrarCarroFaixaOpcionais(carrosFile, vendasFile);
                    }
                    else
                    {
                        printf("Nao existem carros no cadastro para serem mostrados!\n");
                    }
                    break;
                case 5:
                    if (existeDadosCarros(carrosFile))
                    {
                        mostrarCarroFaixaAnoFabricacao(carrosFile, vendasFile);
                    }
                    else
                    {
                        printf("Nao existem carros no cadastro para serem mostrados!\n");
                    }
                    break;
                }
                system("pause");
            }
            break;
        case 2:
            while (opc = sistemaClientes())
            {
                switch (opc)
                {
                case 1:
                    inserirCliente(clientesFile);
                    break;
                case 2:
                    if (existeDadosClientes(clientesFile))
                    {
                        lerCPF(cpfAux);
                        if (existeCpfCliente(clientesFile, cpfAux))
                        {
                            if (!existeCompraCpf(vendasFile, cpfAux))
                            {
                                excluirCliente(clientesFile, cpfAux);
                                printf("Cliente excluido!\n");
                            }
                            else
                            {
                                printf("Nao e possivel excluir o cliente!\n");
                            }
                        }
                        else
                        {
                            printf("O cliente nao pode ser encontrado...\n");
                        }
                    }
                    else
                    {
                        printf("Nao existem clientes para serem excluidos!\n");
                    }
                    break;
                case 3:
                    if (existeDadosClientes(clientesFile))
                    {
                        mostrarClienteOrdemNome(clientesFile);
                    }
                    else
                    {
                        printf("Nao existem clientes para serem mostrados!\n");
                    }
                    break;
                case 4:
                    if (existeDadosClientes(clientesFile))
                    {
                        mostrarClienteOrdemFaixaRenda(clientesFile);
                    }
                    else
                    {
                        printf("Nao existem clientes para serem mostrados!\n");
                    }
                    break;
                }
                system("pause");
            }
            break;
        case 3:
            while (opc = sistemaVendas())
            {
                switch (opc)
                {
                case 1:
                    if (existeDadosClientes(clientesFile))
                    {
                        if (existeDadosCarros(carrosFile))
                        {
                            lerCPF(cpfAux);
                            if (existeCpfCliente(clientesFile, cpfAux))
                            {
                                printf("Insira a placa do carro que sera vendido:\n");
                                fflush(stdin);
                                scanf("%s", placaAux);
                                if (existePlacaCarro(carrosFile, placaAux))
                                {
                                    precoAux = getPrecoVenda(carrosFile, placaAux);
                                    inserirVenda(vendasFile, cpfAux, placaAux, precoAux);
                                }
                                else
                                {
                                    printf("A placa informada nao pertence a nenhum carro!\n");
                                }
                            }
                            else
                            {
                                printf("O cliente nao pode ser encontrado...\n");
                            }
                        }
                        else
                        {
                            printf("Nao existem carros no cadastro para se vender!\n");
                        }
                    }
                    else
                    {
                        printf("Nao existem clientes no cadastro para vender!\n");
                    }
                    break;
                case 2:
                    if (existeDadosVendas(vendasFile))
                    {
                        printf("Informe a placa do carro da venda que deve ser excluida:\n");
                        fflush(stdin);
                        scanf("%s", placaAux);
                        if (existeVendaPlaca(vendasFile, placaAux))
                        {
                            excluirVenda(vendasFile, placaAux);
                            printf("Venda excluida!\n");
                        }
                        else
                        {
                            printf("O carro nao existe dentre as vendas...\n");
                        }
                    }
                    else
                    {
                        printf("Nao existem vendas para serem excluidas!\n");
                    }
                    break;
                case 3:
                    if (existeDadosVendas(vendasFile))
                    {
                        printf("Informe as vendas de qual fabricante voce deseja visualizar:\n");
                        fflush(stdin);
                        scanf("%s", fabricanteAux);
                        mostrarVendasFabricante(vendasFile, fabricanteAux);
                    }
                    else
                    {
                        printf("Nao existem vendas para serem mostradas!\n");
                    }
                    break;
                case 4:
                    if (existeDadosVendas(vendasFile))
                    {
                        printf("Informe as vendas de qual modelo voce deseja visualizar:\n");
                        fflush(stdin);
                        scanf("%s", modeloAux);
                        mostrarVendasModelo(vendasFile, modeloAux);
                    }
                    else
                    {
                        printf("Nao existem vendas para serem mostradas!\n");
                    }
                    break;
                case 5:
                    if (existeDadosVendas(vendasFile))
                    {
                        mostrarNumTotalVendas(vendasFile);
                    }
                    else
                    {
                        printf("Nao existem vendas no cadastro para serem mostradas!\n");
                    }
                    break;
                case 6:
                    if (existeDadosVendas(vendasFile))
                    {
                        printf("O lucro total das vendas foi de: %2.f\n", calculaLucroTotal(vendasFile));
                    }
                    else
                    {
                        printf("Nao existem vendas no cadastro para serem mostradas!\n");
                    }
                    break;
                }
                system("pause");
            }

            break;
        }
    }
    remove(clientesFile);
    remove(carrosFile);
    remove(vendasFile);
    return 0;
}
