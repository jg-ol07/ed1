#include <stdio.h>

/* Ao passar um vetor para uma função em C, ele sofre decaimento (array decay) para um ponteiro que aponta para o primeiro elemento (int *a).
Ponteiros não guardam informações sobre o tamanho do vetor (fazer sizeof(a) dentro da função retornaria apenas o tamanho do ponteiro na arquitetura).
Por isso, é estritamente necessário passar o tamanho n como parâmetro separado.
Dentro da função, utilizamos a aritmética de ponteiros:
- Com *a, acessamos diretamente o valor contido no endereço atual da memória.
- Com a = a + 1 (ou a++), avançamos o ponteiro para o próximo endereço de memória contíguo (andando sizeof(int) bytes).
Como o parâmetro 'a' é uma cópia local do endereço original, modificá-lo dentro da função não afeta o ponteiro 'p' no main.
*/

int SomaVetor(int *a, int n){
    int soma = 0;
    printf("n: %d\n", n);
    for(int i = 0; i < n; i++){
        soma += *a;
        printf("soma agora: %d\n", soma);
        a = a + 1;
    }

    return soma;
}

int main(void){
    int a[] = {12, 7, 30, 4, 18};
    int *p = a;
    int tamanho = sizeof(a)/sizeof(int);

    int soma = SomaVetor(p, tamanho);
    printf("%d", soma);
}