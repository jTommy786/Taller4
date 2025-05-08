#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu() {
    int opc;
    char entrada[100];

    while (1) {
        printf("\nSeleccione una opcion:\n");
        printf("1. Ingresar Producto\n");
        printf("2. Mostrar Precio Total del inventario\n");
        printf("3. Mostrar Producto mas caro y mas barato\n");
        printf("4. Mostrar Promedio del Precio del inventario\n");
        printf("5. Buscar precio segun el Producto\n");
        printf("6. Salir\n>> ");

        fgets(entrada, sizeof(entrada), stdin);
        if (sscanf(entrada, "%d", &opc) == 1 && opc >= 1 && opc <= 5) {
            return opc;
        } else {
            printf("Por favor, introduzca un numero valido entre 1 y 5.\n");
        }
    }
}

//ingreso de productos.

int ingresarDatos(char nombres[][MAX_NOMBRE], float precios[]) {
    int n=0;
    char entrada[100];

    while (1) {
        printf("Ingrese la cantidad de productos (1 a %d): ", MAX_PRODUCTOS);
        fgets(entrada, sizeof(entrada), stdin);
        if (sscanf(entrada, "%d", &n) == 1 && n >= 1 && n <= MAX_PRODUCTOS) {
            break;
        } else {
            printf("Valor no valido. Intente de nuevo.\n");
        }
    }

    for (int i = 0; i < n; i++) {

        // ingreso del nombre

        while (1) {
            printf("Producto %d - Nombre: ", i + 1);
            fgets(nombres[i], MAX_NOMBRE, stdin);
            nombres[i][strcspn(nombres[i], "\n")] = 0;  

            if (strlen(nombres[i]) == 0) {
                printf("El nombre no puede estar vacio.\n");
            } else {
                break;
            }
        }

        // ingreso del precio

        while (1) {
            printf("Producto %d - Precio: ", i + 1);
            fgets(entrada, sizeof(entrada), stdin);
            if (sscanf(entrada, "%f", &precios[i]) == 1 && precios[i] >= 0) {
                break;
            } else {
                printf("Ingrese un precio valido (numero positivo).\n");
            }
        }
    }

    return n;
}




//calcular total del inventario.

float calcularTotal(float precios[], int n){
    float total=0;

    for(int i=0; i<n;i++){
        total+=precios[i];
    }
    return total;
}

//producto mas caro y mas barato.

int productoMasCaro(float precios[], int n) {
    int indice = 0;
    for (int i = 0; i < n; i++) {
        if (precios[i] > precios[indice])
            indice = i;
    }
    return indice;
}

int productoMasBarato(float precios[], int n) {
    int indice = 0;
    for (int i = 0; i < n; i++) {
        if (precios[i] < precios[indice])
            indice = i;
    }
    return indice;
}

//calcular promedio

float calcularPromedio(float precios[], int n){
    return calcularTotal(precios, n)/n;
}

//busqueda

int buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int n, const char nombre[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(nombres[i], nombre) == 0)
            return i;
    }
    return -1;
}


