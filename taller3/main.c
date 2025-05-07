#include <stdio.h>
#include "funciones.h"

int main()
{
    int op;
    int cantidadProductos = 0;
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];

    op=menu();
    
    switch (op)
    {
    case 1:
                cantidadProductos = ingresarDatos(nombres, precios);
                printf("\nSe han registrado %d productos correctamente.\n", cantidadProductos);
                break;
        
        break;
    
    default:
        break;
    }

    return 0;
}