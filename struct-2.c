#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct aluno_t{
    int cod;
    char nome[255];
    float notas[3];
    float media;
}alunos;


float calculaMedia(alunos aluno){
    int i;
    float soma=0;

    for(i=0; i<3; i++){
        soma += aluno.notas[i];
    }

    return soma/3;
}


void encontraMaiorMedia(alunos aluno[], int n){
    float maior_media = 0;
    int i, numero_do_aluno;

    for(i=0; i<n; i++){
        if(aluno[i].media > maior_media)
        {
            maior_media = aluno[i].media;
            numero_do_aluno = i;
        }
    }

    printf("O aluno com maior media e: %d %s %.1f", aluno[numero_do_aluno].cod, aluno[numero_do_aluno].nome, maior_media);
}

void encontraMenorMedia(alunos aluno[], int n){
    float menor_media = aluno[0].media;
    int i, numero_do_aluno;
    for(i=0; i<n; i++){
        if(aluno[i].media < menor_media)
        {
            menor_media = aluno[i].media;
            numero_do_aluno = i;
        }
    }

    printf("O aluno com menor media e: %d %s %.1f", aluno[numero_do_aluno].cod, aluno[numero_do_aluno].nome, menor_media);
}

void encontraMaiorP1(alunos aluno[], int n){
    float maior_p1 = 0;
    int i, numero_do_aluno;

    for(i=0; i<n; i++){
        if(aluno[i].notas[0] > maior_p1)
        {
            maior_p1 = aluno[i].notas[0];
            numero_do_aluno = i;
        }
    }

    printf("O aluno com maior P1 e: %d %s %.1f", aluno[numero_do_aluno].cod, aluno[numero_do_aluno].nome, maior_p1);
}

int main(){
    int numero_de_alunos;
    int i;

    scanf("%d", &numero_de_alunos);

    alunos aluno[numero_de_alunos];

    for(i=0; i<numero_de_alunos; i++){
        scanf("%d", &aluno[i].cod);
        scanf("%s", aluno[i].nome);
        scanf("%f %f %f", &aluno[i].notas[0], &aluno[i].notas[1], &aluno[i].notas[2]);
    }

    for(i=0; i<numero_de_alunos; i++){
        aluno[i].media = calculaMedia(aluno[i]);
    }

    for(i=0; i<numero_de_alunos; i++){
        if(aluno[i].media >= 6)
        {
            printf("Aprovado!\n");
        }
        else printf("Reprovado!\n");
    }

    encontraMaiorMedia(aluno, numero_de_alunos);
    printf("\n");

    encontraMenorMedia(aluno, numero_de_alunos);
    printf("\n");

    encontraMaiorP1(aluno, numero_de_alunos);


    return 0;
}
