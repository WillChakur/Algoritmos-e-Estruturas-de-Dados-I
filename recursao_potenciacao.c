#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int potenciacao(int num, int p);


int main(void){
    int resultado, p, num;

    scanf("%d %d", &num, &p);

    if(num < 0 || p < 0){
        return 0;
    }

    resultado = potenciacao(num, p);

    printf("%d", resultado);



}

int potenciacao(int num, int p){
    int resultado;
    if(p == 0)
        resultado = 1;
    else
        resultado = num * potenciacao(num, p-1);

    return resultado;
}
