#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Gets.h"
#include "Validate.h"
#include "duenio_mascota.h"
#define L 3
#define T 10
#define M 20
#define R 15
#define OCUPADO 1

int main()
{
    int opcion;
    char aux;
    char salir;
    int contadorDuenio=0;
    int contadorMascota=0;

    eRaza arrayRaza[R];
    eDuenio arrayDuenio[T];
    eLocalidad arrayLocalidad[L];
    eMascota arrayMascotas[M];

    InitRaza(arrayRaza, R);
    hardcodearRaza(arrayRaza);

    InitDuenio(arrayDuenio,T);
    hardCodearDuenio(arrayDuenio);
    contadorDuenio = 5;

    InitMascota(arrayMascotas,M);
    hardCodearMascota(arrayMascotas);
    contadorMascota = 11;

    InitLocalidad(arrayLocalidad,L);
    hardCodearLocalidad(arrayLocalidad);

    do
    {
        menuIndex();
        opcion=GetOption("Ingrese una opcion: ");

        switch(opcion)
        {
        case 1:
            system("cls");
            contadorDuenio++;
            if(CargarDuenio(arrayDuenio,T,contadorDuenio,arrayLocalidad,L) == 0)
            {
                printf("Se ingreso correctamente al duenio\n");
            }else
            {
                printf("No hay lugar disponible\n");
            }

            break;
        case 2:
            system("cls");
            MostrarDuenios(arrayDuenio,T,arrayLocalidad,L);
            break;
        case 3:
            system("cls");
            MostrarDuenios(arrayDuenio,T,arrayLocalidad,L);
            mostrarRazas(arrayRaza, R);
            contadorMascota++;
            CargarMascota(arrayMascotas,M,arrayRaza,R,contadorMascota);
            break;
        case 4:
            system("cls");
            printf("MOSTRAR MASCOTA \n");
            mostrarMascotas(arrayMascotas, M,arrayRaza,R, arrayDuenio, T);
            break;
        case 5:
            system("cls");
            printf("Duenios CON MASCOTAS\n");
            MostrarDuenios_mascota(arrayMascotas, M, arrayDuenio,T, arrayLocalidad, L);
            break;
        case 6:
            system("cls");
            printf("Eliminar mascota: \n");
            mostrarMascotas(arrayMascotas, M,arrayRaza,R, arrayDuenio, T);
            bajaMascota(arrayMascotas, M);
            break;
        case 7:
            system("cls");
            printf("***********************\n");
            printf("*  MODIFICAR MASCOTAS *\n");
            printf("***********************\n");
            mostrarMascotas(arrayMascotas, M,arrayRaza,R, arrayDuenio, T);
            modificarMascota(arrayMascotas, M, arrayDuenio, T, arrayLocalidad, L);
            break;
        case 8:
            system("cls");
            printf("**********************\n");
            printf("*    BAJA DE DUENIO  *\n");
            printf("**********************\n");
            MostrarDuenios(arrayDuenio,T,arrayLocalidad,L);
            bajaDuenio(arrayDuenio, T, arrayMascotas, M);
            break;
        case 9:
            system("cls");
            printf("***********************************\n");
            printf("*    MASCOTAS ORDENADAS POR TIPO  *\n");
            printf("***********************************\n");
            ordenarMascotasPorTipo(arrayMascotas, M);
            mostrarMascotas(arrayMascotas, M,arrayRaza,R, arrayDuenio, T);
            break;
        case 10:
            system("cls");
            printf("***********************\n");
            printf("*    MODIFICAR DUENIO *\n");
            printf("***********************\n");
            MostrarDuenios(arrayDuenio,T,arrayLocalidad,L);
            modificarDuenio(arrayDuenio, T);
            break;
        case 11:
            system("cls");
            listarClientesConMasDeUnaMascota(arrayMascotas, M, arrayDuenio, T);
            break;
        case 12:
            system("cls");
            mostrarMascotasMayorTresAnios(arrayMascotas, M, arrayDuenio, T);
            break;
        case 13:
            system("cls");
            mostrarMascotasTipo(arrayMascotas, M, arrayRaza, R);
            break;
        case 14:
            system("cls");
            OrdenarClientes_CantMascotas(arrayMascotas, M, arrayDuenio, T);
            break;
            case 15:
                system("cls");
                OrdenarCantMascotas_Nombre(arrayMascotas, M, arrayDuenio, T);
            break;
            case 16:
                system("cls");
                promedioEdadMascotas(arrayMascotas, M);
            break;
            case 17:
                system("cls");
                promedioMascotasTipo(arrayMascotas, M);
            break;
            case 18:
                system("cls");
                porcentajeMujeres(arrayDuenio, T);
            break;
            case 19:
            system("cls");
            dueniosConMasDeUnaMascota(arrayMascotas,M,arrayDuenio,T,arrayLocalidad,L);
            break;
            case 20:
            system("cls");
            MostrarDueniosPorLocalidad(arrayDuenio,T,arrayLocalidad,L);
            break;
            case 21:
            system("cls");
            ordenarLocalidadNombre(arrayDuenio,T);
            //ordenarNombreDuenio_localidad(arrayDuenio,T,arrayLocalidad,L);
            MostrarDuenios(arrayDuenio,T,arrayLocalidad,L);
            break;
        case 22:
            aux=GetChar("\nSeguro desea salir? (s/n): ");
            salir=tolower(aux);
            if(salir=='s')
            {
                printf("\nSalida con exito\n\n\n");
                opcion=22;
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
    while(opcion!=22);

    return 0;
}
