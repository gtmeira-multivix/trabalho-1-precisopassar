#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct No {
  Token token;
  struct No *prox;
} No;
typedef struct fila {
  struct No *comeco;
  struct No *ultimo;
} Fila;


Fila* fila_criar() {
	Fila *f = (Fila*) malloc(sizeof(Fila));
    f->comeco = NULL;
    f->ultimo = NULL;
    return f;
}


void fila_add(Fila *f, Token t) {
	No *tmp = (No*) malloc(sizeof(No));
    tmp->token = t;
    tmp->prox = NULL;
    if(f->ultimo == NULL){
        f->comeco = tmp;
        f->ultimo = tmp;
        return;
    }
    f->ultimo->prox = tmp;
    f->ultimo = tmp;
    }


Token fila_remover(Fila *f) {
    if(f->comeco == NULL){
        Token t;
        return;
    }
    No *tmp;
    tmp = f->comeco;
    f->comeco = f->comeco->prox;
    if(f->comeco == NULL){
        f->ultimo == NULL;
    }
    Token tmpToken;
    tmpToken = tmp->token;
    free(tmp);
    return(tmpToken);
}


int fila_vazia(Fila *f) {
	if(f->comeco == NULL){
        return 1;
    }
    else{
        return 0;
    }
}


void fila_destruir(Fila *f) {
	free(f->comeco);
	free(f);
}


void fila_impressao(Fila *f) {
	No *tmp;
    tmp = f->comeco;
    while(tmp != NULL){
        token_imprimir(tmp->token);
        tmp = tmp->prox;
    }

}
