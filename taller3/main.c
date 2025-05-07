#include <stdio.h>
#include "funciones.h"

int main()
{
    int op, datosIngresados, indice;
    int cantidadProductos = 0;
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    do{
    op=menu();
    
    
    switch (op)
    {
    case 1:
                cantidadProductos = ingresarDatos(nombres, precios);
                datosIngresados = 1;
                printf("\nSe han registrado %d productos correctamente.\n", cantidadProductos);
                break;
        
        break;
    case 2: 
    if (!datosIngresados==1) {
        printf("Debe ingresar productos primero (opcion 1).\n");
    }else{
    printf("Precio total: %.2f $\n", calcularTotal(precios, cantidadProductos));
    }
    break;

    case 3: 
    if (!datosIngresados==1) {
        printf("Debe ingresar productos primero (opcion 1).\n");
    }else{
        indice = productoMasCaro(precios, cantidadProductos);
        printf("Mas caro: %s (%.2f $)\n", nombres[indice], precios[indice]);
        
        indice = productoMasBarato(precios, cantidadProductos);
        printf("Mas barato: %s (%.2f $)\n", nombres[indice], precios[indice]);
                
    }
    break;
    
    default:
        break;
    }

}while(op<=6);
    return 0;
}