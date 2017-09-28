#include "bibliotecas.h"

int main(void){
	int nroCidades, nroArestas, i;
	cin >> nroCidades >> nroArestas;
	int *e = new int[nroCidades]; //alocação dinamica

	int maximoPessoas = 0;
	for(i=0;i<nroCidades;i++){
		cin >> e[i]; //Leitura do input
	}	

	double **matrizAdj = declaraMatriz(nroCidades);

	int cidade1, cidade2;
	double peso;
	for(i=0;i<nroArestas;i++){
		cin >> cidade1 >> cidade2 >> peso;
		insereAresta(matrizAdj, cidade1, cidade2, peso);
	}

	int** output = new int*[nroCidades];
	for(i=0;i<nroCidades;i++)
		output[i] = new int[nroCidades];


	cout << criterioUm(matrizAdj, nroCidades, e, output) << endl;
	cout << criterioDois(matrizAdj, nroCidades, e, output) << endl;

	free(e);
	destroiMatriz(nroCidades, matrizAdj);
}
