#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ordenacao(int v[], int ini, int tam, int m);

int main()
{   
    int tam, m;
    scanf("%d", &tam);
    int v[tam];
    for(int i=0; i<tam;i++){
        scanf("%d", &v[i]);
    }
    
    scanf("%d", &m);
    
    ordenacao(v, 0, tam-1, m);
    
    for(int i=0; i<tam;i++){
        printf("%d ", v[i]);
    }
    
    return 0;
}

void ordenacao(int v[], int ini, int tam, int m)
{
    int i,j;
    if(tam > m)
    {
        int pivo = v[(tam+ini)/2], i=ini, j=tam;
        do
        {
            while(v[i] < pivo)
                i++;

            while(v[j] > pivo)
                j--;

            if(i <= j)
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
                j--;
            }
        }while(i <= j);

        if(j>ini)
            ordenacao(v, ini, j, m);
        if(i<tam)
            ordenacao(v, i, tam, m);
    }
    else 
    {
        for(i=ini; i<=tam-1; i++) 
        {
            for(j=ini; j<=tam - i - 1; j++)
            {
                if(v[j] > v[j+1])
                {
                    int item = v[j];
                    v[j] = v[j+1];
                    v[j+1] = item;
                }
            }
        }
    }
}
