//ainda vou comentar e corrigir alguns bugs
void alinhar_centro(char *texto) {
    int contador = 80, contadorReserva = 0, espacoTotal = 0, espacoEsquerda = 0, tamanho = strlen(texto);
    
    while (contador < tamanho) {

        while (isspace(texto[contador]) == 0) {
            contador--;
            espacoTotal++;
        }

        espacoEsquerda = espacoTotal / 2;

        for (size_t i = 0; i < espacoEsquerda; i++)
        {
            printf(" ");
        }
        
        for (size_t i = contadorReserva; i < contador; i++) {
            printf("%c", texto[i]);
        }

        printf("\n");

        contadorReserva = contador + 1;

        contador = contador + 80;

        espacoTotal = 0;
        espacoEsquerda = 0;
    }
}
