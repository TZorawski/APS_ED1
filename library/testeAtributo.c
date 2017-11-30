#include <stdio.h>
#include "atributo.h"

int main(){


    NoAtributo* a = Atributo("Teste\0", "nulo\0");

    printf("%s\n", a->nome);
    printf("%s\n", a->tipo);
    if(a->valores == NULL)
        printf("valores == null\n");

    atributo_destruir(a);

   /* char nome[][5] = {{"joao\0"},{"mari\0"},{"jose\0"}};

    char tipo[][5] = {{"tip1\0"},{"tip2\0"},{"tip3\0"}};

    int tam = 3;

    NoAtributo* atr = atributo_criar(nome,tipo,tam);
*/
    return 0;
}
