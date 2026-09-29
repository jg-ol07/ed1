#include <stdio.h>
#include <stdlib.h>

/* Nesta questão utilizamos a alocação dinâmica para criar um vetor de tamanho definido em tempo de execução:
1. malloc(NumDeNotas * sizeof(float)): requisita ao sistema operacional um bloco contíguo de memória na heap para armazenar 'NumDeNotas' floats.
2. É indispensável verificar 'inicio == NULL', pois caso o sistema não consiga alocar o espaço solicitado, tentar acessar esse ponteiro causaria uma falha de segmentação (Segmentation Fault).
3. Ponteiro auxiliar 'escreve': apontamos 'escreve' para o endereço de 'inicio' para percorrer e preencher a memória.
   No scanf("%f", escreve), passamos 'escreve' diretamente (sem o asterisco '*') porque o scanf exige um endereço de memória para gravar a entrada, e 'escreve' já é esse endereço.
   Ao fazer 'escreve++', avançamos o ponteiro para o próximo float na sequência contígua da memória (avançando sizeof(float) bytes).
4. Manter o ponteiro original 'inicio' intacto é essencial para podermos ler os dados posteriormente ou liberar toda a memória alocada com 'free(inicio)'.
*/

int main(void){
    int NumDeNotas = 0;
    printf("Digite o numero de notas: ");
    scanf("%d", &NumDeNotas);
    float *inicio = (float *)malloc(NumDeNotas * sizeof(float));
    
    if (inicio == NULL){
        printf("Não há memória disponível para a alocação e escrita das notas.\n");
        return -1;
    }

    float *escreve = inicio;

    for(int i = 0; i < NumDeNotas; i++){
        printf("digite a nota a ser inserida na posicao: %d\n", (i+1));
        scanf("%f", escreve);
        escreve++;
        
    }

    for(int i = 0; i < NumDeNotas; i++){
        printf("nota na posicao: %d\n", (i+1));
        printf("%f\n", *inicio);
        inicio++;
        
    }

    return 0;
}
