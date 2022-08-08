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

void transferir(ListaE *l1, ListaE *l2);

void imprimir(ListaE *l);

int tam_lista(ListaE *l);

int main() {
    ListaE *l1, *l2;
    int num=0;

    l1 = criar_lista();
    l2 = criar_lista();

    scanf("%d", &num);

    while(num != -1){
        inserir_final(l1, num);
        scanf("%d", &num);
    }

    transferir(l1, l2);

    imprimir(l1);
    imprimir(l2);

    limpar(l1);
    limpar(l2);

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

void transferir(ListaE *l1, ListaE *l2){
    int tam = tam_lista(l1), i;
    Celula *aux, *aux2;

    if(!lista_vazia(l1)){
        aux = l1->head;
        if(tam % 2 != 0){
            for(i=0;i<(tam/2)+1;i++){
                aux = aux->next;
            }
        }
        else{
            for(i=0;i<tam/2;i++){
                aux = aux->next;
            }
        }
        while(aux != NULL){
            inserir_final(l2, aux->item);
            aux = aux->next;
        }
        aux2 = l2->head;
        while(aux2 != NULL){
            remover(l1, aux2->item);
            aux2 = aux2->next;
        }
    }
}
