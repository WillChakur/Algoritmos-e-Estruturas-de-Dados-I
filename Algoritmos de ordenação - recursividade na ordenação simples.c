#include <stdio.h>
#include <stdlib.h>

int selection_sort(int v[], int indiceInicial, int tam);

int main()
{   
    int tam;
    scanf("%d", &tam);
    int v[tam];
    for(int i=0; i<tam;i++){
        scanf("%d", &v[i]);
    }
    
    selection_sort(v, 0, tam);
    
    for(int i=0; i<tam;i++){
        printf("%d ", v[i]);
    }
    
    return 0;
}


int selection_sort(int v[], int indiceInicial, int tam){
    if(indiceInicial >= tam-1)
        return -1;

    int menorIndice = indiceInicial;

    for(int i=indiceInicial; i<tam; i++){
        if(v[i] < v[menorIndice]){
            menorIndice = i;
        }
    }

    int aux = v[menorIndice];
    v[menorIndice] = v[indiceInicial];
    v[indiceInicial] = aux;

    selection_sort(v, indiceInicial+1, tam);

    return 0;

}
