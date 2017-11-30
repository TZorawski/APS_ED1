#include "dado.h"

//typedef struct{
//
//    NoDado* sentilena;
//
//}

tabela->tuplas[Tabela->qtdeTuplas] = tuplas_criar()
Tabela->qtdeTupla++;

NoDado* tuplas_criar(char** dados, int tam_tupla){

    NoDado* new_tupla = dado_criar("sentinela");
    /*replicar o codigo!*/





}

tupla_inserir
/*
NoAtributo* atributo_criar(int tam_vet, char vet_nome[][30],char vet_tipo[][30]){
    NoAtributo* new_atributo = Atributo("Sentinela", "NULL");
//    for(int i =0; i<tam_vet; i++){
//        printf("%s\n%s\n", vet_nome[i], vet_tipo[i]);
//    }

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
    novo->valores = dado_criar("sentinela");
}

*/
