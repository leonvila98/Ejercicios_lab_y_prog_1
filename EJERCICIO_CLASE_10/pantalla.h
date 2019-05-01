typedef struct
{
    int idPantalla;
    int isEmpty;
    char nombre[50];
    char direccion[256];
    float precio;
    char tipo[50];
}Pantalla;

int pan_initArray(Pantalla arrayPantalla[],int limite);
int pan_altaPantalla(Pantalla arrayPantalla[], int limite, int *indice);
int pan_bajaPantalla(Pantalla arrayPantalla[], int id, int limite);
int pan_buscarPorId(Pantalla arrayPantalla[],int limite,int id,int *indice);
int pan_mostrarArrayPantalla(Pantalla arrayPantalla[],int limite);
int pan_modificarPantalla(Pantalla arrayPantalla[],int id,int limite);
