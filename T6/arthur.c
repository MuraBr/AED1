#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "myList.h"

long long int numAlgorismos(int num)
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
    int arr[10], len;
    long long int alg, a, b, num=0, n, k, pot;

    // printf("Digita a: ");
    // scanf("%d", &a);
    printf("Digita n: ");
    scanf("%lld", &n);

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
        for(int i=0; i<=len-1; i++)
        {
            num+=pow(arr[i], len);
        }
        if(num==b) insereOrdem(num);
    }
    return 0;
}
