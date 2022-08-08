#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Celula Celula;

struct Celula
{
    int item;
    Celula *next;
};

typedef struct listaE
{
    Celula *head;
} listaE;

Celula* criar_celula(int key);

listaE* criar_lista();

int lista_vazia(listaE *l);

void adicionar_comeco(listaE *l, int key);

void adicionar(listaE *l, int key);

void rec_reco_transp(listaE *l, int num);

void imprimir_lista(listaE *l);

int main()
{
    int num, i,x;
    listaE *l =criar_lista();

    scanf("%d", &i);

    scanf("%d", &num);


    while(num != -1)
    {
        adicionar(l, num);
        scanf("%d", &num);
    }

    scanf("%d", &x);

    while(x > 0)
    {
        scanf("%d", &num);
        rec_reco_transp(l, num);
        x--;
    }

    imprimir_lista(l);

    return 0;
}

void imprimir_lista(listaE *l)
{
    if(!lista_vazia(l))
    {
        Celula *aux = l->head;

        while(aux != NULL)
        {
            printf("%d ", aux->item);
            aux = aux->next;
        }
    }
}

void rec_reco_transp(listaE *l, int num)
{
    if(!lista_vazia(l))
    {
        Celula *auxA = l->head, *auxO=auxA, *auxP=auxA;

        if(auxA->item != num && auxA->next->item != num)
        {
            while(auxA != NULL)
            {
                if(auxA->item == num)
                {
                    auxP->next = auxA;
                    auxO->next = auxA->next;
                    auxA->next = auxO;
                    break;
                }
                auxP = auxO;
                auxO = auxA;
                auxA = auxA->next;
            }
        }
        else if(auxA->next->item == num){
            auxP = auxA->next;
            auxA->next = auxP->next;
            auxP->next = auxA;
            l->head = auxP;
            
        }
    }
}

listaE* criar_lista()
{
    listaE *l = (listaE*)malloc(sizeof(listaE));

    l->head = NULL;

    return l;
}

Celula* criar_celula(int key)
{
    Celula *c = (Celula*)malloc(sizeof(Celula));

    c->next = NULL;
    c->item = key;

    return c;
}

int lista_vazia(listaE *l)
{
    return (l == NULL) || (l->head == NULL);
}

void adicionar_comeco(listaE *l, int key)
{
    Celula *nova = criar_celula(key);

    if(l == NULL)
        l = criar_lista();

    l->head = nova;
}

void adicionar(listaE *l, int key)
{
    Celula *nova = criar_celula(key);
    Celula *aux;
    if(l == NULL)
        l = criar_lista();

    if(lista_vazia(l))
        adicionar_comeco(l, key);
    else
    {
        aux = l->head;

        while(aux->next != NULL)
            aux = aux->next;

        aux->next = nova;
    }
;
D
C
B
D
A
A
D
B
B
B
A
A
A
A
A
A
A
A
A
B
B
B
B
B
B
B
B
B
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
B
B
B
B
B
B
B
B
B
B
B
B
}
