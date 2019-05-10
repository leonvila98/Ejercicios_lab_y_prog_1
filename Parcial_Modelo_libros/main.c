#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fantasma.h"  //cambiar por nombre entidad
#include "autor.h"
#include "libro.h"
#include "socio.h"
#include "prestamo.h"

#define QTY_ARRAY_TIPO 10
#define QTY_ARRAY_AUTOR 10
#define QTY_ARRAY_LIBRO 10
#define QTY_ARRAY_SOCIO 10
#define QTY_ARRAY_PRESTAMO 10
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int contadorIdfantasma=0;                   //cambiar

    Fantasma arrayFantasma[QTY_ARRAY_TIPO];                   //cambiar
    fantasma_Inicializar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
    fantasma_mock(arrayFantasma, QTY_ARRAY_TIPO, &contadorIdfantasma) ;                     //cambiar fantasma

    int contadorIdAutor=0;
    Autor arrayAutor[QTY_ARRAY_AUTOR];                   //cambiar
    autor_Inicializar(arrayAutor,QTY_ARRAY_AUTOR);                   //cambiar
    autor_mock(arrayAutor, QTY_ARRAY_AUTOR, &contadorIdAutor) ;                     //cambiar fantasma

    int contadorIdLibro=0;
    Libro arrayLibro[QTY_ARRAY_LIBRO];                   //cambiar
    libro_Inicializar(arrayLibro,QTY_ARRAY_LIBRO);                   //cambiar
    libro_mock(arrayLibro, QTY_ARRAY_LIBRO, &contadorIdLibro) ;

    int contadorIdSocio=0;
    Socio arraySocio[QTY_ARRAY_SOCIO];                   //cambiar
    socio_Inicializar(arraySocio,QTY_ARRAY_SOCIO);                   //cambiar
    socio_mock(arraySocio, QTY_ARRAY_SOCIO, &contadorIdSocio) ;

    int contadorIdPrestamo=0;
    Prestamo arrayPrestamo[QTY_ARRAY_PRESTAMO];                   //cambiar
    prestamo_Inicializar(arrayPrestamo,QTY_ARRAY_PRESTAMO);                   //cambiar
    prestamo_mock(arrayPrestamo, QTY_ARRAY_PRESTAMO, &contadorIdPrestamo) ;

    do
    {
        utn_getUnsignedInt("\n\n1) Alta socio \n2) Modificar socio \n3) Baja \n4) Listar \n5) Ordenar \n\n 6) Alta autor \n7) Modificar autor \n8) Baja autor \n9) Listar autor \n10) Ordenar autor \n11) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
			{
				socio_alta(arraySocio,QTY_ARRAY_SOCIO,&contadorIdSocio);
			}
			break;
            case 2:
            {

            }
                                  //cambiar
                break;

            case 3: //Baja
                fantasma_baja(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 4://Listar
                fantasma_listar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 5://Ordenar
                fantasma_ordenarPorDobleCriterio(arrayFantasma,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;
            case 6: //Alta
                autor_alta(arrayAutor,QTY_ARRAY_TIPO,&contadorIdAutor);                   //cambiar
                break;

            case 7: //Modificar
                autor_modificar(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 8: //Baja
                autor_baja(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 9://Listar
                autor_listar(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 10://Ordenar
                autor_ordenarPorDobleCriterio(arrayAutor,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;

            case 11://Salir
                break;

            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
