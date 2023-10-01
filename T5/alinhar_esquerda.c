//ainda vou comentar e corrigir alguns bugs
void alinhar_esquerda(char *texto) {
    int contador = 80, contadorReserva = 0, tamanho = strlen(texto);

    while (contador < tamanho) {

        while (isspace(texto[contador]) == 0) {
            contador--;
        }

        for (size_t i = contadorReserva; i < contador; i++) {
            printf("%c", texto[i]);
        }

        printf("\n");

        contadorReserva = contador + 1;

        contador = contador + 80;
    }
}
