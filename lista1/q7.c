#include <stdio.h>

void inverter(int *v, int tam){
    int j = tam - 1;
    for(int i = 0; i < j; i++){
        int aux = v[j];
        v[j] = v[i];
        v[i] = aux;
        j--;
    }
}

int main(void){
    int a[] = {9,18,4,30,7,12,10};
    int tamanho = sizeof(a)/sizeof(int);
     
    inverter(a, tamanho);

    for(int i = 0; i < tamanho; i++){
        printf("%d ", a[i]);
    }

    printf("\n");
    printf("saindo...");
}