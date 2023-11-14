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
    char maisSobrenomes[][TAM] = {{"de Paula"}, {"Nishiyama"}, {"Carvalho"}, {"Freitas"}, {"Murakami"}, {"Lima"}, {"Andrade"}};
    i = rand() % 13;
    strcpy(nome, nomes[i]);
    strcat(nome, " ");
    i = rand() % 8;
    strcat(nome, sobrenomes[i]);
    strcat(nome, " ");
    i = rand() % 7;
    strcat(nome, maisSobrenomes[i]);
    printf("Nome: %s\n", nome);
}

char geraNumero()
{
    char num;
    num = (rand() % 10) + 48;
    return num;
}

void geraRua(char rua[])
{
    char rua1[][TAM] = {{"Ipanema"}, {"Leblon"}, {"Terra"}, {"Jardim"}, {"Pires"}, {"Marculino"}, {"Hayel"}, {"Guaicurus"}, {"Monte Alegre"}, {"Toshinobu Katayama"}};
    int i = rand() % 10;
    strcpy(rua, rua1[i]);
    printf("Rua: %s\n", rua);
}

void geraNumeroCasa(int *numCasa)
{
    *numCasa = rand() % 100;
    printf("Numero da casa: %d\n", *numCasa);
}

void geraBairro(char bairro[])
{
    char bairros[][TAM] = {{"Porto Belo"}, {"Jardim Agua Boa"}, {"Vila Industrial"}, {"Altos do Indaia"}, {"Parque Alvorada"}, {"Monte Verde"}, {"Ouro Verde"}};
    int i = rand() % 7;
    strcpy(bairro, bairros[i]);
    printf("Bairro: %s\n", bairro);
}

void geraCidade(char cidade[])
{
    char cidades[][TAM] = {{"Meia Praia"}, {"Curitiba"}, {"Dourados"}, {"Maracaju"}, {"Montese"}, {"Sao Paulo"}, {"Osasco"}, {"Campo Grande"}, {"Bonito"}, {"Vicentina"}, {"Rio Brilhante"}};
    int i = rand() % 11;
    strcpy(cidade, cidades[i]);
    printf("Cidade: %s\n", cidade);
}

void geraEstado(char estado[])
{
    char estados[][3] = {{"AC"}, {"AL"}, {"AP"}, {"AM"}, {"BA"}, {"CE"}, {"ES"}, {"GO"}, {"MA"}, {"MT"}, {"MS"}, {"MG"}, {"PA"}, {"PB"}, {"PR"}, {"PE"}, {"PI"}, {"RJ"}, {"RN"}, {"RS"}, {"RO"}, {"RR"}, {"SC"}, {"SP"}, {"SE"}, {"TO"}, {"DF"}};
    int i = rand() % 27;
    strcpy(estado, estados[i]);
    printf("Estado: %s\n", estado);
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
    printf("Cep: %s\n", cep);
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
    cpf_destino[14] = '\0';
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
    printf("CPF: %s\n", cpf);
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
    printf("Telefone: %s\n", numeroT);
}

void geraRenda(float *renda){
    *(renda) = (rand() % 50000) * 1.5; 
}

void inserirCliente(const char *fileName, struct CLIENTE cliente)
{
    FILE *arquivoa = abrirArquivo(fileName, "rb");
    int escolha, i;
    do
    {
        printf("\n------------------------------------------------------------------------------\n");
        geraNome(cliente.nome);
        geraCpf(cliente.cpf);
        geraEndereco(&(cliente.endereco));
        geraTelefone(&(cliente.residencial));
        for (i = 0; i < 5; i++)
        {
            geraTelefone(&(cliente.celular[i]));
        }
        geraRenda(&cliente.renda_mensal);
        printf("------------------------------------------------------------------------------\n");
        printf("Deseja inserir o cliente? Digite 1 para Sim e 0 para nao\n");
        scanf("%d", &escolha);
        system("cls");
    } while (escolha == 0);
    fclose(arquivoa);
    FILE *arquivo = abrirArquivo(fileName, "ab");
    fwrite(&cliente, sizeof(struct CLIENTE), 1, arquivo);
    fclose(arquivo);
}

void mostrarArquivo(const char *fileName, struct CLIENTE cliente)
{
    //struct CLIENTE cliente;
    FILE *arquivo = abrirArquivo(fileName, "rb");
    int tam = sizeof(struct CLIENTE), i;
    while (fread(&cliente, tam, 1, arquivo))
    {
        printf("==========CLIENTE==========\n");
        printf("Nome: %s\n", cliente.nome);
        printf("CPF: %s\n", cliente.cpf);
        printf("Renda Mensal: %.2f\n", cliente.renda_mensal);
        printf("---Endereco---\n");
        printf("Rua: %s\nNumero: %d\nBairro: %s\nCidade: %s\nEstado: %s\nCEP: %s\n",\
        cliente.endereco.rua, cliente.endereco.numero, cliente.endereco.bairro, cliente.endereco.cidade,\
        cliente.endereco.estado, cliente.endereco.cep);
        printf("---Contato---\n");
        printf("Telefone residencial: %s\n", cliente.residencial.telefone);
        for (i = 0; i < 5; i++)
        {
            printf("Celular %d: %s\n", i+1, cliente.celular[i].telefone);
        }
    }
    fclose(arquivo);
}

void excluirRegistro(const char *fileName, struct CLIENTE cliente, char cpf[])
{
    FILE *arquivo = abrirArquivo(fileName, "rb");
    int i=0, j=0, flag=0;
    struct CLIENTE clientescopy[TAM];
    while(fread(&cliente, sizeof(struct CLIENTE), 1, arquivo))
    {
        if(strcmp(cliente.cpf, cpf) == 0)
        {
            flag++;
            printf("Excluindo usuario...\n");

            rewind(arquivo);

            while(fread(&cliente, sizeof(struct CLIENTE), 1, arquivo))
            {
                if(strcmp(cliente.cpf, cpf) != 0) {
                    clientescopy[i] = cliente;
                    i++;
                }
            }
            fclose(arquivo);
            remove(fileName); 
            arquivo = abrirArquivo(fileName, "ab");

            while(j < i)
            { 
                fwrite(&clientescopy[j], sizeof(struct CLIENTE), 1, arquivo);
                j++;
            }
            fclose(arquivo);
        }
    }
}

// void excluirRegistro(const char *fileName, struct CLIENTE excluir)
// {
//     FILE *arquivo = abrirArquivo(fileName, "rb");
//     struct CLIENTE aux;
//     int tam = sizeof(struct CLIENTE), flag = 0;
//     //Cria um arquivo copia que permitirá excluir registros do arquivo
//     FILE *copia = abrirArquivo("excluir.ord", "wb");
//     //Copia para o arquivo excluir.ord todos os registros exceto o registro que deverá ser excluído
//     while (fread(&aux, tam, 1, arquivo))
//     {
//         if (memcmp(&aux, &excluir, tam) != 0)
//         {
//             fwrite(&aux, tam, 1, copia);
//         }
//         else
//         {
//             flag = 1;
//         }
//     }
//     //Caso o registro nunca foi encontrado exibe no terminal esse erro
//     if (flag == 0)
//     {
//         printf("O registro nao existe no arquivo %s\n", fileName);
//     }
//     //Remove o arquivo original e renomeia excluir.ord com o nome do original
//     fclose(arquivo);
//     fclose(copia);
//     remove(fileName);
//     rename("excluir.ord", fileName);
// }

void excluiCliente(const char *fileName, struct CLIENTE cliente)
{
    FILE *arquivo = abrirArquivo(fileName, "rb");
    int flag = 0;
    char cpf[15];
    printf("Digite o cpf do usuario que deseja excluir: \n");
    scanf("%s", cpf);
    while((fread(&cliente, sizeof(struct CLIENTE), 1, arquivo)) && (flag == 0))
    {
        if(memcmp(cpf, cliente.cpf, strlen(cpf))==0)
        {
            flag++;
            excluirRegistro(fileName, cliente, cpf/*, cpf*/);
        }
    }

    if(flag == 0) printf("Este cliente nao existe no banco de dados!\n");
    fclose(arquivo);
}
// void ordemAlfabetica(const char *fileName, struct CLIENTE cliente)
// {

// }
// void ordemAlfabeticaRenda(const char *fileName, struct CLIENTE cliente)
// {

// }

int main()
{
    FILE *arquivoCliente;
    struct CLIENTE cliente;
    int pg = 0;
    char clientesFile[] = "CLIENTES.dat";
    char nome[TAM], rua[TAM], bairro[TAM], estado[3], cep[11], cidade[TAM], a[2];
    srand(time(NULL));
    
    while(pg == 0)
    {
        system("cls");
        printf("Menu Principal\n1- Carro\n2- Cliente\n3- Gerente\n4- Encerrar programa\nEscolha uma opcao:\n");
        scanf("%d", &pg);
        switch(pg)
        {
            case 1:
                system("cls");
                printf("Carro\n");
                system("pause");
                pg = 0;
                break;
            case 2:
                while(pg==2)
                {
                    system("cls");
                    printf("Cliente\n1- Inserir cliente\n2- Exluir cliente\n3- Listar clientes por ordem alfabetica\n4- Listar clientes por ordem alfabetica e faixa de renda\n5- Voltar ao menu principal\nEscolha um opcao:\n");
                    scanf("%d", &pg);
                    switch(pg)
                    {
                        //INCUIR CLIENTE
                        case 1:
                            system("cls");
                            inserirCliente(clientesFile, cliente);
                            system("pause");
                            pg = 2;
                            break;
                        //EXCLUIR CLIENTE
                        case 2:
                            system("cls");
                            excluiCliente(clientesFile, cliente);
                            system("pause");
                            pg = 2;
                            break;
                        //LISTAR EM ORDEM ALFABETICA
                        case 3:
                            system("cls");
                            mostrarArquivo(clientesFile, cliente);
                            fgets(a, 2, stdin);
                            system("PAUSE");
                            pg = 2;
                            break;
                        //LISTAR EM ORDEM ALFABETICA E POR RENDA
                        case 4:
                            system("cls");
                            printf("kk\n");
                            system("pause");
                            pg = 2;
                            break;
                        //VOLTAR PARA O MENU PRINCIPAL
                        case 5:
                            system("cls");
                            printf("Voltando ao menu principal!\n");
                            system("pause");
                            pg = 0;
                            break;
                        default:
                            system("cls");
                            printf("Opcao invalida!\n");
                            system("pause");
                            pg = 2;
                    }
                }
                break;
            case 3:
                system("cls");
                printf("Gerente\n");
                system("pause");
                pg = 0;
                break;
            case 4:
                system("cls");
                printf("Encerrando o programa!\n");
                return 0;
            default:
                system("cls");
                printf("Opcao invalida!\n");
                system("pause");
                pg = 0;
        }
    }
}