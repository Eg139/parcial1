#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gets.h"
#include "Validate.h"
#define LIBRE 0
#define OCUPADO 1




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

void hardCodearMascota(eMascota listadoDeMascotas[]);

int promedioEdadMascotas(eMascota listaDeMascotas[],int sizeMascotas);
int promedioMascotasTipo(eMascota listaDeMascotas[],int sizeMascotas);
void mostrarMascotasSexo(eMascota listaDeMascotas[],int sizeMascotas);



#endif // MASCOTAS_H_INCLUDED
