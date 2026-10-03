#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_preco.h"

/* Definicao da lista (copiada de ListaSequencial.c, com struct produto
   no lugar de struct aluno). Necessaria para as funcoes abaixo. */
struct lista {
    int qtd;
    struct produto dados[MAX];
};

/* ------------------------------------------------------------
   Criacao e destruicao
   ------------------------------------------------------------ */

Lista* cria_lista(void) {
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if (li != NULL)
        li->qtd = 0;
    return li;
}

void libera_lista(Lista* li) {
    free(li);
}

/* ------------------------------------------------------------
   Informacoes de estado
   ------------------------------------------------------------ */

int tamanho_lista(Lista* li) {
    if (li == NULL)
        return -1;
    return li->qtd;
}

int lista_cheia(Lista* li) {
    if (li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int lista_vazia(Lista* li) {
    if (li == NULL)
        return -1;
    return (li->qtd == 0);
}

/* ------------------------------------------------------------
   Insercao
   ------------------------------------------------------------ */

int insere_lista_inicio(Lista* li, struct produto p) {
    int i;
    if (li == NULL)
        return 0;
    if (li->qtd == MAX)           /* teste de estouro */
        return 0;
    /* copia do fim para o inicio, para nao sobrescrever um valor
       antes de ele ser copiado */
    for (i = li->qtd - 1; i >= 0; i--)
        li->dados[i + 1] = li->dados[i];
    li->dados[0] = p;
    li->qtd++;
    return 1;
}

int insere_lista_final(Lista* li, struct produto p) {
    if (li == NULL)
        return 0;
    if (li->qtd == MAX)           /* teste de estouro */
        return 0;
    li->dados[li->qtd] = p;       /* qtd e a primeira posicao livre */
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct produto p) {
    int k, i = 0;
    if (li == NULL)
        return 0;
    if (li->qtd == MAX)           /* teste de estouro */
        return 0;
    /* procura a primeira posicao com codigo maior ou igual */
    while (i < li->qtd && li->dados[i].codigo < p.codigo)
        i++;
    /* abre espaco na posicao i */
    for (k = li->qtd - 1; k >= i; k--)
        li->dados[k + 1] = li->dados[k];
    li->dados[i] = p;
    li->qtd++;
    return 1;
}

/* ------------------------------------------------------------
   Remocao
   ------------------------------------------------------------ */

int remove_lista_inicio(Lista* li) {
    int k;
    if (li == NULL)
        return 0;
    if (li->qtd == 0)             /* teste de lista vazia */
        return 0;
    /* na remocao a copia anda do inicio para o fim */
    for (k = 0; k < li->qtd - 1; k++)
        li->dados[k] = li->dados[k + 1];
    li->qtd--;
    return 1;
}

int remove_lista_final(Lista* li) {
    if (li == NULL)
        return 0;
    if (li->qtd == 0)             /* teste de lista vazia */
        return 0;
    li->qtd--;                    /* nenhum elemento e deslocado */
    return 1;
}

int remove_lista(Lista* li, int cod) {
    int k, i = 0;
    if (li == NULL)
        return 0;
    if (li->qtd == 0)             /* teste de lista vazia */
        return 0;
    while (i < li->qtd && li->dados[i].codigo != cod)
        i++;
    if (i == li->qtd)             /* elemento nao encontrado */
        return 0;
    for (k = i; k < li->qtd - 1; k++)
        li->dados[k] = li->dados[k + 1];
    li->qtd--;
    return 1;
}

int remove_lista_otimizado(Lista* li, int cod) {
    int i = 0;
    if (li == NULL)
        return 0;
    if (li->qtd == 0)             /* teste de lista vazia */
        return 0;
    while (i < li->qtd && li->dados[i].codigo != cod)
        i++;
    if (i == li->qtd)             /* elemento nao encontrado */
        return 0;
    li->qtd--;                    /* qtd passa a indicar o ultimo elemento */
    li->dados[i] = li->dados[li->qtd];
    return 1;                     /* a ordem da lista foi alterada */
}

/* ------------------------------------------------------------
   Busca
   ------------------------------------------------------------ */

int busca_lista_pos(Lista* li, int pos, struct produto *p) {
    if (li == NULL || p == NULL || pos <= 0 || pos > li->qtd)
        return 0;
    *p = li->dados[pos - 1];      /* posicao 1 da lista = indice 0 */
    return 1;
}

/*
* QUESTÃO 1:
*/
int lista_tem_espaco(Lista *li, int n){
    if(li == NULL || n < 0){
        printf("uma das entradas eh invalida");
        return 0;
    }
    
    if (li->qtd + n <= MAX){
        printf("há espaco disponivel");
        return 1;
    }else{
        return 0;
    }
}
/*
* QUESTÃO 2:
*/
float soma_precos(Lista *li){
    if(!li){
        return 0;
    }
    float soma = 0.0;

    for(int i = 0; i < li->qtd; i++){
        soma += li->dados[i].preco;
    }
    return soma;
}

/*
* QUESTÃO 3:
*/
int busca_por_nome(Lista *li, char *nome, struct produto *p){
    if(li == NULL){
        return -1;
    }
    for(int i = 0; i < li->qtd; i++){
        if(strcmp(nome, li->dados[i].nome) == 0){
            *p = li->dados[i];
            return 1;
        }

    }
    return 0;
}

/*
* QUESTÃO 4:
*/
int insere_lista_decrescente(Lista *li, struct produto *p){
    if(p == NULL || li == NULL){
        return -1;
    }
    if(li->qtd == MAX){
        return -2;
    }
    int i = 0;
    while(i < li->qtd && p->preco < li->dados[i].preco){
        i++;
    }
    for (int k = li->qtd; k > i; k--){
        li->dados[k] = li->dados[k - 1];
    }
    li->dados[i] = *p;
    li->qtd++;
    return 0;
}
/*
* QUESTÃO 5:
*/
int remove_mais_caro(Lista *li, struct produto *removido){
    if(li == NULL){
        return -1;
    }
    if(li->qtd == 0){
        return -2;
    }
    if(removido == NULL){
        return -3;
    }
    int final = li->qtd-1;
    int mais_caro = 0;
    float maior_preco = li->dados[mais_caro].preco;

    for(int i = 0; i < li->qtd; i++){
       if(li->dados[i].preco > maior_preco){
        maior_preco = li->dados[i].preco;
        mais_caro = i;
       } 
    }
    *removido = li->dados[mais_caro];
    li->dados[mais_caro] = li->dados[final];
    li->qtd--;
    return 0;
}
/*
* QUESTÃO 6:
*/
int conta_faixa_preco(Lista *li, float min, float max){
    if(li == NULL){
        return -1;
    }

    int conta = 0;
    for(int i = 0; i < li->qtd; i++){
        if(li->dados[i].preco >= min && li->dados[i].preco <= max){
            conta++;
        }
    }
    return conta;
}
/*
* QUESTÃO 7:
*/
int remove_abaixo_de(Lista *li, float precoMinimo){
    if(li == NULL){
        return -1;
    }
    if(precoMinimo < 0){
        return -1;
    }
    int removidos = 0;
    int i = 0;
    while(i < li->qtd){
        if(li->dados[i].preco < precoMinimo){
            li->dados[i] = li->dados[li->qtd-1];
            li->qtd--;
            removidos++;
        }else{
            i++;
        }
    }
    return removidos;
}

/*
* QUESTÃO 8
*/
int mescla_listas(Lista *destino, Lista *origem){
    if (destino == NULL || origem == NULL)
        return -1;

    int inseridos = 0;

    for (int i = 0; i < origem->qtd; i++) {
        if (destino->qtd == MAX)
            break;

        int existe = 0;
        for (int j = 0; j < destino->qtd; j++) {
            if (destino->dados[j].codigo == origem->dados[i].codigo) {
                existe = 1;
                break;
            }
        }

        if (!existe) {
            destino->dados[destino->qtd] = origem->dados[i];
            destino->qtd++;
            inseridos++;
        }
    }

    return inseridos;
}

