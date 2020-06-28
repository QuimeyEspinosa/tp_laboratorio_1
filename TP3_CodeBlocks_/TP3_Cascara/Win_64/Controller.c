#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "menu.h"
#include "validations.h"

#define nameLen 25


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;

    pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        if(parser_EmployeeFromText(pFile, pArrayListEmployee) == 0)
        {
            system("cls");
            printf("Datos cargados con exito!\n\n");
            retorno = 0;
        }
        else
        {
            system("cls");
            printf("No ha sido posible cargar los datos\n\n");
        }
    }
    else
    {
        system("cls");
        printf("Error NULL\n\n");
    }

    fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;//error
    FILE* pFile;

    pFile = fopen(path, "rb");

    if(pFile != NULL)
    {
        if(parser_EmployeeFromBinary(pFile, pArrayListEmployee) == 0)
        {
            system("cls");
            printf("Datos cargados con exito!\n");
            retorno = 0; //exito
        }
        else
        {
            system("cls");
            printf("No ha sido posible cargar los datos\n\n");
        }
    }
    else
    {
        system("cls");
        printf("Error NULL\n");
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmployee = employee_new();

    int nextId;
    char auxNombre[nameLen];
    int auxHorasTrabajadas; //declaro variables auxiliares para asegurarme de pasar al array los datos correctos
    int auxSueldo;

    if(pArrayListEmployee != NULL && pEmployee != NULL)
    {
        system("cls"); //limpio la pantalla
        //muestro el empleado buscado
        printf("||Alta Empleados||\n\n");

        if(get_Cadena(auxNombre, nameLen, 3, "Ingrese nombre del nuevo empleado: ", "Error, reingrese nombre: \n") == 0 &&
                get_Entero(&auxHorasTrabajadas, 3, "Ingrese horas trabajadas: ", "Error, reingrese horas: \n", 0, 5000) == 0 &&
                get_Entero(&auxSueldo, 3, "Ingrese sueldo: ", "Error, reingrese sueldo: \n", 12000, 300000) == 0)
        {
            normalizeStr(auxNombre); //normalizo nombre

            nextId = employee_lastId(pArrayListEmployee) + 1; //cargo el ultimo id en nextId y le sumo 1

            if(employee_setId(pEmployee, nextId) == 0 &&
                    employee_setNombre(pEmployee, auxNombre) == 0 &&
                    employee_setHorasTrabajadas(pEmployee, auxHorasTrabajadas) == 0 &&
                    employee_setSueldo(pEmployee, auxSueldo) == 0)
            {
                ll_add(pArrayListEmployee, pEmployee);
                retorno = 0; //alta con exito
            }
            else
            {
                free(pEmployee);
            }
        }
        else
        {
            free(pEmployee);
        }
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxEmployee;

    int auxId;
    int lastId;

    int index;

    //int confirmChange;

    int quitMenu = 1;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);//listo los empleados

        for(int i = 0; i < ll_len(pArrayListEmployee); i++) //busco el ultimo id para indicar el limite en la funcion get_Entero
        {
            auxEmployee = ll_get(pArrayListEmployee, i);

            employee_getId(auxEmployee, &auxId);
            if(auxId >= lastId)
            {
                lastId = auxId;
            }
        }
        if(get_Entero(&auxId, 3, "\nIngrese ID del empleado a modificar: ", "Error, reingrese un ID valido: \n", 0, lastId) == 0)
        {
            index = employee_searchForId(pArrayListEmployee, auxId); //cargo en index el indice buscado

            if(index >= 0)
            {
                system("cls"); //limpio la pantalla
                //muestro el empleado buscado
                printf("||Modificar Empleados||\n\n");
                printf("Usted eligio el siguiente empleado para modificar:\n\n");
                printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n");
                employee_printEmployee(pArrayListEmployee, index);

                printf("\nQue desea modificar?\n");

                do
                {
                    switch(menuModifications())
                    {
                    case 1:
                        if(employee_changeName(pArrayListEmployee, index) == 0)
                        {
                            system("cls");
                            printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n");
                            employee_printEmployee(pArrayListEmployee, index);
                            printf("\nNombre modificado con exito! Se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        else
                        {
                            system("cls");
                            printf("No se pudo realizar la modificacion del nombre, se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        break;
                    case 2:
                        if(employee_changeHours(pArrayListEmployee, index) == 0)
                        {
                            system("cls");
                            printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n");
                            employee_printEmployee(pArrayListEmployee, index);
                            printf("\nHoras trabajadas modificadas con exito! Se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        else
                        {
                            system("cls");
                            printf("No se pudo realizar la modificacion de las horas trabajadas, se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        break;
                    case 3:
                        if(employee_changeSalary(pArrayListEmployee, index) == 0)
                        {
                            system("cls");
                            printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n");
                            employee_printEmployee(pArrayListEmployee, index);
                            printf("\nSueldo modificado con exito! Se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        else
                        {
                            system("cls");
                            printf("No se pudo realizar la modificacion del sueldo, se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        break;
                    case 4:
                        quitMenu = 0;
                        break;
                    default:
                        system("cls");
                        printf("No es una opcion valida\n\n");
                        break;
                    }
                }
                while(quitMenu == 1);

            }//fin if menu

        }//fin pedir id

    }//fin distinto de NULL

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxEmployee;

    int auxId;
    int lastId;

    int index;
    char confirmDelete;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);//listo los empleados

        for(int i = 0; i < ll_len(pArrayListEmployee); i++) //busco el ultimo id para indicar el limite en la funcion get_Entero
        {
            auxEmployee = ll_get(pArrayListEmployee, i);

            employee_getId(auxEmployee, &auxId);
            if(auxId >= lastId)
            {
                lastId = auxId;
            }
        }
        if(get_Entero(&auxId, 3, "\nIngrese ID del empleado a eliminar: ", "Error, reingrese un ID valido: \n", 0, lastId) == 0)
        {
            index = employee_searchForId(pArrayListEmployee, auxId);

            if(index >= 0)
            {
                system("cls"); //limpio la pantalla
                //muestro el empleado buscado
                printf("||Baja Empleados||\n\n");
                printf("Usted eligio el siguiente empleado para dar de baja:\n\n");
                auxEmployee = ll_get(pArrayListEmployee, index);
                printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n");
                employee_printEmployee(pArrayListEmployee, index);

                printf("\nDesea eliminar al empleado? s/n: ");
                fflush(stdin);
                scanf("%c", &confirmDelete);

                if(confirmDelete == 's')
                {
                    ll_remove(pArrayListEmployee, index);//elimino el empleado en ese indice
                    if(employee_delete(auxEmployee) == 0) //elimino el puntero auxiliar que cree
                    {
                        system("cls");
                        printf("Baja realizada con exito!\n\n");
                        retorno = 0;
                    }
                }
                else
                {
                    system("cls");
                    printf("No se ha realizado la baja\n");
                }
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n\n");
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            employee_printEmployee(pArrayListEmployee, i);
        }
        retorno = 0;
    }
    else
    {
        printf("No hay empleados cargados para mostrar\n");
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        if(employee_sort(pArrayListEmployee) == 0)
        {
            printf("\nEmpleados ordenados exitosamente.\n\n");
        }
    }
    else
    {
        printf("Error\n");
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    FILE* pFile;
    Employee* pEmployee;

    int auxId;
    char auxName[nameLen];
    int auxHours;
    int auxSalary;


    if(pArrayListEmployee != NULL && path != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {

            for(int i = 0; i < ll_len(pArrayListEmployee); i++)//por cada elemento del array lo escribo en el archivo, desde la posicion 1
            {
                pEmployee = ll_get(pArrayListEmployee, i);
                //utilizo las funciones getter para obtener la informacion
                if(!employee_getId(pEmployee, &auxId) &&
                        !employee_getNombre(pEmployee, auxName) &&
                        !employee_getHorasTrabajadas(pEmployee, &auxHours) &&
                        !employee_getSueldo(pEmployee, &auxSalary))
                {
                    fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxName, auxHours, auxSalary);
                }
            }
            fclose(pFile);
            system("cls");
            printf("Datos guardados como texto de forma exitosa!\n\n");
            retorno = 0;
        }//if fpArchivo NULL
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;//retorno error
	FILE* pFile;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "wb");

		for(int i = 1; i < ll_len(pArrayListEmployee); i++)//desde la pos 1
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(pEmployee, sizeof(Employee), 1, pFile);
		}
		fclose(pFile);
		system("cls");
		printf("Datos guardados como binario de forma exitosa!\n");
		retorno = 0;//si se guardo devuelvo cero como exito
	}

    return retorno;
}

