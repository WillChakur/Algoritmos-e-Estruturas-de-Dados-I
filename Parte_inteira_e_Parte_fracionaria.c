#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void frac(float n,int *pi, float *pf){

    *pi = (int)n;
    *pf = n - (int)n;

    printf("N=%.3f I=%d F=%.3f", n, *pi, *pf);
};

int main() {
    int n, i, *pi, in;
    float *pf, fr;

    pf = &fr;
    pi = &in;

    scanf("%d", &n);
    
    float v[n];

    for(i=0;i<n;i++){
        scanf("%f", &v[i]);
    };

    for(i=0; i<n; i++){

        frac(v[i], pi, pf);
        printf("\n");
    }

    return 0;
}
