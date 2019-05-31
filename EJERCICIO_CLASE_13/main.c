#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"
#define true 1
#define false 0
#define SIZE_PUNTEROS 1000

int main()
{
    Persona* pArrayPersona[SIZE_PUNTEROS];
    Per_initArray(pArrayPersona,SIZE_PUNTEROS);

    Per_parserPersonas("dataCpy.csv",pArrayPersona,SIZE_PUNTEROS);


    /*int indiceActual=0;

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
            fprintf(pFileBkp,"%s,%s,%s,%s\n",bufferId,bufferNombre,bufferApellido,bufferEstado);
            pArrayPersona[indiceActual]=Per_newStr(bufferId,bufferNombre,bufferApellido,bufferEstado);
            indiceActual++;
		}
		fclose(pFile);
		fclose(pFileBkp);
    }*/
    return 0;
}
