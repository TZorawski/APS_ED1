#include "tabela.h"
#define TAM_TABELA 4
#define TAM_COL 30
typedef struct {
    char* nome; //char nome[30]; deixei alocado dinamicamente
    Tabela** tabelas;
    unsigned short int tamTabelas;
    unsigned short int qtdeTabelas;
}Database;


//void banco_tabela_imprimir_condicional(char* NomeTable,char* NomeAtrib,char* condicao);

Database* banco_criar(char* nome_banco){

    Database* novo_banco = (Database*)malloc(sizeof(Database));
    int tam_nome = strlen(nome_banco);
    novo_banco->nome = (char*)calloc(tam_nome+1,sizeof(char));

    strcpy(novo_banco->nome,nome_banco);
    novo_banco->tamTabelas= TAM_TABELA;
    //novo_banco->tabelas = NULL;// ok / LEIA OS COMENTARIOS DA LINHA 28
    novo_banco->tabelas = (Tabela**)calloc(novo_banco->tamTabelas,sizeof(Tabela*));
    novo_banco->qtdeTabelas= 0;

    return novo_banco;
}

void banco_criar_tabela(Database* banco, char* nome_tabela, char atributo[][30], char tipo[][30], int qtd_atr){

    //banco->tabelas = (Tabela**)calloc(banco->tamTabelas,sizeof(Tabela*)); ///VOCE ESTAVA DANDO UM CALLOC EM CIMA DE OUTRO FOI RETIRADO ISSO E COLOCADO ALI EM CIMA
    banco->tabelas[banco->qtdeTabelas] = tabela_criar(nome_tabela,qtd_atr, atributo,tipo);
    banco->qtdeTabelas++;

}

Tabela* buscaTabela(Database* banco, char* nome){
    for(int i = 0; i < banco->qtdeTabelas; i++){
        if((strcmp(banco->tabelas[i]->nome,nome)) == 0){
            return banco->tabelas[i];
        }
    }
    printf("sai\n");
    return NULL;
}


void banco_inserir_tabela_dados(Database* banco, char* nome, char dados[][30], int qtd_atr){

    Tabela* tabela = buscaTabela(banco,nome);
    if(tabela==NULL){
        printf("\n\n\n");
        printf("*********************************************************************\n");
        printf("** NAO FOI POSSIVEL LOCALIZAR A TABELA, POR FAVOR TENTE NOVAMENTE! **\n");
        printf("*********************************************************************\n");

        return;
    }

    tabela_inserir_dados_na_tupla(tabela, dados, qtd_atr);
}


void banco_imprimir(Database* db){
    printf("DATABASE: %s\n", db->nome);
    printf("TABELA(S): \n");
    int i;
    for (int i = 0; i < db->qtdeTabelas; i++){
        tabela_imprimir(db->tabelas[i]);
    }
}

void banco_destruir(Database* banco){

    for(int i = 0; i < banco->qtdeTabelas; i++){
        tabela_destruir(banco->tabelas[i]);
    }
    free(banco->nome);
    free(banco);
    banco = NULL;
}



/*** FUNÇÃO NOVA ***/
void banco_tabela_imprimir_condicional(Database* banc, char* NomeTable,char* NomeAtrib, char condicao,char* elem_comparado){

    Tabela* table = buscaTabela(banc,NomeTable);

    if(table == NULL){
        printf("\n\n\n");
        printf("*********************************************************************\n");
        printf("** NAO FOI POSSIVEL LOCALIZAR A TABELA, POR FAVOR TENTE NOVAMENTE! **\n");
        printf("*********************************************************************\n");

        return;
    }
   // printf("\n\npassou pela tabela");
    tabela_imprimir_condicional(table,NomeAtrib,condicao,elem_comparado);
}
/*** FIM ***/

