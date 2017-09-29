#include "bibliotecas.h"

int criterioUm(double **Grafo, int nroCidades, int *distribEgressos, int **output){
	int i,j;
	//Copia a matriz do grafo para não editá-la.
	double **M = declaraMatriz(nroCidades); 
	for(i = 0; i < nroCidades; i++){
		for(j = 0;j < nroCidades; j++){
			M[i][j] = Grafo[i][j];
		}
	}

	/*
		Faz o floyd warshall em cima da matriz copiada para ser usada na procura dos caminhos mínimos.
	*/
	floydWarshall(M, nroCidades, output);

	double *auxPeso = new double[nroCidades]; //equivalente ao malloc
	memset(auxPeso, 0, sizeof(auxPeso)); //Seta a matriz toda como zero

	/*
		Usa-se o vetor auxPeso para guardar a soma dos custos de deslocamento
		Usado para simular como se a festa fosse na cidade j.
	*/
	for(i = 0; i < nroCidades; i++){
		for(j = 0;j < nroCidades; j++){
			auxPeso[j] += M[i][j] * distribEgressos[i];
		}
	}

	double minDist = 0x3f3f3f; //Infinito
	int cidadeEscolhida;
	//Obtém-se a cidade que teve o menor custo total, sendo esta a resposta final.
	for(i=0;i<nroCidades;i++){
		if(auxPeso[i] < minDist){
			minDist = auxPeso[i];
			cidadeEscolhida = i;
		}
	}

	free(auxPeso); //free no vetor auxiliar
	destroiMatriz(nroCidades, M); //dá free na matriz copiada
	return cidadeEscolhida;
}

int criterioDois(double **M, int nroCidades, int *distribEgressos, int **output) {
	int i, j;	

	/*
		Gera uma matriz "output", onde serão guardados os últimos antecessores de um vértice
		Tal antecessor é o último vértice acessado em um caminho mínimo(i,j)
		Inicializa-se com -1 a fim de identificar aqueles que não possuem antecessor continuarem assim.
	*/

	for(int i = 0; i < nroCidades; i++){
		for(int j = 0;j < nroCidades; j++){
			output[i][j] = -1;
		}
	}	

	//Roda o floyd warshall e salva na matriz output os antecessores como comentado
	floydWarshall(M, nroCidades, output);


	int tmp;
	int *freq = new int[nroCidades];
	
	/*
		Usa-se a ideia de união, aplicando o princípio da otimalidade de Bellman.
		Por conta do princípio podemos gerar os caminhos mínimos e contar a frequência de cada vértice
		Assim, tendo tal frequência, basta ver qual é a maior, que será a resposta.
	*/
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

	//Libera a matriz output.
	for(i=0;i<nroCidades;i++)
		free(output[i]);
	free(output);

	//Retorna o valor da cidade que apareceu em mais caminhos mínimos.
	return maxI;
}

