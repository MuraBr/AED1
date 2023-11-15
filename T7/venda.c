#include <stdio.h>
#include <stdlib.h>

#define TAM 50

char opcionais[][TAM] = {{"4.portas"}, {"cambio.automatico"}, {"vidros.eletricos"}, {"abs"}, {"air.bag"}, {"ar.condicionado"}, {"banco.couro"}, {"sensor.estacionamento"}};

typedef struct CARRO
{
    char placa[9];
    char modelo[TAM];
    char fabricante[TAM];
    int ano_fabricacao;
    int ano_modelo;
    char combustivel[TAM];
    char cor[TAM];
    int opcional[8];
    float preco_compra;
};

typedef struct ENDERECO
{
    char rua[TAM];
    int numero;
    char bairro[TAM];
    char cidade[TAM];
    char estado[3];
    char cep[11];
};
typedef struct TELEFONE
{
    char telefone[14];
};
typedef struct CLIENTE
{
    char nome[TAM];
    char cpf[15];
    struct ENDERECO endereco;
    struct TELEFONE residencial;
    struct TELEFONE celular[5];
    float renda_mensal;
};
typedef struct DATA
{
    int dia, mes, ano;
};

typedef struct VENDA_CARRO
{
    char placa_car[9];
    char cpf_cli[15];
    float preco_venda;
    struct DATA data_venda;
};

FILE* abrir_arquivo(const char* nome, const char* modo) {
    //abrir arquivo
    FILE* arquivo = fopen(nome, modo);

    //testar se foi aberto corretamente
    if (arquivo == NULL) {
        printf("\nErro na abertura o arquivo!");
    }

    return arquivo;
}

void fechar_arquivo(FILE* arquivo) {
    //testar se o arquivo foi aberto corretamente
    if (arquivo != NULL) {
        //fechar arquivo
        fclose(arquivo);
    }
}

int existe_carro(char placa_car[9]) {
    FILE* arquivo = abrir_arquivo("carro.dat", "rb");
    struct CARRO carro;

    while (!feof(arquivo)) {
        if (fread(&carro, sizeof(struct CARRO), 1, arquivo)) {
            if (carro.placa == placa_car)
            {
                return 1;
            }
        }    
    }

    return 0;

    fechar_arquivo(arquivo);
}

int existe_cpf(char cpf[15]) {
    FILE* arquivo = abrir_arquivo("cliente.dat", "rb");
    struct CLIENTE cliente;

    while (!feof(arquivo)) {
        if (fread(&cliente, sizeof(struct CLIENTE), 1, arquivo)) {
            if (cliente.cpf == cpf)
            {
                return 1;
            }
        }    
    }

    return 0;

    fechar_arquivo(arquivo);
}

int menu() {
    int opcao = 0;

    printf("\n\nVenda\n\n1. Inserir uma venda.\n2. Excluir uma venda.\n3. Listar os carros vendidos de um determinado fabricante.\n4. Listar carros vendidos de um determinado modelo.\n5. Informar a quantidade de carros vendidos com o valor totalizado dos precos vendidos.\n6. Informar o lucro total das vendas.\n7. Sair do programa.\n\nDigite qual opcao deseja: ");
    fflush(stdin);
    scanf("%d", &opcao);

    return opcao;
}

void inserir_venda() {
    FILE* arquivo = abrir_arquivo("venda.dat", "ab");
    struct VENDA_CARRO venda_carro;
    int teste = 0;

    do {
        //preencher placa do carro
        printf("\n\nDigite a placa do carro: ");
        fflush(stdin);
        scanf("%8s", venda_carro.placa_car);

        //testar se o carro existe
        while (existe_carro(venda_carro.placa_car) != 1) {
            printf("\nCarro nao cadastrado. Digite novamente: ");
            fflush(stdin);
            scanf("%8s", venda_carro.placa_car);
        }
        
        //preencher cpf do cliente
        printf("\nDigite o CPF: ");
        fflush(stdin);
        scanf("%14s", venda_carro.cpf_cli);
        while (existe_cpf(venda_carro.cpf_cli) != 1) {
            printf("\nCliente nao cadastrado. Digite novamente: ");
            fflush(stdin);
            scanf("%8s", venda_carro.cpf_cli);
        }

        //preencher preco da venda
        printf("\nDigite o preco da venda: ");
        fflush(stdin);
        scanf("%f", &venda_carro.preco_venda);

        //preencher a data
        printf("\nInforme a data da venda\nDigite o dia: ");
        fflush(stdin);
        scanf("%2d", &venda_carro.data_venda.dia);
        printf("\nDigite o mes: ");
        fflush(stdin);
        scanf("%2d", &venda_carro.data_venda.mes);
        printf("\nDigite o ano: ");
        fflush(stdin);
        scanf("%4d", &venda_carro.data_venda.ano);

        //perguntar se o usuario deseja cadastrar os dados
        printf("\nVenda\n\nPlaca do carro : %s\nCPF: %s\nPreco da venda: %.2f\nData da venda: %d/%d/%d\nDeseja cadastrar essas informacoes?\n1- Sim\n2- Nao\n\nDigite sua resposta: ", venda_carro.placa_car, venda_carro.cpf_cli, venda_carro.preco_venda, venda_carro.data_venda.dia, venda_carro.data_venda.mes, venda_carro.data_venda.ano);
        fflush(stdin);
        scanf("%d", &teste);

    } while (teste != 1);

    //adicionar a venda ao arquivo
    fwrite(&venda_carro, sizeof(struct VENDA_CARRO), 1, arquivo);

    fechar_arquivo(arquivo);
}

void excluir_venda() {
    FILE* arquivo = abrir_arquivo("venda.dat", "rb");



    fechar_arquivo(arquivo);
}

void listar_fabricante() {
    FILE* arquivo = abrir_arquivo("venda.dat", "rb");
    struct VENDA_CARRO venda_carro;

    while (!feof(arquivo)) {
        if (fread(&venda_carro, sizeof(struct VENDA_CARRO), 1, arquivo)) {
            printf("\nVenda\n\nPlaca do carro : %s\nCPF: %s\nPreco da venda: %.2f\nData da venda: %d/%d/%d\n", venda_carro.placa_car, venda_carro.cpf_cli, venda_carro.preco_venda, venda_carro.data_venda.dia, venda_carro.data_venda.mes, venda_carro.data_venda.ano);
        }    
    }
    
    fechar_arquivo(arquivo);
}

void listar_modelo() {
    FILE* arquivo = abrir_arquivo("venda.dat", "ab");



    fechar_arquivo(arquivo);
}

void informar_quantidade() {
    FILE* arquivo = abrir_arquivo("venda.dat", "rb");
    struct VENDA_CARRO venda_carro;
    int quantidade = 0;

    while (!feof(arquivo)) {
        if (fread(&venda_carro, sizeof(struct VENDA_CARRO), 1, arquivo)) {
            quantidade++;
        }    
    }

    printf("\nO total de carros vendidos e: %d.", quantidade);

    fechar_arquivo(arquivo);
}

void informar_preco_total() {
    FILE* arquivo = abrir_arquivo("venda.dat", "rb");
    struct VENDA_CARRO venda_carro;
    float preco_total;

    while (!feof(arquivo)) {
        if (fread(&venda_carro, sizeof(struct VENDA_CARRO), 1, arquivo)) {
            preco_total += venda_carro.preco_venda;
        }    
    }

    printf("\nO preco total das vendas e: %f.", preco_total);

    fechar_arquivo(arquivo);
}

void informar_lucro_total() {
    FILE* arquivo = abrir_arquivo("venda.dat", "rb");
    FILE* arquivo_secundario = abrir_arquivo("carro.dat", "rb");
    struct VENDA_CARRO venda_carro;
    struct CARRO carro;
    float lucro_total;

    while (!feof(arquivo)) {
        if (fread(&venda_carro, sizeof(struct VENDA_CARRO), 1, arquivo)) {
            while (!feof(arquivo_secundario)) {
                if (fread(&carro, sizeof(struct CARRO), 1, arquivo_secundario)) {
                    if (venda_carro.placa_car == carro.placa)
                    {
                        lucro_total += venda_carro.preco_venda - carro.preco_compra;
                    }
                }    
            }
        }    
    }

    printf("O lucro total das vendas e : %f", lucro_total);

    fechar_arquivo(arquivo);
    fechar_arquivo(arquivo_secundario);
}

int main()
{
    int opcao = 0;

    do {
        opcao = menu();

        switch (opcao)
        {
        case 1:
            //inserir uma venda
            inserir_venda();
            break;

        case 2:
            //excluir uma venda
            excluir_venda();
            break;

        case 3:
            //listar os carros vendidos de um determinado fabricante, ordenados crescrentemente pelo modelo (as seguintes informacoes devem aparecer: modelo, placa, ano de fabricacao e nome do cliente)
            listar_fabricante();
            break;

        case 4:
            //listar carros vendidos de um determinado modelo, ordenados crescrentemente pelo ano de fabricacao (as seguintes informacoes devem aparecer: ano de fabricacao, placa e nome do cliente)
            listar_modelo();
            break;

        case 5:
            //informar a quantidade de carros vendidos com o valor totalizado dos precos vendidos
            informar_quantidade();
            informar_preco_total();
            break;

        case 6:
            //informar o lucro total das vendas
            informar_lucro_total();
            break;

        case 7:    
            //terminar execucao
            printf("\nSaindo do programa.\n");
            break;

        default:
            //opcao invalida
            printf("\nOpcao invalida!");
            break;
        }
    } while(opcao != 7);

    return 0;
}
