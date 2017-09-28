#include "bibliotecas.h"

int main(void){

	/*
        Declara as variaveis "nroCidades" e "nroArestas" e, em seguida, faz a leitura dos dois valores inteiros
        da primeira linha de entrada, salvando-os nas variaveis declaradas.
	*/
	int nroCidades, nroArestas, i;
	cin >> nroCidades >> nroArestas;

	/*
        Aloca dinamicamente um vetor "e" de tamanho "nroCidades" e, em seguida, faz a leitura dos inteiros das "nroCidades" proximas linhas,
        salvando-os sequencialmente no vetor "e" para guardar a quantidade de egressos em cada cidade.
	*/
	int *e = new int[nroCidades];
	for(i=0;i<nroCidades;i++){
		cin >> e[i]; //Leitura do input
	}

	//  Declara a matriz de adjacencia "matrizAdj"
	double **matrizAdj = declaraMatriz(nroCidades);

	/*
        Declara as variaveis "cidade1", "cidade2" e "peso"
	*/
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
