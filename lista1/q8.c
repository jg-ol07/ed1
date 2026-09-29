#include <stdio.h>

/* Ao buscar o maior elemento de um vetor retornando um ponteiro (int *), a função não retorna apenas uma cópia do valor numérico, mas sim a localização exata (endereço) onde o maior número reside na memória.
Inicializamos o ponteiro 'maior' apontando para o primeiro endereço do vetor (maior = v).
Ao iterar pelo vetor, comparamos o valor no endereço apontado por maior (*maior) com o valor da posição atual.
Se encontrarmos um elemento estritamente maior, atualizamos o ponteiro fazendo 'maior = v + i', que usa aritmética de ponteiros para armazenar o endereço daquele i-ésimo elemento.
No main, podemos ler o maior número desreferenciando o ponteiro (*b) ou até mesmo alterá-lo no vetor original se desejado.
*/

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