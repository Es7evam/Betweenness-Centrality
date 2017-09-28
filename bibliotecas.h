#include <stdio.h>
#include <stdlib.h> // Malloc/Free
#include <iostream> //cin/cout
#include <cstring> //memset

using namespace std; //usado para cin/cout

/*
	Matrix.cpp
	TAD para matriz de adjacência
*/

//Declara a matriz de adjacência de tamanho "nroCidades" * "nroCidades" e coloca a distância entre todas as cidades como infinito
double** declaraMatriz(int nroCidades);

//Destrói a matriz de doubles, liberando o seu espaço na memória.
void destroiMatriz(int nroCidades, double **M);


/*
	Insere aresta na matriz de adjacência "M" entre "cidade1" e "cidade2", com peso "peso".
	Feita para grafos não direcionados.
	Só irá inserir a aresta se ela for menor do que uma conexão já existente entre a cidade 1 e 2.
*/
void insereAresta(double **M, int cidade1, int cidade2, double peso);

/*
	Algoritmo de Floyd Warshall, calcula as distâncias entre todos os pares de nós e salva na matriz M
	A matriz output é usada no critério 2 e é o "antecessor imediato" de um nó no seu menor caminho na aresta (i,j)
*/
void floydWarshall(double **M, int nrocidades, int **output);


/*
	Criterios.cpp
	Cada um retorna a cidade escolhida de acordo com o critério especificado
	Os parâmetros são:
		M: Matriz de adjacências
		nrocidades: Número de cidades total
		DistribEgressos: Vetor com a quantidade de ingressos em cada cidade
		Output: Matriz utilizada para medir os valores do betweeness centrality
*/

int criterioUm(double **M, int nrocidades, int *distribEgressos, int **output);
int criterioDois(double **M, int nroCidades, int *distribEgressos, int **output);
