#include "lib.h"

typedef struct noDado{
    char* dado;/*trabalhar com void e depois fazer um cast ao acessar o dado ou na hora de guardar o dado*/
    int tamDado;
    struct noDado* dir;
    struct noDado* esq;
    struct noDado* cima;
    struct noDado* baixo;
}NoDado;

NoDado* dado_criar(char* elemento);
void dado_deletar(NoDado* dado);


NoDado* dado_criar(char* elemento){

    int tam = strlen(elemento)+1;

    NoDado* new_dado = (NoDado*)calloc(tam,sizeof(NoDado));
    new_dado->tamDado = tam;
    new_dado->dado = elemento;
    new_dado->dir = new_dado;
    new_dado->esq = new_dado;
    new_dado->cima = new_dado;
    new_dado->baixo = new_dado;

    return new_dado;
}

void dado_deletar(NoDado* dado){
    free(dado);
    dado =  NULL;
}


