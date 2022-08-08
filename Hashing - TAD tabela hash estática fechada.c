#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct hashTF{
    unsigned int tam;
    int *buckets;
}hashTF;


int inserir_hashTF(hashTF *hTF ,int num, float c);

hashTF* criar_hashTF(int tam);

int rehash(int h1, int h2, int tentativa, int tam);

int h1(int num, float c, int tam);

int h2(int num, int tam);

void liberar_hTF(hashTF *hTF);

int main(){
    float c;
    int tam, kquant,i,num;
    scanf("%f %d", &c, &tam);
    scanf("%d", &kquant);
    hashTF *hTF = criar_hashTF(tam);
    
    for(i=0;i<kquant;i++){
        scanf("%d", &num);
        inserir_hashTF(hTF, num, c);
    }
    
    liberar_hTF(hTF);
    
    return 0;
}

int h1(int num, float c, int tam){
    float pFrac;
    pFrac = num * c;
    pFrac = pFrac - (int)pFrac;    
    return (int)(pFrac * tam);
}

int h2(int num, int tam){
    return 1 + num % (tam - 1);
}

int rehash(int h1, int h2, int tentativa, int tam){
    return (h1 + (tentativa*h2)) % tam;
}

hashTF* criar_hashTF(int tam){
    hashTF *hTF = malloc(sizeof(hashTF));
    hTF->tam = tam;
    hTF->buckets = malloc(sizeof(int)*tam);
    for(int i=0; i<tam; i++){
        hTF->buckets[i] = -1;
    }
    return hTF;
}

int inserir_hashTF(hashTF *hTF ,int num, float c){
    int pos,i,rh;

    if(hTF != NULL){
        pos = h1(num, c, hTF->tam);

        if(hTF->buckets[pos] <= 0){
            hTF->buckets[pos] = num;
            printf("%d\n", pos);
            return 1;
        }
        else{
            i=1;
            rh = pos;
            int pos2 = h2(num, hTF->tam);

            while(hTF->buckets[rh] > 0 && hTF->buckets[rh] != num && i < hTF->tam){
                
                rh = rehash(pos, pos2, i, hTF->tam);
                i++;
            }
            if(i < hTF->tam && hTF->buckets[rh] <= 0){
                hTF->buckets[rh] = num;
                printf("%d\n", rh);
                return 1;
            }
        }
    }
    return 0;
}

void liberar_hTF(hashTF *hTF){
    if(hTF != NULL){
        free(hTF->buckets);
        free(hTF);
    }
}
