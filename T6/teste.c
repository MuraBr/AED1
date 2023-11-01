#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "myList.h"

int main()
{
    inicializa();

    int a=0, b=1, c=2;
    insereOrdem(a);
    insereOrdem(b);
    insereOrdem(c);

    imprime();

    return 0;
}