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

	/* PARTE DA LISTA
	vector <aresta> listaAdj[51]; //Lista de adjacência (Mudar depois)
	aresta tmp;
	*/
	double **matrizAdj = declaraMatriz(nroCidades);

	

	int cidade1, cidade2;
	double peso;
	for(i=0;i<nroArestas;i++){
		cin >> cidade1 >> cidade2 >> peso;
		insereAresta(matrizAdj, cidade1, cidade2, peso);
		/* PARTE DA LISTA
		tmp.vertice = b;
		tmp.peso = c;
		listaAdj[a].push_back(tmp); //Vai colocar no final da lista - MUDAR

		tmp.vertice = a;
		listaAdj[b].push_back(tmp); //Vai colocar no final da lista - MUDAR
		*/
	}
	cout << criterioUm(matrizAdj, nroCidades, e) << endl;

	cout << endl << endl; // TESTE, equivale a printf \n\n

	/*PARTE DA LISTA
	for(int i=0;i<n;i++){
		cout << "Adjacentes a " << i << ":";
		for(auto a:listaAdj[i]){ ////Passar pela lista imprimindo (teste) - MUDAR
			cout << " " << a.vertice << "|" << a.peso;
		}		
		cout << endl;
	}*/



}
