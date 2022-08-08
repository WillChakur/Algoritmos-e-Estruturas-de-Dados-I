#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Celula Celula;

struct Celula{
    int item;
    Celula *next;
};

typedef struct ListaE{
    Celula *head;
}ListaE;

Celula* criar_celula(int key);

ListaE* criar_lista();

void inserir_comeco(ListaE *l, int key);

void inserir_final(ListaE *l, int key);

void remover(ListaE *l, int key);

void limpar(ListaE *l);

int lista_vazia(ListaE *l);

void imprimir(ListaE *l);

int tam_lista(ListaE *l);

int repete(ListaE *l, int key);

int main(void){
    ListaE *l = criar_lista();
    int num, procura, rep;

    scanf("%d", &num);

    while(num != -1){
        inserir_final(l, num);
        scanf("%d", &num);
    }
    
    scanf("%d", &procura);
    
    rep = repete(l, procura);

    printf("o item %d aparece %d vez(es)",procura, rep);
    
    limpar(l);

    return 0;
}

Celula* criar_celula(int key){
    Celula *c;

    c = (Celula*)malloc(sizeof(Celula));
    c->item = key;
    c->next = NULL;

    return c;
}

ListaE* criar_lista(){
    ListaE *l;
    l = (ListaE*)malloc(sizeof(ListaE));
    l->head = NULL;

    return l;

}

int lista_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}

void inserir_comeco(ListaE *l, int key){
    Celula *novo;

    if(l == NULL)
       l = criar_lista();

    novo = criar_celula(key);

    novo->next = l->head;
    l->head = novo;
}

void inserir_final(ListaE *l, int key){
    Celula *aux, *novo;

    if(!lista_vazia(l)){
    novo = criar_celula(key);
        aux = l->head;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = novo;
    }
    else{
        inserir_comeco(l, key);
    }
}

void remover(ListaE *l, int key){
    Celula *auxP=NULL, *auxA;

    if(!lista_vazia(l)){
        auxA = l->head;

        if(auxA->item == key){
            l->head = l->head->next;
        }
        else{
            auxP = auxA;

            while((auxA->item != key) && (auxA != NULL)){
                auxP = auxA;
                auxA = auxA->next;
            }
        }

        if(auxA != NULL){
            if(auxP != NULL){
                auxP->next = auxA->next;
            }
            free(auxA);
        }
    }
}

void limpar(ListaE *l){
    Celula *aux;

    if(!lista_vazia(l)){
        while(l->head != NULL){
            aux = l->head;
            l->head = aux->next;
            free(aux);
        }
        free(l);   aux = l->head;
    }
}

void imprimir(ListaE *l){
    Celula *aux;

    if(!lista_vazia(l)){
        aux = l->head;

        while(aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
        printf("\n");
    }
}

int tam_lista(ListaE *l){
    int tam=0;
    Celula *aux;

    if(!lista_vazia(l)){
        aux = l->head;

        while(aux != NULL){
            tam++;
            aux = aux->next;
        }
    }
    return tam;
}

int repete(ListaE *l, int key){
    Celula *aux;
    int cont=0;

    if(!lista_vazia(l)){
        aux = l->head;

        while(aux != NULL){
            if(aux->item == key){
                cont++;
            }
            aux = aux->next;
        }
    }

    return cont;
}
