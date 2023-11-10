#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50

int opcoesMenu(void)
{
    int opc;
    printf("----------Menu------------\na)      Inserir um carro no cadastro;\n\
    b)      Excluir um carro do cadastro;\n\
    c)      Listar os carros disponíveis para a venda ordenados crescentemente por fabricante e modelo;\n\
    d)      Listar os carros disponíveis para a venda por seleção de um ou mais opcionais;\n\
    e)      Listar os carros disponíveis para a venda por seleção da faixa de ano de fabricação;\n\
    f)      Encerrar programa\n\
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

void gerarModelo(char fabricante[],char modelo[], float preco_compra){
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

}

int gerarAnoFabricacao(int ano_fabricacao, float preco_compra){
    int i=0;
    i=rand()%35;
    ano_fabricacao = 2000+(i-19);
    int calculo=0;
    calculo= ano_fabricacao-2016;
    preco_compra = preco_compra+(1000*calculo);
    printf("Ano de Fabricacao: %d\n",ano_fabricacao);
    return ano_fabricacao;
}
void gerarAnoModelo(int ano_fabricacao, int ano_modelo){
    int i=0;
    i=rand()%3;
    ano_modelo=0;
    ano_modelo=ano_fabricacao+(i-1);
    printf("Ano Modelo: %d\n",ano_modelo);
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
void gerarOpcional(int opcional[]){
    int k=0;
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
        }
      }
      
      if (opcional[i]==1)
      {
        printf("%s",opcionais[i]);
        printf(", ",opcionais[i]);
      }
    }
}

void inserirCarro(){
   RCARRO c;
   int escolha=0;
   int ano_fabricacao1=0;
   FILE *fp;
   do{
      printf("------------------------------------------------------------------------------\n");
      GerarPlaca(c.placa);
      gerarFabricante(c.fabricante);
      ano_fabricacao1=gerarAnoFabricacao(c.ano_fabricacao, c.preco_compra);
      gerarModelo(c.fabricante,c.modelo, c.preco_compra);
      gerarAnoModelo(ano_fabricacao1,c.ano_modelo);
      gerarGasolina(c.combustivel);
      gerarCor(c.cor);
      gerarOpcional(c.opcional);
      printf("------------------------------------------------------------------------------\n");
      printf("Placa: %s oi\n",c.placa);
      printf("fabricante: %s\n",c.fabricante);
      printf("Modelo: %s\n",c.modelo);
      printf("Deseja inserir o carro? Digite 1 para Sim e 0 para\n");
      scanf("%d",&escolha);
   }while (escolha==0);

   fp =fopen("CARROS.dat","ab");
   if (fp==NULL)
   {
      printf("\n Erro na abertura do arquivo!");
      exit(100);
   }
   fflush(stdin);
   fwrite(&c,sizeof(RCARRO),1,fp);
   
   
   



}

/*
void GerarCarro(){
  RCARRO car;
  
  char placa[9];
  char modelo[TAM];
  char fabricante[TAM];
  int ano_fabricacao;
  int ano_modelo;
  char combustivel[TAM];
  char cor[TAM];
  int opcional[8];
  float preco_compra =0;
  
 int escolha=0;
   printf("------------------------------------------------------------------------------\n");
   GerarPlaca(car.placa);
   printf("placa:\n",car.placa);
   gerarFabricante(car.fabricante);
   gerarModelo(car.fabricante,car.modelo, car.preco_compra);
   car.ano_fabricacao=gerarAnoFabricacao(car.ano_fabricacao, car.preco_compra);
   gerarAnoModelo(car.ano_fabricacao,car.ano_modelo);
   gerarGasolina(car.combustivel);
   gerarCor(car.cor);
   gerarOpcional(car.opcional);
   printf("\nPreco de Compra: %f\n",car.preco_compra);
   printf("------------------------------------------------------------------------------\n");
   printf("placa:\n",car.placa);
   
   printf("Deseja inserir o carro? Digite 1 para Sim e 2 para\n");
   printf("Digite 1 para Sim e 0 para Não\n");
   scanf("%d",escolha);
   inserirCarro(&car);
}*/

int main()
{
   RCARRO car;
  int opc=0;
  
  do
  {
    system("clear");
    opc = opcoesMenu();
    switch (opc)
    {
    case 1: //inserir carro
      inserirCarro(&car);
      
        
      break;
    case 2: //

      break;
    case 3:

      break;
    case 4:
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