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


Tabela* table_criar(char* nome, char** vet_nome,char** vet_tipo,int tam_vet){

    Tabela* new_table = tabela_vazia(nome);

    new_table->atributos = atributo_criar(ver_nome, vet_tipo, tam_vet);
}



void tabela_destruir(Tabela* tb){/*FALTA COLOCAR OS DADOS DO ATRIBUTO!*/

    free(tb);
    tb = NULL;
}











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
