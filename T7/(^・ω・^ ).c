#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define TAM 50
int numClientes = 0;

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

void mostrarCliente(struct CLIENTE bcliente)
{
    int i;
    printf("==========CLIENTE==========\n");
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

void inserirCliente(const char *fileName)
{
    struct CLIENTE bpessoa;
    int escolha, i;
    do
    {
        printf("\n------------------------------------------------------------------------------\n");
        geraNome(bpessoa.nome); // char nome[TAM];
        geraCpf(bpessoa.cpf);   // char cpf[15]; //999.999.999-99
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

void excluirRegistro(const char *fileName, struct CLIENTE excluir)
{
    FILE *arquivo = abrirArquivo(fileName, "rb");
    struct CLIENTE aux;
    int tam = sizeof(struct CLIENTE), flag = 0;

    FILE *copia = abrirArquivo("excluir.ord", "wb");

    while (fread(&aux, tam, 1, arquivo))
    {
        if (memcmp(&aux, &excluir, tam) != 0)
        {
            fwrite(&aux, tam, 1, copia);
        }
        else
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("O registro nao existe no arquivo %s\n", fileName);
    }
    fclose(arquivo);
    fclose(copia);
    remove(fileName);
    rename("excluir.ord", fileName);
}
void lerCPF(char cpf[])
{
    char cpfaux[15];
    int flag = 0;
    do
    {
        if (flag == 1)
        {
            printf("CPF inserido nao eh invalido! ");
        }
        printf("Digite um cpf valido para a exclusao: \n");
        fflush(stdin);
        gets(cpfaux);
        flag = 1;
    } while (!verifica_cpf_valido(cpfaux));
    strcpy(cpf, cpfaux);
}

void excluiCliente(const char *filename)
{
    FILE *arquivo = abrirArquivo(filename, "rb");
    struct CLIENTE buffer;
    int flag = 0;
    char cpfC[15];

    lerCPF(cpfC);
    while ((flag == 0) && (fread(&buffer, sizeof(struct CLIENTE), 1, arquivo)))
    {
        if (memcmp(cpfC, buffer.cpf, strlen(buffer.cpf)) == 0)
        {
            fclose(arquivo);
            excluirRegistro(filename, buffer);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Este cliente nao existe no banco de dados!\n");
    }
    if (arquivo != NULL)
    {
        fclose(arquivo);
    }
}
void alternarClientes(struct CLIENTE *cl1, struct CLIENTE *cl2)
{
    struct CLIENTE aux;

    aux = *cl1;
    *cl1 = *cl2;
    *cl2 = aux;
}
void mostrarOrdemNome(const char *fileName)
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

void mostrarOrdemFaixaRenda(const char *fileName)
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

int main()
{
    char clientesFile[] = "clientes.dat";
    int i;
    srand(time(NULL));

    for (i = 0; i < 15; i++)
    {
        inserirCliente(clientesFile);
    }

    mostrarArquivoClientes(clientesFile);
    getchar();
    getchar();
    excluiCliente(clientesFile);
    mostrarArquivoClientes(clientesFile);
    getchar();
    printf("----------------------------------------------------Ordenado-------------------------------------------\n");
    mostrarOrdemNome(clientesFile);
    printf("-------------------------Faixa de renda--------------------------\n");
    mostrarOrdemFaixaRenda(clientesFile);
    remove(clientesFile);
    return 0;
}
