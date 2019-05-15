#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

int main()
{
    Empleado *pArrayEmpleado[1000];
    int ultimoElementoArrayEmpleado = 0;
    int indiceActual;
    int auxInt;
    char auxName[50];
    float auxPeso;
    int auxEstado;
    int i=

    indiceActual = ultimoElementoArrayEmpleado;
    pArrayEmpleado[indiceActual] =  Emp_new();

	if(pArrayEmpleado[indiceActual] != NULL)
	{
		printf("OK");
		if(!Emp_setId(pArrayEmpleado[indiceActual],14))
		{
			Emp_getId(pArrayEmpleado[indiceActual], &auxInt);
			printf("\nID:%d",auxInt);
		}
		if(!Emp_setNombre(pArrayEmpleado[indiceActual],"leon"))
		{
			Emp_getNombre(pArrayEmpleado[indiceActual],auxName);
			printf("\nNombre:%s",auxName);
		}
		if(!Emp_setPeso(pArrayEmpleado[indiceActual],56.75))
		{
			Emp_getPeso(pArrayEmpleado[indiceActual],&auxPeso);
			printf("\nPeso:%.2f",auxPeso);
		}
		if(!Emp_setEstado(pArrayEmpleado[indiceActual],3))
		{
			Emp_getEstado(pArrayEmpleado[indiceActual],&auxEstado);
			printf("\nEstado:%d",auxEstado);
		}
		ultimoElementoArrayEmpleado++;
	}
		if(pArrayEmpleado[indiceActual] != NULL)
	{
		printf("OK");
		if(!Emp_setId(pArrayEmpleado[indiceActual],14))
		{
			Emp_getId(pArrayEmpleado[indiceActual], &auxInt);
			printf("\nID:%d",auxInt);
		}
		if(!Emp_setNombre(pArrayEmpleado[indiceActual],"capo"))
		{
			Emp_getNombre(pArrayEmpleado[indiceActual],auxName);
			printf("\nNombre:%s",auxName);
		}
		if(!Emp_setPeso(pArrayEmpleado[indiceActual],56.75))
		{
			Emp_getPeso(pArrayEmpleado[indiceActual],&auxPeso);
			printf("\nPeso:%.2f",auxPeso);
		}
		if(!Emp_setEstado(pArrayEmpleado[indiceActual],2))
		{
			Emp_getEstado(pArrayEmpleado[indiceActual],&auxEstado);
			printf("\nEstado:%d",auxEstado);
		}
		ultimoElementoArrayEmpleado++;
	}

    return 0;
}
