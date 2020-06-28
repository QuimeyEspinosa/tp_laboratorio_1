#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED



#endif // VALIDATIONS_H_INCLUDED


/**
 * @brief Valida la cadena que le pasemos como nombre.
 * @param Cadena a cargar el string validado
 * @return Retorna 1 si valida la cadena con exito, o 0 si no.
 */
int validarNombre(char* cadena, int longitud);


/**
 * @brief Verifica y valida que el usuario ingrese una cadena de caracteres.
 * @param Puntero a variable char en la que cargar la cadena validada.
 * @param Limite de caracteres a ingresar
 * @param Numero de reintentos
 * @param Mensaje a mostrar
 * @param Mensaje de error
 * @return 0 si tuvo exito, y -1 si no.
 */
int get_Cadena(char *pAux, int limitChar, int retry, char* msg, char* msgError);


/**
 * @brief Toma la cadena ingresada y le quita el '\n' al fgets.
 * @param Puntero a variable char en la que cargar la cadena validada.
 * @return 0 si tuvo exito, y -1 si no.
 */
int getCadena(char* pAux, int limitChar);


/**
 * @brief Valida que cada posicion de la cadena sea letra.
 * @param Cadena a analizar
 * @return 0 si todas las posiciones son letras, y -1 si no.
 */
int isChar(char str[]);


/**
 * @brief "Normaliza" la cadena que le pasemos, ejemplo: si se ingreso "juAn", se "normaliza a "Juan".
 * @param Cadena a cargar el string "normalizado"
 * @return Retorna 0 si normaliza la cadena con exito, o -1 si no.
 */
int normalizeStr(char* str);


/**
 * @brief Pasa la cadena ingresada a minuscula recorriendola y en cada posicion llamando a tolower.
 * @param Cadena a cargar el string en minuscula
 * @return Retorna 0 si pasa la cadena con exito, o -1 si no.
 */
int strLwr(char* str);


/**
 * @brief Verifica y valida que lo ingresado por el usuario sea un numero entero.
 * @param Puntero a entero donde cargar lo validado.
 * @param Cantidad de reintentos
 * @param Mensaje
 * @param Mensaje de error
 * @param Minimo numero a ingresar
 * @param Maximo numero a ingresar
 * @return
 */
int get_Entero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);


/**
 * @brief Llama a getInt y a isCadena para validar que lo ingresado es un numero entero y pasa la cadena a integer.
 * @param Puntero a variable a cargar el numero validado.
 * @return Retorna 0 si logra validar, o -1 si no.
 */
int getInt(int* pAux);


/**
 * @brief Recorre la cadena validando que cada posicion sea un numero (0 - 9)
 * @param Cadena a cargar el numero validado
 * @return Retorna 0 si logra validar, o -1 si no.
 */
int isInt(char *pAux);


int get_Flotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);
int getFloat(float*pAux);
int isFloat(char* pAux);
