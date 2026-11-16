/* ============================================================
   PilhaChar.h
   Estrutura de Dados I - UFPB - Aula 11
   Pilha sequencial estatica de char com capacidade definida na criacao
   ============================================================ */

#ifndef PILHA_CHAR_H
#define PILHA_CHAR_H

/* Tipo opaco: o usuario da biblioteca so pode declarar Pilha *pi. */
typedef struct pilha Pilha;

/* --- criacao e destruicao ---------------------------------- */

Pilha* cria_Pilha(int capacidade);

void libera_Pilha(Pilha* pi);

/* --- informacoes de estado --------------------------------- */

int tamanho_Pilha(Pilha* pi);

int Pilha_cheia(Pilha* pi);

int Pilha_vazia(Pilha* pi);

/* --- operacoes da pilha ------------------------------------- */

/* Insere um char no topo da pilha (empilha). */
int insere_Pilha(Pilha* pi, char c);

/* Remove o elemento do topo da pilha (desempilha). */
int remove_Pilha(Pilha* pi);

/* Copia para *c o char do topo, sem remove-lo. */
int consulta_topo_Pilha(Pilha* pi, char *c);

int verifica_delimitadores(const char *s);


#endif /* PILHA_CHAR_H */
