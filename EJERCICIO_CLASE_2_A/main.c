#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_NUMEROS 3

int promedioNumerosIngresados(void);
int calcularPromedio(int valorAcumulado,int cantidad,float *promedio);

int main()
{
    promedioNumerosIngresados();
}
int promedioNumerosIngresados(void)
{
    int numeroIngresado;
    int acumulador=0;
    float promedio;
    int i;

    for(i=0;i<CANTIDAD_NUMEROS;i++)
    {
        printf("\nIngrese numero:");
        scanf("%d",&numeroIngresado);
        acumulador=numeroIngresado+acumulador;
    }
    //promedio=(float)acumulador/CANTIDAD_NUMEROS;
    if(calcularPromedio(acumulador,CANTIDAD_NUMEROS,&promedio)==0)
    {
        printf("\nel promedio es: %.2f",promedio);
    }
    else
    {
        printf("\nERROR");
    }
    return 0;
}


int calcularPromedio(int valorAcumulado,int cantidad,float *promedio)
{
    int retorno=-1;
    if(cantidad>0 && promedio!=NULL)
    {
        *promedio=(float)valorAcumulado/cantidad;
        retorno=0;
    }
    return retorno;
}
