#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct stack {
	int top;
	int maxElms;
	void **elms;
} Stack;
/* Pilha */

Stack *stkCreate( int n);
/* Cria Pilha */
	    	
int stkDestroy(Stack *s);
/* Destrói Pilha */

int stkPush(Stack *s, void *elms);
/* Insere dados na Pilha */

int stkEmpty(Stack *s);
/* Checa se Pilha está vazia */
	
void *stkPop(Stack *s);
/* Retira elemento da Pilha */

void *stkTop(Stack *s);
/* Retorna Elemento no topo da Pilha */