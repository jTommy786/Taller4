
#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50


int menu();
int ingresarDatos(char nombres[][MAX_NOMBRE], float precios[]);
float calcularTotal(float precios[], int n);
float calcularPromedio(float precios[], int n);
int buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int n, const char nombre[]);
void productoMasCaro(float precios[], int n, int *indice);
void productoMasBarato(float precios[], int n, int *indice);
