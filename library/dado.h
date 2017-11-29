#include "lib.h"

typedef struct noDado{
    void* dado;
    int tamDado;
    struct noDado* dir;
    struct noDado* esq;
    struct noDado* cima;
    struct noDado* baixo;
}NoDado;


NoDado* dado_criar(void *dado){

    NoDado* new_noDado = (NoDado*)malloc(NoDado);

    new_noDado->tamDado = 0;
    new_noDado->dado = dado;

    new_noDado->cima = new_noDado;
    new_noDado->baixo = new_noDado;
    new_noDado->dir = new_noDado;
    new_noDado->esq = new_noDado;

    return new_noDado;
}

void dado_deletar(NoDado* dado){

    free(dado);
    dado =  NULL;
}
