#ifndef PONTO_H
#define PONTO_H

typedef struct ponto Ponto;

Ponto *criarPonto(float x, float y);

void   liberarPonto(Ponto *p);

int    lerPonto(Ponto *p, float *x, float *y);

int    atribuirPonto(Ponto *p, float x, float y);

float  distancia(Ponto *p, Ponto *q);


#endif

