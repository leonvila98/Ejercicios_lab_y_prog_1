typedef struct
{
    int idPantalla;
    int isEmpty;
    char nombre[50];
    char direccion[256];
    float precio;
    char tipo;
}Pantalla;

int pan_initArray(Pantalla arrayPantalla[],int limite);
int pan_AltaPantalla(Pantalla arrayPantalla[], int limite, int posLibre);
int pan_buscarPorId(Pantalla arrayPantalla[],int limite,int id,int *indice);
int pan_mostrarArrayPantalla(Pantalla arrayPantalla[],int limite);
