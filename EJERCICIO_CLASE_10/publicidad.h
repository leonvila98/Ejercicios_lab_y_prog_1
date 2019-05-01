typedef struct
{
    int idPublicidad;
    int isEmpty;
    char cuit[20];
    int dias;
    char archivo[256];
    int idPantalla;
}Publicidad;

int pub_initArray(Publicidad arrayPublicidad[],int limite);
int pub_mostrarArrayPublicidad(Publicidad arrayPublicidad[],int limite);
int pub_lugarLibre(Publicidad arrayPublicidad[],int limite,int *indice);
int pub_buscarPorId(Publicidad arrayPublicidad[],int limite,int id,int *indice);
int pub_altaPublicidad(Publicidad arrayPublicidad[],int idPantalla, int limite, int *indice);
int pub_buscarPorCuit(Publicidad arrayPublicidad,int limite,char *cuit,int *indice);
