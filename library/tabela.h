#include "atributo.h"
#define tam_tupla 4

typedef struct {
    char nome[30];
    NoAtributo* atributos;
    NoDado** tuplas;
    unsigned short int tamTuplas;
    unsigned short int qtdeTuplas;
}Tabela;



Tabela* tabela_vazia(char* nome){

    Tabela* new_table = (Tabela*)malloc(sizeof(Tabela));

    strcpy(new_table->nome,nome);
    new_table->qtdeTuplas = 0;
    new_table->tamTuplas = tam_tupla;
    new_table->tuplas = NULL;
    new_table->atributos = NULL;

    return new_table;



}

Tabela* tabela_criar(char* nome, int tam_vet, char vet_nome[][30], char vet_tipo[][30]){

    Tabela* new_table = tabela_vazia(nome);
    new_table->atributos = atributo_criar(tam_vet, vet_nome, vet_tipo);

}


void tabela_imprimir(Tabela* table){

    printf("\n\n # TABELA:  %s",table->nome);
    atributo_imprimir(table->atributos);

}

void tabela_destruir(Tabela* table){/*FALTA COLOCAR OS DADOS DO ATRIBUTO!*/

    atributo_destruir(table->atributos);
    free(table);
    table = NULL;
}
