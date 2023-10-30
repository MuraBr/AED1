#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "myList.h"

int numAlgorismos(int num)
{
    int valor;
    for(valor=0; num!=0; valor++)
    {
        num/=10;
    }
    return valor;
}

int numVetor(int vec[])
{
    int valor=0, i=0;
    do{
        valor++;
        i++;
    } while(vec[i]!='\0');
    return valor;
}

int main()
{   
    int a, b=0, n, k, pot, arr[10];
    long long int alg, len, num=0;
    //Lista num;
    //inicializa();
    printf("Digita a: ");
    scanf("%d", &a);
    // printf("Digita n: ");
    // scanf("%d", &n);

    // for(int i=10; i<n; i++)
    {
        k=0;
        a=a;
        b=a;
        len = numAlgorismos(a);
        pot = pow(10, len-1);
        for(int j=len; j>0; j--)
        {
            arr[k] = a/pot;
            a%=pot;
            pot/=10;
            k++;
        }
        alg = numVetor(arr);
        for(int i=0; i<=alg; i++)
        {
            num+=pow(arr[i], alg);
        }
    }
    for(int i=0; i<=10; i++) printf("%d ", arr[i]);
    printf("\n%lld %lld\n", len, num);
    return 0;
}