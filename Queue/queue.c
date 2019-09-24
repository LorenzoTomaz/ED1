#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./queue.h"



Queue *qCreate(int n){
    Queue *q;
    if (n > 0){
        q = (Queue *)malloc(sizeof(Queue));
        if (q != NULL){
            q->elms = (void **)malloc(n*sizeof(void *));
            if (q->elms != NULL){
                q->beg = 0;
                q->end = -1;
                q->nElms = 0;
                q->maxElms = n;
                return q;
            }
        }
    }
    return NULL;
}
int qDestroy(Queue *q){
    if (q != NULL){
        if (q->nElms == 0){
            free(q->elms);
            free(q);
            return true;
        }
    }
    return false;
}

int qEnqueue(Queue *q, void *elms){
    if (q != NULL){
        if (q->nElms < q->maxElms){
            q->end = qCircleIncrement(q->end, q->maxElms);
            q->elms[q->end];
            q->nElms++;
            return true;
        }
    }
    return false;
}

void *qDequeue(Queue *q){
    if (q != NULL){
        void *aux;
        if (q->nElms > 0){
            aux = q->elms[q->beg];
            q->beg = qCircleIncrement(q->beg, q->maxElms);
            q->nElms--;
            return aux;
        }
    }
    return NULL;
}

int qCircleIncrement(int i, int max){
    
    return ((i+1)%max);
}

int qCircleDecrement(int i, int max){

    return ((max+(i-1))%max);
}