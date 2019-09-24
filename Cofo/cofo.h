#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct cofo {
    int nElms;
    int maxElms;
    int curElms;
    void **elms;
} Cofo;
/* Cofo */


Cofo *cCreate(int n);
/* Cria Cofo */


int cDestroy(Cofo *c);
/* Destroi Cofo */

int cInsert(Cofo *c, void *elms);
/* Insere dados no Cofo */


void *cQuery(Cofo *c, void *key, int (*cmp)(void *, void*));
/* Pesquisa dados do Cofo usando uma função auxiliar */


void *cRemove(Cofo *c, void *key, int (*cmp)(void *, void *));
/* Remove dados do Cofo usando uma função auxiliar */

void *cGetFirst(Cofo *c);
/* Exibe o primeiro elemento do Cofo */

void *cGetNext(Cofo *c);
/* Exibe o próximo elemento do cofo uma vez executada a função cGetFirst Cofo */

typedef struct aluno{
     char nome[100];
     char curso[50];
     int matricula;
     float coefRend;
     int ativo;
     

 } Aluno;
/* Aluno */

int comparaMatricula(void *a, void *b);
/* Compara numero de matrícula presente no Cofo com uma valor informado pelo usuário */

int comparaNome(void *a, void *b);
/* Compara nome presente no Cofo com uma valor informado pelo usuário */

int listaAluno(Cofo *c);
/* Lista dados do Cofo  */