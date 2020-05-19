#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Menu.h"
#define T 3
void Menu()
{
    int opcion;
    char aux;
    char salir;
    int contOrquesta=0;
    int contMusico=0;
    int contInstrumento=0;

    eOrquesta arrayOrquesta[T];
    eMusico arrayMusico[T];
    eInstrumento arrayInstrumento[T];
    eTipoInstrumento arrayTipoInstrumento[4]={{1,"Cuerdas"},{2,"Viento-Madera"},{3,"Viento-Metal"},{4,"Percusion"}};

    InitOrquesta(arrayOrquesta,T);
    InitMusicos(arrayMusico,T);
    InitInstrumentos(arrayInstrumento,T);


    do
    {
        printf("**********************\n");
        printf(">       MENU         <\n");
        printf("**********************\n\n");
        printf("1).Agregar Orquesta\n");
        printf("2).Eliminar Orquesta\n");
        printf("3).Imprimir Orquestas\n");
        printf("4).Agregar Musico\n");
        printf("5).Modificar Musico\n");
        printf("6).Eliminar Musico\n");
        printf("7).Imprimir Musicos\n");
        printf("8).Agregar Instrumento\n");
        printf("9).Imrimir Instrumentos\n");
        printf("10).Informes\n");
        printf("11).Salir\n");
        opcion=GetOption("Ingrese una opcion: ");

        switch(opcion)
        {
        case 1:
            system("cls");
            printf("**********************\n");
            printf(">    ALTA ORQUESTA   <\n");
            printf("**********************\n");
            contOrquesta++;
            CargarOrquesta(arrayOrquesta,T,contOrquesta);
            break;
        case 2:
            system("cls");
            printf("************************\n");
            printf(">  ELIMINAR ORQUESTA    <\n");
            printf("************************\n");
            EliminarOrquesta(arrayOrquesta,T,arrayMusico,T,arrayInstrumento,4);
            break;
        case 3:
            printf("************************\n");
            printf(">  LISTA DE ORQUESTAS  <\n");
            printf("************************\n");
            MostrarOrquestas(arrayOrquesta,T);
            break;
        case 4:
            system("cls");
            printf("**********************\n");
            printf(">    ALTA MUSICO   <\n");
            printf("**********************\n");
            CargarMusico(arrayMusico,T,contMusico);
            contMusico++;
            break;
        case 7:
            MostrarMusicos(arrayMusico,T);
            break;
        case 8:
            system("cls");
            printf("**********************\n");
            printf(">    ALTA INSTRUMENTO  <\n");
            printf("**********************\n");
            CargarInstrumento(arrayInstrumento,T,contInstrumento);
            contInstrumento++;
            break;
        case 9:
            MostrarInstrumentos(arrayInstrumento,T,arrayTipoInstrumento,4);
            break;
        case 11:
            aux=GetChar("\nSeguro desea salir? (s/n): ");
            salir=tolower(aux);

            if(salir=='s')
            {
                printf("\nSalida con exito\n\n\n");
                opcion=11;
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
    while(opcion!=11);

}

strn
