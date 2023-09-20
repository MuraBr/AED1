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

// Objetivo: dado a matriz que armazena todas as bacterias, encontra e retorna o endereço da menor bacteria
// Parametros: matriz com as bacterias e numero de bacterias na lista
// Retorno: posição inicial da menor bacteria na matriz de bacterias
char *encontraMenor(char listaBacterias[][COMPR_BACTERIAS], int numBacterias){
    int i, compBacteria, compMenorBacteria = COMPR_BACTERIAS;
    char *menor;
    //Varre a lista de bacterias e atribui ao ponteiro o endereço de uma bacteria, se ela for menor que qualquer outra encontrada
    for(i = 0; i < numBacterias; i++){
        compBacteria = strlen(listaBacterias[i]);
        if(compBacteria < compMenorBacteria){
            compMenorBacteria = compBacteria;
            menor = listaBacterias[i];
        }
    }
    return menor;
}

// Objetivo: encontra a maior sequencia genética que seja comum a todas as bacterias e armazena ela um vetor
// Parametros: matriz com as bacterias infectadas, endereço da menor bacteria e seu tamanho, endereço do vetor onde será armazenado a maior sequencia e o numero de bacterias
// Retorno: sem retorno
void maiorSequenciaComum(char listaBacterias[][COMPR_BACTERIAS], char *menor, int tamMenor, char *maior, int numBacterias){
    char sequenciaComparacao[COMPR_BACTERIAS];
    int numCaracteresSequencia = 0, posInicioSequenciaComparacao = 0, tamMaiorsequencia = 0;

    // Encontra a maior sequencia gentética comum a todas as bacterias
    //Enquanto a posição onde começamos a construir a sequencia de comparação não ultrapassar o vetor da menor bactéria rodamos o código
    //Além disso, se a maior sequência encontrada até então superar o tamanho de qualquer outra que pudermos encontrar, encerramos o código mais cedo
    for(posInicioSequenciaComparacao = 0; posInicioSequenciaComparacao + tamMaiorsequencia <= tamMenor; posInicioSequenciaComparacao++)
    {
        //Começamos uma nova sequência de comparação
        sequenciaComparacao[0] = menor[posInicioSequenciaComparacao];
        sequenciaComparacao[1] = '\0';
        //Enquanto o tamanho da sequencia atual mais a posição de onde começamos a análise não ultapassa o vetor
        //E a sequência é comum para todas as bactérias, contabilizamos o número de caracteres da sequência
        while((numCaracteresSequencia + posInicioSequenciaComparacao < tamMenor) && (verificaExistenciaSequencia(listaBacterias, sequenciaComparacao, numBacterias) == 1))
        {
            numCaracteresSequencia++;
            //Se for possível adicionar mais caracteres para sequência de comparação, adicionamos o próximo caracter 
            //existente na menor bactéria e fazemos os mesmos testes de novo
            if (numCaracteresSequencia + posInicioSequenciaComparacao < tamMenor)
            {
                sequenciaComparacao[numCaracteresSequencia] = menor[posInicioSequenciaComparacao + numCaracteresSequencia];
                sequenciaComparacao[numCaracteresSequencia + 1] = '\0';
            }
        }
        //Se a atual sequencia de comparação for maior que todas as outras, trocamos a maior sequencia
        if (tamMaiorsequencia < numCaracteresSequencia)
        {
            tamMaiorsequencia = numCaracteresSequencia;
            //Devemos garantir que copiamos o numero certo de caracteres, para os casos em que adicionamos mais caracteres
            //Mas a nova sequencia não era comum a todas as bactérias
            strncpy(maior, sequenciaComparacao, numCaracteresSequencia);
        }
        //Resetamos a sequencia de comparação e o tamanho dela
        numCaracteresSequencia = 0;
        memset(sequenciaComparacao, 0, strlen(sequenciaComparacao));
    }
}


int main(int argc, char *argv[])
{
    int nBacterias, tamMenorBacteria, i;
    char BACTERIAS[LIMITE_BACTERIAS][COMPR_BACTERIAS];
    char VIRUS[COMPR_VIRUS];
    char *menorBacteria, maiorSequencia[COMPR_BACTERIAS];

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
    menorBacteria = encontraMenor(BACTERIAS, nBacterias);
    tamMenorBacteria = strlen(menorBacteria);
    //Mostra as bacterias infectadas
    for (i = 0; i < nBacterias; i++)
    {
        printf(SAIDA_5, BACTERIAS[i]);
    }
    //Busca a maior sequencia comum para todas as bacterias infectadas e armazena no vetor maiorSequencia  
    maiorSequenciaComum(BACTERIAS, menorBacteria, tamMenorBacteria, maiorSequencia, nBacterias);
    //Mostra a bacteria modificada que será resistente ao vírus
    printf(SAIDA_6, maiorSequencia);
    return 0;
}
