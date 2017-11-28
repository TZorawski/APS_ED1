#include <stdlib.h>
#include <string.h>

typedef float T;

typedef struct no{
    T* dado;
    struct no* prox;
    struct no* ant;
}No;

typedef struct{
    No* sentinela;
    int qtde;
}Lista;


Lista* lista_cria();
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

//helpers
void aumenta(Lista* l);
T* copiar(T* elemento);
No* encontra_end(Lista* l, int posicao);
void insere_antes(No* end, No* novo);
void remover(Lista* l, No* end, int posicao);

Lista* lista_cria(){
    Lista* l= (Lista*) malloc(sizeof(Lista));
    No* no= (No*) malloc(sizeof(No));
    no->dado= NULL;
    no->prox= no;
    no->ant= no;
    l->sentinela= no;
    l->qtde= 0;
    return l;
}

void lista_desaloca(Lista* l){
    No* no= l->sentinela->prox;
    for (int i= 0; i<l->qtde; i++) {
        no= no->prox;
        free(no->ant);
    }
    free(l->sentinela);
    free(l);
}

void lista_insere(Lista* l, T* elemento, int posicao){
    No* novo= (No*) malloc(sizeof(No));
    novo->dado= copiar(elemento);

    if (posicao>=0 && posicao<=l->qtde) {
        No* p= encontra_end(l, posicao);
        insere_antes(p, novo);
        l->qtde++;
    }
}

void lista_insere_fim(Lista* l, T* elemento){
    No* novo= (No*) malloc(sizeof(No));
    novo->dado= copiar(elemento);
    insere_antes(l->sentinela, novo);
    l->qtde++;
}

T* lista_remove1(Lista* l, int posicao){
    if (posicao>=0 && posicao<l->qtde) {
        No* end= encontra_end(l, posicao);
        T* elemento= copiar(end->dado);

        remover(l, end, posicao);

        return elemento;
    }
    return NULL;
}

int lista_remove2(Lista* l, int posicao, T* endereco){
    if (posicao>=0 && posicao<l->qtde) {
        No* end= encontra_end(l, posicao);
        memcpy(endereco, end->dado, sizeof(T));

        remover(l, end, posicao);

        return 1;
    }
    return 0;
}

T* lista_remove_elemento(Lista* l, T* elemento, int (*compara)(void*,void*)){
    int posicao= lista_posicao(l, elemento, compara);
    if (posicao!=-1) {
        T* e= lista_remove1(l, posicao);
        return e;
    }
    return NULL;
}

T* lista_busca1(Lista* l, int posicao){
    if (posicao>=0 && posicao<l->qtde) {
        No* no= encontra_end(l, posicao);
        T* e= copiar(no->dado);
        return e;
    }
    return NULL;
}

int lista_busca2(Lista* l, int posicao, T* endereco){
    if (posicao>=0 && posicao<l->qtde) {
        No* no= encontra_end(l, posicao);
        memcpy(endereco, no->dado, sizeof(T));
        return 1;
    }
    return 0;
}

int lista_contem(Lista* l, T* elemento, int (*compara)(void*,void*)){
    No* no= l->sentinela->prox;
    for (int i= 0; i<l->qtde; i++) {
        if (compara(elemento, no->dado)==1) {
            return 1;
        }
        no= no->prox;
    }
    return 0;
}

int lista_posicao(Lista* l, T* elemento, int (*compara)(void*,void*)){
    No* end= l->sentinela->prox;
    for (int i= 0; i<l->qtde; i++) {
        if (compara(elemento, end->dado)==1) {
            return i;
        }
        end= end->prox;
    }
    return -1;
}

int lista_tamanho(Lista* l){
    return l->qtde;
}

void lista_imprime(Lista* l, void (*imprimeElemento)(void*)){
    No* no= l->sentinela->prox;
    for (int i= 0; i<l->qtde; i++) {
        imprimeElemento(no);
        no= no->prox;
    }
}

//helpers
T* copiar(T* elemento){
    T* copia= (T*) malloc(sizeof(T));
    memcpy(copia, elemento, sizeof(T));
    return copia;
}

No* encontra_end(Lista* l, int posicao){
    No* end= l->sentinela->prox;
    for (int i= 0; i<posicao; i++) {
        end= end->prox;
    }
    return end;
}

void insere_antes(No* end, No* novo){
    novo->prox= end;
    novo->ant= end->ant;
    end->ant->prox= novo;
    end->ant= novo;
}

void remover(Lista* l, No* end, int posicao){
    end->ant->prox= end->prox;
    end->prox->ant= end->ant;
    free(end);
    l->qtde--;
}

void imprime_float(void* e){
    No* elemento= (No*) e;
    printf("%f\n", *(elemento->dado));
}

int compara_float(void* e1, void* e2){
    T* elemento1= (T*) e1;
    T* elemento2= (T*) e2;

    if ((*elemento1)==(*elemento2)) {
        return 1;
    }
    return 0;
}
