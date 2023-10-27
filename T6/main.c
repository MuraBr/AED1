// Codigo Real Oficial
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "myList.h"
/* Funcionalidades da biblioteca myList
  //define uma lista como estrutura
  struct lista {
     int info;
     struct lista* prox;
  };

  typedef struct lista Lista;

  void inicializa (void);    //deve ser chamada antes de usar a estrutura
  void insere (int);         //inserir um numero na estrutura fora da ordem
  void insereOrdem (int);    //inserir um numero na estrutura na ordem
  void imprime (void);       //imprimir o conteudo da estrutura
  int busca (int);           //localiza um valor na estrutura, devolvendo 1 se encontrou ou 0 caso contrario
  void retira (int);         //apaga um numero da estrutura
  void esvazia();            //deve ser chamada quando nao for mais usar a estrutura
*/
int opcoesMenu(void)
{
  int opc;
  printf("---Numeros Narcisistas---\n1) Gerar numeros narcisistas entre 10 e N:\n2) Mostrar numeros narcisistas:\n3) Excluir um numero da lista:\n4) Encerrar\n---Digite uma opcao---\n");
  scanf("%d", &opc);
  return opc;
}
int leNValido(void)
{
  int n;
  printf("Insira um numero entre 10 e 1000000 para N:\n");
  scanf("%d", &n);
  while ((n > 1000000) || (n < 10))
  {
    printf("O numero nao eh valido! Insira outro:\n");
    scanf("%d", &n);
  }
  return n;
}

int main()
{
  int opc, limite, num;
  inicializa();
  do
  {
    system("clear");
    opc = opcoesMenu();
    switch (opc)
    {
    case 1:
      limite = leNValido();
      // Codigo Arthur
      printf("Os numeros encontrados foram armazenados na lista!\n");
      break;
    case 2:
      imprime();
      break;
    case 3:
      printf("Informe o numero que sera removido da lista:\n");
      scanf("%d", &num);
      if (!busca(num))
      {
        printf("O numero nao existe na lista!\n");
      }
      else
      {
        retira(num);
        printf("O numero foi retirado da lista com sucesso!\n");
      }
      break;
    case 4:
      printf("Encerrando programa...\n");
      opc = 0;
      break;
    default:
      printf("Opcao invalida!\n");
      break;
    }
    getchar();
    getchar();
  } while (opc);
  esvazia();
  return 0;
}
