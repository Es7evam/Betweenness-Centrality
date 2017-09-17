#include <stdio.h>
#include <stdlib.h> // Malloc/Free
#include <iostream> //cin/cout

#include <bits/stdc++.h> //REMOVER DEPOIS ------------------- 
using namespace std; //usado para cin/cout


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
	vector <int> Lista;

	for(i=0;i<n;i++){
		if(e[i] == maximoPessoas){
			//adicionar i na lista de cidades a serem testadas
			Lista.push_back(i); //adiciona no fim da Lista
		}
	}

	cout << "Lista de Maiores Cidades (0 Based)" << endl;
	for(auto a:Lista){
		cout <<"Cidade " << a << endl;
	}

}