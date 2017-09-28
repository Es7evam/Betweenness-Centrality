#include <stdio.h>
#include <stdlib.h> // Malloc/Free
#include <iostream> //cin/cout
#include <cstring> //memset

using namespace std; //usado para cin/cout

/*
	Parte da Lista
*/

struct cidade;
struct aresta;
struct Lista;

typedef struct cidade{

	int egressos;
	int id;
	Lista *inicio;

}cidade;

typedef struct aresta{
	
	double distancia;
	int idChegada;
	aresta *prox;

}aresta;

typedef struct Lista{
	
	aresta *inicio;
	aresta *fim;

}Lista;

void cria_lista(Lista *L);
void finaliza_lista(Lista *L);
int lista_vazia(Lista *L);
void insereLista(Lista *L, int *x);

/*
	Parte da Matriz - Critério 1
*/

//Declara a matriz de adjacência de tamanho nroCidades*nroCidades e coloca a distância entre todas as cidades como infinito
double** declaraMatriz(int nroCidades);
void destroiMatriz(int nroCidades, double **M);

//Insere aresta na matriz de adjacência entre as cidades 1 e 2, com peso "peso"
//Feita para grafos não direcionados.
void insereAresta(double **M, int cidade1, int cidade2, double peso);

void floydWarshall(double **M, int nrocidades);

int criterioUm(double **M, int nrocidades, int *distribEgressos);

/*
	Betweenness Centratity - Critério 2
*/

void floydWarshallPath(double **M, int nroCidades, int *distribEgressos, int **output);
int criterioDois(double **M, int nroCidades, int *distribEgressos);
