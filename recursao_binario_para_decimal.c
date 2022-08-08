#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int binario_decimal(int v[], int tam, int aux);

int main(void){
    int tam, resultado, aux=0;
    scanf("%d", &tam);
    int v[tam], i=0;

    while(i < tam){
        scanf("%d", &v[i]);
        i++;
    }

    resultado = binario_decimal(v, tam-1, aux);

    printf("%d", resultado);


    return 0;

}

int binario_decimal(int v[], int tam, int aux){
    int resultado;
    //printf("\n%d\n", v[aux]);
    if(tam == 0 && v[aux] == 1)
        resultado = 1;
    else if(tam == 0 && v[aux] == 0)
        resultado = 0;
    else{
        resultado = v[aux] * pow(2, tam) + binario_decimal(v, tam - 1, aux+1);
    }

    return resultado;
}
