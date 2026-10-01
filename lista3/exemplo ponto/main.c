#include<stdio.h>
#include "ponto.h"

int main(){
    Ponto *p = criarPonto(2.0f, 1.0f);
    Ponto *q = criarPonto(5.0f, 5.0f);


    float x, y;
    lerPonto(p, &x, &y);
    printf("Ponto x: %.1f - Ponto y: %.1f\n", x, y);
    printf("Distância: %.2f\n", distancia(p, q));
    
    liberarPonto(p);
    liberarPonto(q);

    return 0;

}