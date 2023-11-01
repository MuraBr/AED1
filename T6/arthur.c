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

int main()
{   
    int a, b=0, n, k, pot, arr[10];
    long long int alg, len, num=0;

    // printf("Digita a: ");
    // scanf("%d", &a);
    printf("Digita n: ");
    scanf("%d", &n);

    for(int i=10; i<=n; i++)
    {
        num=0;
        k=0;
        a=i;
        b=i;
        len = numAlgorismos(a);
        pot = pow(10, len-1);
        for(int j=len; j>0; j--)
        {
            arr[k] = a/pot;
            a%=pot;
            pot/=10;
            k++;
        }
        for(int i=0; i<=len; i++)
        {
            num+=pow(arr[i], len);
        }
    }
    return 0;
}
