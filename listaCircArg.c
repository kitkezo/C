#include <stdio.h>
#include <stdlib.h>
//sacarInicio 
//sacarFinal
struct Nodo
{
	int dato;
	struct Nodo *ptrSig;
	struct nodo *ptrAnt;

};

struct Nodo *ptrIni,*ptrFin;

void meterInicio(int dato1)
{
	struct Nodo *ptrNuevo;
	ptrNuevo = (struct Nodo *)malloc(sizeof(struct Nodo));

	printf("\nMeter al inicio");
	ptrNuevo->dato=dato1;
	ptrNuevo->ptrSig=NULL;

	if(ptrIni==NULL)
	{
		printf("\nEs el primer nodo\n");
		ptrAnt = ptrNuevo;
		ptrIni=ptrNuevo;
		ptrIni->ptrSig=ptrIni;//apunta al mismo nodo
		ptrFin=ptrNuevo;

	}else
	{
		ptrNuevo->ptrSig=ptrIni;
		ptrIni=ptrNuevo;
		ptrFin->ptrSig=ptrIni;

	}

}

void meterFinal(int dato1)
{
	struct Nodo *ptrNuevo;
	ptrNuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
	printf("\nMeter al final");

	ptrNuevo->dato=dato1;

	if(ptrIni==NULL)
	{
		printf("primer nodo");
		ptrIni=ptrNuevo;
		ptrIni->ptrSig=ptrIni;//apunta al mismo nodo
		ptrFin=ptrNuevo;

	}else
	{
		ptrFin->ptrSig=ptrNuevo;
		ptrNuevo->ptrSig = ptrIni;
		ptrFin=ptrNuevo;

	}


}

void mostrarlista()
{
	struct Nodo *ptrRecIni;
	ptrRecIni = ptrIni;

	if(ptrIni == NULL)
	{
		printf("La lista está vacia lel \n");

	}else
	{
		while(ptrRecIni!=ptrFin)
		{
			printf("\n %d",ptrRecIni->dato);
			ptrRecIni=ptrRecIni->ptrSig;

		}
		
		printf("\n%d",ptrRecIni->dato);

	}

}

void sacarInicio()
{
	struct Nodo *ptrAux;
	ptrAux = ptrIni;
	if(ptrFin==ptrIni)
	{
		printf("Solo hay un elemento");
		printf("el dato a eliminar es %d",ptrIni->dato);
		free(ptrAux);
		ptrIni=NULL;
		ptrFin=NULL;

	}else
	{
		printf("el dato a eliminar es %d",ptrAux->dato);
		ptrFin->ptrSig=ptrIni->ptrSig;
		ptrIni=ptrIni->ptrSig;
		free(ptrAux);

	}
	
}

void sacarFinal()
{	
	struct Nodo *ptrRec,*ptrAux;
	ptrRec = ptrIni;
	ptrAux = NULL;

	if(ptrRec == ptrFin)
	{
		printf("Solo hay un elemento");
		printf("el dato a eliminar es %d",ptrIni->dato);

		ptrIni=NULL;
		ptrFin=NULL;

	}

	if(ptrIni != NULL)
	{
		//recorrer lista
		while(ptrRec!=ptrFin)
		{
			//verificar si en realidad es el último elemento
			if(ptrRec->ptrSig==ptrFin)
			{
				ptrAux = ptrFin;//hacemos la asignacion de apuntadores para despues liberarlos
				ptrFin = ptrRec;
				ptrFin->ptrSig = ptrIni;
				printf("el dato a eliminar es %d",ptrAux->dato);
				free(ptrAux);
				break;

			}
			ptrRec = ptrRec->ptrSig;
		}
	}




}


int main()
{
	int op,dato1;
	
	
	do
	{
		printf("\n\nSeleccione una opcion: \n\n 1.-Meter dato(al incio)\n 2.-Meter al final\n 3.-Mostrar Lista\n 4.-Sacar al inicio\n 5.-Sacar al final\n 6.-Salir\n\n");

		scanf("%d",&op);
		
		switch(op)
		{
			case 1:
				printf("\n Ingresa el dato: ");
				scanf("%d",&dato1);
				meterInicio(dato1);
			break;
			case 2:
				printf("\n Ingresa el dato: ");
				scanf("%d",&dato1);
				meterFinal(dato1);
			break;
			case 3:	
				mostrarlista();
			break;
			case 4:
				sacarInicio();
			break;
			case 5:
				sacarFinal();
			break;
			case 6:
				exit(0);
			break;
			default:
			printf("Ingrese una opción válida");
		

		}
	}while(op!=6);



	return 0;
}

