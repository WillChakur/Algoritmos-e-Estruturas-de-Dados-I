#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int matricula;
    char* nome;
    char* curso;
    float coef;
}Aluno;

void insert(Aluno *a, int tam);

int selection_sort(Aluno *a, int indiceInicial, int tam);

void swap(Aluno *a, int i, int j);

void imprimir(Aluno *a, int tam);

int main(void){
    int tam,i;
    scanf("%d", &tam);
    Aluno *a = (Aluno*)malloc(sizeof(Aluno)*tam);

    for(i=0; i<tam;i++){

        a[i].nome = (char*)malloc(sizeof(char)*100);
        a[i].curso = (char*)malloc(sizeof(char)*100);

        scanf("%d", &a[i].matricula);
        scanf("%s", a[i].nome);
        scanf("%s", a[i].curso);
        scanf("%f", &a[i].coef);
    }
    selection_sort(a, 0, tam);

    imprimir(a, tam);

    return 0;
}

void imprimir(Aluno *a, int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("%s %d %s %.2f\n", a[i].nome, a[i].matricula, a[i].curso, a[i].coef);
    }
}



int selection_sort(Aluno *a, int indiceInicial, int tam){
    if(indiceInicial >= tam-1)
        return -1;

    int menorIndice = indiceInicial;

    for(int i=indiceInicial; i<tam; i++){
        if(strcmp(a[i].nome, a[menorIndice].nome) < 0){
            menorIndice = i;
        }
        else if(strcmp(a[i].nome, a[menorIndice].nome) == 0){
            if(a[i].matricula < a[menorIndice].matricula){
                menorIndice = i;
            }
        }
    }
    swap(a, menorIndice, indiceInicial);

    selection_sort(a, indiceInicial+1, tam);

    return 0;
}

void swap(Aluno *a, int i, int j){
    Aluno aux;

    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}
