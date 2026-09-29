#include <stdio.h>
#include <stdlib.h>

/* Nesta questão implementamos um vetor dinâmico com redimensionamento automático (estilo ArrayList / std::vector):
1. Em C, a memória alocada por malloc não tem mecanismos automáticos de verificação de limites nem autoredimensionamento.
   Por isso, precisamos monitorar manualmente a 'capacidade' (quantidade máxima suportada atualmente) e o 'contador' (elementos já inseridos).
2. Quando 'capacidade == contador', atingimos o limite da memória alocada.
   Para expandir, dobramos a capacidade (estratégia clássica para garantir complexidade de inserção amortizada O(1)) e chamamos realloc().
3. O realloc tenta expandir o bloco contíguo existente. Se não houver espaço adjacente livre na heap, ele aloca um novo bloco maior em outra região, copia automaticamente os dados antigos para lá e libera o bloco anterior, retornando o novo endereço base.
4. Usamos o valor sentinela '-1' para sinalizar o fim da entrada, interrompendo o laço antes de gravar esse número no vetor ou contabilizá-lo na soma total.
5. A cada inserção, usamos a desreferenciação (*atual = entrada) e a aritmética de ponteiros (atual++) para navegar pelos endereços contíguos de memória.
*/

int main(void){
    int contador = 0;
    int capacidade = 2;
    int entrada = 0;
    int realocacao = 0;
    int somatotal = 0;
    int *vetor = (int *)malloc(capacidade * sizeof(int));
    int *atual = vetor;
    if (vetor == NULL){
        printf("Não há memória disponível para a alocação e escrita do vetor.\n");
        return -1;
    }
    
    while(1){
        printf("digite um numero para registro ou -1 para finalizar a escrita\n");
        scanf("%d", &entrada);
        if(entrada == -1){
            break;
        }
        if (capacidade == contador){
            capacidade *= 2;
            atual = vetor = (int *)realloc(vetor, capacidade *sizeof(int));
            realocacao++;
            atual += contador;
            *atual = entrada;
            contador++;
            atual++;
            somatotal += entrada;
        }else{
            *atual = entrada;
            atual++;
            contador++;
            somatotal += entrada;
        }
    }
    
    
    printf("tam: %d\ncap: %d\nrealocacoes: %d\nsoma: %d", contador, capacidade, realocacao, somatotal);

    return 0;
}