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
    

    libera_lista(li);
    return 0;
}
