/*
 * producto.c
 *
 *  Created on: 11 may. 2021
 *      Author: ledes
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"

producto* producto_new(void)
{

	return (producto*) malloc(sizeof(producto));
}


producto* producto_newParam(char* decripcion,int* idTipo,
		int* idNacionalidad,float* precio,int* idProducto)
{
	producto* auxproducto = producto_new();
	if(auxproducto != NULL)
	{
		if  ( 	producto_setDescripcion(auxproducto,decripcion) < 0 ||
				producto_setIdProducto(auxproducto,idProducto) < 0 ||
				producto_setIdNacionalidad(auxproducto,idNacionalidad) < 0 ||
				producto_setidTipo(auxproducto,idTipo) < 0 ||
				producto_setPrecio(auxproducto,precio) < 0 )
		{
			producto_delete(auxproducto);
			auxproducto = NULL;
		}
	}
	return auxproducto;;
}

int producto_delete(producto* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

char producto_setdecripcion(producto* this, char* decripcion)
{
	int retorno = -1;
	if(this != NULL && decripcion != NULL && isValidDescripcion(decripcion) )
	{
		strcpy(this->decripcion,decripcion);
		retorno = 0;
	}
	return retorno;
}

char* producto_getdecripcion(producto* this,int* flagError)
{
	*flagError = -1;
	char* auxdecripcion= NULL;
	if(this != NULL && flagError != NULL )
	{
		auxdecripcion = this->decripcion;
		*flagError = 0;
	return auxdecripcion;
}

int isValidDescripcion(char* decripcion)
{
	return 1;
}

int producto_setidProducto(producto* this, int* idProducto)
{
	int retorno = -1;
	if(this != NULL && idProducto != NULL && isidProducto(idProducto) )
	{
		strcpy(this->idProducto,idProducto);
		retorno = 0;
	}
	return retorno;
}



int* producto_getidProducto(producto* this,int* flagError)
{
	*flagError = -1;
	char* aux= NULL;
	if(this != NULL && flagError != NULL )
	{
		aux = this->idProducto;
		*flagError = 0;
	}
	return aux;
}


int isValididProducto(char* idProducto)
{
	return 1;
}


int producto_setidNacionalidad(producto* this, int* idNacionalidad)
{
	int retorno = -1;
	if(this != NULL && idNacionalidad != NULL && isValididNacionalidad(idNacionalidad) )
	{
		strcpy(this->idNacionalidad,idNacionalidad);
		retorno = 0;
	}
	return retorno;
}



int* producto_getidNacionalidad(producto* this,int* flagError)
{
	*flagError = -1;
	char* aux= NULL;
	if(this != NULL && flagError != NULL )
	{
		aux = this->idNacionalidad;
		*flagError = 0;
	}
	return aux;
}



int isValiidNacionalidad(int* idNacionalidad)
{
	return 1;
}

int producto_setidTipo(producto* this, int idTipo)
{
	int retorno = -1;
	if(this != NULL && isValididTipo(idTipo) )
	{
		this->idTipo = idTipo;
		retorno = 0;
	}
	return retorno;
}



int producto_getidTipo(producto* this,int* flagError)
{
	*flagError = -1;
	int auxId = -1;
	if(this != NULL && flagError != NULL )
	{
		auxId=this->idTipo;
		*flagError = 0;
	}
	return auxId;
}

int isValididTipo(int idTipo)
{
	return 1;
}

int producto_setprecio(producto* this, int precio)
{
	int retorno = -1;
	if(this != NULL && isValidprecio(precio) )
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}



int producto_getprecio(producto* this,int* flagError)
{
	*flagError = -1;
	int auxprecio = -1;
	if(this != NULL && flagError != NULL )
	{
		auxprecio=this->precio;
		*flagError = 0;
	}
	return auxprecio;
}

int isValididprecio(int precio)
{
	return 1;
}



