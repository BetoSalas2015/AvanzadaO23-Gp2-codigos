#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define pausa system("pause")
#define cls system("cls")
#define NL putchar('\n')

//  Prototipos
void insert(char dato);
void insert1(char dato);
void insertn(char dato, int pos);

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

void insertn(char dato, int pos)
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
	if( pos == 1)
	{
		nuevo ->sig = raiz;
		raiz = nuevo;
	}
	else
	{
		int cont = 1;
		nodo *recorre = raiz;
		while( recorre ->sig != NULL && cont < pos - 1)
		{
			recorre = recorre ->sig; 
			cont++;
		}
		nuevo ->sig = recorre ->sig;
		recorre -> sig = nuevo;
	}
}


char remueve(void)
{
	char dato;
	nodo *anterior = NULL, *siguiente = NULL;
	if(raiz == NULL)
	{
		printf("Lista vacía, no ha nada que eliminar.\n");
		pausa;
		return '\0';
	}
	anterior = raiz;
	if(anterior ->sig == NULL)
	{
		raiz = NULL;
		dato = anterior ->info;
		free(anterior);
		return dato;
	}
	else
	{ 
		siguiente = anterior ->sig;
		while(siguiente ->sig != NULL)
		{
			anterior = siguiente;
			siguiente = siguiente ->sig;
		}
		anterior -> sig = NULL;
		dato = siguiente ->info;
		free(siguiente);
		return dato;
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

	printf("Lo que salio de la lista ligada: %c\n", remueve() );
	printf("Lo que salio de la lista ligada: %c\n", remueve() );

	imprimeLista();

	pausa;
	return 0;
}