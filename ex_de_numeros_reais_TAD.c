#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int i;
    int f;
} Real;

Real* criar(int i, int f);

Real* soma(Real *r1, Real *r2);

Real* subtracao(Real *r1, Real *r2);

int arredondar(Real *r1);

void imprimir(Real *r1);

int main()
{
    int i1, i2, f1, f2, arredondado, arredondado2;
    Real* r1;
    Real* r2;
    Real* rSoma;
    Real* rSubtracao;


    r1 = (Real*)malloc(sizeof(Real));
    r2 = (Real*)malloc(sizeof(Real));
    rSoma = (Real*)malloc(sizeof(Real));
    rSubtracao = (Real*)malloc(sizeof(Real));


    scanf("%d %d", &i1, &f1);
    scanf("%d %d", &i2, &f2);

    r1 = criar(i1, f1);
    r2 = criar(i2, f2);

    imprimir(r1);
    imprimir(r2);

    rSoma = soma(r1, r2);
    imprimir(rSoma);
    free(rSoma);

    rSubtracao = subtracao(r1, r2);
    imprimir(rSubtracao);
    free(rSubtracao);

    arredondado = arredondar(r1);
    arredondado2 = arredondar(r2);


    printf("%d ", arredondado);
    printf("%d", arredondado2);

    return 0;
}

Real* criar(int i, int f)
{
    Real* r1;
    r1 = (Real*)malloc(sizeof(Real));

    r1->i = i;
    r1->f = f;

    return r1;
};

Real* soma(Real *r1, Real *r2)
{
    Real* rSoma;
    rSoma = (Real*)malloc(sizeof(Real));
    int somaF, somaI;

    somaF = r1->f + r2->f;

    if(somaF >= 100)
    {
        somaI = r1->i + r2->i + 1;
        somaF = somaF - 100;
    }
    else
    {
        somaI = r1->i + r2->i;
    }

    rSoma->i = somaI;
    rSoma->f = somaF;

    return rSoma;

};

Real* subtracao(Real *r1, Real *r2)
{
    Real *rSubtracao;
    rSubtracao = (Real*)malloc(sizeof(Real));
    int subtF, subtI,x1,x2,subt;

    x1 = (r1->i*100) + r1->f;
    x2 = (r2->i*100) + r2->f;

    if(x1 >= x2){
        subt = x1 - x2;
    }
    else{
        subt = x2 - x1;
    }

    subtI = (int)subt/100;
    subtF = subt - (subtI*100);

    rSubtracao->i = subtI;
    rSubtracao->f = subtF;

    return rSubtracao;
}

int arredondar(Real *r1){
    int arredondado;

    arredondado = r1->i + 1;

    return arredondado;

}

void imprimir(Real *r1){
    if(r1->f < 10){
        printf("%d.0%d\n", r1->i, r1->f);
    }
    else{
        printf("%d.%d\n", r1->i, r1->f);
    }
}
