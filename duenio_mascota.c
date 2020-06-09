#include "duenio_mascota.h"

void MostrarDuenios_mascota(eMascota listaDeMascotas[], int sizeMascota, eDuenio listaDeDuenio[], int sizeDuenio,eLocalidad localidades[],int sizeLocal)
{
    int i;//Duenio
    int j;//mascota
    int k;//localidad
    int resMascotas=0;

    for(i=0; i<sizeDuenio; i++)
    {
        if(listaDeDuenio[i].estado == OCUPADO)
            {
            printf("\n*************************************Duenio: %s**************************\n",listaDeDuenio[i].nombre);
            for(k=0; k<sizeLocal; k++)
                {
                if(listaDeDuenio[i].idLocalidad == localidades[k].idLocalidad)
                {
                    printf("Provincia: %15s\n",localidades[k].provincia);
                    printf("Localidad: %15s\n",localidades[k].descripcion);
                    printf("Codigo Postal: %5d\n",localidades[k].codigoPostal);
                }
                }
                printf("IDMASCOTA       NOMBRE          TIPO           RAZA          SEXO       EDAD     PESO\n");
                for(j=0; j<sizeMascota; j++)
                {
                    if((listaDeMascotas[j].idDuenio == listaDeDuenio[i].idDuenio) && listaDeMascotas[j].estadoMascota==OCUPADO)
                    {
                           printf("%4d %15s %15s  %15s \t%4d \t%.2f\n",listaDeMascotas[j].idMascota,
                                                                            listaDeMascotas[j].nombre,
                                                                            listaDeMascotas[j].tipo,
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
void mostrarMascotas(eMascota listaDeMascotas[],int sizeMascotas,eRaza listaDeRazas[],int sizeRazas, eDuenio listaDeDuenio[], int sizeDuenio)
{
    int i;
    int j;
    int k;
    printf("\nDUENIO      \tIDMASCOTA       NOMBRE          TIPO        \tRAZA    \tPAIS  \t    SEXO   EDAD  PESO\n");
    for(i=0; i<sizeMascotas; i++)
    {
        for(j = 0; j<sizeDuenio;j++)
        {
            if((listaDeMascotas[i].idDuenio == listaDeDuenio[j].idDuenio) && (listaDeMascotas[i].estadoMascota == OCUPADO) && (listaDeDuenio[j].estado== OCUPADO))
            {
                          for(k = 0; k<sizeRazas; k++)
                            {
                               if(listaDeRazas[k].idRaza == listaDeMascotas[i].idRaza && listaDeRazas[k].estado == OCUPADO)
                            {
                               printf("%s\t\t %4d %15s %15s %15s  %15s %10s %4d\t %.2f\n",listaDeDuenio[j].nombre,
                                                                                        listaDeMascotas[i].idMascota,
                                                                                        listaDeMascotas[i].nombre,
                                                                                        listaDeMascotas[i].tipo,
                                                                                        listaDeRazas[k].Nombre,
                                                                                        listaDeRazas[k].Pais,
                                                                                        listaDeMascotas[i].sexo,
                                                                                        listaDeMascotas[i].edad,
                                                                                        listaDeMascotas[i].peso);
                            }
                        }

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

void modificarMascota(eMascota listadoDeMascotas[], int len, eDuenio listadoDeDuenios[], int sizeDuenio, eLocalidad listadoLocalidad[], int sizeLocalidad)
{
    int posicion;
    int id;
    int eleccion = 0;
    int i;

    printf("Ingrese el id de la mascota  a modificar: ");
    scanf("%d", &id);
    do{
            printf("MODIFICAR: \n");
            eleccion = GetOption("1. Nombre\n2. Tipo\n3. Duenio\n4.Sexo\n5. Edad\n6. Peso\n7. SALIR\nElija una opcion: ");

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
                MostrarDuenios(listadoDeDuenios, sizeDuenio, listadoLocalidad, sizeLocalidad);
                listadoDeMascotas[posicion].idDuenio=GetInt("Reingrese el ID del duenio: ",len);
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
    printf("*************************************************\n");
    printf("*    LISTA DE CLIENTES CON MAS DE UNA MASCOTA   *\n");
    printf("*************************************************\n");

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


printf("IDDUENIO  CANTIDAD     NOMBRE         APELLIDO        SEXO       EDAD     TELEFONO\n");
     for(i=0;i<sizeDuenio; i++)
    {

        if(auxDuenio_mascota[i].cantMascota > 1 && listadoDeDuenio[i].estado == OCUPADO)
        {

               if(auxDuenio_mascota[i].idDuenio == listadoDeDuenio[i].idDuenio)
               {
                   printf("%4d \t%4d %15s %15s %15s\t %4d \t%4d\n",listadoDeDuenio[i].idDuenio,
                                                        auxDuenio_mascota[i].cantMascota,
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
    printf("************************************************\n");
    printf("*    LISTA DE MASCOTAS CON MAS DE TRES ANIOS   *\n");
    printf("************************************************\n");
    printf("\nDUENIO      \tIDMASCOTA       NOMBRE          TIPO           SEXO     EDAD   PESO\n");
    for(i=0; i<sizeMascotas; i++)
    {
            for(j = 0; j<sizeDuenio;j++)
            {
                if((listaDeMascotas[i].idDuenio == listaDeDuenio[j].idDuenio) && (listaDeMascotas[i].estadoMascota == OCUPADO) && (listaDeDuenio[j].estado== OCUPADO)&&(listaDeMascotas[i].edad > 3))
                {
                    printf("%s\t\t %4d %15s %15s %15s %4d \t%.2f\n",listaDeDuenio[j].nombre,
                                                                        listaDeMascotas[i].idMascota,
                                                                        listaDeMascotas[i].nombre,
                                                                        listaDeMascotas[i].tipo,
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
    printf("**************************************************************\n");
    printf("*    LISTA ORDENADA DE CLIENTES POR SU CANTIDAD DE MASCOTAS  *\n");
    printf("**************************************************************\n");

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

printf("IDDUENIO  CANTIDAD     NOMBRE         APELLIDO        SEXO       EDAD     TELEFONO\n");
     for(i=0;i<sizeDuenio; i++)
    {

        if(auxDuenio_mascota[i].cantMascota > 0 && listadoDeDuenio[i].estado == OCUPADO)
        {

               if(auxDuenio_mascota[i].idDuenio == listadoDeDuenio[i].idDuenio)
               {
                   printf("%4d \t%4d %15s %15s %15s\t %4d \t%4d\n",listadoDeDuenio[i].idDuenio,
                                                        auxDuenio_mascota[i].cantMascota,
                                                        listadoDeDuenio[i].nombre,
                                                        listadoDeDuenio[i].apellido,
                                                        listadoDeDuenio[i].sexo,
                                                        listadoDeDuenio[i].edad,
                                                        listadoDeDuenio[i].telefono);
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
    printf("********************************************************************\n");
    printf(">    LISTA ORDENADA POR CANTIDAD DE MASCOTAS Y NOMBRE DEL DUENIO   <\n");
    printf("********************************************************************\n");
    printf("IDDUENIO  CANTIDAD     NOMBRE         APELLIDO        SEXO       EDAD     TELEFONO\n");
     for(i=0;i<sizeDuenio; i++)
    {

        if(auxDuenio_mascota[i].cantMascota > 0 && listadoDeDuenio[i].estado == OCUPADO)
        {

               if(auxDuenio_mascota[i].idDuenio == listadoDeDuenio[i].idDuenio)
               {
                   printf("%4d \t%4d %15s %15s %15s\t %4d \t%4d\n",listadoDeDuenio[i].idDuenio,
                                                        auxDuenio_mascota[i].cantMascota,
                                                        listadoDeDuenio[i].nombre,
                                                        listadoDeDuenio[i].apellido,
                                                        listadoDeDuenio[i].sexo,
                                                        listadoDeDuenio[i].edad,
                                                        listadoDeDuenio[i].telefono);
               }
        }
    }
}


int CargarMascota(eMascota listaDeMascota[],int len, eRaza listaDeRazas[], int sizeRazas,int cont)
{
    int index;
    int retorno=-1;
    index=BuscarMascotaLibre(listaDeMascota,len);

    printf("**********************************************\n");
    printf("*               ALTA MASCOTA                 *\n");
    printf("**********************************************\n");
    if(index!=-1)
    {
        listaDeMascota[index].idDuenio = GetInt("Ingrese el Id del duneio que eligio: ", len);
        GetString("Ingrese nombre de la Mascota: ",listaDeMascota[index].nombre,len);
        do{
            GetString("Ingrese tipo de la Mascota (Perro, Gato, Raro): ",listaDeMascota[index].tipo,len);
        }while((strcmpi(listaDeMascota[index].tipo, "Perro" )!= 0) && (strcmpi(listaDeMascota[index].tipo, "Gato" )!= 0)&&(strcmpi(listaDeMascota[index].tipo, "Raro" )!= 0));

        if((strcmpi(listaDeMascota[index].tipo, "Perro" )== 0))
        {
            do
            {
                listaDeMascota[index].idRaza = GetInt("Ingrese el ID de la raza (Pastor, Aleman, Pitbul, Labrador, Buldog): ",sizeRazas);

            }while(listaDeMascota[index].idRaza > 6 || listaDeMascota[index].idRaza < 0);

        }else if((strcmpi(listaDeMascota[index].tipo, "Gato" )== 0))
        {
            do
            {
                listaDeMascota[index].idRaza = GetInt("Ingrese el ID de la raza (Gato, Persa, Siames): ",sizeRazas);

            }while(listaDeMascota[index].idRaza > 11 || listaDeMascota[index].idRaza < 8);

        }else{
            do
            {
                listaDeMascota[index].idRaza = GetInt("Ingrese el ID de la raza (Overo, Argentina): ",sizeRazas);

            }while(listaDeMascota[index].idRaza > 8 || listaDeMascota[index].idRaza < 6);
        }


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

void mostrarMascotasTipo(eMascota listaDeMascotas[],int sizeMascotas, eRaza listaDeRazas[], int sizeRaza)
{
    int i;
    printf("**********************************\n");
    printf(">    MOSTRAR MASCOTAS POR TIPO   <\n");
    printf("**********************************\n");
    char tipo[20];
    GetString("elija el tipo de mascota quiere mostrar (PERRO, GATO, RARO): ", tipo, sizeMascotas);
    while((strcmpi(tipo, "Perro" ) != 0) && (strcmpi(tipo, "Gato" ) != 0) && (strcmpi(tipo, "Raro" ) != 0))
    {
        GetString("elija un tipo de mascota valido (PERRO, GATO, RARO): ", tipo, sizeMascotas);
    }
    printf("IDMASCOTA       NOMBRE            TIPO             RAZA       PAIS           SEXO   EDAD        PESO\n");
    for(i=0; i<sizeMascotas; i++)
    {
        for(int j = 0;j<sizeRaza; j++){
        if(listaDeMascotas[i].idRaza == listaDeRazas[j].idRaza && listaDeRazas[j].estado == OCUPADO)
        {
            if((strcmpi(listaDeMascotas[i].tipo,tipo ) == 0)&&(listaDeMascotas[i].estadoMascota == OCUPADO))
        {
            printf("%4d %15s \t%15s %15s %15s %10s %4d \t%.2f\n",listaDeMascotas[i].idMascota,
                                                                        listaDeMascotas[i].nombre,
                                                                        listaDeMascotas[i].tipo,
                                                                        listaDeRazas[j].Nombre,
                                                                        listaDeRazas[j].Pais,
                                                                        listaDeMascotas[i].sexo,
                                                                        listaDeMascotas[i].edad,
                                                                        listaDeMascotas[i].peso);
        }
        }
        }

    }
}

void dueniosConMasDeUnaMascota(eMascota listadoDeMascotas[], int sizeMascotas, eDuenio listadoDeDuenio[], int sizeDuenio,eLocalidad listaDeLocalidades[],int sizeLocalidad)
{
    eDuenioMascota auxDuenio_mascota[sizeMascotas];
    int i;
    int j;

    for(i=0; i<sizeDuenio; i++)
    {
        auxDuenio_mascota[i].idDuenio = listadoDeDuenio[i].idDuenio;
        auxDuenio_mascota[i].cantMascota = 0;
    }
    for(i=0; i<sizeMascotas; i++)
    {
        strcpy(auxDuenio_mascota[i].tipo, listadoDeMascotas[i].tipo);
    }


    for(i=0; i<sizeDuenio; i++)
    {
        for(j=0; j<sizeMascotas; j++)
        {
            if(listadoDeMascotas[i].estadoMascota==OCUPADO && auxDuenio_mascota[j].idDuenio == listadoDeMascotas[i].idDuenio && strcmpi(listadoDeMascotas[j].tipo,auxDuenio_mascota[j].tipo)==0)
            {
                auxDuenio_mascota[j].cantMascota++;
            }
        }
    }


    printf("IDDUENIO  CANTIDAD     NOMBRE         APELLIDO        SEXO       EDAD     TELEFONO MASCOTA TIPO\n");
     for(i=0;i<sizeDuenio; i++)
    {


        if(auxDuenio_mascota[i].cantMascota > 1 && listadoDeDuenio[i].estado == OCUPADO)
        {
            for(j=0;j<sizeMascotas;j++)
            {
                if(auxDuenio_mascota[i].idDuenio == listadoDeDuenio[i].idDuenio && listadoDeDuenio[i].idDuenio==listadoDeMascotas[j].idDuenio)
                   {
                       printf("%4d \t%4d %15s %15s %15s\t %4d \t%4d %15s %15s\n",listadoDeDuenio[i].idDuenio,
                                                            auxDuenio_mascota[i].cantMascota,
                                                            listadoDeDuenio[i].nombre,
                                                            listadoDeDuenio[i].apellido,
                                                            listadoDeDuenio[i].sexo,
                                                            listadoDeDuenio[i].edad,
                                                            listadoDeDuenio[i].telefono,
                                                            listadoDeMascotas[j].nombre,
                                                            listadoDeMascotas[j].tipo);
                   }
            }


        }
    }
}
