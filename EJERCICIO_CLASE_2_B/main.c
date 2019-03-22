#include <stdio.h>
#include <stdlib.h>
int calcularMaxMinEnteros(int cantidadNumeros,int *maximo,int *minimo);

int main()
{
    int min;
    int max;
    calcularMaxMinEnteros(4,&max,&min);
    printf("El minimo es %d y el maximo es %d",min,max);
    return 0;
}

int calcularMaxMinEnteros(int cantidadNumeros,int *maximo,int *minimo)
{
    int acumulador;
    int i;
    int flag=1;
    int retorno=-1;

    if(*maximo!=NULL && *minimo!=NULL)
    {
        for(i=0;i<cantidadNumeros;i++)
        {
            printf("\nIngrese el numero:");
            scanf("%d",&acumulador);
            if(flag==1)
            {
                *maximo=acumulador;
                *minimo=acumulador;
                flag=0;
            }
            if(acumulador<*minimo)
            {
                *minimo=acumulador;
            }
            if(acumulador>*maximo)
            {
                *maximo=acumulador;
            }
        }
        retorno=0;
    }
    else
    {
        printf("ERROR");
    }
    return retorno;
}
