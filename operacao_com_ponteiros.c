#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void manipula_ponteiros(int *pa, int *pb, int *pc){
    
    *pc = fabs(*pa - *pb);
    *pa = *pc + *pa;
    *pb = *pb - *pc;
    
    printf("A=%d B=%d C=%d", *pa, *pb, *pc);
      
};

int main() {

    int a, b, c;
    int *pa, *pb, *pc;
    
    scanf("%d %d", &a, &b);
    
    pa = &a;
    pb = &b;
    pc = &c;
    
    manipula_ponteiros(pa, pb, pc);

    return 0;
}

