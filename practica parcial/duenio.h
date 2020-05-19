#ifndef Duenio_H_INCLUDED
#define Duenio_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "Gets.h"
#include "Validate.h"
#define LIBRE 0
#define OCUPADO 1




typedef struct{
char nombre[20];
char apellido[20];
char sexo[10];
int edad;
int telefono;
int idDuenio;
int estado;
}eDuenio;

int InitDuenio(eDuenio listaDeDuenio[],int len);
int BuscarDuenioLibre(eDuenio listaDeDuenio[],int len);
int CargarDuenio(eDuenio listaDeDuenio[],int len,int cont);
void MostrarDuenios(eDuenio listaDeDuenio[],int len);
void hardCodearDuenio(eDuenio listadoDeDuenio[]);
void modificarDuenio(eDuenio listadoDeDuenios[], int len);
int promedioHombresMujeres(eDuenio listadoDeDuenios[], int len);



#endif // CLIENTE_H_INCLUDED
