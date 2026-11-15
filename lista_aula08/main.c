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

    //questão 4
    printf("\n--- testes questao 4 (remove_lista_pos) ---\n");
    printf("Lista NULL (esperado 0): %d\n", remove_lista_pos(NULL, 1));
    printf("Lista vazia (esperado 0): %d\n", remove_lista_pos(li, 1));

    insere_lista_final(li, a3); // pos 1: 10 Carla
    insere_lista_final(li, a1); // pos 2: 20 Ana
    insere_lista_final(li, a2); // pos 3: 30 Bruno
    insere_lista_final(li, a4); // pos 4: 40 Diego

    printf("Posicao 0 invalida (esperado 0): %d\n", remove_lista_pos(li, 0));
    printf("Posicao negativa -1 (esperado 0): %d\n", remove_lista_pos(li, -1));
    printf("Posicao maior que tamanho 10 (esperado 0): %d\n", remove_lista_pos(li, 10));

    printf("Remove pos 2 - meio (esperado 1): %d\n", remove_lista_pos(li, 2));
    printf("Remove pos 1 - inicio (esperado 1): %d\n", remove_lista_pos(li, 1));
    printf("Remove pos 2 - final (esperado 1): %d\n", remove_lista_pos(li, 2));
    printf("Consistente: %d | Tamanho restante (esperado 1): %d\n", lista_consistente(li), tamanho_lista(li));
    if (busca_lista_pos(li, 1, &al))
        printf("Elemento que sobrou (esperado 30 Bruno): %d %s\n", al.matricula, al.nome);

    //questão 5
    printf("\n--- testes questao 5 (move_para_inicio) ---\n");
    printf("Lista NULL (esperado 0): %d\n", move_para_inicio(NULL, 10));

    Lista *vazia2 = cria_lista();
    printf("Lista vazia (esperado 0): %d\n", move_para_inicio(vazia2, 10));
    libera_lista(vazia2);

    // Lista atual tem [30]. Vamos adicionar 10, 20, 40 -> [30, 10, 20, 40]
    insere_lista_final(li, a3); // 10 Carla
    insere_lista_final(li, a1); // 20 Ana
    insere_lista_final(li, a4); // 40 Diego

    printf("\nMove quem ja esta no inicio 30 (esperado 1): %d\n", move_para_inicio(li, 30));

    printf("Move do meio 20 para o inicio (esperado 1): %d\n", move_para_inicio(li, 20));
    if (busca_lista_pos(li, 1, &al))
        printf("Novo primeiro (esperado 20 Ana): %d %s | Consistente: %d\n", al.matricula, al.nome, lista_consistente(li));

    printf("Move do final 40 para o inicio (esperado 1): %d\n", move_para_inicio(li, 40));
    if (busca_lista_pos(li, 1, &al))
        printf("Novo primeiro (esperado 40 Diego): %d %s | Consistente: %d\n", al.matricula, al.nome, lista_consistente(li));

    printf("Tentando mover inexistente 99 (esperado 0)...\n");
    fflush(stdout);
    printf("Move inexistente 99 (esperado 0): %d\n", move_para_inicio(li, 99));

    //questão 6
    printf("\n--- testes questao 6 (remove_todos) ---\n");
    printf("Lista NULL (esperado 0): %d\n", remove_todos(NULL, 10));

    Lista *vazia3 = cria_lista();
    printf("Lista vazia (esperado 0): %d\n", remove_todos(vazia3, 10));
    libera_lista(vazia3);

    // Lista atual tem [40, 20, 30, 10]. Vamos inserir repetidos de 10 no inicio, meio e fim:
    insere_lista_inicio(li, a3); // 10 no inicio
    insere_lista_inicio(li, a3); // outro 10 seguido no inicio
    insere_lista_final(li, a3);  // mais um 10 no final (total de quatro '10')
    printf("Tamanho antes de remover 10 (esperado 7): %d\n", tamanho_lista(li));

    printf("Remove inexistente 99 (esperado 0): %d\n", remove_todos(li, 99));
    printf("Remove todos os 10 (esperado 4): %d\n", remove_todos(li, 10));
    printf("Tamanho apos remover 10 (esperado 3): %d | Consistente: %d\n", tamanho_lista(li), lista_consistente(li));
    printf("Busca 10 apos remocao (esperado 0): %d\n", busca_lista_mat(li, 10, &al));

    //questão 7
    printf("\n--- testes questao 7 (inverte_lista) ---\n");
    printf("Testando com NULL:\n");
    inverte_lista(NULL);

    Lista *vazia4 = cria_lista();
    printf("\nTestando com lista vazia:\n");
    inverte_lista(vazia4);
    libera_lista(vazia4);

    printf("\nAntes de inverter (tamanho=%d):\n", tamanho_lista(li));
    for (i = 1; i <= tamanho_lista(li); i++) {
        if (busca_lista_pos(li, i, &al))
            printf("pos %d: %d %s\n", i, al.matricula, al.nome);
    }

    inverte_lista(li);

    printf("\nDepois de inverter (tamanho=%d | Consistente=%d):\n", tamanho_lista(li), lista_consistente(li));
    for (i = 1; i <= tamanho_lista(li); i++) {
        if (busca_lista_pos(li, i, &al))
            printf("pos %d: %d %s\n", i, al.matricula, al.nome);
    }

    libera_lista(li);
    return 0;
}
