#define TAM
50 typedef struct
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
