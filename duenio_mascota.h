#ifndef DUENIO_MASCOTA_H_INCLUDED
#define DUENIO_MASCOTA_H_INCLUDED
#include "mascotas.h"
#include "duenio.h"

typedef struct
{
  int idDuenio;//PK
  int cantMascota;
}eDuenioMascota;

void MostrarDuenios_mascota(eMascota listaDeMascotas[], int sizeMascota, eDuenio listaDeDuenio[], int sizeDuenio);
void mostrarMascotas(eMascota listaDeMascotas[],int sizeMascotas,eRaza listaDeRazas[],int sizeRazas, eDuenio listaDeDuenio[], int sizeDuenio);
void bajaMascota(eMascota listadoDeMascotas[], int len);
void modificarMascota(eMascota listadoDeMascotas[], int len);
void bajaDuenio(eDuenio listadoDeDuenios[] ,int sizeDuenio, eMascota listadoDeMascotas[], int sizeMascotas);
void ordenarMascotasPorTipo(eMascota listadoDeMascotas[], int len);
void listarClientesConMasDeUnaMascota(eMascota listadoDeMascotas[], int sizeMascotas, eDuenio listadoDeDuenio[], int sizeDuenio);
void mostrarMascotasMayorTresAnios(eMascota listaDeMascotas[],int sizeMascotas, eDuenio listaDeDuenio[], int sizeDuenio);
void OrdenarClientes_CantMascotas(eMascota listadoDeMascotas[], int sizeMascotas, eDuenio listadoDeDuenio[], int sizeDuenio);
void OrdenarCantMascotas_Nombre(eMascota listadoDeMascotas[], int sizeMascotas, eDuenio listadoDeDuenio[], int sizeDuenio);











#endif // DUENIO_MASCOTA_H_INCLUDED
