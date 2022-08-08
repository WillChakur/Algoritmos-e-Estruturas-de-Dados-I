#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct complexo{
    float real, img, mod;
}complexo;

void atualizar_complexos(complexo *c, float real, float img){
    c->real = real;
    c->img = img;
    c->mod = sqrt(real * real + img * img);

    if(img >= 0){
        printf("%.1f+%.1fi\n%.1f", c->real, c->img, c->mod);
    }
    else{
        printf("%.1f%.1fi\n%.1f", c->real, c->img, c->mod);
    }
};

int main() {
    complexo c1;
    complexo *pcx;
    float real;
    float img;

    pcx = &c1;

    scanf("%f %f", &real, &img);

    atualizar_complexos(pcx, real, img);

    return 0;
}
