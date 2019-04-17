#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define QTY_CARACTERES 50
#define QTY_EMPLEADOS 5


int initMatriz(char matriz[][50],int cantidadElementos);
int encontrarVacio(char matriz[][50],int cantidadElementos);
int encontrarNombre(char matriz[][50],char *nombreABuscar,int cantidadElementos);
int printMatriz(char matriz[][50],int cantidadElementos);

int main()
{
    int opcion=0;
    char arrayNombres[QTY_EMPLEADOS][50];
    char auxName[QTY_CARACTERES];
    char auxApellido[QTY_CARACTERES];
    int lugarLibre;
    getInt("Ingrese una opcion:","Error",1,6,2,&opcion);

    while(opcion!=4)
    {
        printf("1.Alta de usuario\n");
        printf("2.Baja de usuario\n");
        printf("3.Modificacion de usuario\n");
        printf("4.Mostrar usuario\n");
        printf("5.Buscar usuario\n");
        printf("6.Finalizar\n");

        switch(opcion)
        {
            case 1:
                lugarLibre=encontrarVacio(arrayNombres,QTY_EMPLEADOS);
                if(lugarLibre>=0)
                {
                    getName("\nIngrese nombre:","Error",2,QTY_CARACTERES,2,auxName);
                }
        }
    }

    initMatriz(arrayNombres,QTY_EMPLEADOS);

    strncpy(arrayNombres[0],"Juan",50);
    strncpy(arrayNombres[1],"Leon",50);


    printMatriz(arrayNombres,QTY_EMPLEADOS);

    printf("Posicion libre: %d\n",encontrarVacio(arrayNombres,QTY_EMPLEADOS));

    printf("Posicion del nombre:%d\n",encontrarNombre(arrayNombres,"Juan",QTY_EMPLEADOS));

}

int initMatriz(char matriz[][50],int cantidadElementos)
{
    for(int i=0;i<cantidadElementos;i++)
    {
        strncpy(matriz[i],"\0",50);
    }
    return 0;
}

int encontrarVacio(char matriz[][50],int cantidadElementos)
{
    int retorno=-1;
    int i;
    for(i=0;i<cantidadElementos;i++)
    {
        if(strcmp(matriz[i],"\0")==0)
        {
            retorno=i+1;
            break;
        }
    }
    return retorno;
}

int encontrarNombre(char matriz[][50],char *nombreABuscar,int cantidadElementos)
{
    int retorno=-1;
    int i;
    for(i=0;i<cantidadElementos;i++)
    {
        if(strcmp(matriz[i],nombreABuscar)==0)
        {
            retorno=i+1;
        }
    }
    return retorno;
}

int printMatriz(char matriz[][50],int cantidadElementos)
{
    for(int i=0;i<cantidadElementos;i++)
    {
        printf("%s\n",matriz[i]);
    }
    return 0;
}
