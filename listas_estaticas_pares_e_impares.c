#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct listas
{
    int itens[MAX_SIZE];
    int ultimo_item;
} listas;

listas* inicializar();

int inserir(listas *l, int key);

int lista_vazia(listas *l);

int remover(listas *l, int key);

int lista_cheia(listas *l);

void separar_l1(listas *l1, listas *l2, listas *l3);

void imprimir_lista(listas *l);

void limpar_lista(listas *l);

int main()
{
    listas *l1;
    listas *l2;
    listas *l3;
    l1 = inicializar();
    l2 = inicializar();
    l3 = inicializar();
    int num;

    while(num != -1)
    {
        scanf("%d", &num);
        if(num == -1) break;
        inserir(l1, num);
    }

    separar_l1(l1, l2, l3);

    printf("par: ");
    imprimir_lista(l2);
    printf("\n");
    printf("impar: ");
    imprimir_lista(l3);
    
    limpar_lista(l1);
    limpar_lista(l2);
    limpar_lista(l3);
    

    return 0;
}

listas* inicializar()
{
    listas *l;
    l = (listas*)malloc(sizeof(listas));

    l->ultimo_item = 0;

    return l;
}

int inserir(listas *l, int key)
{
    if(l == NULL)
    {
        l = (listas*)malloc(sizeof(listas));
        l->ultimo_item = 0;
        return -1;
    }
    else if(lista_cheia(l) == 0)
    {
        l->itens[l->ultimo_item] = key;
        l->ultimo_item++;

        return 1;
    }
    else
    {
        return 0;
    }
}

int lista_vazia(listas *l)
{
    return (l == NULL) || (l->ultimo_item == 0);
}

int remover(listas *l, int key)
{
    int i,k = 0;
    if(l == NULL)
    {
        l = (listas*)malloc(sizeof(listas));
        l->ultimo_item = 0;

        return -1;
    }
    else if(lista_vazia(l) == 1)
    {
        for(i=0; i<l->ultimo_item; i++)
        {
            if(l->itens[i] == key)
            {
                k = i;
            }
        }
        for(i=k; i<l->ultimo_item; i++)
        {
            l->itens[k] = l->itens[k+1];
        }

        l->ultimo_item--;

        return 1;
    }
    else
    {
        return 0;
    }
}

int lista_cheia(listas *l)
{
    if(l == NULL)
    {
        l = (listas*)malloc(sizeof(listas));
        l->ultimo_item = 0;

        return -1;
    }
    else if(l->ultimo_item == MAX_SIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void separar_l1(listas *l1, listas *l2, listas *l3)
{
    int i;

    for(i=0; i<l1->ultimo_item; i++)
    {
        if(l1->itens[i] % 2 == 0)
        {
            inserir(l2, l1->itens[i]);
        }
    }
    for(i=0; i<l1->ultimo_item; i++)
    {
        if(l1->itens[i] % 2 != 0)
        {
            inserir(l3, l1->itens[i]);
        }
    }
}

void imprimir_lista(listas *l)
{
    int i, cont=0;

    for(i=0; i<l->ultimo_item; i++)
    {

        printf("%d ", l->itens[i]);

        cont++;

    }

    if(cont == 0){
        printf("-1");
    }
}

void limpar_lista(listas *l){
    free(l);
}

