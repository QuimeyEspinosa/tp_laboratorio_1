#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "parser.h"
#include "instrument.h"
#include "validations.h"
#include "menu.h"

#define nameLen 30


int getId(int* id)
{
    int error = 1;
    *id = 101;

    FILE* f;
    f = fopen("nextId.bin", "rb");

    if(f != NULL)
    {
        fread(id, sizeof(int), 1, f);
        fclose(f);
        error = 0;
    }

    return error;
}

int updateId(int id)
{
    int error = 1;
    id++;

    FILE* f = fopen("nextId.bin", "wb");
    if(f != NULL)
    {
        fwrite(&id, sizeof(int), 1, f);
        fclose(f);
        error = 0;
    }

    return error;
}

int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    int retorno = -1;
    FILE* pFile = NULL;

    pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        if(parser_InstrumentFromText(pFile, pArrayList) == 0)
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
    /*else
    {
        system("cls");
        printf("Error NULL\n\n");
    }*/

    fclose(pFile);

    return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    int retorno = -1;

    FILE* pFile;
    eInstrument* pInstrument;

    int auxId;
    char auxTipo[nameLen];
    char auxNombre[nameLen];
    char auxMarca[nameLen];
    char auxColor[nameLen];
    char auxProveedor[nameLen];
    float auxPrecio;
    char auxStock[nameLen];


    if(pArrayList != NULL && path != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {

            for(int i = 0; i < ll_len(pArrayList); i++)//por cada elemento del array lo escribo en el archivo, desde la posicion 1
            {
                pInstrument = ll_get(pArrayList, i);
                //utilizo las funciones getter para obtener la informacion
                if(instrument_getId(pInstrument, &auxId) == 0 &&
                        instrument_getTipo(pInstrument, auxTipo) == 0 &&
                        instrument_getNombre(pInstrument, auxNombre) == 0 &&
                        instrument_getMarca(pInstrument, auxMarca) == 0 &&
                        instrument_getColor(pInstrument, auxColor) == 0 &&
                        instrument_getProveedor(pInstrument, auxProveedor) == 0 &&
                        instrument_getPrecio(pInstrument, &auxPrecio) == 0 &&
                        instrument_getStock(pInstrument, auxStock) == 0)
                {
                    fprintf(pFile, "%d,%s,%s,%s,%s,%s,%f,%s\n", auxId, auxTipo, auxNombre, auxMarca, auxColor, auxProveedor, auxPrecio, auxStock);
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

int controller_loadFromBinary(char* path, LinkedList* pArrayList)
{
    int retorno = -1;//error
    FILE* pFile;

    pFile = fopen(path, "rb");

    if(pFile != NULL)
    {
        if(parser_InstrumentFromBinary(pFile, pArrayList) == 0)
        {
            system("cls");
            printf("Datos cargados con exito!\n\n");
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
        printf("Error, primero debe cargar los datos desde el archivo de texto y guardarlos como binario\n\n");
    }
    fclose(pFile);
    return retorno;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayList)
{
    int retorno = -1;//retorno error
    FILE* pFile;
    eInstrument* pInstrument;

    if(pArrayList != NULL && path != NULL)
    {
        pFile = fopen(path, "wb");

        for(int i = 1; i < ll_len(pArrayList); i++)//desde la pos 1
        {
            pInstrument = (eInstrument*) ll_get(pArrayList, i);
            fwrite(pInstrument, sizeof(eInstrument), 1, pFile);
        }
        fclose(pFile);
        system("cls");
        printf("Datos guardados como binario de forma exitosa!\n");
        retorno = 0;//si se guardo devuelvo cero como exito
    }

    return retorno;
}

int controller_listInstrument(LinkedList* pArrayList)
{
    int retorno = -1;
    int length;

    if(pArrayList != NULL)
    {
        length = ll_len(pArrayList);
        printf("|| ID ||      Tipo      ||     Nombre     ||    Marca    ||   Color   ||    Proveedor    ||   Precio   || Stock ||\n\n");

        for(int i=0; i<length; i++)
        {
            instrument_printInstrument(pArrayList, i);
        }
        retorno = 0;
    }
    else
    {
        printf("No hay datos cargados para mostrar\n");
    }

    return retorno;
}


int controller_addInstrument(LinkedList* pArrayList)
{
    int retorno = -1;
    eInstrument* pInstrument = instrument_new();

    char auxTipo[nameLen];
    char auxNombre[nameLen];
    char auxMarca[nameLen];
    char auxColor[nameLen];
    char auxProveedor[nameLen];
    float auxPrecio;
    char auxStock[nameLen];
    int nextId;


    if(pArrayList != NULL && pInstrument != NULL)
    {
        system("cls"); //limpio la pantalla
        printf("|| Alta Instrumentos ||\n\n");

        if(get_Cadena(auxTipo, nameLen, 3, "Ingrese tipo del nuevo instrumento: ", "Error, reingrese tipo: \n") == 0 &&
                get_Cadena(auxNombre, nameLen, 3, "Ingrese nombre del nuevo instrumento: ", "Error, reingrese nombre: \n") == 0 &&
                get_Cadena(auxMarca, nameLen, 3, "Ingrese marca del nuevo instrumento: ", "Error, reingrese marca: \n") == 0 &&
                get_Cadena(auxColor, nameLen, 3, "Ingrese color del nuevo instrumento: ", "Error, reingrese color: \n") == 0 &&
                get_Cadena(auxProveedor, nameLen, 3, "Ingrese proveedor del nuevo instrumento: ", "Error, reingrese proveedor: \n") == 0 &&
                get_Flotante(&auxPrecio, 3, "Ingrese precio del instrumento: ", "Error, reingrese precio: \n", 200, 120000) == 0 &&
                get_Cadena(auxStock, nameLen, 3, "Ingrese stock ('Si'/'No'): ", "Error, reingrese stock: \n") == 0)
        {
            normalizeStr(auxTipo); //normalizo tipo
            normalizeStr(auxNombre); //normalizo nombre
            normalizeStr(auxMarca); //normalizo marca
            normalizeStr(auxColor); //normalizo color
            normalizeStr(auxProveedor); //normalizo proveedor
            normalizeStr(auxStock); //normalizo stock

            getId(&nextId);

            printf("\n| Los datos a cargar son los siguientes |\n");
            printf("\nTipo: %s\n", auxTipo);
            printf("Nombre: %s\n", auxNombre);
            printf("Marca: %s\n", auxMarca);
            printf("Color: %s\n", auxColor);
            printf("Proveedor: %s\n", auxProveedor);
            printf("Precio: %.2f\n", auxPrecio);
            printf("Stock: %s\n", auxStock);
            system("pause");

            //nextId = instrument_lastId(pArrayList) + 1; //cargo el ultimo id en nextId y le sumo 1

            if(instrument_setId(pInstrument, nextId) == 0 &&
                    instrument_setTipo(pInstrument, auxTipo) == 0 &&
                    instrument_setNombre(pInstrument, auxNombre) == 0 &&
                    instrument_setMarca(pInstrument, auxMarca) == 0 &&
                    instrument_setColor(pInstrument, auxColor) == 0 &&
                    instrument_setProveedor(pInstrument, auxProveedor) == 0 &&
                    instrument_setPrecio(pInstrument, auxPrecio) == 0 &&
                    instrument_setStock(pInstrument, auxStock) == 0)
            {
                if(ll_add(pArrayList, pInstrument) == 0)
                {
                    updateId(nextId);
                    retorno = 0; //alta con exito
                }

            }
            else
            {
                free(pInstrument);
            }
        }
        else
        {
            free(pInstrument);
        }
    }

    return retorno;
}


int controller_editInstrument(LinkedList* pArrayList)
{
    int retorno = -1;
    eInstrument* auxInstrument;

    int auxId;
    int lastId;

    int index;

    //int confirmChange;

    int quitMenu = 1;

    if(pArrayList != NULL)
    {
        system("cls");
        controller_listInstrument(pArrayList);//listo los empleados

        for(int i = 0; i < ll_len(pArrayList); i++) //busco el ultimo id para indicar el limite en la funcion get_Entero
        {
            auxInstrument = ll_get(pArrayList, i);

            instrument_getId(auxInstrument, &auxId);
            if(auxId >= lastId)
            {
                lastId = auxId;
            }
        }
        if(get_Entero(&auxId, 3, "\nIngrese ID del instrumento a modificar: ", "Error, reingrese un ID valido: \n", 0, lastId) == 0)
        {
            index = instrument_searchForId(pArrayList, auxId); //cargo en index el indice buscado

            if(index >= 0)
            {
                system("cls"); //limpio la pantalla
                //muestro el instrumento buscado
                printf("||Modificar Instrumentos||\n\n");
                printf("Usted eligio el siguiente instrumento para modificar:\n\n");
                printf("|| ID ||      Tipo      ||     Nombre     ||    Marca    ||   Color   ||    Proveedor    ||   Precio   || Stock ||\n\n");
                instrument_printInstrument(pArrayList, index);

                printf("\n\nQue desea modificar?\n");

                do
                {
                    switch(menuModifications())
                    {
                    case 1:
                        if(instrument_modifyTipo(pArrayList, index) == 0)
                        {
                            system("cls");
                            printf("|| ID ||      Tipo      ||     Nombre     ||    Marca    ||   Color   ||    Proveedor    ||   Precio   || Stock ||\n\n");
                            instrument_printInstrument(pArrayList, index);
                            printf("\nTipo de instrumento modificado con exito! Se regresara al menu principal\n\n");
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
                        if(instrument_modifyNombre(pArrayList, index) == 0)
                        {
                            system("cls");
                            printf("|| ID ||      Tipo      ||     Nombre     ||    Marca    ||   Color   ||    Proveedor    ||   Precio   || Stock ||\n\n");
                            instrument_printInstrument(pArrayList, index);
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
                    case 3:
                        if(instrument_modifyMarca(pArrayList, index) == 0)
                        {
                            system("cls");
                            printf("|| ID ||      Tipo      ||     Nombre     ||    Marca    ||   Color   ||    Proveedor    ||   Precio   || Stock ||\n\n");
                            instrument_printInstrument(pArrayList, index);
                            printf("\nMarca modificada con exito! Se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        else
                        {
                            system("cls");
                            printf("No se pudo realizar la modificacion de la marca, se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        break;
                    case 4:
                        if(instrument_modifyColor(pArrayList, index) == 0)
                        {
                            system("cls");
                            printf("|| ID ||      Tipo      ||     Nombre     ||    Marca    ||   Color   ||    Proveedor    ||   Precio   || Stock ||\n\n");
                            instrument_printInstrument(pArrayList, index);
                            printf("\nColor modificado con exito! Se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        else
                        {
                            system("cls");
                            printf("No se pudo realizar la modificacion del color, se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        break;
                    case 5:
                        if(instrument_modifyProveedor(pArrayList, index) == 0)
                        {
                            system("cls");
                            printf("|| ID ||      Tipo      ||     Nombre     ||    Marca    ||   Color   ||    Proveedor    ||   Precio   || Stock ||\n\n");
                            instrument_printInstrument(pArrayList, index);
                            printf("\nProveedor modificado con exito! Se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        else
                        {
                            system("cls");
                            printf("No se pudo realizar la modificacion del proveedor, se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        break;
                    case 6:
                        if(instrument_modifyPrecio(pArrayList, index) == 0)
                        {
                            system("cls");
                            printf("|| ID ||      Tipo      ||     Nombre     ||    Marca    ||   Color   ||    Proveedor    ||   Precio   || Stock ||\n\n");
                            instrument_printInstrument(pArrayList, index);
                            printf("\nPrecio modificado con exito! Se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        else
                        {
                            system("cls");
                            printf("No se pudo realizar la modificacion del precio, se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        break;
                    case 7:
                        if(instrument_modifyStock(pArrayList, index) == 0)
                        {
                            system("cls");
                            printf("|| ID ||      Tipo      ||     Nombre     ||    Marca    ||   Color   ||    Proveedor    ||   Precio   || Stock ||\n\n");
                            instrument_printInstrument(pArrayList, index);
                            printf("\nStock modificado con exito! Se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        else
                        {
                            system("cls");
                            printf("No se pudo realizar la modificacion del stock, se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        break;
                    case 8:
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

int controller_removeInstrument(LinkedList* pArrayList)
{
    int retorno = -1;
    eInstrument* auxInstrument;

    int auxId;
    int lastId;

    int index;
    char confirmDelete;

    if(pArrayList != NULL)
    {
        system("cls");
        controller_listInstrument(pArrayList);//listo los instrumentos

        for(int i = 0; i < ll_len(pArrayList); i++) //busco el ultimo id para indicar el limite en la funcion get_Entero
        {
            auxInstrument = ll_get(pArrayList, i);

            instrument_getId(auxInstrument, &auxId);
            if(auxId >= lastId)
            {
                lastId = auxId;
            }
        }
        if(get_Entero(&auxId, 3, "\nIngrese ID del instrumento a eliminar: ", "Error, reingrese un ID valido: \n", 0, lastId) == 0)
        {
            index = instrument_searchForId(pArrayList, auxId);

            if(index >= 0)
            {
                system("cls"); //limpio la pantalla
                //muestro el instrumento buscado
                printf("||Baja Instrumentos||\n\n");
                printf("Usted eligio el siguiente instrumento para dar de baja:\n\n");
                auxInstrument = ll_get(pArrayList, index);
                printf("|| ID ||      Tipo      ||     Nombre     ||    Marca    ||   Color   ||    Proveedor    ||   Precio   || Stock ||\n\n");
                instrument_printInstrument(pArrayList, index);

                printf("\nDesea eliminar al instrumento? s/n: ");
                fflush(stdin);
                scanf("%c", &confirmDelete);

                if(confirmDelete == 's')
                {
                    ll_remove(pArrayList, index);//elimino el instrumento en el indice especificado
                    if(instrument_delete(auxInstrument) == 0) //elimino el puntero auxiliar
                    {
                        system("cls");
                        printf("Baja realizada con exito!\n\n");
                        retorno = 0;//retorno 0 si se pudo eliminar
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


int controller_sortInstrument(LinkedList* pArrayList)
{
    int retorno = -1;

    if(pArrayList != NULL)
    {
        if(instrument_sort(pArrayList) == 0)
        {
            printf("\nInstrumentos ordenados exitosamente.\n\n");
        }
    }
    else
    {
        printf("Error\n");
    }

    return retorno;
}


int controller_filterInstrument(LinkedList* pArrayList)
{
    int retorno = -1;

    LinkedList* filterList = NULL;
    filterList = ll_clone(pArrayList);

    if(pArrayList != NULL && filterList != NULL)
    {
        system("cls");
        printf("||Menu Filtrar||\n");
        retorno = 0;
        switch(menuFilter())
        {
        case 1:
            system("cls");
            filterList = ll_filter(pArrayList, instrument_filterByStock);
            controller_listInstrument(filterList);
            break;
        case 2:
            system("cls");
            filterList = ll_filter(pArrayList, instrument_filterByNoStock);
            controller_listInstrument(filterList);
            break;
        case 3:
            system("cls");
            filterList = ll_filter(pArrayList, instrument_filterByTypeCuerdas);
            controller_listInstrument(filterList);
            break;
        case 4:
            system("cls");
            filterList = ll_filter(pArrayList, instrument_filterByTypePercusion);
            controller_listInstrument(filterList);
            break;
        case 5:
            system("cls");
            filterList = ll_filter(pArrayList, instrument_filterByTypeTeclas);
            controller_listInstrument(filterList);
            break;
        case 6:
            system("cls");
            filterList = ll_filter(pArrayList, instrument_filterByTypeViento);
            controller_listInstrument(filterList);
            break;
        default:
            printf("\nNo es una opcion valida\n\n");
            break;
        }
    }
    return retorno;
}
