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

void string_para_int(char expressao[], pilha *p);

void limpar_pilha(pilha *p);

int main()
{
    char string[100];
    pilha *p;

    scanf("%s", string);
    p = inicializar();

    string_para_int(string, p);

    imprimir_pilha(p);
    
    limpar_pilha(p);

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

void string_para_int(char expressao[], pilha *p)
{
    char string[15][1] = {{'0'},{'1'},{'2'},{'3'},{'4'},{'5'},{'6'},{'7'},{'8'},{'9'},{'+'},{'-'},{'/'},{'*'}};
    int i, j,num1,num2,aux;
    char num = ' ';

    for(i=0; i<strlen(expressao); i++)
    {
        for(j=-1; j<13; j++)
        {
            if(expressao[i] == string[j][1])
            {

                num = string[j][1];
            }
        }
        switch(num)
        {
        case '0':
            empilhar(p, 0);
            break;
        case '1':
            empilhar(p, 1);
            break;
        case '2':
            empilhar(p, 2);
            break;
        case '3':
            empilhar(p, 3);
            break;
        case '4':
            empilhar(p, 4);
            break;
        case '5':
            empilhar(p, 5);
            break;
        case '6':
            empilhar(p, 6);
            break;
        case '7':
            empilhar(p, 7);
            break;
        case '8':
            empilhar(p, 8);
            break;
        case '9':
            empilhar(p, 9);
            break;
        case '+':
            num1 = desempilhar(p);
            num2 = desempilhar(p);
            aux = num2 + num1;
            empilhar(p, aux);
            break;
        case '-':
            num1 = desempilhar(p);
            num2 = desempilhar(p);
            aux = num2 - num1;
            empilhar(p, aux);
            break;
        case '*':
            num1 = desempilhar(p);
            num2 = desempilhar(p);
            aux = num1 * num2;
            empilhar(p, aux);
            break;
        case '/':
            num1 = desempilhar(p);
            num2 = desempilhar(p);
            aux = num2/num1;
            empilhar(p, aux);
        }
    }
}

void limpar_pilha(pilha *p){
    free(p);
}
