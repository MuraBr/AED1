#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Objetivo: Alinhar o texto à esquerda
// Parametros: vetor do texto
// Retorno: nenhum
void alinhar_esquerda(char *texto) {
    int contador = 80, contadorReserva = 0, tamanho = strlen(texto);

    //loop de projeção das linhas, que se encerra ao concluir o texto
    while (contador < tamanho) {

        //loop que calcula o fim da linha, sem que haja quebra de uma palavra
        while ((isspace(texto[contador]) == 0) && (contador != contadorReserva)) {
            contador--;
        }

        //if condition para caso não haja espaço na linha
        if (contador == contadorReserva)
        {
            contador = contador + 80;
        }

        //loop que projeta a linha
        for (size_t i = contadorReserva; i < contador; i++) {
            printf("%c", texto[i]);
        }

        //pulo de linha
        printf("\n");

        //definição do contador reserva para próxima execução do loop "for"
        contadorReserva = contador + 1;

        //definição do contador para próxima execução do loop "for"
        contador = contador + 80;
    }
}
