#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "instrument.h"
#include "validations.h"
#include "menu.h"
#include "controller.h"

#define nameLen 30

eInstrument* instrument_new()
{
    return (eInstrument*) malloc(sizeof(eInstrument));
}

int instrument_delete(eInstrument* this)
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

eInstrument* instrument_newParameters(char* idStr, char* tipoStr, char* nombreStr, char* marcaStr, char* colorStr, char* proveedorStr, char* precioStr, char* stockStr)
{
    eInstrument* newInstrument = NULL;
    newInstrument = instrument_new();

    if(newInstrument != NULL && idStr != NULL && tipoStr != NULL && nombreStr != NULL && marcaStr != NULL && colorStr != NULL && proveedorStr != NULL && precioStr != NULL && stockStr != NULL)
    {
        //si da error llamo a delete para que no exista el instrumento
        if(instrument_setId(newInstrument, atoi(idStr)) == -1 ||
                instrument_setTipo(newInstrument, tipoStr) == -1 ||
                instrument_setNombre(newInstrument, nombreStr) == -1 ||
                instrument_setMarca(newInstrument, marcaStr) == -1 ||
                instrument_setColor(newInstrument, colorStr) == -1 ||
                instrument_setProveedor(newInstrument, proveedorStr) == -1 ||
                instrument_setPrecio(newInstrument, atof(precioStr)) == -1 ||
                instrument_setStock(newInstrument, stockStr) == -1)
        {
            instrument_delete(newInstrument);
            newInstrument = NULL;
        }
    }

    return newInstrument;
}

int instrument_printInstrument(LinkedList* pArrayList, int index)
{
    int retorno = -1;

    eInstrument* pAuxInstrument;
    int auxId;
    char auxTipo[nameLen];
    char auxNombre[nameLen];
    char auxMarca[nameLen];
    char auxColor[nameLen];
    char auxProveedor[nameLen];
    float auxPrecio;
    char auxStock[nameLen];


    if(pArrayList != NULL && index >= 0)
    {
        pAuxInstrument = (eInstrument*)ll_get(pArrayList, index);
        if(instrument_getId(pAuxInstrument, &auxId) == 0 &&
                instrument_getTipo(pAuxInstrument, auxTipo) == 0 &&
                instrument_getNombre(pAuxInstrument, auxNombre) == 0 &&
                instrument_getMarca(pAuxInstrument, auxMarca) == 0 &&
                instrument_getColor(pAuxInstrument, auxColor) == 0 &&
                instrument_getProveedor(pAuxInstrument, auxProveedor) == 0 &&
                instrument_getPrecio(pAuxInstrument, &auxPrecio) == 0 &&
                instrument_getStock(pAuxInstrument, auxStock) == 0)
        {
            printf("   %-5d    %-10s        %-12s     %-10s    %-10s    %-12s      %-10.2f     %-10s\n", auxId, auxTipo, auxNombre, auxMarca, auxColor, auxProveedor, auxPrecio, auxStock);
            //system("pause"); //utilizo un pause para que solamente se muestre el primer elemento de la lista y asi poder modificar el printf comodamente
        }
        else
        {
            printf("Error\n");
        }
    }

    return retorno;
}

int instrument_searchForId(LinkedList* pArrayList, int id)
{
    int retorno = -1;
    int idAux;
    eInstrument* pInstrument;

    for(int index = 0; index < ll_len(pArrayList); index++)
    {
        pInstrument = ll_get(pArrayList, index);

        if(instrument_getId(pInstrument, &idAux) == 0 &&
                idAux == id)
        {
            retorno = index;//devuelvo la posicion del empleado
        }
    }
    return retorno;
}


int instrument_lastId(LinkedList* pArrayList)
{
    eInstrument* pInstrument;
    int len = ll_len(pArrayList);
    int auxId;
    int lastId = 0;
    int flag = 0;

    if(pArrayList != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            pInstrument = (eInstrument*) ll_get(pArrayList,i);
            instrument_getId(pInstrument, &auxId);

            if(auxId > lastId || flag == 0)
            {
                lastId = auxId;
                flag = 1;
            }
        }
    }
    return lastId;
}

//-----------------------------------------
//---------------SETTERS-------------------
//-----------------------------------------

int instrument_setId(eInstrument* this,int id)
{
    int retorno = -1; //devuelvo error

    if(this != NULL && id >= 0)
    {
        this->id = id; //guardo el id de parametros en el id de this
        retorno = 0; //si se pudo guardar devuelvo 0
    }

    return retorno;
}

int instrument_setTipo(eInstrument* this,char* tipo)
{
    int retorno = -1; //devuelvo error

    if(this != NULL && tipo != NULL)
    {
        strcpy(this->tipo, tipo); //guardo el id de parametros en el id de this
        retorno = 0; //si se pudo guardar devuelvo 0

    }

    return retorno;
}

int instrument_setNombre(eInstrument* this,char* nombre)
{
    int retorno = -1; //devuelvo error

    if(this != NULL && nombre != NULL)
    {
        strncpy(this->nombre, nombre, nameLen); //guardo el id de parametros en el id de this
        retorno = 0; //si se pudo guardar devuelvo 0
    }

    return retorno;
}

int instrument_setMarca(eInstrument* this,char* marca)
{
    int retorno = -1; //devuelvo error

    if(this != NULL && marca != NULL)
    {
        strncpy(this->marca, marca, nameLen); //guardo el id de parametros en el id de this
        retorno = 0; //si se pudo guardar devuelvo 0
    }

    return retorno;
}

int instrument_setColor(eInstrument* this,char* color)
{
    int retorno = -1; //devuelvo error

    if(this != NULL && color != NULL)
    {
        strncpy(this->color, color, nameLen); //guardo el id de parametros en el id de this
        retorno = 0; //si se pudo guardar devuelvo 0
    }

    return retorno;
}

int instrument_setProveedor(eInstrument* this,char* proveedor)
{
    int retorno = -1; //devuelvo error

    if(this != NULL && proveedor != NULL)
    {
        strncpy(this->proveedor, proveedor, nameLen); //guardo el id de parametros en el id de this
        retorno = 0; //si se pudo guardar devuelvo 0
    }

    return retorno;
}

int instrument_setPrecio(eInstrument* this,float precio)
{
    int retorno = -1; //devuelvo error

    if(this != NULL && precio >= 0)
    {
        this->precio = precio; //guardo precio de parametros en el precio de this
        retorno = 0; //si se pudo guardar devuelvo 0
    }

    return retorno;
}

int instrument_setStock(eInstrument* this,char* stock)
{
    int retorno = -1; //devuelvo error


    if(this != NULL && stock != NULL)
    {
        strncpy(this->stock, stock, nameLen); //guardo el id de parametros en el id de this
        retorno = 0; //si se pudo guardar devuelvo 0

    }

    return retorno;
}

//-----------------------------------------
//---------------GETTERS-------------------
//-----------------------------------------

int instrument_getId(eInstrument* this,int* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }

    return retorno;
}

int instrument_getTipo(eInstrument* this,char* tipo)
{
    int retorno = -1;

    if(this != NULL && tipo != NULL)
    {
        strncpy(tipo, this->tipo, nameLen);
        retorno = 0;
    }

    return retorno;
}

int instrument_getNombre(eInstrument* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre, this->nombre, nameLen);
        retorno = 0;
    }

    return retorno;
}

int instrument_getMarca(eInstrument* this,char* marca)
{
    int retorno = -1;

    if(this != NULL && marca != NULL)
    {
        strncpy(marca, this->marca, nameLen);
        retorno = 0;
    }

    return retorno;
}

int instrument_getColor(eInstrument* this,char* color)
{
    int retorno = -1;

    if(this != NULL && color != NULL)
    {
        strncpy(color, this->color, nameLen);
        retorno = 0;
    }

    return retorno;
}

int instrument_getProveedor(eInstrument* this,char* proveedor)
{
    int retorno = -1;

    if(this != NULL && proveedor != NULL)
    {
        strncpy(proveedor, this->proveedor, nameLen);
        retorno = 0;
    }

    return retorno;
}

int instrument_getPrecio(eInstrument* this,float* precio)
{
    float retorno = -1;

    if(this != NULL && precio != NULL)
    {
        *precio = this->precio;
        retorno = 0;
    }

    return retorno;
}


int instrument_getStock(eInstrument* this,char* stock)
{
    int retorno = -1;

    if(this != NULL && stock != NULL)
    {
        strncpy(stock, this->stock, nameLen);
        retorno = 0;
    }


    return retorno;
}


//-----------------------------------------
//---------MODIFICAR CRITERIOS-------------
//-----------------------------------------


int instrument_modifyTipo(LinkedList* pArrayList, int index)
{
    int retorno = -1;
    char newTipo[nameLen];
    char confirmModify;
    eInstrument* pInstrument;

    pInstrument = ll_get(pArrayList, index);

    if(get_Cadena(newTipo, nameLen, 2, "Ingrese nuevo tipo: ","Error, reingrese un tipo valido.\n") == 0)
    {
        printf("\nConfirma la modificacion del instrumento? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmModify);

        if(confirmModify == 's')
        {
            normalizeStr(newTipo);
            instrument_setTipo(pInstrument, newTipo);
            retorno = 0;
        }
    }

    return retorno;
}



int instrument_modifyNombre(LinkedList* pArrayList, int index)
{
    int retorno = -1;
    char newName[nameLen];
    char confirmModify;
    eInstrument* pInstrument;

    pInstrument = ll_get(pArrayList, index);

    if(get_Cadena(newName, nameLen, 2, "Ingrese nuevo nombre: ","Error, reingrese un nombre valido.\n") == 0)
    {
        printf("\nConfirma la modificacion del instrumento? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmModify);

        if(confirmModify == 's')
        {
            normalizeStr(newName);
            instrument_setNombre(pInstrument, newName);
            retorno = 0;
        }
    }

    return retorno;
}

int instrument_modifyMarca(LinkedList* pArrayList, int index)
{
    int retorno = -1;
    char newMarca[nameLen];
    char confirmModify;
    eInstrument* pInstrument;

    pInstrument = ll_get(pArrayList, index);

    if(get_Cadena(newMarca, nameLen, 2, "Ingrese nueva marca: ","Error, reingrese una marca valida.\n") == 0)
    {
        printf("\nConfirma la modificacion del instrumento? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmModify);

        if(confirmModify == 's')
        {
            normalizeStr(newMarca);
            instrument_setMarca(pInstrument, newMarca);
            retorno = 0;
        }
    }

    return retorno;
}

int instrument_modifyColor(LinkedList* pArrayList, int index)
{
    int retorno = -1;
    char newColor[nameLen];
    char confirmModify;
    eInstrument* pInstrument;

    pInstrument = ll_get(pArrayList, index);

    if(get_Cadena(newColor, nameLen, 2, "Ingrese nuevo color: ","Error, reingrese un color valido.\n") == 0)
    {
        printf("\nConfirma la modificacion del instrumento? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmModify);

        if(confirmModify == 's')
        {
            normalizeStr(newColor);
            instrument_setColor(pInstrument, newColor);
            retorno = 0;
        }
    }

    return retorno;
}

int instrument_modifyProveedor(LinkedList* pArrayList, int index)
{
    int retorno = -1;
    char newProveedor[nameLen];
    char confirmModify;
    eInstrument* pInstrument;

    pInstrument = ll_get(pArrayList, index);

    if(get_Cadena(newProveedor, nameLen, 2, "Ingrese nuevo proveedor: ","Error, reingrese un proveedor valido.\n") == 0)
    {
        printf("\nConfirma la modificacion del instrumento? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmModify);

        if(confirmModify == 's')
        {
            normalizeStr(newProveedor);
            instrument_setProveedor(pInstrument, newProveedor);
            retorno = 0;
        }
    }

    return retorno;
}

int instrument_modifyPrecio(LinkedList* pArrayList, int index)
{
    int retorno = -1;
    float newPrecio;
    char confirmModify;
    eInstrument* pInstrument;

    pInstrument = ll_get(pArrayList, index);

    if(get_Flotante(&newPrecio, 2, "Ingrese nuevo precio: ", "Error, precio invalido: ", 1, 120000) == 0)//hasta 300000
    {
        printf("\nConfirma la modificacion del instrumento? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmModify);

        if(confirmModify == 's')
        {
            instrument_setPrecio(pInstrument, newPrecio);
            retorno = 0;
        }
    }

    return retorno;
}


int instrument_modifyStock(LinkedList* pArrayList, int index)
{
    int retorno = -1;
    char newStock[nameLen];
    char confirmModify;
    eInstrument* pInstrument;

    pInstrument = ll_get(pArrayList, index);

    if(get_Cadena(newStock, nameLen, 2, "Ingrese nuevo stock: ","Error, reingrese un stock valido.\n") == 0)
    {
        printf("\nConfirma la modificacion del instrumento? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmModify);

        if(confirmModify == 's')
        {
            normalizeStr(newStock);
            instrument_setStock(pInstrument, newStock);
            retorno = 0;
        }
    }

    return retorno;
}


//-----------------------------------------
//---------MODIFICAR CRITERIOS-------------
//-----------------------------------------


int instrument_sort(LinkedList* pArrayList)
{
    int retorno = -1;
    int orden;

    if(pArrayList != NULL)
    {
        system("cls");
        printf("||Menu ordenar||\n");
        switch(menuSort())
        {
        case 1:
            //ordenar por ID
            get_Entero(&orden, 2, "\nIngrese orden, 1 ascendente, 0 descendente: ", "\nError, ingrese un orden valido", 0, 1);
            printf("\nOrdenando...\n\n\n");
            ll_sort(pArrayList, instrument_sortById, orden);
            controller_listInstrument(pArrayList);
            retorno = 0;
            break;
        case 2:
            //ordenar por Tipo
            get_Entero(&orden, 2, "\nIngrese orden, 1 ascendente, 0 descendente: ", "\nError, ingrese un orden valido", 0, 1);
            printf("\nOrdenando...\n\n\n");
            ll_sort(pArrayList, instrument_sortByType, orden);
            controller_listInstrument(pArrayList);
            retorno = 0;
            break;
        case 3:
            //ordenar por Nombre
            get_Entero(&orden, 2, "\nIngrese orden, 1 ascendente, 0 descendente: ", "\nError, ingrese un orden valido", 0, 1);
            printf("\nOrdenando...\n\n\n");
            ll_sort(pArrayList, instrument_sortByName, orden);
            controller_listInstrument(pArrayList);
            retorno = 0;
            break;
        case 4:
            //ordenar por Marca
            get_Entero(&orden, 2, "\nIngrese orden, 1 ascendente, 0 descendente: ", "\nError, ingrese un orden valido", 0, 1);
            printf("\nOrdenando...\n\n\n");
            ll_sort(pArrayList, instrument_sortByBrand, orden);
            controller_listInstrument(pArrayList);
            retorno = 0;
            break;
        case 5:
            //ordenar por Color
            get_Entero(&orden, 2, "\nIngrese orden, 1 ascendente, 0 descendente: ", "\nError, ingrese un orden valido", 0, 1);
            printf("\nOrdenando...\n\n\n");
            ll_sort(pArrayList, instrument_sortByColour, orden);
            controller_listInstrument(pArrayList);
            retorno = 0;
            break;
        case 6:
            //ordenar por Proveedor
            get_Entero(&orden, 2, "\nIngrese orden, 1 ascendente, 0 descendente: ", "\nError, ingrese un orden valido", 0, 1);
            printf("\nOrdenando...\n\n\n");
            ll_sort(pArrayList, instrument_sortByProvider, orden);
            controller_listInstrument(pArrayList);
            retorno = 0;
            break;
        case 7:
            //ordenar por Precio
            get_Entero(&orden, 2, "\nIngrese orden, 1 ascendente, 0 descendente: ", "\nError, ingrese un orden valido", 0, 1);
            printf("\nOrdenando...\n\n\n");
            ll_sort(pArrayList, instrument_sortByPrice, orden);
            controller_listInstrument(pArrayList);
            retorno = 0;
            break;
        case 8:
            //ordenar por Stock
            get_Entero(&orden, 2, "\nIngrese orden, 1 ascendente, 0 descendente: ", "\nError, ingrese un orden valido", 0, 1);
            printf("\nOrdenando...\n\n\n");
            ll_sort(pArrayList, instrument_sortByStock, orden);
            controller_listInstrument(pArrayList);
            retorno = 0;
            break;
        case 9:
            //vuelve al menu
            break;
        default:
            printf("\nNo es una opcion valida\n\n");
            break;
        }

    }

    return retorno;
}

int instrument_sortById(void* firstElement, void* secondElement)
{
    int retorno = 0; //si son iguales retorno 0

    int firstId;
    int secondId;

    instrument_getId(firstElement, &firstId);
    instrument_getId(secondElement, &secondId);

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

int instrument_sortByType(void* firstElement, void* secondElement)
{
    int retorno = 0; //si son iguales retorno 0

    char firstType[nameLen];
    char secondType[nameLen];

    instrument_getTipo(firstElement, firstType);
    instrument_getTipo(secondElement, secondType);

    if(strcmp(firstType, secondType) > 0)
    {
        retorno = 1; //retorno 1 si el primer parametro es mayor que el segundo
    }
    else if(strcmp(secondType, firstType) < 0)
    {
        retorno = -1;
    }

    return retorno;
}

int instrument_sortByName(void* firstElement, void* secondElement)
{
    int retorno = 0; //si son iguales retorno 0

    char firstName[nameLen];
    char secondName[nameLen];

    instrument_getNombre(firstElement, firstName);
    instrument_getNombre(secondElement, secondName);

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

int instrument_sortByBrand(void* firstElement, void* secondElement)
{
    int retorno = 0; //si son iguales retorno 0

    char firstBrand[nameLen];
    char secondBrand[nameLen];

    instrument_getMarca(firstElement, firstBrand);
    instrument_getMarca(secondElement, secondBrand);

    if(strcmp(firstBrand, secondBrand) > 0)
    {
        retorno = 1; //retorno 1 si el primer parametro es mayor que el segundo
    }
    else if(strcmp(secondBrand, firstBrand) < 0)
    {
        retorno = -1;
    }

    return retorno;
}

int instrument_sortByColour(void* firstElement, void* secondElement)
{
    int retorno = 0; //si son iguales retorno 0

    char firstColour[nameLen];
    char secondColour[nameLen];

    instrument_getColor(firstElement, firstColour);
    instrument_getColor(secondElement, secondColour);

    if(strcmp(firstColour, secondColour) > 0)
    {
        retorno = 1; //retorno 1 si el primer parametro es mayor que el segundo
    }
    else if(strcmp(secondColour, firstColour) < 0)
    {
        retorno = -1;
    }

    return retorno;
}

int instrument_sortByProvider(void* firstElement, void* secondElement)
{
    int retorno = 0; //si son iguales retorno 0

    char firstProvider[nameLen];
    char secondProvider[nameLen];

    instrument_getProveedor(firstElement, firstProvider);
    instrument_getProveedor(secondElement, secondProvider);

    if(strcmp(firstProvider, secondProvider) > 0)
    {
        retorno = 1; //retorno 1 si el primer parametro es mayor que el segundo
    }
    else if(strcmp(secondProvider, firstProvider) < 0)
    {
        retorno = -1;
    }

    return retorno;
}

int instrument_sortByPrice(void* firstElement, void* secondElement)
{
    int retorno = 0; //si son iguales retorno 0

    float firstPrice;
    float secondPrice;

    instrument_getPrecio(firstElement, &firstPrice);
    instrument_getPrecio(secondElement, &secondPrice);

    if(firstPrice > secondPrice)
    {
        retorno = 1; //retorno 1 si el primer parametro es mayor que el segundo
    }
    else if(secondPrice > firstPrice)
    {
        retorno = -1;
    }

    return retorno;
}

int instrument_sortByStock(void* firstElement, void* secondElement)
{
    int retorno = 0; //si son iguales retorno 0

    char firstStock[nameLen];
    char secondStock[nameLen];

    instrument_getStock(firstElement, firstStock);
    instrument_getStock(secondElement, secondStock);

    if(strcmp(firstStock, secondStock) > 0)
    {
        retorno = 1; //retorno 1 si el primer parametro es mayor que el segundo
    }
    else if(strcmp(secondStock, firstStock) < 0)
    {
        retorno = -1;
    }

    return retorno;
}


int instrument_filterByTypeCuerdas(void* element)
{
    int retorno = 0;

    eInstrument* pInstrument;

    if(element != NULL)
    {
        pInstrument = (eInstrument*) element;
        if(strcmp(pInstrument->tipo, "Cuerdas"))
        {
            retorno = 1;
        }
    }
    return retorno;
}

int instrument_filterByTypePercusion(void* element)
{
    int retorno = 0;

    eInstrument* pInstrument;

    if(element != NULL)
    {
        pInstrument = (eInstrument*) element;
        if(strcmp(pInstrument->tipo, "Percusion"))
        {
            retorno = 1;
        }
    }
    return retorno;
}

int instrument_filterByTypeTeclas(void* element)
{
    int retorno = 0;

    eInstrument* pInstrument;

    if(element != NULL)
    {
        pInstrument = (eInstrument*) element;
        if(strcmp(pInstrument->tipo, "Teclas"))
        {
            retorno = 1;
        }
    }
    return retorno;
}

int instrument_filterByTypeViento(void* element)
{
    int retorno = 0;

    eInstrument* pInstrument;

    if(element != NULL)
    {
        pInstrument = (eInstrument*) element;
        if(strcmp(pInstrument->tipo, "Viento"))
        {
            retorno = 1;
        }
    }
    return retorno;
}

int instrument_filterByStock(void* element)
{
    int retorno = 0;

    eInstrument* pInstrument;

    if(element != NULL)
    {
        pInstrument = (eInstrument*) element;
        if(strcmp(pInstrument->stock, "Si"))
        {
            retorno = 1;
        }
    }
    return retorno;
}

int instrument_filterByNoStock(void* element)
{
    int retorno = 0;

    eInstrument* pInstrument;

    if(element != NULL)
    {
        pInstrument = (eInstrument*) element;
        if(strcmp(pInstrument->stock, "No"))
        {
            retorno = 1;
        }
    }
    return retorno;
}
