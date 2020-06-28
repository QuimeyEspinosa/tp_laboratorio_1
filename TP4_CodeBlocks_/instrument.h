#ifndef INSTRUMENT_H_INCLUDED
#define INSTRUMENT_H_INCLUDED

typedef struct
{
    int id;
    char tipo[128];
    char nombre[128];
    char marca[128];
    char color[128];
    char proveedor[128];
    float precio;
    char stock[128];

} eInstrument;

#endif // INSTRUMENT_H_INCLUDED


/**
 * \brief Pide memoria con malloc
 * \return Retorna un puntero a instrumento
 */
eInstrument* instrument_new();

/**
 * \brief Elimina un instrumento
 * \param this, puntero a instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_delete(eInstrument* this);

/**
 * \brief Llama a los setters que cargan los campos del instrumento
 * \param IdStr, cadena de caracteres de id del instrumento
 * \param tipoStr, cadena de caracteres de tipo del instrumento
 * \param nombreStr, cadena de caracteres de nombre del instrumento
 * \param marcaStr, cadena de caracteres de marca del instrumento
 * \param colorStr, cadena de caracteres de color del instrumento
 * \param proveedorStr, cadena de caracteres de proveedor del instrumento
 * \param precioStr, cadena de caracteres de precio del instrumento
 * \param stockStr, cadena de caracteres de stock del instrumento
 * \return Retorna un puntero a instrumento
 */
eInstrument* instrument_newParameters(char* idStr, char* tipoStr, char* nombreStr, char* marcaStr, char* colorStr, char* proveedorStr, char* precioStr, char* stockStr);


/**
 * \brief Imprime un instrumento
 * \param pArrayList, LinkedList
 * \param index, indice donde se encuentra el instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_printInstrument(LinkedList* pArrayList, int index);

/**
 * \brief Busca un instrumento por id
 * \param pArrayList, LinkedList
 * \param id, id a buscar en la lista
 * \return -1 en caso de error, o el index del instrumento en caso de exito
 */
int instrument_searchForId(LinkedList* pArrayList, int id);

/**
 * \brief Devuelve el id mas alto de la lista
 * \param pArrayList, LinkedList
 * \return -1 en caso de error, o el id mas alto en caso de exito
 */
int instrument_lastId(LinkedList* pArrayList);


//-----------------------------------------
//---------------MODIFYS-------------------
//-----------------------------------------


/**
 * \brief Cambia el tipo de un instrumento
 * \param pArrayList, LinkedList
 * \param index, indice donde se encuentra el instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_modifyTipo(LinkedList* pArrayList, int index);

/**
 * \brief Cambia el nombre de un instrumento
 * \param pArrayList, LinkedList
 * \param index, indice donde se encuentra el instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_modifyNombre(LinkedList* pArrayList, int index);

/**
 * \brief Cambia la marca de un instrumento
 * \param pArrayList, LinkedList
 * \param index, indice donde se encuentra el instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_modifyMarca(LinkedList* pArrayList, int index);

/**
 * \brief Cambia el color de un instrumento
 * \param pArrayList, LinkedList
 * \param index, indice donde se encuentra el instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_modifyColor(LinkedList* pArrayList, int index);

/**
 * \brief Cambia el proveedor de un instrumento
 * \param pArrayList, LinkedList
 * \param index, indice donde se encuentra el instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_modifyProveedor(LinkedList* pArrayList, int index);

/**
 * \brief Cambia el precio de un instrumento
 * \param pArrayList, LinkedList
 * \param index, indice donde se encuentra el instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_modifyPrecio(LinkedList* pArrayList, int index);

/**
 * \brief Cambia el stock de un instrumento
 * \param pArrayList, LinkedList
 * \param index, indice donde se encuentra el instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_modifyStock(LinkedList* pArrayList, int index);


//-----------------------------------------
//-------------SORTS---------------
//-----------------------------------------


/**
 * \brief Switchea entre los cases de ordenamiento
 * \param pArrayList, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_sort(LinkedList* pArrayList);

/**
 * \brief Compara los ids de dos instrumentos
 * \param firstElement, puntero a primer instrumento a comparar
 * \param secondElement, puntero a segundo instrumento a comparar
 * \return 1 si el id del primer instrumento es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int instrument_sortById(void* firstElement, void* secondElement);

/**
 * \brief Compara los tipos de dos instrumentos
 * \param firstElement, puntero a primer instrumento a comparar
 * \param secondElement, puntero a segundo instrumento a comparar
 * \return 1 si el id del primer instrumento es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int instrument_sortByType(void* firstElement, void* secondElement);

/**
 * \brief Compara los nombres de dos instrumentos
 * \param firstElement, puntero a primer instrumento a comparar
 * \param secondElement, puntero a segundo instrumento a comparar
 * \return 1 si el id del primer instrumento es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int instrument_sortByName(void* firstElement, void* secondElement);

/**
 * \brief Compara las marcas de dos instrumentos
 * \param firstElement, puntero a primer instrumento a comparar
 * \param secondElement, puntero a segundo instrumento a comparar
 * \return 1 si el id del primer instrumento es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int instrument_sortByBrand(void* firstElement, void* secondElement);

/**
 * \brief Compara los precios de dos instrumentos
 * \param firstElement, puntero a primer instrumento a comparar
 * \param secondElement, puntero a segundo instrumento a comparar
 * \return 1 si el id del primer instrumento es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int instrument_sortByColour(void* firstElement, void* secondElement);

/**
 * \brief Compara los proveedores de dos instrumentos
 * \param firstElement, puntero a primer instrumento a comparar
 * \param secondElement, puntero a segundo instrumento a comparar
 * \return 1 si el id del primer instrumento es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int instrument_sortByProvider(void* firstElement, void* secondElement);

/**
 * \brief Compara los precios de dos instrumentos
 * \param firstElement, puntero a primer instrumento a comparar
 * \param secondElement, puntero a segundo instrumento a comparar
 * \return 1 si el id del primer instrumento es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int instrument_sortByPrice(void* firstElement, void* secondElement);

/**
 * \brief Compara los stocks de dos instrumentos
 * \param firstElement, puntero a primer instrumento a comparar
 * \param secondElement, puntero a segundo instrumento a comparar
 * \return 1 si el id del primer instrumento es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int instrument_sortByStock(void* firstElement, void* secondElement);

//-----------------------------------------
//---------------FILTERS-------------------
//-----------------------------------------

/** \brief guarda en element el valor del filtro deseado
 * \param element, puntero a void
 * \return retorna 1 si pudo filtrar, 0 si no
 */
int instrument_filterByTypeCuerdas(void* element);

/** \brief guarda en element el valor del filtro deseado
 * \param element, puntero a void
 * \return retorna 1 si pudo filtrar, 0 si no
 */
int instrument_filterByTypePercusion(void* element);

/** \brief guarda en element el valor del filtro deseado
 * \param element, puntero a void
 * \return retorna 1 si pudo filtrar, 0 si no
 */
int instrument_filterByTypeTeclas(void* element);

/** \brief guarda en element el valor del filtro deseado
 * \param element, puntero a void
 * \return retorna 1 si pudo filtrar, 0 si no
 */
int instrument_filterByTypeViento(void* element);

/** \brief guarda en element el valor del filtro deseado
 * \param element, puntero a void
 * \return retorna 1 si pudo filtrar, 0 si no
 */
int instrument_filterByStock(void* element);

/** \brief guarda en element el valor del filtro deseado
 * \param element, puntero a void
 * \return retorna 1 si pudo filtrar, 0 si no
 */
int instrument_filterByNoStock(void* element);

//-----------------------------------------
//---------------SETTERS-------------------
//-----------------------------------------

/**
 * \brief Valida y carga el id en el campo del instrumento
 * \param this, puntero a instrumento
 * \param id, id a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_setId(eInstrument* this,int id);

/**
 * \brief Valida y carga el tipo en el campo tipo del instrumento
 * \param this, puntero a instrumento
 * \param tipo, cadena de caracteres de tipo del instrumento a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_setTipo(eInstrument* this,char* tipo);

/**
 * \brief Valida y carga el nombre en el campo nombre del instrumento
 * \param this, puntero a instrumento
 * \param nombre, cadena de caracteres de nombre del instrumento a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_setNombre(eInstrument* this,char* nombre);

/**
 * \brief Valida y carga la marca en el campo marca del instrumento
 * \param this, puntero a instrumento
 * \param marca, cadena de caracteres de marca del instrumento a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_setMarca(eInstrument* this,char* marca);

/**
 * \brief Valida y carga el color en el campo color del instrumento
 * \param this, puntero a instrumento
 * \param color, cadena de caracteres de color del instrumento a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_setColor(eInstrument* this,char* color);

/**
 * \brief Valida y carga el proveedor en el campo proveedor del instrumento
 * \param this, puntero a instrumento
 * \param proveedor, cadena de caracteres de proveedor del instrumento a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_setProveedor(eInstrument* this,char* proveedor);

/**
 * \brief Valida y carga el precio en el campo precio del instrumento
 * \param this, puntero a instrumento
 * \param precio, cadena de caracteres de precio del instrumento a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_setPrecio(eInstrument* this,float precio);

/**
 * \brief Valida y carga el stock en el campo stock del instrumento
 * \param this, puntero a instrumento
 * \param stock, cadena de caracteres de stock del instrumento a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_setStock(eInstrument* this,char* stock);

//-----------------------------------------
//---------------GETTERS-------------------
//-----------------------------------------

/**
 * \brief Valida y carga el id en el campo del instrumento
 * \param this, puntero a instrumento
 * \param id, id a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_getId(eInstrument* this,int* id);

/**
 * \brief Carga el tipo del instrumento en el puntero que pasemos por parametros
 * \param this, puntero al instrumento
 * \param tipo, cadena de caracteres en la que la funcion cargara el tipo del instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_getTipo(eInstrument* this,char* tipo);

/**
 * \brief Carga el nombre del instrumento en el puntero que pasemos por parametros
 * \param this, puntero al instrumento
 * \param nombre, cadena de caracteres en la que la funcion cargara el nombre del instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_getNombre(eInstrument* this,char* nombre);

/**
 * \brief Carga la marca del instrumento en el puntero que pasemos por parametros
 * \param this, puntero al instrumento
 * \param marca, cadena de caracteres en la que la funcion cargara el marca del instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_getMarca(eInstrument* this,char* marca);

/**
 * \brief Carga el color del instrumento en el puntero que pasemos por parametros
 * \param this, puntero al instrumento
 * \param color, cadena de caracteres en la que la funcion cargara el color del instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_getColor(eInstrument* this,char* color);

/**
 * \brief Carga el proveedor del instrumento en el puntero que pasemos por parametros
 * \param this, puntero al instrumento
 * \param proveedor, cadena de caracteres en la que la funcion cargara el proveedor del instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_getProveedor(eInstrument* this,char* proveedor);

/**
 * \brief Carga el precio del instrumento en el puntero que pasemos por parametros
 * \param this, puntero al instrumento
 * \param precio, cadena de caracteres en la que la funcion cargara el precio del instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_getPrecio(eInstrument* this,float* precio);

/**
 * \brief Carga el stock del instrumento en el puntero que pasemos por parametros
 * \param this, puntero al instrumento
 * \param stock, cadena de caracteres en la que la funcion cargara el stock del instrumento
 * \return -1 en caso de error, o 0 en caso de exito
 */
int instrument_getStock(eInstrument* this,char* stock);
