#ifndef OPERACIONESCALCULADORA_H_INCLUDED
#define OPERACIONESCALCULADORA_H_INCLUDED



#endif // OPERACIONESCALCULADORA_H_INCLUDED

/** \brief Suma 2 numeros enteros
 *
 * \param  a Recibe el operando A a sumar
 * \param  b Recibe el operando B a sumar
 * \return Devuelve el resultado de la suma
 *
 */
int calcularSuma(int a, int b);

/** \brief Resta 2 numeros enteros
 *
 * \param a Recibe el operando A a restar
 * \param b Recibe el operando B a restar
 * \return Devuelve el resultado de la resta
 *
 */
int calcularResta(int a, int b);

/** \brief Recibe y divide 2 numeros enteros, devuelve el resultado de forma flotante
 *
 * \param a Recibe el operando A
 * \param b Recibe el operando B
 * \return Devuelve el resultado de la división de forma flotante
 *
 */
float calcularDivision(int a, int b);

/** \brief Multiplica 2 numeros enteros
 *
 * \param a Recibe el operando A
 * \param b Recibe el operando B
 * \return Devuelve el resultado de la multiplicación
 *
 */
int calcularMultiplicacion(int a, int b);

/** \brief Factoriza un numero entero positivo (numero maximo = 33)
 *
 * \param a Recibe el numero a factorizar
 * \return Devuelve el resultado de la factorización
 *
 */
//la funcion factorial creada define que el factorial de 0 es 1
unsigned int operacionFactorial(int a);
