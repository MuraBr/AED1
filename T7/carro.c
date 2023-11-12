#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50

int opcoesMenu(void)
{
    int opc;
    printf("----------Menu------------\n\
    1)      Inserir um carro no cadastro;\n\
    2)      (Mostra carro ta aqui) Excluir um carro do cadastro;\n\
    3)      Listar os carros disponiveis para a venda ordenados crescentemente por fabricante e modelo;\n\
    4)      Listar os carros disponiveis para a venda por selecao de um ou mais opcionais;\n\
    5)      Listar os carros disponiveis para a venda por selecao da faixa de ano de fabricacao;\n\
    6)      Encerrar programa\n\
    Escolha uma opcao:\n");
    scanf("%d", &opc);
    return opc;
}
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
}RCARRO;

char geraAlfabeto() {
    int i=0;
    char letras[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    i=rand()%26;
    return(letras[i]);
}

char geraNumero() {
    int i=0;
    char numeros[] = { '0','1','2','3','4','5','6','7','8','9'};

    i=rand()%9;
    return(numeros[i]);
}

void GerarPlaca(char placa[]){

    char PlacaCarro[9];
    memset(PlacaCarro, 0, strlen(PlacaCarro));
    for (int i = 0; i < 8; i++)
    {
        if (i<3){
            PlacaCarro[i]=geraAlfabeto();
        }
        else if (i==3){
            PlacaCarro[i]='-';
        }
        else{
            PlacaCarro[i]=geraNumero();
        }
    }
    strcpy(placa, PlacaCarro);
    printf("Placa: %s\n",placa);
}

void gerarFabricante(char fabricante[]){
   memset(fabricante, 0, strlen(fabricante));
    int i=0;
    i=rand()%4;
    if (i==0){
       strcpy(fabricante, "fiat");
    }
    if (i==1){
       strcpy(fabricante, "volkswagen");
    }
    if (i==2){
       strcpy(fabricante, "toyota");
    }
    if (i==3){
       strcpy(fabricante, "chevrolet");
    }
    printf("Fabricante: %s\n",fabricante);
}

int gerarModelo(char fabricante[],char modelo[], float preco_compra){
    int j=0;
    char fabricanteteste[TAM];
    preco_compra=0;
    memset(modelo, 0, strlen(modelo));
    memset(fabricanteteste, 0, strlen(fabricanteteste));
    strcpy(fabricanteteste, fabricante);
    int teste =strcmp(fabricanteteste,"chevrolet");
    if (teste==0){
      j=rand()%3;
      if (j==0){
         strcpy(modelo, "Onix");
         preco_compra=80000;
      }
      if (j==1){
         strcpy(modelo, "S10");
         preco_compra=100000;
      }
      if (j==2){
         strcpy(modelo, "Cruze");
         preco_compra=70000;
      }
    }

    teste =strcmp(fabricanteteste,"toyota");
    if (teste==0){
      j=rand()%3;
      if (j==0){
         strcpy(modelo, "Corolla");
         preco_compra=73000;
      }
      if (j==1){
         strcpy(modelo, "Etios");
         preco_compra=40000;
      }
      if (j==2){
         strcpy(modelo, "Hilux");
         preco_compra=40000;
      }
    }

    teste =strcmp(fabricanteteste,"fiat");
    if (teste==0){
      j=rand()%3;
      if (j==0){
         strcpy(modelo, "Strada");
         preco_compra=55000;
      }
      if (j==1){
         strcpy(modelo, "Uno");
         preco_compra=40000;
      }
      if (j==2){
         strcpy(modelo, "Mobi");
         preco_compra=50000;
      }
    }
    teste =strcmp(fabricanteteste,"volkswagen");
    if (teste==0){
      j=rand()%3;
      if (j==0){
         strcpy(modelo, "Saveiro");
         preco_compra=58000;
      }
      if (j==1){
         strcpy(modelo, "Fox");
         preco_compra=40000;
      }
      if (j==2){
         strcpy(modelo, "Gol");
         preco_compra=40000;
      }
    }
    printf("Modelo: %s\n",modelo);
    return preco_compra;

}

int gerarAnoFabricacao(int ano_fabricacao){
    int i=0;
    i=rand()%35;
    ano_fabricacao=0;
    ano_fabricacao = 2000+(i-19);
    printf("Ano de Fabricacao: %d\n",ano_fabricacao);
    return ano_fabricacao;
}
int gerarAnoModelo(int ano_fabricacao, int ano_modelo){
    int i=0;
    i=rand()%3;
    ano_modelo=0;
    ano_modelo=ano_fabricacao+(i-1);
    printf("Ano Modelo: %d\n",ano_modelo);
    return ano_modelo;
}

void gerarGasolina(char combustivel[]){
    int i=0;
    i=rand()%4;
    memset(combustivel, 0, strlen(combustivel));
    if (i==0){
       strcpy(combustivel, "gasolina");
    }
    if (i==1){
       strcpy(combustivel, "alcool");
    }
    if (i==2){
       strcpy(combustivel, "flex");
    }
    if (i==3){
       strcpy(combustivel, "diesel");
    }
    printf("Combustivel: %s\n",combustivel);
}

void gerarCor(char cor[]){
    int i=0;
    memset(cor, 0, strlen(cor));
    i=rand()%3;
    if (i==0){
       strcpy(cor, "branca");
    }
    if (i==1){
       strcpy(cor, "prata");
    }
    if (i==2){
       strcpy(cor, "preta");
    }
    printf("Cor: %s\n",cor);
}
int gerarOpcional(int opcional[], float preco_compra, int ano_fabricacao){
    int k=0;

    int calculo=0;
    calculo= ano_fabricacao-2016;
    preco_compra = preco_compra+(1000*calculo);

    for (int j = 0; j < 8; j++)
    {
      k=rand()%2;
      opcional[j]=k;
    }
    printf("Opcional: ");
    for(int i=0; i<8;i++){
      if (i==7)
      {
        if (opcional[i]==1)
        {
          printf("%s\n",opcionais[i]);
          preco_compra+=1000;
        }
      }
      
      else if (opcional[i]==1 )
      {
        printf("%s, ",opcionais[i]);
        preco_compra+=1000;
      }
      }
      return preco_compra;
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

void inserirCarro(const char *fileName){
   RCARRO c;
   int escolha=0;
   int ano_fabricacao1=0;
   int ano_modelo1=0;
   do{
      printf("\n------------------------------------------------------------------------------\n");
      GerarPlaca(c.placa);
      gerarFabricante(c.fabricante);
      ano_fabricacao1=gerarAnoFabricacao(c.ano_fabricacao);
      c.ano_fabricacao=ano_fabricacao1;
      c.preco_compra=gerarModelo(c.fabricante,c.modelo, c.preco_compra);
      ano_modelo1=  gerarAnoModelo(ano_fabricacao1,c.ano_modelo);
      c.ano_modelo=ano_modelo1;
      gerarGasolina(c.combustivel);
      gerarCor(c.cor);
      c.preco_compra=gerarOpcional(c.opcional,c.preco_compra,ano_fabricacao1);
      printf("Preco: %.2f\n", c.preco_compra);
      printf("------------------------------------------------------------------------------\n");
      printf("Deseja inserir o carro? Digite 1 para Sim e 0 para\n");
      scanf("%d",&escolha); 
   }while (escolha==0);
   FILE *arquivo = abrirArquivo(fileName, "ab");
   fflush(stdin);
   fwrite(&c,sizeof(RCARRO),1,arquivo);
   fclose(arquivo);


}

void mostrarArquivo(const char *fileName)
{
    RCARRO buffer;
    FILE *arquivo = abrirArquivo(fileName, "rb");
    int tam = sizeof(RCARRO);
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
      for(int i=0; i<8;i++){
         if (i==7){
            if (buffer.opcional[i]==1)
            {
               printf("%s\n",opcionais[i]);
            }
            else
            printf("\n");
         } 
         else if (buffer.opcional[i]==1){
            printf("%s, ",opcionais[i]);
         }
         }
      printf("Preco: %.2f\n", buffer.preco_compra);
    }
    fclose(arquivo);
}

int main()
{
   //const char original[] = "carro.dbf";
   //const char ordenado[] = "carro.ord";
   //RCARRO car;
  int opc=0;
  
  do
  {
    //system("clear");
    opc = opcoesMenu();
    switch (opc)
    {
    case 1: //inserir carro
      inserirCarro("CARROS.dat");
      
        
      break;
    case 2: // mostrar os registros do carro
            //Verifica se o arquivo existe e possui algum registro, se sim mostra ele
            if (existeArquivo("CARROS.dat"))
            {
                mostrarArquivo("CARROS.dat");
            }
            else
            {
                printf("O arquivo não existe ainda!\n");
            }
            break;
    case 3:

      break;
    case 4:
      printf("Encerrando programa...\n");
      opc = 0;
      break;
    case 5:
      printf("Encerrando programa...\n");
      opc = 0;
      break;
    case 6:
      printf("Encerrando programa...\n");
      opc = 0;
      break;     
    default:
      printf("Opcao invalida!\n");
      break;
    }
  } while (opc);
  return 0;
}