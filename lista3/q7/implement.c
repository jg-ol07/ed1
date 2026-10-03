/*
 * implement.c - Implementação do TAD Data
 *
 * Contém a definição completa da struct e a implementação
 * de todas as funções declaradas em data.h.
 */
#include <stdio.h>
#include <stdlib.h>
#include "data.h"

/*
 * Definição completa da struct data.
 * Só é visível neste arquivo (.c), garantindo encapsulamento —
 * quem inclui data.h só enxerga o typedef opaco.
 */
typedef struct data{
    int dia;
    int mes;
    int ano;
}Data;

/*
 * registrarData - Cria uma nova Data no heap.
 *
 * Fluxo:
 *   1. Valida dia (1-31), mes (1-12) e ano (>= 0)
 *   2. Verifica caso especial de fevereiro (max 29 dias)
 *   3. Aloca memória com malloc
 *   4. Atribui os valores aos campos da struct
 *   5. Retorna o ponteiro para a Data criada
 *
 * Retorna NULL se alguma validação falhar ou se o malloc falhar.
 */
Data *registrarData(int dia, int mes, int ano){

    // Validação: dia deve estar entre 1 e 31
    if(dia > 31 || dia < 1){
        printf("a sua operacao infelizmente contem uma quantidade de dias invalido, por favor, insira dentro do range : (1-31)");
        return NULL;
    }
    // Validação: mês deve estar entre 1 e 12
    if(mes > 12 || mes < 0){
        printf("a sua operacao infelizmente contem um numero de mes invalido, por favor, insira dentro do range : (1-12)");
        return NULL; 
    }
    // Validação: ano não pode ser negativo
    if(ano < 0){
        printf("a sua operacao infelizmente contem um numero de ano invalido, por favor, insira dentro do range : (0-inf)");
        return NULL; 
    }
    // Validação: fevereiro tem no máximo 29 dias
    if(mes == 2 && dia > 29){
        printf("o mes inserido nao tem essa quantidade de dias");
        return  NULL;
    }

    // Aloca memória no heap para uma struct Data
    Data *p = malloc(sizeof(Data));
    
    // Verifica se a alocação foi bem-sucedida
    if (p == NULL){
        printf("nao ha espaço disponivel na memoria. (NULl pointer exception)");
        return NULL;
    }

    // Atribui os valores recebidos aos campos da struct
    p->dia = dia;
    p->mes = mes;
    p->ano = ano;

    return p;

}

/*
 * liberarMem - Libera a memória de uma Data.
 *
 * Chama free() para devolver a memória ao sistema.
 *
 */
void liberarMem(Data *p){
    free(p);
}

/*
 * lerData - Exibe os campos da Data no terminal.
 *
 * Verifica se o ponteiro é válido antes de acessar os campos.
 * Retorna 0 se imprimiu com sucesso, -1 se p era NULL.
 */
int lerData(Data *p){
    if (p == NULL){
        printf("o registro inserido eh invalido (NULL pointer exception)");
        return -1;
    }
    printf("|dia: %d|mes: %d|ano: %d|\n", p->dia, p->mes, p->ano);
    return 0;
}

/*
 * mudaDia - Altera o dia da Data apontada por p.
 *
 * Retorna 0 em caso de sucesso, -1 se p for NULL.
 */
int mudaDia(int dia, Data *p){
    if(p == NULL){
        printf("o registro inserido eh invalido (NULL pointer exception)");
        return -1;
    }
    p->dia = dia;
    return 0;
}

/*
 * mudaMes - Altera o mês da Data apontada por p.
 *
 * Retorna 0 em caso de sucesso, -1 se p for NULL.
 */
int mudaMes(int mes, Data *p){
    if(p == NULL){
        printf("o registro inserido eh invalido (NULL pointer exception)");
        return -1;
    }
    p->mes = mes;
    return 0;
}

/*
 * mudaAno - Altera o ano da Data apontada por p.
 *
 * Retorna 0 em caso de sucesso, -1 se p for NULL.
 */
int mudaAno(int ano, Data *p){
    if(p == NULL){
        printf("o registro inserido eh invalido (NULL pointer exception)");
        return -1;
    }
    p->ano = ano;
    return 0;
}

/*
 * avancaDias - Soma 'dias' ao campo dia da Data.
 *
 * Verifica se o resultado ultrapassaria 31 dias antes de aplicar.
 * Retorna 0 em caso de sucesso, -1 se p for NULL ou se estourar o mês.
 */
int avancaDias(int dias, Data *p){
    if(p == NULL){
        printf("o registro inserido eh invalido (NULL pointer exception)");
        return -1;
    }
    if((p->dia + dias) > 31){
        printf("o avanço passou o numero de dias limite de um mês.");
        return -1;
    }
    p->dia += dias;

    return 0;
}

/*
 * comparandoDatas - Calcula e exibe a diferença absoluta entre duas datas.
 *
 * Calcula |a.ano - b.ano|, |a.dia - b.dia| e |a.mes - b.mes|
 * separadamente e imprime o resultado no terminal.
 *
 * Retorna 0 em caso de sucesso, -1 se algum ponteiro for NULL.
 */
int comparandoDatas(Data *a, Data *b){
    if(a == NULL || b == NULL){
        printf("um dos registros inserido eh invalido (NULL pointer exception)");
        return -1;
    }

    // Calcula diferença absoluta de anos
    int dif_anos = a->ano - b->ano;
    if(dif_anos < 0){
        dif_anos = -dif_anos;
    }
    // Calcula diferença absoluta de dias
    int dif_dias = a->dia - b->dia;
    if(dif_dias < 0){
        dif_dias = -dif_dias;
    }
    // Calcula diferença absoluta de meses
    int dif_meses = a->mes - b->mes;
    if(dif_meses < 0){
        dif_meses = -dif_meses;
    }

    printf("diferenca de:\n|dias: %d\n|mes: %d\n|ano: %d\n", dif_dias, dif_meses, dif_anos);
    return 0;

}
