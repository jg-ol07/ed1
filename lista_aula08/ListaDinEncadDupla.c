/* ============================================================
   ListaDinEncadDupla.c
   Estrutura de Dados I - UFPB - Aula 08
   Lista dinamica duplamente encadeada

   Implementacao identica a apresentada nos slides da Aula 08.
   A definicao de struct elemento esta aqui, e nao no .h: e isso
   que torna Lista um tipo opaco. Quem usa a biblioteca enxerga
   apenas Lista* e os prototipos declarados no cabecalho.

   Qualquer funcao nova que precise percorrer a lista no a no
   tem de ser escrita NESTE arquivo, porque e aqui que os campos
   ant, dados e prox sao visiveis.
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h"

/* Definicao do tipo lista: oculta de quem usa a biblioteca.
   Com struct aluno de 48 bytes, sizeof(Elem) = 64 bytes em uma
   plataforma de 64 bits, contra 56 na lista encadeada simples. */
struct elemento {
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

/* --- criacao e destruicao ---------------------------------- */

Lista* cria_lista(void) {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li) {
    if (li != NULL) {
        Elem* no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;   /* avanca antes de liberar */
            free(no);
        }
        free(li);                /* libera o bloco do inicio */
    }
}

/* --- informacoes de estado --------------------------------- */

int tamanho_lista(Lista* li) {
    if (li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li) {
    (void) li;               /* parametro mantido por simetria com as demais */
    return 0;
}

int lista_vazia(Lista* li) {
    if (li == NULL)
        return 1;            /* lista invalida */
    if (*li == NULL)
        return 1;            /* nenhum elemento alocado */
    return 0;
}

/* --- insercao ---------------------------------------------- */

int insere_lista_inicio(Lista* li, struct aluno al) {
    if (li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;    /* sem memoria: a lista esta cheia */
    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;
    if (*li != NULL)             /* lista nao vazia */
        (*li)->ant = no;         /* o antigo primeiro ganha antecessor */
    *li = no;
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al) {
    if (li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;
    if ((*li) == NULL) {         /* lista vazia: insere inicio */
        no->ant = NULL;
        *li = no;
    } else {
        Elem* aux = *li;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al) {
    if (li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = al;
    if ((*li) == NULL) {         /* lista vazia: insere inicio */
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }
    else {
        /* O livro declara ante sem valor inicial. A inicializacao com
           NULL nao altera o comportamento e elimina o aviso
           "may be used uninitialized" do gcc com -O2. */
        Elem *ante = NULL, *atual = *li;
        while (atual != NULL &&
               atual->dados.matricula < al.matricula) {
            ante = atual;
            atual = atual->prox;
        }
        if (atual == *li) {      /* insere inicio */
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        } else {                 /* insere no meio ou no final */
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if (atual != NULL)   /* nao e o ultimo */
                atual->ant = no;
        }
        return 1;
    }
}

/* --- remocao ----------------------------------------------- */

int remove_lista_inicio(Lista* li) {
    if (li == NULL) return 0;
    if ((*li) == NULL) return 0;   /* lista vazia */
    Elem* no = *li;
    *li = no->prox;
    if (no->prox != NULL)          /* existe um seguinte */
        no->prox->ant = NULL;      /* ele passa a ser o primeiro */
    free(no);
    return 1;
}

int remove_lista_final(Lista* li) {
    if (li == NULL) return 0;
    if ((*li) == NULL) return 0;   /* lista vazia */
    Elem* no = *li;
    while (no->prox != NULL)
        no = no->prox;
    if (no->ant == NULL)           /* primeiro e unico */
        *li = no->prox;
    else
        no->ant->prox = NULL;      /* penultimo obtido pelo proprio no */
    free(no);
    return 1;
}

int remove_lista(Lista* li, int mat) {
    if (li == NULL) return 0;
    if ((*li) == NULL) return 0;   /* lista vazia */
    Elem* no = *li;
    while (no != NULL && no->dados.matricula != mat)
        no = no->prox;
    if (no == NULL)                /* chave ausente */
        return 0;
    if (no->ant == NULL)           /* remove o primeiro */
        *li = no->prox;
    else
        no->ant->prox = no->prox;
    if (no->prox != NULL)          /* nao e o ultimo */
        no->prox->ant = no->ant;
    free(no);
    return 1;
}

/* --- busca ------------------------------------------------- */

int busca_lista_pos(Lista* li, int pos, struct aluno *al) {
    if (li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while (no != NULL && i < pos) {
        no = no->prox;
        i++;
    }
    if (no == NULL)
        return 0;
    else {
        *al = no->dados;
        return 1;
    }
}

int busca_lista_mat(Lista* li, int mat, struct aluno *al) {
    if (li == NULL)
        return 0;
    Elem *no = *li;
    while (no != NULL && no->dados.matricula != mat)
        no = no->prox;
    if (no == NULL)
        return 0;
    else {
        *al = no->dados;
        return 1;
    }
}

//questão 1.
void imprime_lista_inversa(Lista* li){
    if (li == NULL || (*li) == NULL){
        printf("houve um erro ao tentar imprimir a lista");
        return;
    }
    Elem *no = *li;
    while (no->prox != NULL){
        no = no->prox;
    }
    do{
        printf("Matricula: %d\n", no->dados.matricula);
        no = no->ant;
        if(no->ant == NULL){
            printf("Matricula: %d\n", no->dados.matricula);
        }
    } while (no->ant != NULL);
}

//questão 2.
int lista_consistente(Lista* li){
    if(li == NULL){
        return 0;
    }
    if((*li) == NULL){
        printf("sua lista está vazia, mas por isso, ela é consistente.");
        return 1;
    }
    
    int flag = 0;
    Elem *no = *li;
    
    if(no->ant == NULL){
        flag++;
    }
    while(no->prox != NULL){
        if(no->prox->ant != no){
            printf("sua lista não é consistente.");
            return 0;
        }else{
            no = no->prox;
        }
        
    }
    
    flag++;
    
    if(flag > 1){
        return 1;
    }else{
        return 0;
    }

}

//questão 3.
int remove_lista1(Lista* li, int mat){
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;

    Elem* no = *li;

    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }

    if(no->ant == NULL){
        *li = no->prox;
    }else{
        no->ant->prox = no->prox;
    }
    if(no->prox != NULL){
        no->prox->ant = no->ant;
    }
    free(no);

    return 1;
}

//questão 4.
int remove_lista_pos(Lista* li, int pos){
    if(li == NULL || pos <= 0 || (*li) == NULL || pos > tamanho_lista(li)){
        return 0;
    }
    int i = 1;
    Elem* no = *li;
    while(i < pos){
        no = no->prox;
        i++;
    }
    remove_lista(li, no->dados.matricula);
    return 1;
}

//questão 5.
int move_para_inicio(Lista* li, int mat){
    if(li == NULL || (*li) == NULL){
        return 0;
    } 
    Elem* primeiro = *li;
    Elem* no = *li;

    while(no != NULL && no->dados.matricula != mat){
        no =  no->prox;
    }
    
    if(no == NULL){
        printf("a matricula nao foi encontrada.");
        return 0;
    }else if(no->ant == NULL){
        printf("a matricula ja esta no inicio da lista.");
        return 1;
    }


    //religando ponteiros da posição:
    no->ant->prox = no->prox;
    if(no->prox != NULL){
        no->prox->ant = no->ant; 
    }
    

    //como vamos pra primeira posição, precisamos zerar o valor de ant
    no->ant = NULL;
    no->prox = *li;
    primeiro->ant = no;
    *li = no;

    return 1;

}

//questão 6.
int remove_todos(Lista* li, int mat){
    if(li == NULL || (*li) == NULL){
        return 0;
    }

    int removidos = 0;
    Elem* aux = *li;
    Elem* no = *li;
    while(no != NULL){
        if(no->dados.matricula == mat){
            if(no->ant != NULL){
                no->ant->prox = no->prox;
            }else{
                *li = no->prox;
            }
            if(no->prox != NULL){
                no->prox->ant = no->ant;
            }
            aux = no;
            no = no->prox;
            free(aux);
            removidos++;
            
        }else{
            no = no->prox;
        }
        
    }
    return removidos;

}

//questão 7.
void inverte_lista(Lista* li){
    if(li == NULL || (*li) == NULL){
        printf("lista invalida\n");
        return;
    }

    Elem* aux = NULL;
    Elem* no = *li;

    while(no != NULL){
        aux = no->ant;
        no->ant = no->prox;
        no->prox = aux;

        if(no->ant == NULL){
            *li = no;
        }
        no = no->ant;
    }

    int resultado = lista_consistente(li);
    if(resultado){
        printf("operacao concluida com sucesso\n");
        return;
    }else{
        printf("houve algo errado com a operação\n");
        return;
    }
}

//questão 8.


