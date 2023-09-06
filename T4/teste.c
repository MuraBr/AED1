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

#define SAIDA_2 "\nSAIDA_2 = Quantidade de bacterias: %d\n"
#define SAIDA_3 "\nSAIDA_3 = Bacteria: %s\n"
#define SAIDA_4 "\nSAIDA_4 = Virus: %s\n"
#define SAIDA_5 "\nSAIDA_5 = Bacteria infectada: %s\n"
#define SAIDA_6 "\nSAIDA_6 = DNA resultante: %s\n"

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
        if (distSequenciaFracaAteFinal != tamanhoVirus)
        {
            resto = sequenciaFraca + tamanhoVirus;
            strcpy(copia, resto);
            memset(sequenciaFraca, 0, distSequenciaFracaAteFinal);
            strcpy(sequenciaFraca, copia);
            memset(copia, 0, strlen(copia));
        }
        else
        {
            memset(sequenciaFraca, 0, distSequenciaFracaAteFinal);
        }
    }
}
// Objetivo: verifica se uma certa substring genética é comum a todas as bacterias
// Parametros: matriz com as bacterias infectas, a substring genética que deve ser verificada e o num de bacterias no teste
// Retorno: retorna 1 se a substring genética é comum para todas as bacterias e 0 em caso contrário
int verificaExistenciaSequencia(char bacteriasInfectadas[][COMPR_BACTERIAS], char substringGenetica[], int numBacterias)
{
    int i;
    for (i = 0; i < numBacterias; i++)
    {
        if (strstr(bacteriasInfectadas[i], substringGenetica) == NULL)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int nBacterias, tamMenorBacteria, tamMaiorsequencia, numCaracteresSequencia, i, k;
    char BACTERIAS[LIMITE_BACTERIAS][COMPR_BACTERIAS];
    char VIRUS[COMPR_VIRUS];
    char *menorBacteria, maiorSequencia[COMPR_BACTERIAS], sequenciaComparacao[COMPR_BACTERIAS];
    tamMenorBacteria = COMPR_BACTERIAS;
    memset(sequenciaComparacao, 0, strlen(sequenciaComparacao));
    memset(maiorSequencia, 0, strlen(maiorSequencia));
    
    nBacterias = atoi(argv[1]);
    printf(SAIDA_2, nBacterias);

    for (i = 2; i < argc - 1; i++)
    {
        strcpy(BACTERIAS[i - 2], argv[i]);
        printf(SAIDA_3, BACTERIAS[i - 2]);
    }

    strcpy(VIRUS, argv[argc - 1]);
    printf(SAIDA_4, VIRUS);
    //Infecta todas as bacterias com o virus
    for (i = 0; i < nBacterias; i++)
    {
        eliminaSequenciaFraca(BACTERIAS[i], VIRUS);
    }
    //Encontra a menor bacteria após a infecção do vírus
    for (i = 0; i < nBacterias; i++)
    {
        if (strlen(BACTERIAS[i]) < tamMenorBacteria)
        {
            tamMenorBacteria = strlen(BACTERIAS[i]);
            menorBacteria = BACTERIAS[i];
        }
        printf(SAIDA_5, BACTERIAS[i]);
    }
    //Encontra a maior sequencia gentética comum a todas as bacterias
    k = 0;
    tamMaiorsequencia = 0;
    numCaracteresSequencia = 0;
    while ((k < tamMenorBacteria) && (tamMaiorsequencia < tamMenorBacteria - k))
    {

        sequenciaComparacao[0] = menorBacteria[k];
        sequenciaComparacao[1] = '\0';
        for (i = 0; (i < tamMenorBacteria - k) && (verificaExistenciaSequencia(BACTERIAS, sequenciaComparacao, nBacterias) == 1); i++)
        {
            numCaracteresSequencia++;
            if (numCaracteresSequencia < tamMenorBacteria - k)
            {
                sequenciaComparacao[numCaracteresSequencia] = menorBacteria[k + numCaracteresSequencia];
                sequenciaComparacao[numCaracteresSequencia + 1] = '\0';
            }
        }
        if (tamMaiorsequencia < numCaracteresSequencia)
        {
            tamMaiorsequencia = numCaracteresSequencia;
            memset(maiorSequencia, 0, strlen(maiorSequencia));
            strncpy(maiorSequencia, sequenciaComparacao, numCaracteresSequencia);
            maiorSequencia[numCaracteresSequencia] = '\0';
        }
        numCaracteresSequencia = 0;
        memset(sequenciaComparacao, 0, strlen(sequenciaComparacao));
        k++;
    }
    printf(SAIDA_6, maiorSequencia);
    return 0;
}
