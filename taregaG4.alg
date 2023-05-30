algoritmo "semnome"
// Função :
// Autor :
// Data : 10/5/2023
// Seção de Declarações
 
var
   p,p1,cont,ult,i,guard: inteiro
inicio
      p=0
      p1=0
      cont=0
      ult=0
      i=0
      escreval("digite um valor M")
      leia(M)
      repita
      se(p%2=1)entao
      p=1+p
      ult=p
      cont=cont+1
      fimse
      se(p1>M) entao
      p1=0
      cont=0
      p=1
      guard=1+guard
      p=p+guard
      fimse
      ate(M=p)
      escreval("os impares consecutivos cuja soma é ",cont," elevado a 3 é:")
      para i de 1 ate cont faca
      escreval(ult)
      ult=ult-2
      fimpara
      fimalgoritmo
fimpara

escreva(cont)
fimalgoritmo
