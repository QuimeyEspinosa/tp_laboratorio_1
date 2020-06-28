#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1; //retorno error

    Employee* pEmployee;

    int nextId = 0;
    int cant = 4; //guarda la cantidad que devuelve fscanf
    char id[128];
    char nombre[128];
    char horasTrabajadas[128];
    char sueldo[128];


    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        //cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo); //cuento la cantidad y salteo la primer linea
        do
        {
            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo) == cant)
            {
                //imprime mientras fscanf devuelva la cantidad correcta

                pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

                if(pEmployee != NULL)
                {
                    ll_add(pArrayListEmployee, pEmployee);
                    retorno = 0;
                }
            }
            else
            {
                break; //si no entra en el if, pongo un break para evitar continuar con el do while
            }

        }
        while(feof(pFile) == 0);
        retorno = nextId;
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmployee;

    if(pFile != NULL)
    {
        do
        {
            pEmployee = employee_new(); //reservo lugar
            //lectura fantasma
            //fread(pEmployee, sizeof(Employee), 1, pFile);//salteo primera linea
            if(fread(pEmployee, sizeof(Employee), 1, pFile) == 1) //leo datos binarios y valido si me leyo 1
            {
                ll_add(pArrayListEmployee, pEmployee);
                retorno = 0;//exito
            }
        }
        while(!feof(pFile)); //recorro mientras no sea el final del archivo
    }

    return retorno;
}
