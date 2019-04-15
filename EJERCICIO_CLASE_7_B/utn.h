
int getInt(char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos,int *resultado);
int isValidInt(int numero,int max,int min);
int getFloat(char *mensaje,char *mensajeError,float minimo,float maximo,int reintentos,float *resultado);
int isValidFloat(float numero,float max,float min);
int getChar(char *mensaje,char *mensajeError,char minimo,char maximo,int reintentos,char *resultado);
int isValidChar(char caracter,char min,char max);
void mostrarArrayInt(int *array,int limite);
void burbujeoArrayInt(int *array,int limite);
int utn_getString(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado);
int utn_isValidNumero(char *str);
int utn_getNumero(char *msg,char *msgError,int minimo,int maximo,int reintentos,int *resultado);

int isNumerico(char *str);
int isTel(char *str);
int isAlfaNum(char *str);
int isSoloLetras(char *str);
