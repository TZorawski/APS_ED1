#include <stdio.h>
#include "banco.h"

int main(){




    Database* db = banco_criar("Universidade\0");

     char* nome = {"Alunos\0"};
     char* nome2 = {"Professores\0"};

     char atrib[][30] = {{"ra\0"}, {"nome\0"}, {"nota\0"}};
     char tipo[][30] = {{"integer\0"}, {"string\0"}, {"float\0"}};

     char atrib2[][30] = {{"cpf\0"}, {"nome\0"}, {"turma\0"}};
     char tipo2[][30] = {{"integer\0"}, {"string\0"}, {"float\0"}};

    banco_criar_tabela(db,nome , atrib, tipo, 3);
    banco_criar_tabela(db,nome2 , atrib2, tipo2, 3);

    char dados[3][30] = {{"dado 4\0"},{"dado 5\0"},{"dado 6\0"}};
    char dados2[3][30] = {{"dado 45\0"},{"dado 5\0"},{"dado 6\0"}};

    banco_inserir_tabela_dados(db,"Alunos",dados,3);
    banco_inserir_tabela_dados(db,"Professores",dados2,3);
    banco_imprimir(db);
    banco_destruir(db);

    return 0;
}
