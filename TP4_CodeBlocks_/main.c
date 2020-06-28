#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "menu.h"

int main()
{
    char seguir = 's';
    char salirProg;
    int flagTexto = 1;
    int flagBinario = 1;
    int flagSave = 0; //bandera contadora para corroborar que se hayan guardado los cambios antes de salir del programa

    LinkedList* listaInstrumentos = ll_newLinkedList();

    if(listaInstrumentos == NULL)
    {
        printf("No se pudo conseguir memoria\n\n");
        exit(EXIT_FAILURE);
    }


    do
    {
        system("cls");
        //printf("%d", ll_len(listaInstrumentos)); //muestro el numero de datos ingresados para asegurarme que se hayan cargado todos
        switch(menuOpciones())
        {
        case 1:
            if(flagBinario != 0 && flagTexto == 1)//si no fue cargado como binario
            {
                if(controller_loadFromText("DataInstruments.csv",listaInstrumentos) == 0)
                {
                    flagTexto = 0; //se pudo cargar como texto
                }
            }
            else
            {
                system("cls");
                printf("El archivo ya fue cargado\n\n");
            }
            system("pause");
            break;

        case 2:
            if(flagTexto != 0 && flagBinario == 1)//si no fue cargado como texto
            {
                if(controller_loadFromBinary("instrumentos.bin", listaInstrumentos) == 0)
                {
                    flagBinario = 0; //se cargo como binario
                }
            }
            else
            {
                system("cls");
                printf("El archivo ya fue cargado\n\n");
            }
            system("pause");
            break;

        case 3:
            if(flagTexto == 0 || flagBinario == 0)
            {
                if(controller_addInstrument(listaInstrumentos) == 0)
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
                controller_editInstrument(listaInstrumentos);
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
                controller_removeInstrument(listaInstrumentos);
                flagSave++;
            }
            else
            {
                system("cls");
                printf("Para realizar bajas, primero debe haber instrumentos cargados\n\n");
            }
            system("pause");
            break;

        case 6:
            if(flagTexto == 0 || flagBinario == 0)
            {
                system("cls");
                controller_listInstrument(listaInstrumentos);
            }
            else
            {
                system("cls");
                printf("No hay instrumentos que listar\n\n");
            }
            system("pause");
            break;

        case 7:
            if(flagTexto == 0 || flagBinario == 0)
            {
                system("cls");
                controller_sortInstrument(listaInstrumentos);
                flagSave++;
            }
            else
            {
                system("cls");
                printf("No hay instrumentos que ordenar\n\n");
            }
            system("pause");
            break;
        case 8:

            if(flagTexto == 0 || flagBinario == 0)
            {
                system("cls");
                controller_filterInstrument(listaInstrumentos);
                flagSave++;
            }
            else
            {
                system("cls");
                printf("No hay instrumentos que filtrar\n\n");
            }
            system("pause");
            break;
        case 9:
            if(flagTexto == 0 || flagBinario == 0)
            {
                controller_saveAsText("DataInstruments.csv", listaInstrumentos);
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
            if(flagTexto == 0 || flagBinario == 0)
            {
                controller_saveAsBinary("DataInstruments.bin", listaInstrumentos);
                flagSave = 0;
            }
            else
            {
                system("cls");
                printf("No hay archivos cargados para guardar\n\n");
            }
            system("pause");
            break;

        case 11:
            if(flagSave > 0)
            {
                do
                {
                    fflush(stdin);
                    system("cls");
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
                ll_deleteLinkedList(listaInstrumentos);
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





