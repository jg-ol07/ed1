#include <stdio.h>

/* Retornar um ponteiro (int *) em vez de um índice inteiro confere à função a capacidade de dar acesso direto à memória do elemento encontrado.
Ao encontrar o valor 'alvo', a função obtém o endereço exato daquela posição no vetor original através do operador de endereço (&v[i]) e o retorna.
Dessa forma, a função chamadora (main) recebe esse endereço e pode alterar diretamente a memória original através da desreferenciação (*ocurrence = 0).
Caso o elemento não exista no vetor, a função retorna NULL (ponteiro nulo).
O retorno de NULL atua como uma sentinela segura para indicar a ausência do elemento, tornando obrigatória a verificação 'if (ocurrence == NULL)' antes de qualquer tentativa de desreferenciação para evitar uma falha de segmentação (Segmentation Fault).
*/

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