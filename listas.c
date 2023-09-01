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
}

int main()
{
	nodo Variable;
	pausa;
	return 0;
}