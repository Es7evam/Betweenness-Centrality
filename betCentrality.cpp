#include "bibliotecas.h"

void FloydWarshallPath(double **M, Lista **path, int nroCidades){
  	int i, j, k;

  	for(k = 0; k < nroCidades; k++) {
    	int i;
    	for(i = 0; i < nroCidades; i++) {
	      	int j;
	      	for(j = 0; j < nroCidades; j++) {
	        	double aux = M[i][k] + M[k][j];

	        	if(k != i && k != j && aux <= M[i][j]) {
	          		if(aux < M[i][j]) {
	            		finaliza_lista(&(path[i][j]));
	          		}
	          		insereLista(&(path[i][j]), &k);

	          		M[i][j] = aux;
	        	}
	      	}
    	}
  	}
}

void pathCounter(Lista **path, paths *p, int curr, int pathWithK){
	//função recursiva que vai passar pelas listas olhando se possui k ou não e contando a quantidade em cada.
}

void _kNoCaminhoIJ(Lista **path, int initial, int dest, int k, int *npath, int *npathWithK) {
	paths p;
	p.initial = initial;
	p.k = k;
	p.npath = npath;
	p.npathWithK = npathWithK;
  	pathCounter(path, &p, dest, 0);
}

void betweennessCentrality(int nroCidades, double peso, Lista **path) {
	int i, j, k;	
	double* output = new double[nroCidades];


	for(k = 0; k < nroCidades; k++) {
    	int npath = 1;
    	int npathWithK = 0;

    	for(i = 0; i < nroCidades; i++) {
    		if(i == k) 
    			continue;
      
      		for(j = 0; j < nroCidades; j++) {
        		if(j == k)
        			continue;

        		_kNoCaminhoIJ(path, i, j, k, &npath, &npathWithK);
      		}
    	}

    	output[k] = npathWithK/npath; //guarda o valor de betweenness centrality de um vertice
  	}
}