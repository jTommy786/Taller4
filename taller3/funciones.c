#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu() {
    int opc;
    char entrada[100];

    while (1) {
        printf("\nSeleccione una opción:\n");
        printf("1. Ingresar Producto\n");
        printf("2. Mostrar Precio Total del inventario\n");
        printf("3. Mostrar Promedio del Precio del inventario\n");
        printf("4. Buscar precio según el Producto\n");
        printf("5. Salir\n>> ");

        fgets(entrada, sizeof(entrada), stdin);
        if (sscanf(entrada, "%d", &opc) == 1 && opc >= 1 && opc <= 5) {
            return opc;
        } else {
            printf("Por favor, introduzca un número válido entre 1 y 5.\n");
        }
    }
}

int ingresarDatos(char nombres[][MAX_NOMBRE], float precios[]) {
    int n;
    char entrada[100];

    while (1) {
        printf("Ingrese la cantidad de productos (1 a %d): ", MAX_PRODUCTOS);
        fgets(entrada, sizeof(entrada), stdin);
        if (sscanf(entrada, "%d", &n) == 1 && n >= 1 && n <= MAX_PRODUCTOS) {
            break;
        } else {
            printf("Valor no válido. Intente de nuevo.\n");
        }
    }

    for (int i = 0; i < n; i++) {
        // Ingreso del nombre
        while (1) {
            printf("Producto %d - Nombre: ", i + 1);
            fgets(nombres[i], MAX_NOMBRE, stdin);
            nombres[i][strcspn(nombres[i], "\n")] = 0;  

            if (strlen(nombres[i]) == 0) {
                printf("El nombre no puede estar vacío.\n");
            } else {
                break;
            }
        }

        // Ingreso del precio
        while (1) {
            printf("Producto %d - Precio: ", i + 1);
            fgets(entrada, sizeof(entrada), stdin);
            if (sscanf(entrada, "%f", &precios[i]) == 1 && precios[i] >= 0) {
                break;
            } else {
                printf("Ingrese un precio válido (número positivo).\n");
            }
        }
    }

    return n;
}
