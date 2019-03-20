#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_NUMEROS 5

int pedirSumar(void);
int promedioNumeros(void);

int main()
{
    promedioNumeros();
    return 0;
}

/*int pedirSumar(void)
{
    int valorA;
    int valorB;
    int resultado;

    printf("\nIngrese un numero:");
    scanf("%d", &valorA);
    printf("\nIngrese otro numero:");
    scanf("%d", &valorB);
    resultado=valorA+valorB;
    printf("%d",resultado);
    return 0;
}
*/
int promedioNumeros(void)
{
    int sumatoria=0;
    int numeroIngresado;
    int promedio;
    int i;

    for(i=0;i<CANTIDAD_NUMEROS;i++)
    {
        printf("\nIngrese numero:");
        scanf("%d",&numeroIngresado);
        sumatoria=sumatoria+numeroIngresado;
        promedio=sumatoria/CANTIDAD_NUMEROS;
    }

    printf("%d",promedio);

    return 0;
}

