#include <stdio.h>
#include <stdlib.h> // Malloc/Free
#include <iostream> //cin/cout
#include <cstring> //memset

using namespace std; //usado para cin/cout

/*
	Parte da Matriz
*/

//Declara a matriz de adjacência de tamanho nroCidades*nroCidades e coloca a distância entre todas as cidades como infinito
double** declaraMatriz(int nroCidades);
void destroiMatriz(int nroCidades, double **M);


//Insere aresta na matriz de adjacência entre as cidades 1 e 2, com peso "peso"
//Feita para grafos não direcionados.
void insereAresta(double **M, int cidade1, int cidade2, double peso);


void floydWarshall(double **M, int nrocidades, int **output);


/*
	Criterios.cpp
*/

int criterioUm(double **M, int nrocidades, int *distribEgressos, int **output);
int criterioDois(double **M, int nroCidades, int *distribEgressos, int **output);
