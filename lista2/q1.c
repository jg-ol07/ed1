#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[32];
    float media;
} Aluno;

/* Nesta questão exploramos a alocação dinâmica de structs e o uso de ponteiros para ponteiros:
1. criarAluno: se criássemos o Aluno como variável local na pilha (stack), sua memória seria liberada assim que a função retornasse, gerando um ponteiro inválido (dangling pointer). Por isso, usamos malloc(sizeof(Aluno)) na memória heap, garantindo que os dados permaneçam válidos até serem explicitamente liberados.
2. imprimirAluno: recebe 'const Aluno *a' (ponteiro constante). Passar por referência evita copiar os bytes inteiros da struct a cada chamada, aumentando o desempenho, enquanto o modificador 'const' impede alterações acidentais nos dados.
3. destruirAluno: recebe um ponteiro para ponteiro (Aluno **pa). Como a passagem de parâmetros em C é por valor, se recebêssemos apenas 'Aluno *a', poderíamos dar free(a), mas ao fazer 'a = NULL' estaríamos alterando apenas uma cópia local daquele endereço. Para alterar a variável 'aluno1' original da main para NULL (evitando ponteiros soltos / dangling pointers), precisamos passar o endereço do próprio ponteiro (&aluno1).
*/

Aluno *criarAluno(int matricula, const char *nome, float media){
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    if (aluno == NULL){
        return NULL;
    }
    aluno->matricula = matricula;
    strcpy(aluno->nome, nome);
    aluno->media = media;
    return aluno;
}

void imprimirAluno(const Aluno *a){
    if (a == NULL){
        printf("Aluno nulo.\n");
        return;
    }
    printf("Matricula: %d\n", a->matricula);
    printf("Nome: %s\n", a->nome);
    printf("Media: %.2f\n", a->media);
}

void destruirAluno(Aluno **pa){
    if (pa != NULL && *pa != NULL){
        free(*pa);
        *pa = NULL;
    }
}

int main(void){
    Aluno *aluno1 = criarAluno(12345, "Joao Silva", 8.5);
    if (aluno1 == NULL){
        printf("Erro ao criar aluno.\n");
        return 1;
    }
    imprimirAluno(aluno1);

    destruirAluno(&aluno1);
    
    imprimirAluno(aluno1);
    return 0;

}


