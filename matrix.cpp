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

void floydWarshall(double **M, int nroCidades){
	int i,j,k;

	for(i = 0;i<nroCidades;i++)
		M[i][i] = 0; //diagonais como 0

	for(k = 0;k<nroCidades;k++){
		for(i = 0; i < nroCidades; i++){
			for(j = 0;j < nroCidades; j++){
					M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
			}
		}
	}

}

int criterioUm(double **Grafo, int nroCidades, int *distribAlunos){
	int i,j;
	double **M = declaraMatriz(nroCidades); //Copia a matriz do grafo
	for(i = 0; i < nroCidades; i++){
		for(j = 0;j < nroCidades; j++){
			M[i][j] = Grafo[i][j];
		}
	}

	floydWarshall(M, nroCidades);

	double *auxPeso = new double[nroCidades]; //equivalente ao malloc
	memset(auxPeso, 0, sizeof(auxPeso)); //Seta a matriz toda como zero

	for(i = 0; i < nroCidades; i++){
		for(j = 0;j < nroCidades; j++){
			auxPeso[j] += M[i][j] * distribAlunos[i];
		}
	}

	double minDist = 0x3f3f3f; //Infinito
	int cidadeEscolhida;
	for(i=0;i<nroCidades;i++){
		if(auxPeso[i] < minDist){
			minDist = auxPeso[i];
			cidadeEscolhida = i;
		}
	}

	cout << "Impressao de teste (matrix.cpp)" << endl;
	for(i=0;i<nroCidades;i++)
		cout << auxPeso[i] << " ";
	cout << endl;

	cout << "Criterio 1: ";
	free(auxPeso); //free no vetor auxiliar
	destroiMatriz(nroCidades, M); //dá free na matriz
	return cidadeEscolhida; //transforma em 1 based para o retorno
}