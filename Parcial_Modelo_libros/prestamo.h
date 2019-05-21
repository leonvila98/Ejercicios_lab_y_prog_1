#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED
#include "socio.h"
#include "libro.h"

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    int idLibro;
    int idSocio;

}Prestamo;


#endif // PRESTAMO_H_INCLUDED

int prestamo_Inicializar(Prestamo array[], int size);
int prestamo_buscarEmpty(Prestamo array[], int size, int* posicion);
int prestamo_buscarID(Prestamo array[], int size, int valorBuscado, int* posicion);
int prestamo_buscarInt(Prestamo array[], int size, int valorBuscado, int* posicion);
int prestamo_buscarString(Prestamo array[], int size, char* valorBuscado, int* indice);
int prestamo_alta(Prestamo array[],Socio arraySoc[],Libro arrayLib[], int size,int sizeSoc,int sizeLib);
int prestamo_baja(Prestamo array[], int sizeArray);
int prestamo_bajaValorRepetidoInt(Prestamo array[], int sizeArray, int valorBuscado);
int prestamo_modificar(Prestamo array[], int sizeArray);
int prestamo_ordenarPorDobleCriterio(Prestamo array[],int size, int orderFirst, int orderSecond);
int prestamo_listar(Prestamo array[], int size);
void prestamo_mock(Prestamo arrayPrestamo[], int size);

