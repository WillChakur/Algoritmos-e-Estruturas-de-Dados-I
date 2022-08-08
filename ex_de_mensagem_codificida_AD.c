#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* alfabeto_func(char *s, int *v){
    int i=0, valor;
    char *string_result;
    string_result = (char*)malloc(sizeof(char)*100);


    while(v[i] != -1){
        string_result[i] = s[v[i] - 1];

        i++;
    }

    return string_result;

};


int main() {
    char *alfabeto;
    int *msg_cod, i=0;
    char *string_result;

    msg_cod = (int*)malloc(sizeof(int)*100);
    alfabeto = (char*)malloc(sizeof(char)*100);

    gets(alfabeto);

    while(msg_cod[i] != -1){
        scanf("%d", &msg_cod[i]);
        if(msg_cod[i] == -1) break;
        i++;
    }



    string_result = alfabeto_func(alfabeto, msg_cod);
    free(alfabeto);
    free(msg_cod);

    printf("%s\n", string_result);
    free(string_result);

    return 0;
}
