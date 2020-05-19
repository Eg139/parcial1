#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gets.h"
#include "Validate.h"
#include "mascotas.h"
#include "duenio.h"

void hardcodearRaza(eRaza listadoDeRazas[])
{
    int i;
    int idRaza[10]={1,2,3,4,5,6,7,8,9,10};
    char Nombre[10][20]={"{Pastor", "Aleman","pitbul","Labrador","Buldog}","{lagarto overo","Argentina}","{Gato, Persa}"};
    char Pais[10][20]={"Holanda","ALEMANIA","ARGENTINA","INGLATERRA","ARGENTINA","INGLATERRA","ARGENTINA","INGLATERRA","ARGENTINA","ARGENTINA"};

    for(i=0; i<11; i++)
  {
      listadoDeRazas[i].idRaza = idRaza[i];
      strcpy(listadoDeRazas[i].Pais, Pais[i]);
      strcpy(listadoDeRazas[i].Nombre, Nombre[i]);
  }
}

void mostrarRazas(eRaza listadoDeRazas[], int len)
{
    int i;
    printf("IDRAZA       NOMBRE         PAIS\n");
    for(i=0; i<len; i++)
    {
            printf("%4d %15s %15s\n",listadoDeRazas[i].idRaza,
                                    listadoDeRazas[i].Nombre,
                                    listadoDeRazas[i].Pais);
    }
}


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
eRaza getRaza(void)
{
    eRaza unaRaza;
    printf("Ingrese el idRaza: ");
    scanf("%d", &unaRaza.idRaza);
    printf("Ingrese Nombre: ");
    gets(unaRaza.Nombre);
    printf("Ingrese el pais: ");
    gets(unaRaza.Pais);
    return unaRaza;
}

int CargarMascota(eMascota listaDeMascota[],int len,int cont)
{
    int index;
    int retorno=-1;
    index=BuscarMascotaLibre(listaDeMascota,len);

    if(index!=-1)
    {
        listaDeMascota[index].idDuenio = GetInt("Ingrese el Id del dunio que eligio: ", len);
        GetString("Ingrese nombre de la Mascota: ",listaDeMascota[index].nombre,len);
        GetString("Ingrese tipo de la Mascota (Perro, Gato, Raro): ",listaDeMascota[index].tipo,len);
        do{
            GetString("Ingrese el sexo de la mascota MACHO o HEMBRA: ", listaDeMascota[index].sexo, len);
        }while((strcmpi(listaDeMascota[index].sexo, "MACHO" )!= 0) && (strcmpi(listaDeMascota[index].sexo, "HEMBRA" )!= 0));
        listaDeMascota[index].edad=GetInt("Ingrese edad de la Mascota: ",len);
        listaDeMascota[index].peso=GetFloat("Ingrese el peso de la mascota: ");
        listaDeMascota[index].idMascota=GenerarId(999,cont);
        listaDeMascota[index].estadoMascota=OCUPADO;
        retorno=0;
    }
    return retorno;
}

void hardCodearMascota(eMascota listadoDeMascotas[])
{
int i;
char nombre[11][20] ={"Nala","Charlie","Mimi","bigotes","Mancha","carla","roy","clara","yema","rabiol", "escamas"};
char tipo[11][20]={"Gato","Gato","Gato","Gato","Gato","Perro","Perro","Perro","Perro","Perro","Raro"};
//eRaza raza[11][20]={{1,"Persa","HOLANDA"},{1,"Persa","HOLANDA"},{1,"Persa","HOLANDA"},{1,"Persa","HOLANDA"},{1,"Gato","HOLANDA"},{2,"pitbul","ALEMANIA"},{3,"Labrador","Inglaterra"},{4,"Buldog","HOLANDA"},{4,"Buldog","HOLANDA"},{4,"Buldog","HOLANDA"},{3,"Lagarto overo","Alemania"}};
char sexo[11][7]={"HEMBRA","HEMBRA","MACHO","MACHO","MACHO","MACHO","MACHO","MACHO","MACHO","MACHO","MACHO"};
int edad[11]={4,5,2,7,4,8,10,1,2,3,5};
float peso[11]={5.2,6.7,3.2,4.7,7.2,10.7,5.9,6.1,15.2,2.7,3.2};
int idMascota[11]={1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
int idDuenio[11] = {103, 103,100,102,102,104,101,102,100,100,104};

  for(i=0; i<11; i++)
  {
      listadoDeMascotas[i].idMascota = idMascota[i];
      strcpy(listadoDeMascotas[i].nombre,nombre[i]);
      strcpy(listadoDeMascotas[i].tipo, tipo[i]);
      //strcpy(listadoDeMascotas[i].raza, raza[i]);
      strcpy(listadoDeMascotas[i].sexo, sexo[i]);
      listadoDeMascotas[i].edad= edad[i];
      listadoDeMascotas[i].peso= peso[i];
      listadoDeMascotas[i].idDuenio = idDuenio[i];
      listadoDeMascotas[i].estadoMascota=OCUPADO;
  }
}

void mostrarMascotasTipo(eMascota listaDeMascotas[],int sizeMascotas)
{
    int i;
    char tipo[20];
    GetString("elija el tipo de mascota quiere mostrar (PERRO, GATO, RARO): ", tipo, sizeMascotas);
    while((strcmpi(tipo, "Perro" ) != 0) && (strcmpi(tipo, "Gato" ) != 0) && (strcmpi(tipo, "Raro" ) != 0))
    {
        GetString("elija un tipo de mascota valido (PERRO, GATO, RARO): ", tipo, sizeMascotas);
    }
    printf("IDMASCOTA       NOMBRE          TIPO           RAZA            SEXO     EDAD      PESO\n");
    for(i=0; i<sizeMascotas; i++)
    {
        if((strcmpi(listaDeMascotas[i].tipo,tipo ) == 0)&& (listaDeMascotas[i].estadoMascota == OCUPADO))
        {
            printf("%4d %15s %15s  %15s %4d \t%.2f\n",listaDeMascotas[i].idMascota,
                                                                listaDeMascotas[i].nombre,
                                                                listaDeMascotas[i].tipo,
                                                                //listaDeMascotas[i].raza.idRaza,
                                                                //listaDeMascotas[i].raza.Nombre,
                                                                //listaDeMascotas[i].raza.Pais,
                                                                listaDeMascotas[i].sexo,
                                                                listaDeMascotas[i].edad,
                                                                listaDeMascotas[i].peso);
        }
    }
}
int promedioEdadMascotas(eMascota listaDeMascotas[],int sizeMascotas)
{
    int i;
    int contador = 0;
    int index = -1;
    int acumulador = 0;
    float promedioEdadMascotas;

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


