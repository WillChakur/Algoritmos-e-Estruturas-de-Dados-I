#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef struct pilha
{
    int itens[MAX_SIZE];
    int ultimo_item;
} pilha;

pilha* inicializar();

int pilha_vazia(pilha *p);

int pilha_cheia(pilha *p);

int empilhar(pilha *p, int key);

int desempilhar(pilha *p);

void imprimir_pilha(pilha *p);

void decimal_binario(int decimal, pilha *p);

void liberar_pilha(pilha *p);




int main()
{
    pilha *p;
    int decimal;
    int num,i,u_item;

    p = inicializar();
    scanf("%d", &decimal);

    decimal_binario(decimal, p);
    
    u_item = p->ultimo_item;
    
    

    for(i=0;i<u_item;i++)
    {
        num = desempilhar(p);
        printf("%d", num);
    }
    
    liberar_pilha(p);

    return 0;
}

pilha* inicializar()
{
    pilha *p;
    p = (pilha*)malloc(sizeof(pilha));

    p->ultimo_item = 0;

    return p;
}

int pilha_vazia(pilha *p)
{
    if(p->ultimo_item == -1)
    {
        return 1;
    }
    else return 0;
}

int pilha_cheia(pilha *p)
{
    
    if(p->ultimo_item == MAX_SIZE - 1)
    {
        return 1;
    }
    else return 0;
}

int empilhar(pilha *p, int key)
{
    if(pilha_cheia(p) == 0)
    {
        p->itens[p->ultimo_item] = key;
        p->ultimo_item++;

        return 1;
    }
    else return 0;
}

int desempilhar(pilha *p)
{
    int num=0;
    if(pilha_vazia(p) == 0)
    {
        num = p->itens[p->ultimo_item - 1];
        p->ultimo_item--;
    }
    
    return num;
}

void imprimir_pilha(pilha *p)
{
    pilha aux = *p;
    int item, i;

    for(i=0; i<p->ultimo_item; i++)
    {
        item = desempilhar(&aux);

        printf("%d", item);
    }
}

void decimal_binario(int decimal, pilha *p)
{
    int binario;

    while(decimal != 1)
    {
       
        binario = decimal % 2;
        decimal = decimal/2;
       

        empilhar(p, binario);
    }

    empilhar(p, 1);
}

void liberar_pilha(pilha *p){
    free(p);
}
