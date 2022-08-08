#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

struct Cell{
        int item;
        int col;
        Cell *next;
};


typedef struct ListaE{
        Cell *head;
}ListaE;


typedef struct Spa_Mat{
       int n_lin;
       int n_col;
       ListaE **lin;
}Spa_Mat;

Spa_Mat* criar(int l, int c);

static int validar_pos_matriz(int lin, int col, Spa_Mat* mat);

static void trocar_inserir_na_lista(int item, int col, ListaE *l);

static void remover_na_lista(int col, ListaE *l);

void trocar(int item, int l, int c, Spa_Mat* mat);

void bidimensional_para_esparca(int l, int c, Spa_Mat *mat);

int main() {
    int l,c;
    scanf("%d %d", &l, &c);
    Spa_Mat *mat = criar(l, c);
    bidimensional_para_esparca(l, c, mat);
    return 0;
}

void bidimensional_para_esparca(int l, int c, Spa_Mat *mat){
    int i,j, matriz[l][c];
    Cell *aux;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            if(matriz[i][j] != 0){
                trocar(matriz[i][j], i, j, mat);
            }
        }
    }
    
    for(i=0; i<l; i++){
        aux = mat->lin[i]->head;
        printf("%d:", i);
        if(mat->lin[i]->head == NULL){
            printf(" -> ");
        }
        while(aux != NULL){
            printf(" -> %d,%d", aux->col, aux->item);
            aux = aux->next;
        }
        printf("\n");
    }

    for(i=0; i<l; i++){
        while(mat->lin[i]->head != NULL){
            aux = mat->lin[i]->head;
            mat->lin[i]->head = aux->next;
            free(aux);
        }
    }

    free(mat);

}

Spa_Mat* criar(int l, int c){
        Spa_Mat* mat = (Spa_Mat*) malloc(sizeof(Spa_Mat));
        int i;

        mat->n_col = c;
        mat->n_lin = l;
        mat->lin = (ListaE**) malloc(sizeof(ListaE*) * l);

        for (i = 0; i < l; i++){
                mat->lin[i] = (ListaE*) malloc(sizeof(ListaE));
                mat->lin[i]->head = NULL;
        }

        return mat;
}


Cell* criar_celula(int item, int col){
    Cell *nova = (Cell*) malloc(sizeof(Cell));
    nova->item = item;
    nova->col = col;
    nova->next = NULL;

    return nova;
}

static int validar_pos_matriz(int lin, int col, Spa_Mat* mat){
    return (mat != NULL) && (lin >= 0) && (lin < mat->n_lin) && (col >= 0) && (col < mat->n_col);
}

static void trocar_inserir_na_lista(int item, int col, ListaE *l){
    Cell *auxA, *auxP, *novo;

    if ((l->head == NULL) || (col < l->head->col)){
        novo = criar_celula(item, col);
        novo->next = l->head;
        l->head = novo;

    }else if (col == l->head->col){
        l->head->item = item;
    }else{
        auxA = l->head;
        auxP = auxA;


        while ((auxP != NULL) && (auxP->col < col)){
            auxA = auxP;
            auxP = auxP->next;
        }

        if ((auxP != NULL) && (col == auxP->col))
            auxP->item = item;

        else{
            novo = criar_celula(item, col);
            novo->next = auxA->next;
            auxA->next = novo;
        }
    }
}

static void remover_na_lista(int col, ListaE *l){
    Cell *auxA, *auxP = NULL;


    if (l->head != NULL){
        if (col == l->head->col){
            auxP = l->head;
            l->head = l->head->next;
            free(auxP);
        }else{
            auxA = l->head;
            auxP = auxA;


            while ((auxP != NULL) && (auxP->col < col)){
                auxA = auxP;
                auxP = auxP->next;
            }

            if ((auxP != NULL) && (col == auxP->col)){
                auxA->next = auxP->next;

                free(auxP);
            }
        }
    }
}

void trocar(int item, int l, int c, Spa_Mat* mat){
    if (validar_pos_matriz(l, c, mat)){
        if (item > 0)
            trocar_inserir_na_lista(item, c, mat->lin[l]);
        else
            remover_na_lista(c, mat->lin[l]);
    }
}
