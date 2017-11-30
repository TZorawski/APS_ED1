#include "lib.h"

typedef struct noDado{
    char* dado;
    int tamDado;
    struct noDado* dir;
    struct noDado* esq;
    struct noDado* cima;
    struct noDado* baixo;
}NoDado;

NoDado* dado_criar(char* elemento);
void dado_deletar(NoDado* dado);


NoDado* dado_criar(char* elemento){
    NoDado* new_dado = (NoDado*)malloc(sizeof(NoDado));
    new_dado->tamDado = strlen(elemento);
    new_dado->dado = elemento;
    new_dado->dir = new_dado;
    new_dado->esq = new_dado;
    new_dado->cima = new_dado;
    new_dado->baixo = new_dado;
}

void dado_deletar(NoDado* dado){
    free(dado);
    dado =  NULL;
}

