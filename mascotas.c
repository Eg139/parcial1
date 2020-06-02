#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gets.h"
#include "Validate.h"
#include "mascotas.h"
#include "duenio.h"





int InitMascota(eMascota listaDeMascota[],int len)
{
    int i;
    int retorno=-1;
    for(i=0; i<len; i++)
    {
        listaDeMascota[i].estadoMascota=LIBRE;
        retorno=0;
    }
    return retorno;
}


int BuscarMascotaLibre(eMascota listaDeMascota[],int len)
{
    int i;
    int retorno=-1;
    for(i=0; i<len; i++)
    {
        if(listaDeMascota[i].estadoMascota==LIBRE)
        {
            retorno=i;
        }
    }
    return retorno;
}




void hardCodearMascota(eMascota listadoDeMascotas[])
{
int i;
char nombre[11][20] ={"Nala","Charlie","Mimi","bigotes","Mancha","carla","roy","clara","yema","rabiol", "escamas"};
char tipo[11][20]={"GATO","GATO","GATO","GATO","GATO","Perro","Perro","Perro","Perro","Perro","Raro"};
char sexo[11][7]={"HEMBRA","HEMBRA","MACHO","MACHO","MACHO","MACHO","MACHO","MACHO","MACHO","MACHO","MACHO"};
int edad[11]={4,5,2,7,4,8,10,1,2,3,5};
float peso[11]={5.2,6.7,3.2,4.7,7.2,10.7,5.9,6.1,15.2,2.7,3.2};
int idRaza[11] = {8,10,9,8,9,3,4,5,1,2,6};
int idMascota[11]={1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
int idDuenio[11] = {103, 103,100,102,102,104,101,102,100,100,104};

  for(i=0; i<11; i++)
  {
      listadoDeMascotas[i].idMascota = idMascota[i];
      strcpy(listadoDeMascotas[i].nombre,nombre[i]);
      strcpy(listadoDeMascotas[i].tipo, tipo[i]);
      strcpy(listadoDeMascotas[i].sexo, sexo[i]);
      listadoDeMascotas[i].edad= edad[i];
      listadoDeMascotas[i].idRaza = idRaza[i];
      listadoDeMascotas[i].peso= peso[i];
      listadoDeMascotas[i].idDuenio = idDuenio[i];
      listadoDeMascotas[i].estadoMascota=OCUPADO;
  }
}


int promedioEdadMascotas(eMascota listaDeMascotas[],int sizeMascotas)
{
    int i;
    int contador = 0;
    int index = -1;
    int acumulador = 0;
    float promedioEdadMascotas;
    printf("********************************************\n");
    printf(">    PROMEDIO DE LA EDAD DE LAS MASCOTAS   <\n");
    printf("********************************************\n");

    for(i=0;i<sizeMascotas;i++)
    {
        if(listaDeMascotas[i].estadoMascota == OCUPADO)
        {
            acumulador = acumulador + listaDeMascotas[i].edad;
            contador++;
            index = 1;
        }
    }
    promedioEdadMascotas = (float)acumulador/contador;
    printf("El promedio de las edades de todas las mascotas es: %.2f\n", promedioEdadMascotas);


    return index;
}


int promedioMascotasTipo(eMascota listaDeMascotas[],int sizeMascotas)
{
    printf("*****************************************************\n");
    printf("*    PROMEDIO DE EDAD DE LA MASCOTA SEGUN SU TIPO   *\n");
    printf("*****************************************************\n");
    int i;
    int acumulador = 0;
    int contador = 0;
    float promedio;
    int index = -1;
    char tipo[20];
    GetString("elija el tipo de mascota quiere mostrar (PERRO, GATO, RARO): ", tipo, sizeMascotas);
    while((strcmpi(tipo, "Perro" ) != 0) && (strcmpi(tipo, "Gato" ) != 0) && (strcmpi(tipo, "Raro" ) != 0))
    {
        GetString("elija un tipo de mascota valido (PERRO, GATO, RARO): ", tipo, sizeMascotas);
    }
    for(i=0; i<sizeMascotas; i++)
    {
        if((strcmpi(listaDeMascotas[i].tipo,tipo ) == 0)&& (listaDeMascotas[i].estadoMascota == OCUPADO))
        {
            acumulador = acumulador + listaDeMascotas[i].edad;
            contador++;
            index = 1;
        }
    }
    promedio = (float)acumulador/contador;
    printf("El promedio de las edades de todas las mascotas es: %.2f\n", promedio);


    return index;
}


void mostrarMascotasSexo(eMascota listaDeMascotas[],int sizeMascotas)
{
    int i;
    char tipo[20];
    GetString("elija el sexo de la mascota que desea mostrar(MACHO, HEMBRA): ", tipo, sizeMascotas);
    while((strcmpi(tipo, "MACHO" ) != 0) && (strcmpi(tipo, "HEMBRA" ) != 0))
    {
        GetString("elija un sexo valido de la mascota que desea mostrar(MACHO, HEMBRA): ", tipo, sizeMascotas);
    }
    printf("IDMASCOTA       NOMBRE          TIPO    \tSEXO  \tEDAD     PESO\n");
    for(i=0; i<sizeMascotas; i++)
    {
        if((strcmpi(listaDeMascotas[i].sexo,tipo ) == 0)&& (listaDeMascotas[i].estadoMascota == OCUPADO))
        {
            printf("%4d %15s %15s  %15s %4d \t%.2f\n",listaDeMascotas[i].idMascota,
                                                                listaDeMascotas[i].nombre,
                                                                listaDeMascotas[i].tipo,
                                                                listaDeMascotas[i].sexo,
                                                                listaDeMascotas[i].edad,
                                                                listaDeMascotas[i].peso);
        }
    }
}
