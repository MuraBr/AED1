#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define COMP_LINHAS 80
#define SPACE 32

// Obejtivo: Dado os limites de uma linha, encontrar onde quebrar uma linha sem que nenhuma palara seja cortada
// Parametros: endereço do começo da linha e endereço final
// Retorno: um ponteiro para o endereço do primeiro caracter da palavra que servirá de quebra
char *encontraIncioPalavra(char *comecoLinha, char *finalMaximoSuportado)
{
    char *quebra, *espaco;
    // Encontra a primeria ocorrência de um caracter espaço
    espaco = strchr(comecoLinha, SPACE);
    // Testa se existe espaço na linha
    if ((espaco > finalMaximoSuportado) || (espaco == NULL))
        return NULL;
    // Enquanto o espaço existir e estvier dentro do intervalo da linha
    while ((espaco < finalMaximoSuportado) && (espaco != NULL))
    {
        // Define provisoriamente a quebra para ser o endereço de espaco mais 1
        quebra = strchr(espaco, SPACE) + 1;
        // Procura um novo espaço
        espaco = strchr(quebra, SPACE);
    }
    return quebra;
}

// Obejtivo: Dado um texto, define onde existem quebras de linha, de modo a manter cada linha com um limite de COMP_LINHA caracteres
// Parametros: vetor do texto e vetor de ponteiros para as linhas
// Retorno: nenhum
void definePosQuebraDeLinha(char texto[], char *endLinhas[])
{
    int i, k;
    // Define a primeira linha para ser o começo do texto
    endLinhas[0] = texto;
    // Enquanto a distância do endereço anterior até o final do texto for maior que COMP_LINHAS não estamos na última linha
    for (k = 1; strlen(endLinhas[k - 1]) > COMP_LINHAS; k++)
    {
        // Atribui o endereço de umma linha diretamente se o máximo for um espaço ou seguido de um espaço
        if ((*(endLinhas[k - 1] + COMP_LINHAS - 1) == SPACE) || (*(endLinhas[k - 1] + COMP_LINHAS) == SPACE))
        {
            endLinhas[k] = endLinhas[k - 1] + COMP_LINHAS;
        }
        else
        {
            // Se não, utiliza a função encontraInicioPalavra para encontrar uma quebra válida
            endLinhas[k] = encontraIncioPalavra(endLinhas[k - 1], endLinhas[k - 1] + COMP_LINHAS);
        }
    }
    // Atribui a última linha o endereço do caracter terminal do texto
    endLinhas[k] = endLinhas[k - 1] + strlen(endLinhas[k - 1]);
}
// Objetivo: imprime o texto em sua formatação original
// Parametros: endereço das linhas
// Retorno: nenhum
void imprimeOriginal(char *endLinhas[])
{
    int i, tamLinha;
    // Enquanto o endereço da linha não for o fim do texto, exibe cada linha de acordo com o tamahno da linha
    for (i = 0; *(endLinhas[i]) != '\0'; i++)
    {
        tamLinha = abs(strlen(endLinhas[i]) - strlen(endLinhas[i + 1]));
        printf("%.*s\n", tamLinha, endLinhas[i]);
    }
}
// Objetivo: atualiza o endereço de uma linha para ignorar espaços mais a esquerda
// Parametros: endereço das linhas
// Retorno: novo endereço para linha
char *ignoraEspacosEsquerda(char *endLinha)
{
    int i;
    // Enquanto o endereço não ser o fim do texto e possuir um caracter espaço, atualiza o endereço
    while ((*(endLinha) != '\0') && (*(endLinha) == SPACE))
    {
        endLinha = endLinha + 1;
    }
    return endLinha;
}
// Objetivo: atualiza o endereço de uma linha para ignorar espaços mais a direita
// Parametros: endereço das linhas
// Retorno: novo endereço para linha
char *ignoraEspacosDireita(char *endLinha)
{
    int i;
    // Enquanto o endereço da linha não apontar para o fim do texto e o caracter anterior ao endereço for um espaço, atualiza o endereço
    while ((*(endLinha) != '\0') && (*(endLinha - 1) == SPACE))
    {
        endLinha = endLinha - 1;
    }
    return endLinha;
}
// Obejtivo: Dado o texto e os endreços de cada uma de suas linhas exibe o texto formatado
// Parametros: endereço das linhas
// Retorno: nenhum
void imprimeEsquerda(char *endLinhas[])
{
    int i, tamLinha;
    // Enquanto a linha não apontar para o caracter terminal exibe cada linha
    for (i = 0; *(endLinhas[i]) != '\0'; ++i)
    {
        // Ignora os espaços a esquerda e quantifica o restante dos caracteres
        endLinhas[i] = ignoraEspacosEsquerda(endLinhas[i]);
        tamLinha = abs(strlen(endLinhas[i]) - strlen((endLinhas[i + 1])));
        // Exibe os caracteres da linha, excluindo os espaços mais a esquerda
        printf("%.*s\n", tamLinha, endLinhas[i]);
    }
}
// Objetivo: imprime o texto alinhado à direita
// Parametros: endereço das linhas
// Retorno: nenhum
void imprimeDireita(char *endLinhas[])
{
    int i, tamLinha;
    // Enquanto a linha não apontar para o caracter terminal exibe cada linha
    for (i = 0; *(endLinhas[i]) != '\0'; ++i)
    {
        // Ignora os espços mais a esquerda e a direita de uma linha e quantifica o restante dos caracteres
        endLinhas[i] = ignoraEspacosEsquerda(endLinhas[i]);
        endLinhas[i + 1] = ignoraEspacosDireita(endLinhas[i + 1]);
        tamLinha = abs(strlen(endLinhas[i]) - strlen((endLinhas[i + 1])));
        // Exibe quantos espaços faltam para completar o maximo da linha
        if (tamLinha < COMP_LINHAS)
            printf("%*c", COMP_LINHAS - tamLinha, SPACE);
        printf("%.*s\n", tamLinha, endLinhas[i]); // Exibe a linha
    }
}
// Objetivo: calcula quantos espaços existem em um dado intervalo
// Parametros: endereços do começo e do final do intervalo
// Retorno: o numero de espaços no intervalo
int calculaNumEspacosLinha(char *comecoLinha, char *finalLinha)
{
    int qtd;
    char *espaco;
    for (qtd = 0, espaco = strchr(comecoLinha, SPACE); (espaco != NULL) && (espaco < finalLinha); espaco = strchr(espaco + 1, SPACE), qtd++)
        ;
    return qtd;
}
// Objetivo: imprime o texto justificado
// Parametros: endereço da linhas
// Retorno: nenhum
void imprimeJustificado(char *endLinhas[])
{
    int i, tamLinha, sobra, numEspacos, distAteEspaco;
    char *espaco;
    // Enquanto a linha não apontar para o caracter terminal exibe cada linha
    for (i = 0; *(endLinhas[i]) != '\0'; i++)
    {
        // Ignora os caracteres a esquerda e direita e quantifica o restante dos caracteres
        endLinhas[i] = ignoraEspacosEsquerda(endLinhas[i]);
        endLinhas[i + 1] = ignoraEspacosDireita(endLinhas[i + 1]);
        tamLinha = abs(strlen(endLinhas[i]) - strlen((endLinhas[i + 1])));
        // Calcula o numero de espaços na linha e a ocorrencia do primeiro espaço
        numEspacos = calculaNumEspacosLinha(endLinhas[i], endLinhas[i + 1]);
        espaco = strchr(endLinhas[i], SPACE);
        // Se o espaço existir calcula a distancia entre o começo da linha e o primeiro espaço
        if (espaco != NULL)
            distAteEspaco = abs(strlen(espaco) - strlen(endLinhas[i])); // 7
        // Se não houverem espaços ou a linha estiver em seu tamahno máximo, imprime ela sem formatação
        if ((tamLinha == COMP_LINHAS) || (numEspacos == 0))
        {
            printf("%.*s\n", tamLinha, endLinhas[i]);
        }
        else if ((espaco != NULL) && (distAteEspaco < COMP_LINHAS)) // Se a distância até o espaço for maior que a prórpia linha, exibe ela sem formatação
        {
            printf("%.*s", distAteEspaco, endLinhas[i]); // Mostra a palavra entre o começo da linha e o primeiro espaço
            // Calcula quantos caracteres faltam para a linha atingir seu máximo
            // Imprime um número especifico de espaços de acordo com o numero de espaços na linha e quantos caracteres faltam para o maximo da linha
            // Então mostra a palavra até o próximo espaço e encontra o próximo espaço
            for (sobra = (COMP_LINHAS - tamLinha); (espaco != NULL) && (numEspacos > 0); sobra = sobra - sobra / numEspacos, numEspacos--)
            {
                if (sobra / numEspacos > 0)
                    printf("%*c", sobra / numEspacos, SPACE);
                distAteEspaco = abs(strlen(strchr(espaco + 1, SPACE)) - strlen(espaco));
                printf("%.*s", distAteEspaco, espaco);
                espaco = strchr(espaco + 1, SPACE);
            }
            printf("\n");
        }
        else
        {
            printf("%.*s\n", tamLinha, endLinhas[i]);
        }
    }
}
// Objetivo: imprime o texto centralizado
// Parametros: endereço das linhas
// Retorno: nehnum
void imprimeCentralizado(char *endLinhas[])
{
    int i, tamLinha, sobra;

    // Enquanto a linha não apontar para o caracter terminal exibe cada linha
    for (i = 0; *(endLinhas[i]) != '\0'; ++i)
    {
        // Ignora os espaços a esquerda e direita e calcula o restante dos caracteres
        endLinhas[i] = ignoraEspacosEsquerda(endLinhas[i]);
        endLinhas[i + 1] = ignoraEspacosDireita(endLinhas[i + 1]);
        tamLinha = abs(strlen(endLinhas[i]) - strlen((endLinhas[i + 1])));
        // Calcula e divide o numero de caracteres que faltam na linha para o máximo de 80 por dois
        sobra = (COMP_LINHAS - tamLinha) / 2;
        if (sobra > 0)
            printf("%*c", sobra, SPACE);
        // Exibe exatamente o numéro calculado de caracteres da linha
        printf("%.*s\n", tamLinha, endLinhas[i]);
    }
}
// Objetivo: imprime o texto segundo a formatação informada
// Parametros: endereço das linhas e o indice da formtação
// Retorno: nenhum
void imprimeTextoFormatado(char *endLinhas[], int indice)
{
    switch (indice)
    {
    case 0:
        imprimeEsquerda(endLinhas);
        break;
    case 1:
        imprimeDireita(endLinhas);
        break;
    case 2:
        imprimeJustificado(endLinhas);
        break;
    case 3:
        imprimeCentralizado(endLinhas);
        break;
    case 4:
        imprimeOriginal(endLinhas);
        break;
    }
}
// Obejtivo: Dado o texto, verifica espaços extras e remove eles
// Parametros: vetor com o texto
// Retorno: nenhum
void removeEspacosExtras(char texto[])
{
    char *espacoExtra, copia[4000];
    int cont;
    // Enquanto houver sequencias de espaços, substitui eles pelo resto do texto
    for (espacoExtra = strstr(texto, "  "); espacoExtra != NULL; espacoExtra = strstr(texto, "  "))
    {
        // Calcula quantos espaços estão dispostos numa sequencia específica
        for (cont = 1; *(espacoExtra + cont) == SPACE; cont++)
            ;
        // Copia para uma variavel auxiliar tudo após a sequencia de espaço
        strcpy(copia, espacoExtra + cont);
        // Zera o texto
        memset(espacoExtra + 1, 0, strlen(espacoExtra + 1));
        // Copia de volta o texto após a sequencia de espaços para a posição onde os espaços começam a se repetir
        strcpy(espacoExtra + 1, copia);
    }
}
// Objetivo: deixa o texto em caixa alta
// Parametros: endereço do texto
// Retorno: nenhum
void maiusculo(char texto[])
{
    int i;
    // Enquanto houverem caracteres minusculos, trasnforma eles em maiusculo
    for (i = 0; texto[i] != '\0'; i++)
    {
        if (islower(texto[i]))
            texto[i] = toupper(texto[i]);
    }
}
// Objetivo: deixa o texto em caixa baixa
// Parametros: endereço do texto
// Retorno: nenhum
void minusculo(char texto[])
{
    int i;
    // Enquanto houverem caracteres maiusculos, transforma eles em minúsculos
    for (i = 0; texto[i] != '\0'; i++)
    {
        if (isupper(texto[i]))
            texto[i] = tolower(texto[i]);
    }
}
// Objetivo: valida se um ponto serve como fim de uma frase
// Parametros: endereço do ponto
// Retorno: 1 para verdadeiro e 0 para falso
int validaPonto(char *p)
{
    if (*(p - 2) == SPACE)
    {
        return 0;
    }
    return 1;
}
// Objetivo: deixa em caixa alta o inicio de cada frase
// Parametros: endereço do texto
// Retorno: nenhum
void capitalizarTexto(char texto[])
{
    char *ponto;
    minusculo(texto);             // Reformata o texto inteiro como minúsculo
    texto[0] = toupper(texto[0]); // Deixa a primeira letra do texto em caixa alta
    // Procura por um ponto no texto e coloca a letra em seguida em caixa alta
    for (ponto = strstr(texto, ". "); ponto != NULL; ponto = strstr(ponto + 1, ". "))
    {
        if (validaPonto(ponto))
            *(ponto + 2) = toupper(*(ponto + 2));
    }
}
// Objetivo: encontra o endereço de uma palavra no texto e retorna ele
// Parametros: endereço do texto e string com a palavra que será encontrada
// Retorno: endereço da primeira ocorrência de uma palavra
char *encontraPalavra(char texto[], char palavra[])
{
    int tamPalavra = strlen(palavra);
    char *endPalavra;
    endPalavra = strstr(texto, palavra);
    // Se a palavra não existe, retorna NULL antecipadamente
    if (endPalavra == NULL)
        return NULL;
    // Se a palavra for o próprio ínicio do texto, retorna antecipadamente
    if ((endPalavra == texto) && ((isspace(*(endPalavra + tamPalavra))) || ((ispunct(*(endPalavra + tamPalavra))) && (isspace(*(endPalavra + tamPalavra + 1))))))
        return endPalavra;
    // Faz um loop até encontrar uma palavra que exista e admita a a formatação correta
    // Ou seja: " palavra " ou "palavra " ou "palavra. " ou " palavra'\0'" e etc...
    while (!((endPalavra == NULL) || ((strncmp(endPalavra, palavra, tamPalavra) == 0) && ((isspace(*(endPalavra - 1)))) && (((isspace(*(endPalavra + tamPalavra)))) || (((isspace(*(endPalavra + tamPalavra + 1))) || (*(endPalavra + tamPalavra + 1) == '\0')) && (ispunct(*(endPalavra + tamPalavra)))) || (*(endPalavra + tamPalavra) == '\0')))))
    {
        endPalavra = strstr(endPalavra + 1, palavra);
    }
    return endPalavra;
}
// Objetivo: substitui a primeira ocorrencia de uma palavra
// Parametros: endereço do texto e strings com a palavra que será substituída e a palavra susbtituta
// Retorno: nenhum
void substituirPalavra(char texto[], char palavraSubstituir[], char palavraSubstituta[])
{
    char *endPalavra, copia[4000];
    int tamPalavra = strlen(palavraSubstituir);
    // Se a palavra existir no texto, susbtitui ela assim como na função substituirTodasOcorrencias
    if (encontraPalavra(texto, palavraSubstituir) != NULL)
    {
        endPalavra = encontraPalavra(texto, palavraSubstituir);
        strcpy(copia, endPalavra + tamPalavra);
        memset(endPalavra, 0, strlen(endPalavra));
        strcpy(endPalavra, palavraSubstituta);
        strcpy(endPalavra + strlen(palavraSubstituta), copia);
        memset(copia, 0, strlen(copia));
    }
}
// Objetivo: Susbtitui todas as ocorrencias de uma palavra
// Parametros: endereço do texto, strings com a palavra que será substituída e a palavra substituta
// Retorno: nenhum
void substituirTodasOcorrencias(char texto[], char palavraSubstituir[], char palavraSubstituta[])
{
    char *ocorrencia, copia[4000];
    int tamPalavra = strlen(palavraSubstituir);
    // Enquanto houverem mais ocorrências de uma palavra, susbtituímos ela, e procuramos mais ocorrências
    for (ocorrencia = encontraPalavra(texto, palavraSubstituir); ocorrencia != NULL; ocorrencia = encontraPalavra(ocorrencia + 1, palavraSubstituir))
    {
        strcpy(copia, ocorrencia + tamPalavra);                // Copia o texto após a ocorrencia da palavra para uma copia
        memset(ocorrencia, 0, strlen(ocorrencia));             // Exclui o texto após a ocorrencia
        strcpy(ocorrencia, palavraSubstituta);                 // Copia a palavra substituta para o endereço da ocorrencia
        strcpy(ocorrencia + strlen(palavraSubstituta), copia); // Copia de volta o texto
        memset(copia, 0, strlen(copia));                       // Reseta a copia
    }
}
// Objetivo: calcula quantas vezes uma palavra existe no texto e em quais posições ela está (sem formatação)
// Parametros: endereço do texto e das linhas, a palavra escolhida e os vetores onde serão guardados a posição da linha
//... e coluna de cada ocorrência da palavra
// Retorno: retorna o número de ocorrências
int QuantPalavra(char texto[], char palavra[], int linhasOcorrencias[], int colunasOcorrencias[], char *endLinhas[])
{
    int tamPalavra = strlen(palavra);
    char *endPalavra;
    int quant, k, i;
    endPalavra = encontraPalavra(texto, palavra);
    // Enquanto houver uma palavra contabilizamos ela e atualizamos o endereço da palavra para a próxima ocôrrencia
    for (k = 0, quant = 0, i = 0; (endPalavra != NULL) && (*(endLinhas[i]) != '\0'); endPalavra = encontraPalavra(endPalavra + 1, palavra), i = 0)
    {
        // Se o endereço da palavra estiver entre uma linha e outra, procuramos outra palavra na linha até não houverem mais
        while ((!((endLinhas[i] <= endPalavra) && (endPalavra <= endLinhas[i + 1]))) && (*(endLinhas[i]) != '\0'))
        {
            i++;
        }
        // Se o endereço da palavra for a própria linha, também caímos no mesmo caso anterior
        if ((endPalavra == endLinhas[i + 1]) && (*(endLinhas[i]) != '\0'))
        {
            i++;
        }
        linhasOcorrencias[quant] = i + 1;                                               // Define a linha como o próprio índice da linha em que ela foi encontrada
        colunasOcorrencias[quant] = abs(strlen(endPalavra) - strlen(endLinhas[i])) + 1; // Define a coluna como a distância
        // entre o endereço da palavra e a linha em que aparece
        quant++; // atualiza a quantidade de palavras
    }
    return quant;
}
// Objetivo: mostrar as opçoes existentes no menu
// Parametros: nenhum
// Retorno: nenhum
void declararOpcoes()
{
    printf("----------Menu------------\na)      Imprimir o texto formatado;\n\
b)      Informacoes da palavra do texto;\n\
c)      Substituir uma palavra do texto;\n\
d)      Substituir todas as ocorrencias de uma palavra do texto;\n\
e)      Colocar o texto em caixa-alta;\n\
f)      Colocar o texto em caixa-baixa;\n\
g)      Colocar em caixa-alta o primeiro caracter de cada inicio de frase;\n\
h)      Alinhar o texto a esquerda;\n\
i)      Alinhar o texto a direita;\n\
j)      Justificar o texto;\n\
k)      Centralizar o texto;\n\
l)      Encerrar programa\n\
Escolha uma opcao:\n");
}
// Objetivo: valida se a opcao inserida é válida
// Parametros: caracter inserido
// Retorno: 1 se o caracter for válido e foi inserido corretamente, e 0 em caso contrário
int validaOpcao(char opcaoEscolhida)
{
    // Se a opcao estiver entre a e l e vir seguida de enter, retorna válido
    if ((opcaoEscolhida >= 97) && (opcaoEscolhida <= 108) && (getchar() == '\n'))
    {
        return 1;
    }
    printf("Invalido!\n");
    if (opcaoEscolhida != '\n')
        while (((getchar()) != '\n')) // Libera o buffer de teclado
            ;
    system("pause");
    return 0;
}
// Objetivo: valida se uma substituição dde palavra é válida
// Parametros: endereço do texto e a string com a palavra que será substituída e com a palavra substituta
// Retorno: 1 se a palavra for válida e 0 em caso contrário
int validaSubstituicao(char texto[], char palavraSubstituir[], char palavraSubstituta[])
{
    if (encontraPalavra(texto, palavraSubstituir) == NULL)
    {
        printf("Palavra nao existe no texto!\n");
        system("pause");
        return 0;
    }
    if (strlen(palavraSubstituta) > COMP_LINHAS)
    {
        printf("A palavra substituta é muito grande!\n");
        system("pause");
        return 0;
    }
    return 1;
}
// Objetivo: mostra as ocorrencias de cada palavra de acordo com a atual formatação do texto
// Parametros: os vetores com a linha e a coluna de cada ocorrencias, a qauntidade de ocorrencias
//...o endereço do texto e de todas as linha, além do identificador da formatação atual
// Retorno:
void mostraOcorrencias(int linhasOcorrencias[], int colunasOcorrencias[], int qtd, char texto[], char *endLinhas[], int tipo)
{
    int tamLinha, j, sobra, espacosSomados, numEspacosLinha, numEspacosIntervalo;
    // Roda enquanto houverem ocorrencias para analisar
    for (j = 0; j < qtd; j++)
    {
        // Se houver um espaço a esquerda na linha de qualquer ocorrencia, desconsideramos ela, exceto para formatação padrão
        if ((*(endLinhas[linhasOcorrencias[j] - 1]) == SPACE) && (tipo != 4))
            colunasOcorrencias[j]--;
        // Desconsideramos os espaços a esquerda e a direita na contagem do numero de caracteres na linha, exceto para formatação alinhado a esquerda
        if (tipo != 0)
        {
            endLinhas[linhasOcorrencias[j] - 1] = ignoraEspacosEsquerda(endLinhas[linhasOcorrencias[j] - 1]);
            endLinhas[linhasOcorrencias[j]] = ignoraEspacosDireita(endLinhas[linhasOcorrencias[j]]);
            tamLinha = abs(strlen(endLinhas[linhasOcorrencias[j]]) - (strlen(endLinhas[linhasOcorrencias[j] - 1])));
        }
        // Analisa cada formtação de forma diferente
        switch (tipo)
        {
        case 1:
            // Soma a coluna o numero de caracteres espaço que são adcionados na formatação alinhado a direita
            colunasOcorrencias[j] += COMP_LINHAS - tamLinha;
            break;
        case 2:
            // Calcula o numero de espacos na linha e entre o inicio da linha e a ocorrencia da palavra, além de quanto falta de espaços
            numEspacosLinha = calculaNumEspacosLinha(endLinhas[linhasOcorrencias[j] - 1], endLinhas[linhasOcorrencias[j]]);
            numEspacosIntervalo = calculaNumEspacosLinha(endLinhas[linhasOcorrencias[j] - 1], endLinhas[linhasOcorrencias[j] - 1] + colunasOcorrencias[j] - 1);
            sobra = (COMP_LINHAS - tamLinha);
            // Enqaunto houverem espaços no intervalo, determina o número de espaços extras de acordo com a formatação justificada
            for (espacosSomados = 0; (numEspacosIntervalo > 0) && (sobra > 0); sobra -= sobra / numEspacosLinha, numEspacosLinha--, numEspacosIntervalo--)
            {
                espacosSomados += sobra / numEspacosLinha;
            }
            // Soma a coluna os espaços extras entre o inicio da linha e a palavra
            colunasOcorrencias[j] += espacosSomados;
            break;
        case 3:
            // Soma à coluna o numero de espaços colocados na formatação centralizada
            sobra = (COMP_LINHAS - tamLinha) / 2;
            colunasOcorrencias[j] += sobra;
            break;
        }
        printf("Ocorrencia #%d\n Linha: %d Coluna: %d\n", j + 1, linhasOcorrencias[j], colunasOcorrencias[j]);
        // Redefine qualquer alteração feita
        definePosQuebraDeLinha(texto, endLinhas);
        colunasOcorrencias[j] = 0;
        linhasOcorrencias[j] = 0;
    }
}

int main()
{
    char resto[1000];
    memset(resto, 0, strlen(resto));

    char text[] = "William Henry Gates III KBE GCIH (Seattle, 28 de outubro de 1955) mais conhecido como Bill Gates,\
 e um magnata, empresario, diretor executivo, investidor, filantropo e autor americano, que ficou conhecido por \
 fundar junto com Paul Allen a Microsoft a maior e mais conhecida empresa de software do mundo em termos de valor \
 de mercado. Gates ocupa atualmente o cargo de presidente nao-executivo da Microsoft alem de ser classificado \
 regularmente como a pessoa mais rica do mundo, posicao ocupada por ele de 1995 a 2007, 2009, e de 2014 a 2017. E \
 um dos pioneiros na revolucao do computador pessoal. Gates nasceu em uma familia de classe media de Seattle. Seu \
 pai, William H. Gates, era advogado de grandes empresas, e sua mae, Mary Maxwell Gates, foi professora da \
 Universidade de Washington e diretora de bancos. Bill Gates e as suas duas irmas, Kristanne e Libby, \
 frequentaram as melhores escolas particulares de sua cidade natal, e Bill tambem participou do \
 Movimento Escoteiro ainda quando jovem. Bill Gates, foi admitido na prestigiosa Universidade \
 Harvard, (conseguindo 1590 SATs dos 1600 possiveis) mas abandonou os cursos de Matematica e \
 Direito no terceiro ano para dedicar-se a Microsoft. Trabalhou na Taito com o desenvolvimento de \
 software basico para maquinas de jogos eletronicos (fliperamas) ate seus 16 anos. Tambem \
 trabalhou como pesquisador visitante na University of Massachusetts at Amherst, UMASS, Estados Unidos, quando \
 com 17 anos, desenvolveu junto com Paul Allen um software para leitura de fitas magneticas, com informacoes \
 de trafego de veiculos, em um chip Intel 8008. Com esse produto, Gates e Allen criaram uma empresa, \
 a Traf-o-Data, porem os clientes desistiram do negocio quando descobriram a idade dos donos. Enquanto \
 estudavam em Harvard, os jovens desenvolveram um interpretador da linguagem BASIC para um dos primeiros \
 computadores pessoais a serem lancado nos Estados Unidos - o Altair 8800. Apos um modesto sucesso na \
 comercializacao deste produto, Gates e Allen fundaram a Microsoft, uma das primeiras empresas no mundo \
 focadas exclusivamente no mercado de programas para computadores pessoais ou PCs. Gates adquiriu ao \
 longo dos anos uma fama de visionario (apostou no mercado de software na epoca em que o hardware era \
 considerado muito mais valioso) e de negociador agressivo, chegando muitas vezes a ser acusado por \
 concorrentes da Microsoft de utilizar praticas comerciais desleais. Nos anos 1980, a IBM, lider \
 no mercado de grandes computadores, resolveu entrar no mercado da microinformatica com o PC, \
 porem faltava o Sistema Operacional. Para isso, fechou contrato com a recem-criada Microsoft. Todavia, \
 a Microsoft nao possuia o software ainda. O jovem Bill Gates foi a uma pequena empresa que havia \
 desenvolvido o sistema para o processador da Intel e decidiu compra-lo, pagou cerca de US$ 50 mil, personalizou \
 o programa e vendeu-o por US$ 8 milhoes, mantendo a licenca do produto. Este viria a ser o MS-DOS. \
 Fonte: https://pt.wikipedia.org/wiki/Bill_Gates";

    int flag = 0, tipo = 4, qtd, posColunasPalavra[100], posLinhasPalavra[100];
    char *linhas[100], opcao, substituir[COMP_LINHAS + 1], substituta[COMP_LINHAS + 1], palavraInfo[COMP_LINHAS + 1];
    // Alguns testes
    system("cls");
    removeEspacosExtras(text);
    while (!flag)
    {
        system("cls");
        definePosQuebraDeLinha(text, linhas);
        declararOpcoes();
        do
        {
            scanf("%c", &opcao);
        } while (!validaOpcao(opcao));
        system("cls");
        switch (opcao)
        {
        case 'a':
            imprimeTextoFormatado(linhas, tipo);
            break;
        case 'b':
            printf("Escreva uma palavra do texto:\n");
            gets(palavraInfo);
            qtd = QuantPalavra(text, palavraInfo, posLinhasPalavra, posColunasPalavra, linhas);
            printf("Ocorrencias da palavra: %d\n", qtd);
            mostraOcorrencias(posLinhasPalavra, posColunasPalavra, qtd, text, linhas, tipo);
            break;
        case 'c':
            do
            {
                system("cls");
                printf("Escreva a palavra que deve ser substituida:\n");
                gets(substituir);
                printf("Escreva a palavra que servira para substituir a anterior:\n");
                gets(substituta);
            } while (!validaSubstituicao(text, substituir, substituta));
            substituirPalavra(text, substituir, substituta);
            printf("A primeira ocorrencia dessa palavra foi substituida com successo!\n");
            break;
        case 'd':
            do
            {
                system("cls");
                printf("Escreva a palavra que deve ser substituida:\n");
                gets(substituir);
                printf("Escreva a palavra que servira para substituir a anterior:\n");
                gets(substituta);
            } while (!validaSubstituicao(text, substituir, substituta));
            substituirTodasOcorrencias(text, substituir, substituta);
            printf("Todas as ocorrencias dessa palavra foram substituidas com successo!\n");
            break;
        case 'e':
            maiusculo(text);
            printf("Todos os caracteres foram colocados em caixa alta com sucesso!\n");
            break;
        case 'f':
            minusculo(text);
            printf("Todos os caracteres foram colocados em caixa baixa com sucesso!\n");
            break;
        case 'g':
            capitalizarTexto(text);
            printf("Todo começo de frase foi colocado em caixa alta com sucesso!\n");
            break;
        case 'h':
            tipo = 0;
            printf("O texto foi alinhado a esquerda com sucesso!\n");
            break;
        case 'i':
            tipo = 1;
            printf("O texto foi alinahdo a direita com sucesso!\n");
            break;
        case 'j':
            tipo = 2;
            printf("O texto foi justificado com sucesso!\n");
            break;
        case 'k':
            tipo = 3;
            printf("O texto foi centralizado com sucesso!\n");
            break;
        case 'l':
            flag = 1;
            printf("Encerrando o programa...\n");
            break;
        }
        system("pause");
    }
    return 0;
}
