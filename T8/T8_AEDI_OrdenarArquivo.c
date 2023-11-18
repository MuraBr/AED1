/* T8 - AEDI
Alunos{
    João Vitor Antunes da Silva,
    Arthur Kenji Murakami,
    Guilherme Zanan Piveta,
    Mathews Henrique Costa da Costa,
    Fernando Massahiro Cruz Miyashiro
};
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

// Objetivo: controla as opções do menu
// Parametros: nenhum
// Retorno: a opção selecionada pelo usuário
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
// Objetivo: abre um arquivo com o modo desejado e encerra o programa em caso de erro
// Parametros: nome do arquivo e modo de abertura
// Retorno: ponteiro para o arquivo aberto
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
// Objetivo: copia o conteúdo de um arquivo para outro
// Parametros: nome do arquivo cópia e do arquivo original
// Retorno: nenhum
void copiarArquivo(const char *destName, const char *srcName)
{
    CARRO c;
    FILE *dest = abrirArquivo(destName, "wb");
    FILE *src = abrirArquivo(srcName, "rb");
    int tam = sizeof(CARRO);
    // Enquanto houverem registros no original copia eles para o arquivo cópia
    while (fread(&c, tam, 1, src))
    {
        fwrite(&c, tam, 1, dest);
    }
    fclose(dest);
    fclose(src);
}
// Objetivo: mostra todos os registros no arquivo
// Parametros: nome do arquivo
// Retorno: nenhum
void mostrarArquivo(const char *fileName)
{
    CARRO buffer;
    FILE *arquivo = abrirArquivo(fileName, "rb");
    int tam = sizeof(CARRO), cont, i;
    // Enquanto houver registros mostra cada um deles com a formatação necessária
    while (fread(&buffer, tam, 1, arquivo))
    {
        cont = 0;
        printf("==========Carro==========\nID: %li\n", buffer.id_reg);
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
// Objetivo: excluir um registro de um arquivo
// Parametros: nome do arquivo e o registro que será excluído
// Retorno: nenhum
void excluirRegistro(const char *fileName, CARRO excluir)
{
    FILE *arquivo = abrirArquivo(fileName, "rb");
    CARRO aux;
    int tam = sizeof(CARRO), flag = 0;
    // Cria um arquivo copia que permitirá excluir registros do arquivo
    FILE *copia = abrirArquivo("excluir.ord", "wb");
    // Copia para o arquivo excluir.ord todos os registros exceto o registro que deverá ser excluído
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
    // Caso o registro nunca foi encontrado exibe no terminal esse erro
    if (flag == 0)
    {
        printf("O registro nao existe no arquivo %s\n", fileName);
    }
    // Remove o arquivo original e renomeia excluir.ord com o nome do original
    fclose(arquivo);
    fclose(copia);
    remove(fileName);
    rename("excluir.ord", fileName);
}
// Objetivo: decide a ordem alfabética entre duas placas
// Parametros: dois registros que contenham placas para comparação
// Retorno: 0 quando as placas são iguais, <0 quando a segunda vem antes da primeira e >0 em caso contrário deste
int comparaPlacas(CARRO a, CARRO b)
{
    return memcmp(a.placa, b.placa, sizeof(a.placa));
}
// Objetivo: encontrar o menor registro no arquivo
// Parametros: nome do arquivo e endereço do registro onde será armazenado o menor
// Retorno: nenhum
void menorRegistroPlaca(const char *fileName, CARRO *endMenor)
{
    FILE *arquivo = abrirArquivo(fileName, "rb");
    CARRO aux, menor;
    int tam = sizeof(CARRO);
    // Define inicialmente que o menor registro seja o primeiro do arquivo
    fread(&menor, tam, 1, arquivo);
    // Depois compara cada registro, em caso de existir outro menor substitui o registro menor
    while (fread(&aux, tam, 1, arquivo))
    {
        // Compara as placas e atribui um novo registro menor quando necessário
        if (comparaPlacas(aux, menor) < 0)
        {
            memcpy(&menor, &aux, tam);
        }
    }
    // Atribui ao endereço passado para função o menor registro encontrado no arquivo
    memcpy(endMenor, &menor, tam);
    fclose(arquivo);
}
// Objetivo: verifica se o arquivo não está vazio
// Parametros: nome do arquivo
// Retorno: 1 se existe se existe algum carro no arquivo e 0 em caso contrário
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
// Objetivo: ordena o arquivo em ordem crescente de acordo com a placa de cada carro
// Parametros: nome do arquivo
// Retorno: nenhum
void ordenaArquivoPlaca(const char *fileName)
{
    FILE *ordenar = abrirArquivo("ordenar.ord", "wb");
    CARRO ordem;
    int tam = sizeof(CARRO);
    printf("Ordenando o arquivo! Espere alguns segundos...\n");
    // Enquanto existirem registros no arquivo
    while (existeRegistros(fileName) == 1)
    {
        // Procura pelo menor registro na ordem crescente por placa e armazena ele em um registro
        menorRegistroPlaca(fileName, &ordem);
        // Escreve desse registro para um arquivo
        fwrite(&ordem, tam, 1, ordenar);
        // Depois exclui esse registro do arquivo original para que ele não seja escrito mais de uma vez
        // E para podermos avançar para o segundo menor registro no arquivo
        excluirRegistro(fileName, ordem);
    }
    fclose(ordenar);
    // Depois renome o arquivo original e renomeia o novo arquivo criado com o nome do original
    remove(fileName);
    rename("ordenar.ord", fileName);
    printf("Arquivo ordenado com sucesso!\n");
}
// Objetivo: calcula quantos carros possuem determinado combustível
// Parametros: nome do arquivo e vetor com tamanho 4 para armazenar o número de cada combustível
// Retorno:nenhum
void contabilizaCombustivel(const char *fileName, int contCombustiveis[4])
{
    CARRO aux;
    FILE *arquivo = abrirArquivo(fileName, "rb");
    // Zera o vetor
    contCombustiveis[0] = 0;
    contCombustiveis[1] = 0;
    contCombustiveis[2] = 0;
    contCombustiveis[3] = 0;
    // Enquanto existirem registros, verifica a primeira letra do vetor com combustíveis e contabliza de acordo
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
// Objetivo: calcula quantos carros existem com cada opcional
// Parametros: nome do arquivo e um vetor de tamanho 8 para armazenar a quantidade de cada opcional
// Retorno: nenhum
void contabilizaOpcionais(const char *fileName, int contOpcionais[8])
{
    int i;
    CARRO aux;
    FILE *arquivo = abrirArquivo(fileName, "rb");
    for (i = 0; i < 8; i++) // Zera o vetor
    {
        contOpcionais[i] = 0;
    }
    // Enquanto for possível ler, percorre cada indíce do vetor de opcionais de um struct buscando 1 e contabilizando de acordo
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
// Objetivo: calcula o numero de registros em um arquivo
// Parametros: nome do arquivo
// Retorno: o numero de registros no arquivo
int numRegistros(const char *fileName)
{
    int num = 0, tam = sizeof(CARRO);
    FILE *arquivo = abrirArquivo(fileName, "rb");
    CARRO aux;
    // Enquanto for possível ler um registro, contabiliza ele
    while (fread(&aux, tam, 1, arquivo))
    {
        num++;
    }
    fclose(arquivo);
    return num;
}
// Objetivo: verifica se existe
// Parametros: o nome do arquivo
// Retorno: 1 se arquivo existe e 0 em caso contrário
int existeArquivo(const char *fileName)
{
    int flag = 0;
    FILE *arquivo = fopen(fileName, "rb");
    if (arquivo != NULL)
    {
        flag = 1;
    }
    return flag;
}
int main()
{
    const char ordenado[] = "carro.ord";
    const char original[] = "carro.dbf";
    int flag, qtdCarrosCombustivel[4], qtdCarrosOpcionais[8], i, existe = 0;
    do
    {
        system("cls");
        flag = sistemaMenu();
        switch (flag)
        {
        case 1:
            // Calcula e mosta a quantidade de registros em carro.dbf
            printf("O numero de registros em carro.dbf eh: %d\n", numRegistros(original));
            break;
        case 2:
            // Se essa secção ainda não foi executada, copia o conteúdo de carro.dbf para carro.ord e ordenda o arquivo
            if (!existe)
            {
                copiarArquivo(ordenado, original);
                ordenaArquivoPlaca(ordenado);
                existe = 1;
            }
            else
            {
                printf("O arquivo ja foi ordenado e esta disponivel para vizualizacao!\n");
            }
            break;
        case 3:
            // Verifica se o arquivo existe e possui algum registro, se sim mostra ele
            if (existeArquivo(ordenado))
            {
                mostrarArquivo(ordenado);
            }
            else
            {
                printf("O arquivo nao existe ainda!\n");
            }
            break;
        case 4:
            // Calcula o númrero de carros com cada combustível
            contabilizaCombustivel(original, qtdCarrosCombustivel);
            // Mostra o resultado para cada combustível
            printf("==========Numeros de Carros por Combustivel==========\n");
            for (i = 0; i < 4; i++)
            {
                printf("%s: %d\n", tipoCombustivel[i], qtdCarrosCombustivel[i]);
            }
            break;
        case 5:
            // Calcula o número de carros com cada opcional
            contabilizaOpcionais(original, qtdCarrosOpcionais);
            // Mostra o resultado para cada opcional
            printf("==========Numeros de Carros por Opcionais==========\n");
            for (i = 0; i < 8; i++)
            {
                printf("%s: %d\n", opcionais[i], qtdCarrosOpcionais[i]);
            }
            break;
        case 6:
            printf("Encerrando o programa...\n");
            break;
        }
        system("pause");
    } while (flag != 6);
    return 0;
}
