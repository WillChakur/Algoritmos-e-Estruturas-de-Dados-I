#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

struct Cell{
    int item;
    Cell *next;
};

typedef struct listaE{
    Cell *head;
}listaE;

typedef struct hashTF{
    int tam;
    int *buckets;
}hashTF;

typedef struct hashTA{
    unsigned int tam;
    listaE *buckets;
}hashTA;

void liberar_hTA(hashTA *hTA);

void liberar_hTF(hashTF *hTF);

Cell* criar_celula(int num);

int h1(int k, int B);

hashTA* criar_hashTA(int tam);

hashTF* criar_hashTF(int tam);

int inserir_hashTF(hashTF *hTF ,int num);

int overflow_prog(int hashC, int tentativa, int tam);

void imprimir_hTA(hashTA *hTA);

void conversor(hashTF *hTF);

void inserir_hashTA(hashTA *hTA, int tam, hashTF *hTF);

void imprimir(hashTF *t);

int main() {
    int m, n, i, num;
    scanf("%d", &m);
    hashTF *hTF = criar_hashTF(m);
    hashTA *hTA = criar_hashTA(m);
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &num);
        inserir_hashTF(hTF, num);
    }  
    inserir_hashTA(hTA, m, hTF);

    imprimir_hTA(hTA);
    
    liberar_hTA(hTA);
    liberar_hTF(hTF);

    return 0;
}

void imprimir(hashTF *t){
    int i;
    if (t != NULL){
        for (i = 0; i < t->tam; i++){
            if (t->buckets[i] >= 0)
                printf("%d\n", t->buckets[i]);
        }
    }
}

Cell* criar_celula(int num){
    Cell *novo = malloc(sizeof(Cell));
    novo->next = NULL;
    novo->item = num;

    return novo;
}

hashTA* criar_hashTA(int tam)
{
    hashTA *hTA = malloc(sizeof(hashTA));
    hTA->tam = tam;
    hTA->buckets = malloc(sizeof(listaE)*tam);
    for(int i=0; i<tam ; i++)
    {
        hTA->buckets[i].head = criar_celula(-1);
    }
    return hTA;
}

hashTF* criar_hashTF(int tam){
    hashTF *hTF = malloc(sizeof(hashTF));
    hTF->tam = tam;
    hTF->buckets = malloc(sizeof(int)*tam);
    for(int i=0; i<tam; i++){
        hTF->buckets[i] = -1;
    }
    return hTF;
}

int h1(int k, int B){
    return k % B;
}

int overflow_prog(int hashC, int tentativa, int tam){
    return (hashC + tentativa)%tam;
}

int inserir_hashTF(hashTF *hTF ,int num){
    int pos,i,rh;

    if(hTF != NULL){
        pos = h1(num, hTF->tam);

        if(hTF->buckets[pos] <= 0){
            hTF->buckets[pos] = num;
            return 1;
        }
        else{
            i=1;
            rh = pos;

            while(hTF->buckets[rh] > 0 && hTF->buckets[rh] != num && i < hTF->tam){
                rh = overflow_prog(pos, i, hTF->tam);
                i++;
            }
            if(i < hTF->tam && hTF->buckets[rh] <= 0){
                hTF->buckets[rh] = num;
                return 1;
            }
        }
    }
    return 0;
}

void inserir_hashTA(hashTA *hTA, int tam, hashTF *hTF)
{
    int num;
    for(int i = 0; i<hTF->tam; i++)
    {
        num = hTF->buckets[i];
        if(hTA != NULL)
        {
            int l = h1(num, hTA->tam);
            Cell *aux, *novo = criar_celula(num);
            aux = hTA->buckets[l].head;
            while(aux != NULL)
            {
                while(aux->item > 0)
                {
                    if(aux->next == NULL)
                        aux->next = criar_celula(-1);

                    aux = aux->next;
                }
                if(aux->item <= 0)
                    aux->item = novo->item;

                aux = aux->next;
            }
        }
    }
}

void imprimir_hTA(hashTA *hTA){
    int i;
    if(hTA != NULL){
        Cell *aux;
        for(i=0;i<hTA->tam;i++){
            aux = hTA->buckets[i].head;
            printf("%d: -> ",i);
            while(aux != NULL){
                if(aux->item > 0)
                    printf("%d ", aux->item);
                if(aux->next != NULL)
                    printf("-> ");
                aux = aux->next;
            }
            printf("\n");
        }
    }
}

void liberar_hTA(hashTA *hTA){
    if(hTA != NULL){
        free(hTA->buckets);
        free(hTA);
    }
    
}

void liberar_hTF(hashTF *hTF){
    if(hTF != NULL){
        free(hTF->buckets);
        free(hTF);
    }
}
