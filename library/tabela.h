#include "lib.h"
//#include "banco.h"
#include "dado.h"
#include "atributo.h"


typedef struct {
    char nome[30];
    NoAtributo* atributos;
    NoDado** tuplas;
    unsigned short int tamTuplas;
    unsigned short int qtdeTuplas;
} Tabela;
















/*
NoDado* dado_criar(Tabela* tabela, char** vet_dado, int vet_tam){
    NoDado* new_noDado = dado_novo("sentinela");

    for(int i=0; i < vet_tam; i++){
        new_noDado->dado[i];
    }
    return new_noDado;
}

*/




/// NÃO VAI TER CREATE TABLE PORQUE JA ESTA SENDO CRIADO NO BANCO!
/*Tabela* create_table(char* nome_tb, char** atr){
    if(!db)return NULL;
    if(db->qtdeTabelas >= db->tamTabelas){
        return NULL;
    }

    Tabela* new_table = (Tabela*)malloc(sizeof(Tabela));
    strcpy(new_table->nome,nome_tb);


    new_table->qtdeTuplas = 0;
    new_table->tamTuplas = 4;

    //new_table->atributos = lista_cria();

    //new_table->atributos->dir = new_table->atributos;
}*/
