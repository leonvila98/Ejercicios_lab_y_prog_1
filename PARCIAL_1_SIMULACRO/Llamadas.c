#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Asociados.h"
#include "Llamadas.h"

int lla_printLlamada(Llamadas *auxLlamada,int limite)
{
    int i;
    int flag=1;
    for(i=0;i<limite;i++)
    {
        if(auxLlamada[i].estado==1 || auxLlamada[i].estado==0)
        {
            printf("\nID: %d\nEstado: %d\nMotivo: %d\nID Asociado: %d\nTiempo: %d\n-------",auxLlamada[i].idLlamada,
                                                                                            auxLlamada[i].estado,
                                                                                            auxLlamada[i].motivo,
                                                                                            auxLlamada[i].idAsociado,
                                                                                            auxLlamada[i].tiempo);
            flag=0;
        }
    }
    if(flag==1)
    {
        printf("\nNo hay llamadas\n");
    }
    return 0;
}
int lla_initLlamada(Llamadas *auxLlamada,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        auxLlamada[i].estado=2;
        auxLlamada[i].idAmbulancia=0;
    }
    return 0;
}
int lla_altaLlamada(Llamadas *auxLlamada,int limite,int *indice)
{
    int i;
    int retorno=-1;
    int bufferMotivo;
    int bufferIdAsociado;

    for(i=0;i<limite;i++)
    {
        if(auxLlamada[i].estado==2 &&
           getInt("\nIngrese motivo:","\nError",0,2,2,&bufferMotivo)==0 &&
           getInt("\nIngrese ID del asociado:","\nError",1,50,2,&bufferIdAsociado)==0)
        {
            auxLlamada[i].motivo=bufferMotivo;
            auxLlamada[i].idAsociado=bufferIdAsociado;
            auxLlamada[i].estado=0;
            retorno=0;
            break;
        }
    }
    lla_printLlamada(auxLlamada,limite);
    return retorno;
}
int lla_modificarLlamada(Llamadas *auxLlamada,int limite,int *indiceLlamada)
{
    int id;
    int indice;
    int retorno=-1;
    lla_printLlamada(auxLlamada,limite);
    if(getInt("\nIngrese id de llamada:","Error",0,limite*2,2,&id)==0)
    {
        if(lla_findById(auxLlamada,limite,id,&indice)==0)
        {
            auxLlamada[indice].estado=1;
            *indiceLlamada=indice;
            retorno=0;
        }
    }
    return retorno;
}
int lla_findById(Llamadas *auxLlamada,int limite,int id,int *resultado)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++)
    {
        if(auxLlamada[i].idLlamada==id)
        {
            *resultado=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
int lla_asoMasLlamados(Llamadas *auxLlamada,Asociado *auxAsociado,int limite,int limiteAso)
{
    int i;
    int j=0;
    int flag=0;
    int retorno=-1;
    int contador=0;
    int maximo;
    do
    {
        for(i=0;i<limite;i++)
        {
            if(flag==0)
            {
                maximo=contador;
                retorno=auxAsociado[j].idAsociado;
                flag=1;
            }
            if(auxLlamada[i].idAsociado==auxAsociado[j].idAsociado)
            {
                contador++;
                if(contador>maximo)
                {
                    maximo=contador;
                    retorno=auxAsociado[j].idAsociado;
                }
            }
        }
        j++;
        contador=0;
    }while(j<limiteAso);
    return retorno;
}
int lla_maxMotivos(Llamadas *auxLlamada,int limite)
{
    int i;
    int flag=0;
    int retorno=-1;
    int contadorUno=0;
    int contadorDos=0;
    int contadorTres=0;
    int maximo;

    for(i=0;i<limite;i++)



    return retorno;
}
