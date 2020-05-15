#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Validations.h"
#include "ArrayEmployees.h"

int printMenuModifications()
{
    int opcion;

    system("cls");
    printf("**** Modificaciones ****\n\n");
    printf("1-Modificar Nombre\n");
    printf("2-Modificar Apellido\n");
    printf("3-Modificar Salario\n");
    printf("4-Modificar Sector\n");
    printf("5-Volver al menu principal\n\n");

    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int printMenuInformes()
{
    int opcion;

    system("cls");
    printf("**** Informes Employees ****\n\n");
    printf("1-Informar Empleados alfabeticamente por apellido y sector\n");
    printf("2-Informar Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n");
    printf("3-Volver al menu principal\n\n");

    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void initEmployees(eEmployee employees[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        employees[i].isEmpty = 1;
    }
}

int addDescriptionSector(char description[], int id, eSector sectores[], int tamSec)
{
    int todoOk = 0;

    for(int i=0; i<tamSec; i++)
    {
        if(sectores[i].idSector == id)
        {
            strcpy(description, sectores[i].description);
            todoOk = 1;
        }
    }
    return todoOk;
}

void printEmployee(eEmployee employee, eSector sectores[], int tamSec)
{
    char nameSector[20];

    addDescriptionSector(nameSector, employee.idSector, sectores, tamSec);

    printf("  %d %10s   %10s     %7.2f    %10s\n", employee.id, employee.name, employee.lastName, employee.salary, nameSector);
}

void printEmployees(eEmployee employees[], int tam, eSector sectores[], int tamSec)
{
    int flag = 0;
    //system("cls");
    printf("***** List of employees *****\n");
    printf("   Id      Nombre     Apellido      Sueldo         Sector\n\n");

    for(int i=0; i<tam; i++)
    {
        if(employees[i].isEmpty == 0)
        {
            printEmployee(employees[i], sectores, tamSec);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("*** No hay empleados que listar ***\n");
    }
}

int findEmployee(eEmployee employee[], int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(employee[i].isEmpty /*== 1*/)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int findEmployeeById(int id, eEmployee employee[], int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(employee[i].id == id && employee[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void printSector(eSector sector, int tamSec)
{
    printf("  %4d %10s  \n", sector.idSector, sector.description);
}

void printSectores(eSector sectores[], int tamSec)
{
    printf("\n***** Lista de sectores *****\n");
    printf("   Id      Sector\n\n");

    for(int i=0; i<tamSec; i++)
    {
        printSector(sectores[i], tamSec);
    }
}

int addEmployees(int idx, eEmployee employee[], int tam, eSector sectores[], int tamSec)
{
    int dataEntered = 0;
    int indice = findEmployee(employee, tam);
    char auxCad[100];
    eEmployee auxEmployee;

    system("cls");

    printf("***** ALTA EMPLEADO *****\n\n");

    if(indice == -1) //verificar si hay lugar
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        auxEmployee.id = idx;

        //PEDIR RESTO DE DATOS CON FUNCIONES Y VALIDACIONES
        getString(auxCad, 51, "Ingrese nombre empleado: ", "Error, reingrese nombre empleado: ");
        strLwr(auxCad);
        auxCad[0] = toupper(auxCad[0]);
        strcpy(auxEmployee.name, auxCad);

        getString(auxCad, 51, "Ingrese apellido empleado: ", "Error, reingrese apellido empleado: ");
        strLwr(auxCad);
        auxCad[0] = toupper(auxCad[0]);
        strcpy(auxEmployee.lastName, auxCad);

        printf("Ingrese salario del empleado: ");
        scanf("%f", &auxEmployee.salary);
        while(auxEmployee.salary < -1)
        {
            printf("Error, Reingrese edad de la mascota: ");
            scanf("%f", &auxEmployee.salary);
        }

        printSectores(sectores, tamSec);

        printf("Ingrese id del sector a asignar al empleado: ");
        scanf("%d", &auxEmployee.idSector);
        while(auxEmployee.idSector > 5 || auxEmployee.idSector < 1)
        {
            printf("Error, Reingrese id del sector a asignar al empleado: ");
            scanf("%d", &auxEmployee.idSector);
        }

        auxEmployee.isEmpty = 0;

        employee[indice] = auxEmployee;//copio datos del empleado al primer indice disponible

        dataEntered = 1;

    }//else exterior

    return dataEntered;

}//fin funcion ALTA

void modifyEmployee(eEmployee employee[], int tam, eSector sectores[], int tamSec)
{
    char seguir = 's';
    char salirProg;

    do
    {
        switch(printMenuModifications())
        {
        case 1:
            modifyEmployeeName(employee, tam, sectores, tamSec);
            system("pause");
            break;
        case 2:
            modifyEmployeeLastName(employee, tam, sectores, tamSec);
            system("pause");
            break;
        case 3:
            modifyEmployeeSalary(employee, tam, sectores, tamSec);
            system("pause");
            break;
        case 4:
            modifyEmployeeSector(employee, tam, sectores, tamSec);
            system("pause");
            break;
        case 5:
            do
            {
                fflush(stdin);
                printf("Desea volver al menu principal? s/n: ");
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
}

void modifyEmployeeName(eEmployee employee[], int tam, eSector sectores[], int tamSec)
{
    int indice;
    int idBuscado;
    char confirmMod;
    char nuevoNombre[20]; //MODIFICAR TIPO DE VARIABLE EN BASE A LO QUE SE PIDA MODIFICAR
    char auxCad[100];

    system("cls");

    printf("***** Modificar nombre *****\n\n");

    printf("Ingrese id del empleado a modificar el nombre: ");
    scanf("%d", &idBuscado);

    indice = findEmployeeById(idBuscado, employee, tam);

    if(indice == -1)
    {
        printf("No existe un empleado con el ID ingresado\n\n");
    }
    else
    {
        printEmployee(employee[indice], sectores, tamSec);

        getString(auxCad, 51, "Ingrese nombre empleado a modificar: ", "Error, reingrese nombre empleado: ");
        strLwr(auxCad);
        auxCad[0] = toupper(auxCad[0]);
        strcpy(nuevoNombre, auxCad);

        printf("Confirma la modificacion del nombre del empleado? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmMod);

        if(confirmMod == 's' || confirmMod == 'S')
        {
            strcpy(employee[indice].name, nuevoNombre);
            printf("Se ha actualizado el nombre del empleado con exito\n\n");
        }
        else
        {
            printf("No se ha modificado al empleado\n\n");
        }//else interior

    }//else exterior
}

void modifyEmployeeLastName(eEmployee employee[], int tam, eSector sectores[], int tamSec)
{
    int indice;
    int idBuscado;
    char confirmMod;
    char nuevoApellido[20]; //MODIFICAR TIPO DE VARIABLE EN BASE A LO QUE SE PIDA MODIFICAR
    char auxCad[100];

    system("cls");

    printf("***** Modificar apellido *****\n\n");

    printf("Ingrese id del empleado a modificar el apellido: ");
    scanf("%d", &idBuscado);

    indice = findEmployeeById(idBuscado, employee, tam);

    if(indice == -1)
    {
        printf("No existe un empleado con el ID ingresado\n\n");
    }
    else
    {
        printEmployee(employee[indice], sectores, tamSec);

        getString(auxCad, 51, "Ingrese apellido empleado: ", "Error, reingrese apellido empleado: ");
        strLwr(auxCad);
        auxCad[0] = toupper(auxCad[0]);
        strcpy(nuevoApellido, auxCad);

        printf("Confirma la modificacion del apellido del empleado? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmMod);

        if(confirmMod == 's' || confirmMod == 'S')
        {
            strcpy(employee[indice].lastName, nuevoApellido);
            printf("Se ha actualizado el apellido del empleado con exito\n\n");
        }
        else
        {
            printf("No se ha modificado al empleado\n\n");
        }//else interior

    }//else exterior
}

void modifyEmployeeSalary(eEmployee employee[], int tam, eSector sectores[], int tamSec)
{
    int indice;
    int idBuscado;
    char confirmMod;
    float nuevoSalario;

    system("cls");

    printf("***** Modificar salario *****\n\n");

    printf("Ingrese id del empleado a modificar el salario: ");
    scanf("%d", &idBuscado);

    indice = findEmployeeById(idBuscado, employee, tam);

    if(indice == -1)
    {
        printf("No existe un empleado con el ID ingresado\n\n");
    }
    else
    {
        printEmployee(employee[indice], sectores, tamSec);

        printf("Ingrese el nuevo salario a actualizar: ");
        scanf("%f", &nuevoSalario);
        while(nuevoSalario < -1)
        {
            printf("Error, reingrese el nuevo salario a actualizar: ");
            scanf("%f", &nuevoSalario);
        }

        printf("Confirma la modificacion del apellido del empleado? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmMod);

        if(confirmMod == 's' || confirmMod == 'S')
        {
            employee[indice].salary = nuevoSalario;
            printf("Se ha actualizado el salario del empleado con exito\n\n");
        }
        else
        {
            printf("No se ha modificado al empleado\n\n");
        }//else interior

    }//else exterior
}

void modifyEmployeeSector(eEmployee employee[], int tam, eSector sectores[], int tamSec)
{
    int indice;
    int idBuscado;
    char confirmMod;
    int nuevoSector;

    system("cls");

    printf("***** Modificar sector *****\n\n");

    printf("Ingrese id del empleado a modificar el salario: ");
    scanf("%d", &idBuscado);

    indice = findEmployeeById(idBuscado, employee, tam);

    if(indice == -1)
    {
        printf("No existe un empleado con el ID ingresado\n\n");
    }
    else
    {
        printEmployee(employee[indice], sectores, tamSec);

        printf("Ingrese el nuevo salario a actualizar: ");
        scanf("%d", &nuevoSector);
        while(nuevoSector < 1 || nuevoSector > 5)
        {
            printf("Error, reingrese el nuevo salario a actualizar: ");
            scanf("%d", &nuevoSector);
        }

        printf("Confirma la modificacion del apellido del empleado? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmMod);

        if(confirmMod == 's' || confirmMod == 'S')
        {
            employee[indice].idSector = nuevoSector;
            printf("Se ha actualizado el salario del empleado con exito\n\n");
        }
        else
        {
            printf("No se ha modificado al empleado\n\n");
        }//else interior

    }//else exterior
}

void removeEmployee (eEmployee employee[], int tam, eSector sectores[], int tamSec)
{
    int indice;
    int idBuscado;
    char confirmBaja;

    system("cls");

    printf("***** Baja empleados *****\n\n");

    printf("Ingrese id del empleado a dar de baja: ");
    scanf("%d", &idBuscado);

    indice = findEmployeeById(idBuscado, employee, tam);

    if(indice == -1)
    {
        printf("No existe un empleado con el ID ingresado\n\n");
    }
    else
    {
        printEmployee(employee[indice], sectores, tamSec);

        printf("Confirma la baja del empleado? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmBaja);

        if(confirmBaja == 's')
        {
            employee[indice].isEmpty = 1;
            printf("Se ha dado de baja al empleado con exito\n\n");
        }
        else
        {
            printf("No se ha dado de baja al empleado\n\n");
        }//else interior

    }//else exterior

}//fin funcion

void sortEmployees(eEmployee employee[], int tam, eSector sectores[], int tamSec)
{
    char seguir = 's';
    char salirProg;
    int option;

    system("cls");

    printf("***** Informar empleados *****\n\n");

    do
    {
        switch(printMenuInformes())
        {
        case 1:
            printf("De que manera desea informar alfabeticamente empleados?\n\n");
            printf("1-Ascendente\n\n");
            printf("0-Descendente\n\n");
            fflush(stdin);
            printf("Indique opcion: ");
            scanf("%d", &option);
            while(option < 0 || option > 1)
            {
                printf("Error, indique una opcion valida: ");
                scanf("%d", &option);
            }
            sortEmployeesByLastNameAndSector(employee, tam, sectores, tamSec, option);
            printEmployees(employee, tam, sectores, tamSec);
            system("pause");
            break;
        case 2:
            sortEmployeesBySalarys(employee, tam, sectores, tamSec);
            system("pause");
            break;
        case 3:
            do
            {
                fflush(stdin);
                printf("Desea volver al menu? s/n: ");
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
}

void sortEmployeesByLastNameAndSector(eEmployee employee[], int tam, eSector sectores[], int tamSec, int order)
{
    eEmployee auxEmployee;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(order == 1)
            {
                //Ordeno en base a sector
                if(employee[i].idSector < employee[j].idSector)
                {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                }
                //Si el sector es el mismo, ordenar por apellido
                else if(employee[i].idSector == employee[j].idSector && strcmp(employee[i].lastName, employee[j].lastName) > 0)
                {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                }//fin else if ordenamiento ascendente
            }
            else
            {
                //Ordeno en base a sector
                if(employee[i].idSector > employee[j].idSector)
                {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                }
                //Si el sector es el mismo, ordenar por apellido
                else if(employee[i].idSector == employee[j].idSector && strcmp(employee[i].lastName, employee[j].lastName) > 0)
                {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                }//fin else if ordenamiento descendente

            }//fin if exterior que determina el ordenamiento

        }//fin for interior

    }//fin for exterior
}

void sortEmployeesBySalarys(eEmployee employee[], int tam, eSector sectores[], int tamSec)
{
    float accumulatorSalarys = 0;
    int contSalarys = 0;
    float averageSalary;

    system("cls");

    printf("***** Informes *****\n\n");

    for(int i=0; i<tam; i++)
    {
        if(employee[i].isEmpty == 0)
        {
            accumulatorSalarys += employee[i].salary;
            contSalarys++;
        }
    }
    printf("Total de los salarios: %.2f\n\n", accumulatorSalarys);


    averageSalary = accumulatorSalarys / contSalarys;

    printf("Promedio de los salarios: %.2f\n\n", averageSalary);


    printf("Los empleados que superan el salario promedio son:\n");

    for(int i=0; i<tam; i++)
    {
        if(employee[i].isEmpty == 0 && employee[i].salary > averageSalary)
        {
            printEmployee(employee[i], sectores, tamSec);
        }
    }

    printf("\n");

}
