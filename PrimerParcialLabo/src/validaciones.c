/*
 * validaciones.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Ludo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "cliente.h"
int get_myGets(char* pResultado, int len)
{
	int retorno = -1;
	fflush(stdin);
	if(pResultado != NULL && len > 0 && fgets(pResultado,len,stdin)==pResultado)
	{
		fflush(stdin);
		if(pResultado[strnlen(pResultado,len)-1]== '\n')
		{
			pResultado[strnlen(pResultado,len)-1]='\0';
		}
		retorno = 1;
	}
	return retorno;
}

int val_isValidInt(char* numero, int flagSigned)
{
	int retorno = -1;
	int i;
	if(numero != NULL)
	{
		retorno = 1;
		if((numero[0] < '0' || numero[0] > '9') && (numero[0] != '-' || numero[0] != '+'))
		{
			retorno = 0;
		}
		else
		{
			i = 1;
			while(numero[i] != 0) // busco el final
			{
				if(numero[i]<'0' || numero[i]>'9')
				{
					retorno = 0;
					break;
				}
				i++;
			}
		}
	}
	return retorno;
}
int get_int(int* pResultado,int len,char* mensaje,char* mensajeError, int minimo, int maximo, int reintentos,int flagSigned)
{
	int retorno = -1;
	char buffer[len];
	int bufferInt;
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno= 0;
		for(int i=0; i <= reintentos ;reintentos--)
		{
			printf("%s",mensaje);
			fflush(stdin);
			if(get_myGets(buffer,len) && val_isValidInt(buffer,flagSigned))
			{
					bufferInt=atoi(buffer);
				if(bufferInt <= maximo && bufferInt >= minimo)
				{

					*pResultado = bufferInt;
					retorno = 1;
					break;
				}

			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return retorno;
}

int IngresarEntero(char mensaje[])
{
	int unEntero;

	printf("%s\n",mensaje);
	scanf("%d", &unEntero);

	return unEntero;
	//entero que va a devolver la funcion, por eso tiene un int adelante

}

int PedirEntero(void)
{
	int unEntero;

	printf("ingrese un numero:\n ");
	scanf("%d", &unEntero);

	return unEntero;
	//entero que va a devolver la funcion, por eso tiene un int adelante

}

int PedirEntero2(char mensaje[],int minimo,int maximo)
{
	int numeroIngresado;

	printf("%s",mensaje);
	scanf("%d",&numeroIngresado);

	while(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("ERROR,reingrese\n");
		scanf("%d",&numeroIngresado);
	}
	return numeroIngresado;
}

void mostrarNumero(float numero)// implementacion o desarrollo
{
	printf("el numero es: %.2f",numero );
}



int myGets (char* cadena,char mensaje[] ,int longitud) //char nombre [200] myGets(nombre,sizeof(nombre)) sizeof le manda el tamaño
{
	int retorno = -1;

	char bufferString [50];

	printf("%s",mensaje);

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}//leer de un archivo una cadena de caracteres

	}

	return retorno;
}

int getString(char* cadena, int limite)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && limite > 0 && fgets(bufferString, sizeof(bufferString), stdin) != NULL)
	{
		fflush(stdin);
		if(bufferString[strlen(bufferString) - 1] == '\n')
		{
			bufferString[strlen(bufferString) - 1] = '\0';
		}
		strncpy(cadena, bufferString, limite);
		retorno = 0;
	}

	return retorno;
}

void CargarVector(int listaNumeros[],int tam) //parametro formal, paso una copia de la direccion de memoria
{
	int i;

	for(i=0 ; i<tam ; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d",&listaNumeros[i]);
	}
	//las funciones no pueden devolver un vector, no hay return
}

void MostrarVector(int listaNumeros[],int tam)
{
	int i;

	for(i=0; i<tam ; i++)
	{
		printf("%d\n",listaNumeros[i]);
	}
}

void SumarNumeros(int listaNumeros[],int tam)
{
	int i;
	int acumulador;
	acumulador = 0;
	for(i=0; i<tam ; i++)
	{
	 acumulador = acumulador + listaNumeros[i];
	}
	printf("La suma es: %d\n", acumulador);
}

void PedirCadena(char cadena[],int tam, char mensaje[])
{
	char auxString[1000];//buffer que me permita desvordarlo para despues comprobar

	printf(mensaje);
	fflush(stdin);
	gets(auxString);

	//validar el largo de la cadena con strnlen (cantidad de caracteres que encuentra hasta el /0)
	while(strlen(auxString) > tam-1)
	{
		printf("reingrese : ");
		fflush(stdin);
		gets(auxString);
	}
	strncpy(cadena,auxString,24);
}

/*int getFloat(char mensaje[],float *pflotante,int tam)
{
	int retorno = -1;
	char bufferFloat[64];

	printf("%s",mensaje);
	if(pflotante != NULL)
	{
		fflush(stdin);
		if(getString(bufferFloat, sizeof(bufferFloat)) == 0 && validarDecimal(bufferFloat, sizeof(bufferFloat)))
		{
			*pflotante = atof(bufferFloat);
			retorno = 0;
		}
	}

	return retorno;
}*/



int MenuPrincipal (void)
{
	int opciones;

	printf(" 1)ALTA CLIENTE\n 2)BAJA CLIENTE\n 3)MODIFICAR DATOS CLIENTE\n 4)Crear Pedido de Recoleccion\n 5)Procesar Residuos\n"
	" 6)Imprimir Clientes\n 7)Imprimir Pedidos Pendientes\n 8)Imprimir Pedidos Procesados\n"
	" 9)Pedidos Pendientes Por Localidad\n 10)Cantidad de kilos de Polipropileno Reciclado Promedio por Cliente\n 11)SALIR\n Ingrese una opcion: ");

	scanf("%d",&opciones);
	return opciones;
}

float PedirFlotante(char mensaje[])
{
	int unFlotante;

	printf("%s\n",mensaje);
	scanf("%d", &unFlotante);

	return unFlotante;
}
