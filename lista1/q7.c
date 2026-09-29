#include <stdio.h>

/* Para inverter um vetor "in-place" (diretamente na memória original, sem alocar memória adicional), utilizamos a estratégia de dois ponteiros/índices:
um índice 'i' iniciando no começo do bloco de memória e um índice 'j' iniciando na última posição válida (tam - 1).
Como 'v' aponta diretamente para o bloco contíguo na memória RAM onde o vetor reside, a cada iteração acessamos as duas posições extremas v[i] e v[j].
Fazemos a troca direta de seus conteúdos utilizando uma variável auxiliar (aux) para não sobrescrever um dado antes de guardá-lo.
À medida que 'i' avança e 'j' recua, os dados vão sendo reordenados na memória original até que os índices se cruzem no meio do vetor.
*/

void inverter(int *v, int tam){
    int i = 0;
    int j = tam - 1;
    for(i; i < j; i++){
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