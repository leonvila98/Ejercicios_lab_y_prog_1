#include "utn.h"
#include "pantalla.h"
#include "publicidad.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int pub_initArray(Publicidad arrayPublicidad[],int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        arrayPublicidad[i].isEmpty=1;
    }
    return 0;
}
int pub_mostrarArrayPublicidad(Publicidad arrayPublicidad[],int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        if(arrayPublicidad[i].isEmpty==0)
        {
            printf("ID:%d CUIT:%s DIAS:%d ARCHIVO:%s ID PANTALLA:%d\n",  arrayPublicidad[i].idPublicidad,
                                                        arrayPublicidad[i].cuit,
                                                        arrayPublicidad[i].dias,
                                                        arrayPublicidad[i].archivo,
                                                        arrayPublicidad[i].idPantalla);
        }
        else
        {
            return -1;
        }
    }
    return 0;
}
int pub_lugarLibre(Publicidad arrayPublicidad[],int limite,int *indice)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++)
    {
        if(arrayPublicidad[i].isEmpty==1)
        {
            *indice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
int pub_buscarPorId(Publicidad arrayPublicidad[],int limite,int id,int *indice)
{
    int retorno=-1;
    int i;
    for(i=0;i<limite;i++)
    {
        if(arrayPublicidad[i].idPublicidad==id)
        {
            *indice=i;
            retorno=0;
        }
    }
    return retorno;
}
