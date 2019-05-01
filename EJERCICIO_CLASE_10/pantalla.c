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
        if(arrayPantalla[i].isEmpty==0)
        {
            printf("ID:%d NOMBRE:%s DIR:%s TIPO:%s\n",  arrayPantalla[i].idPantalla,
                                                        arrayPantalla[i].nombre,
                                                        arrayPantalla[i].direccion,
                                                        arrayPantalla[i].tipo);
        }
        else
        {
            return -1;
        }
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
int pan_altaPantalla(Pantalla arrayPantalla[], int limite, int *indice)
{
    char bufferNombre[50];
    char bufferDireccion[256];
    char bufferTipo[50];
    int i;
    int retorno=-1;
    if(pan_lugarLibre(arrayPantalla,limite,&i)==0)
    {
        getString("Ingrese el nombre: ","Error",1,50,2,bufferNombre);
        getString("Ingrese la direccion: ","Error",1,256,2,bufferDireccion);
        getString("Ingrese el tipo: ","Error",1,50,2,bufferTipo);
        strncpy(arrayPantalla[i].nombre,bufferNombre,50);
        strncpy(arrayPantalla[i].direccion,bufferDireccion,256);
        strncpy(arrayPantalla[i].tipo,bufferTipo,50);
        arrayPantalla[i].isEmpty=0;
        retorno=0;
    }
    return retorno;
}
int pan_bajaPantalla(Pantalla arrayPantalla[], int id, int limite)
{
    int indicePantalla;
    if(pan_buscarPorId(arrayPantalla,limite,id,&indicePantalla)==0)
    {
        strncpy(arrayPantalla[indicePantalla].direccion,"\0",256);
        strncpy(arrayPantalla[indicePantalla].nombre,"\0",50);
        strncpy(arrayPantalla[indicePantalla].tipo,"\0",50);
        arrayPantalla[indicePantalla].isEmpty==1;
        return 0;
    }
    else
    {
        return -1;
    }
}
int pan_modificarPantalla(Pantalla arrayPantalla[],int id,int limite)
{
    int opcion;
    int indicePantalla;
    char bufferNombre[50];
    char bufferDireccion[256];
    char bufferTipo[50];
    if(pan_buscarPorId(arrayPantalla,limite,id,&indicePantalla)==0)
    {
        printf("\n1.Nombre");
        printf("\n2.Direccion");
        printf("\n3.Tipo");
        printf("\nIngrese opcion que quiera modificar:");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                getString("\nIngrese el nombre: ","Error",1,50,2,bufferNombre);
                strncpy(arrayPantalla[indicePantalla].nombre,bufferNombre,50);
                break;
            case 2:
                getString("\nIngrese la direccion: ","Error",1,256,2,bufferDireccion);
                strncpy(arrayPantalla[indicePantalla].direccion,bufferDireccion,256);
                break;
            case 3:
                getString("\nIngrese el tipo: ","Error",1,50,2,bufferTipo);
                strncpy(arrayPantalla[indicePantalla].tipo,bufferTipo,50);
                break;
        }
        return 0;
    }
    else
    {
        return -1;
    }
}
