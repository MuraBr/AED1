//Testes
//5 CAAAAAACACCACACCCCAACCACAAACCAAAAAAAAACACAAACCAAAACACCCCCCAACAAAACAACACCACCCCCACCCCAACCCACCA CACAAAAACCCAAACAACCCAACCCAACCAACAACAACCCAACCACCCAAAAAAAAAACAACCA AACACAACACACACCCCCCCCCACAACACCCCACCCCACCCCAAACCCCACAACAACCAACACCCC ACCAAAAAAACACACCAACACCCCACACACCAACACCCCACCAACCCCCCCAAACACCCCCAACCAACCACACCAAAACCCACCCACACAA AAAAAACAAAACCCCCCAAACCCACAAAAACAACACCCCACCCAACCCCCCAAAACACAACCCAACCCCACACCCAAACCACAACAAACAACCCCCC AAAAA
//Resposta: CACCCCA
//8 AACTCACGGTGTAATGTCTATTACATCTGATGAGCCAGAGC CTAGCTAGTTCTACCCAACTGTTCGTAACCAGGATCT AACTGCGATGAATGTAACTACGTCTCCCTGAGACCGGAGCAGCTTGTGCAGTGCATGCGCCGACACAGTGCTTTAATTGG GCCACGGGTCACCCTGCCCATGTCGTGCTTGCGACCACATTAAGCTTTGGTTTAGCTTTAACCGTGATAAATAACCTAGTGCATCGG CTACGTACCCGCCAGTAAGGAGCAACTTACTCGTTGATACGATCACGATTGTCATTCAACTTTCAAACGCTTCCGCTTCACCGTCCAGTAAATGCGG ATGTCAG CTGTTAGCTCGGACGACTGTCGACCGGTGGGACTGGTTCAG GGCGATCGATTCGAATT CC
//Resposta: TC
//3 GCTTTCGACGAT GATCGAGCTTCGAA GGTCTAGCTAAT TCGA
//Resposta: GCT
//4 GCTTTCGACGAT GATCGAGCTTCGAA GGTCTAGCTAAT GATCGAGCTTCGAAGGTCTAGCTAATAACGTTCTCTGTGA TCGA
//Resposta: GCT
//5 AACCAAACCCCAAAACCAACAACACA CAACAAACCAAACCCCC AAAAACCCACAACA ACCACACAACCCA ACCACCCAAA CAC
//Resposta: AAA
//2 ACACTATACTA ACACTATACTA ACTA
//Resposta:CTA
//2 CAACAAAACCAAAACCCACCCCCACACCACCCACAAAAACCACAACCACCCAACACCCACCAACCACCAACAAAACCCCAAAACCCACACACCCAACAAAACAACACCCACACACACCCCAACCCCAACAACCAAAACCAACACCCCAACCCCAAAAAACACCCCCAAACAAAACCCCCCACACCCCCCCCAAACACCACCAACACCCAAAACCCCAAACACCACCAAAAACAACACACAAAAACACCACAACACACCCCACCACACAAAAAACACCCACCCAACCAAACCAAACCAAAAAACCCCAACCAAAAACCACCAAAACCACCAACACAAACACAACAACCCAACAACACAACCACACACCAACAAACAACCACCCCCACCAAACACCCCAACAACAACAAACACACAACCCCCCAAAACCAAACAACACAACCCAAAAAACCCCAACAAACAACCACCAACCCAACAACAACCAACACCACAAAAAACCCAAACAACCAACCCCCCACAACAACAACAAACAACCCCAAACCCAAAACCACAACCAACCACAAAACCCACCCAACCACACACCAACCAAAACAACAAAAACCCAAACAACAAACAAACCACCAA CAAAAACACCACAACCACCAAAACCCCACCAACAAAAAACCACAAACCACCACCCAAAACCCACCACAACCACAACCCACACCCCACCCACACCCACAAACAAAAAACCAAAACCCACACCCCAACAACCACCACCACCCACCACCCCACACCCCCACCAACCCCACCAACACAAACCCCACACCCCCCACCAACCCACCAACCACAAACCACAAACCCACCACCCCACACCAAAACAACAAACAACCCAAACAACCCCACCCCCCCCAAAAAACAAACCACAACACACAAACCCCCAACAACACAACAACACCACCCCAAAACCCAACACACAAAACCACACACCCACCACCAAACCCCCACACCACAAACACAAACACACACCCACACACCCAAAAACAAACCACCACCAACAAAACACCAAAACAACCCCAAAACCAAACCACCACACACCACCCCCACACCACCCCAACCCCAAACACCCACACCCACACCCCACCCCCCA AAA
//Resposta: CACCCCAACCCCCACCC OU CCACCCCCACACCACCC

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LIMITE_BACTERIAS 10
#define COMPR_BACTERIAS 1000
#define COMPR_VIRUS 1000

#define SAIDA_2 "\nSAIDA_2 = Quantidade de bacterias: %d"
#define SAIDA_3 "\nSAIDA_3 = Bacteria: %s"
#define SAIDA_4 "\nSAIDA_4 = Virus: %s"
#define SAIDA_5 "\nSAIDA_5 = Bacteria infectada: %s"
#define SAIDA_6 "\nSAIDA_6 = DNA resultante: %s"

// Objetivo: elimina o parte do código genético de uma bactéria que é fraco a infecção do vírus
// Parametros: vetor que armazena o código genético de uma bactéria e vetor que armazena o RNA do vírus
// Retorno: nehnum
void eliminaSequenciaFraca(char bacteriaSaudavel[], char virusInfectador[])
{
    int tamanhoVirus, distSequenciaFracaAteFinal;
    char *sequenciaFraca, *resto, copia[1000];
    tamanhoVirus = strlen(virusInfectador);
    
    while (strstr(bacteriaSaudavel, virusInfectador) != NULL)
    {
        //Enquanto houver a sequencia do vírus no código genético da bactéria, o ponteiro sequenciaFraca passa a apontar para o lugar em que encontra a sequência do vírus
        //e a distância dessa sequencia até o final do código genético da bactéria é atualizado
        sequenciaFraca = strstr(bacteriaSaudavel, virusInfectador);
        distSequenciaFracaAteFinal = strlen(sequenciaFraca);
        if (distSequenciaFracaAteFinal != tamanhoVirus)
        {
            //O ponteiro resto aponta para a posição após a sequência do vírus, indicando que parte da bactéria deve ser mantida 
            resto = sequenciaFraca + tamanhoVirus;
            strcpy(copia, resto);
            //Para manter o código genético da bactéria que não possui o vírus, copiamos ele para o vetor cópia
            memset(sequenciaFraca, 0, distSequenciaFracaAteFinal);
            strcpy(sequenciaFraca, copia);
            //Depois de apagar as partes necessárias, copiamos de volta a parte do código que deveria ser mantida e depois zeramos o vetor de cópias
            memset(copia, 0, strlen(copia));
        }
        else
        {
            //No caso sequência do vírus ser encontrada no final da bactéria basta apagá-la
            memset(sequenciaFraca, 0, distSequenciaFracaAteFinal);
        }
    }
}
// Objetivo: verifica se uma certa substring genética é comum a todas as bacterias
// Parametros: matriz com as bacterias infectadas, a substring genética que deve ser verificada e o num de bacterias no teste
// Retorno: retorna 1 se a substring genética é comum para todas as bacterias e 0 em caso contrário
int verificaExistenciaSequencia(char bacteriasInfectadas[][COMPR_BACTERIAS], char substringGenetica[], int numBacterias)
{
    int i;
    for (i = 0; i < numBacterias; i++)
    {
        if (strstr(bacteriasInfectadas[i], substringGenetica) == NULL)
        {
            //Retorna imediatamente zero se não encontrar a substring genética em alguma bactéria
            return 0;
        }
    }
    //Se nunca retornar zero, então retorna um
    return 1;
}

int main(int argc, char *argv[])
{
    int nBacterias, tamMenorBacteria, tamMaiorsequencia, numCaracteresSequencia, i, posInicioSequenciaComparacao;
    char BACTERIAS[LIMITE_BACTERIAS][COMPR_BACTERIAS];
    char VIRUS[COMPR_VIRUS];
    char *menorBacteria, maiorSequencia[COMPR_BACTERIAS], sequenciaComparacao[COMPR_BACTERIAS];

    //Inicialização de variáveis
    numCaracteresSequencia = 0;
    posInicioSequenciaComparacao = 0;
    tamMenorBacteria = COMPR_BACTERIAS;
    tamMaiorsequencia = 0;

    nBacterias = atoi(argv[1]);
    printf(SAIDA_2, nBacterias);

    for (i = 2; i < argc - 1; i++)
    {
        strcpy(BACTERIAS[i - 2], argv[i]);
        printf(SAIDA_3, BACTERIAS[i - 2]);
    }

    strcpy(VIRUS, argv[argc - 1]);
    printf(SAIDA_4, VIRUS);
    
    // Infecta e reduz todas as bacterias com o virus
    for (i = 0; i < nBacterias; i++)
    {
        eliminaSequenciaFraca(BACTERIAS[i], VIRUS);
    }
    
    // Encontra a menor bacteria após a infecção do vírus
    for (i = 0; i < nBacterias; i++)
    {
        if (strlen(BACTERIAS[i]) < tamMenorBacteria)
        {
            tamMenorBacteria = strlen(BACTERIAS[i]);
            menorBacteria = BACTERIAS[i];
            //Quando encontra a menor bactéria dentro da matriz com as bactérias, o ponteiro da menor bactéria passa a apontar para o espaço onde ela está armazenada
        }
        printf(SAIDA_5, BACTERIAS[i]);
    }
    
    // Encontra a maior sequencia gentética comum a todas as bacterias
    //Enquanto a posição onde começamos a construir a sequencia de comparação não ultrapassar o vetor da menor bactéria rodamos o código
    //Além disso, se a maior sequência encontrada até então superar o tamanho de qualquer outra que pudermos encontrar, encerramos o código mais cedo
    for(posInicioSequenciaComparacao = 0; posInicioSequenciaComparacao + tamMaiorsequencia <= tamMenorBacteria; posInicioSequenciaComparacao++)
    {
        //Começamos uma nova sequência de comparação
        sequenciaComparacao[0] = menorBacteria[posInicioSequenciaComparacao];
        sequenciaComparacao[1] = '\0';
        //Enquanto o tamanho da sequencia atual mais a posição de onde começamos a análise não ultapassa o vetor
        //E a sequência é comum para todas as bactérias, contabilizamos o número de caracteres da sequência
        while((numCaracteresSequencia + posInicioSequenciaComparacao < tamMenorBacteria) && (verificaExistenciaSequencia(BACTERIAS, sequenciaComparacao, nBacterias) == 1))
        {
            numCaracteresSequencia++;
            //Se for possível adicionar mais caracteres para sequência de comparação, adicionamos o próximo caracter 
            //existente na menor bactéria e fazemos os mesmos testes de novo
            if (numCaracteresSequencia + posInicioSequenciaComparacao < tamMenorBacteria)
            {
                sequenciaComparacao[numCaracteresSequencia] = menorBacteria[posInicioSequenciaComparacao + numCaracteresSequencia];
                sequenciaComparacao[numCaracteresSequencia + 1] = '\0';
            }
        }
        //Se a atual sequencia de comparação for maior que todas as outras, trocamos a maior sequencia
        if (tamMaiorsequencia < numCaracteresSequencia)
        {
            tamMaiorsequencia = numCaracteresSequencia;
            //Devemos garantir que copiamos o numero certo de caracteres, para os casos em que adicionamos mais caracteres
            //Mas a nova sequencia não era comum a todas as bactérias
            strncpy(maiorSequencia, sequenciaComparacao, numCaracteresSequencia);
        }
        //Resetamos a sequencia de comparação e o tamanho dela
        numCaracteresSequencia = 0;
        memset(sequenciaComparacao, 0, strlen(sequenciaComparacao));
    }
    printf(SAIDA_6, maiorSequencia);
    return 0;
}
