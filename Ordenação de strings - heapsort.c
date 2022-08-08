#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void heap_generator(char **string, int n);

void restore_heap(char **string, int esq, int dir);

void heap_sort(char **string, int n);

int main() {
    char **string;
    int tam,i;
    scanf("%d", &tam);
    string = (char**)malloc(sizeof(char*)*tam);

    for(i=0; i<tam;i++){
        string[i] = (char*)malloc(sizeof(char)*100);
        scanf("%s", string[i]);
    }

    heap_sort(string, tam);

    for(i=0; i<tam; i++){
        printf("%s\n", string[i]);
        free(string[i]);
    }

    free(string);

    return 0;
}

void heap_generator(char **string, int n){
    int esq = n/2;

    while(esq >= 0){
        restore_heap(string, esq, n-1);
        esq--;
    }
}

void restore_heap(char **string, int esq, int dir){
    int j = (esq + 1) * 2 - 1;

    char *x = string[esq];

    while (j <= dir){

        if ((j < dir) && (strcmp(string[j], string[j + 1]) < 0))
            j++;

        if (strcmp(string[j], x) < 0)
            break;

        string[esq] = string[j];
        esq = j;
        j = (esq + 1) * 2 - 1;
    }

    string[esq] = x;
}

void heap_sort(char **string, int n){
    char *x;
    int dir = n - 1;

    heap_generator(string, n);

    while (dir > 0){
        x = string[0];
        string[0] = string[dir];
        string[dir] = x;
        dir--;

        restore_heap(string, 0, dir);
    }
}
