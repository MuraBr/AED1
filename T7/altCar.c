#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
char opcionais[][TAM] = {{"4.portas"}, {"cambio.automatico"}, {"vidros.eletricos"}, {"abs"}, {"air.bag"}, {"ar.condicionado"}, {"banco.couro"}, {"sensor.estacionamento"}};
struct CARRO
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

int opcoesMenu(void)
{
    int opc;
    printf("\t----------Menu------------\n\
    1.      Inserir um carro no cadastro;\n\
    2.      Excluir um carro do cadastro;\n\
    3.      Listar os carros disponiveis para a venda ordenados crescentemente por fabricante e modelo;\n\
    4.      Listar os carros disponiveis para a venda por selecao de um ou mais opcionais;\n\
    5.      Listar os carros disponiveis para a venda por selecao da faixa de ano de fabricacao;\n\
    6.      Encerrar programa\n\
    Escolha uma opcao:\n");
    scanf("%d", &opc);
    while ((opc > 6) || (opc < 1))
    {
        printf("Opcao invalida!\nDigite outra:\n");
        scanf("%d", &opc);
    }
    return opc;
}
char geraAlfabeto()
{
    char i;
    i = (rand() % 26) + 65;
    return i;
}

char geraNumero()
{
    char i;
    i = (rand() % 10) + 48;
    return i;
}

void GerarPlaca(char placa[9])
{

    char PlacaCarro[9];
    PlacaCarro[8] = '\0';
    int i;
    for (i = 0; i < 8; i++)
    {
        if (i < 3)
        {
            PlacaCarro[i] = geraAlfabeto();
        }
        else if (i == 3)
        {
            PlacaCarro[i] = '-';
        }
        else
        {
            PlacaCarro[i] = geraNumero();
        }
    }
    strcpy(placa, PlacaCarro);
    printf("Placa: %s\n", placa);
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
    printf("Fabricante: %s\n", fabricante);
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
    printf("Modelo: %s\n", modelo);
}

void gerarAnoFabricacao(int *ano_fabricacao, float *preco_compra)
{
    int i, calculo;
    i = rand() % 22;
    *(ano_fabricacao) = 1995 + i;
    calculo = *(ano_fabricacao)-2016;
    *(preco_compra) = *(preco_compra) + (1000 * calculo);
    printf("Ano de Fabricacao: %d\n", *(ano_fabricacao));
}
void gerarAnoModelo(int ano_fabricacao, int *ano_modelo)
{
    int i;
    i = rand() % 3;
    *(ano_modelo) = ano_fabricacao + i;
    printf("Ano Modelo: %d\n", *(ano_modelo));
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
    printf("Combustivel: %s\n", combustivel);
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
    printf("Cor: %s\n", cor);
}
void gerarOpcional(int opcional[])
{
    int k, j, cont = 0, i;
    for (j = 0; j < 8; j++)
    {
        k = rand() % 2;
        opcional[j] = k;
    }
    printf("Opcional: ");
    for (i = 0; i < 8; i++)
    {
        if (opcional[i] == 1)
        {
            if ((i != 0) && (cont == 1))
            {
                printf(", ");
            }
            printf("%s", opcionais[i]);
            cont = 1;
        }
    }
    printf("\n");
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

void inserirCarro(const char *fileName)
{
    struct CARRO c;
    int escolha;
    do
    {
        printf("\n------------------------------------------------------------------------------\n");
        GerarPlaca(c.placa);
        gerarFabricante(c.fabricante);
        gerarModelo(c.fabricante, c.modelo, &c.preco_compra);
        gerarAnoFabricacao(&c.ano_fabricacao, &c.preco_compra);
        gerarAnoModelo(c.ano_fabricacao, &c.ano_modelo);
        gerarGasolina(c.combustivel);
        gerarCor(c.cor);
        gerarOpcional(c.opcional);
        printf("------------------------------------------------------------------------------\n");
        printf("Deseja inserir o carro? Digite 1 para Sim e 0 para nao:\n");
        scanf("%d", &escolha);
    } while (escolha == 0);
    FILE *arquivo = abrirArquivo(fileName, "ab");
    fwrite(&c, sizeof(struct CARRO), 1, arquivo);
    fclose(arquivo);
}

void mostrarArquivo(const char *fileName)
{
    struct CARRO buffer;
    FILE *arquivo = abrirArquivo(fileName, "rb");
    int tam = sizeof(struct CARRO), cont = 0, i;
    while (fread(&buffer, tam, 1, arquivo))
    {
        printf("==========Carro==========\n");
        printf("Placa: %s\n", buffer.placa);
        printf("Modelo: %s\n", buffer.modelo);
        printf("Fabricante: %s\n", buffer.fabricante);
        printf("Ano de Fabricacao: %d\n", buffer.ano_fabricacao);
        printf("Ano do modelo: %d\n", buffer.ano_modelo);
        printf("Tipo de combustivel: %s\n", buffer.combustivel);
        printf("Cor: %s\n", buffer.cor);
        printf("Opcional: ");
        for (i = 0; i < 8; i++)
        {
            if (buffer.opcional[i] == 1)
            {
                if ((i != 0) && (cont == 1))
                {
                    printf(", ");
                }
                printf("%s", opcionais[i]);
                cont = 1;
            }
        }

        printf("\n");
        printf("Preco: %.2f\n", buffer.preco_compra);
    }
    fclose(arquivo);
}

int main()
{
    srand(time(NULL));
    int opc;

    do
    {
        system("cls");
        opc = opcoesMenu();
        switch (opc)
        {
        case 1: // inserir carro
            inserirCarro("CARROS.dat");
            break;
        case 2: //
            mostrarArquivo("CARROS.dat");
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            printf("Encerrando programa...\n");
            break;
        }
        system("pause");
    } while (opc != 6);
    return 0;
}
