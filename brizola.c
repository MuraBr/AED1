#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define COMP_LINHAS 80
#define SPACE 32

void pausa()
{
    printf("Aperte qualquer tecla para continuar...");
    scanf("%*c");
}
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
        // Se o último caracter permitido na linha for um espaço faz uma atribuição direta do próximo caracter para ser a quebra
        if (*(endLinhas[k - 1] + COMP_LINHAS - 1) == SPACE)
        {
            endLinhas[k] = endLinhas[k - 1] + COMP_LINHAS;
        }
        else
        {
            // Se não, utiliza a função encontraInicioPalavra para encontrar um quebra válida
            endLinhas[k] = encontraIncioPalavra(endLinhas[k - 1], endLinhas[k - 1] + COMP_LINHAS);
        }
    }
    // Atribui a última linha o endereço do caracter terminal do texto
    endLinhas[k] = endLinhas[k - 1] + strlen(endLinhas[k - 1]);
}

// Obejtivo: Dado o texto e os endreços de cada uma de suas linhas exibe o texto formatado
// Parametros: vetor com o texto e vetor de ponteiros com os endereços de cada linha
// Retorno: nenhum
void imprimeEsquerda(char *endLinhas[])
{
    int i, tamLinha;
    // Enquanto a linha não apontar para o caracter terminal exibe cada linha
    for (i = 0; *(endLinhas[i]) != '\0'; ++i)
    {
        // Calcula o tamahno da linha
        tamLinha = abs(endLinhas[i] - endLinhas[i + 1]);
        // Exibe exatamente o numéro calculado de caracteres da linha
        printf("%.*s\n", tamLinha - 1, endLinhas[i]);
    }
}
void imprimeDireita(char *endLinhas[])
{
    int i, tamLinha;
    // Enquanto a linha não apontar para o caracter terminal exibe cada linha
    tamLinha = abs(endLinhas[0] - (endLinhas[1] - 1));
    if (tamLinha != COMP_LINHAS)
        printf("%*c", COMP_LINHAS - tamLinha, SPACE);
    printf("%.*s\n", tamLinha, endLinhas[0]);
    for (i = 1; *(endLinhas[i]) != '\0'; ++i)
    {
        // Calcula o tamahno da linha
        tamLinha = abs(endLinhas[i] - (endLinhas[i + 1] - 1));
        // Exibe exatamente o numéro calculado de caracteres da linha
        if (tamLinha < COMP_LINHAS - 1)
            printf("%*c", COMP_LINHAS - 1 - tamLinha, SPACE);
        printf("%.*s\n", tamLinha + 1, endLinhas[i] - 1);
    }
}

int calculaNumEspacosLinha(char *comecoLinha, char *finalLinha)
{
    int qtd;
    char *espaco;
    for (qtd = 0, espaco = strchr(comecoLinha, SPACE); (espaco != NULL) && (espaco < finalLinha); espaco = strchr(espaco + 1, SPACE), qtd++)
        ;
    return qtd;
}
void imprimeJustificado(char *endLinhas[])
{
    int i, tamLinha, sobra, numEspacos, distAteEspaco;
    char *espaco;
    // Enquanto a linha não apontar para o caracter terminal exibe cada linha

    for (i = 0; *(endLinhas[i]) != '\0'; i++)
    {
        tamLinha = abs(endLinhas[i] - (endLinhas[i + 1] - 1));                   // 72
        numEspacos = calculaNumEspacosLinha(endLinhas[i], endLinhas[i + 1] - 1); // 12
        espaco = strchr(endLinhas[i], SPACE);
        distAteEspaco = abs(espaco - endLinhas[i]); // 7

        if (tamLinha == COMP_LINHAS)
        {
            printf("%.*s\n", tamLinha, endLinhas[i]);
        }
        else if ((espaco != NULL) && (distAteEspaco < COMP_LINHAS))
        {
            printf("%.*s", distAteEspaco, endLinhas[i]);
            for (sobra = (COMP_LINHAS - tamLinha); (espaco != NULL) && (numEspacos > 0); sobra = sobra - sobra / numEspacos, numEspacos--)
            {
                if (sobra / numEspacos > 0)
                    printf("%*c", sobra / numEspacos, SPACE);
                distAteEspaco = abs(strchr(espaco + 1, SPACE) - (espaco));
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

void imprimeCentralizado(char *endLinhas[])
{
    int i, tamLinha, sobra;

    tamLinha = abs(endLinhas[0] - (endLinhas[1] - 1));
    sobra = (COMP_LINHAS - tamLinha) / 2;
    if (tamLinha != COMP_LINHAS)
        printf("%*c", sobra, SPACE);
    printf("%.*s\n", tamLinha, endLinhas[0]);

    for (i = 1; *(endLinhas[i]) != '\0'; ++i)
    {
        // Calcula o tamahno da linha
        tamLinha = abs(endLinhas[i] - (endLinhas[i + 1] - 1));
        sobra = (COMP_LINHAS - tamLinha) / 2;
        if (tamLinha < COMP_LINHAS - 1)
            printf("%*c", sobra, SPACE);
        // Exibe exatamente o numéro calculado de caracteres da linha
        printf("%.*s\n", tamLinha + 1, endLinhas[i] - 1);
    }
}

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
void maiusculo(char texto[])
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
    if (*(p - 2) == SPACE)
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

int validaOpcao(char opcaoEscolhida)
{
    if ((opcaoEscolhida >= 97) && (opcaoEscolhida <= 108))
        return 1;
    printf("Invalido!\n");
    pausa();
    return 0;
}

int validaSubstituicao(char texto[], char palavraSubstituir[], char palavraSubstituta[]){
    if(encontraPalavra(texto, palavraSubstituir) == NULL){
        printf("Palavra nao existe no texto!");
        pausa();
        return 0;
    }
    if(strlen(palavraSubstituta) > COMP_LINHAS){
        printf("A palavra substituta é muito grande!");
        pausa();
        return 0;
    }
    return 1;
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

    int i, flag, tipo;
    char *linhas[100], opcao, substituir[80], substituta[80];
    // Alguns testes
    system("cls");
    removeEspacosExtras(text);
    definePosQuebraDeLinha(text, linhas);
    for (flag = 0, tipo = 0; flag != 1;)
    {
        do{
            declararOpcoes();
            scanf("%c%*c", &opcao);
        }while (validaOpcao(opcao) == 0);
        system("cls");
        switch (opcao)
        {
        case 'a':
            imprimeTextoFormatado(linhas, tipo);
            break;
        case 'b':
            printf("Mathews\n");
            break;
        case 'c':
            do{
                printf("Escreva a palavra que deve ser substituida:\n");
                scanf("%s", substituir);
                printf("Escreva a palavra que servira para substituir a anterior:\n");
                scanf("%s", substituta);
            } while(!validaSubstituicao(text, substituir, substituta));
            substituirPalavra(text, substituir, substituta);
            definePosQuebraDeLinha(text, linhas);
            break;
        case 'd':
            do{
                printf("Escreva a palavra que deve ser substituida:\n");
                scanf("%s", substituir);
                printf("Escreva a palavra que servira para substituir a anterior:\n");
                scanf("%s", substituta);
            } while(!validaSubstituicao(text, substituir, substituta));
            substituirTodasOcorrencias(text, substituir, substituta);
            definePosQuebraDeLinha(text, linhas);
            break;
        case 'e':
            minusculo(text);
            break;
        case 'f':
            maiusculo(text);
            break;
        case 'g':
            capitalizarTexto(text);
            break;
        case 'h':
            tipo = 0;
            break;
        case 'i':
            tipo = 1;
            break;
        case 'j':
            tipo = 2;
            break;
        case 'k':
            tipo = 3;
            break;
        case 'l':
            flag = 1;
            printf("Encerrando o programa...\n");
            pausa();
            return 0;
            break;
        default:
            break;
        }
        pausa();
        system("cls");
    }

    // O limite do vetor text é dado pelo número de caracteres dentro dele quando ele foi declarado, por isso, quando
    // uma palavra é substituida por outra maior, alguns caracteres ficam fora do vetor text
    // Para evitar que os caracteres de fora causem algum problema, somando-se ao fato de que a posição na memória de cada variável
    // Fica no final da próxima variável que será declarada na função, se declararmos um vetor antes de text,
    // Então todos os caracteres extras ocupam esse vetor de resto
    printf("\nParte fora do vetor text: %s\n", resto - 12);
    return 0;
}
