#include <stdio.h>
#include "lista_sentinela.h"

void main(){
    Lista* l= lista_cria();
    // lista_desaloca(l);
    float num= 2.2;
    float num1= 7.2;
    float num2= 3.5;
    float num3= 4.1;

    //INSERIR
    lista_insere(l, &num, 0);
    lista_insere(l, &num1, 1);
    lista_insere(l, &num2, 0);
    lista_insere(l, &num2, 1);
    lista_insere_fim(l, &num);
    lista_insere_fim(l, &num);
    lista_insere_fim(l, &num);
    lista_insere_fim(l, &num3);

    //REMOVER
    // T* elemento= lista_remove1(l, 4);
    // printf("%p : %f\n", elemento, *elemento);

    // T elemento;
    // int a= lista_remove2(l, 0, &elemento);
    // printf("%d: %f\n", a, elemento);

    // T elemento= 3.5;
    // T* e= lista_remove_elemento(l, &elemento, compara_float);
    // printf("%p : %f\n", e, *e);

    //BUSCAR
    // T* elemento= lista_busca1(l, 4);
    // printf("%p : %f\n", elemento, *elemento);

    // T elemento;
    // int a= lista_busca2(l, 7, &elemento);
    // printf("%d: %f\n", a, elemento);

    //COMPARA FLOAT
    // float* n1= (T*) malloc(sizeof(T));
    // float* n2= (T*) malloc(sizeof(T));
    //
    // *(n1)= 2.3;
    // *(n2)= 2.3;
    //
    // int a= compara_float(n1, n2);
    // printf("%d\n", a);

    //CONTEM NA LISTA
    // T elemento= 7.3;
    // int a= lista_contem(l, &elemento, compara_float);
    // printf("%d\n", a);

    //POSICAO NA LISTA
    // T elemento= 4.1;
    // int a= lista_posicao(l, &elemento, compara_float);
    // printf("%d\n", a);

    //IMPRIME LISTA
    // printf("--------------------\n");
    // lista_imprime(l, imprime_float);

}
