#include <stdio.h>
#include <stdlib.h>

#include "lista_sentinela"

#define TAMDB 4
#define TAMTB 4

typedef struct noDado{
    void* dado;
    int tamDado;
    struct noDado* dir;
    struct noDado* esq;
    struct noDado* cima;
    struct noDado* baixo;
} NoDado;

typedef struct noAtributo{
    char nome[30];
    char tipo[30];
    NoDado* valores;
    struct noAtributo* dir;
    struct noAtributo* esq;
} NoAtributo;

typedef struct {
    char nome[30];
    NoAtributo* atributos;
    NoDado** tuplas;
    unsigned short int tamTuplas;
    unsigned short int qtdeTuplas;
} Tabela;


typedef struct {
    char nome[30];
    Tabela** tabelas;
    unsigned short int tamTabelas;
    unsigned short int qtdeTabelas;
} Database;

void create_db(char* nome);

void create_db(char* nome){
    Database* db= (Database*) malloc(sizeof(Database));
    db->tabelas= (Tabela**) malloc(sizeof(Tabela*)*TAMDB);
    db->tamTabelas= TAMDB;
    db->qtdeTabelas= 0;
}

void insert_dado(Tabela* t, NoAtributo* atr){

}

Tabela* create_table(char* nome_bd, char* nome_tb, char** atr){

    int tam = strlen(nome_tb);


}







