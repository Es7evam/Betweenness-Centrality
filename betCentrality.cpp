#include "bibliotecas.h"

void floydWarshallPath(double **M, int nroCidades, int *distribEgressos, int **output){
  	int i, j, k;

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


int criterioDois(double **M, int nroCidades, int *distribEgressos) {
	int i, j, k;	
	int** output = new int*[nroCidades];
	for(i=0;i<nroCidades;i++)
		output[i] = new int[nroCidades];


	for(int i = 0; i < nroCidades; i++){
		for(int j = 0;j < nroCidades; j++){
			output[i][j] = -1;
		}
	}	


	floydWarshallPath(M, nroCidades, distribEgressos, output);

	for(int i = 0; i < nroCidades; i++){
		for(int j = 0;j < nroCidades; j++){
			cout << output[i][j] << " ";
		}
		cout << endl;
	}	

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

