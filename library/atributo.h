#include "lib.h"
#include "dado.h"

#include "lista_dado.h"


typedef struct noAtributo{
    char nome[30];
    char tipo[30];
    NoDado* valores;
    struct noAtributo* dir;
    struct noAtributo* esq;
} NoAtributo;



NoAtributo* lista_atributo_cria(char* nome_atr, char* tipo, char** valores){

    NoAtributo* new_atributo = (NoAtributo*)malloc(sizeof(NoAtributo));

    new_atributo->dir = new_atributo;
    new_atributo->esq = new_atributo;

    strcpy(new_atributo->nome,nome_atr);

    strcpy(new_atributo->tipo,tipo);


    new_atributo->valores = lista_dado_criar(NULL);


}

/* // FUNÇÕES PARA SEREM IMPLEMENETADAS (RASCUNHO!!)

void lista_desaloca(Lista* l);

void lista_insere(Lista* l, T* elemento, int posicao);
void lista_insere_fim(Lista* l, T* elemento);

T* lista_remove1(Lista* l, int posicao);
int lista_remove2(Lista* l, int posicao, T* endereco);
T* lista_remove_elemento(Lista* l, T* elemento, int (*compara)(void*,void*));

T* lista_busca1(Lista* l, int posicao);
int lista_busca2(Lista* l, int posicao, T* endereco);
int lista_contem(Lista* l, T* elemento, int (*compara)(void*,void*));
int lista_posicao(Lista* l, T* elemento, int (*compara)(void*,void*));

int lista_tamanho(Lista* l);
void lista_imprime(Lista* l, void (*imprimeElemento)(void*));
*/
