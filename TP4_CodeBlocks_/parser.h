#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED

/** \brief Parsea los datos desde un archivo de texto
 *
 * \param path char*: el path del archivo a cargar
 * \param pArrayList, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 *
 */
int parser_InstrumentFromText(FILE* pFile, LinkedList* pArrayList);


/** \brief Parsea los datos los datos de los libros desde el archivo data.csv (modo binario).
 *
 * \param path char*: el path del archivo a cargar
 * \param pArrayList, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 *
 */
int parser_InstrumentFromBinary(FILE* pFile, LinkedList* pArrayList);
