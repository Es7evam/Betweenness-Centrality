#include "bibliotecas.h"

void cria_lista(Lista *L){
	
	L->inicio = NULL;
	L->fim = NULL;
}

void finaliza_lista(Lista *L){
	aresta *p;
	p = L->inicio;

	while (p!=NULL){
		L->inicio = L->inicio->prox;
		free(p);
		p = L->inicio;

	}

	L->fim = NULL;
}

int lista_vazia(Lista *L){
	if(L->inicio == NULL)
		return 1;
	
	else return 0;
}

void insereLista(Lista *L, int *x){

	aresta *a;

	a = (aresta*)malloc(sizeof(aresta));

	a->distancia = *x;
	a->prox = NULL;

	if(L->inicio == NULL)
		L->inicio = a;
	else 
		L->fim->prox = a;
	
	L->fim = a;
}
