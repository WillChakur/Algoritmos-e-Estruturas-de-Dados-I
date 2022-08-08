#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 100
typedef struct pilhaES
{
    int itens[MAX_SIZE];
    int topo;
} pilhaES;

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

pilhaES* criar_pilhaES();

void empilhar(pilhaES *p, int key);

int pilhaES_vazia(pilhaES *p);

int pilhaES_cheia(pilhaES *p);

int desempilhar(pilhaES *p);

void liberar_pilha(pilhaES *p);

void imprimir_pilha(pilhaES *p);

int filaE_vazia(filaE *f);

filaE* criar_filaE();

Celula* criar_celula(int key);

void enfileirar(filaE *f, int key);

int desinfileirar(filaE *f);

void imprimir_filaE(filaE *f);

void liberar_filaE(filaE *f);

void inverte_pilhaES(pilhaES *p, filaE *f);

int main(void)
{
    filaE *f = criar_filaE();
    pilhaES *p = criar_pilhaES();
    int i;

    scanf("%d", &i);

    while(i != -1){
        empilhar(p, i);
        scanf("%d", &i);
    }

    inverte_pilhaES(p, f);

    imprimir_filaE(f);

    return 0;
}

pilhaES* criar_pilhaES()
{
    pilhaES *p = (pilhaES*)malloc(sizeof(pilhaES));

    p->topo = 0;

    return p;
}

void empilhar(pilhaES *p, int key)
{
    if(p == NULL)
        p = criar_pilhaES();

    if(!pilhaES_cheia(p))
    {
        p->itens[p->topo] = key;
        p->topo++;
    }
}

int pilhaES_vazia(pilhaES *p)
{
    return (p == NULL) || (p->topo == 0);
}

int pilhaES_cheia(pilhaES *p)
{
    return (p->topo == MAX_SIZE - 1);
}

int desempilhar(pilhaES *p)
{
    int item=-INT_MAX;
    if(!pilhaES_vazia(p)){
        item = p->itens[p->topo-1];
        p->topo--;
    }

    return item;
}

void liberar_pilha(pilhaES *p){
    free(p);
}

void imprimir_pilha(pilhaES *p){
    int i;

    for(i=0; i<p->topo;i++){
        printf("%d ", p->itens[i]);
    }
}

int filaE_vazia(filaE *f){
    return (f == NULL) || (f->ini == NULL);
}

filaE* criar_filaE(){
    filaE *f = (filaE*)malloc(sizeof(filaE));

    f->ini = NULL;
    f->fim = NULL;

    return f;
}

Celula* criar_celula(int key){
    Celula *c = (Celula*)malloc(sizeof(Celula));
    c->item = key;
    c->next = NULL;

    return c;
}

void enfileirar(filaE *f, int key){
    Celula *nova;

    if(f == NULL)
        f = criar_filaE();

    nova = criar_celula(key);

    if(filaE_vazia(f)){
        f->ini = f->fim = nova;
    }
    else{
        f->fim->next = nova;
        f->fim = nova;
    }
}

int desinfileirar(filaE *f){
    int item=-INT_MAX;
    Celula *aux;

    if(!filaE_vazia(f)){
        aux = f->ini->next;
        item = f->ini->item;
        f->ini = aux;
    }

    return item;
}

void imprimir_filaE(filaE *f){
    Celula *aux;

    if(!filaE_vazia(f)){
        aux = f->ini;

        while(aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }

        printf("\n");
    }
}

void liberar_filaE(filaE *f){
    Celula *aux;

    if(!filaE_vazia(f)){
        while(f->ini != NULL){
            aux = f->ini;
            free(aux);
            f->ini = f->ini->next;
        }
        free(f);
    }
}

void inverte_pilhaES(pilhaES *p, filaE *f){
    if(f == NULL)
        f = criar_filaE();

    while(!pilhaES_vazia(p)){
        enfileirar(f, desempilhar(p));
    }
}
