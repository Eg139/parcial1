#ifndef RAZA_H_INCLUDED
#define RAZA_H_INCLUDED

typedef struct
{
    int idRaza;
    char Nombre[20];
    char Pais[20];
    int estado;
}eRaza;

void hardcodearRaza(eRaza listadoDeRazas[]);
void mostrarRazas(eRaza listadoDeRazas[], int len);
int InitRaza(eRaza listaDeRazas[],int len);

#endif // RAZA_H_INCLUDED
