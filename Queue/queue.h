#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct queue
{
   int nElms;
   int end;
   int beg;
   int maxElms;
   void **elms;
} Queue;

Queue *qCreate(int n);
/* Cria Fila */

int qDestroy(Queue *q);
/* Destrói Fila */

int qEnqueue(Queue *q, void *elms);
/* Insere dado na Fila */

void *qDequeue(Queue *q);
/* Retira dado da File */

int qCircleIncrement(int i, int max);
/* Incrementa posição de beg de forma circular */

int qCircleDecrement(int i, int max);
/* Decrementa posição de beg de forma circular */
