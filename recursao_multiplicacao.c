#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int multiplicacao(int num, int multiplicador);

int main(void){
    int resultado, num, multiplicador;

    scanf("%d %d", &num, &multiplicador);

    if(num < 0 || multiplicador < 0)
        return 0;

    resultado = multiplicacao(num, multiplicador);

    printf("%d", resultado);


    return 0;
}

int multiplicacao(int num, int multiplicador){
    int resultado;
    if(multiplicador == 0)
        resultado = 0;
    else
        resultado = num + multiplicacao(num, multiplicador - 1);

    return resultado;
}
