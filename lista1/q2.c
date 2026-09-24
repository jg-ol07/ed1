#include <stdio.h>

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