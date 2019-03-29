#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char caracterValidado;

    if(getChar("Ingrese caracter:\n","Error\n",'a','z',3,&caracterValidado)==0)
    {
        printf("El caracter es:%c",caracterValidado);
    }
    return 0;
}







