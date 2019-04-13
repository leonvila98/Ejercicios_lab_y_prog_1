#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 4

struct fecha
{
    int dia;
    int mes;
    int anio;
};
struct producto
{
    char nombre[20];
    char precio[20];
    struct fecha fechaIngreso;
};

int main()
{
    struct producto prod1[CANTIDAD];
    struct fecha fn[CANTIDAD];
    for(int i=0;i<CANTIDAD;i++)
    {
        __fpurge(stdin);
        utn_getString("\nIngrese nombre:","Error",1,20,0,prod1[i].nombre);
        utn_getString("\nIngrese precio:","Error",1,20,0,prod1[i].precio);
        getInt("Ingrese dia:","Error",1,3,0,&fn[i].dia);
        getInt("Ingrese mes:","Error",1,3,0,&fn[i].mes);
        getInt("Ingrese anio:","Error",1,5,0,&fn[i].anio);
    }
    //prod1.fechaIngreso=fn;
    for(int j=0;j<CANTIDAD;j++)
    {
        printf("\nNombre: %s",prod1[j].nombre);
        printf("Precio: %s",prod1[j].precio);
        printf("Fecha: %d/%d/%d",fn[j].dia,fn[j].mes,fn[j].anio);
    }
    return 0;
}
