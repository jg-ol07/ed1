#include <stdio.h>

int *PrimeiraOcorrencia(int *v, int tam, int alvo){
    int *p = NULL;
    int flag = 0;
    for(int i = 0; i < tam; i++){
        if (v[i] == alvo){
            p = &v[i];
            flag = 1;
            break;
        }
    }
    if(flag){
        return p;
    }else{
        return NULL;
    }
}

int main(void){
    int a[] = {12, 7, 30, 4, 18, 30};
    int tamanho = sizeof(a)/sizeof(int);
    int valor = 0;
    int *ocurrence = NULL;
    
    printf("digite o valor que vc gostaria de encontrar no vetor\n");
    scanf("%d", &valor);

    ocurrence = PrimeiraOcorrencia(a,tamanho,valor);

    if (ocurrence == NULL){
        printf("valor nao encontrado");
        return 0;
    }
    
    *ocurrence = 0;

    for(int i = 0; i < tamanho; i++){
        printf("%d ", a[i]);
    }
    
    printf("\n");
    printf("programa finalizado.");

    
}