#include <stdio.h>
#include "banco.h"

int main(){




    Database* db = banco_criar("Universidade\0");

     char* nomeTabela1 = {"Alunos\0"};
     char* nomeTabela2 = {"Professores\0"};

     char atrib[][30] = {{"ra\0"}, {"nome\0"}, {"nota\0"}};
     char tipo[][30] = {{"integer\0"}, {"string\0"}, {"float\0"}};

     char atrib2[][30] = {{"cpf\0"}, {"nome\0"}, {"turma\0"}};
     char tipo2[][30] = {{"integer\0"}, {"string\0"}, {"string\0"}};

    banco_criar_tabela(db,nomeTabela1 , atrib, tipo, 3);
    banco_criar_tabela(db,nomeTabela2 , atrib2, tipo2, 3);


    /*dados do aluno*/
    char dados[3][30] = {{"1858\0"},{"luiz henrique\0"},{"55\0"}};

    char dados1[3][30] = {{"1858\0"},{"thais\0"},{"65\0"}};

    char dados2[3][30] = {{"1858\0"},{"michel\0"},{"70\0"}};

    char dados3[3][30] = {{"1858\0"},{"daniel\0"},{"80\0"}};


    /*dados do professor*/
    char dados4[3][30] = {{"81518181\0"},{"elaine\0"},{"prob\0"}};

    banco_inserir_tabela_dados(db,"Alunos",dados,3);
    banco_inserir_tabela_dados(db,"Alunos",dados1,3);
    banco_inserir_tabela_dados(db,"Alunos",dados2,3);
    banco_inserir_tabela_dados(db,"Alunos",dados3,3);


    banco_inserir_tabela_dados(db,"Professores",dados4,3);
    banco_imprimir(db);

    printf("\n\n\n CONSULTA CONDICAO: \n\n");

   // banco_tabela_imprimir_condicional(db,"Alunos","nota",'<',"70");
   // banco_tabela_imprimir_condicional(db,"Alunos","nota",'=',"70");
    banco_tabela_imprimir_condicional(db,"Alunos","nota",'=',"10");

    banco_destruir(db);

    return 0;
}
