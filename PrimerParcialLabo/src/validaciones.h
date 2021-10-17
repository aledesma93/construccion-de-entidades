/*
 * validaciones.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Ludo
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"

int get_myGets(char* pResultado, int len);
int get_int(int* pResultado,int len,char* mensaje,char* mensajeError,int minimo, int maximo, int reintentos,int flagSigned);
int IngresarEntero(char[]);
int PedirEntero(void);
int PedirEntero2(char mensaje[],int,int);
int myGets (char* cadena,char mensaje[], int longitud);
int getString(char* cadena, int limite);
void mostrarNumero(float); //prototipo, lo que yo quiero utilizar,
void CargarVector(int listaNumeros[],int); //void porq la funcion no puede devolver un vector
void MostrarVector(int [],int);
void SumarNumeros(int[],int);
void PedirCadena(char cadena[], int tam, char mensaje[]);
//int getFloat(char mensaje[],float *pflotante,int tam);
float PedirFlotante(char mensaje[]);
int MenuPrincipal (void);

#endif /* VALIDACIONES_H_ */
