#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int numero=0;
    utn_getNumero("ingrese numero:","error",1,9999,1,&numero);
    printf("\nEl numero es:%d",numero);
    return 0;
}

int utn_getString(  char *msg,
                    char *msgError,
                    int minimo,
                    int maximo,
                    int reintentos,
                    char *resultado)
{
    int retorno=-1;
    int size;
    char buffer[maximo];
    if(msg!=NULL && msgError!=NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            printf("\n%s",msg);
            fgets(buffer,sizeof(buffer),stdin);
            buffer[strlen(buffer)-1]='\0';
            size=strlen(buffer);
            if(size<=maximo && size>=minimo)
            {
                strncpy(resultado,buffer,maximo);
                retorno=0;
                break;
            }
            else
            {
                printf("\n%s",msgError);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}
int utn_isValidNumero(char *str)
{
   int retorno=-1;
   for(int i=0;str[i] != '\0';i++)
   {
       if(str[i]>='0' && str[i]<='9')
       {
            retorno=0;
       }
       else
       {
           return 1;
       }
   }
   return retorno;
}
int utn_getNumero(  char *msg,
                    char *msgError,
                    int minimo,
                    int maximo,
                    int reintentos,
                    int *resultado)
{
    int retorno=-1;
    char buffer[10];
    int bufferInt;
    if(msg!=NULL && msgError!=NULL && minimo<=maximo && reintentos>=0)
    {
        if(utn_getString(msg,msgError,1,16,reintentos,buffer)==0)
        {
            if(utn_isValidNumero(buffer)==0)
            {
                bufferInt=atoi(buffer);
                if(bufferInt<=maximo && bufferInt>=minimo)
                {
                    *resultado=bufferInt;
                    retorno=0;
                }
                else
                {
                    printf("\n%s",msgError);
                }
            }
            else
            {
                printf("\n%s",msgError);
            }
        }
    }
    return retorno;
}
