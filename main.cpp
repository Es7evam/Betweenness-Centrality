#include "bibliotecas.h"

int main(void){
	int nroCidades, nroArestas, i;
	cin >> nroCidades >> nroArestas;
	int *e = new int[nroCidades]; //alocação dinamica

	int maximoPessoas = 0;
	for(i=0;i<nroCidades;i++){
		cin >> e[i]; //Leitura do input
		maximoPessoas = max(maximoPessoas, e[i]); //mudar depois
	}	

	double **matrizAdj = declaraMatriz(nroCidades);

	int cidade1, cidade2;
	double peso;
	for(i=0;i<nroArestas;i++){
		cin >> cidade1 >> cidade2 >> peso;
		insereAresta(matrizAdj, cidade1, cidade2, peso);
	}
	cout << criterioUm(matrizAdj, nroCidades, e) << endl;
	cout << criterioDois(matrizAdj, nroCidades, e) << endl;


}
