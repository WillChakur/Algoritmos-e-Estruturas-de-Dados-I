#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define TAM_MAX 100

typedef struct fila
{
    int itens[TAM_MAX];
    int ini;
    int fim;
    int tam;
} fila;

fila* criar_fila();

int fila_cheia(fila *f);

int fila_vazia(fila *f);

int enfileirar(fila *f, int key);

int desinfileirar(fila *f);

void limpar_fila(fila *f);

void imprimir_fila(fila *f);

fila* intercala_fila(fila *f1, fila *f2);

int main()
{
    fila *f1;
    fila *f2;
    fila *f3;
    int num, num2;

    f1 = criar_fila();
    f2 = criar_fila();
    f3 = criar_fila();

    while(num != -1)
    {
        scanf("%d", &num);
        if(num == -1) break;
        enfileirar(f1, num);
    }

    while(num2 != -1)
    {
        scanf("%d", &num2);
        if(num2 == -1) break;
        enfileirar(f2, num2);
    }

    f3 = intercala_fila(f1, f2);

    imprimir_fila(f3);

    limpar_fila(f3);

    return 0;
}

fila* criar_fila()
{
    fila *p;
    p = (fila*)malloc(sizeof(fila));

    p-> tam = 0;
    p-> ini = p-> fim = -1;

    return p;
}

int fila_cheia(fila *p)
{
    if(p == NULL)
    {
        p = criar_fila();
        return -1;
    }
    if(p->tam == TAM_MAX - 1)
    {
        return 1;
    }
    else return 0;
}

int fila_vazia(fila *p)
{
    if(p == NULL)
    {
        p = criar_fila();
        return -1;
    }
    if(p->tam == 0)
    {
        return 1;
    }
    else return 0;
}

void limpar_fila(fila *f)
{
    free(f);
}

int enfileirar(fila *f, int key)
{
    if(f == NULL)
    {
        f = criar_fila();
    }
    if(!fila_cheia(f))
    {

        if(f->ini < 0)
        {
            f->ini = 0;
        }
        if(f->fim == TAM_MAX - 1)
        {
            f->fim = 0;
        }
        else
        {
            f->fim++;
        }

        f->itens[f->fim] = key;

        f->tam++;

        return 1;
    }

    return 0;
}

int desinfileirar(fila *f)
{
    int num;

    if(!fila_vazia(f))
    {
        num = f->itens[f->ini];

        f->tam--;

        if(f->tam == 0)
        {
            f->ini = f->fim = 0;
        }
        else if(f->ini == TAM_MAX - 1)
        {
            f->ini = 0;
        }
        else
        {
            f->ini++;
        }

        return num;
    }

    return 0;
}

void imprimir_fila(fila *f)
{
    int num;
    while(!fila_vazia(f))
    {
        num = desinfileirar(f);

        printf("%d ", num);
    }
}

fila* intercala_fila(fila *f1, fila *f2)
{
    fila *f3;
    int i,num,num2, tam_inicialf1, tam_inicialf2;
    f3 = criar_fila();
    tam_inicialf1 = f1->tam;
    tam_inicialf2 = f2->tam;

    if(tam_inicialf1 >= tam_inicialf2)
    {
        for(i=0; i<tam_inicialf1; i++)
        {
            num = desinfileirar(f1);
            num2 = desinfileirar(f2);

            if(i < tam_inicialf2)
            {
                if(num > num2)
                {
                    enfileirar(f3, num);
                    enfileirar(f3, num2);
                }
                else
                {
                    enfileirar(f3, num2);
                    enfileirar(f3, num);
                }
            }
            else
            {
                    enfileirar(f3, num);
            }
        }
    }
    if(tam_inicialf1 < tam_inicialf2)
    {
        for(i=0; i<tam_inicialf2; i++)
        {
            num = desinfileirar(f1);
            num2 = desinfileirar(f2);

            if(i < tam_inicialf1)
            {
                if(num > num2)
                {
                    enfileirar(f3, num);
                    enfileirar(f3, num2);
                }
                else
                {
                    enfileirar(f3, num2);
                    enfileirar(f3, num);
                }
            }
            else
            {
                enfileirar(f3, num2);

            }
        }
    }

    return f3;
}
