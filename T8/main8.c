/*
1. Informar quantos registros tem “carro.dbf”.
2. Ordenar os registros de “carro.dbf” de forma crescente pelo campo “placa” e armazená-los
no arquivo “carro.ord”.
3. Mostrar os registros de “carro.ord”.
4. Para cada tipo de combustível informar a quantidade de carros.
5. Para cada tipo de opcional informar a quantidade de carros.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char tipoCombustivel[][TAM] = {
    {"alcool"},
    {"diesel"},
    {"flex"},
    {"gasolina"}};

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
        printf("Nao foi possivel abrir o arquivo %s\n", nome);
        exit(100);
    }
    return arquivo;
}

void copiarArquivo(const char *destName, const char *srcName)
{
    CARRO c;
    FILE *dest = abrirArquivo(destName, "wb");
    FILE *src = abrirArquivo(srcName, "rb");

    int tam = sizeof(CARRO);
    while (fread(&c, tam, 1, src))
    {
        fwrite(&c, tam, 1, dest);
    }
    fclose(dest);
    fclose(src);
}

void mostrarArquivo(const char *fileName)
{
    CARRO buffer;
    FILE *arquivo = abrirArquivo(fileName, "rb");
    int tam = sizeof(CARRO);
    while (fread(&buffer, tam, 1, arquivo))
    {
        printf("==========Carro==========\nID: %li\n", buffer.id_reg);
        printf("Placa: %s\n", buffer.placa);
        printf("Modelo: %s\n", buffer.modelo);
        printf("Fabricante: %s\n", buffer.fabricante);
        printf("Ano de Fabricacao: %d\n", buffer.ano_fabricacao);
        printf("Ano do modelo: %d\n", buffer.ano_modelo);
        printf("Tipo de combustivel: %s\n", buffer.combustivel);
        printf("Cor: %s\n", buffer.cor);
        printf("Preco: %.2f\n", buffer.preco_compra);
    }
    fclose(arquivo);
}
void mostrarRegistro(CARRO buffer)
{
    printf("==========Carro==========\nID: %li\n", buffer.id_reg);
    printf("Placa: %s\n", buffer.placa);
    printf("Modelo: %s\n", buffer.modelo);
    printf("Fabricante: %s\n", buffer.fabricante);
    printf("Ano de Fabricacao: %d\n", buffer.ano_fabricacao);
    printf("Ano do modelo: %d\n", buffer.ano_modelo);
    printf("Tipo de combustivel: %s\n", buffer.combustivel);
    printf("Cor: %s\n", buffer.cor);
    printf("Preco: %.2f\n", buffer.preco_compra);
}

void excluirRegistro(const char *fileName, CARRO excluir)
{
    FILE *arquivo = abrirArquivo(fileName, "rb");
    CARRO aux;
    int tam = sizeof(CARRO), flag = 0;

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

int bytesAteStruct(const char *fileName, CARRO busca)
{
    int bytes = 0, flag = 0, tam = sizeof(CARRO);
    FILE *arquivo = abrirArquivo(fileName, "rb");
    CARRO aux;

    while (fread(&aux, tam, 1, arquivo))
    {
        if (memcmp(&aux, &busca, tam) != 0)
        {
            bytes += tam;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    fclose(arquivo);
    if (flag == 0)
        bytes = -1;
    return bytes;
}
// Retorna 0, se são iguais, >0 se b vem antes que a, e <0 se a vem antes de b
int comparaPlacas(CARRO a, CARRO b)
{
    return memcmp(a.placa, b.placa, sizeof(a.placa));
}

void menorRegistroPlaca(const char *fileName, CARRO *endMenor)
{
    FILE *arquivo = abrirArquivo(fileName, "rb");
    CARRO aux, menor;
    int tam = sizeof(CARRO);
    fread(&menor, tam, 1, arquivo);

    while (fread(&aux, tam, 1, arquivo))
    {
        if (comparaPlacas(aux, menor) < 0)
        {
            memcpy(&menor, &aux, tam);
        }
    }
    memcpy(endMenor, &menor, tam);
    fclose(arquivo);
}

int existeRegistros(const char *fileName)
{
    int flag = 0, tam = sizeof(CARRO);
    FILE *arquivo = abrirArquivo(fileName, "rb");
    CARRO buffer;
    if (fread(&buffer, tam, 1, arquivo))
    {
        flag = 1;
    }
    fclose(arquivo);
    return flag;
}

void ordenaArquivoPlaca(const char *fileName)
{
    FILE *ordenar = abrirArquivo("ordenar.ord", "wb");
    CARRO ordem;
    int tam = sizeof(CARRO);
    printf("Ordenando o arquivo! Espere alguns segundos...\n");
    while (existeRegistros(fileName) == 1)
    {
        menorRegistroPlaca(fileName, &ordem);
        fwrite(&ordem, tam, 1, ordenar);
        excluirRegistro(fileName, ordem);
    }
    fclose(ordenar);
    remove(fileName);
    rename("ordenar.ord", fileName);
    printf("Arquivo ordenado com sucesso!\n");
}

void contabilizaCombustivel(const char *fileName, int contCombustiveis[4])
{
    CARRO aux;
    FILE *arquivo = abrirArquivo(fileName, "rb");
    contCombustiveis[0] = 0;
    contCombustiveis[1] = 0;
    contCombustiveis[2] = 0;
    contCombustiveis[3] = 0;
    while (fread(&aux, sizeof(CARRO), 1, arquivo))
    {
        switch (aux.combustivel[0])
        {
        case 'a':
            contCombustiveis[0]++;
            break;
        case 'd':
            contCombustiveis[1]++;
            break;
        case 'f':
            contCombustiveis[2]++;
            break;
        case 'g':
            contCombustiveis[3]++;
            break;
        }
    }
    fclose(arquivo);
}

void contabilizaOpcionais(const char *fileName, int contOpcionais[8])
{
    int i;
    CARRO aux;
    FILE *arquivo = abrirArquivo(fileName, "rb");
    for (i = 0; i < 8; i++)
    {
        contOpcionais[i] = 0;
    }
    while (fread(&aux, sizeof(CARRO), 1, arquivo))
    {
        for (i = 0; i < 8; i++)
        {
            if (aux.opcional[i] == 1)
            {
                contOpcionais[i]++;
            }
        }
    }
    fclose(arquivo);
}

int main()
{
    char fileName[] = "carro.dbf";
    FILE *dataBase = NULL;
    FILE *baseOrdenada = NULL;
    FILE *comparer = NULL;
    CARRO aux, aux2;
    int flag, i, data, qtdCarrosCombustivel[4], qtdCarrosOpcionais[8], cmp;

    dataBase = abrirArquivo(fileName, "rb");

    do
    {
        system("cls");
        flag = sistemaMenu();
        switch (flag)
        {
        case 1:
            printf("%d\n", numRegistros(dataBase));
            break;
        case 2:
            if (baseOrdenada == NULL)
            {
                baseOrdenada = abrirArquivo("carros.ord", "w+b");
            }
            // Copiar arquivo
            while (1)
            {
                fread(&aux, sizeof(CARRO), 1, dataBase);
                fwrite(&aux, sizeof(CARRO), 1, baseOrdenada);
                if (feof(dataBase))
                {
                    break;
                }
            }
            rewind(dataBase);
            rewind(baseOrdenada);
            // Ordena
            while (1)
            {
                printf("2\n");
                fread(&aux, sizeof(CARRO), 1, baseOrdenada);
                fread(&aux2, sizeof(CARRO), 1, comparer);
                if (feof(baseOrdenada))
                {
                    break;
                }
                while (((cmp = memcmp(aux.placa, aux2.placa, 9 * sizeof(char))) <= 0) && (!feof(comparer)))
                {
                    fread(&aux2, sizeof(CARRO), 1, comparer);
                }
                if (cmp < 0)
                {
                    fwrite(&aux, sizeof(CARRO), 1, comparer);
                    fwrite(&aux2, sizeof(CARRO), 1, baseOrdenada);
                    fseek(comparer, -1, SEEK_CUR);
                    fseek(baseOrdenada, -1, SEEK_CUR);
                }
            }
            rewind(baseOrdenada);
            break;
        case 3:
            FILE *texto = abrirArquivo("analise.txt", "w+");
            while (1)
            {
                fread(&aux, sizeof(CARRO), 1, baseOrdenada);
                if (feof(baseOrdenada))
                {
                    break;
                }
                fprintf(texto, "==========Carro==========\nID: %li\nPlaca: %s\nModelo: %s\nFabricante: %s\nAno de Fabricacao: %d\nAno do modelo: %d\nTipo de combustivel: %s\nCor: %s\nPreco: %.2f\n", aux.id_reg, aux.placa, aux.modelo, aux.fabricante, aux.ano_fabricacao, aux.ano_modelo, aux.combustivel, aux.cor, aux.preco_compra);
            }
            printf("\n");
            rewind(baseOrdenada);
            break;
        case 4:
            qtdCarrosCombustivel[0] = 0;
            qtdCarrosCombustivel[1] = 0;
            qtdCarrosCombustivel[2] = 0;
            qtdCarrosCombustivel[3] = 0;
            while (1)
            {
                fread(&aux, sizeof(CARRO), 1, dataBase);
                if (feof(dataBase))
                {
                    break;
                }
                switch (aux.combustivel[0])
                {
                case 'a':
                    qtdCarrosCombustivel[0]++;
                    break;
                case 'd':
                    qtdCarrosCombustivel[1]++;
                    break;
                case 'f':
                    qtdCarrosCombustivel[2]++;
                    break;
                case 'g':
                    qtdCarrosCombustivel[3]++;
                    break;
                }
            }
            printf("==========Numeros de Carros por Combustivel==========\n");
            for (i = 0; i < 4; i++)
            {
                printf("%s: %d\n", tipoCombustivel[i], qtdCarrosCombustivel[i]);
            }
            rewind(dataBase);
            break;
        case 5:
            for (i = 0; i < 8; i++)
            {
                qtdCarrosOpcionais[i] = 0;
            }
            while (1)
            {
                fread(&aux, sizeof(CARRO), 1, dataBase);
                if (feof(dataBase))
                {
                    break;
                }

                for (i = 0; i < 8; i++)
                {
                    if (aux.opcional[i] == 1)
                    {
                        qtdCarrosOpcionais[i]++;
                    }
                }
            }
            printf("==========Numeros de Carros por Opcionais==========\n");
            for (i = 0; i < 8; i++)
            {
                printf("%s: %d\n", opcionais[i], qtdCarrosOpcionais[i]);
            }
            rewind(dataBase);
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
