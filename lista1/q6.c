#include <stdio.h>

/* Em C, cadeias de caracteres (strings) não são tipos primitivos, mas sim sequências contíguas de bytes na memória terminadas pelo caractere nulo ('\0').
Ao recebermos um ponteiro para char (const char *s), estamos recebendo o endereço inicial dessa sequência na memória.
- O uso do modificador 'const' garante que a função apenas fará a leitura da memória apontada, impedindo mutações acidentais na string de origem.
- Na função meuStrlen, percorremos os endereços sequenciais lendo s[i] (que equivale a *(s + i)) até encontrar o terminador '\0', contando quantos caracteres válidos existem.
- Na função meuStrcpy, recebemos o ponteiro do buffer de destino (char *destino) e copiamos caractere por caractere a partir do endereço de origem até transferir inclusive o '\0', delimitando o fim da nova string na memória.
*/

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