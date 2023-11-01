#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TAM 50
typedef struct
{
    long int id_reg;
    char placa[9];
    char modelo[TAM];
    char fabricante[TAM];
    int ano_fabricacao;
    int ano_modelo;
    char combustivel[TAM];
    char cor[TAM];
    int opcional[8];
    float preco_compra;
} CARRO;

char opcionais[][TAM] = {
    {"4.portas"},
    {"cambio.automatico"},
    {"vidros.eletricos"},
    {"abs"},
    {"air.bag"},
    {"ar.condicionado"},
    {"banco.couro"},
    {"sensor.estacionamento"}};

/*
1. Informar quantos registros tem “carro.dbf”.
2. Ordenar os registros de “carro.dbf” de forma crescente pelo campo “placa” e armazená-los
no arquivo “carro.ord”.
3. Mostrar os registros de “carro.ord”.
4. Para cada tipo de combustível informar a quantidade de carros.
5. Para cada tipo de opcional informar a quantidade de carros.
*/

int sistemaMenu()
{
    int opc;
    printf("---Menu de opcoes---\n");
    printf("1. Informar o numero de registros em carros.dbf\n2. Criar arquivo carro.ord\n3. Mostrar as informacoes dos carros em carros.ord\n4. Informar a quantidade de carros para cada combustivel\n5. Informar a quantidade de carros para cada opcional\n6. Encerrar\n");
    printf("Insira a opcao que deseja executar:\n");
    scanf("%d", &opc);
    while ((opc < 1) || (opc > 6))
    {
        printf("Opcao invalida!\nDigite outra:\n");
        scanf("%d", &opc);
    }
    return opc;
}

FILE *abrirArquivo(const char *nome, const char *modo)
{
    FILE *arquivo;
    if ((arquivo = fopen(nome, modo)) == NULL)
    {
        printf("Nao foi possivel arbir o arquivo %s\n", nome);
        exit(100);
    }
    return arquivo;
}

int main()
{
    char fileName[] = "carro.dbf", str[] = "Abacate";
    FILE *dataBase = NULL;
    FILE *baseOrdenada = NULL;
    int flag, i, data;

    dataBase = abrirArquivo(fileName, "rb");

    do
    {
        system("cls");
        flag = sistemaMenu();
        switch (flag)
        {
        case 1:

            break;
        case 2:
            if (baseOrdenada == NULL)
            {
                baseOrdenada = abrirArquivo("carros.ord", "w+b");
            }
            rewind(baseOrdenada);
            fwrite(str, 1, sizeof(str), baseOrdenada);
            break;
        case 3:
            rewind(baseOrdenada);
            while (!feof(baseOrdenada))
            {
                data = fgetc(baseOrdenada);
                printf("%c", data);
            }
            printf("\n");
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            printf("Encerrando o programa...\n");
            break;
        }
        system("pause");
    } while (flag != 6);
    fclose(baseOrdenada);
    fclose(dataBase);

    return 0;
}
