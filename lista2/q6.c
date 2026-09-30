#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatenar(const char *a, const char *b){
    int tamTotal = strlen(a) + strlen(b) + 1; // +1 pq senao nao tem o "\0"
    int tamA = strlen(a);
    int tamB = strlen(b);
    char *t = malloc(tamTotal * sizeof(char));
    if (!t){
        return NULL; // tem que checar SEMPRE.
    }

    for (int i = 0; i < tamA; i++){
        t[i] = a[i];
    }
    for (int i = 0; i < tamB; i++){
        t[i + tamA] = b[i];
    }
    t[tamTotal - 1] = '\0'; // tem que colocar o \0 no final, senao nao é uma string.
    return t;
}

int main(void){
    char a[] = "Estrutura de ";
    char b[] = "Dados";
    char *t = concatenar(a, b);
    int tamfinal = strlen(t);
    printf("Tamanho final: %d\n", tamfinal);
    printf("%s\n", t);
    free(t);
    t = NULL; // tem que colocar o ponteiro como NULL, senao fica um dangling pointer.
    return 0;
}

// a função pede ao malloc o seguinte numero de bytes: 19 bytes, pois, como usamos o strlen, strlen
// so retorna o tamanho da string sem o \0, e como queremos concatenar duas strings
// temos que somar o tamanho das duas strings e adicionar 1 para o \0 no final.
// se nos esquecermos e tentar imprimir com %s, o printf vai imprimir lixo, pois nao tem o \0 no final da string.
// mesma coisa com strlen(t), se nao tiver o \0 no final, o strlen vai contar lixo e vai dar um tamanho errado.
// sizeof(a) vai devolver 16, pois a string "Estrutura de " tem 15 caracteres + 1 do \0, igualmente para b
// o que nao tem relação com o tamanho do texto, que na verdade, é 14. (5 para b).

