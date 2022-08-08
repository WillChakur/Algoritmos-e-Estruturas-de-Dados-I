#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int selection_sort(char **s, int indiceInicial, int tam);

void swap(char **s, int i, int j);

int main(void){
    int tam,i;
    scanf("%d", &tam);
    char **s = (char**)malloc(tam * sizeof(char*)), str;

    for(i=0; i<tam;i++){
        s[i] = (char*)malloc(sizeof(char)*10);
    }

    for(i=0;i<tam;i++){
        scanf("%s", s[i]);
    }

    selection_sort(s, 0, tam);

    for(i=0;i<tam;i++){
        printf("%s\n", s[i]);
    }

    for(i=0;i<tam;i++){
        free(s[i]);
    }
    free(s);

    return 0;
}

int selection_sort(char **s, int indiceInicial, int tam){
    if(indiceInicial >= tam-1)
        return -1;

    int menorIndice = indiceInicial;

    for(int i=indiceInicial; i<tam; i++){
        if(strcmp(s[i], s[menorIndice]) < 0){
            menorIndice = i;
        }
    }

    swap(s, menorIndice, indiceInicial);

    selection_sort(s, indiceInicial+1, tam);

    return 0;
}

void swap(char **s, int i, int j){
    char *str;

    str = s[i];
    s[i] = s[j];
    s[j] = str;
}
