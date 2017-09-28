#include "bibliotecas.h"


int criterioUm(double **Grafo, int nroCidades, int *distribEgressos, int **output){
	int i,j;
	double **M = declaraMatriz(nroCidades); //Copia a matriz do grafo
	for(i = 0; i < nroCidades; i++){
		for(j = 0;j < nroCidades; j++){
			M[i][j] = Grafo[i][j];
		}
	}

	floydWarshall(M, nroCidades, output);

	double *auxPeso = new double[nroCidades]; //equivalente ao malloc
	memset(auxPeso, 0, sizeof(auxPeso)); //Seta a matriz toda como zero

	for(i = 0; i < nroCidades; i++){
		for(j = 0;j < nroCidades; j++){
			auxPeso[j] += M[i][j] * distribEgressos[i];
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

int criterioDois(double **M, int nroCidades, int *distribEgressos, int **output) {
	int i, j, k;	

	for(int i = 0; i < nroCidades; i++){
		for(int j = 0;j < nroCidades; j++){
			output[i][j] = -1;
		}
	}	


	floydWarshall(M, nroCidades, output);

	// for(int i = 0; i < nroCidades; i++){
	// 	for(int j = 0;j < nroCidades; j++){
	// 		cout << output[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }	

	int freqK = 0;
	int freqCurr, MaxK;
	for(k=0;k<nroCidades;k++){
		freqCurr = 0;
		for(i = 0; i < nroCidades; i++){
			for(j = 0;j < nroCidades; j++){
				if(output[i][j] == k)
					freqCurr++;
			}
		}
		if(freqCurr > freqK){
			MaxK = k;
			freqK = freqCurr;
		}
	}
	cout << "Criterio 2: ";

	for(i=0;i<nroCidades;i++)
		free(output[i]);
	free(output);
	return MaxK;
}

