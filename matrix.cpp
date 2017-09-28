#include "bibliotecas.h"

double** declaraMatriz(int nroCidades){
	int i,j;

	double** Grafo = new double*[nroCidades];
	for(i = 0; i < nroCidades; i++)
    	Grafo[i] = new double[nroCidades];

	for(i = 0; i < nroCidades; i++){
		for(j = 0;j < nroCidades; j++){
			Grafo[i][j] = 0x3f3f3f; //seta como infinito
		}
	}
    return Grafo;
}

void destroiMatriz(int nroCidades, double **M){
	int i;
	for(i=0;i<nroCidades;i++)
		free(M[i]);
	free(M);
}

void insereAresta(double **M, int cidade1, int cidade2, double peso){
	//Supõe-se que sempre deslocarão pela estrada de menor peso entre 2 cidades.
	M[cidade1][cidade2] = min(M[cidade1][cidade2], peso);
	M[cidade2][cidade1] = min(M[cidade2][cidade1], peso);
}

void floydWarshall(double **M, int nroCidades, int **output){
	int i,j,k;

	for(i = 0;i<nroCidades;i++)
		M[i][i] = 0; //diagonais como 0

	for(k = 0;k<nroCidades;k++){
		for(i = 0; i < nroCidades; i++){
			for(j = 0;j < nroCidades; j++){
				if(M[i][j] > M[i][k] + M[k][j]){
					M[i][j] = M[i][k] + M[k][j];
					output[i][j] = k;
				}
			}
		}
	}
}