typedef struct cidade{

	int egressos;
	int id;
	Lista *inicio;

}cidade;

typedef struct Lista{
	
	aresta *inicio;
	aresta *prox;

}Lista;

typedef struct aresta{
	
	float distancia;
	int idChegada;

}aresta;