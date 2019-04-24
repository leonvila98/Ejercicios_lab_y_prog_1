#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY_EMPLEADOS 3
/*
int emp_alta(Empleado arrayEmpleado[],int limite,int id);
int emp_baja(Empleado arrayEmpleado[],int limite);
int emp_buscarPorNombre(Empleado arrayEmpleado[],int limite,char *nombre,int *indice);
int emp_ordenarPorNombre(Empleado arrayEmpleado[],int limite);
*/

typedef struct
{
	int idEmpleado;
	int isEmpty;
	//-----------------LAS DOS DE ARRIBA VAN SIEMPRE
	char nombre[50];
}Empleado;

int emp_initArray(Empleado arrayEmpleado[],int limite);
int emp_mostrarArrayEmpleados(Empleado arrayEmpleado[],int limite);
int emp_lugarLibre(Empleado arrayEmpleado[],int limite,int *indice);

int main()
{
    Empleado auxEmpleado[QTY_EMPLEADOS];
    int i;
    int j=5;
    auxEmpleado[0].idEmpleado=5;
    auxEmpleado[1].idEmpleado=10;
    auxEmpleado[2].idEmpleado=15;
    strncpy(auxEmpleado[0].nombre,"juan",50);
    strncpy(auxEmpleado[1].nombre,"carlos",50);
    strncpy(auxEmpleado[2].nombre,"leon",50);

    emp_mostrarArrayEmpleados(auxEmpleado,QTY_EMPLEADOS);

    return 0;
}

int emp_initArray(Empleado arrayEmpleado[],int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        arrayEmpleado[i].isEmpty=1;
    }
    return 0;
}
int emp_mostrarArrayEmpleados(Empleado arrayEmpleado[],int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("\nNombre:%s ID:%d",arrayEmpleado[i].nombre,arrayEmpleado[i].idEmpleado);
    }
    return 0;
}
int emp_lugarLibre(Empleado arrayEmpleado[],int limite,int *indice)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++)
    {
        if(arrayEmpleado[i].isEmpty==1)
        {
            *indice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
