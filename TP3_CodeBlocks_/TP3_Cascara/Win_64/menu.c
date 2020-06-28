#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "validations.h"

int menuOpciones()
{
    int opcion;

    printf("||Menu de opciones Empleados||\n\n");

    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n\n");

    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuModifications()
{
    int opcion;

    printf("\n1. Modificar nombre\n");
    printf("2. Modificar horas trabajadas\n");
    printf("3. Modificar sueldo\n");
    printf("4. Volver al menu principal\n\n");

    get_Entero(&opcion, 3, "Ingrese opcion: ", "Error, no es una opcion valida\n", 1, 4);

    return opcion;
}
int menuSort()
{
    int opcion;

    printf("\n1. Ordenar por ID\n");
    printf("2. Ordenar por nombre\n");
    printf("3. Ordenar por horas trabajadas\n");
    printf("4. Ordenar por sueldo\n");
    printf("5. Volver al menu principal\n\n");

    get_Entero(&opcion, 3, "Ingrese opcion: ", "Error, no es una opcion valida\n", 1, 5);

    return opcion;
}
