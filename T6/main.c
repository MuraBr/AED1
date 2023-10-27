//Codigo Real Oficial
#include <stdio.h>
#include <math.h>
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

int main(){
  inicializa();
  
  esvazia();
  
  return 0;
}
