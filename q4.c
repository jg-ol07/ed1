#include <stdio.h>

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