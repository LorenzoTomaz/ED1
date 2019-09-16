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

Cofo *cCreate(int n){
    Cofo *c;
    c = (Cofo *)malloc(sizeof(Cofo));
    if (c != NULL){
        printf("teste");
        c->elms = (void **)malloc(sizeof(void*)*n);
        if (c->elms != NULL){
            c->maxElms = n;
            c->nElms = 0;
            return c;
        }
        printf("free");
        free(c);
    }
    printf("NULL");
    return NULL;
}
int cDestroy(Cofo *c){
    if (c != NULL){
        if( c->elms == 0){
            free(c->elms);
            free(c);
            return true;
        }
    }
    return false;
}
int cInsert(Cofo *c, void *elms){
    if (c != NULL){
        if (c->nElms < c->maxElms){
            c->elms[c->nElms] = elms;
            c->nElms++;
            return true;
        }
    }
    return false;
}
void *cQuery(Cofo *c, void *key, int (*cmp)(void *, void*)){
    int i = 0;
    printf("query");
    if (c != NULL){
        if (c->nElms > 0){
            while (cmp(c->elms[i], key) != true && i < c->nElms){
                i++;
                printf("i++");
            }
            if (cmp(c->elms[i], key) == true){
                return c->elms[i];
            }
            else{
                printf("else");
            }
        }
    }
    return NULL;
}

void *cRemove(Cofo *c, void *key, int (*cmp)(void *, void *)){
    int i = 0;
    void *aux;
    if (c != NULL){
        if (c->nElms > 0){
            while (cmp(c->elms[i], key) != true && i < c->nElms){
                i++;
            }
            if (cmp(c->elms[i], key) == true){
                aux = c->elms[i];
                for ( ;i<c->nElms;i++){
                    c->elms[i] = c->elms[i+1];
                }
                c->nElms--;
                return aux;
            }
        }
    }
    return NULL;
}
 void *cGetFirst(Cofo *c){
     if (c != NULL){
         c->curElms = 0;
         return c->elms[c->curElms];
     }
     return NULL;
 }

 void *cGetNext(Cofo *c){
     if (c != NULL){
         if (c->curElms < c->nElms -1){
             c->curElms++;
             return c->elms[c->curElms];
         }
     }
     return NULL;
 }

 typedef struct aluno{
     char nome[100];
     char curso[50];
     int matricula;
     float coefRend;
     int ativo;
     

 } Aluno;

 int comparaMatricula(void *a, void *b){
     Aluno *pa;
     int *pb;
     pb = (int *)b;
     pa = (Aluno *)a;
     printf("cmp");
     if (pa->matricula == *pb){
         return true;
     }
     else{
         return false;
     }
 }


 int comparaNome(void *a, void *b){
     Aluno *pa;
     char *pb;
     pb = (char *)b;
     pa = (Aluno *)a;
     if (strcmp(pa->curso,pb) == 0){
         return true;
     }
     else{
         return false;
     }
 }


 int comparaAtivo(void *a, void *b){
     Aluno *pa;
     int *pb;
     pb = (int *)b;
     pa = (Aluno *)a;
     if (pa->ativo == *pb){
         return true;
     }
     else{
         return false;
     }
 }
