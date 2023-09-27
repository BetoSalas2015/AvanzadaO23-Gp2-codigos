#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define pausa system("pause")
#define cls system("cls")
#define NL putchar('\n')

//  Prototipos
nodo *insert(nodo *raiz, char dato);
nodo *insert1(nodo *raiz, char dato);
nodo *insert1(nodo *raiz, char dato);
nodo *remueven(nodo *raiz, char *dato, int pos);
nodo *remueve1(nodo *raiz, char *dato);
nodo *remueve(nodo *raiz, char *dato);

struct Nodo 
{
	char info;
	struct Nodo *sig;
};

typedef struct Nodo nodo;

///  Primitivas
nodo *insert(nodo *raiz, char dato)
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
	return raiz;
}

nodo *insert1(nodo *raiz, char dato)
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
	return raiz;
}

nodo *insertn(nodo *raiz, char dato, int pos)
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
	return raiz;
}


nodo *remueve(nodo *raiz, char *dato)
{

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
		*dato = anterior ->info;
		free(anterior);
		return raiz;
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
		*dato = siguiente ->info;
		free(siguiente);
		return raiz;
	}

}

nodo *remueven(nodo *raiz, char *dato, int pos)
{
	nodo *anterior = NULL, *siguiente = NULL;
	if(raiz == NULL)
	{
		printf("Lista vacía, no ha nada que eliminar.\n");
		pausa;
		return NULL;
	}
	anterior = raiz;
	if(pos == 1)
	{
		raiz = raiz ->sig;
		*dato = anterior ->info;
		free(anterior);
		return raiz;
	}
	else
	{ 
		int cont = 1;
		siguiente = anterior ->sig;
		while(siguiente ->sig != NULL && cont < pos - 1)
		{
			anterior = siguiente;
			siguiente = siguiente ->sig;
			cont++;
		}
		if(siguiente ->sig == NULL && cont < pos)
		{
			printf("No se puede eliminar el elemento.\n");
			pausa;
			return '\0';
		}
		anterior -> sig = siguiente->sig;
		*dato = siguiente ->info;
		free(siguiente);
		return raiz;
	}
}

nodo *remueve1(nodo *raiz, char *dato)
{
	nodo *anterior = NULL;
	if(raiz == NULL)
	{
		printf("Lista vacía, no ha nada que eliminar.\n");
		pausa;
		return 0;
	}
	anterior = raiz;
	raiz = raiz ->sig;				// raiz = anterior -> sig
	*dato = anterior ->info;
	free(anterior);
	return raiz;
}
	



void imprimeLista(nodo *raiz)
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
	//int javierHernandez;
	//int *chicharito;		// alias 
	//chicharito = &javierHernandez
	//*chicharito = 50;
	char letra;
	nodo *nombre = NULL, *apellido = NULL;
	imprimeLista(nombre);
	

	nombre = insert(nombre,'R');
	nombre = insert(nombre,'o');
	nombre = insert(nombre,'b');
	nombre = insert(nombre,'e');
	nombre = insert(nombre,'r');
	nombre = insert(nombre,'t');
	nombre = insert(nombre,'o');

	imprimeLista(nombre);
	
	apellido = insert1(apellido, 'S');
	apellido = insert1(apellido, 'a');
	apellido = insert1(apellido, 'l');
	apellido = insert1(apellido, 'a');
	apellido = insert1(apellido, 'z');
	apellido = insert1(apellido, 'a');
	apellido = insert1(apellido, 'r');

	imprimeLista(apellido);

	nombre = remueve1(nombre, &letra);

	printf("El dato que salió fue %c\n", letra);

	imprimeLista(nombre);
	

	pausa;
	return 0;
}