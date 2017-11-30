#include "lib.h"

typedef struct noDado{
    void* dado;
    int tamDado;
    struct noDado* dir;
    struct noDado* esq;
    struct noDado* cima;
    struct noDado* baixo;
}NoDado;

NoDado* dado_novo(char* nome);
void dado_deletar(NoDado* dado);

NoDado* dado_novo(char* nome){
    NoDado* novo = (NoDado*)malloc(sizeof(NoDado));
    novo->tamDado = strlen(nome);
    novo->dado = (void*)nome;
    novo->dir = novo;
    novo->esq = novo;
    novo->cima = novo;
    novo->baixo = novo;
}

void dado_deletar(NoDado* dado){
    free(dado);
    dado =  NULL;
}

