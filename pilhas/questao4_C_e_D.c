#include <stdio.h>
#include <string.h>

int sequencia_valida(const char *s){
    int i = 0;
    int tamanho = strlen(s);
    int IR = 0;
    for(i = 0; i < tamanho; i++){
        if(s[i] ==  'I'){
            IR++;
        }else if(s[i] == 'R'){
            IR--;
        }
        

        if(IR < 0){
            printf("voce nao pode remover mais do que inseriu");
            return 0;
        }
    }

    return(IR == 0);
}

int main(void){
    char texto[7];
    fgets(texto, 7, stdin);
    texto[strcspn(texto, "\n")] = '\0';
    int resultado = sequencia_valida(texto);
    printf("%d", resultado);
    return 0;
}

// na minha solução eu não usei uma pilha, fiz somente um algoritmo que usa do array pransolução, porém a variavel passada dentro dos paramentros da função
// representa uma sequencia de chamadas em relação a uma pilha, ou seja, por isso que, obrigatoriamente, não podemos ter mais remoções do que inserções, visto
// que isso em uma pilha simplemente não funcionaria, e no final teriamos uma chamada de função (de remoção) que retornaria 0 ou -1, simbolizando que não há
// elementos para retirada.