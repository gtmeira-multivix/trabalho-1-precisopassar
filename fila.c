#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct No {
  Token token;
  struct No *prox;
} No;

typedef struct fila {
  struct No *primeiro;
  struct No *ultimo;
} Fila;


Fila* fila_criar() {
	Fila *f = (Fila*) malloc(sizeof(Fila));
    f->primeiro = 0;
    f->ultimo = 0;
    return f;
}

void fila_add(Fila *f, Token t) {
	No *tmp = (No*) malloc(sizeof(No));
    tmp->token = t;
    tmp->prox = 0;

    if(f->ultimo == NULL){
        f->primeiro = tmp;
        f->ultimo = tmp;
        return;
    }

    f->ultimo->prox = tmp;
    f->ultimo = tmp;
    
    
    
    
}

Token fila_remover(Fila *f) {
    if(f->primeiro == 0){
        printf("A fila esta vazia.\n");
        return;
    }

    No *tmp = f->primeiro;
    tmp = f->primeiro;

    f->primeiro = f->primeiro->prox;

    if(f->primeiro == 0){
        f->ultimo == 0;
    }

    Token tmpToken;
    tmpToken = tmp->token;
    free(tmp);

    return(tmpToken);
}

int fila_vazia(Fila *f) {
	if(f->primeiro == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void fila_destruir(Fila *f) {
	free(f->primeiro);
	free(f);
}

void fila_impressao(Fila *f) {
	No *tmp;
    tmp = f->primeiro;

    while(tmp != 0){
        token_imprimir(tmp->token);
        tmp = tmp->prox;
    }

}
