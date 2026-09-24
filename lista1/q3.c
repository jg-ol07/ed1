#include <stdio.h>

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