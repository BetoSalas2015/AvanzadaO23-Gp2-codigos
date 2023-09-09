#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define pausa system("pause")
#define cls system("cls")
#define NL putchar('\n')

struct Nodo 
{
	char info;
	struct Nodo *sig;
};

typedef struct Nodo nodo;

nodo *raiz = NULL;

///  Primitivas
void insert(char dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof( nodo ) );
	if(nuevo == NULL)
	{
		printf("No hay memoria. \n");
		exit(1);
	}
	nuevo -> info = dato;
	nuevo -> sig = NULL;
	if( raiz == NULL )
	{
		raiz = nuevo;
	}
	else
	{
		nodo *recorre = raiz;
		while( recorre ->sig != NULL)
			recorre = recorre ->sig; 
		recorre -> sig = nuevo;
	}
}

void insert1(char dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof( nodo ) );
	if(nuevo == NULL)
	{
		printf("No hay memoria. \n");
		exit(1);
	}
	nuevo -> info = dato;
	nuevo -> sig = NULL;

	nuevo ->sig = raiz;
	raiz = nuevo;
}

void insertn(char dato, int n)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof( nodo ) );
	if(nuevo == NULL)
	{
		printf("No hay memoria. \n");
		exit(1);
	}
	nuevo -> info = dato;
	nuevo -> sig = NULL;
	if( raiz == NULL )
	{
		raiz = nuevo;
	}
	else
	{
		nodo *recorre = raiz;
		while( recorre ->sig != NULL)
			recorre = recorre ->sig; 
		recorre -> sig = nuevo;
	}
}

void imprimeLista()
{
	nodo *recorre = raiz;
	while( recorre != NULL)
	{
		printf("%c, ", recorre ->info);
		recorre = recorre ->sig; 
	}
	putchar('\n');
}

int main()
{
	imprimeLista();

	insert1('R');
	insert1('o');
	insert1('b');
	insert1('e');
	insert1('r');
	insert1('t');
	insert1('o');

	imprimeLista();

	pausa;
	return 0;
}