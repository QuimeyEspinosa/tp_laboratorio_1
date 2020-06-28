#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "validations.h"

int menuOpciones()
{
    int opcion;

    printf("||Menu de opciones INSTRUMENTOS||\n\n");

    printf("1. Cargar los datos de los instrumentos desde el archivo DataInstruments.csv (modo texto).\n");
    printf("2. Cargar los datos de los instrumentos desde el archivo DataInstruments.bin (modo binario).\n");
    printf("3. Alta de instrumento\n");
    printf("4. Modificar datos de instrumento\n");
    printf("5. Baja de instrumento\n");
    printf("6. Listar instrumentos\n");
    printf("7. Ordenar instrumentos\n");
    printf("8. Mostrar lista filtrada\n");
    printf("9. Guardar los datos de los instrumentos en el archivo DataInstruments.csv (modo texto).\n");
    printf("10. Guardar los datos de los instrumentos en el archivo DataInstruments.bin (modo binario).\n");
    printf("11. Salir\n\n");

    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuModifications()
{
    int opcion;

    printf("\n1. Modificar Tipo\n");
    printf("2. Modificar Nombre\n");
    printf("3. Modificar Marca\n");
    printf("4. Modificar Color\n");
    printf("5. Modificar Proveedor\n");
    printf("6. Modificar Precio\n");
    printf("7. Modificar Stock\n");
    printf("8. Volver al menu principal\n\n");

    get_Entero(&opcion, 3, "Ingrese opcion: ", "Error, no es una opcion valida\n", 1, 8);

    return opcion;
}
int menuSort()
{
    int opcion;

    printf("\n1. Ordenar por ID\n");
    printf("2. Ordenar por Tipo\n");
    printf("3. Ordenar por Nombre\n");
    printf("4. Ordenar por Marca\n");
    printf("5. Ordenar por Color\n");
    printf("6. Ordenar por Proveedor\n");
    printf("7. Ordenar por Precio\n");
    printf("8. Ordenar por Stock\n");
    printf("9. Volver al menu principal\n\n");

    get_Entero(&opcion, 3, "Ingrese opcion: ", "Error, no es una opcion valida\n", 1, 8);

    return opcion;
}

int menuFilter()
{
    int opcion;

    printf("\n1. Mostrar lista filtrada de Stock\n");
    printf("2. Mostrar lista filtrada sin Stock\n");
    printf("3. Mostrar lista filtrada por instrumentos de cuerda\n");
    printf("4. Mostrar lista filtrada por instrumentos de percusion\n");
    printf("5. Mostrar lista filtrada por instrumentos de teclas\n");
    printf("6. Mostrar lista filtrada por instrumentos de viento\n");
    printf("7. Volver al menu principal\n\n");

    get_Entero(&opcion, 3, "Ingrese opcion: ", "Error, no es una opcion valida\n", 1, 7);

    return opcion;
}
