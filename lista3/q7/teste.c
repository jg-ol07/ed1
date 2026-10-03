#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main(void){
    int dia = 0;
    int mes = 0;
    int ano = 0;
    int avanco = 0;

    printf("por favor, digite a data que voce gostaria de registrar\nordem: |dia|mes|ano|avanco|\n");
    scanf("%d %d %d %d", &dia, &mes, &ano, &avanco);

    Data *p = registrarData(dia, mes, ano);
    lerData(p);

    avancaDias(avanco, p);
    lerData(p);

    printf("por favor, digite a data que voce gostaria de registrar\nordem: |dia|mes|ano|avanco|\n");
    scanf("%d %d %d %d", &dia, &mes, &ano, &avanco);

    Data *a = registrarData(dia, mes, ano);
    lerData(a);

    avancaDias(avanco, a);
    lerData(a);

    return 0;

}
