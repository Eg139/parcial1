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
    int estado;
}eRaza;



typedef struct{
char nombre[15];
char tipo[15];
char sexo[10];
int edad;
float peso;
int idRaza;
int idMascota;
int idDuenio;
int estadoMascota;
}eMascota;

int InitMascota(eMascota listaDeMascota[],int len);
int BuscarMascotaLibre(eMascota listaDeMascota[],int len);
int CargarMascota(eMascota listaDeMascota[],int len, eRaza listaDeRazas[], int sizeRazas,int cont);
void hardCodearMascota(eMascota listadoDeMascotas[]);
void mostrarMascotasTipo(eMascota listaDeMascotas[],int sizeMascotas,eRaza listaDeRazas[], int sizeRaza);
int promedioEdadMascotas(eMascota listaDeMascotas[],int sizeMascotas);
int promedioMascotasTipo(eMascota listaDeMascotas[],int sizeMascotas);
void mostrarMascotasSexo(eMascota listaDeMascotas[],int sizeMascotas);

void hardcodearRaza(eRaza listadoDeRazas[]);
void mostrarRazas(eRaza listadoDeRazas[], int len);
eMascota getMascota(void);
int InitRaza(eRaza listaDeRazas[],int len);

#endif // MASCOTAS_H_INCLUDED
