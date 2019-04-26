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
        printf("ID:%s Empty:%d Nombre:%s Dir:%s Precio:%.2f Tipo:%s",arrayPantalla[i].nombre,
                                                                    arrayPantalla[i].idPantalla,
                                                                    arrayPantalla[i].nombre,
                                                                    arrayPantalla[i].direccion,
                                                                    arrayPantalla[i].precio,
                                                                    arrayPantalla[i].tipo);

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

int pan_AltaPantalla(Pantalla arrayPantalla[], int limite, int *indice)
{
    char bufferNombre[50];
    char bufferDireccion[256];
    char bufferTipo[50];
    int i;
    int retorno=-1;

    if(pan_lugarLibre(arrayPantalla,limite,&i))
    {
        getString("Ingrese el nombre: ","Error",1,50,2,bufferNombre);
        getString("Ingrese la direccion: ","Error",1,256,2,bufferDireccion);
        getString("Ingrese el tipo: ","Error",1,50,2,bufferTipo);
        strncpy(arrayPantalla[i].nombre,bufferNombre,50);
        strncpy(arrayPantalla[i].direccion,bufferDireccion,256);
        strncpy(arrayPantalla[i].tipo,bufferTipo,50);
    }

    retorno=0;
    return retorno;
}
