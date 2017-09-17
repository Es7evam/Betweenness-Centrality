#include <stdio.h>
#include <stdlib.h> // Malloc/Free
#include <iostream> //cin/cout

#include <bits/stdc++.h> //REMOVER DEPOIS ------------------- (MUDAR)
using namespace std; //usado para cin/cout

struct aresta{
	int vertice;
	double peso;
	aresta *arestaprox;
};


int main(void){
	int n, m, i;
	cin >> n >> m;
	int *e = new int[n]; //alocação dinamica

	int maximoPessoas = 0;
	for(i=0;i<n;i++){
		cin >> e[i]; //Leitura do input
		maximoPessoas = max(maximoPessoas, e[i]);
	}	

	//maximoPessoas -> Nro de pessoas na cidade que tem mais
	vector <int> ListaMaiores;

	for(i=0;i<n;i++){
		if(e[i] == maximoPessoas){
			//adicionar i na lista de cidades a serem testadas
			ListaMaiores.push_back(i); //adiciona no fim da Lista
		}
	}

	cout << "Lista de Maiores Cidades (0 Based)" << endl;
	for(auto a:ListaMaiores){
		cout <<"Cidade " << a << endl;
	}
	cout << endl;


	vector <aresta> listaAdj[51]; //Lista de adjacência (Mudar depois)
	int a, b;
	double c;
	aresta tmp;
	for(i=0;i<m;i++){
		cin >> a >> b >> c;
		tmp.vertice = b;
		tmp.peso = c;
		listaAdj[a].push_back(tmp); //Vai colocar no final da lista - MUDAR

		tmp.vertice = a;
		listaAdj[b].push_back(tmp); //Vai colocar no final da lista - MUDAR
	}

	for(int i=0;i<n;i++){
		cout << "Adjacentes a " << i << ":";
		for(auto a:listaAdj[i]){ ////Passar pela lista imprimindo (teste) - MUDAR
			cout << " " << a.vertice << "|" << a.peso;
		}		
		cout << endl;
	}



}