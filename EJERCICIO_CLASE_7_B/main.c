#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define CANTIDAD_PERSONAS 200

typedef struct
{
    char nombre[50];
    char apellido[50];
    int legajo;
}Persona;

int main()
{
    int length;
    char resultado[256];
    utn_getString("Ingrese string:\n","Error",1,50+1,2,resultado);
    length=strlen(resultado);
    if(length>0)
    {
        if(isNumerico(resultado))
        {
            printf("Es numerico\n");
        }
        if(isSoloLetras(resultado))
        {
            printf("Es solo letras\n");
        }
        if(isTel(resultado))
        {
            printf("Es telefono\n");
        }
        if(isAlfaNum(resultado))
        {
            printf("Es alfanumerico\n");
        }
        printf("%s",resultado);
    }

    return 0;
}
