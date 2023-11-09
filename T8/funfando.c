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

int main()
{
    const char original[] = "carro.dbf";
    const char ordenado[] = "carro.ord";
    CARRO aux, m;
    FILE *testes;
    int tam = sizeof(CARRO);
    copiarArquivo(ordenado, original);
    mostrarArquivo(ordenado);
    getchar();
    ordenaArquivoPlaca(ordenado);
    getchar();
    mostrarArquivo(ordenado);
    getchar();

    return 0;
}
