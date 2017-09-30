#include "bibliotecas.h"

int main(void){

	/*
        Declara as variaveis "nroCidades" e "nroArestas" e, em seguida, faz a leitura dos dois valores inteiros
        da primeira linha de entrada, salvando-os nas variaveis declaradas.
	*/
	int nroCidades, nroArestas, i;
	cout << "Digite o numero de cidades e de estradas entre as cidades, respectivamente" << endl;
	cin >> nroCidades >> nroArestas;
	while(nroCidades < 2 || nroCidades > 50 || nroArestas > nroCidades*nroCidades || nroArestas < 1){
		cout << "Número digitado inválido, digite novamente." << endl;
		cout << "Digite o numero de cidades e de estradas entre as cidades, respectivamente" << endl;
		cin >> nroCidades >> nroArestas;
	}

	/*
        Aloca dinamicamente um vetor "e" de tamanho "nroCidades" e, em seguida, faz a leitura dos inteiros das proximas "nroCidades" linhas,
        salvando-os sequencialmente no vetor "e" para guardar a quantidade de egressos em cada cidade.
	*/
	cout << "Digite o numero de egressos em cada cidade, seguindo a ordem de numeraçao delas: 0, 1, 2, ..." << endl;
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
	cout << "Digite as estradas, seguindo o padrão: cidade1 cidade2 tamanhoDaEstrada" << endl;
	for(i=0;i<nroArestas;i++){
		cin >> cidade1 >> cidade2 >> peso;
		if(cidade1 < 0 || cidade1 >= nroCidades || cidade2 < 0 || cidade2 >= nroCidades || peso < 0){
			i--;
			cout << "Valor invalido, digite novamente:" << endl;
			continue;
		}
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
    cout << "Saidas desejadas:" << endl;
	cout << "Criterio 1:" << criterioUm(matrizAdj, nroCidades, e, output) << endl;
	cout << "Criterio 2:" << criterioDois(matrizAdj, nroCidades, e, output) << endl;

	/*
        Libera as memorias alocadas anteriormente, para a resolucao do trabalho.
	*/
	free(e);
	destroiMatriz(nroCidades, matrizAdj);
	// A matriz output foi liberada dentro da função criterioDois.
}
