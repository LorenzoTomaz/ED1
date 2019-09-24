#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./stack.h"



Stack *stkCreate( int n) {
	Stack *s;
	if (n > 0){
		s = (Stack *)malloc(sizeof(Stack));
	    if (s != NULL){
	    	s->top = -1;
	    	s->maxElms = n;
	    	s->elms = (void **)malloc(n*sizeof(void *));
	    	return s;
	    }
	}
	return NULL;
}
	    	
int stkDestroy(Stack *s){
	if (s != NULL){
		if (s->top < 0){
			free(s->elms);
			free(s);
			return true;
		}
	}
	return false;
}

int stkPush(Stack *s, void *elms){
	if (s != NULL){
		if (s->top < s->maxElms -1){
			s->top++;
			s->elms[s->top] = elms;
			return true;
		}
	}
	return false;
}
int stkEmpty(Stack *s){
	if (s != NULL){
		if (s->top >= 0){
			return false;
		}
	}
	return true;
}

	
void *stkPop(Stack *s){
	void *aux;
	if (s != NULL){
		if (stkEmpty(s) == false){
			aux = s->elms[s->top]; 
			s->top--;
			return aux;
		}
	}
	return NULL;
}
void *stkTop(Stack *s){
	if (s != NULL){
		if (stkEmpty(s) == false){
	   	return s->elms[s->top];
    	}
	}	
	return NULL;
}
