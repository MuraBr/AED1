#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define TAM 50
int numClientes = 0;

typedef struct ENDERECO {
    char rua[TAM];
    int numero;
    char bairro[TAM];
    char cidade[TAM];
    char estado[3];
    char cep[11]; //99.999-999
} RENDERECO;

typedef struct TELEFONE {
    char telefone[14]; //99 99999-9999
} RTELEFONE;

typedef struct CLIENTE {
    char nome[TAM];
    char cpf[15]; //999.999.999-99
    struct ENDERECO endereco;
    struct TELEFONE residencial;
    struct TELEFONE celular[5];
    float renda_mensal;
} RCLIENTE;

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

// objetivo:escolhe dentre os numeros ('0'..'9') uma numero aleatoriamente
// parametros: nenhum
// retorno:o numero
char geraNumero()
{
    int i;
    char numeros[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    i = rand() % 9;
    return (numeros[i]);
}
void geraNome(char nome[])
{
    int i;
    char nomes[][TAM] = {{"Joao"}, {"Maria"}, {"Camila"}, {"Roberto"}};
    i = rand()%4;
    //strcpy(, );
    printf("Nome: %s\n", nomes);
}
void geraCpf(char cpf[])
{

}
void geraEndereco(char rua[], int *numero, char bairro[], char cidade[], char estado[], char cep[])
{

}
void geraRenda(float renda_mensal)
{
    float max = 50000, renda;
    while(renda < 2000)
    {
        renda = ((float)rand()/(float)(RAND_MAX)) * max;
    }
    renda_mensal = renda;
    printf("Renda: %2.f\n", renda_mensal);
}
void geraTelefone(char telefone[])
{
    char teleteste[14];
    for(int i=0; i<=14; i++)
    {
        teleteste[i] = geraNumero();
    }
    teleteste[2] = ' ';
    teleteste[10] = '-';
    strcpy(telefone, teleteste);
    printf("Numero: %s\n", telefone);
}
void geraCep(char cep[])
{
    char cepteste[11];
    for(int i=0; i<=11; i++)
    {
        cepteste[i] = geraNumero();
    }
    cepteste[2] = '.';
    cepteste[8] = '-';
    strcpy(cep, cepteste);
    printf("Cep: %s\n", cep);
}

// objetivo: insere pontuacoes '.' e '- ' em um cpf
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

// objetivo: calcula o primeiro digito verificador de um cpf no formato 999999999
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

// objetivo: calcula o segundo digito verificador de um cpf no formato 999999999
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

// objetivo: verifica se um cpf no formato 999.999.999-99 e valido
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

// Objetivo: verifica se o cpf em analise esta no sistema do caixa
// Parametros: local onde os cpfs estão armazenados e o cpf em analise
// retorno: 1 se o cpf existe no sistema e 0 caso contrário
int existeCPF(char cpfAnalise[15], char cpfClientes[50][15])
{
    int i;
    for (i = 0; i < numClientes; i++)
    {
        // Percorre toda a matriz onde estão armazenados os cpf até encontrar um cpf identico ao da analise ou nada
        if ((strcmp(cpfAnalise, cpfClientes[i]) == 0))
        {
            return 1;
        }
    }
    return 0;
}

// objetivo: gera aleatoriamente um cpf valido no formato 999.999.999-99
// parametros: o cpf onde sera armazenado o cpf valido
// retorno: nenhum
void gera_cpf_valido(char cpf[])
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
}

// Objetivo: verifica se não existe nenhum cpf ou conta corrente iguais já cadastrados
// Parametros: locais onde os cpfs e as contas estão armazenados, além do numero de cpf e conta que será comparado
// Retorno: 2 se existe, 1 se existe o cpf ou conta corrente, e 0 em caso contrário
int existeCadastro(char cpfAnalise[15], char cpfClientes[50][15])
{
    int i;
    for (i = 0; i < numClientes; i++)
    {
        if ((existeCPF(cpfAnalise, cpfClientes) == 1))
        {
            return 1;
        } 
    }
    return 0;
}

// Objetivo: inclui um cliente com cpf valido
// verifica se não existe nenhum cpf ou conta corrente iguais já cadastrados, inclui o cliente no sistema
// Parametros: locais onde serão armazenados o cpf e outro para conta corrente
// Retorno: nenhum
// void incluirCliente(char cpfClientes[50][15])
// {
//     char cpfTeste[15], contaTeste[10];
//     int i;
//     // Gera um cpf e uma conta corrente para o cliente
//     gera_cpf_valido(cpfTeste);
//     // Verifica se o cpf ou a conta já estão no sistema ou se o sistema está cheio
//     if ((existeCadastro(cpfTeste, cpfClientes) == 0) && (numClientes < 50))
//     {
//         // Em caso de sucesso atualiza o numero de clientes e adiciona o novo cliente
//         strcpy(cpfClientes[numClientes], cpfTeste);
//         numClientes++;
//         printf("\nO cliente foi incluido com sucesso!\n");
//     }
//     else
//     {
//         printf("\nNao foi possivel incluir o cliente!\n");
//     }
// }
void mostrarArquivo(const char *fileName)
{
    RCLIENTE bcliente;
    FILE *arquivo = abrirArquivo(fileName, "rb");
    int tam = sizeof(RCLIENTE);
    while(fread(&bcliente, tam, 1, arquivo))
    {
        printf("==========Carro==========\n");
        printf("Nome: %s\n", bcliente.nome);
        printf("Endereco: %s\n", bcliente.endereco);
        printf("Telefone residencial: %s\n", bcliente.residencial);
        printf("Celular(es): %d\n", bcliente.celular);
        printf("Renda mensal: %d\n", bcliente.renda_mensal);
    }
    fclose(arquivo);
}
void inserirCliente(const char *fileName){
    RCLIENTE bpessoa;
    int escolha=0;
    int ano_fabricacao1=0;
    while(escolha == 0){
        printf("\n------------------------------------------------------------------------------\n");
        geraNome(bpessoa.nome);//char nome[TAM];
        geraCpf(bpessoa.cpf);//char cpf[15]; //999.999.999-99
        geraEndereco(bpessoa.endereco.rua, &bpessoa.endereco.numero, bpessoa.endereco.bairro, bpessoa.endereco.cidade, bpessoa.endereco.estado, bpessoa.endereco.cep);//struct ENDERECO endereco;
        geraTelefoneRes(bpessoa.residencial.telefone);//struct TELEFONE residencial;
        geraTelefoneCel(bpessoa.celular->telefone);//struct TELEFONE celular[5];
        geraRenda(bpessoa.renda_mensal);//float renda_mensal;
        printf("------------------------------------------------------------------------------\n");
        printf("Deseja inserir o cliente? Digite 1 para Sim e 0 para nao\n");
        scanf("%d",&escolha); 
    }
    FILE *arquivo = abrirArquivo(fileName, "ab");
    fflush(stdin);
    fwrite(&bpessoa, sizeof(RCLIENTE), 1, arquivo);
}


int main()
{
    int pg = 0;
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
                    printf("Cliente\n1- Inserir cliente\n2- Exluir cliente\n3- Listar clientes por ordem alfabetica\n4- Listar clientes por ordem alfabetica e faixa de renda\n5 - Voltar ao menu principal\nEscolha um opcao:\n");
                    scanf("%d", &pg);
                    switch(pg)
                    {
                        //INCUIR CLIENTE
                        case 1:
                            system("cls");
                            inserirCliente("CLIENTES.dat");
                            system("pause");
                            pg = 2;
                            break;
                        //EXCLUIR CLIENTE
                        case 2:
                            system("cls");
                            printf("kk\n");
                            system("pause");
                            pg = 2;
                            break;
                        //LISTAR EM ORDEM ALFABETICA
                        case 3:
                            system("cls");
                            
                            system("pause");
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