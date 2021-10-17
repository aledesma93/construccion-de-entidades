/*
 * harcodeo.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Ludo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "harcodeo.h"

#include "cliente.h"




int cuit[10] = {141,132,555,666,777,455,735,123,567};
char nombreEmpresa[10][14] =
{
    {"IKEA"},
    {"CANON"},
    {"LEGO"},
    {"SONY"},
    {"HAAGEN DASZ"},
    {"WD-40"},
    {"YAHOO"},
    {"PEPSI"},
    {"GOOGLE"},
    {"BLACKBERRY"},
};

char direccion[10][18] =
{
    {"Riobamba 5525"},
    {"Meeks 414"},
    {"Yrigoyen 956"},
    {"Frias 5963"},
    {"Latarico 1697"},
    {"Sucre 2000"},
    {"Garibaldi 132"},
    {"Oliden 331"},
    {"Vieytes 453"},
    {"Veracruz 1002"},
};

char localidades[10][24] =
{
    {"TEMPERLEY"},
    {"TEMPERLEY"},
    {"LOMAS DE ZAMORA"},
    {"BANFIELD"},
    {"BANDIELD"},
    {"LOMAS DE ZAMORA"},
    {"LOMAS DE ZAMORA"},
    {"LOMAS DE ZAMORA"},
    {"LOMAS DE ZAMORA"},
    {"LANUS"},
};



int hardcorearClientes(eCliente lista[],int tam, int cantCargar, int* pIdC)
{
    int cantidad = 0;

    if(lista!= NULL && cantCargar > 0 && cantCargar <= tam && pIdC != NULL)
    {
        for(int i=0; i<cantCargar; i++)
        {
            lista[i].id = (*pIdC);
            strcpy(lista[i].NombreEmpresa, nombreEmpresa[i]);
            strcpy(lista[i].direccion, direccion[i]);
            strcpy(lista[i].localidad, localidades[i]);
            lista[i].cuit = cuit[i];
            lista[i].isEmpty = OCUPADO;
            (*pIdC)++;
             cantidad++;
        }
    }
    return cantidad;
}


