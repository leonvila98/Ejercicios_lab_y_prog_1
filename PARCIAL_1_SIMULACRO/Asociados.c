#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Asociados.h"

int aso_printAsociado(Asociado *auxAsociado,int limite)
{
    int i;
    int flag=1;
    for(i=0;i<limite;i++)
    {
        if(auxAsociado[i].estado==1 || auxAsociado[i].estado==0)
        {
            printf("\nID: %d\nNombre: %s\nApellido: %s\nEstado: %d\nDNI: %s\nEdad: %d\n-------",auxAsociado[i].idAsociado,
                                                                                                auxAsociado[i].nombre,
                                                                                                auxAsociado[i].apellido,
                                                                                                auxAsociado[i].estado,
                                                                                                auxAsociado[i].dni,
                                                                                                auxAsociado[i].edad);
            flag=0;
        }
    }
    if(flag==1)
    {
        printf("\nNo hay asociados\n");
    }
    return 0;
}
int aso_estado(Asociado *auxAsociado,int limite,int *indice)
{
    int i;
    for(i=0;i<limite;i++)
    {
        if(auxAsociado[i].estado==2)
        {
            *indice=i;
        }
    }
    return 0;
}
int aso_initAsociado(Asociado *auxAsociado,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        auxAsociado[i].estado=2;
        auxAsociado[i].edad=0;
        strncpy(auxAsociado[i].nombre,"\0",50);
        strncpy(auxAsociado[i].apellido,"\0",50);
        strncpy(auxAsociado[i].dni,"\0",20);
    }
    return 0;
}
int aso_altaAsociado(Asociado *auxAsociado,int limite,int *indice)
{
    int i;
    int retorno=-1;
    char bufferNombre[50];
    char bufferApellido[50];
    char bufferDni[20];
    int bufferEdad;

    for(i=0;i<limite;i++)
    {
        if(auxAsociado[i].estado==2)
        {
            if((getName("\nIngrese nombre:","\nError",1,20,2,bufferNombre)&
                getName("\nIngrese apellido:","\nError",1,20,2,bufferApellido)&
                getInt("\nIngrese edad:","\nError",1,150,2,&bufferEdad)&
                getString("\nIngrese DNI:","\nError",1,20,2,bufferDni))==0)
            {
                auxAsociado[i].edad=bufferEdad;
                strncpy(auxAsociado[i].nombre,bufferNombre,50);
                strncpy(auxAsociado[i].apellido,bufferApellido,50);
                strncpy(auxAsociado[i].dni,bufferDni,20);
                auxAsociado[i].estado=1;
                retorno=0;
            }
        }
    }
    return retorno;
}
int aso_modificar(Asociado *auxAsociado,int limite)
{
    int id;
    int indice;
    int retorno=-1;
    aso_printAsociado(auxAsociado,limite);
    if(getInt("\nIngrese id de asociado:","Error",0,limite*5,2,&id)==0)
    {
        if(aso_findById(auxAsociado,limite,id,&indice)==0)
        {
            getName("\nIngrese nombre:","\nError",1,20,2,auxAsociado[indice].nombre);
            getName("\nIngrese apellido:","\nError",1,20,2,auxAsociado[indice].apellido);
            getInt("\nIngrese edad:","\nError",1,150,2,&auxAsociado[indice].edad);
            getString("\nIngrese DNI:","\nError",1,20,2,auxAsociado[indice].dni);
            retorno=0;
        }
    }
    return retorno;
}
int aso_findById(Asociado *auxAsociado, int limite, int id,int *resultado)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++)
    {
        if(auxAsociado[i].idAsociado==id)
        {
            *resultado=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
int aso_modificarEstado(Asociado *auxAsociado,int limite)
{
    int id;
    int indice;
    int opcion;
    int retorno=-1;
    aso_printAsociado(auxAsociado,limite);
    if(getInt("\nIngrese id de asociado:","Error",0,limite*5,2,&id)==0)
    {
        if(aso_findById(auxAsociado,limite,id,&indice)==0)
        {
            getInt("\n0-Deshabilitar\n1-Habilitar\n","Error",0,1,2,&opcion);
            if(opcion==1)
            {
                auxAsociado[indice].estado=1;
                retorno=0;
            }
            else if(opcion==0)
            {
                auxAsociado[indice].estado=0;
                retorno=0;
            }
        }
    }
    return retorno;
}
int aso_printUnAsociado(Asociado *auxAsociado,int limite,int id)
{
    int i;
    int flag=1;
    for(i=0;i<limite;i++)
    {
        if(auxAsociado[i].estado!=2 && auxAsociado[i].idAsociado==id)
        {
            printf("\nID: %d\nNombre: %s\nApellido: %s\nEstado: %d\nDNI: %s\nEdad: %d\n-------",auxAsociado[i].idAsociado,
                                                                                                auxAsociado[i].nombre,
                                                                                                auxAsociado[i].apellido,
                                                                                                auxAsociado[i].estado,
                                                                                                auxAsociado[i].dni,
                                                                                                auxAsociado[i].edad);
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        printf("\nNo hay asociados\n");
    }
    return 0;
}
