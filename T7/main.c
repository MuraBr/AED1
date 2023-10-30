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
// AAA-1234
// gol, celta, palio, ...
// chevrolet, fiat, ...
// 1980 à 2016
// 1980 à 2017
// alcool, gasolina, flex, diesel
// branca, prata, preta
// ver matriz opcionais
struct ENDERECO
{
    char rua[TAM];
    int numero;
    char bairro[TAM];
    char cidade[TAM];
    char estado[3];
    char cep[11];
    // 99.999-999
};
struct TELEFONE
{
    char telefone[14]; // 99 99999-9999
};
struct CLIENTE
{
    char nome[TAM];
    char cpf[15];
    // 999.999.999-99
    struct ENDERECO endereco;
    struct TELEFONE residencial;
    struct TELEFONE celular[5];
    float renda_mensal;
};
struct DATA
{
    int dia, mes, ano;
};
struct VENDA_CARRO
{
    char placa_car[9];
    char cpf_cli[15];
    float preco_venda;
    struct DATA data_venda;
};
/*
Funções
---Carros---
Inserir um carro no cadastro
Excluir um carro do cadastro
Listar os carros disponíveis para a venda ordenados crescentemente por fabricante e modelo
Listar os carros disponíveis para a venda por seleção de um ou mais opcionais
Listar os carros disponíveis para a venda por seleção da faixa de ano de fabricação
---Cliente---
Inserir um cliente no cadastro
Excluir um cliente do cadastro
Listar os clientes do cadastro ordenados crescentemente pelo nome
Listar os clientes do cadastro ordenados crescentemente pelo nome por seleção de faixa de renda salarial mensal
---Venda---
Inserir uma venda
Excluir uma venda
Listar os carros vendidos de um determinado fabricante, ordenados crescentemente pelo modelo (as seguintes
informações devem aparecer: modelo, placa, ano fabricação e nome cliente)
Listar os carros vendidos de um determinado modelo, ordenados crescentemente pelo ano de fabricação (as
seguintes informações devem aparecer: ano de fabricação, placa e nome cliente)
Informar a quantidade de carros vendidos com o valor totalizado dos preços vendidos
Informar o lucro total das vendas
*/

/*
Observações:
Para inserir um carro, gere automaticamente as informações do carro, e o usuário decide se o carro será inserido.
Na exclusão de um carro o usuário fornece a placa do carro que deseja que seja excluído. Só poderá ser excluído um carro
que ainda não foi vendido.
Para inserir um cliente, gere automaticamente as informações do cliente, e o usuário decide se o cliente será inserido.
Na exclusão de um cliente o usuário fornece o cpf do cliente que deseja que seja excluído. Só poderá ser excluído um
cliente caso não há nenhuma venda registrada para ele.
Para inserir uma venda tanto o carro como o cliente devem existir em seus respectivos cadastros.
Para excluir uma venda o usuário fornece a placa do carro para pesquisa.
O cpf do cliente deve ser válido.
Exemplo de uma listagem de carros ordenados crescentemente por fabricante e modelo
*/
