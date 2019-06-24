int controller_loadFromText(char* path , LinkedList* pArrayListCliente);
int controller_ventasLoadFromText(char* pathVentas, LinkedList* pArrayVentas);
int controller_loadFromBinary(char* path , LinkedList* pArrayListCliente);
int controller_addCliente(LinkedList* pArrayListCliente);
int controller_addVenta(LinkedList* pArrayVentas,LinkedList* pArrayClientes);
int controller_editCliente(LinkedList* pArrayListCliente);
int controller_removeCliente(LinkedList* pArrayClientes,LinkedList* pArrayVentas);
int controller_removeVenta(LinkedList* pArrayVentas);
int controller_ListCliente(LinkedList* pArrayListCliente);
int controller_ListVentas(LinkedList* pArrayVentas,LinkedList* pArrayClientes);
int controller_ListVentasByProducto(LinkedList* pArrayVentas,LinkedList* pArrayClientes);
int controller_sortCliente(LinkedList* pArrayListCliente);
int controller_saveClientesAsText(char* pathClientes, LinkedList* pArrayClientes);
int controller_saveVentasAsText(char* pathVentas, LinkedList* pArrayVentas);
int controller_SaveInformeVentas(char* path,LinkedList* pArrayVentas,LinkedList* pArrayClientes);


