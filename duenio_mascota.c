#include "duenio_mascota.h"

void MostrarDuenios_mascota(eMascota listaDeMascotas[], int sizeMascota, eDuenio listaDeDuenio[], int sizeDuenio)
{
    int i;//Duenio
    int j;//mascota
    int resMascotas=0;

    for(i=0; i<sizeDuenio; i++)
    {
        if(listaDeDuenio[i].estado == OCUPADO)
            {
        printf("*************************************Duenio: %s**************************\n",listaDeDuenio[i].nombre);
        printf("IDMASCOTA       NOMBRE          TIPO           RAZA          SEXO       EDAD     PESO\n");
        for(j=0; j<sizeMascota; j++)
        {
            if((listaDeMascotas[j].idDuenio == listaDeDuenio[i].idDuenio) && listaDeMascotas[j].estadoMascota==OCUPADO)
            {

                printf("%4d %15s %15s %15s %15s \t%4d \t%.2f\n",listaDeMascotas[j].idMascota,
                                                                listaDeMascotas[j].nombre,
                                                                listaDeMascotas[j].tipo,
                                                                listaDeMascotas[j].raza,
                                                                listaDeMascotas[j].sexo,
                                                                listaDeMascotas[j].edad,
                                                                listaDeMascotas[j].peso);
                resMascotas++;
            }
        }
        if(resMascotas==0)
        {
            printf("NO HAY MASCOTAS.\n\n");
        }

    }
    }

}
void mostrarMascotas(eMascota listaDeMascotas[],int sizeMascotas, eDuenio listaDeDuenio[], int sizeDuenio)
{
    int i;
    int j;
    printf("\nDUENIO      \tIDMASCOTA       NOMBRE          TIPO           RAZA            SEXO     EDAD      PESO\n");
    for(i=0; i<sizeMascotas; i++)
    {
            for(j = 0; j<sizeDuenio;j++)
            {
                if((listaDeMascotas[i].idDuenio == listaDeDuenio[j].idDuenio) && (listaDeMascotas[i].estadoMascota == OCUPADO) && (listaDeDuenio[j].estado== OCUPADO))
                {
                    printf("%s\t\t %4d %15s %15s %15s %15s %4d \t%.2f\n",listaDeDuenio[j].nombre,
                                                                        listaDeMascotas[i].idMascota,
                                                                        listaDeMascotas[i].nombre,
                                                                        listaDeMascotas[i].tipo,
                                                                        listaDeMascotas[i].raza,
                                                                        listaDeMascotas[i].sexo,
                                                                        listaDeMascotas[i].edad,
                                                                        listaDeMascotas[i].peso);
                }
            }

    }
}

void bajaMascota(eMascota listadoDeMascotas[], int len)
{
    int id;
    int i;
    printf("Ingrese el id: ");
    scanf("%d", &id);
    for(i = 0; i<len; i++)
    {
        if(id == listadoDeMascotas[i].idMascota)
        {
            listadoDeMascotas[i].estadoMascota = LIBRE;
            break;
        }
    }
}

void modificarMascota(eMascota listadoDeMascotas[], int len)
{
    int posicion;
    int id;
    int eleccion = 0;
    int i;

    printf("Ingrese el id del alumno a modificar: ");
    scanf("%d", &id);
    do{
            printf("MODIFICAR: \n");
            eleccion = GetOption("1. Nombre\n2. Tipo\n3. Raza\n4.Sexo\n5. Edad\n6. Peso\n7. SALIR\nElija una opcion: ");

            for(i = 0; i< len; i++)
              {
              if(id == listadoDeMascotas[i].idMascota)
                {
                   posicion = i;
                   break;
                }
              }
              system("cls");
     switch(eleccion)
      {
          case 1:
                    GetString("Reingrese nombre de la Mascota: ",listadoDeMascotas[posicion].nombre,len);
            break;

          case 2:
                GetString("Reingrese tipo de la Mascota (Perro, Gato, Raro): ",listadoDeMascotas[posicion].tipo,len);
            break;

          case 3:
                GetString("Reingrese raza de la Mascota: ", listadoDeMascotas[posicion].raza,len);
            break;

          case 4:
            do
            {
                GetString("Reingrese el sexo de la mascota MACHO o HEMBRA: ", listadoDeMascotas[posicion].sexo, len);
            }while((strcmpi(listadoDeMascotas[posicion].sexo, "MACHO" )!= 0) && (strcmpi(listadoDeMascotas[posicion].sexo, "HEMBRA" )!= 0));
            break;
          case 5:
              listadoDeMascotas[posicion].edad=GetInt("Reingrese edad de la Mascota: ",len);
            break;
          case 6:
                listadoDeMascotas[posicion].peso=GetFloat("Reingrese el peso de la mascota: ");
            break;
            case 7:
            break;
      }
    }while(eleccion != 7);

}


void bajaDuenio(eDuenio listadoDeDuenios[] ,int sizeDuenio, eMascota listadoDeMascotas[], int sizeMascotas)
{
    int i;
    int j;
    int id;

    printf("Indique el Id del Duenio que desea eliminar: ");
    scanf("%d", &id);


    for(i=0;i<sizeDuenio;i++)
    {
        if(id == listadoDeDuenios[i].idDuenio && listadoDeDuenios[i].estado == OCUPADO)
        {
            listadoDeDuenios[i].estado = LIBRE;

           for(j=0;j<sizeMascotas;j++)
           {
               if(listadoDeDuenios[i].estado==LIBRE && listadoDeDuenios[i].idDuenio == listadoDeMascotas[j].idDuenio)
               {
                   listadoDeMascotas[j].estadoMascota = LIBRE;
               }
           }
        }

    }
}

void ordenarMascotasPorTipo(eMascota listadoDeMascotas[], int len)
{
    int i;
    int j;
    eMascota auxMascota;

    for(i = 0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(strcmpi(listadoDeMascotas[i].tipo, listadoDeMascotas[j].tipo)>0)
            {
                auxMascota = listadoDeMascotas[i];
                listadoDeMascotas[i] = listadoDeMascotas[j];
                listadoDeMascotas[j] = auxMascota;
            }
        }
    }
}

void listarClientesConMasDeUnaMascota(eMascota listadoDeMascotas[], int sizeMascotas, eDuenio listadoDeDuenio[], int sizeDuenio)
{
    eDuenioMascota auxDuenio_mascota[sizeMascotas];
    int i;
    int j;

    for(i=0; i<sizeDuenio; i++)
    {
        auxDuenio_mascota[i].idDuenio = listadoDeDuenio[i].idDuenio;
        auxDuenio_mascota[i].cantMascota = 0;
    }

    for(i=0; i<sizeDuenio; i++)
    {
        for(j=0; j<sizeMascotas; j++)
        {
            if(listadoDeMascotas[j].estadoMascota==OCUPADO && auxDuenio_mascota[i].idDuenio == listadoDeMascotas[j].idDuenio)
            {
                auxDuenio_mascota[i].cantMascota++;
            }
        }
    }

     for(i=0;i<sizeDuenio; i++)
    {
        if(auxDuenio_mascota[i].cantMascota > 1 && listadoDeDuenio[i].estado == OCUPADO)
        {
            printf("IDDUENIO       NOMBRE         APELLIDO        SEXO       EDAD     TELEFONO\n");
               if(auxDuenio_mascota[i].idDuenio == listadoDeDuenio[i].idDuenio)
               {
                   printf("%4d %15s %15s %15s\t %4d \t%4d\n",listadoDeDuenio[i].idDuenio,
                                                        listadoDeDuenio[i].nombre,
                                                        listadoDeDuenio[i].apellido,
                                                        listadoDeDuenio[i].sexo,
                                                        listadoDeDuenio[i].edad,
                                                        listadoDeDuenio[i].telefono);
               }
        }
    }

}

void mostrarMascotasMayorTresAnios(eMascota listaDeMascotas[],int sizeMascotas, eDuenio listaDeDuenio[], int sizeDuenio)
{
    int i;
    int j;
    printf("\nDUENIO      \tIDMASCOTA       NOMBRE          TIPO           RAZA            SEXO     EDAD      PESO\n");
    for(i=0; i<sizeMascotas; i++)
    {
            for(j = 0; j<sizeDuenio;j++)
            {
                if((listaDeMascotas[i].idDuenio == listaDeDuenio[j].idDuenio) && (listaDeMascotas[i].estadoMascota == OCUPADO) && (listaDeDuenio[j].estado== OCUPADO)&&(listaDeMascotas[i].edad > 3))
                {
                    printf("\n%s\t\t %4d %15s %15s %15s %15s %4d \t%.2f\n",listaDeDuenio[j].nombre,
                                                                        listaDeMascotas[i].idMascota,
                                                                        listaDeMascotas[i].nombre,
                                                                        listaDeMascotas[i].tipo,
                                                                        listaDeMascotas[i].raza,
                                                                        listaDeMascotas[i].sexo,
                                                                        listaDeMascotas[i].edad,
                                                                        listaDeMascotas[i].peso);
                }
            }

    }
}

void OrdenarClientes_CantMascotas(eMascota listadoDeMascotas[], int sizeMascotas, eDuenio listadoDeDuenio[], int sizeDuenio)
{
    eDuenioMascota auxDuenio_mascota[sizeMascotas];
    eDuenioMascota auxOrdenar;
    eDuenio auxiliarOrdenarCant;
    int i;
    int j;

    for(i=0; i<sizeDuenio; i++)
    {
        auxDuenio_mascota[i].idDuenio = listadoDeDuenio[i].idDuenio;
        auxDuenio_mascota[i].cantMascota = 0;
    }

    for(i=0; i<sizeDuenio; i++)
    {
        for(j=0; j<sizeMascotas; j++)
        {
            if(listadoDeMascotas[j].estadoMascota==OCUPADO && auxDuenio_mascota[i].idDuenio == listadoDeMascotas[j].idDuenio)
            {
                auxDuenio_mascota[i].cantMascota++;
            }
        }
    }



    for(i=0;i<sizeDuenio-1;i++)
    {
        for(j=i+1;j<sizeDuenio;j++)
        {
            if(auxDuenio_mascota[i].cantMascota > auxDuenio_mascota[j].cantMascota)
            {
                auxOrdenar = auxDuenio_mascota[i];
                auxDuenio_mascota[i] = auxDuenio_mascota[j];
                auxDuenio_mascota[j] = auxOrdenar;


                auxiliarOrdenarCant = listadoDeDuenio[i];
                listadoDeDuenio[i] = listadoDeDuenio[j];
                listadoDeDuenio[j] = auxiliarOrdenarCant;
            }
        }
}
}


void OrdenarCantMascotas_Nombre(eMascota listadoDeMascotas[], int sizeMascotas, eDuenio listadoDeDuenio[], int sizeDuenio)
{
    eDuenioMascota auxDuenio_mascota[sizeMascotas];
    eDuenioMascota auxOrdenar;
    eDuenio auxiliarOrdenarCant;
    int i;
    int j;

    for(i=0; i<sizeDuenio; i++)
    {
        auxDuenio_mascota[i].idDuenio = listadoDeDuenio[i].idDuenio;
        auxDuenio_mascota[i].cantMascota = 0;
    }

    for(i=0; i<sizeDuenio; i++)
    {
        for(j=0; j<sizeMascotas; j++)
        {
            if(listadoDeMascotas[j].estadoMascota==OCUPADO && auxDuenio_mascota[i].idDuenio == listadoDeMascotas[j].idDuenio)
            {
                auxDuenio_mascota[i].cantMascota++;
            }
        }
    }



    for(i=0;i<sizeDuenio-1;i++)
    {
        for(j=i+1;j<sizeDuenio;j++)
        {
            if(auxDuenio_mascota[i].cantMascota > auxDuenio_mascota[j].cantMascota)
            {
                auxOrdenar = auxDuenio_mascota[i];
                auxDuenio_mascota[i] = auxDuenio_mascota[j];
                auxDuenio_mascota[j] = auxOrdenar;


                auxiliarOrdenarCant = listadoDeDuenio[i];
                listadoDeDuenio[i] = listadoDeDuenio[j];
                listadoDeDuenio[j] = auxiliarOrdenarCant;


            }else{
                if(auxDuenio_mascota[i].cantMascota == auxDuenio_mascota[j].cantMascota &&strcmpi(listadoDeDuenio[i].nombre, listadoDeDuenio[j].nombre)>0)
                {
                    auxOrdenar = auxDuenio_mascota[i];
                    auxDuenio_mascota[i] = auxDuenio_mascota[j];
                    auxDuenio_mascota[j] = auxOrdenar;


                    auxiliarOrdenarCant = listadoDeDuenio[i];
                    listadoDeDuenio[i] = listadoDeDuenio[j];
                    listadoDeDuenio[j] = auxiliarOrdenarCant;

                }
            }
}
}
}
