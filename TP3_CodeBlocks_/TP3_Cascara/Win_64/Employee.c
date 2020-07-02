#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "validations.h"
#include "menu.h"
#include "Controller.h"

#define nameLen 25

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
    Employee* newEmployee = NULL;
    newEmployee = employee_new();

    if(newEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldo != NULL)
    {
        //si da error llamo a delete para que no exista el empleado
        if(employee_setId(newEmployee,atoi(idStr)) == -1 ||
                employee_setNombre(newEmployee, nombreStr) == -1 ||
                employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr)) == -1 ||
                employee_setSueldo(newEmployee, atoi(sueldo)) == -1 )
        {
            employee_delete(newEmployee);
            newEmployee = NULL;
        }
    }

    return newEmployee;
}

int employee_delete(Employee* this)
{
    int retorno = -1;//error
    if(this != NULL)
    {
        free(this);
        this = NULL;
        retorno = 0;//exito
    }
    return retorno;
}


int employee_setId(Employee* this,int id)
{
    int retorno = -1; //devuelvo error

    if(this != NULL && id >= 0)
    {
        this->id = id; //guardo el id de parametros en el id de this
        retorno = 0; //si se pudo guardar devuelvo 0
    }

    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }

    return retorno;
}


int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1; //devuelvo error

    if(this != NULL && nombre != NULL)
    {
        if(validarNombre(nombre, nameLen) != 1)
        {
            strncpy(this->nombre, nombre, nameLen); //guardo el id de parametros en el id de this
            retorno = 0; //si se pudo guardar devuelvo 0
        }
    }

    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre, this->nombre, nameLen);
        retorno = 0;
    }

    return retorno;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1; //devuelvo error

    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas; //guardo horasTrabajadas de parametros en el horasTrabajadas de this
        retorno = 0; //si se pudo guardar devuelvo 0
    }

    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }

    return retorno;
}


int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1; //devuelvo error

    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo; //guardo el sueldo de parametros en el sueldo de this
        retorno = 0; //si se pudo guardar devuelvo 0
    }

    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }

    return retorno;
}

//--------------------------------------------------------------------

int employee_searchForId(LinkedList* pArrayListEmployee, int id)
{
    int retorno = -1;
    int idAux;
    Employee* pEmployee;

    for(int index = 0; index < ll_len(pArrayListEmployee); index++)
    {
        pEmployee = ll_get(pArrayListEmployee, index);

        if(employee_getId(pEmployee, &idAux) == 0 &&
                idAux == id)
        {
            retorno = index;//devuelvo la posicion del empleado
            break;
        }
    }
    return retorno;
}

int employee_printEmployee(LinkedList* pArrayListEmployee, int index)
{
    int retorno = -1;

    Employee* pAuxEmployee;
    int auxId;
    char auxNombre[nameLen];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(pArrayListEmployee != NULL && index >= 0)
    {
        pAuxEmployee = ll_get(pArrayListEmployee, index);
        if( employee_getId(pAuxEmployee, &auxId) == 0 &&
                employee_getNombre(pAuxEmployee, auxNombre) == 0 &&
                employee_getHorasTrabajadas(pAuxEmployee, &auxHorasTrabajadas) == 0 &&
                employee_getSueldo(pAuxEmployee, &auxSueldo) == 0 )
        {
            printf("  %-5d     %-15s     %-10d       %-10d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
        }
        else
        {
            printf("Error\n");
        }
    }

    return retorno;
}

int employee_lastId(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int len = ll_len(pArrayListEmployee);
    int auxId;
    int lastId = 0;
    int flag = 0;

    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            pEmployee = (Employee*) ll_get(pArrayListEmployee,i);
            employee_getId(pEmployee, &auxId);

            if(auxId > lastId || flag == 0)
            {
                lastId = auxId;
                flag = 1;
            }
        }
    }
    return lastId;
}

//--------------------------------------------------------------------

int employee_changeName(LinkedList* pArrayListEmployee, int index)
{
    int retorno = -1;
    char newName[nameLen];
    Employee* pEmployee;

    pEmployee = ll_get(pArrayListEmployee, index);

    if(get_Cadena(newName, nameLen, 2, "Ingrese nuevo nombre: ","Error, reingrese un nombre valido.\n") == 0)
    {
        normalizeStr(newName);
        employee_setNombre(pEmployee, newName);
        retorno = 0;
    }

    return retorno;
}

int employee_changeHours(LinkedList* pArrayListEmployee, int index)
{
    int retorno = -1;
    int newHours;
    Employee* pEmployee;

    pEmployee = ll_get(pArrayListEmployee, index);

    if(get_Entero(&newHours, 2, "Ingrese actualizacion de horas trabajadas: ", "Error, numero invalido.\n", 0, 100000) == 0)//hasta 100000
    {
        employee_setHorasTrabajadas(pEmployee, newHours);
        retorno = 0;
    }

    return retorno;
}

int employee_changeSalary(LinkedList* pArrayListEmployee, int index)
{
    int retorno = -1;
    int newSalary;
    Employee* pEmployee;

    pEmployee = ll_get(pArrayListEmployee, index);

    if(get_Entero(&newSalary, 2, "Ingrese nuevo sueldo entre 12000 y 300000: ", "Error, sueldo invalido.\n", 12000, 300000) == 0)//hasta 300000
    {
        employee_setSueldo(pEmployee, newSalary);
        retorno = 0;
    }

    return retorno;
}

//--------------------------------------------------------------------

int employee_sort(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int orden;

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("||Menu ordenar||\n");
        switch(menuSort())
        {
        case 1:
            //ordenar por ID
            get_Entero(&orden, 2, "\nIngrese orden, 1 ascendente, 0 descendente: ", "\nError, ingrese un orden valido", 0, 1);
            printf("\nOrdenando...\n\n\n");
            ll_sort(pArrayListEmployee, employee_sortById, orden);
            controller_ListEmployee(pArrayListEmployee);
            retorno = 0;
            break;
        case 2:
            //ordenar por Nombre
            get_Entero(&orden, 2, "\nIngrese orden, 1 ascendente, 0 descendente: ", "\nError, ingrese un orden valido", 0, 1);
            printf("\nOrdenando...\n\n\n");
            ll_sort(pArrayListEmployee, employee_sortByName, orden);
            controller_ListEmployee(pArrayListEmployee);
            retorno = 0;
            break;
        case 3:
            //ordenar por Horas trabajadas
            get_Entero(&orden, 2, "\nIngrese orden, 1 ascendente, 0 descendente: ", "\nError, ingrese un orden valido", 0, 1);
            printf("\nOrdenando...\n\n\n");
            ll_sort(pArrayListEmployee, employee_sortByHours, orden);
            controller_ListEmployee(pArrayListEmployee);
            retorno = 0;
            break;
        case 4:
            //ordenar por Sueldo
            get_Entero(&orden, 2, "\nIngrese orden, 1 ascendente, 0 descendente: ", "\nError, ingrese un orden valido", 0, 1);
            printf("\nOrdenando...\n\n\n");
            ll_sort(pArrayListEmployee, employee_sortBySalary, orden);
            controller_ListEmployee(pArrayListEmployee);
            retorno = 0;
            break;
        case 5:
            //vuelve al menu
            break;
        default:
            printf("\nNo es una opcion valida\n\n");
            break;
        }

    }

    return retorno;
}

int employee_sortById(void* firstEmployee, void* secondEmployee)
{
    int retorno = 0; //si son iguales retorno 0

    int firstId;
    int secondId;

    employee_getId(firstEmployee, &firstId);
    employee_getId(secondEmployee, &secondId);

    if(firstId > secondId)
    {
        retorno = 1; //retorno 1 si el primer parametro es mayor que el segundo
    }
    else if(secondId > firstId)
    {
        retorno = -1;
    }

    return retorno;
}

int employee_sortByName(void* firstEmployee, void* secondEmployee)
{
    int retorno = 0; //si son iguales retorno 0

    char firstName[nameLen];
    char secondName[nameLen];

    employee_getNombre(firstEmployee, firstName);
    employee_getNombre(secondEmployee, secondName);

    if(strcmp(firstName, secondName) > 0)
    {
        retorno = 1; //retorno 1 si el primer parametro es mayor que el segundo
    }
    else if(strcmp(secondName, firstName) < 0)
    {
        retorno = -1;
    }

    return retorno;
}

int employee_sortByHours(void* firstEmployee, void* secondEmployee)
{
    int retorno = 0; //si son iguales retorno 0

    int firstHours;
    int secondHours;

    employee_getHorasTrabajadas(firstEmployee, &firstHours);
    employee_getHorasTrabajadas(secondEmployee, &secondHours);

    if(firstHours > secondHours)
    {
        retorno = 1; //retorno 1 si el primer parametro es mayor que el segundo
    }
    else if(secondHours > firstHours)
    {
        retorno = -1;
    }

    return retorno;
}

int employee_sortBySalary(void* firstEmployee, void* secondEmployee)
{
    int retorno = 0; //si son iguales retorno 0

    int firstSalary;
    int secondSalary;

    employee_getSueldo(firstEmployee, &firstSalary);
    employee_getSueldo(secondEmployee, &secondSalary);

    if(firstSalary > secondSalary)
    {
        retorno = 1; //retorno 1 si el primer parametro es mayor que el segundo
    }
    else if(secondSalary > firstSalary)
    {
        retorno = -1;
    }

    return retorno;
}
