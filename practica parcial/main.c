#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Gets.h"
#include "Validate.h"
#include "duenio_mascota.h"
#define T 10
#define M 20
#define OCUPADO 1

int main()
{
    int opcion;
    char aux;
    char salir;
    int contadorDuenio=0;
    int contadorMascota=0;

    eRaza arrayRaza[M];
    eDuenio arrayDuenio[T];
    eMascota arrayMascotas[M];
    hardcodearRaza(arrayRaza);

    InitDuenio(arrayDuenio,T);
    hardCodearDuenio(arrayDuenio);
    contadorDuenio = 5;

    InitMascota(arrayMascotas,M);
    hardCodearMascota(arrayMascotas);
    contadorMascota = 11;

    do
    {
        printf("******************************************************************\n");
        printf("*                                 MENU                           *\n");
        printf("******************************************************************\n");
        printf("1).Agregar Duenio\n");
        printf("2).Mostrar Duenio\n");
        printf("3).Agregar Mascota\n");
        printf("4).Mostrar Mascota\n");
        printf("5).Mostrar Duenio con mascotas\n");
        printf("6).Eliminar Una mascota\n");
        printf("7).Modificar una mascota\n");
        printf("8).Borrado de duenio en cascada\n");
        printf("9).Ordenar las mascotas por tipo y listarlas con sus duenios\n");
        printf("10).Modificacion Duenio\n");
        printf("11).Listar los clientes con mas de una mascota\n");
        printf("12).Listar las mascotas de mas de tres anios, con respectivos duenios.\n");
        printf("13).Listar las mascotas por un tipo en particular perro,gato,raro\n");
        printf("14).Ordenar a los duenios por cantidades de mascotas y mostrarlos.\n");
        printf("15).Ordenar a los duenios por cantidades de mascotas y por orden alfabetico de los nombres y mostrarlos\n");
        printf("16).El promedio de edad entre las mascotas\n");
        printf("17).El promedio de edad entre las mascotas, por tipo\n");
        printf("18).El promedio que tengo entre varones y mujeres de mis clientes\n");
        printf("19).Salir\n");
        opcion=GetOption("Ingrese una opcion: ");

        switch(opcion)
        {
        case 1:
            system("cls");
            printf("**********************\n");
            printf(">    ALTA Duenio   <\n");
            printf("**********************\n");
            contadorDuenio++;
            CargarDuenio(arrayDuenio,T,contadorDuenio);
            break;
        case 2:
            system("cls");
            printf("MOSTRAR Duenio\n");
            MostrarDuenios(arrayDuenio,T);
            break;
        case 3:
            system("cls");
            printf("**********************\n");
            printf(">    ALTA MASCOTA   <\n");
            printf("**********************\n");
            printf("*********DUENIOS DISPONIBLES**********\n");
            MostrarDuenios(arrayDuenio, T);
            contadorMascota++;
            CargarMascota(arrayMascotas,M,contadorMascota);
            break;
        case 4:
            system("cls");
            printf("MOSTRAR MASCOTA \n");
            mostrarRazas(arrayRaza, T);
            mostrarMascotas(arrayMascotas, M, arrayDuenio, T);
            break;
        case 5:
            system("cls");
            printf("Duenios CON MASCOTAS\n");
            MostrarDuenios_mascota(arrayMascotas, M, arrayDuenio,T);
            break;
        case 6:
            system("cls");
            printf("Eliminar mascota: \n");
            mostrarMascotas(arrayMascotas, M, arrayDuenio, T);
            bajaMascota(arrayMascotas, M);
            break;
        case 7:
            system("cls");
            printf("**********************\n");
            printf(">  MODIFICAR MASCOTAS <\n");
            printf("**********************\n");
            mostrarMascotas(arrayMascotas, M, arrayDuenio, T);
            modificarMascota(arrayMascotas, M);
            break;
        case 8:
            system("cls");
            printf("**********************\n");
            printf(">    BAJA DE DUENIO   <\n");
            printf("**********************\n");
            MostrarDuenios(arrayDuenio,T);
            bajaDuenio(arrayDuenio, T, arrayMascotas, M);
            break;
        case 9:
            system("cls");
            printf("***********************************\n");
            printf(">    MASCOTAS ORDENADAS POR TIPO   <\n");
            printf("************************************\n");
            ordenarMascotasPorTipo(arrayMascotas, M);
            mostrarMascotas(arrayMascotas, M, arrayDuenio, T);
            break;
        case 10:
            system("cls");
            printf("***********************\n");
            printf(">    MODIFICAR DUENIO   <\n");
            printf("***********************\n");
            MostrarDuenios(arrayDuenio,T);
            modificarDuenio(arrayDuenio, T);
            break;
        case 11:
            system("cls");
            printf("*************************************************\n");
            printf(">    LISTA DE CLIENTES CON MAS DE UNA MASCOTA   <\n");
            printf("*************************************************\n");
            listarClientesConMasDeUnaMascota(arrayMascotas, M, arrayDuenio, T);
            break;
        case 12:
            system("cls");
            printf("************************************************\n");
            printf(">    LISTA DE MASCOTAS CON MAS DE TRES ANIOS   <\n");
            printf("************************************************\n");
            mostrarMascotasMayorTresAnios(arrayMascotas, M, arrayDuenio, T);
            break;
        case 13:
            system("cls");
            printf("**********************************\n");
            printf(">    MOSTRAR MASCOTAS POR TIPO   <\n");
            printf("**********************************\n");
            mostrarMascotasTipo(arrayMascotas, M);
            break;
        case 14:
            system("cls");
            printf("**************************************************************\n");
            printf(">    LISTA ORDENADA DE CLIENTES POR SU CANTIDAD DE MASCOTAS   <\n");
            printf("**************************************************************\n");
            OrdenarClientes_CantMascotas(arrayMascotas, M, arrayDuenio, T);
            MostrarDuenios(arrayDuenio, T);
            break;
            case 15:
                system("cls");
                printf("********************************************************************\n");
                printf(">    LISTA ORDENADA POR CANTIDAD DE MASCOTAS Y NOMBRE DEL DUENIO   <\n");
                printf("********************************************************************\n");
                OrdenarCantMascotas_Nombre(arrayMascotas, M, arrayDuenio, T);
                MostrarDuenios(arrayDuenio, T);
            break;
            case 16:
                system("cls");
                printf("********************************************\n");
                printf(">    PROMEDIO DE LA EDAD DE LAS MASCOTAS   <\n");
                printf("********************************************\n");
                mostrarMascotas(arrayMascotas, M, arrayDuenio, T);
                promedioEdadMascotas(arrayMascotas, M);
            break;
            case 17:
                system("cls");
                printf("*****************************************************\n");
                printf(">    PROMEDIO DE EDAD DE LA MASCOTA SEGUN SU TIPO   <\n");
                printf("*****************************************************\n");
                promedioMascotasTipo(arrayMascotas, M);
            break;
            case 18:
                system("cls");
                printf("**************************************\n");
                printf(">    PROMEDIO DE HOMBRES Y MUJERES   <\n");
                printf("**************************************\n");
                promedioHombresMujeres(arrayDuenio, T);
            break;
        case 19:
            aux=GetChar("\nSeguro desea salir? (s/n): ");
            salir=tolower(aux);
            if(salir=='s')
            {
                printf("\nSalida con exito\n\n\n");
                opcion=19;
            }
            else
            {
                opcion=0;
            }
            break;
        }
        system("pause");
        system("cls");

    }
    while(opcion!=19);

    return 0;
}
