/*
 * producto.h
 *
 *  Created on: 11 may. 2021
 *      Author: ledes
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_
typedef struct
{
    int idProducto;
    char decripcion[51];
    int  idNacionalidad;
    int idTipo;
    float precio;

} producto;


producto* empleado_new(void);
producto* empleado_newParam(char* nombre,char* apellido,char* dni,int idEmpleado);

int producto_delete(producto* this);

int producto_setNombre(producto* this, char* nombre);
char* producto_getNombre(producto* this,int* flagError);
int isValidNombre(char*);

int producto_setApellido(producto* this,char* apellido);
char* producto_getApellido(producto* this,int* flagError);
int isValidApellido(char*);

int producto_setDni(producto* this,char* dni);
char* producto_getDni(producto* this,int* flagError);
int isValidDni(char*);

int producto_setId(producto* this,int idEmpleado);
int producto_getId(producto* this,int* flagError);
int isValidId(int);


#endif /* PRODUCTO_H_ */
