#include <stdio.h>

/* Em C, funções só podem ter um único valor de retorno através da instrução 'return'.
Para retornar mais de um resultado simultaneamente (neste caso, o valor mínimo e o valor máximo de um vetor),
utilizamos a passagem de parâmetros por referência através de ponteiros (int *min, int *max).
Passando os endereços de memória &min e &max a partir da função main, a função PercorreVetor é capaz de:
1. Receber esses endereços em cópias locais de ponteiros;
2. Desreferenciá-los (*min e *max) para ler os limites atuais;
3. Sobrescrever diretamente os valores nessas regiões de memória ao encontrar um valor menor ou maior.
A sintaxe de indexação a[i] funciona como um atalho para *(a + i), acessando diretamente o i-ésimo elemento a partir do início do vetor.
*/

void PercorreVetor(int *a, int n, int *min, int *max){
    printf("n: %d\n", n);

    for(int i = 0; i < n; i++){
        if (a[i] < *min){
            *min = a[i];
        }
        if (a[i] > *max){
            *max = a[i];
        }
    }
}

int main(void){
    int a[] = {12, 7, 30, 4, 18};
    int *p = a;
    int tamanho = sizeof(a)/sizeof(int);
    int max = a[0];
    int min = a[0];

    PercorreVetor(p, tamanho, &min, &max);

    printf("%d e %d", max, min);
}