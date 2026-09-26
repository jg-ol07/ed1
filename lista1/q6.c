#include <stdio.h>

int meuStrlen(const char *s){
    int contador = 0;
    for(int i = 0; i >= 0; i++){
        if (s[i] != '\0'){
            contador++;
        }else{
            break;
        }   
    }
    return contador;
}

void meuStrcpy(char *destino, const char *origem){
    int i = 0;
    while(1){
        if(origem[i] == '\0'){
            destino[i] = origem[i];
            break;
        }
        destino[i] = origem[i];
        i++;
    }
}

int main(void){
    char *origem = "Estrutura de Dados!";
    int tamanho = sizeof(origem)/sizeof(char);
    char destino[tamanho];
    int len = 0;

    len = meuStrlen(origem);

    printf("o tamanho eh %d\n", len);

    meuStrcpy(destino, origem);

    printf("%s", destino);

}