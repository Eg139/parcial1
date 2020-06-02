#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gets.h"
#include "Validate.h"
#include "raza.h"
#define LIBRE 0
#define OCUPADO 1

int InitRaza(eRaza listaDeRazas[],int len)
{
    int i;
    int retorno=-1;
    for(i=0; i<len; i++)
    {
        listaDeRazas[i].estado=LIBRE;
        retorno=0;
    }
    return retorno;
}
void hardcodearRaza(eRaza listadoDeRazas[])
{
    int i;
    int idRaza[10]={1,2,3,4,5,6,7,8,9,10};
    char Nombre[10][20]={"Pastor", "Aleman","pitbul","Labrador","Buldog","overo","Argentina","Gato","Persa","Siames"};
    char Pais[10][20]={"Holanda","ALEMANIA","ARGENTINA","INGLATERRA","ARGENTINA","INGLATERRA","ARGENTINA","INGLATERRA","ARGENTINA","ARGENTINA"};

    for(i=0; i<10; i++)
  {
      listadoDeRazas[i].idRaza = idRaza[i];
      strcpy(listadoDeRazas[i].Pais, Pais[i]);
      strcpy(listadoDeRazas[i].Nombre, Nombre[i]);
      listadoDeRazas[i].estado = OCUPADO;
  }
}
void mostrarRazas(eRaza listadoDeRazas[], int len)
{
    int i;
    printf("\nIDRAZA       NOMBRE         PAIS\n");
    for(i=0; i<len; i++)
    {
        if(listadoDeRazas[i].estado == OCUPADO)
        {
         printf("%4d %15s %15s\n",listadoDeRazas[i].idRaza,
                                    listadoDeRazas[i].Nombre,
                                    listadoDeRazas[i].Pais);
        }
    }
}
