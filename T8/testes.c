#include <stdio.h>
#include <string.h>
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

char tipoCombustivel[][TAM] = {
    {"alcool"},
    {"diesel"},
    {"flex"},
    {"gasolina"}};

void resetarPos(FILE *arquivo, int opcReset)
{
    int size = sizeof(CARRO);
    switch (opcReset)
    {
    case 0:
        break;
    case 1:
        fseek(arquivo, -1 * size, SEEK_CUR);
        break;
    case 2:
        rewind(arquivo);
        break;
    default:
        break;
    }
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

int numRegistros(FILE *arquivo, int res)
{
    int num = 0;
    CARRO buffer;
    while (fread(&buffer, sizeof(CARRO), 1, arquivo))
    {
        num++;
    }
    resetarPos(arquivo, res);
    return num;
}
void mostrarRegistro(FILE *arquivo, int res)
{
    CARRO buffer;
    fread(&buffer, sizeof(CARRO), 1, arquivo);
    printf("==========Carro==========\nID: %li\n", buffer.id_reg);
    printf("Placa: %s\n", buffer.placa);
    printf("Modelo: %s\n", buffer.modelo);
    printf("Fabricante: %s\n", buffer.fabricante);
    printf("Ano de Fabricacao: %d\n", buffer.ano_fabricacao);
    printf("Ano do modelo: %d\n", buffer.ano_modelo);
    printf("Tipo de combustivel: %s\n", buffer.combustivel);
    printf("Cor: %s\n", buffer.cor);
    printf("Preco: %.2f\n", buffer.preco_compra);
    resetarPos(arquivo, res);
}

void mostrarArquivo(FILE *arquivo, int res)
{
    CARRO buffer;
    while (fread(&buffer, sizeof(CARRO), 1, arquivo))
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
    resetarPos(arquivo, res);
}

void copiarArquivo(FILE *dest, FILE *src, int res)
{
    CARRO c;
    while (fread(&c, sizeof(CARRO), 1, src))
    {
        fwrite(&c, sizeof(CARRO), 1, dest);
    }
    resetarPos(dest, res);
    resetarPos(src, res);
}

// Retorna 0, se são iguais, >0 se b vem antes que a, e <0 se a vem antes de b
int comparaPlacas(CARRO a, CARRO b)
{
    return memcmp(a.placa, b.placa, sizeof(a.placa));
}

void trocaRegistros(FILE *pos1, FILE *pos2, int res)
{
    int tam = sizeof(CARRO);
    CARRO a;
    CARRO b;
    // Passa para
    fread(&b, tam, 1, pos1);
    fread(&a, tam, 1, pos2);

    resetarPos(pos1, 1);
    resetarPos(pos2, 1);

    fwrite(&b, tam, 1, pos1);
    fwrite(&a, tam, 1, pos2);

    resetarPos(pos1, res);
    resetarPos(pos2, res);
}

void contabilizaCombustivel(FILE *arquivo, int contCombustiveis[4], int res)
{
    CARRO aux;
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
    resetarPos(arquivo, res);
}

void contabilizaOpcionais(FILE *arquivo, int contOpcionais[8], int res)
{
    int i;
    CARRO aux;
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
    resetarPos(arquivo, res);
}

int verificaExistenciaStruct(const char *fileName, CARRO busca){
    int flag = 0, tam = sizeof(CARRO);
    CARRO aux;
    FILE *arquivo = abrirArquivo(fileName, "rb");

    while (fread(&aux, tam, 1, arquivo))
    {
        if(memcmp(&aux, &busca, tam) == 0){
            flag = 1;
            break;
        }
    }
    fclose(arquivo);
    return flag;
}

int numBytesAteStruct(const char *fileName, CARRO busca){
    int bytes = 0, flag = 0, tam = sizeof(CARRO);
    FILE *arquivo = abrirArquivo(fileName, "rb");
    CARRO aux; 

    while(fread(&aux, tam, 1, arquivo)){
        if(memcmp(&aux, &busca, tam) != 0){
            bytes++;
        }
        else{
            flag = 1;
            break;
        }
    }
    fclose(arquivo);
    if(flag == 0)
        bytes = -1;
    return bytes;
}

void removeStruct(const char *fileName, CARRO excluir){
    FILE *arquivo = abrirArquivo(fileName, "w+b");
    int dist = numBytesAteStruct(fileName, excluir), tam = sizeof(CARRO);
    FILE *tempo = tmpfile();
    CARRO aux;
    while (dist > 0)
    {
        dist--;
        fread(&aux, tam, 1, arquivo);
        fwrite(&aux, tam, 1, tempo);
    }
    fread(&aux, tam, 1, arquivo);
    while(fread(&aux, tam, 1, arquivo)){
        fwrite(&aux, tam, 1, tempo);
    }
    fclose(arquivo);
    remove(fileName);

    arquivo = abrirArquivo(fileName, "a+b");
    copiarArquivo(arquivo, tempo, 2);
    fclose(arquivo);
    fclose(tempo);
}


int main()
{
    FILE *a = abrirArquivo("carro.dbf", "rb");
    FILE *b = abrirArquivo("carro.ord", "w+b");
    FILE *c = abrirArquivo("carro.ord", "w+b");
    CARRO aux;
    int i, quantidadeCarrosCombustivel[4], quantidadeCarrosOpcionais[8], tam = sizeof(CARRO);
    copiarArquivo(b, a, 2);
    contabilizaOpcionais(b, quantidadeCarrosOpcionais, 2);
    printf("==========Numeros de Carros por Opcionais==========\n");
    for (i = 0; i < 8; i++)
    {
        printf("%s: %d\n", opcionais[i], quantidadeCarrosOpcionais[i]);
    }
    contabilizaCombustivel(b, quantidadeCarrosCombustivel, 2);
    printf("==========Numeros de Carros por Combustivel==========\n");
    for (i = 0; i < 4; i++)
    {
        printf("%s: %d\n", tipoCombustivel[i], quantidadeCarrosCombustivel[i]);
    }
    fread(&aux, tam, 1, b);
    removeStruct("carro.ord", aux);
    fclose(a);
    fclose(b);

    return 0;
}

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
    printf("Arquivo %s aberto com sucesso\n", nome);
    return arquivo;
}

void copiarArquivo(FILE *dest, FILE *src)
{
    CARRO c;
    int cont = 0, tam = sizeof(CARRO);
    while ((fread(&c, tam, 1, src)) && (cont < 3))
    {
        fwrite(&c, tam, 1, dest);
        cont++;
    }
    rewind(dest);
    rewind(src);
}

void mostrarArquivo(FILE *arquivo)
{
    CARRO buffer;
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
    rewind(arquivo);
}

int main(){
    FILE *nada = abrirArquivo("carro.dbf", "rb");
    FILE *arquivo = abrirArquivo("testes.ord", "w+b");
    CARRO excluir, aux;
    int tam = sizeof(CARRO);
    getchar();
    mostrarArquivo(nada);
    getchar();
    copiarArquivo(arquivo, nada);
    fclose(nada);

    mostrarArquivo(arquivo);
    
    FILE *copia = abrirArquivo("copia.ord", "w+b");

    fread(&excluir, tam, 1, arquivo);
    rewind(arquivo);

    getchar();

    while(fread(&aux, tam, 1, arquivo)){
        if(memcmp(&aux, &excluir, tam) != 0){
            fwrite(&aux, tam, 1, copia);
        }
    }
    fclose(arquivo);
    fclose(copia);
    remove("testes.ord");
    rename("copia.ord", "carro.ord");

    return 0;
}
