#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main()
{
    int op, datosIngresados=0, indice;
    int cantidadProductos = 0;
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    char nombreBusqueda[MAX_NOMBRE];
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
    if (datosIngresados!=1) {
        printf("Debe ingresar productos primero (opcion 1).\n");
    }else{
    printf("Precio total: %.2f $\n", calcularTotal(precios, cantidadProductos));
    }
    break;

    case 3: 
    if (datosIngresados!=1) {
        printf("Debe ingresar productos primero (opcion 1).\n");
    }else{
        indice = productoMasCaro(precios, cantidadProductos);
        printf("Mas caro: %s (%.2f $)\n", nombres[indice], precios[indice]);
        
        indice = productoMasBarato(precios, cantidadProductos);
        printf("Mas barato: %s (%.2f $)\n", nombres[indice], precios[indice]);
                
    }
    break;

    case 4:
    if (datosIngresados!=1) {
        printf("Debe ingresar productos primero (opcion 1).\n");
    }else{
    printf("\n El precio promedio de los productos es: %.2f $", calcularPromedio(precios, cantidadProductos));
    }
    break;

    case 5:
    if (datosIngresados!=1) {
        printf("Debe ingresar productos primero (opcion 1).\n");
    }else{
    printf("\n Ingrese el nombre del producto que desea buscar.");
    printf("\n>> ");
    fgets(nombreBusqueda, MAX_NOMBRE, stdin);
    nombreBusqueda[strcspn(nombreBusqueda, "\n")] = 0;  
    if (strlen(nombreBusqueda) == 0) {
        printf("El nombre no puede estar vacio.\n");
    } else {
        indice = buscarProducto(nombres, precios, cantidadProductos, nombreBusqueda);
        if (indice >= 0)
            printf("Precio de %s: %.2f $\n", nombres[indice], precios[indice]);
        else
            printf("Producto no encontrado.\n");
        break;
    }
}
   
    break;
    
    default:
    break;
    }

}while(op<=6);
    return 0;
}