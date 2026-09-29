#include <stdio.h>

/* Para que a função OrdenarPar funcione corretamente, precisamos alterar a ordem dos valores fora do escopo da própria função.
Como em C a passagem de parâmetros é sempre por valor (cópia), se passássemos inteiros comuns, estaríamos apenas alterando cópias locais.
Portanto, é necessário receber ponteiros (int *a, int *b) contendo os endereços de memória das variáveis originais.
Ao desreferenciar (*a e *b), acessamos diretamente a memória onde os números estão guardados, permitindo trocar seus valores com o auxílio de uma variável temporária aux.
No main, usamos a aritmética de ponteiros (b + 1) para acessar o elemento adjacente na memória contígua do vetor.
*/

void OrdenarPar(int *a, int *b){
    if (*a > *b){
        int aux = *a;
        *a = *b;
        *b = aux;
    }
    
}

int main(void){
    int a[2] = {9,5};
    int *b = &a[0];
    int *c = b + 1;

    for(int i = 0; i < 2; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    
    OrdenarPar(b, c);

    for(int i = 0; i < 2; i++){
        printf("%d ", a[i]);
    }

    return 0;

}