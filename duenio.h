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

typedef struct
{
    int idLocalidad;
    char provincia[20];
    char descripcion[20];
    int codigoPostal;
    int estado;
}eLocalidad;


typedef struct{
char nombre[20];
char apellido[20];
int idLocalidad;
char sexo[10];
int edad;
int telefono;
int idDuenio;
int estado;
}eDuenio;

//void ordenarNombreDuenio_localidad(eDuenio listadoDuenio[], int sizeDuenio,eLocalidad listadoLocalidades[], int sizeLocalidades);
void hardCodearLocalidad(eLocalidad listadoDeLocalidades[]);
int InitLocalidad(eLocalidad listaLocales[],int len);
void mostrarLocalidades(eLocalidad listadoLocales[], int len);
void MostrarDueniosPorLocalidad(eDuenio listaDeDuenios[],int sizeDuenio, eLocalidad listaDeLocalidades[], int sizeLocalidades);

int InitDuenio(eDuenio listaDeDuenio[],int len);
int BuscarDuenioLibre(eDuenio listaDeDuenio[],int len);
int CargarDuenio(eDuenio listaDeDuenio[],int len,int cont, eLocalidad listadoLocalidades[],int sizeLocalidades);
void MostrarDuenios(eDuenio listaDeDuenio[],int len, eLocalidad listaDeLocalidades[],int sizeLocalidad);
void hardCodearDuenio(eDuenio listadoDeDuenio[]);
void modificarDuenio(eDuenio listadoDeDuenios[], int len);
int porcentajeMujeres(eDuenio listadoDeDuenios[], int len);

void menuIndex();

void ordenarLocalidadNombre(eDuenio listadoDuenio[], int sizeDuenio);

#endif // CLIENTE_H_INCLUDED
