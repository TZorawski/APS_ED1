#include <stdio.h>
#include "tabela.h"


int main(){

    Tabela* nova = tabela_vazia("novaTabelsssssssa\0");

    printf(" nome: %s \n\n", nova->nome);

    tabela_destruir(nova);

    return 0;

}
