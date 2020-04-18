#ifndef MENUCALCULADORA_H_INCLUDED
#define MENUCALCULADORA_H_INCLUDED



#endif // MENUCALCULADORA_H_INCLUDED

/** \brief Muestra el menú de la calculadora y da a elegir una opcion a realizar
 *
 * \param x Recibe el valor entero del operando A
 * \param y Recibe el valor entero del operando B
 * \param flagA Recibe el valor de la bandera del operando A, para modificar el texto de la consigna 1
 * \param flagB Recibe el valor de la bandera del operando B, para modificar el texto de la consigna 2
 *
 * \return Devuelve la opcion elegida
 *
 */
int menuCalculadora(int x, int y, int flagA, int flagB);

/** \brief Pide un numero entero
 *
 * \return devuelve el numero entero ingresado
 *
 */
int ingresarOperando();

/** \brief Muestra un mensaje que indica que las operaciones fueron calculadas
 *
 */
void calcularOperaciones();

/** \brief Llama a las funciones de calculo utilizando los respectivos operandos y muestra los resultados
 *
 * \param a Recibe el operando A a calcular
 * \param b Recibe el operando B a calcular
 *
 */
void informarResultados(int a, int b);
