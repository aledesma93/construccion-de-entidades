/*
 * pedido.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Ludo
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "cliente.h"

#define SINPEDIDO -1
#define PENDIENTE 0
#define COMPLETADO 1

typedef struct
{
	int idCliente;
	int idPedido;
	int CantidadHDPE;
	int CantidadLDPE;
	int CantidadPP;
	int TotalKilos;
	int isEmpty;

}ePedido;

int InicializarListaPedido(ePedido listaPedidos[],int tam);


#endif /* PEDIDO_H_ */

