#include "utn.h"
#include "pantalla.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int pan_initArray(Pantalla arrayPantalla[],int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        arrayPantalla[i].isEmpty=1;
    }
    return 0;
}
int pan_mostrarArrayPantalla(Pantalla arrayPantalla[],int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("\ID:%s Empty:%d Nombre:%s Dir:%s Precio:%f Tipo:%s",arrayPantalla[i].nombre,
                                                                    arrayPantalla[i].idPantalla,
                                                                    arrayPantalla[i].nombre,);

    }
    return 0;
}
int pan_lugarLibre(Pantalla arrayPantalla[],int limite,int *indice)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++)
    {
        if(arrayPantalla[i].isEmpty==1)
        {
            *indice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
int pan_buscarPorId(Pantalla arrayPantalla[],int limite,int id,int *indice)
{
    int retorno=-1;
    int i;
    for(i=0;i<limite;i++)
    {
        if(arrayPantalla[i].idPantalla==id)
        {
            *indice=i;
            retorno=0;
        }
    }
    return retorno;
}

int pan_AltaPantalla(Pantalla arrayPantalla[], int limite, int posLibre)
{
    char bufferNombre;
    char bufferDireccion;
    char bufferTipo;
    int indice;
    int retorno=-1;
    if(pan_lugarLibre(arrayPantalla, 100, &indice))
    {
    getString("Ingrese el nombre: ", "Error", 1, 50, 2, &bufferNombre);
    getString("Ingrese la direccion: ", "Error", 1, 50, 2, &bufferDireccion);
    getString("Ingrese el tipo: ", "Error", 1, 50, 2, &bufferTipo);
    retorno=0;
    }
    return retorno;
}
