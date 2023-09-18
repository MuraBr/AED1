#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *maisculo(char texto[]){
    int i = 0;
    for(i;i<strlen(texto);i++){
        if(islower(texto[i])){
            texto[i]=toupper(texto[i]);
        }
    }
    return(texto);
}
