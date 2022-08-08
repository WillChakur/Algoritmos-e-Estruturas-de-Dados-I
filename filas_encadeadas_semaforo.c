#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Celula Celula;

struct Celula
{
    int item;
    Celula *next;
};

typedef struct filaE
{
    Celula *ini;
    Celula *fim;
} filaE;

Celula* criar_celula(int key);

filaE* criar_filaE();

int filaE_vazia(filaE *f);

void enfileirar(filaE *f, int key);

int desinfileirar(filaE *f);

void liberar_filaE(filaE *f);

void imprimir_filaE(filaE *f);

filaE* adm_semaforo(filaE *f1, filaE *f2, filaE *f3);

int main()
{
    filaE *f1 = criar_filaE();
    filaE *f2 = criar_filaE();
    filaE *f3 = criar_filaE();
    filaE *rod;
    int item;

    scanf("%d", &item);
    while(item != -1)
    {
        enfileirar(f1, item);
        scanf("%d", &item);
    }


    scanf("%d", &item);
    while(item != -1)
    {
        enfileirar(f2, item);
        scanf("%d", &item);
    }

    scanf("%d", &item);
    while(item != -1)
    {
        enfileirar(f3, item);
        scanf("%d", &item);
    }


    rod = adm_semaforo(f1, f2, f3);

    imprimir_filaE(rod);
    
    liberar_filaE(f1);
    liberar_filaE(f2);
    liberar_filaE(f3);
    liberar_filaE(rod);

    return 0;
}

Celula* criar_celula(int key)
{
    Celula *nova = (Celula*)malloc(sizeof(Celula));

    nova->item = key;
    nova->next = NULL;

    return nova;
}

filaE* criar_filaE()
{
    filaE* f = (filaE*)malloc(sizeof(filaE));

    f->ini = NULL;
    f->fim = NULL;

    return f;
}

int filaE_vazia(filaE *f)
{
    return (f == NULL) || (f->ini == NULL);
}

void enfileirar(filaE *f, int key)
{
    Celula *aux = criar_celula(key);

    if(f == NULL)
        f = criar_filaE();

    if(filaE_vazia(f))
        f->ini = f->fim = aux;
    else
    {
        f->fim->next = aux;
        f->fim = aux;
    }
}

int desinfileirar(filaE *f)
{
    int item=-INT_MAX;
    Celula *aux;
    if(!filaE_vazia(f))
    {
       aux = f->ini;

       f->ini = aux->next;

       item = aux->item;

       free(aux);
    }
    return item;
}

void liberar_filaE(filaE *f)
{
    Celula *aux;

    if(!filaE_vazia(f))
    {
        aux = f->ini;

        while(f->ini != NULL)
        {
            aux = f->ini;
            f->ini = f->ini->next;
            free(aux);
        }

        free(f);
    }
}

void imprimir_filaE(filaE *f)
{
    Celula *aux;

    if(!filaE_vazia(f))
    {
        aux = f->ini;

        while(aux != NULL)
        {
            printf("%d ", aux->item);
            aux = aux->next;
        }

        printf("\n");
    }
}

filaE* adm_semaforo(filaE *f1, filaE *f2, filaE *f3)
{
    filaE *rod_p = criar_filaE();
    int cont=0;

    while(!filaE_vazia(f1) || !filaE_vazia(f2) || !filaE_vazia(f3))
    {

        while(cont < 3)
        {
            if(filaE_vazia(f1))
            {
                break;
            }
            else
            {
                enfileirar(rod_p, desinfileirar(f1));

            }
            cont++;
        }

        cont = 0;

        while(cont < 3)
        {
            if(filaE_vazia(f2))
            {
                break;
            }
            else
            {
                enfileirar(rod_p, desinfileirar(f2));
            }
            cont++;
        }

        cont = 0;

        while(cont < 3)
        {
            if(filaE_vazia(f3))
            {
                break;
            }
            else
            {
                enfileirar(rod_p, desinfileirar(f3));
            }
            cont++;
        }
    }
    return rod_p;
}