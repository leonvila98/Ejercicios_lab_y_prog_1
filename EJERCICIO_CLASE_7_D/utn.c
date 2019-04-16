#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValidInt(int numero,int max,int min)
{
    if(numero<=max && numero>=min)
    {
        return 1;
    }
    return 0;
}

int getInt(char *mensaje,char *mensajeError,int minimo,
            int maximo,int reintentos,int *resultado)
{
    int buffer;
    int retorno=-1;
    if(mensaje != NULL && mensajeError != NULL && maximo >= minimo && reintentos>=0)
    {
        do
        {
            printf("%s",mensaje);
            scanf("%d",&buffer);
            if(isValidInt(buffer,maximo,minimo))
            {
                *resultado=buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    else
    {
        printf("%s",mensajeError);
    }
    return retorno;
}
int isValidFloat(float numero,float max,float min)
{
    if(numero<=max && numero>=min)
    {
        return 1;
    }
    return 0;
}

int getFloat(char *mensaje,char *mensajeError,float minimo,float maximo,int reintentos,float *resultado)
{
    int retorno=-1;
    float buffer;
    if(mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            printf("%s",mensaje);
            scanf("%f",&buffer);
            if(isValidFloat(buffer,maximo,minimo))
            {
                *resultado=buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}

int isValidChar(char caracter,char min,char max)
{
    if(caracter<=max && caracter>=min)
    {
        return 1;
    }
    return 0;
}
int getChar(char *mensaje,char *mensajeError,char minimo,char maximo,int reintentos,char *resultado)
{
    int retorno=-1;
    char buffer;
    if(mensaje!=NULL && mensajeError!=NULL && maximo>=minimo && reintentos>=0)
    {
        do
        {
            printf("%s",mensaje);
//            __fpurge(stdin);
            scanf("%c",&buffer);
            if(isValidChar(buffer,minimo,maximo))
            {
                *resultado=buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}
void mostrarArrayInt(int *array,int limite)
{
    if(array!=NULL && limite>0)
    {
        for(int i=0;i<limite;i++)
        {
            printf("%d",array[i]);
        }
    }
}
void burbujeoArrayInt(int *array,int limite)
{
    int i;
    int buffer;
    for(int j=0;j<limite;j++)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i]>array[i+1])
            {
                buffer=array[i];
                array[i]=array[i+1];
                array[i+1]=buffer;
            }
        }
    }
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
            //buffer[strlen(buffer)-1]='\0';
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
        }while(reintentos>0);
    }
    return retorno;
}
/**
* \brief verifica si el valor recibido es numerico
* \param str array con la cadena a ser analizada
* \return 1 si es numerico y 0 si no lo es
*
*/
int isNumerico(char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]>='0' && str[i]<='9')//pregunto si pertenece
        {
            return 1;
        }
        i++;
    }
    return 0;
}
/**
* \brief verifica si el valor recibido contiene solo letras
* \param str array con la cadena a ser analizada
* \return 1 si contiene solo letras y 0 si no contiene
*
*/
int isSoloLetras(char *str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if((str[i]!=' ')&&(str[i]<'a'||str[i]>'z')&&(str[i]<'A'||str[i]>'Z'))//pregunto si no pertenece
        {
            return 0;
        }
    }
    return 1;
}
/**
* \brief verifica si el valor recibido es alfanumerico
* \param str array con la cadena a ser analizada
* \return 1 si es alfanumerico y 0 si no lo es
*
*/
int isAlfaNum(char *str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if((str[i]!=' ')&&(str[i]<'a'||str[i]>'z')&&(str[i]<'A'||str[i]>'Z')&&(str[i]<'0'||str[i]>'9'))//pregunto si no pertenece
        {
            return 0;
        }
    }
    return 1;
}
/**
* \brief verifica si el valor recibido es telefono
* \param str array con la cadena a ser analizada
* \return 1 si contine numeros, espacio y un guion y 0 si no
*
*/
int isTel(char *str)
{
    int contadorGuion=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if((str[i]!=' ')&&(str[i]!='-')&&(str[i]<'0'||str[i]>'9'))//pregunto si no pertenece
        {
            return 0;
        }
        if(str[i]=='-')
        {
            contadorGuion++;
        }
    }
    if(contadorGuion==1)
    {
        return 1;
    }
    return 0;
}
/**
* \brief solicita un string de solo letras
* \param resultado devuelve el texto ingresado
* \return 1 si es solo letras y 0 si no
*
*/
int getStringLetras(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado)
{
    char buffer[maximo];
    utn_getString(msg,msgError,minimo,maximo+1,reintentos,buffer);
    if(isSoloLetras(buffer))
    {
        strncpy(resultado,buffer,maximo);
        return 1;
    }
    return 0;
}
/**
* \brief solicita un string de solo numeros
* \param resultado devuelve el texto ingresado
* \return 1 si es solo numeros y 0 si no
*
*/
int getStringNumeros(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado)
{
    char buffer[maximo];
    utn_getString(msg,msgError,minimo,maximo+1,reintentos,buffer);
    if(isNumerico(buffer))
    {
        strncpy(resultado,buffer,maximo);
        return 1;
    }
    return 0;
}
