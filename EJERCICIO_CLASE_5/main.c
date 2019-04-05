#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANTIDAD_NUMEROS 4

int getArrayInt(char *mensaje,char *mensajeError,int maximo,int minimo,int reintentos,int *arrayResultado,int limite);

int main()
{
    int arrayDeEnteros[CANTIDAD_NUMEROS];
    getArrayInt("Ingrese un numero\n","Error",100,0,0,arrayDeEnteros,CANTIDAD_NUMEROS);
}

int getArrayInt(char *mensaje,char *mensajeError,int maximo,int minimo,int reintentos,int *arrayResultado,int limite)
{
    int buffer;
    int retorno=-1;
    int i;

    printf("hola");
    if(mensaje!=NULL && mensajeError!=NULL &&
        maximo>=minimo && reintentos>=0 && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(getInt(mensaje,mensajeError,minimo,maximo,reintentos,&buffer)==0)
            {
                arrayResultado[i]=buffer;
            }
            else
            {
                printf("%s",mensajeError);
                break;
            }
        }
        retorno=0;
    }
    return retorno;
}

//int imprimirArray
