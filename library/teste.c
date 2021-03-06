
#include <stdio.h>
//#include <stdio_ext.h>
#include <ctype.h>
#include "banco.h"



#define P 6     //Qtde de Palavras
#define L 17    //Qtde de Letras
#define I 100   //Tamanho Instrucao
#define N 30    //Tamanho Nomes


Database* novo_bd(char inst[I], int p_comeco);
void nova_tabela(Database* bd, char inst[I], int p_comeco);
void insere_dados(Database* bd, char inst[I], int p_comeco);
void select_dados(Database* bd, char inst[I], int p_comeco);
void toLowerCase(char* s);
int devolve_pos(char* s, char comeco[P][L]);
void zera_string(char* s);
void imprime_funcoes ();
void trim(char *p);

void main(){


    printf("Bem-vindo ao Gerenciador de Banco de Dados ED1\n");
    char comeco[P][L]= {"quit()", "create database ", "create table ", "insert into ", "select * from ", "imprimir()"};
    char inst[I];//Instrucao
    Database* bd = NULL;
    imprime_funcoes ();

    for (;;) {
        zera_string(inst);
        printf("GBD ED1: ");

        scanf(" %[^\n]s", inst);
        //__fpurge(stdin);
        setbuf(stdin,NULL);

        toLowerCase(inst);

        inst[strlen(inst)]= ';';
        inst[strlen(inst)]= '\0';

        int pos= devolve_pos(inst, comeco);
        if (pos==0) {
            if(bd != NULL){
                banco_destruir(bd);
            }

            exit(0);
            break;
        }
        switch (pos) {
            case 1:
                bd= novo_bd(inst, strlen(comeco[1]));
                break;
            case 2:
                nova_tabela(bd, inst, strlen(comeco[2]));
                break;
            case 3:
                insere_dados(bd, inst, strlen(comeco[3]));
                break;
            case 4:
                select_dados(bd, inst, strlen(comeco[4]));
                break;
            case 5:
                banco_imprimir(bd);
                break;
            default:
                printf("Erro de sintaxe. Verifique seu código.\n");
        }

        //int k= strlen(inst);
        //printf("%d\n", k);
        //printf("-> %s\n", inst);
    }
}

void toLowerCase(char* s){
    for (int i= 0; i<strlen(s)-1; i++) {
        s[i]= tolower(s[i]);
    }
}

int devolve_pos(char* s, char comeco[P][L]){
    int pos= -1;
    for (int i= 0; i<P; i++) {
        int aux= -1;
        char* palavra= comeco[i];
        if (strncmp(palavra, s, strlen(palavra))==0) {
            pos= i;
            break;
        }
    }
    //printf("pos: %d\n", pos);
    return pos;
}

void zera_string(char* s){
    int tam= strlen(s);
    //    printf("tam: %d\n", tam);
    for (int i= 0; i<tam; i++) {
        s[i]= '\0';
    }
}

Database* novo_bd(char inst[I], int p_comeco){
    char nome_bd[N];
    for (int i= p_comeco, j= 0; i<strlen(inst); i++, j++) {
        if (inst[i]==' ' || inst[i]==';') {
            nome_bd[j]= '\0';
            break;

        } else {
            nome_bd[j]= inst[i];
        }
    }
    //printf("%s\n", nome_bd);
    return banco_criar(nome_bd);
}

void nova_tabela(Database* bd, char inst[I], int p_comeco){
    char nome_tabela[N];
    int tam= 1;

    //Get nome
    int carac, j;
    for (carac= p_comeco, j= 0; carac<strlen(inst); carac++, j++) {
        if (inst[carac]==' ') {
            nome_tabela[j]= '\0';
            break;
        } else {
            nome_tabela[j]= inst[carac];
        }
    }

    //Get tamanho
    for (j= carac; j<strlen(inst); j++) {
        if (inst[j]==',') {
            tam++;
        }
    }

    //Get atributos e tipos
    char atributos[tam][N];
    char tipos[tam][N];
    carac+= 2;
    for (int i= 0; i<tam; i++) {
        int aux= 0;
        j= 0;
        while (inst[carac]!=',' && inst[carac]!=')') {
            //printf("%c", inst[carac]);
            if (aux==0 && inst[carac]!=' ') {
                atributos[i][j]= inst[carac];
                j++;
            } else if (aux==0 && inst[carac]==' ') {
                aux++;
                atributos[i][j]= '\0';
                j= 0;
            } else if (aux==1 && inst[carac]!=',') {
                tipos[i][j]= inst[carac];
                j++;
            } else if (aux==1 && inst[carac]==',') {
                aux= 0;
                carac++;
            }
            carac++;
        }
        tipos[i][j]= '\0';
        //trim(atributos[i]);
        //trim(tipos[i]);
        carac+= 2;
    }

    //Cria Tabela
    return banco_criar_tabela(bd, nome_tabela, atributos, tipos, tam);
}

void insere_dados(Database* bd, char inst[I], int p_comeco){
    char nome_tabela[N];
    int tam= 1;

    //Get nome #################
    int carac, j;
    for (carac= p_comeco, j= 0; carac<strlen(inst); carac++, j++) {
        if (inst[carac]==' ') {
            nome_tabela[j]= '\0';
            break;
        } else {
            nome_tabela[j]= inst[carac];
        }
    }

    //Get tamanho #################
    carac+= 2;
    for (j= carac; j<strlen(inst); j++) {
        if (inst[j]==',') {
            tam++;
        }
    }

    //Get valores #################
    char valores[tam][N];
    for (int i= 0; i<tam; i++) {
        j= 0;
        while (inst[carac]!=',' && inst[carac]!=')') {
            if (inst[carac]!='\"') {
                valores[i][j]= inst[carac];
                j++;
            }
            carac++;
        }
        valores[i][j]= '\0';
        //printf("%s\n", valores[i]);
        carac+= 2;
    }
    banco_inserir_tabela_dados(bd, nome_tabela, valores, tam);
}

void select_dados(Database* bd, char inst[I], int p_comeco){
    char nome_tabela[N];
    int tam= 1;

    //Get nome #################
    int carac= p_comeco, j= 0;
    while (inst[carac]!=' ' && inst[carac]!=';') {
//    while (j<2) {
        nome_tabela[j]= inst[carac];
        j++;
        carac++;
    }
    nome_tabela[j]= '\0';
    Tabela* t= buscaTabela(bd, nome_tabela);
    if (inst[carac]==';') {
        tabela_imprimir(t);
    } else if (inst[carac]==' ') {
        char atr[N];
        char operador;
        char valor[N];

        //Get atributo #################
        carac+= 7;
        j= 0;
        while (inst[carac]!=' ') {
            atr[j]= inst[carac];
            j++;
            carac++;
        }
        atr[j]= '\0';

        //Get operador
        carac++;
        operador= inst[carac];

        //Get valor
        j= 0;
        carac++;
        while (inst[carac]!=';') {
            if (inst[carac]!='\"') {
                valor[j]= inst[carac];
                j++;
            }
            carac++;
        }
        valor[j]= '\0';
        trim(valor);

        // printf("atr: %s\n", atr);
        // printf("op: %c\n", operador);
        // printf("valor: %s\n", valor);
        banco_tabela_imprimir_condicional(bd, nome_tabela, atr, operador, valor);
    }
}

void imprime_funcoes (){
    printf("\n");
    printf("+++++++++++++++++++++++\n");
    printf("create database nome_database;\n");
    printf("create table nome_tabela (variavel1 tipo1, variavel2 tipo2, ..., varN tipoN);\n");
    printf("insert into nome_tabela (v1, v2, ..., vn);\n");
    printf("select * from nome_tabela;\n");
    printf("select * from nome_tabela where atributo </=/> valor;\n");
    printf("imprimir();\n");
    printf("quit();\n");
    printf("+++++++++++++++++++++++\n");
    printf("\n");
}

void trim(char *p){//tira espacos em branco dos extremos da string
    int len= strlen(p);
    while(isspace(p[0])!=0){
        len= strlen(p);
        for(int i= 0; i<=len; i++){
            p[i]= p[i+1];
        }
    }
    len= strlen(p);
    while(isspace(p[len-1])!=0){
        for(int i= 0; i<=len; i++){
            p[(len-1)]= '\0';
        }
        len= strlen(p);
    }
}
