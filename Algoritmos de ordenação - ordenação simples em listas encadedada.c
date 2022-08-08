#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Celula Celula;

struct Celula{
    int item;
    Celula *next;
};

typedef struct listaE{
    Celula *head;
}listaE;

int lista_vazia(listaE *l);

Celula* criar_celula(int key);

listaE* criar_lista();

void inserir_inicio(listaE *l, int key);

void inserir_final(listaE *l, int key);

int remover(listaE *l, int key);

void liberar(listaE *l);

void imprimir(listaE *l);

void bubble_sort(listaE *l);

int tam_lista(listaE *l);

int main(void){
    listaE *l = criar_lista();
    int item;

    scanf("%d", &item);
    while(item != -1){
        inserir_final(l, item);
        scanf("%d", &item);
    }

    bubble_sort(l);

    imprimir(l);

    liberar(l);

    return 0;

}

void bubble_sort(listaE *l){
    if(!lista_vazia(l)){
        Celula *auxA, *auxB;
        int tam = tam_lista(l), item;

        for(int i = tam - 2;i>=0; i--){
            auxA = l->head;
            auxB = l->head->next;

            for(int j=0; j <= i; j++){
                if(auxA->item > auxB->item){
                    item = auxA->item;
                    auxA->item = auxB->item;
                    auxB->item = item;
                }
                auxA =  auxB;
                auxB = auxB->next;
            }
        }

    }
}



Celula* criar_celula(int key){
    Celula *nova = (Celula*)malloc(sizeof(Celula));

    nova->item = key;
    nova->next = NULL;

    return nova;
}

listaE* criar_lista(){
    listaE *l = (listaE*)malloc(sizeof(listaE));

    l->head = NULL;

    return l;
}

int lista_vazia(listaE *l){
    return (l == NULL) || (l->head == NULL);
}

void inserir_inicio(listaE *l, int key){
    Celula *nova = criar_celula(key);

    if(l == NULL)
        l = criar_lista();

    nova->next = l->head;
    l->head = nova;
}

void inserir_final(listaE *l, int key){
    Celula *novo, *aux;

    if(l == NULL)
        l = criar_lista();

    if(lista_vazia(l))
        inserir_inicio(l, key);
    else{
        aux = l->head;

        while(aux->next!= NULL)
            aux = aux->next;

        novo = criar_celula(key);

        aux->next = novo;
    }
}

int remover(listaE *l, int key){
    if(!lista_vazia(l)){
        Celula *aux = l->head, *auxP = NULL;

        if(aux->item == key)
            l->head = aux->next;

        else{
            while((aux != NULL) && (aux->item != key)){
                auxP = aux;
                aux = aux->next;
            }
        }

        if(aux != NULL){
            if(auxP != NULL){
                auxP->next = aux->next;
            }
            free(aux);

            return 1;
        }
    }
    return 0;
}

void liberar(listaE *l){
    if(l != NULL){
        Celula *aux = l->head;

        while(l->head != NULL){
            aux = l->head;
            l->head = l->head->next;
            free(aux);
        }
        free(l);
    }
}

void imprimir(listaE *l){
    if(!lista_vazia(l)){
        Celula *aux = l->head;

        while(aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }

        printf("\n");
    }
}

int tam_lista(listaE *l){
    int tam = 0;

    if(!lista_vazia(l)){
        Celula *aux = l->head;

        while(aux != NULL){
            tam++;
            aux = aux->next;
        }
    }
    return tam;
}
