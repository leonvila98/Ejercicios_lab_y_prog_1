#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_NUMEROS 5

void burbujeoArrayInt(int *array,int limite);

int main()
{
    int array[CANTIDAD_NUMEROS]={1,6,4,2,9};
    burbujeoArrayInt(array,CANTIDAD_NUMEROS);
}

void burbujeoArrayInt(int *array,int limite)
{
    int flagSwap;
    int i;
    int buffer;
    do
    {
        for(i=0;i<limite;i++)
        {
            flagSwap=0;
            if(array[i]>array[i+1])
            {
                buffer=array[i];
                array[i]=array[i+1];
                array[i+1]=buffer;
                flagSwap=1;
            }
        }
    }while(flagSwap=0);
    for(int j=0;j<limite;j++)
    {
        printf("%d",array[j]);
    }
}
