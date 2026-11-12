/* Programa de teste simples da ListaDinEncadDupla.
   A lista e preenchida apenas parcialmente: acrescente novos
   alunos/testes conforme for implementando as outras funcoes. */
#include <stdio.h>
#include "ListaDinEncadDupla.h"

int main(void) {
    Lista *li = cria_lista();
    if (li == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }
    struct aluno al;
    int i;

    printf("vazia=%d cheia=%d tamanho=%d\n",
           lista_vazia(li), lista_cheia(li), tamanho_lista(li));

    /* --- preenchimento parcial ------------------------------ */
    /* struct aluno vem do .h: {matricula, nome, n1, n2, n3} */
    struct aluno a1 = {20, "Ana",   7.0f, 8.0f, 9.0f};
    struct aluno a2 = {30, "Bruno", 6.5f, 7.5f, 8.0f};
    struct aluno a3 = {10, "Carla", 9.0f, 9.5f, 10.0f};

    insere_lista_final(li, a1);
    insere_lista_final(li, a2);
    insere_lista_inicio(li, a3);

    /* o .h nao tem imprime_lista: percorre usando busca_lista_pos */
    printf("\n--- apos 3 insercoes (tamanho=%d) ---\n", tamanho_lista(li));
    for (i = 1; i <= tamanho_lista(li); i++) {
        if (busca_lista_pos(li, i, &al))
            printf("pos %d: %d %s\n", i, al.matricula, al.nome);
    }

    /* --- buscas --------------------------------------------- */
    if (busca_lista_pos(li, 2, &al))
        printf("\nbusca_pos(2) -> %d %s\n", al.matricula, al.nome);
    if (busca_lista_mat(li, 30, &al))
        printf("busca_mat(30) -> %s\n", al.nome);
    printf("busca_mat(99) = %d (esperado 0)\n", busca_lista_mat(li, 99, &al));

    /* --- adicione aqui novos testes ------------------------- */

    //questão 1
    printf("\n--- lista inversa ---\n");
    imprime_lista_inversa(li);

    //questão 2
    printf("\n--- testes lista_consistente ---\n");
    printf("Lista NULL (esperado 0): %d\n", lista_consistente(NULL));

    Lista *vazia = cria_lista();
    printf("\nLista vazia (esperado 1): %d\n", lista_consistente(vazia));
    libera_lista(vazia);

    struct aluno a4 = {40, "Diego", 8.0f, 7.0f, 9.0f};
    struct aluno a5 = {25, "Elisa", 9.5f, 8.5f, 9.0f};
    struct aluno a6 = {5,  "Fabio", 6.0f, 7.0f, 6.5f};

    insere_lista_final(li, a4);
    insere_lista_ordenada(li, a5);
    insere_lista_inicio(li, a6);
    printf("\nApos inserir mais 3 alunos (esperado 1): %d\n", lista_consistente(li));

    remove_lista_inicio(li);
    remove_lista_final(li);
    remove_lista(li, 25);
    printf("Apos remocoes no inicio, meio e fim (esperado 1): %d\n", lista_consistente(li));

    //questão 3
    printf("\n--- testes questao 3 (remove_lista1) ---\n");
    printf("Remove inexistente 99 (esperado 0): %d\n", remove_lista1(li, 99));
    printf("Remove do meio 20 (esperado 1): %d\n", remove_lista1(li, 20));
    printf("Consistente apos remover meio: %d | tamanho: %d\n", lista_consistente(li), tamanho_lista(li));
    fflush(stdout);

    printf("Tentando remover do inicio (10)...\n");
    fflush(stdout);
    printf("Remove do inicio 10 (esperado 1): %d\n", remove_lista1(li, 10));
    printf("Remove do final 30 (esperado 1): %d\n", remove_lista1(li, 30));
    printf("Tamanho final (esperado 0): %d\n", tamanho_lista(li));

    libera_lista(li);
    return 0;
}
