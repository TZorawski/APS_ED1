#include "lib.h"


#define TAMDB 4

typedef struct {
    char nome[30];
    Tabela** tabelas;
    unsigned short int tamTabelas;
    unsigned short int qtdeTabelas;
} Database;


void create_db(char* nome){
    Database* db = (Database*) malloc(sizeof(Database));

    strcpy(db->nome,nome);

    db->tabelas = (Tabela**)calloc(TAMDB,sizeof(Tabela*));// ok
    db->tamTabelas= TAMDB;
    db->qtdeTabelas= 0;
}

void insert_dado(Tabela* t, NoAtributo* atr){

}









