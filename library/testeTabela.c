#include <stdio.h>
#include "tabela.h"


int main(){

    char nome[3][30] = {{"joao\0"},{"mari\0"},{"jose\0"}};
    char tipo[3][30] = {{"tip1\0"},{"tip2\0"},{"tip3\0"}};
    int tam = 3;




    Tabela* nova = tabela_criar("tabelaCarro\0",tam, nome, tipo);


    tabela_imprimir(nova);
    tabela_destruir(nova);

    return 0;

}
