/*
 * cliente.c
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



int InicializarListaProductos(eCliente listaClientes[],int tam) //todos los espacios de la lista comienzan vacios
{
	int retorno;
	retorno = 0;

	if(listaClientes != NULL && tam > 0)
	{
		for(int i=0 ; i<tam; i++ )
		{
			listaClientes[i].isEmpty= LIBRE;
			retorno = 1;
		}
	}
	return retorno;
}

int AltaCliente(eCliente listaClientes[],int tam,int* idAutomatico) // CARGO EL ARRAY CON LOS DATOS DE LA ESTRUCTURA
{
	int retorno;
	int auxId;
	auxId = *idAutomatico;
	retorno = 0;

	if(listaClientes != NULL && tam > 0)
	{
		for(int i=0 ; i<tam; i++ )
		{
			if(listaClientes[i].isEmpty == LIBRE )
			{
				listaClientes[i].id = auxId;
				myGets(listaClientes[i].NombreEmpresa,"Ingrese nombre de la empresa: \n",sizeof(listaClientes[i].NombreEmpresa));
				listaClientes[i].cuit = IngresarEntero("Ingrese nro de Cuit: \n");
				myGets(listaClientes[i].direccion,"Ingrese direccion de la empresa: \n",sizeof(listaClientes[i].direccion));
				myGets(listaClientes[i].localidad,"Ingrese localidad de la empresa: \n",sizeof(listaClientes[i].localidad));
				listaClientes[i].isEmpty = OCUPADO;

				auxId++;
				*idAutomatico = auxId;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

void MostrarUnCliente(eCliente unCliente)
{
  printf("%4d   %10s       %10d  %15s %15s %15d \t\n",unCliente.id,unCliente.NombreEmpresa, unCliente.cuit,unCliente.direccion, unCliente.localidad, unCliente.acumPedidos);
}
void MostrarUnPedido(ePedido unPedido)
{
	printf("%4d  %10d   \t\n",unPedido.idPedido,unPedido.TotalKilos);//acumulador en pendientes
}

int MostrarListaPedidos(ePedido listaPedidos[],int tamPedidos)
{
	int retorno;
	retorno = 0;
	if(listaPedidos != NULL && tamPedidos >0)
	{
		for(int i=0 ; i< tamPedidos; i++)
		{
			MostrarUnPedido(listaPedidos[i]);
			retorno = 1;
		}
	}
	return retorno;
}

int MostrarListadoClientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido)
{
    int retorno;
    retorno = 0;

    printf("ID CLIENTE   NOMBRE EMPRESA   CUIT      DIRECCION         LOCALIDAD       CANTIDAD EN ESTADO PENDIENTE \t \n");

    if(listaClientes != NULL && tamCliente > 0)
    {	for(int i=0; i<tamCliente ; i++)
    	{
    		if(listaClientes[i].isEmpty == OCUPADO)
    		{
    			MostrarUnCliente(listaClientes[i]);
    			retorno = 1;
    		}
    	}
    }
    return retorno;
}

int ModificarCliente(eCliente listaClientes[],int tam)//busco un producto por su id modifico direccion y localidad
{
	int idBuscado;
	int subMenu;
	int retorno;
	retorno = 0;

	if(listaClientes != NULL && tam > 0)
	{
		//MostrarListadoClientes(listaClientes,tam);
		idBuscado = IngresarEntero("Ingrese id del cliente \n");

		for(int i=0; i<tam; i++)//buscar dato
		{
			if(listaClientes[i].isEmpty == OCUPADO && listaClientes[i].id == idBuscado)
			{
				printf("1)Modificar direccion\n 2)Modificar localidad\n");
				subMenu =  IngresarEntero("Ingrese opcion\n");
				switch(subMenu)
				{
				   case 1:
					   myGets(listaClientes[i].direccion,"Ingrese direccion de la empresa: \n",sizeof(listaClientes[i].direccion));
				       break;
				   case 2:
					   myGets(listaClientes[i].localidad,"Ingrese localidad de la empresa: \n",sizeof(listaClientes[i].localidad));
				       break;
				   default:
					   printf("Opcion erronea\n");
					   break;
				 }
				 retorno = 1;
				 break;
			}
		}
	}
	return retorno;
}

int BajaCliente(eCliente listaClientes[],int tam) //Se ingresa el ID del cliente. Luego se preguntará si se quiere confirmar la eliminación.
{
	int idBuscado;
	int retorno;
	char respuesta;
	retorno = 0;

	if(listaClientes != NULL && tam > 0)
	{
		idBuscado = BuscarCliente(listaClientes,tam);
		if(idBuscado != -1)
		{
			MostrarUnCliente(listaClientes[idBuscado]);
			printf("Desea eliminar este cliente: s/n");
			fflush(stdin);
			scanf("%c",&respuesta);
			if(respuesta == 's')
			{
				listaClientes[idBuscado].isEmpty = LIBRE;
				retorno = 1;
			}
		}
	}
	return retorno;
}

int BuscarCliente(eCliente listaClientes[],int tam)
{
	int idBuscado;
	int indiceCliente;
	indiceCliente = -1;

	//MostrarListadoClientes(listaClientes,tam);

	idBuscado = IngresarEntero("Ingrese id de cliente que desea buscar");
	for(int i=0; i<tam; i++)
	{
		if(listaClientes[i].isEmpty == OCUPADO && listaClientes[i].id == idBuscado)
		{
			indiceCliente = i;
			break;
		}
	}
	return indiceCliente;
}

/*4) Crear pedido de recolección: Se imprimirán los clientes por pantalla y se pedirá que se ingrese el ID de un cliente
 existente y la cantidad de kilos totales que se recolectarán del cliente. Se generará un ID para el pedido y el mismo
 quedará en estado “Pendiente” hasta que se obtengan los residuos del cliente y se trasladen a la empresa.*/

int CrearPedidoRecoleccion (eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido,int* idPedidos)
{
	int indiceCliente;
	int retorno;
	int auxId;
	auxId = *idPedidos;
	retorno = 0;


	if(listaClientes != NULL && tamCliente > 0 && listaPedidos != NULL && tamPedido>0)
	{
		//MostrarListadoClientes(listaClientes,tamCliente);
		indiceCliente = BuscarCliente(listaClientes,tamCliente);
		int auxCantidad=0;

		if(indiceCliente != -1) //ya estoy trabajando en ese cliente porq trabajo en ese indice
		{
			for(int i = 0; i< tamPedido; i++)
			{
				if(listaPedidos[i].isEmpty == SINPEDIDO)
				{
					listaPedidos[i].idPedido = auxId;
					listaPedidos[i].TotalKilos = IngresarEntero("Ingrese cantidad de kilos totales:  \n");
					listaPedidos[i].isEmpty = PENDIENTE;
					listaPedidos[i].idCliente = listaClientes[indiceCliente].id;
					auxId++;
					*idPedidos = auxId;
					retorno = 1;
					auxCantidad=listaClientes[indiceCliente].acumPedidos;
					auxCantidad++;
					listaClientes[indiceCliente].acumPedidos=auxCantidad;
					break;

				}
			}
		}

	}
	return retorno;
}
int ProcesarPedido(ePedido listaPedidos[],int tamPedido) //punto5
{
	int iPedido;
	int retorno;
	retorno = 0;
	iPedido = BuscarPedido(listaPedidos,tamPedido);

	if(listaPedidos != NULL && tamPedido >0 && iPedido!= -1)
	{
		for(int i = 0; i<tamPedido; i++)
		{
			if(listaPedidos[i].isEmpty == PENDIENTE)
			{
				listaPedidos[iPedido].isEmpty = COMPLETADO;
				listaPedidos[iPedido].CantidadPP = listaPedidos[iPedido].TotalKilos /3;
				listaPedidos[iPedido].CantidadLDPE = listaPedidos[iPedido].TotalKilos /3;
				listaPedidos[iPedido].CantidadHDPE = listaPedidos[iPedido].TotalKilos /3;
				retorno = 1;
				break;
			}

		}
	}
	return retorno;
}


int BuscarPedido(ePedido listaPedidos[],int tamPedido)
{
	int idBuscado;
	int indicePedido;
	indicePedido = -1;

	idBuscado = IngresarEntero("Ingrese id del pedido que desea buscar");
	for(int i=0; i<tamPedido; i++)
	{
		if(listaPedidos[i].isEmpty == PENDIENTE && listaPedidos[i].idPedido == idBuscado)
		{
			indicePedido = i;
			break;

		}
	}
	return indicePedido;
}

/*int AcumuladorPedidos(ePedido unCliente)
{


}
*/
/* int ProcesarPedido(listaPedidos[],int tamPedido) //punto5
 {

 }
*/
