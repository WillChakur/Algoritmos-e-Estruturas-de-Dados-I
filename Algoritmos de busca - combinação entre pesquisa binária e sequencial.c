#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void busca_bin_seq(int num, int v[], int n, int m);

int main(void)
{
    int num, m, n,i=0;

    scanf("%d", &num);
    scanf("%d", &n);
    int v[n];

    while(i < n){
        scanf("%d", &v[i]);
        i++;
    }

    scanf("%d", &m);

    busca_bin_seq(num, v, n, m);

    return 0;
}

void busca_bin_seq(int num, int v[], int n, int m)
{
    int fim = v[n-1], ini = v[0], meio=0, aux=0, indice=-1;
    
    while(fim - ini + 1 > m){
        meio = (fim+ini)/2;
        if(num == meio){
            printf("%d", meio-1);
            aux=1;
            break;
        }
        else if(num < meio)
            fim = meio - 1;
        else
            ini = meio + 1;
    }

    if(aux == 0){
        for(int i=ini-1;i<fim;i++){
        printf("%d ", v[i]);
        if(num == v[i])
            indice = i;
        }   
        printf("\n%d", indice);
    }
}
