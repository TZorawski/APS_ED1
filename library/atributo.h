#include "lib.h"
//#include "tabela.h"
#include "dado.h"


typedef struct noAtributo{
    char nome[30];
    char tipo[30];
    NoDado* valores;
    struct noAtributo* dir;
    struct noAtributo* esq;
} NoAtributo;

NoAtributo* Atributo(char* nome, char* tipo){
    NoAtributo* new_atributo = (NoAtributo*)malloc(sizeof(NoAtributo));

    new_atributo->dir = new_atributo;
    new_atributo->esq = new_atributo;
    new_atributo->valores = NULL;
    strcpy(new_atributo->nome,nome);
    strcpy(new_atributo->tipo,tipo);

    return new_atributo;
}


/*
NoAtributo* atributo_criar(char** vet_nome,char** vet_tipo,int tam_vet){

    NoAtributo* new_atributo = Atributo("Sentinela", "NULL");
    for(int i =0; i< tam_vet; i++){
        atributo_inserir(new_atributo,vet_nome[i],vet_tipo[i]);
    }

    new_atributo->valores = NULL;

   return new_atributo; // retornando o atributo para a tabela
}


void atributo_inserir(NoAtributo* sent_atr, char* nome, char* tipo){

    NoAtributo* novo = Atributo(nome, tipo);

    novo->esq = sent_atr->esq;
    novo->dir = sent_atr;
    sent_atr->esq->dir = novo;
    sent_atr->esq = novo;

    novo->valores = dado_criar("sentinela",NULL,0);

}
*/
void atributo_destruir(NoAtributo* sent_atr){

    NoAtributo* aux = sent_atr->dir;

    while(aux != sent_atr){
        aux = aux->dir;
        dado_deletar(aux->esq->valores);
        free(aux->esq);
    }
    free(sent_atr);
    sent_atr = NULL;
}
