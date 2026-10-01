#include <stdlib.h>
#include<stdio.h>
#include<math.h>

#include "ponto.h"

struct ponto
{
    float c[2];
};

Ponto *criarPonto(float x, float y){

    printf("Criando ponto versão float c[2]\n");
    Ponto *p = malloc(sizeof(Ponto));
    if (p == NULL) {
        return NULL;   // sem memoria disponivel
    }
    p->c[0] = x;
    p->c[1] = y;
    return p;
}

void liberarPonto(Ponto *p){
    free(p);
}

int lerPonto(Ponto *p, float *x, float *y){
    if (p == NULL) return 0;
    *x = p->c[0];
    *y = p->c[1];
    return 1;
}

int atribuirPonto(Ponto *p, float x, float y){
    if (p == NULL) return 0;
    p->c[0] = x;
    p->c[1] = y;
    return 1;

}

float  distancia(Ponto *p, Ponto *q){
    float dx, dy;
    if (p == NULL || q == NULL) return -1.0f;
    dx = p->c[0] - q->c[0];
    dy = p->c[1] - q->c[1];
    return sqrtf(dx * dx + dy * dy);
}