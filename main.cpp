#include "bibliotecas.h"

int main(void){

	/*
        Declara as variaveis "nroCidades" e "nroArestas" e, em seguida, faz a leitura dos dois valores inteiros
        da primeira linha de entrada, salvando-os nas variaveis declaradas.
	*/
	int nroCidades, nroArestas, i;
	cin >> nroCidades >> nroArestas;

	/*
        Aloca dinamicamente um vetor "e" de tamanho "nroCidades" e, em seguida, faz a leitura dos inteiros das proximas "nroCidades" linhas,
        salvando-os sequencialmente no vetor "e" para guardar a quantidade de egressos em cada cidade.
	*/
	int *e = new int[nroCidades];
	for(i=0;i<nroCidades;i++){
		cin >> e[i]; //Leitura do input
	}

	//  Declara a matriz de adjacencia "matrizAdj"
	double **matrizAdj = declaraMatriz(nroCidades);

	/*
        Declara as variaveis "cidade1", "cidade2" e "peso" e, em seguida, faz a leitura das proximas "nroArestas" linhas,
        recebendo dois numeros inteiros e um numero real em cada linha, sendo os inteiros, correspondentes as cidades, os indices para a insercao
        do real "peso" na matriz de adjacencia.
	*/
	int cidade1, cidade2;
	double peso;
	for(i=0;i<nroArestas;i++){
		cin >> cidade1 >> cidade2 >> peso;
		insereAresta(matrizAdj, cidade1, cidade2, peso);
	}

	/*
        Declara uma matriz "output", semelhante a matriz de adjacencia "matrizAdj".
        A matriz "matrizAdj" armazena e permanece com os valores de entrada,
        enquanto a matriz "output", que possui os mesmos valores de "matrizAdj", tem seus valores
        modificados a fim de gerar as saidas correspondentes aos criterios exigidos pelo trabalho.
	*/
	int** output = new int*[nroCidades];
	for(i=0;i<nroCidades;i++)
		output[i] = new int[nroCidades];

    /*
        Imprime as saidas correspondentes aos criterios do trabalho.
    */
	cout << criterioUm(matrizAdj, nroCidades, e, output) << endl;
	cout << criterioDois(matrizAdj, nroCidades, e, output) << endl;

	/*
        Libera as memorias alocadas anteriormente, para a resolucao do trabalho.
	*/
	free(e);
	destroiMatriz(nroCidades, matrizAdj);
	// A matriz output foi liberada dentro da função criterioDois.
}
