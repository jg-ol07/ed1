#include <stdio.h>

/* para que a função dobrar funcione corretamente (ou como esperado) é necessário que façamos um acesso direto a memória (ou o valor guardado dentro da varíavel n)]
ou seja, dentro da função dobrar é neccessário que na verdade, seja passado como seu paramentro, um ponteiro, cujo o qual (pela natureza da linguagem), criamos uma cópia
e, a partir disso, sejamos capazes de acessar a região da memória onde o valor de n está guardado
após realizar esse acesso, nós aletarmos o valor por meio de acesso direto, dobrando o valor.
*/ 

void dobrar(int* num){
    *num *= 2;
}

int main(void){
    int n = 21;
    int* p = &n;
    dobrar(p);
    printf("%d\n", n);
    return 0;
}