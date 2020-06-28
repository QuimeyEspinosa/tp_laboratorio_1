#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "instrument.h"
#include "parser.h"


int parser_InstrumentFromText(FILE* pFile, LinkedList* pArrayList)
{
    int retorno = -1; //retorno error

    eInstrument* pInstrument;

    //int cant; //guarda la cantidad que devuelve fscanf
    char id[128];
    char tipo[128];
    char nombre[128];
    char marca[128];
    char color[128];
    char proveedor[128];
    char precio[128];
    char stock[128];
    int nextId = 0;

    if(pFile != NULL && pArrayList != NULL)
    {
        do
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, tipo, nombre, marca, color, proveedor, precio, stock) == 8)
            {
                //imprime mientras fscanf devuelva la cantidad correcta

                pInstrument = instrument_newParameters(id, tipo, nombre, marca, color, proveedor, precio, stock);

                if(pInstrument != NULL)
                {
                    ll_add(pArrayList, pInstrument);
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


int parser_InstrumentFromBinary(FILE* pFile, LinkedList* pArrayList)
{
    int retorno = -1;
    eInstrument* pInstrument;

    if(pFile != NULL)
    {
        do
        {
            pInstrument = instrument_new(); //reservo lugar

            if(fread(pInstrument, sizeof(eInstrument), 1, pFile) == 1) //leo datos binarios y valido si me leyo 1
            {
                ll_add(pArrayList, pInstrument);
                retorno = 0;//exito
            }
        }
        while(!feof(pFile)); //recorro mientras no sea el final del archivo
    }

    return retorno;
}
