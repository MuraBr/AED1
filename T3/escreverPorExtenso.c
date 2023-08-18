
//Objetivo: escreve por extenso as casas de centena 
//Parametros: recebe o algarismo da centena(a), dezena(b) e unidade(c) de um numero, além da formatação desejada
//Onde 0 é a formatação padrão e 1 a formatação para cedulas
//Retorno: nenhum
void escreveCent(int a, int b, int c, int tipo)
{
    if (a == 1)
    {
        if ((b == 0) && (c == 0))
        {
            // Escreve cem se forem vazias e cento se existir algum algarismo não nulo
            printf("Cem ");
        }
        else
        {
            printf("Cento ");
        }
    }
    else
    {
        // Utiliza o próprio algarismo para identificar a saída por extenso no vetor das centenas
        if (tipo != 1)
        {
            printf(centenas[a]);
        }
        else
        {
            printf(centenasCedulas[a]);
        }
    }
}

//Objetivo: escreve por extenso as casas de unidade de um numero
//Parametros: recebe o algarismo da centena(a), dezena(b) e unidade(c) de um numero, a formatação desejada
//Onde 0 é a formatação padrão e 1 a formatação para cedulas
//Além da coordenada i do vetor de algarismos
//Retorno: nenhum
void escreveUni(int i, int c, int b, int a, int tipo)
{
    if (i != 2)
    {
        if (tipo != 1)
        {
            printf(unidades[c]);
        }
        else
        {
            printf(unidadesCedula[c]);
        }
    }
    else
    {
        if ((c != 1) || ((b != 0) || (a != 0)))
        {
            if (tipo != 1)
            {
                printf(unidades[c]);
            }
            else
            {
                printf(unidadesCedula[c]);
            }
        }
        // Utiliza o próprio algarismo para identificar a saída por extenso no vetor das unidades
    }
}


//Objetivo: escreve por extenso as casas de dezena de um numero
//Parametros: recebe o algarismo da dezena(b) e unidade(c) de um numero
//Retorno: retorna 1 se o modulo utilizou as dezenas especiais e 0 se usou as dezenas normais 
int escreveDez(int b, int c)
{
    if (b == 1)
    {
        //Se o numero é 1, então está entre 10 e 19, por isso utiliza as dezenas especiais
        printf(dezenasEspeciais[c]);
        return 1;
        // Utiliza o próprio algarismo para identificar a saída por extenso no vetor 
    }
    else
    {
        // Utiliza o próprio algarismo para identificar a saída por extenso no vetor das dezenas
        printf(dezenas[b]);
        return 0;
    }
}

//Objetivo: testa e escreve mil nos lugares corretos 
//Parametros: recebe todas as casas do numero com os algarismos armazenados no vetor [a, b, c, d, e, f]
//Retorno: nenhum
void escreveMil(int a, int b, int c, int d, int e, int f)
{
    // Escreve mil quando pelo menos um algarismo antes da casa da centena não for nulo
    if ((a != 0) || (b != 0) || (c != 0))
    {
        // Escreve mil e apenas se houver numeros não nulos após a unidade de milhar ou se a centena for o único algarismo não nulo no resto do número
        if (((d == 0) && (e == 0) && (f == 0)) || ((d != 0) && ((e != 0) || (f != 0))))
        {
            printf("Mil ");
        }
        else
        {
            printf("Mil e ");
        }
    }
}

//Objetivo: testa e escreve "e" nos momentos adequados
//Parametros: recebe o algarismo da centena(a), dezena(b) e unidade(c) de um numero
//Além da coordenada i do vetor que está sendo analisada
//Retorno: nenhum
void escreveE(int i, int a, int b, int c)
{
    // Avalia quando escrever "e'"
    // Escreve apenas se o algarismo analisado não for nulo ou da casa da unidade
    // Se o algarismo faz parte da centena de milhar ou centena e os próximos num não são nulos
    // Se o algarismo faz parte da dezena de milhar ou dezena e o próximo algarismo não é nulo
    // Se o algarismo não fazer parte da unidade de milhar (já é escrito quando o mil é avaliado)
    if ((i < 5) && (a != 0))
    {
        if (((i != 0) && (i != 3)) || ((b != 0) || (c != 0)))
        {
            if (((i != 1) && (i != 4)) || ((b != 0) && (a != 1)))
            {
                if (i != 2)
                {
                    printf("e ");
                }
            }
        }
    }
}

//Objetivo: reune todas as funções para escrever um numero por extenso e avalia todos as coordenadas do vetor de algarismos
//Parametros: recebe um vetor com os algarismos de um numero, além do tipo de formatação desejada
//Onde 0 é a formatação padrão e 1 a formatação para cedulas 
//Retorno: nenhum
void escrevePorExtenso(int num[], int tipo)
{
    int j;
    for (j = 0; j < 6; j++)
    {
        if ((j == 0) || (j == 3))
        {
            escreveCent(num[j], num[j + 1], num[j + 2], tipo);
        }
        else if ((j == 2) || (j == 5))
        {
            escreveUni(j, num[j], num[j - 1], num[j - 2], tipo);
            if (j == 2)
                escreveMil(num[0], num[1], num[2], num[3], num[4], num[5]);
        }
        else if ((j == 1) || (j == 4))
        {
            if (escreveDez(num[j], num[j + 1]) == 1)
            {
                j++;
            }
            if (j == 2)
                escreveMil(num[0], num[1], num[2], num[3], num[4], num[5]);
        }
        escreveE(j, num[j], num[j + 1], num[j + 2]);
    }
}
