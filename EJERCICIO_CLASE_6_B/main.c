#include <stdio.h>
#include <stdlib.h>

int utn_getString(  char *msg,
                    char *msgError,
                    int minimo,
                    int maximo,
                    int reintentos,
                    char *resultado);

int isValidNumero(char *str);

int utn_getNumero(  char *msg,
                    char *msgError,
                    int minimo,
                    int maximo,
                    int reintentos,
                    char *resultado);

int main()
{

    return 0;
}
int isValidNumero(char *str);
{
    return 0;
}
int utn_getString(  char *msg,
                    char *msgError,
                    int minimo,
                    int maximo,
                    int reintentos,
                    char *resultado)
{
    strncpy(resultado,"1234",5);
    return 0;
}
int utn_getNumero(  char *msg,
                    char *msgError,
                    int minimo,
                    int maximo,
                    int reintentos,
                    char *resultado);
{
    int retorno=-1;
    char buffer[17];
    int bufferInt;
    if(msg!=NULL)//validar todo
    {
        if(utn_getString(msg,msgError,1,16,reintentos,buffer)==0)
        {
            if(utn_isValidNumero)
            {
                bufferInt=atoi(buffer);
                if(bufferInt>=minimo && bufferInt<=maximo)
                {
                    *resultado=bufferInt;
                }
            }
        }
    }
    return retorno;
}
