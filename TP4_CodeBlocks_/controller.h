#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

/**
 * \brief Carga los datos desde el archivo data.csv (modo texto).
 * \param path char*, path al archivo a cargar
 * \param pArrayList LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_loadFromText(char* path, LinkedList* pArrayList);

/**
 * \brief Guarda los datos en el archivo data.csv (modo texto).
 * \param path char*: path al archivo a guardar
 * \param pArrayList LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_saveAsText(char* path, LinkedList* pArrayList);

/**
 * \brief Carga los datos desde el archivo data.bin (modo binario).
 * \param path char*: path al archivo a cargar
 * \param pArrayList LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayList);

/**
 * \brief Guarda los datos en el archivo data.bin (modo binario).
 * \param path char*: path al archivo a guardar
 * \param pArrayList LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayList);


/** \brief Lista un instrumento
 *
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_listInstrument(LinkedList* pArrayList);


/** \brief Alta instrumento
 *
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_addInstrument(LinkedList* pArrayList);


/** \brief Modificar un instrumento
 *
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_editInstrument(LinkedList* pArrayList);


/** \brief Eliminar un instrumento
 *
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_removeInstrument(LinkedList* pArrayList);


/** \brief Ordenar instrumentos
 *
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_sortInstrument(LinkedList* pArrayList);


/**
 * \brief Muestra una lista filtrada en base al criterio elegido en los cases
 * \param pArrayList, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_filterInstrument(LinkedList* pArrayList);
