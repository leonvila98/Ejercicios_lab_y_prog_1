#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARACTERES 7

int getNombre(char *mensaje,char *mensajeError,int size,char *nombreResultado);
int isValidNombre(char *nombre,int size);

int main()
{
    char nombre[MAX_CARACTERES];
    if(getNombre("Ingrese nombre:\n","Error, nombre invalido\n",MAX_CARACTERES,nombre)==0)
    {
        printf("El nombre ingresado es:%s",nombre);
    }
    return 0;
}
int getNombre(char *mensaje,char *mensajeError,int size,char *nombreResultado)
{
    int charIngresados;
    char bufferNombre[size];
    if(mensaje!=NULL && mensajeError!=NULL && size<1000)
    {
        printf("\n%s",mensaje);
        fgets(bufferNombre,sizeof(bufferNombre),stdin);
        bufferNombre[strlen(bufferNombre)-1]='\0';
        charIngresados=strlen(bufferNombre);
        if(isValidNombre(bufferNombre,charIngresados)==1)
        {
            strncpy(nombreResultado,bufferNombre,size);
        }
        else
        {
            printf("\n%s",mensajeError);
            return -1;
        }
    }
    return 0;
}
int isValidNombre(char *nombre,int size)
{
    char buffer[size];
    for(int i=0;i<=size;i++)
    {
        if((nombre[i]>='a' && nombre[i]<='z')||
            (nombre[i]>='A' && nombre[i]<='Z'))
        {
            strncpy(nombre,buffer,size);
        }
        else
        {
            printf("%s",nombre);
            return 0;
        }
    }

    return 1;
}
