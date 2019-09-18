#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "./cofo.h"

Cofo *cCreate(int n){
    Cofo *c;
    c = (Cofo *)malloc(sizeof(Cofo));
    if (c != NULL){
        c->elms = (void **)malloc(sizeof(void*)*n);
        if (c->elms != NULL){
            c->maxElms = n;
            c->nElms = 0;
            return c;
        }
        free(c);
    }
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
    int i = 0; int aux;int k;
    printf("query");
    if (c != NULL){
        if (c->nElms > 0){
            aux = c->nElms;
            while ((i < aux) && (cmp(c->elms[i], key) != true)){
                i++;
                k = i;
            }
            if ( i >= aux){
                return NULL;
            }
            if (cmp(c->elms[i], key) == true){
                return c->elms[i];
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


