#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"

int main()
{
    Persona *pArrayPersona[1000];
    int ultimoElementoArrayPersona = 0;
    int indiceActual;

    char bufferId[4096];
    char bufferNombre[4096];
    char bufferApellido[4096];
    char bufferEstado[4096];
    FILE *pFile=NULL;
    FILE *pFileBkp=NULL;
    pFile=fopen("data.csv","r");
    pFileBkp=fopen("data_bkp.csv","w");

    if(pFile!=NULL && pFileBkp!=NULL)
    {
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferEstado);
			Per_newStr(bufferId,bufferNombre,bufferApellido,bufferEstado);
		}
		fclose(pFile);
		fclose(pFileBkp);
    }
	printf("%s\n",bufferApellido);
    indiceActual = ultimoElementoArrayPersona;
    pArrayPersona[indiceActual] =  Per_new();

    return 0;
}
