#include "lib.h"
#include "atributo.h"



typedef struct {
    char nome[30];
    NoAtributo* atributos;
    NoDado** tuplas;
    unsigned short int tamTuplas;
    unsigned short int qtdeTuplas;
} Tabela;



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
