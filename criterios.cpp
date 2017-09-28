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


	// Impressao de teste dos custos totais;
	// for(i=0;i<nroCidades;i++)
	// 	cout << auxPeso[i] << " ";
	// cout << endl;

	free(auxPeso); //free no vetor auxiliar
	destroiMatriz(nroCidades, M); //dá free na matriz
	return cidadeEscolhida; //transforma em 1 based para o retorno
}

int criterioDois(double **M, int nroCidades, int *distribEgressos, int **output) {
	int i, j;	

	for(int i = 0; i < nroCidades; i++){
		for(int j = 0;j < nroCidades; j++){
			output[i][j] = -1;
		}
	}	


	floydWarshall(M, nroCidades, output);


	int tmp;
	int *freq = new int[nroCidades];
	
	for(i = 0; i < nroCidades; i++){
		for(j = i+1;j < nroCidades; j++){
			tmp = j;
			while(output[i][tmp] != -1){
				freq[output[i][tmp]]++;
				tmp = output[i][tmp];
			}
		}
	}
	int maxFreq = 0;
	int maxI;

	for(i=0;i<nroCidades;i++){	
		if(freq[i] > maxFreq){
			maxFreq = freq[i];
			maxI = i;
		}
	}


	for(i=0;i<nroCidades;i++)
		free(output[i]);
	free(output);

	return maxI;
}

