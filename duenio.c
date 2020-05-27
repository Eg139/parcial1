#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gets.h"
#include "Validate.h"
#include "duenio.h"
#include "mascotas.h"


int InitDuenio(eDuenio listaDeDuenio[],int len)
{
    int i;
    int retorno=-1;
    for(i=0; i<len; i++)
    {
        listaDeDuenio[i].estado=LIBRE;
        retorno=0;
    }
    return retorno;
}


int BuscarDuenioLibre(eDuenio listaDeDuenio[],int len)
{
    int i;
    int retorno=-1;
    for(i=0; i<len; i++)
    {
        if(listaDeDuenio[i].estado==LIBRE)
        {
            retorno=i;
        }
    }
    return retorno;
}

int CargarDuenio(eDuenio listaDeDuenio[],int len,int cont)
{
    int index;
    int retorno=-1;
    index=BuscarDuenioLibre(listaDeDuenio,len);

    if(index!=-1)
    {
        GetString("Ingrese nombre del Duenio: ",listaDeDuenio[index].nombre,len);
        GetString("Ingrese apellido del Duenio: ",listaDeDuenio[index].apellido,len);
        do{
            GetString("Ingrese el sexo del Duenio HOMBRE o MUJER: ", listaDeDuenio[index].sexo, len);
        }while((strcmpi(listaDeDuenio[index].sexo, "HOMBRE" )!= 0) && (strcmpi(listaDeDuenio[index].sexo, "MUJER" )!= 0));

        listaDeDuenio[index].edad=GetInt("Ingrese edad del Duenio: ",len);
        listaDeDuenio[index].telefono=GetInt("Ingrese telefono del Duenio: ", len);
        listaDeDuenio[index].idDuenio=GenerarId(99,cont);
        listaDeDuenio[index].estado=OCUPADO;
        retorno=0;
    }
    return retorno;
}

void MostrarDuenios(eDuenio listaDeDuenio[],int len)
{
    int i;

    printf("IDDUENIO       NOMBRE         APELLIDO        SEXO       EDAD     TELEFONO\n");
    for(i=0; i<len; i++)
    {
        if(listaDeDuenio[i].estado==OCUPADO)
        {
            printf("%4d %15s %15s %15s\t %4d \t%4d\n",listaDeDuenio[i].idDuenio,
                                                        listaDeDuenio[i].nombre,
                                                        listaDeDuenio[i].apellido,
                                                        listaDeDuenio[i].sexo,
                                                        listaDeDuenio[i].edad,
                                                        listaDeDuenio[i].telefono);

        }
    }
}

void hardCodearDuenio(eDuenio listadoDeDuenio[])
{

char nombre[5][20] ={"COKI","JUAN","RICARDO","PATY","ZONI"};
char apellido[5][20]={"Argento","Gonzalez","Guitierrez","Argento","Fuseneco"};
char sexo[5][8]={"HOMBRE","HOMBRE","HOMBRE","MUJER","MUJER"};
int edad[5]={44,5,20,18,10};
int telefono[5]={1169541747, 1154879298, 115102098, 1153019298, 1154719298};
int idDuenio[5]= {100, 101,102,103,104};
int i;
  for(i=0; i<5; i++)
  {
      listadoDeDuenio[i].idDuenio = idDuenio[i];
      strcpy(listadoDeDuenio[i].nombre,nombre[i]);
      strcpy(listadoDeDuenio[i].apellido, apellido[i]);
      strcpy(listadoDeDuenio[i].sexo, sexo[i]);
      listadoDeDuenio[i].edad= edad[i];
      listadoDeDuenio[i].telefono = telefono[i];
      listadoDeDuenio[i].estado = OCUPADO;

  }
}


void modificarDuenio(eDuenio listadoDeDuenios[], int len)
{
    int posicion;
    int id;
    int eleccion = 0;
    int i;

    printf("Ingrese el id del duenio a modificar: ");
    scanf("%d", &id);
    do{
            printf("MODIFICAR: \n");
            eleccion = GetOption("1. Nombre\n2. Apellido\n3. Sexo\n4.Edad\n5. Telefono\n6.SALIR\nElija una opcion: ");

            for(i = 0; i< len; i++)
              {
              if(id == listadoDeDuenios[i].idDuenio)
                {
                   posicion = i;
                   break;
                }
              }
     switch(eleccion)
      {
          case 1:
                    GetString("Reingrese el nombre del duenio: ",listadoDeDuenios[posicion].nombre,len);
            break;

          case 2:
                GetString("Reingrese el apellido del duenio: ",listadoDeDuenios[posicion].apellido,len);
            break;

          case 3:
                do{
                    GetString("Reingrese el sexo del Duenio HOMBRE o MUJER: ", listadoDeDuenios[posicion].sexo, len);
                }while((strcmpi(listadoDeDuenios[posicion].sexo, "HOMBRE" )!= 0) && (strcmpi(listadoDeDuenios[posicion].sexo, "MUJER" )!= 0));
            break;

          case 4:
                listadoDeDuenios[posicion].edad=GetInt("Reingrese edad del Duenio: ",len);

            break;
          case 5:
              listadoDeDuenios[posicion].telefono=GetInt("Reingrese telefono del Duenio: ", len);
            break;
          case 6:
            break;
      }
      system("cls");
    }while(eleccion != 6);


}


int promedioHombresMujeres(eDuenio listadoDeDuenios[], int len)
{
    int i;
    int acumuladorHombres = 0;
    int acumuladorMujeres = 0;
    int contador = 0;
    float porcentajeMujeres;

    int index = -1;
    for(i=0; i<len; i++)
    {
        if((strcmpi(listadoDeDuenios[i].sexo, "HOMBRE") == 0) && (listadoDeDuenios[i].estado == OCUPADO))
        {
            acumuladorHombres++;
            index = 1;
            contador++;
        }
        else
        {
           if((strcmpi(listadoDeDuenios[i].sexo, "MUJER") == 0) && (listadoDeDuenios[i].estado == OCUPADO))
        {
            acumuladorMujeres++;
            contador++;
        }
        }
    }

    porcentajeMujeres = (float)acumuladorMujeres/contador*100;
    printf("En total hay %d duenios de mascotas \n", contador);
    printf("El porcentaje de  mujeres es: %.2f%%\n", porcentajeMujeres);


    return index;
}
