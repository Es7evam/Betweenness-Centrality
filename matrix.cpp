#include "bibliotecas.h"

double** declaraMatriz(int nroCidades){

	int i,j;

	//  Declara a matriz de adjacencia "Grafo".
	double** Grafo = new double*[nroCidades];
	for(i = 0; i < nroCidades; i++)
    	Grafo[i] = new double[nroCidades];

	//  Seta todos os elementos da matriz como infinito.
	for(i = 0; i < nroCidades; i++){
		for(j = 0;j < nroCidades; j++){
			Grafo[i][j] = 0x3f3f3f;
		}
	}

	//  Retorna a matriz de adjacencia "Grafo" para a funcao.
    return Grafo;
}

void destroiMatriz(int nroCidades, double **M){

	int i;

	//  Libera as memorias alocadas para a matriz de adjacencia "M".
	for(i=0;i<nroCidades;i++)
		free(M[i]);
	free(M);
}


void insereAresta(double **M, int cidade1, int cidade2, double peso){
    //  Compara o elemento "peso" com o elemento atual da linha "cidade1" e coluna "cidade2", inserindo-o caso menor.
	//  Supõe-se que sempre deslocarão pela estrada de menor peso entre 2 cidades.
	M[cidade1][cidade2] = min(M[cidade1][cidade2], peso);
	M[cidade2][cidade1] = min(M[cidade2][cidade1], peso);
}

void floydWarshall(double **M, int nroCidades, int **output){
	int i,j,k;

	//  Seta os elementos da diagonal principal da matriz "M" como Zero.
	for(i = 0;i<nroCidades;i++)
		M[i][i] = 0;

    /*
        Verifica se existe um caminho entre as cidades "i" e "j", passando pela cidade "k" e que seja mais curto
        do que o caminho atual.
    */
	for(k = 0;k<nroCidades;k++){
		for(i = 0; i < nroCidades; i++){
			for(j = 0;j < nroCidades; j++){
				if(M[i][j] > M[i][k] + M[k][j]){
					M[i][j] = M[i][k] + M[k][j];
					output[i][j] = k; //k, utilizado no criterio 2
				}
			}
		}
	}
}
