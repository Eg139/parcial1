#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gets.h"
#include "Validate.h"
#define LIBRE 0
#define OCUPADO 1
typedef struct
{
    int idRaza;
    char Nombre[20];
    char Pais[20];
}eRaza;


typedef struct{
char nombre[15];
char tipo[15];
eRaza raza[15];
char sexo[10];
int edad;
float peso;
int idMascota;
int idDuenio;
int estadoMascota;
}eMascota;

int InitMascota(eMascota listaDeMascota[],int len);
int BuscarMascotaLibre(eMascota listaDeMascota[],int len);
int CargarMascota(eMascota listaDeMascota[],int len,int cont);
void hardCodearMascota(eMascota listadoDeMascotas[]);
void mostrarMascotasTipo(eMascota listaDeMascotas[],int sizeMascotas);
int promedioEdadMascotas(eMascota listaDeMascotas[],int sizeMascotas);
int promedioMascotasTipo(eMascota listaDeMascotas[],int sizeMascotas);


void hardcodearRaza(eRaza listadoDeRazas[]);
void mostrarRazas(eRaza listadoDeRazas[], int len);
eMascota getMascota(void);

#endif // MASCOTAS_H_INCLUDED
