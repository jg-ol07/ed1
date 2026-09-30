#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int   matricula;
    char  nome[32];
    float media;
} Aluno;

int main(void) {
    // Aluno *a = malloc(sizeof(Aluno *));  outro erro, estamos alocando o tamanho de um ponteiro, e não o tamanho
    // da estrutura aluno.
    //correto: 
    Aluno *a = malloc(sizeof(Aluno));
    if (!a){
        return 1; // erro: não há checagem do retorno do malloc, se a alocação falhar, teremos um ponteiro nulo.
    }
    a->matricula = 20260145;
    a->media = 8.7f;

    // ERRO PRINCIPAL: NÃO HÁ CHECAGEM DO RETORNO DE NENHUM DOS MALLOCS, SE A ALOCAÇÃO FALHAR, TEREMOS UM PONTEIRO NULO.

    free(a);
    // outro erro, ao liberarmos a memória, temos que dar a anotação NULL ao ponteiro liberado, se não, ficaremos com um ponteiro
    // que aponta para uma região de memória que não é mais de nosso acesso.
    a = NULL;
    // printf("%.1f\n", a->media); // não vai imprimir nada e vai crashar o programa.

    Aluno *b = malloc(sizeof(Aluno));
    if (!b){
        return 1; // erro: não há checagem do retorno do malloc, se a alocação falhar, teremos um ponteiro nulo.
    }
    // erro 1: há uma alocação dupla, dentro da mesma variável, entretanto
    // na segunda linha (linha 22), nos sobreescrevemos o ponteiro, perdendo a referência para a primeira alocação
    // o que por consequencia, gera um vazamento de memória, ja que a primeira alocaçaõ dinamica jamais poderá ser liberada
    // b = malloc(sizeof(Aluno));
    b->matricula = 20260200;

    free(b);
    // free(b); não é necessário liberar o ponteiro duas vezes.
    // (inclusive, isso corrompe o heap e pode gerar erros de segmentação, caso tentemos acessar a memória liberada).
    b = NULL;

    int *v = malloc(5 * sizeof(int));
    if (!v){
        return 1; // erro: não há checagem do retorno do malloc, se a alocação falhar, teremos um ponteiro nulo.
    }
    // for (int i = 0; i <= 5; i++) erro: estamos acessando v[5], que não foi alocado.
    // correto:
    for (int i = 0; i < 5; i++) {
        v[i] = i * i;
    }
    
    free(v);
    v = NULL;

    return 0;
}