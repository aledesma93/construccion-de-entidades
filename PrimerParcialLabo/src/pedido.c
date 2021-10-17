/*
 * pedido.c
 *
 *  Created on: 16 oct. 2021
 *      Author: Ludo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "cliente.h"
#include "pedido.h"

int InicializarListaPedido(ePedido listaPedidos[],int tam) //todos los espacios de la lista comienzan pendiente
{
	int retorno;
	retorno = 0;

	if(listaPedidos != NULL && tam > 0)
	{
		for(int i=0 ; i<tam; i++ )
		{
			listaPedidos[i].isEmpty= SINPEDIDO;
			retorno = 1;
		}
	}
	return retorno;
}

