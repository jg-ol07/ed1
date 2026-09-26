#include <stdio.h>

// também não podemos usar o v[] na passagem de parametros, mesmo que isso equivalha a v[x] = *(v + x);
int *MaiorValor(int *v, int n){
    // int n = sizeof(v)/sizeof(int); essa linha de c´doigo não pode ser executada aqui, porque sifeof(v) vai pegar o tamanho do ponteiro, invés do tamanho do vetor
    int *maior = v;
    for (int i = 1; i <= n; i++){
        if (v[i] > *maior){
            maior = v + i;
        }
    }

    return maior;
}

int main(void){
    int a[] = {14, 3, 27, 8, 11, 5};
    int *b = NULL;
    int tamanho = sizeof(a)/sizeof(int);
    
    b = MaiorValor(a, tamanho);

    printf("%d", *b);
}