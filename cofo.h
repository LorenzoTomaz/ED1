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

Cofo *cCreate(int n);

int cDestroy(Cofo *c);

int cInsert(Cofo *c, void *elms);

void *cQuery(Cofo *c, void *key, int (*cmp)(void *, void*));

void *cRemove(Cofo *c, void *key, int (*cmp)(void *, void *));

void *cGetFirst(Cofo *c);

void *cGetNext(Cofo *c);

typedef struct aluno{
     char nome[100];
     char curso[50];
     int matricula;
     float coefRend;
     int ativo;
     

 } Aluno;

int comparaMatricula(void *a, void *b);

int comparaNome(void *a, void *b);

int comparaAtivo(void *a, void *b);
