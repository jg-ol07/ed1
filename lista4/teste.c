#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_preco.h"

/*ESTE ARQUIVO FOI GERADO POR UMA LLM (CLAUDE SONNET 5.5), ELE FOI UTILIZADO COM O INTUITO DE AUTOMATIZAR OS TESTE REALIZADOS DOS MEUS ALGORITMOS, ENCONTRADOS EM LISTA_PRECO.C
*/
static int total = 0, passou = 0;

static struct produto mk(int codigo, const char *nome, float preco) {
    struct produto p;
    p.codigo = codigo;
    strncpy(p.nome, nome, sizeof(p.nome) - 1);
    p.nome[sizeof(p.nome) - 1] = '\0';
    p.preco = preco;
    return p;
}

static void testa(const char *descricao, int obtido, int esperado) {
    total++;
    if (obtido == esperado) {
        passou++;
        printf("\n[ OK ] %s (retornou %d)\n", descricao, obtido);
    } else {
        printf("\n[FALHOU] %s (esperado %d, obtido %d)\n", descricao, esperado, obtido);
    }
}

static void testaf(const char *descricao, float obtido, float esperado) {
    total++;
    if (obtido > esperado - 0.001f && obtido < esperado + 0.001f) {
        passou++;
        printf("\n[ OK ] %s (%.2f)\n", descricao, obtido);
    } else {
        printf("\n[FALHOU] %s (esperado %.2f, obtido %.2f)\n", descricao, esperado, obtido);
    }
}

static void preenche(Lista *li, int n) {
    for (int i = 0; i < n; i++)
        insere_lista_final(li, mk(100 + i, "Item", 10.0f * (i + 1)));
}

static void secao(const char *titulo) {
    printf("\n--- %s ---\n", titulo);
}

int main(void) {
    struct produto p;
    Lista *li;

    secao("QUESTAO 1: lista_tem_espaco");
    li = cria_lista();
    testa("lista NULL", lista_tem_espaco(NULL, 1), 0);
    testa("n negativo", lista_tem_espaco(li, -1), 0);
    testa("vazia, n = 0", lista_tem_espaco(li, 0), 1);
    testa("vazia, n = MAX (cabe exatamente)", lista_tem_espaco(li, MAX), 1);
    testa("vazia, n = MAX + 1", lista_tem_espaco(li, MAX + 1), 0);
    preenche(li, 3);
    testa("qtd = 3, n = MAX - 3", lista_tem_espaco(li, MAX - 3), 1);
    testa("qtd = 3, n = MAX - 2", lista_tem_espaco(li, MAX - 2), 0);
    preenche(li, MAX - 3);
    testa("cheia, n = 0", lista_tem_espaco(li, 0), 1);
    testa("cheia, n = 1", lista_tem_espaco(li, 1), 0);
    libera_lista(li);

    secao("QUESTAO 2: soma_precos");
    li = cria_lista();
    testaf("lista NULL", soma_precos(NULL), 0.0f);
    testaf("lista vazia", soma_precos(li), 0.0f);
    insere_lista_final(li, mk(1, "A", 10.0f));
    insere_lista_final(li, mk(2, "B", 20.0f));
    insere_lista_final(li, mk(3, "C", 30.0f));
    testaf("10 + 20 + 30", soma_precos(li), 60.0f);
    insere_lista_final(li, mk(4, "D", 0.5f));
    testaf("com preco decimal: 60.5", soma_precos(li), 60.5f);
    libera_lista(li);

    secao("QUESTAO 3: busca_por_nome");
    li = cria_lista();
    insere_lista_final(li, mk(1, "Arroz", 5.0f));
    insere_lista_final(li, mk(2, "Feijao", 8.0f));
    testa("lista NULL", busca_por_nome(NULL, "Arroz", &p), -1);
    testa("lista vazia (outra lista)", busca_por_nome(cria_lista(), "Arroz", &p), 0);
    testa("nome inexistente", busca_por_nome(li, "Leite", &p), 0);
    testa("nome existente", busca_por_nome(li, "Feijao", &p), 1);
    testa("codigo do produto encontrado", p.codigo, 2);
    testaf("preco do produto encontrado", p.preco, 8.0f);
    libera_lista(li);

    secao("QUESTAO 4: insere_lista_decrescente");
    li = cria_lista();
    p = mk(1, "A", 20.0f);
    testa("lista NULL", insere_lista_decrescente(NULL, &p), -1);
    testa("produto NULL", insere_lista_decrescente(li, NULL), -1);
    p = mk(1, "A", 20.0f);
    testa("insere 20", insere_lista_decrescente(li, &p), 0);
    p = mk(2, "B", 50.0f);
    testa("insere 50", insere_lista_decrescente(li, &p), 0);
    p = mk(3, "C", 30.0f);
    testa("insere 30", insere_lista_decrescente(li, &p), 0);
    p = mk(4, "D", 5.0f);
    testa("insere 5", insere_lista_decrescente(li, &p), 0);
    testa("tamanho = 4", tamanho_lista(li), 4);
    busca_lista_pos(li, 1, &p);
    testaf("posicao 1 = 50", p.preco, 50.0f);
    busca_lista_pos(li, 2, &p);
    testaf("posicao 2 = 30", p.preco, 30.0f);
    busca_lista_pos(li, 3, &p);
    testaf("posicao 3 = 20", p.preco, 20.0f);
    busca_lista_pos(li, 4, &p);
    testaf("posicao 4 = 5", p.preco, 5.0f);
    p = mk(5, "E", 1.0f);
    insere_lista_decrescente(li, &p);
    p = mk(6, "F", 0.5f);
    insere_lista_decrescente(li, &p);
    p = mk(7, "G", 0.1f);
    testa("lista cheia", insere_lista_decrescente(li, &p), -2);
    libera_lista(li);

    secao("QUESTAO 5: remove_mais_caro");
    li = cria_lista();
    testa("lista NULL", remove_mais_caro(NULL, &p), -1);
    testa("lista vazia", remove_mais_caro(li, &p), -2);
    insere_lista_final(li, mk(1, "A", 10.0f));
    testa("removido NULL", remove_mais_caro(li, NULL), -3);
    insere_lista_final(li, mk(2, "B", 50.0f));
    insere_lista_final(li, mk(3, "C", 30.0f));
    testa("remove com sucesso", remove_mais_caro(li, &p), 0);
    testaf("preco do removido", p.preco, 50.0f);
    testa("tamanho = 2", tamanho_lista(li), 2);
    testa("removido nao esta mais na lista", busca_por_nome(li, "B", &p), 0);
    libera_lista(li);
    li = cria_lista();
    insere_lista_final(li, mk(1, "A", 10.9f));
    insere_lista_final(li, mk(2, "B", 10.5f));
    remove_mais_caro(li, &p);
    testaf("precos decimais: remove 10.9 e nao 10.5", p.preco, 10.9f);
    libera_lista(li);

    secao("QUESTAO 6: conta_faixa_preco");
    li = cria_lista();
    testa("lista NULL", conta_faixa_preco(NULL, 0, 100), -1);
    testa("lista vazia", conta_faixa_preco(li, 0, 100), 0);
    insere_lista_final(li, mk(1, "A", 10.0f));
    insere_lista_final(li, mk(2, "B", 20.0f));
    insere_lista_final(li, mk(3, "C", 30.0f));
    insere_lista_final(li, mk(4, "D", 40.0f));
    testa("faixa 15-35", conta_faixa_preco(li, 15.0f, 35.0f), 2);
    testa("limites inclusivos 20-30", conta_faixa_preco(li, 20.0f, 30.0f), 2);
    testa("faixa sem produtos 100-200", conta_faixa_preco(li, 100.0f, 200.0f), 0);
    testa("faixa cobrindo tudo", conta_faixa_preco(li, 0.0f, 1000.0f), 4);
    libera_lista(li);

    secao("QUESTAO 7: remove_abaixo_de");
    li = cria_lista();
    testa("lista NULL", remove_abaixo_de(NULL, 10.0f), -1);
    testa("preco minimo negativo", remove_abaixo_de(li, -1.0f), -1);
    testa("lista vazia", remove_abaixo_de(li, 10.0f), 0);
    insere_lista_final(li, mk(1, "A", 5.0f));
    insere_lista_final(li, mk(2, "B", 15.0f));
    insere_lista_final(li, mk(3, "C", 8.0f));
    insere_lista_final(li, mk(4, "D", 25.0f));
    insere_lista_final(li, mk(5, "E", 9.0f));
    testa("remove abaixo de 10", remove_abaixo_de(li, 10.0f), 3);
    testa("tamanho = 2", tamanho_lista(li), 2);
    testa("preco igual ao minimo nao e removido", remove_abaixo_de(li, 15.0f), 0);
    testa("remove tudo", remove_abaixo_de(li, 1000.0f), 2);
    testa("lista ficou vazia", lista_vazia(li), 1);
    libera_lista(li);

    secao("QUESTAO 8: mescla_listas");
    Lista *dest = cria_lista();
    Lista *orig = cria_lista();
    testa("destino NULL", mescla_listas(NULL, orig), -1);
    testa("origem NULL", mescla_listas(dest, NULL), -1);
    testa("origem vazia", mescla_listas(dest, orig), 0);
    insere_lista_final(dest, mk(1, "A", 10.0f));
    insere_lista_final(dest, mk(2, "B", 20.0f));
    insere_lista_final(orig, mk(2, "B", 20.0f));
    insere_lista_final(orig, mk(3, "C", 30.0f));
    insere_lista_final(orig, mk(4, "D", 40.0f));
    testa("insere so os codigos novos", mescla_listas(dest, orig), 2);
    testa("tamanho do destino = 4", tamanho_lista(dest), 4);
    testa("origem nao foi alterada", tamanho_lista(orig), 3);
    testa("mesclar de novo nao insere nada", mescla_listas(dest, orig), 0);
    Lista *quase = cria_lista();
    preenche(quase, MAX - 1);
    Lista *grande = cria_lista();
    insere_lista_final(grande, mk(900, "X", 1.0f));
    insere_lista_final(grande, mk(901, "Y", 2.0f));
    insere_lista_final(grande, mk(902, "Z", 3.0f));
    testa("destino enche no meio: insere so 1", mescla_listas(quase, grande), 1);
    testa("destino ficou cheio", lista_cheia(quase), 1);
    libera_lista(dest);
    libera_lista(orig);
    libera_lista(quase);
    libera_lista(grande);

    printf("\n===== Resultado: %d/%d testes passaram =====\n", passou, total);
    return 0;
}
