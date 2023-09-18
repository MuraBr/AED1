char *minusculo(char texto[]){
    int i = 0;
    for(i;i<strlen(texto);i++){
        if(isupper(texto[i])){
            texto[i]=tolower(texto[i]);
        }
    }
    return(texto);
}
