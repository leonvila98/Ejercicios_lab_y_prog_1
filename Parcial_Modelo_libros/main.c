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
    int i;
    int opcion=1;

    Autor arrayAutor[QTY_ARRAY_AUTOR];
    autor_Inicializar(arrayAutor,QTY_ARRAY_AUTOR);
    Libro arrayLibro[QTY_ARRAY_LIBRO];
    libro_Inicializar(arrayLibro,QTY_ARRAY_LIBRO);
    Socio arraySocio[QTY_ARRAY_SOCIO];
    socio_Inicializar(arraySocio,QTY_ARRAY_SOCIO);
    Prestamo arrayPrestamo[QTY_ARRAY_PRESTAMO];
    prestamo_Inicializar(arrayPrestamo,QTY_ARRAY_PRESTAMO);

    autor_mock(arrayAutor, QTY_ARRAY_AUTOR) ;
    libro_mock(arrayLibro, QTY_ARRAY_LIBRO) ;
    socio_mock(arraySocio, QTY_ARRAY_SOCIO) ;
    prestamo_mock(arrayPrestamo, QTY_ARRAY_PRESTAMO) ;

    for(i=0;i<QTY_ARRAY_AUTOR;i++)
    {
        arrayAutor[i].idUnico=i*2;
    }
    for(i=0;i<QTY_ARRAY_LIBRO;i++)
    {
        arrayLibro[i].idUnico=i*3;
    }
    for(i=0;i<QTY_ARRAY_SOCIO;i++)
    {
        arraySocio[i].idUnico=i*5;
    }
    for(i=0;i<QTY_ARRAY_PRESTAMO;i++)
    {
        arrayPrestamo[i].idUnico=i*10;
    }

    do
    {
        utn_getInt("\n\n1) Alta socio \n2) Modificar socio \n3) Baja socio \n4) Listar socios \n5) Listar libros"
                    "\n6) Listar autores\n7) Alta prestamo \n8) Salir\n","\nError",1,8,1,&opcion);
        switch(opcion)
        {
            case 1:
			{
				//socio_alta(arraySocio,QTY_ARRAY_SOCIO);
				Informes_listarSociosPorLibro(arraySocio,arrayLibro,arrayPrestamo,QTY_ARRAY_SOCIO,QTY_ARRAY_LIBRO,QTY_ARRAY_PRESTAMO);
				break;
			}
            case 2:
            {
                socio_modificar(arraySocio,QTY_ARRAY_SOCIO);
                break;
            }
            case 3:
            {
                socio_baja(arraySocio,QTY_ARRAY_SOCIO);
                break;
            }
            case 4:
            {
                socio_listar(arraySocio,QTY_ARRAY_SOCIO);
                break;
            }
            case 5:
            {
                libro_listar(arrayLibro,QTY_ARRAY_LIBRO);
                break;
            }
            case 6:
            {
                autor_listar(arrayAutor,QTY_ARRAY_AUTOR);
                break;
            }
            case 7:
            {
                prestamo_alta(arrayPrestamo,arraySocio,arrayLibro,QTY_ARRAY_PRESTAMO,QTY_ARRAY_SOCIO,QTY_ARRAY_LIBRO);
                prestamo_listar(arrayPrestamo,QTY_ARRAY_PRESTAMO);
                break;
            }
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=8);
    return 0;
}
