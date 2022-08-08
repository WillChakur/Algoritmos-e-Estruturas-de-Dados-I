#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct numero_racional{
    int numerador, denominador;  
}racional;

racional racional_resultante(racional a, racional b){
    racional r3;
    
    r3.numerador = a.numerador * b.denominador;
    r3.denominador = a.denominador * b.numerador;
    
    return r3;
    
};

int main() {
    
    racional r1;
    racional r2;
    
    scanf("%d %d", &r1.numerador, &r1.denominador);
    scanf("%d %d", &r2.numerador, &r2.denominador);
    
    racional r3 = racional_resultante(r1, r2);
    
    printf("%d %d", r3.numerador, r3.denominador);
      
    return 0;
}

