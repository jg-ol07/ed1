#include <stdlib.h>
#include<stdio.h>
#include<math.h>

#include "ponto.h"

struct ponto
{
    float x;
    float y;
};

Ponto *criarPonto(float x, float y){
    printf("Criando ponto versão float x, y\n");
    Ponto *p = malloc(sizeof(Ponto));
    if (p == NULL) {
        return NULL;   // sem memoria disponivel
    }
    p->x = x;
    p->y = y;
    return p;
}

void liberarPonto(Ponto *p){
    free(p);
}

int lerPonto(Ponto *p, float *x, float *y){
    if (p == NULL) return 0;
    *x = p->x;
    *y = p->y;
    return 1;
}

int atribuirPonto(Ponto *p, float x, float y){
    if (p == NULL) return 0;
    p->x = x;
    p->y = y;
    return 1;

}

float  distancia(Ponto *p, Ponto *q){
    float dx, dy;
    if (p == NULL || q == NULL) return -1.0f;
    dx = p->x - q->x;
    dy = p->y - q->y;
    return sqrtf(dx * dx + dy * dy);
}