#include <stdio.h>
#include <string.h>
#include "PilhaChar.h"

int sequencia_valida(const char *s) {
    if (s == NULL) return 0;

    int tamanho = (int) strlen(s);
    if (tamanho == 0) return 1;

    Pilha *pi = cria_Pilha(tamanho);
    if (pi == NULL) return 0;

    for (int i = 0; i < tamanho; i++) {
        if (s[i] == 'I') {
            insere_Pilha(pi, 'I');
        } else if (s[i] == 'S' || s[i] == 'R') {
            if (remove_Pilha(pi) == 0) {
                libera_Pilha(pi);
                return 0;
            }
        } else {
            libera_Pilha(pi);
            return 0;
        }
    }

    int valida = Pilha_vazia(pi);
    libera_Pilha(pi);
    return valida;
}

int main(void) {
    printf("=== 1. Teste basico de PilhaChar ===\n");
    Pilha *pi = cria_Pilha(4);
    char topo;

    insere_Pilha(pi, 'A');
    insere_Pilha(pi, 'B');
    insere_Pilha(pi, 'C');
    if (consulta_topo_Pilha(pi, &topo))
        printf("Topo apos empilhar A, B, C (esperado C): %c | qtd=%d\n", topo, tamanho_Pilha(pi));

    printf("Desempilhando tudo:");
    while (!Pilha_vazia(pi)) {
        consulta_topo_Pilha(pi, &topo);
        printf(" %c", topo);
        remove_Pilha(pi);
    }
    printf("\nPilha vazia (esperado 1): %d\n", Pilha_vazia(pi));
    libera_Pilha(pi);

    printf("\n=== 2. Teste de sequencia_valida (I e S/R) ===\n");
    const char *seqs[] = {"IISIISSS", "IIRIIRRR", "IIISSS", "ISSIIS", "IIIS", "SI"};
    int esp_seq[]      = {1,          1,          1,        0,        0,      0};
    for (int i = 0; i < 6; i++) {
        printf("%-10s -> obtido: %d (esperado: %d)\n",
               seqs[i], sequencia_valida(seqs[i]), esp_seq[i]);
    }

    printf("\n=== 3. Teste de verifica_delimitadores ===\n");
    const char *exprs[] = {"(a)", "[(a)]", "{[a + (b * c)]}", "(a(", "(a]", ")a(", "[(])"};
    int esp_del[]       = {1,     1,       1,                 0,     0,     0,     0};
    for (int i = 0; i < 7; i++) {
        int r = verifica_delimitadores(exprs[i]);
        printf("%-18s -> obtido: %d (esperado: %d)\n", exprs[i], r, esp_del[i]);
    }

    return 0;
}
