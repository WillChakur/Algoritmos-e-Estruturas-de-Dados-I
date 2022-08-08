#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int *v; 
    int n; 
} Vetor;

Vetor* iniciar(int n);

int inserir(Vetor *v, int x, int i); 

Vetor* concatenar(Vetor *v1, Vetor *v2);

Vetor* soma(Vetor *v1, Vetor *v2);


int main()
{
    int n, n2, x,i;
    Vetor* v1;
    Vetor* v2;
    Vetor* vConcat;
    Vetor* vSoma;

    scanf("%d", &n);
    v1 = iniciar(n);

    for(i=0; i<n; i++)
    {
        scanf("%d", &x);
        inserir(v1, x, i);
    }

    scanf("%d", &n2);
    v2 = iniciar(n2);

    for(i=0; i<n2; i++)
    {
        scanf("%d", &x);
        inserir(v2, x, i);
    }

    vConcat = concatenar(v1, v2);

    for(i=0; i<vConcat->n; i++)
    {
        printf("%d ", vConcat->v[i]);
    }

    printf("\n");

    vSoma = soma(v1, v2);

    for(i=0; i<vSoma->n; i++)
    {
        printf("%d ", vSoma->v[i]);
    }

    return 0;
}

Vetor* iniciar(int n)
{
    Vetor* vPonteiro;
    vPonteiro = (Vetor*)malloc(sizeof(Vetor));
    vPonteiro->n = n;
    vPonteiro->v = (int*)malloc(sizeof(int)*n);

    return vPonteiro;
};

Vetor* concatenar(Vetor *v1, Vetor *v2)
{
    int i, j=0,tamanho1, tamanho2;
    Vetor *vConcat;

    tamanho1 = v1->n;
    tamanho2 = v2->n;

    vConcat = (Vetor*)malloc(sizeof(Vetor));
    vConcat->n = tamanho1+tamanho2;
    vConcat->v = (int*)malloc(sizeof(int)*(tamanho1 + tamanho2));

    if(tamanho1 > tamanho2)
    {
        for(i=0; i<tamanho1; i++)
        {
            vConcat->v[i] = v1->v[i];
        }
        for(i=tamanho1; i<tamanho1+tamanho2; i++)
        {
            vConcat->v[i] = v2->v[j];
            j++;
        }
    }
    else
    {
        for(i=0; i<tamanho1; i++)
        {
            vConcat->v[i] = v1->v[i];
        }
        for(i=tamanho1; i<tamanho1+tamanho2; i++)
        {
            vConcat->v[i] = v2->v[j];
            j++;
        }

    }
    return vConcat;
};

Vetor* soma(Vetor *v1, Vetor *v2)
{
    int i, tamanho1, tamanho2;
    Vetor *vSoma;
    vSoma = (Vetor*)malloc(sizeof(Vetor));

    tamanho1 = v1->n;
    tamanho2 = v2->n;


    if(tamanho1 > tamanho2)
    {
        vSoma->n = tamanho1;
        vSoma->v = (int*)malloc(sizeof(int)*tamanho1);
        for(i=0; i<tamanho1; i++)
        {
            if(i < tamanho2)
                vSoma->v[i] = v1->v[i] + v2->v[i];
            else
                vSoma->v[i] = v1->v[i];
        }
    }
    else
    {
        vSoma->n = tamanho2;
        vSoma->v = (int*)malloc(sizeof(int)*tamanho2);
        for(i=0; i<tamanho2; i++)
        {
            if(i < tamanho1)
                vSoma->v[i] = v1->v[i] + v2->v[i];
            else
                vSoma->v[i] = v2->v[i];
        }
    }

    return vSoma;
};

int inserir(Vetor *v, int x, int i)
{

    v->v[i] = x;

    return 1;

}
