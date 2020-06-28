#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
    char seguir = 's';
    char salirProg;
    int flagTexto = 1;
    int flagBinario = 1;
    int flagSave = 0; //bandera contadora para corroborar que se hayan guardado los cambios antes de salir del programa

    LinkedList* listaEmpleados = ll_newLinkedList();

    if(listaEmpleados == NULL)
    {
        printf("No se pudo conseguir espacio en memoria\n\n");
        exit(EXIT_FAILURE);
    }
    //Employee* auxEmpleado;

    do
    {
        system("cls");
        switch(menuOpciones())
        {
        case 1:
            if(flagBinario != 0 && flagTexto == 1)//si no fue cargado como binario
            {
                if(controller_loadFromText("data.csv",listaEmpleados) == 0)
                {
                    flagTexto = 0; //se pudo cargar como texto
                }
            }
            else
            {
                system("cls");
                printf("El archivo ya fue cargado.\n");
            }
            system("pause");
            break;

        case 2:
            if(flagTexto != 0 && flagBinario == 1)//si no fue cargado como texto
            {
                if(controller_loadFromBinary("data.bin", listaEmpleados) == 0)
                {
                    flagBinario = 0; //se cargo como binario
                }
            }
            else
            {
                system("cls");
                printf("El archivo ya fue cargado.\n");
            }
            system("pause");
            break;

        case 3:
            if(flagTexto == 0 || flagBinario == 0)
            {
                if(controller_addEmployee(listaEmpleados) == 0)
                {
                    system("cls");
                    printf("Se ha realizado el alta con exito!\n\n");
                    flagSave++;
                }
                else
                {
                    system("cls");
                    printf("Error, no se pudo realizar el alta\n\n");
                }
            }
            else
            {
                system("cls");
                printf("Para realizar el alta, primero debe cargar los archivos\n\n");
            }
            system("pause");
            break;

        case 4:
            if(flagTexto == 0 || flagBinario == 0)
            {
                controller_editEmployee(listaEmpleados);
                flagSave++;
            }
            else
            {
                system("cls");
                printf("Para realizar modificaciones, primero debe haber empleados cargados\n\n");
            }
            system("pause");
            break;

        case 5:
            if(flagTexto == 0 || flagBinario == 0)
            {
                controller_removeEmployee(listaEmpleados);
                flagSave++;
            }
            else
            {
                system("cls");
                printf("Para realizar bajas, primero debe haber empleados cargados\n\n");
            }
            system("pause");
            break;

        case 6:
            if(flagTexto == 0 || flagBinario == 0)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                system("cls");
                printf("No hay empleados que listar\n\n");
            }
            system("pause");
            break;

        case 7:
            controller_sortEmployee(listaEmpleados);
            flagSave++;
            system("pause");
            break;

        case 8:
            if(flagTexto == 0 || flagBinario == 0)
            {
                controller_saveAsText("data.csv", listaEmpleados);
                flagSave = 0;
            }
            else
            {
                system("cls");
                printf("No hay archivos cargados para guardar\n\n");
            }
            system("pause");
            break;

        case 9:
            if(flagTexto == 0 || flagBinario == 0)
            {
                controller_saveAsBinary("data.bin", listaEmpleados);
                flagSave = 0;
            }
            else
            {
                system("cls");
                printf("No hay archivos cargados para guardar\n\n");
            }
            system("pause");
            break;

        case 10:
            if(flagSave > 0)
            {
                do
                {
                    fflush(stdin);
                    printf("\nAtencion!!\n");
                    printf("\nDesea salir del programa sin guardar los cambios? s/n: ");
                    scanf("%c", &salirProg);
                }
                while(salirProg != 's' && salirProg != 'n');
            }
            else if(flagSave == 0)
            {
                do
                {
                    fflush(stdin);
                    printf("\nDesea salir del programa? s/n: ");
                    scanf("%c", &salirProg);
                }
                while(salirProg != 's' && salirProg != 'n');
            }
            if(salirProg == 's')
            {
                ll_deleteLinkedList(listaEmpleados);
                seguir = 'n';
            }
            system("pause");
            break;

        default:
            system("cls");
            printf("No es una opcion valida\n\n");
            system("pause");
            fflush(stdin);
            break;
        }
        fflush(stdin);

    }
    while(seguir == 's');

    return 0;
}
