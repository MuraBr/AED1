#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define COMP_LINHAS 80

char *encontraIncioPalavra(char *comecoLinha, char *finalMaximoSuportado)
{
    char *quebra, *espaco;
    espaco = strchr(comecoLinha, 32);

    if ((espaco > finalMaximoSuportado) || (espaco == NULL))
        return NULL;

    while ((espaco < finalMaximoSuportado) && (espaco != NULL))
    {
        quebra = strchr(espaco, 32) + 1;
        espaco = strchr(quebra, 32);
    }
    return quebra;
}

void definePosQuebraDeLinha(char texto[], char *endLinhas[])
{
    int i, k;
    endLinhas[0] = texto;

    for (k = 1; strlen(endLinhas[k - 1]) > COMP_LINHAS; k++)
    {
        if (*(endLinhas[k - 1] + COMP_LINHAS - 1) == 32)
        {
            endLinhas[k] = endLinhas[k - 1] + COMP_LINHAS;
        }
        else
        {
            endLinhas[k] = encontraIncioPalavra(endLinhas[k - 1], endLinhas[k - 1] + COMP_LINHAS);
        }
    }
    endLinhas[k] = endLinhas[k - 1] + strlen(endLinhas[k - 1]);
}

void imprimeTextoFormatado(char *endLinhas[])
{
    int i, tamLinha;
    for (i = 0; *(endLinhas[i]) != '\0'; ++i)
    {
        tamLinha = abs(endLinhas[i] - endLinhas[i + 1]);
        printf("%.*s\n", tamLinha, endLinhas[i]);
    }
}

void removeEspacosExtras(char texto[])
{
    char *espacoExtra, copia[4000];
    int cont;

    for (espacoExtra = strstr(texto, "  "); espacoExtra != NULL; espacoExtra = strstr(texto, "  "))
    {
        for (cont = 1; *(espacoExtra + cont) == 32; cont++)
            ;
        strcpy(copia, espacoExtra + cont);
        memset(espacoExtra + 1, 0, strlen(espacoExtra + 1));
        strcpy(espacoExtra + 1, copia);
    }
}

void maisculo(char texto[])
{
    int i;
    for (i = 0; texto[i] != '\0'; i++)
    {
        if (islower(texto[i]))
            texto[i] = toupper(texto[i]);
    }
}
void minusculo(char texto[])
{
    int i;
    for (i = 0; texto[i] != '\0'; i++)
    {
        if (isupper(texto[i]))
            texto[i] = tolower(texto[i]);
    }
}

int validaPonto(char *p)
{
    if (*(p - 2) == 32)
    {
        return 0;
    }
    return 1;
}

void capitalizarTexto(char texto[])
{
    char *ponto;
    minusculo(texto);
    texto[0] = toupper(texto[0]);

    for (ponto = strstr(texto, ". "); ponto != NULL; ponto = strstr(ponto + 1, ". "))
    {
        if (validaPonto(ponto))
            *(ponto + 2) = toupper(*(ponto + 2));
    }
}

char *encontraPalavra(char texto[], char palavra[])
{
    int tamPalavra = strlen(palavra);
    char *endPalavra;
    endPalavra = strstr(texto, palavra);
    if (endPalavra == NULL)
        return NULL;

    if ((endPalavra == texto) && ((isspace(*(endPalavra + tamPalavra))) || ((ispunct(*(endPalavra + tamPalavra))) && (isspace(*(endPalavra + tamPalavra + 1))))))
        return endPalavra;

    while (!((endPalavra == NULL) || ((strncmp(endPalavra, palavra, tamPalavra) == 0) && ((isspace(*(endPalavra - 1)))) && (((isspace(*(endPalavra + tamPalavra)))) || (((isspace(*(endPalavra + tamPalavra + 1))) || (*(endPalavra + tamPalavra + 1) == '\0')) && (ispunct(*(endPalavra + tamPalavra)))) || (*(endPalavra + tamPalavra) == '\0')))))
    {
        endPalavra = strstr(endPalavra + 1, palavra);
    }
    return endPalavra;
}

void substituirPalavra(char texto[], char palavraSubstituir[], char palavraSubstituta[])
{
    char *endPalavra, copia[4000];
    int tamPalavra = strlen(palavraSubstituir);

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

void substituirTodasOcorrencias(char texto[], char palavraSubstituir[], char palavraSubstituta[])
{
    char *ocorrencia, copia[4000];
    int tamPalavra = strlen(palavraSubstituir);

    for (ocorrencia = encontraPalavra(texto, palavraSubstituir); ocorrencia != NULL; ocorrencia = encontraPalavra(ocorrencia + 1, palavraSubstituir))
    {
        strcpy(copia, ocorrencia + tamPalavra);
        memset(ocorrencia, 0, strlen(ocorrencia));
        strcpy(ocorrencia, palavraSubstituta);
        strcpy(ocorrencia + strlen(palavraSubstituta), copia);
        memset(copia, 0, strlen(copia));
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

    int i;
    char *linhas[50];
    //Alguns testes
    removeEspacosExtras(text);
    substituirTodasOcorrencias(text, "Bill Gates", "Erwin Johannes Hattori VI");
    substituirTodasOcorrencias(text, "Gates", "Hattori");
    substituirTodasOcorrencias(text, "Bill", "Erwin");
    substituirTodasOcorrencias(text, "Paul Allen", "Mawerick v10");
    substituirTodasOcorrencias(text, "Allen", "Mawerick");
    substituirTodasOcorrencias(text, "Microsoft", "Josef Stalin Company");
    substituirTodasOcorrencias(text, "BASIC", "BASED");
    substituirTodasOcorrencias(text, "software", "nekomimi");
    substituirTodasOcorrencias(text, "hardware", "furry");
    substituirTodasOcorrencias(text, "computador", "dispositivo de fusao nuclear");
    substituirTodasOcorrencias(text, "computadores", "dispositivos de fusao nuclear");
    substituirTodasOcorrencias(text, "PCs", "PDFNs");
    substituirTodasOcorrencias(text, "Estados Unidos", "Estados da Uniao das Republicas Socialistas Sovieticas");

    definePosQuebraDeLinha(text, linhas);
    imprimeTextoFormatado(linhas);
    //O limite do vetor text é dado pelo número de caracteres dentro dele quando ele foi declarado, por isso, quando
    //uma palavra é substituida por outra maior, alguns caracteres ficam fora do vetor text
    //Para evitar que os caracteres de fora causem algum problema, somando-se ao fato de que a posição na memória de cada variável
    //Fica no final da próxima variável que será declarada na função, se declararmos um vetor antes de text, 
    //Então todos os caracteres extras ocupam esse vetor de resto
    printf("\nParte fora do vetor text: %s\n", resto - 12);
    return 0;
}
