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
int pub_buscarPorCuit(Publicidad arrayPublicidad,int limite,char *cuit,int *indice)
{
    int retorno=-1;
    int i;
    for(i=0;i<limite;i++)
    {
        if(strcmp(arrayPublicidad[i].cuit,cuit)==0)
        {
            *indice=i;
            retorno=0;
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
int pub_altaPublicidad(Publicidad arrayPublicidad[],int idPantalla, int limite, int *indice)
{
    char bufferCuit[20];
    char bufferArchivo[256];
    int bufferDias;
    int i;
    int retorno=-1;
    if(pub_lugarLibre(arrayPublicidad,limite,&i)==0)
    {
        getString("Ingrese cuit: ","Error",1,20,2,bufferCuit);
        getString("Ingrese el archivo: ","Error",1,256,2,bufferArchivo);
        getInt("Ingrese cantidad de dias:","Error",1,365,2,&bufferDias);
        strncpy(arrayPublicidad[i].cuit,bufferCuit,20);
        strncpy(arrayPublicidad[i].archivo,bufferArchivo,256);
        arrayPublicidad[i].dias=bufferDias;
        arrayPublicidad[i].idPantalla=idPantalla;
        arrayPublicidad[i].isEmpty=0;
        *indice=i;
        retorno=0;
    }
    return retorno;
}
