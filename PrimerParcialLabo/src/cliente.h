/*
 * cliente.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Ludo
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "pedido.h"

#define LIBRE 0
#define OCUPADO 1


typedef struct
{
  int id;
  char NombreEmpresa[50];
  int cuit;
  char direccion[50];
  char localidad [50];
  int isEmpty;
  int acumPedidos;

}eCliente;

int realizarPedido(ePedido* arrayPedido,int limite,int indice);
int ProcesarPedido(ePedido listaPedidos[],int tamPedido);
int InicializarListaProductos(eCliente listaClientes[],int tam);
int AltaCliente(eCliente listaClientes[],int tam,int*);
void MostrarUnCliente(eCliente unCliente);
int MostrarListadoClientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido);
int ModificarCliente(eCliente listaClientes[],int tam);
int BuscarCliente(eCliente listaClientes[],int tam);
int BajaCliente(eCliente listaClientes[],int tam);
int CrearPedidoRecoleccion (eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido,int* idPedidos);
void MostrarUnPedido(ePedido unPedido);
int MostrarListaPedidos(ePedido listaPedidos[],int tamPedidos);


#endif /* CLIENTE_H_ */
