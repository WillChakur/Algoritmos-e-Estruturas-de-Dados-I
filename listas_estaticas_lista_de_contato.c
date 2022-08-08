#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct contatos
{
    char contatos[MAX_SIZE][100];
    int ultimo_contato;
} contatos;

int inserir_contato(contatos *c, char nome[]);

int remover_contato(contatos *c, char nome[]);

contatos* criar_lista();

int lista_vazia(contatos *c);

int lista_cheia(contatos *c);

void imprimir(contatos *c);

void liberar(contatos *c);

void buscar(contatos *c, char busca[]);


int main()
{
    contatos *lista_contatos;
    char nome[100];
    char busca[100];
    int quantidade,i;

    lista_contatos = (contatos*)malloc(sizeof(contatos));

    lista_contatos = criar_lista();

    scanf("%s", busca);
    scanf("%d", &quantidade);

    for(i=0; i<quantidade; i++)
    {
        scanf("%s", nome);
        inserir_contato(lista_contatos, nome);
    }

    buscar(lista_contatos, busca);

    liberar(lista_contatos);




    return 0;
}

int inserir_contato(contatos *c, char nome[])
{

    if(c == NULL)
    {
        c = (contatos*)malloc(sizeof(contatos));

        c->ultimo_contato = 0;
        return -1;
    }
    else if(lista_cheia(c) == 0)
    {
        strcpy(c->contatos[c->ultimo_contato], nome);
        c->ultimo_contato++;

        return 1;
    }
    else
    {
        return 0;
    }
    
}

int remover_contato(contatos *c, char nome[])
{
    int i;
    int key;

    if(c != NULL)
    {
        c = (contatos*)malloc(sizeof(contatos));

        c->ultimo_contato = 0;
        return -1;
    }
    else if(lista_vazia(c) == 0)
    {
        for(i=0; i<c->ultimo_contato; i++)
        {
            if(strcmp(c->contatos[i], nome) == 0)
            {
                key = i;
            }
        }

        for(i=key; i<c->ultimo_contato; i++)
        {
            strcpy(c->contatos[i], c->contatos[i+1]);
        }

        c->ultimo_contato--;
        
        return 1;
    }
    else{
        
        return 0;
        
    }

}

contatos* criar_lista()
{
    contatos *l;
    l = (contatos*)malloc(sizeof(contatos));

    l->ultimo_contato = 0;
    
    return l;
}

int lista_vazia(contatos *c)
{
    if(c == NULL)
    {
        return -1;
    }
    else if(c->ultimo_contato == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int lista_cheia(contatos *c)
{
    if(c == NULL)
    {
        return -1;
    }
    else if(c->ultimo_contato == MAX_SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void imprimir(contatos *c)
{
    int i;

    for(i=0; i<c->ultimo_contato; i++)
    {
        printf("%s\n", c->contatos[i]);
    }
}

void liberar(contatos *c)
{
    free(c);
}

void buscar(contatos *c, char busca[])
{
    int i;
    char *string_busca;

    for(i=0;i<c->ultimo_contato;i++){
        string_busca = strstr(c->contatos[i], busca);

        if(string_busca)
            printf("%s\n", c->contatos[i]);
    }


}

