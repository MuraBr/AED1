#include <stdio.h> 
#include <string.h>

void eliminaSequenciaFraca(char bacteria[], char virus[]){
  int tamanhoVirus;
  char *sequenciaFraca, *resto;

  tamanhoVirus = strlen(virus);
  sequenciaFraca = strstr(bacteria, virus);
  resto = sequenciaFraca + tamanhoVirus;
  memmove(sequenciaFraca, resto, strlen(resto));
  memset(resto + (strlen(resto) - tamanhoVirus), 0, strlen(resto));
}


int main(){
    char bacteriaSaudavel[1000], virusInfectador[1000], comp[1000];
    printf("Escreva o DNA da bacteria:\n");
    scanf("%s", bacteriaSaudavel);
    printf("Escreva o RNA do virus:\n");
    scanf("%s", virusInfectador);
    while(strstr(bacteriaSaudavel, virusInfectador) != NULL){
        eliminaSequenciaFraca(bacteriaSaudavel, virusInfectador);
    }
    printf("A sequencia resistente ao virus eh:\n%s\n", bacteriaSaudavel);
    scanf("%s", comp);
    printf("%d\n", strcmp(comp, bacteriaSaudavel));
    return 0;
}
