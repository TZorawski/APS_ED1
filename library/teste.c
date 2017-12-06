#include <stdio.h>
#include <ctype.h>

#include "lib.h"

void toLowerCase(char* s);

void main(){
    printf("Bem-vindo ao Gerenciador de Banco de Dados ED1\n");
    int close= 0;
    char* begin= ["create database", "create table", ];
    char* inst;
    while (close!=(-1)) {
        scanf(" %[^;]s", inst);


        toLowerCase(inst);
        //if (strcpm(inst, "create database")) {
            /* code */
        //}
        printf("-> %s\n", inst);
        close= -1;
    }
}

void toLowerCase(char* s){
    //slower[strlen(s)];
    for (int i= 0; i<strlen(s); i++) {
        s[i]= tolower(s[i]);
    }
}
