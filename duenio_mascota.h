#ifndef DUENIO_MASCOTA_H_INCLUDED
#define DUENIO_MASCOTA_H_INCLUDED
#include "mascotas.h"
#include "duenio.h"
#include "raza.h"

typedef struct
{
  int idDuenio;//PK
  int cantMascota;
  char tipo[20];
}eDuenioMascota;

void MostrarDuenios_mascota(eMascota listaDeMascotas[], int sizeMascota, eDuenio listaDeDuenio[], int sizeDuenio,eLocalidad localidades[],int sizeLocal);
void mostrarMascotas(eMascota listaDeMascotas[],int sizeMascotas,eRaza listaDeRazas[],int sizeRazas, eDuenio listaDeDuenio[], int sizeDuenio);
void bajaMascota(eMascota listadoDeMascotas[], int len);
void modificarMascota(eMascota listadoDeMascotas[], int len, eDuenio listadoDeDuenios[], int sizeDuenio, eLocalidad listadoLocalidad[], int sizeLocalidad);
void bajaDuenio(eDuenio listadoDeDuenios[] ,int sizeDuenio, eMascota listadoDeMascotas[], int sizeMascotas);
void ordenarMascotasPorTipo(eMascota listadoDeMascotas[], int len);
void listarClientesConMasDeUnaMascota(eMascota listadoDeMascotas[], int sizeMascotas, eDuenio listadoDeDuenio[], int sizeDuenio);
void mostrarMascotasMayorTresAnios(eMascota listaDeMascotas[],int sizeMascotas, eDuenio listaDeDuenio[], int sizeDuenio);
void OrdenarClientes_CantMascotas(eMascota listadoDeMascotas[], int sizeMascotas, eDuenio listadoDeDuenio[], int sizeDuenio);
void OrdenarCantMascotas_Nombre(eMascota listadoDeMascotas[], int sizeMascotas, eDuenio listadoDeDuenio[], int sizeDuenio);

int CargarMascota(eMascota listaDeMascota[],int len, eRaza listaDeRazas[], int sizeRazas,int cont);
void mostrarMascotasTipo(eMascota listaDeMascotas[],int sizeMascotas,eRaza listaDeRazas[], int sizeRaza);


void dueniosConMasDeUnaMascota(eMascota listadoDeMascotas[], int sizeMascotas, eDuenio listadoDeDuenio[], int sizeDuenio,eLocalidad listaDeLocalidades[],int sizeLocalidad);








#endif // DUENIO_MASCOTA_H_INCLUDED
