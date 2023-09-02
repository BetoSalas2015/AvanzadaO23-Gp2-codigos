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

	insert('R');
	insert('o');
	insert('b');
	insert('e');
	insert('r');
	insert('t');
	insert('o');

	imprimeLista();

	pausa;
	return 0;
}