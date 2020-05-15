#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "DataWarehouseEmployee.h"

#define TAM 1000 //cantidad de empleados que se pueden cargar
#define TAMSEC 5 // cantidad de sectores
#define CANTHARDCODE 5 //cantidad de hardcodeo

//mostra menu empleados
int printMenu();

//funcion que hardcodea empleados
void hardcodeEmployees(eEmployee vec[], int cant);

int main()
{
    char seguir = 's';
    char salirProg;
    int dataEntered; //flag que corrobora el alta de empleados
    int nextId = 1000;
    eEmployee list[TAM];
    eSector sectores[TAMSEC] =
    {
        {1, "Administracion"},
        {2, "Programacion"},
        {3, "Recursos"},
        {4, "Sistemas"},
        {5, "Ventas"}
    };

    initEmployees(list, TAM);

    hardcodeEmployees(list, CANTHARDCODE);
    nextId += CANTHARDCODE;

    do
    {
        switch(printMenu())
        {
        case 1:
            if(addEmployees(nextId, list, TAM, sectores, TAMSEC) == 1)
            {
                nextId++;
                dataEntered = 1;
            }
            system("pause");
            break;
        case 2:
            if(dataEntered == 0)
            {
                printf("No hay empleados que modificar\n\n");
            }
            else
            {
                modifyEmployee(list, TAM, sectores, TAMSEC);
            }
            system("pause");
            break;
        case 3:
            if(dataEntered == 0)
            {
                printf("No hay empleados que modificar\n\n");
            }
            else
            {
                removeEmployee(list, TAM, sectores, TAMSEC);
            }
            system("pause");
            break;
        case 4:
            if(dataEntered == 0)
            {
                printf("No hay empleados que informar\n\n");
            }
            else
            {
                sortEmployees(list, TAM, sectores, TAMSEC);
            }
            system("pause");
            break;
        case 5:
            do
            {
                fflush(stdin);
                printf("Desea salir del programa? s/n: ");
                scanf("%c", &salirProg);
            }
            while(salirProg != 's' && salirProg != 'n');
            break;
        default:
            system("cls");
            printf("No es una opcion valida\n");
            system("pause");
            fflush(stdin);
            break;
        }
        fflush(stdin);

        if(salirProg == 's')
        {
            seguir = 'n';
        }

    }
    while(seguir == 's');

    return 0;
}

void hardcodeEmployees(eEmployee vec[], int cant)
{
    for(int i=0; i<cant; i++)
    {
        vec[i].id = ids[i];
        strcpy(vec[i].name, nombres[i]);
        strcpy(vec[i].lastName, apellidos[i]);
        vec[i].idSector = sectores[i];
        vec[i].salary = sueldos[i];
        vec[i].isEmpty = 0;
    }
}

int printMenu()
{
    int opcion;

    system("cls");
    printf("**** Administracion de Empleados ****\n\n");
    printf("1-Alta empleados\n");
    printf("2-Modificar empleados\n");
    printf("3-Baja empleados\n");
    printf("4-Informes empleados\n");
    printf("5-Salir del programa\n\n");

    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


