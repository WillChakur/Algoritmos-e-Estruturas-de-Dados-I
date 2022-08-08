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

int procurar_carro(fila *f, int id_carro);

int main() {
    fila *estacionamento;
    int id_carro, id_busca;

    estacionamento = criar_fila();

    while(id_carro != -1){
        scanf("%d", &id_carro);
        if(id_carro == -1) break;
        enfileirar(estacionamento, id_carro);
    }

    scanf("%d", &id_busca);

    procurar_carro(estacionamento, id_busca);

    limpar_fila(estacionamento);


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

int procurar_carro(fila *f, int id_carro){
    int id, i = 0,mov=0;
    int tam_inicial;
    tam_inicial = f->tam;

    while(i != 1){
        id = desinfileirar(f);
        if(id != id_carro){
            mov++;
            enfileirar(f, id);
            if(mov == tam_inicial) break;
        }
        else if(id == id_carro){
            i = 1;
        }
    }

    imprimir_fila(f);

    printf("\n%d\n", mov);
    
    if(i == 1){
        printf("sucesso");
    }
    else{
        printf("falha");
    }

    return 1;


}

