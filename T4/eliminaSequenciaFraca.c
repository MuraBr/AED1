#include <stdio.h> 
#include <string.h>

// Objetivo: elimina o código genético de uma bactéria fraco a infecção do vírus
// Parametros: vetor que armazena o código genético de uma bactéria e vetor que armazena o RNA do vírus
// Retorno: nehnum
void eliminaSequenciaFraca(char bacteriaSaudavel[], char virusInfectador[])
{
    int tamanhoVirus, tamanhoBacteria, distSequenciaFracaAteFinal;
    char *sequenciaFraca, *resto, copia[1000];
    tamanhoVirus = strlen(virusInfectador);

    while (strstr(bacteriaSaudavel, virusInfectador) != NULL)
    {
        tamanhoBacteria = strlen(bacteriaSaudavel);
        sequenciaFraca = strstr(bacteriaSaudavel, virusInfectador);
        distSequenciaFracaAteFinal = strlen(sequenciaFraca);
        if(tamanhoBacteria - tamanhoVirus != tamanhoBacteria - distSequenciaFracaAteFinal){
            resto = sequenciaFraca + tamanhoVirus;
            strcpy(copia, resto);
            memset(sequenciaFraca, 0, distSequenciaFracaAteFinal);
            strcpy(sequenciaFraca, copia);
            memset(copia, 0, strlen(copia));
        }
        else{
            memset(sequenciaFraca, 0, distSequenciaFracaAteFinal);            
        }
    }
}
