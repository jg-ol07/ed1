/* Programa de teste simples da ListaDinEncadCirc.
   A lista e preenchida apenas parcialmente: acrescente novos
   alunos/testes conforme for implementando as outras funcoes. */
#include <stdio.h>
#include "ListaDinEncadCirc.h"

int main(void) {
    Lista *li = cria_lista();
    if (li == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }
    struct aluno al;

    printf("vazia=%d cheia=%d tamanho=%d\n",
           lista_vazia(li), lista_cheia(li), tamanho_lista(li));

    /* --- preenchimento parcial ------------------------------ */
    /* struct aluno vem do .h: {matricula, nome, n1, n2, n3} */
    struct aluno a1 = {89, "Ana",   7.0f, 8.0f, 9.0f};
    struct aluno a2 = {75, "Bruno", 6.5f, 7.5f, 8.0f};
    struct aluno a3 = {9500, "Carla", 9.0f, 9.5f, 10.0f};
    struct aluno a4 = {100, "Daniel", 5.0f, 6.0f, 7.0f};
    struct aluno a5 = {200, "Eduardo", 8.0f, 8.5f, 9.0f};
    struct aluno a6 = {300, "Fernanda", 7.5f, 8.0f, 8.5f};
    struct aluno a7 = {400, "Gabriel", 0.0f, 7.0f, 8.0f};

    insere_lista_final(li, a1);
    insere_lista_final(li, a2);
    insere_lista_inicio(li, a3);
    insere_lista_final(li, a4);
    insere_lista_final(li, a5);
    insere_lista_final(li, a6);
    insere_lista_final(li, a7);

    printf("\n--- apos 7 insercoes (tamanho=%d) ---\n", tamanho_lista(li));
    imprime_lista(li);

    /* --- buscas --------------------------------------------- */
    if (busca_lista_pos(li, 2, &al))
        printf("\nbusca_pos(2) -> %d %s\n", al.matricula, al.nome);
    if (busca_lista_mat(li, 75, &al))
        printf("busca_mat(75) -> %s\n", al.nome);
    printf("busca_mat(99) = %d (esperado 0)\n", busca_lista_mat(li, 99, &al));

    /* --- adicione aqui novos testes ------------------------- */ 
    //questão 1
    imprime_lista(li);
    //questão 2
    int mat;
    if (maior_matricula(li, &mat))
        printf("Maior matricula: %d\n", mat);
    //questão 3
    int aprovados = conta_aprovados(li);
    printf("Numero de aprovados: %d\n", aprovados);
    //questão 4
    int k = 500000001;
    if (busca_ciclica(li, k, &al))
        printf("Aluno na posicao ciclica %d: %s\n", k, al.nome);
    else
        printf("Nao foi possivel encontrar o aluno na posicao ciclica %d\n", k);
    //questão 5
    int pos = 3;
    if (remove_lista_pos(li, pos))
        printf("Aluno na posicao %d removido com sucesso.\n", pos);
    else
        printf("Nao foi possivel remover o aluno na posicao %d\n", pos);
    printf("\n--- apos remocao na posicao %d (tamanho=%d) ---\n", pos, tamanho_lista(li));
    imprime_lista(li);
    //questão 6
    int k_rot = 2;
    if (rotaciona_lista(li, k_rot))
        printf("Lista rotacionada em %d posicoes com sucesso.\n", k_rot);
    else
        printf("Nao foi possivel rotacionar a lista em %d posicoes\n", k_rot);
    printf("\n--- apos rotacao em %d posicoes (tamanho=%d) ---\n", k_rot, tamanho_lista(li));
    imprime_lista(li);
    // questão 7
    Lista *li2 = cria_lista();
    if (li2 == NULL) {
        printf("Erro ao criar a segunda lista.\n");
        return 1;
    }
    struct aluno a8 = {500, "Heloisa", 7.0f, 8.0f, 9.0f};
    struct aluno a9 = { 600, "Igor", 6.5f, 7.5f, 8.0f};
    insere_lista_final(li2, a8);
    insere_lista_final(li2, a9);
    printf("\n--- segunda lista (tamanho=%d) ---\n", tamanho_lista(li2));
    imprime_lista(li2);
    if (concatena_listas(li, li2))
        printf("Listas concatenadas com sucesso.\n");
    else
        printf("Nao foi possivel concatenar as listas.\n");
    printf("\n--- apos concatenacao (tamanho=%d) ---\n", tamanho_lista(li));
    imprime_lista(li);
    imprime_lista(li2); // li2 deve estar vazia

    // questão 8
    int sobrevivente;
    if (josephus(li, 3, &sobrevivente))
        printf("Sobrevivente: %d\n", sobrevivente);
        
    libera_lista(li);
    libera_lista(li2);

    
    return 0;
}
