/*
 * data.h - Interface do TAD Data
 *
 * Header guard: impede que o conteúdo deste arquivo seja incluído
 * mais de uma vez durante a compilação (evita erros de redefinição).
 */
#ifndef DATA_H
#define DATA_H

/*
 * Typedef opaco: declara que "Data" é um tipo baseado em "struct data",
 * mas NÃO revela os campos internos (dia, mes, ano).
 * Isso força o usuário do TAD a usar apenas as funções abaixo
 * para manipular a struct — princípio de encapsulamento.
 * A definição completa da struct fica em implement.c.
 */
typedef struct data Data;

/*
 * Cria e retorna um ponteiro para uma nova Data alocada no heap.
 * Valida os valores de dia, mes e ano antes de alocar.
 * Retorna NULL se os valores forem inválidos ou se o malloc falhar.
 */
Data *registrarData(int data, int mes, int ano);

/*
 * Libera a memória alocada para a Data apontada por p.
 */
void liberarMem(Data *p);

/*
 * Imprime a data no formato |dia: X|mes: Y|ano: Z|.
 * Retorna 0 em caso de sucesso, ou -1 se p for NULL.
 */
int lerData(Data *p);

/*
 * Altera o dia da Data apontada por p.
 * Retorna 0 em caso de sucesso, ou -1 se p for NULL.
 */
int mudaDia(int dia, Data *p);

/*
 * Altera o mês da Data apontada por p.
 * Retorna 0 em caso de sucesso, ou -1 se p for NULL.
 */
int mudaMes(int mes, Data *p);

/*
 * Altera o ano da Data apontada por p.
 * Retorna 0 em caso de sucesso, ou -1 se p for NULL.
 */
int mudaAno(int ano, Data *p);

/*
 * Avança a data em 'dias' dias somando diretamente ao campo dia.
 * Retorna 0 em caso de sucesso, ou -1 se p for NULL.
 */
int avancaDias(int dias, Data *p);

/*
 * Compara duas datas, calculando a diferença absoluta
 * entre seus campos (ano, mês, dia).
 * Retorna -1 se algum dos ponteiros for NULL.
 */
int comparandoDatas(Data *a, Data *b);

#endif