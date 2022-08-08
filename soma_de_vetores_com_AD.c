#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int* soma(int *v1, int n1, int *v2, int n2)
{
    int i;
    int *vResult;
    if(n1 > n2)
    {
        vResult = (int*)malloc(n1);

        for(i=0; i<n1; i++)
        {
            if(i < n2)
                vResult[i] = v1[i] + v2[i];
            else
                vResult[i] = v1[i];

        }
    }
    else
    {
        vResult = (int*)malloc(n2);

        for(i=0; i<n2; i++)
        {
            if(i < n1)
                vResult[i] = v1[i] + v2[i];
            else
                vResult[i] = v2[i];
        }
    }

    return vResult;
};

int main()
{
    int *v1, *v2;
    int n1, n2;
    int i;
    scanf("%d", &n1);
    v1 = (int*)malloc(n1);
    for(i=0; i<n1; i++)
    {
        scanf("%d", &v1[i]);
    }
    scanf("%d", &n2);

    v2 = (int*)malloc(n2);
    for(i=0; i<n2; i++)
    {
        scanf("%d", &v2[i]);
    }

    int *vResult = soma(v1, n1, v2, n2);
    free(v1);
    free(v2);

    if(n1 > n2)
    {
        for(i=0; i<n1; i++)
        {
            printf("%d ", vResult[i]);
        }
    }
    else
    {
        for(i=0; i<n2; i++)
        {
            printf("%d ", vResult[i]);
        }
    }
    free(vResult);


    return 0;
}

