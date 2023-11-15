#include <stdio.h>
#include <stdlib.h>

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
}venda_carro;

int menu() {
    int opcao;

    printf("Venda\n\n\t1. Inserir uma venda\n\t2. Excluir uma venda\n\t3. Listar os carros vendidos de um determinado fabricante\n\t4. Listar carros vendidos de um determinado modelo\n\t5. Informar a quantidade de carros vendidos com o valor totalizado dos precos vendidos\n\t6. Informar o lucro total das vendas\n\t7. Sair do programa");
    scanf("%c", &opcao);

    return opcao;
}

void existe_carro(const char *fileName) {
    FILE *arquivo;

    arquivo = fopen("venda.dat", "rb");
    if (arquivo != NULL)
    {
        return 1;
    }

    fclose(arquivo);
}

void existe_cliente() {
    FILE *arquivo;

    arquivo = fopen("cliente.dat", "rb");
    if (arquivo != NULL)
    {
        return 1;
    }

    fclose(arquivo);
}

void inserir_venda(struct VENDA_CARRO *venda_carro) {
    venda_carro novaVendaCarro;
    FILE *arquivo;

    arquivo = fopen("venda.dat", "ab");
    if (arquivo == NULL)
    {
        printf("\nErro na abertura o arquivo!");
        return 0;
    }
    
    printf("\nDigite a placa do carro: ");
    scanf("%s", novaVendaCarro.placa_car);

    printf("\nDigite o CPF do cliente: ");
    scanf("%s", novaVendaCarro.cpf_cli);

    printf("\nDigite o preco da venda: ");
    scanf("%f", &novaVendaCarro.preco_venda);

    fwrite(&novaVendaCarro, sizeof(venda_carro), 1, arquivo);

    fclose(arquivo);
}

void excluir_venda() {
    FILE *arquivo;

    arquivo = fopen("venda.dat", "ab");
    if (arquivo == NULL)
    {
        printf("\nErro na abertura o arquivo!");
        return 0;
    }
    
    //

    fclose(arquivo);
}

void listar_venda_fabricante() {
    FILE *arquivo;

    arquivo = fopen("venda.dat", "ab");
    if (arquivo == NULL)
    {
        printf("\nErro na abertura o arquivo!");
        return 0;
    }
    
    //

    fclose(arquivo);
}

void listar_venda_modelo() {
    FILE *arquivo;

    arquivo = fopen("venda.dat", "ab");
    if (arquivo == NULL)
    {
        printf("\nErro na abertura o arquivo!");
        return 0;
    }
    
    //

    fclose(arquivo);
}

void informar_venda_total() {
    FILE *arquivo;

    arquivo = fopen("venda.dat", "ab");
    if (arquivo == NULL)
    {
        printf("\nErro na abertura o arquivo!");
        return 0;
    }
    
    //

    fclose(arquivo);
}

void informar_lucro_total() {
    FILE *arquivo;

    arquivo = fopen("venda.dat", "ab");
    if (arquivo == NULL)
    {
        printf("\nErro na abertura o arquivo!");
        return 0;
    }
    
    //

    fclose(arquivo);
}

int main() {
    int opcao = 0;

    do {
        opcao = menu();

        switch (opcao)
        {
        case 1:
            //Inserir uma venda
            inserir_venda();
            break;

        case 2:
            //Excluir uma venda
            if ((existe_carro()) && (existe_cliente()))
            {
                excluir_venda();
            }
            break;

        case 3:
            //Listar os carros vendidos de um determinado fabricante, ordenados crescrentemente pelo modelo (as seguintes informacoes devem aparecer: modelo, placa, ano de fabricacao e nome do cliente)
            listar_venda_fabricante();
            break;

        case 4:
            //Listar carros vendidos de um determinado modelo, ordenados crescrentemente pelo ano de fabricacao (as seguintes informacoes devem aparecer: ano de fabricacao, placa e nome do cliente)
            listar_venda_modelo();
            break;

        case 5:
            //Informar a quantidade de carros vendidos com o valor totalizado dos precos vendidos
            informar_venda_total();
            break;

        case 6:
            //Informar o lucro total das vendas
            informar_lucro_total();
            break;

        case 7:    
            //Terminar execucao
            printf("\nSaindo do programa.");
            break;

        default:
            //Opcao invalida
            printf("\nOpcao invalida!");
            break;
        }
    } while(opcao != 7);

    return 0;
}
