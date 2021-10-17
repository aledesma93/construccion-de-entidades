/*
 ============================================================================
 Name        : PrimerParcialLabo.c
 Author      : Ludmila
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "cliente.h"
#include "harcodeo.h"
#include "pedido.h"

#define TAM_CLIENTE 11
#define TAM_PEDIDO 100

int main(void)
{
	setbuf(stdout,NULL);

	char salir;
	salir = 'n';
	int idAutomatico;
	int idPedidos;
	idPedidos = 1;
	idAutomatico = 1;

	eCliente listaClientes[TAM_CLIENTE];
	ePedido listaPedidos[TAM_PEDIDO];
	InicializarListaProductos(listaClientes,TAM_CLIENTE);
	InicializarListaPedido(listaPedidos,TAM_PEDIDO);
	hardcorearClientes(listaClientes,TAM_CLIENTE,10,&idAutomatico);

		do
		{
			switch(MenuPrincipal())
			{
				case 1://ALTA
					if(AltaCliente(listaClientes,TAM_CLIENTE,&idAutomatico))
					{
					  printf("Carga exitosa\n");
					}
					else
					{
						printf("No se puede agregar cliente, lista llena \n");
					}
					break;
				case 2://MODIFICACION
					if(ModificarCliente(listaClientes,TAM_CLIENTE))
					{
						printf("Modificacion exitosa\n");
					}
					else
					{
						printf("No se pudo modificar\n");
					}
					break;
				case 3: //BAJA
					if(BajaCliente(listaClientes,TAM_CLIENTE))
					{
						printf("Baja de cliente exitosa\n");
					}
					else
					{
						printf("No se realizo la baja\n");
					}
					break;
				case 4: //CREAR PEDIDO DE RECOLECCION
					if(CrearPedidoRecoleccion (listaClientes,TAM_CLIENTE,listaPedidos,TAM_PEDIDO,&idPedidos))
					{
						printf("Su pedido ha pasado a pendiente\n");
					}
					else
					{
						printf("No se realizo el pedido\n");
					}
					break;
				case 5://Procesar Residuos

					MostrarListaPedidos(listaPedidos,TAM_PEDIDO);
					if(ProcesarPedido(listaPedidos,TAM_PEDIDO)){
						printf("su pedido ha pasado a completado\n");
					}
					else{
						printf("no se proceso el pedido \n");
					}

					break;
				case 6: //MOSTRAR CLIENTES
				if(MostrarListadoClientes(listaClientes,TAM_CLIENTE,listaPedidos,TAM_PEDIDO))
				{
					printf("Listado mostrado correctamente \n");
				}
				else
				{
					printf("Lista vacia\n");
				}
					break;
				case 7:

					break;
				case 8:

					break;
				case 9:

					break;
				case 10:
					break;
				case 11:
					printf("Confirma salida s/n: \n");
					fflush(stdin);
					scanf("%c",&salir);
					break;
				default:
					printf("Error,opcion invalida \n");
			}

		}while(salir != 's');





































	return EXIT_SUCCESS;



}
