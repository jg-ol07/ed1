#include <stdio.h>
#include <stdlib.h>

int **criarMatriz(int lin, int col, int n){
    if (lin <= 0 || col <= 0){
        return NULL;
    }
    int **matriz = (int **)malloc(lin * sizeof(int *));
    if (!matriz){
    // !matriz vira um valor diferente de zero, ou seja, verdadeiro.
        return NULL;
    }

    for (int i = 0; i < lin; i++){
        matriz[i] = calloc(col, sizeof *matriz[i]); //preeche com zero, e não com lixo de memória.
        if(!matriz[i]){
            while (i > 0) free(matriz[--i]);
            free(matriz);
            return NULL;
        }

    }

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            matriz[i][j] = i * n + j; // Preenche a matriz com valores de exemplo, você pode modificar conforme necessário.
        }
    }

    return matriz;

}

void destruirMatriz(int **matriz, int lin){
    if(!matriz || lin <= 0){
        return;
    }
    for(int i = lin - 1; i >= 0; i--){
        free(matriz[i]);
    }
    free(matriz);
}


long somaDiagonal(int **matriz, int n){
    if(!matriz || n <= 0){
        return 0;
    }
    long soma = 0;
    for(int i = 0; i < n; i++){
        soma += matriz[i][i];
    }
    return soma;
}

void printMatriz(int **matriz, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    int lin = 0;
    int **matriz = NULL;
    printf("Digite o número de linhas: ");
    scanf("%d", &lin);

    matriz = criarMatriz(lin, lin, 2);
    if(!matriz){
        printf("Erro ao alocar memória para a matriz.\n");
        return 1;
    }
    long soma = somaDiagonal(matriz, lin);

    printf("Soma da diagonal principal: %ld\n", soma);

    printMatriz(matriz, lin);
    
    destruirMatriz(matriz, lin);
    matriz = NULL; // Evita dangling pointer

    if (matriz == NULL){
        printf("Matriz desalocada com sucesso.\n");
    } else {
        printf("Erro ao desalocar a matriz.\n");
    }

    return 0;
    
}